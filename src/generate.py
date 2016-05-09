import os

##### IO FILES ######

cfgfile_name = "../cfg/QIE10_testing.cfg"
loopfile_name = "QIE10_loop.h"
initfile_name = "QIE10_init.h"

##### DEFINITIONS #####

# definitions[type][0] = 'type' name
# definitions[type][1] = array of parameter names for 'type'
definitions = [

    ['null'       , ["name"] ],
    ['TH1F'       , ["name" , "nbinsx" , "lowx" , "highx" , "titlex"] ],
    ['TH2F'       , ["name" , "nbinsx" , "lowx" , "highx" , "titlex" , "nbinsy" , "lowy" , "highy" , "titley"] ],
    ['TH1F_PerTS' , ["name" , "nbinsx" , "lowx" , "highx" , "titlex"] ],
    ['TH2F_PerTS' , ["name" , "nbinsx" , "lowx" , "highx" , "titlex" , "nbinsy" , "lowy" , "highy" , "titley"] ],
    ['logger'     , ["name" , "log_file" , "mode"] ],
    ['stdout'     , ["name"] ],
    ['TTree'      , ["name"] ]

]

# types of blocks
block_definitions = [

    'loop_vars' ,
    'pre_loop' ,
    'loop' ,
    'post_loop'

]

# maps parameter name to c++ type
cpp_types = {

    "name"   : "char" ,
    "nbinsx" : "int" ,
    "lowx"   : "float" ,
    "highx"  : "float" ,
    "titlex" : "char" ,
    "nbinsy" : "int" ,
    "lowy"   : "float" ,
    "highy"  : "float" ,
    "titley" : "char"
    
}

##### PRINTING FUNCTIONS #####

def print_header(infile,infile_name):
    infile.write('// #############################################################\n')
    infile.write('// #############################################################\n')
    infile.write('// ###' + ''.center(55) + '###\n')
    infile.write('// ###' + infile_name.center(55) + '###\n')
    infile.write('// ###' + ''.center(55) + '###\n')
    infile.write('// ###' + 'This file was written by a robot!'.center(55) + '###\n')
    infile.write('// ###' + 'Do not edit by hand!'.center(55) + '###\n')
    infile.write('// ###' + ''.center(55) + '###\n')
    infile.write('// ###' + 'Instead, modify the configuration file:'.center(55) + '###\n')
    infile.write('// ###' + ' QIE10_testing.cfg'.center(55) + '###\n')
    infile.write('// ###' + 'and then rebuild with:'.center(55) + '###\n')
    infile.write('// ###' + './rebuild'.center(55) + '###\n')
    infile.write('// ###' + ''.center(55) + '###\n')
    infile.write('// ###' + 'Joseph Mariano -- jmariano@cern.ch'.center(55) + '###\n')
    infile.write('// ###' + '27-04-2016'.center(55) + '###\n')
    infile.write('// ###' + ''.center(55) + '###\n')
    infile.write('// #############################################################\n')
    infile.write('// #############################################################\n')
    infile.write('\n')

def print_loop():

    os.system('rm ./' + loopfile_name)
    os.system('touch ./' + loopfile_name)
    loopfile = open(loopfile_name,'w')

    print_header(loopfile, loopfile_name)

    loopfile.write('#include <vector>\n')
    loopfile.write('\n')
    loopfile.write('#include "TH1D.h"\n')
    loopfile.write('#include "TH2D.h"\n')
    loopfile.write('\n')
    loopfile.write('using namespace std;\n')
    loopfile.write('\n')
    loopfile.write('// ########################\n')
    loopfile.write('// # LOOP_VARS STRUCTURES #\n')
    loopfile.write('// ########################\n')
    loopfile.write('\n')
    for s in range(len(suites)):
        loopfile.write('// --- Suite ' + suites[s][0] + ': ' + suites[s][1] + ' ---\n')
        loopfile.write('\n')
        loopfile.write('struct loop_vars {\n')
        loopfile.write('\n')
        for i in range(len(data)):
            for j in range(len(data[i])):
                if suites[s][0] in data[i][j][2]:
                    for line in data[i][j][1][0]:
                        loopfile.write(line + '\n')                              
        loopfile.write('\n')
        loopfile.write('};\n')
        loopfile.write('\n')
    loopfile.write('// #############\n')
    loopfile.write('// # PRE_LOOPS #\n')
    loopfile.write('// #############\n')
    loopfile.write('\n')
    for s in range(len(suites)):
        loopfile.write('// --- Suite ' + suites[s][0] + ': ' + suites[s][1] + ' ---\n')
        loopfile.write('\n')
        loopfile.write('loop_vars pre_loop() {\n')
        loopfile.write('\n')
        loopfile.write('  loop_vars prevars;\n')
        loopfile.write('\n')
        for i in range(len(data)):
            for j in range(len(data[i])):
                if suites[s][0] in data[i][j][2]:
                    for line in data[i][j][1][1]:
                        loopfile.write(line.replace('<fill>',definitions[i][0]+'s['+str(j)+'][nCH]->Fill').replace('<fill_perTS>',definitions[i][0]+'s['+str(j)+'][nTS][nCH]->Fill') + '\n')
        loopfile.write('\n')
        loopfile.write('  return prevars;\n')
        loopfile.write('\n')
        loopfile.write('};\n')
        loopfile.write('\n')
    loopfile.write('// #########\n')
    loopfile.write('// # LOOPS #\n')
    loopfile.write('// #########\n')
    loopfile.write('\n')
    for s in range(len(suites)):
        loopfile.write('// --- Suite ' + suites[s][0] + ': ' + suites[s][1] + ' ---\n')
        loopfile.write('\n')
        loopfile.write('loop_vars loop(int nTS, int nCH, QIE10DataFrame digis, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<string> &TH1F_names, vector<vector<TH2F*> > &TH2Fs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<string> &TH2F_names) {\n')
#        loopfile.write('loop_vars loop(int nTS, int nCH, QIE10DataFrame digis, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs, vector<string> &TH1F_names, vector<vector<TH2F*> > &TH2Fs, vector<string> &TH2F_names) {\n')
        loopfile.write('\n')
        for i in range(len(data)):
            for j in range(len(data[i])):
                if suites[s][0] in data[i][j][2]:
                    for line in data[i][j][1][2]:
                        loopfile.write(line.replace('<fill>',definitions[i][0]+'s['+str(j)+'][nCH]->Fill').replace('<fill_perTS>',definitions[i][0]+'s['+str(j)+'][nTS][nCH]->Fill') + '\n')
        loopfile.write('\n')
        loopfile.write('  return prevars;\n')
        loopfile.write('\n')
        loopfile.write('};\n')
        loopfile.write('\n')
    loopfile.write('// ##############\n')
    loopfile.write('// # POST_LOOPS #\n')
    loopfile.write('// ##############\n')
    loopfile.write('\n')
    for i in range(len(suites)):
        loopfile.write('// --- Suite ' + suites[i][0] + ': ' + suites[i][1] + ' ---\n')
        loopfile.write('void post_loop(int nCH, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs, vector<vector<vector<TH1F*> > > &TH1F_PerTS, vector<string> &TH1F_names, vector<vector<TH2F*> > &TH2Fs, vector<vector<vector<TH2F*> > > &TH2F_PerTS, vector<string> &TH2F_names) {\n')
        loopfile.write('\n')
#        loopfile.write('void post_loop(int nCH, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs, vector<string> &TH1F_names, vector<vector<TH2F*> > &TH2Fs, vector<string> &TH2F_names) {\n')
        loopfile.write('\n')
        for i in range(len(data)):
            for j in range(len(data[i])):
                if suites[s][0] in data[i][j][2]:
                    for line in data[i][j][1][3]:
                        loopfile.write(line.replace('<fill>',definitions[i][0]+'s['+str(j)+'][nCH]->Fill').replace('<fill_perTS>',definitions[i][0]+'s['+str(j)+'][nTS][nCH]->Fill') + '\n')
        loopfile.write('\n')
        loopfile.write('};\n')
        loopfile.write('\n')

def get_num_tests(suite_code,test_num):
    num_out = 0
    for j in range(len(data[test_num])):
        if suite_code in data[test_num][j][2]:
            num_out = num_out + 1
    return num_out

def print_init():

    os.system('rm ./' + initfile_name)
    os.system('touch ./' + initfile_name)
    initfile = open(initfile_name,'w')

    print_header(initfile,initfile_name)

    initfile.write('#include <vector>\n')
    initfile.write('\n')
    initfile.write('#include "TH1D.h"\n')
    initfile.write('#include "TH2D.h"\n')
    initfile.write('\n')
    initfile.write('// #########\n')
    initfile.write('// # TESTS #\n')
    initfile.write('// #########\n')
    initfile.write('\n')
    for i in range(len(data)):
        if (definitions[i][0] != 'null'):
            initfile.write('// #####  ' + definitions[i][0] + 's  #####\n')
            initfile.write('\n')
            for j in range(len(data[i])):
                initfile.write('// --- ' + definitions[i][0] + ' ' + str(j) + ' ---\n')
                for k in range(len(definitions[i][1])):
                    initfile.write('#define ' + definitions[i][0].upper() + '_' + str(j) + '_' + definitions[i][1][k].upper() + ' ' + data[i][j][0][k] + '\n')
                initfile.write('\n')
    initfile.write('// ##########\n')
    initfile.write('// # SUITES #\n')
    initfile.write('// ##########\n')
    initfile.write('\n')
    for s in range(len(suites)): # for each suite
        initfile.write('// --- Suite ' + suites[s][0] + ': ' + suites[s][1] + ' ---\n')
        for i in range(len(data)):
            num_tests = get_num_tests(suites[s][0],i)
            if ((num_tests > 0) and (definitions[i][0] != 'null')):
                initfile.write('#define SUITE' + suites[s][0] + '_' + definitions[i][0].upper() + '_NUM ' + str(num_tests) + '\n')
                for k in range(len(definitions[i][1])):
                    initfile.write('#define SUITE' + suites[s][0] + '_' + definitions[i][0].upper() + '_' + definitions[i][1][k].upper() + ' ')
                    for j in range(len(data[i])):
                        if suites[s][0] in data[i][j][2]:
                            initfile.write(definitions[i][0].upper() + '_' + str(j) + '_' + definitions[i][1][k].upper() + ' , ')
                    initfile.write('\n')
        initfile.write('\n')
    initfile.write('// #################\n')
    initfile.write('// # INIT FUNCTION #\n')
    initfile.write('// #################\n')
    initfile.write('\n')
    initfile.write('using namespace std;\n')
    initfile.write('\n')

#    initfile.write('void init(vector<vector<TH1F*> > &TH1Fs, int &num_TH1Fs, vector<string> &TH1F_names, vector<int> &TH1F_nbinsx, vector<float> &TH1F_lowx, vector<float> &TH1F_highx, vector<string> &TH1F_axisx, vector<vector<TH2F*> > &TH2Fs, int &num_TH2Fs, vector<string> &TH2F_names, vector<int> &TH2F_nbinsx, vector<float> &TH2F_lowx, vector<float> &TH2F_highx, vector<string> &TH2F_axisx, vector<int> &TH2F_nbinsy, vector<float> &TH2F_lowy, vector<float> &TH2F_highy, vector<string> &TH2F_axisy){\n')
    initfile.write('void init(\n')
    initfile.write('vector<vector<TH1F*> > &TH1Fs, int &num_TH1Fs, vector<string> &TH1F_names, vector<int> &TH1F_nbinsx, vector<float> &TH1F_lowx, vector<float> &TH1F_highx, vector<string> &TH1F_axisx,\n')
    initfile.write('vector<vector<vector<TH1F*> > > &TH1F_PerTSs, int &num_TH1F_PerTSs, vector<string> &TH1F_PerTS_names, vector<int> &TH1F_PerTS_nbinsx, vector<float> &TH1F_PerTS_lowx, vector<float> &TH1F_PerTS_highx, vector<string> &TH1F_PerTS_axisx,\n')
    initfile.write('vector<vector<TH2F*> > &TH2Fs, int &num_TH2Fs, vector<string> &TH2F_names, vector<int> &TH2F_nbinsx, vector<float> &TH2F_lowx, vector<float> &TH2F_highx, vector<string> &TH2F_axisx, vector<int> &TH2F_nbinsy, vector<float> &TH2F_lowy, vector<float> &TH2F_highy, vector<string> &TH2F_axisy,\n')
    initfile.write('vector<vector<vector<TH2F*> > > &TH2F_PerTSs, int &num_TH2F_PerTSs, vector<string> &TH2F_PerTS_names, vector<int> &TH2F_PerTS_nbinsx, vector<float> &TH2F_PerTS_lowx, vector<float> &TH2F_PerTS_highx, vector<string> &TH2F_PerTS_axisx, vector<int> &TH2F_PerTS_nbinsy, vector<float> &TH2F_PerTS_lowy, vector<float> &TH2F_PerTS_highy, vector<string> &TH2F_PerTS_axisy){\n')
    initfile.write('\n')
    for s in range(len(suites)):
        initfile.write('// --- Suite ' + suites[s][0] + ': ' + suites[s][1] + ' ---\n')
        initfile.write('\n')
        for i in range(len(data)):
            num_tests = get_num_tests(suites[s][0],i)
            if ((num_tests > 0) and (definitions[i][0] != 'null')):
                initfile.write('  num_' + definitions[i][0] + 's = SUITE' + str(suites[s][0]) +'_' + definitions[i][0].upper() + '_NUM;\n')
                for k in range(len(definitions[i][1])):
                    initfile.write('  ' + cpp_types[definitions[i][1][k]] + ' temp_' + definitions[i][0] + '_' + definitions[i][1][k] + '[num_' + definitions[i][0] + 's]')
                    if (cpp_types[definitions[i][1][k]] == "char"):
                        initfile.write('[100]')
                    initfile.write(' = {SUITE' + str(s) + '_' + definitions[i][0].upper() + '_' + definitions[i][1][k].upper() + '};\n')
                initfile.write('\n')
    initfile.write('  for (int i=0 ; i < num_TH1Fs ; i++) {\n')
    initfile.write('    vector<TH1F*> temp_TH1F_vector;\n')
    initfile.write('    TH1Fs.push_back(temp_TH1F_vector);\n')
    initfile.write('    TH1F_names.push_back(temp_TH1F_name[i]);\n')
    initfile.write('    TH1F_nbinsx.push_back(temp_TH1F_nbinsx[i]);\n')
    initfile.write('    TH1F_lowx.push_back(temp_TH1F_lowx[i]);\n')
    initfile.write('    TH1F_highx.push_back(temp_TH1F_highx[i]);\n')
    initfile.write('    TH1F_axisx.push_back(temp_TH1F_titlex[i]);\n')
    initfile.write('  }\n')
    initfile.write('\n')
    initfile.write('  for (int i=0 ; i < num_TH2Fs ; i++) {\n')
    initfile.write('    vector<TH2F*> temp_TH2F_vector;\n')
    initfile.write('    TH2Fs.push_back(temp_TH2F_vector);\n')
    initfile.write('    TH2F_names.push_back(temp_TH2F_name[i]);\n')
    initfile.write('    TH2F_nbinsx.push_back(temp_TH2F_nbinsx[i]);\n')
    initfile.write('    TH2F_lowx.push_back(temp_TH2F_lowx[i]);\n')
    initfile.write('    TH2F_highx.push_back(temp_TH2F_highx[i]);\n')
    initfile.write('    TH2F_axisx.push_back(temp_TH2F_titlex[i]);\n')
    initfile.write('    TH2F_nbinsy.push_back(temp_TH2F_nbinsy[i]);\n')
    initfile.write('    TH2F_lowy.push_back(temp_TH2F_lowy[i]);\n')
    initfile.write('    TH2F_highy.push_back(temp_TH2F_highy[i]);\n')
    initfile.write('    TH2F_axisy.push_back(temp_TH2F_titley[i]);\n')
    initfile.write('  }\n')
    initfile.write('\n')
    initfile.write('  for (int i=0 ; i < num_TH1F_PerTSs ; i++) {\n')
    initfile.write('    vector<vector<TH1F*> > temp_TH1F_vector_vector;\n')
    initfile.write('    TH1F_PerTSs.push_back(temp_TH1F_vector_vector);\n')
    initfile.write('    TH1F_PerTS_names.push_back(temp_TH1F_PerTS_name[i]);\n')
    initfile.write('    TH1F_PerTS_nbinsx.push_back(temp_TH1F_PerTS_nbinsx[i]);\n')
    initfile.write('    TH1F_PerTS_lowx.push_back(temp_TH1F_PerTS_lowx[i]);\n')
    initfile.write('    TH1F_PerTS_highx.push_back(temp_TH1F_PerTS_highx[i]);\n')
    initfile.write('    TH1F_PerTS_axisx.push_back(temp_TH1F_PerTS_titlex[i]);\n')
    initfile.write('  }\n')
    initfile.write('\n')
    initfile.write('  for (int i=0 ; i < num_TH2F_PerTSs ; i++) {\n')
    initfile.write('    vector<vector<TH2F*> > temp_TH2F_vector_vector;\n')
    initfile.write('    TH2F_PerTSs.push_back(temp_TH2F_vector_vector);\n')
    initfile.write('    TH2F_PerTS_names.push_back(temp_TH2F_PerTS_name[i]);\n')
    initfile.write('    TH2F_PerTS_nbinsx.push_back(temp_TH2F_PerTS_nbinsx[i]);\n')
    initfile.write('    TH2F_PerTS_lowx.push_back(temp_TH2F_PerTS_lowx[i]);\n')
    initfile.write('    TH2F_PerTS_highx.push_back(temp_TH2F_PerTS_highx[i]);\n')
    initfile.write('    TH2F_PerTS_axisx.push_back(temp_TH2F_PerTS_titlex[i]);\n')
    initfile.write('    TH2F_PerTS_nbinsy.push_back(temp_TH2F_PerTS_nbinsy[i]);\n')
    initfile.write('    TH2F_PerTS_lowy.push_back(temp_TH2F_PerTS_lowy[i]);\n')
    initfile.write('    TH2F_PerTS_highy.push_back(temp_TH2F_PerTS_highy[i]);\n')
    initfile.write('    TH2F_PerTS_axisy.push_back(temp_TH2F_PerTS_titley[i]);\n')
    initfile.write('  }\n')
    initfile.write('\n')
    initfile.write('}\n')
    initfile.write('\n')

##### PARSING FUNCTIONS #####

def fill_data(temp_data):
    for i in range(len(definitions)):
        if definitions[i][0] == temp_data['type']:
            data[i].append([[],[],[]])
            for j in range(len(block_definitions)):
                data[i][-1][1].append([])
            for j in range(len(definitions[i][1])):
                data[i][-1][0].append(temp_data[definitions[i][1][j]]) 

temp_suites = []
def fill_suites():
    for temp_suite in temp_suites:
        suites.append([ temp_suite['code'] , temp_suite['name'] ])
        for key in temp_suite:
            if ((key != 'name') and (key != 'code')):
                for i in range(len(definitions)):
                    if definitions[i][0] == key:
                        for test in temp_suite[key].split(','):
                            for j in range(len(data[i])):
                                if data[i][j][0][0] == test.strip():
                                    data[i][j][2].append(temp_suite['code'])

# blocks[block_number][0] = test_type
# blocks[block_number][1] = test_name
# blocks[block_number][2] = block_type
# blocks[block_number][3] = array of lines in block
blocks = []
def fill_blocks():
    for block in blocks:
        for i in range(len(definitions)):
            if definitions[i][0] == block[0]:
                for j in range(len(data[i])):
                    if data[i][j][0][0] == block[1]:
                        for k in range(len(block_definitions)):
                            if block_definitions[k] == block[2]:
                                for line in block[3]:
                                    data[i][j][1][k].append(line)

##### MAIN #####


###### INITIALIZE  ######

cfg_file = open(cfgfile_name,"r")
lines = cfg_file.readlines()
cfg_file.close()

# data[type] = array of tests of 'type'
# data[type][test][0] = array of parameters for 'test'
# data[type][test][0][0] = 'name' of 'test'
# data[type][test][1] = array of blocks for 'test'
# data[type][test][2] = array of suites which include 'test'
data = []
for i in range(len(definitions)):
    data.append([])

# suites[suite_num][0] = suite_code
# suites[suite_num][1] = suite_name
suites = []

# clean start
in_def = 0
in_blo = 0
in_sui = 0
line_num = 0

##### READ CFG FILE #####

for line in lines:

    if (line.strip() != '') and (line.strip()[0] != '#'):

        if (line.strip() == '<start_definition>'):
            in_def = 1
            temp_data = {}
        if (line.strip() == '<end_definition>'):
            if (in_def == 1):
                in_def = 0
                fill_data(temp_data)
            else:
                print "ERROR: <end_definition> without <start_definition>: line number " + str(line_num)

        if (line.strip() == '<start_suite>'):
            in_sui = 1
            temp_suite = {}
        if (line.strip() == '<end_suite>'):
            if (in_sui == 1):
                in_sui = 0
                temp_suites.append(temp_suite)
            else:
                print "ERROR: <end_suite> without <start_suite>: line number " + str(line_num)

        if ((in_def == 1) and (line.strip() != '<start_definition>')):

            if (line.find('<start_block>') != -1):
                in_blo = 1
                temp_block = []
                block_name = line.split('=')[0].strip()
            if (line.strip() == '<end_block>'):
                if (in_blo == 1):
                    in_blo = 0
                    blocks.append( [ temp_data['type'] , temp_data['name'] , block_name , temp_block ] )
                else:
                    print "ERROR: <end_block> without <start_block>: line number " + str(line_num)

            if ((in_blo == 1) and (line.find('<start_block>') == -1)):# and (line.strip() != '<end_block>')):
                temp_block.append(line.rstrip())

            if ((in_blo != 1) and (line.strip() != '<end_block>')):
                temp_data[line.split('=')[0].strip()] = line.split('=')[1].strip()

        elif ((in_sui == 1) and (line.strip() != '<start_suite>')):
            temp_suite[line.split('=')[0].strip()] = line.split('=')[1].strip()
            
        elif ((line.strip() != '<end_definition>') and (line.strip() != '<start_definition>') and (line.strip() != '<start_suite>') and (line.strip() != '<end_suite>')):
            print "ERROR: statement outside of definition or suite: line " + str(line_num) + ": " + line.strip()

    line_num = line_num + 1

fill_suites()
fill_blocks()
print_init()
print_loop()
