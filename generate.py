cfg_file = open("QIE10_testing.cfg","r")
lines = cfg_file.readlines()
cfg_file.close()

loopfile_name = "QIE10_loop.h"

initfile_name = "init.out"

##### DEFINITIONS #####

types = {

    'TH1F'       : ["name" , "nbinsx" , "lowx" , "highx" , "titlex"] ,
    'TH2F'       : ["name" , "nbinsx" , "lowx" , "highx" , "titlex" , "nbinsy" , "lowy" , "highy" , "titley"] ,
    'TH1F_perTS' : ["name" , "nbinsx" , "lowx" , "highx" , "titlex"] ,
    'TH2F_perTS' : ["name" , "nbinsx" , "lowx" , "highx" , "titlex" , "nbinsy" , "lowy" , "highy" , "titley"] ,
    'logger'     : ["name" , "log_file" , "mode"] ,
    'stdout'     : ["name"] ,
    'null'       : ["name"] ,
    'TTree'      : ["name"]

}

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

data_map = {

    'TH1F'       : 0 , 
    'TH2F'       : 1 ,
    'TH1F_perTS' : 2 ,
    'TH2F_perTS' : 3 ,
    'logger'     : 4 ,
    'stdout'     : 5 ,
    'null'       : 6 ,
    'TTree '     : 7

}

types_map = [

    'TH1F' ,
    'TH2F' ,
    'TH1F_perTS' ,
    'TH2F_perTS' ,
    'logger' ,
    'stdout' ,
    'null' ,
    'TTree'

]

suites_map = [

    'code' ,
    'name' ,

]

data = [

    [] , # TH1F 
    [] , # TH2F
    [] , # TH1F_perTS
    [] , # TH2F_perTS
    [] , # logger
    [] , # stdout
    [] , # null
    [] , #TTree

]

loop_map = {

    'loop_vars' : 0 ,
    'pre_loop'  : 1 ,
    'loop'      : 2 ,
    'post_loop' : 3

}

loop_form = [

    'loop_vars' ,
    'pre_loop' ,
    'loop' ,
    'post_loop'

]

loop_data = [

    # [ [ name ] [ according to loop_map ] ]
    {} , # TH1F 
    {} , # TH2F
    {} , # TH1F_perTS
    {} , # TH2F_perTS
    {} , # logger
    {} , # stdout
    {} , # null
    {} , # TTree

]

suites = []

##### PRINTING FUNCTIONS #####

def print_header(infile,infile_name):
    infile.write('\\ #############################################################\n')
    infile.write('\\ #############################################################\n')
    infile.write('\\ ###' + ''.center(55)  + '###\n')
    infile.write('\\ ###' + infile_name.center(55)  + '###\n')
    infile.write('\\ ###' + ''.center(55)  + '###\n')
    infile.write('\\ ###' + 'This file was written by a robot!'.center(55)  + '###\n')
    infile.write('\\ ###' + 'Do not edit by hand!'.center(55)  + '###\n')
    infile.write('\\ ###' + ''.center(55)  + '###\n')
    infile.write('\\ ###' + 'Instead, modify the configuration file:'.center(55)  + '###\n')
    infile.write('\\ ###' + ' QIE10_testing.cfg'.center(55)  + '###\n')
    infile.write('\\ ###' + 'and then rebuild with:'.center(55)  + '###\n')
    infile.write('\\ ###' + './rebuild'.center(55)  + '###\n')
    infile.write('\\ ###' + ''.center(55)  + '###\n')
    infile.write('\\ ###' + 'Joseph Mariano -- jmariano@cern.ch'.center(55)  + '###\n')
    infile.write('\\ ###' + '27-04-2016'.center(55)  + '###\n')
    infile.write('\\ ###' + ''.center(55)  + '###\n')
    infile.write('\\ #############################################################\n')
    infile.write('\\ #############################################################\n')
    infile.write('\n')

def print_loop():

    loopfile = open(loopfile_name,'w')

    print_header(loopfile, loopfile_name)

    loopfile.write('#include <vector>\n')
    loopfile.write('\n')
    loopfile.write('#include "TH1D.h"\n')
    loopfile.write('#include "TH2D.h"\n')
    loopfile.write('\n')
    loopfile.write('using namespace std;\n')
    loopfile.write('\n')
    loopfile.write('\\\ ########################\n')
    loopfile.write('\\\ # LOOP_VARS STRUCTURES #\n')
    loopfile.write('\\\ ########################\n')
    loopfile.write('\n')
    for i in range(len(suites)):
        loopfile.write('\\\ --- Suite ' + suites[i][0] + ': ' + suites[i][1] + ' ---\n')
        loopfile.write('\n')
        loopfile.write('struct loop_vars {\n')
        loopfile.write('\n')
        for j in range(len(loop_data)):
            for key in loop_data[j]:
                if key in suites[i][2][j]:
                    for line in loop_data[j][key][0]:
                        loopfile.write(line + '\n')
        loopfile.write('\n')
        loopfile.write('};\n')
        loopfile.write('\n')
    loopfile.write('\\\ #############\n')
    loopfile.write('\\\ # PRE_LOOPS #\n')
    loopfile.write('\\\ #############\n')
    loopfile.write('\n')
    for i in range(len(suites)):
        loopfile.write('\\\ --- Suite ' + suites[i][0] + ': ' + suites[i][1] + ' ---\n')
        loopfile.write('\n')
        loopfile.write('loop_vars pre_loop() {\n')
        loopfile.write('\n')
        loopfile.write('  loop_vars output;\n')
        loopfile.write('\n')
        for j in range(len(loop_data)):
            for key in loop_data[j]:
                if key in suites[i][2][j]:
                    for line in loop_data[j][key][1]:
                        loopfile.write(line + '\n')
        loopfile.write('\n')
        loopfile.write('  return output;\n')
        loopfile.write('\n')
        loopfile.write('};\n')
        loopfile.write('\n')
    loopfile.write('\\\ #########\n')
    loopfile.write('\\\ # LOOPS #\n')
    loopfile.write('\\\ #########\n')
    loopfile.write('\n')
    for i in range(len(suites)):
        loopfile.write('\\\ --- Suite ' + suites[i][0] + ': ' + suites[i][1] + ' ---\n')
        loopfile.write('\n')
        loopfile.write('loop_vars loop(int nTS, int nCH, QIE10DataFrame digis, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs, vector<string> &TH1F_names, vector<vector<TH2F*> > &TH2Fs, vector<string> &TH2F_names) {\n')
        loopfile.write('\n')
        for j in range(len(loop_data)):
            for key in loop_data[j]:
                if key in suites[i][2][j]:
                    for line in loop_data[j][key][2]:
                        loopfile.write(line + '\n')
        loopfile.write('\n')
        loopfile.write('  return prevars;\n')
        loopfile.write('\n')
        loopfile.write('};\n')
        loopfile.write('\n')
    loopfile.write('\\\ ##############\n')
    loopfile.write('\\\ # POST_LOOPS #\n')
    loopfile.write('\\\ ##############\n')
    loopfile.write('\n')
    for i in range(len(suites)):
        loopfile.write('\\\ --- Suite ' + suites[i][0] + ': ' + suites[i][1] + ' ---\n')
        loopfile.write('\n')
        loopfile.write('void post_loop(int nCH, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs, vector<string> &TH1F_names, vector<vector<TH2F*> > &TH2Fs, vector<string> &TH2F_names) {\n')
        loopfile.write('\n')
        for j in range(len(loop_data)):
            for key in loop_data[j]:
                if key in suites[i][2][j]:
                    for line in loop_data[j][key][3]:
                        loopfile.write(line + '\n')
        loopfile.write('\n')
        loopfile.write('};\n')
        loopfile.write('\n')

def print_init():

    initfile = open(initfile_name,'w')

    print_header(initfile,initfile_name)

    initfile.write('#include <vector>\n')
    initfile.write('\n')
    initfile.write('#include "TH1D.h"\n')
    initfile.write('#include "TH2D.h"\n')
    initfile.write('\n')
    initfile.write('\\\ #########\n')
    initfile.write('\\\ # TESTS #\n')
    initfile.write('\\\ #########\n')
    initfile.write('\n')
    for i in range(len(data)):
        initfile.write('\\\ #####  ' + types_map[i] + 's  #####\n')
        initfile.write('\n')
        for j in range(len(data[i])):
            initfile.write('\\\ --- ' + types_map[i] + ' ' + str(j) + ' ---\n')
            for k in range(len(types[types_map[i]])):
                initfile.write('#define ' + types_map[i].upper() + '_' + str(j) + '_' + types[types_map[i]][k].upper() + ' ' + data[i][j][k] + '\n')
            initfile.write('\n')
    initfile.write('\\\ ##########\n')
    initfile.write('\\\ # SUITES #\n')
    initfile.write('\\\ ##########\n')
    initfile.write('\n')
    for i in range(len(suites)):
        initfile.write('\\\ --- Suite ' + suites[i][0] + ': ' + suites[i][1] + ' ---\n')
        for j in range(len(suites[i][2])):
            test_type = types_map[j]
            if (len(suites[i][2][j]) > 0):
                initfile.write('#define SUITE' + str(i) + '_' + test_type.upper() + '_NUM' + ' ' + str(len(suites[i][2][j])) + '\n')
                for field in types[test_type]:
                    initfile.write('#define SUITE' + str(i) + '_' + test_type.upper() + '_' + field.upper() + ' ')
                    for k in range(len(suites[i][2][j])):
                        for l in range(len(data[data_map[test_type]])):
                            if data[data_map[test_type]][l][0] == suites[i][2][j][k]:
                                initfile.write(test_type.upper() + '_' + str(l) + '_' + field.upper() + ' ')
                    initfile.write('\n')
        initfile.write('\n')
    initfile.write('\\\ #################\n')
    initfile.write('\\\ # INIT FUNCTION #\n')
    initfile.write('\\\ #################\n')
    initfile.write('\n')
    initfile.write('using namespace std;\n')
    initfile.write('\n')
    initfile.write('void init(vector<vector<TH1F*> > &TH1Fs, int &num_TH1Fs, vector<string> &TH1F_names, vector<int> &TH1F_nbinsx, vector<float> &TH1F_lowx, vector<float> &TH1F_highx, vector<string> &TH1F_axisx, vector<vector<TH2F*> > &TH2Fs, int &num_TH2Fs, vector<string> &TH2F_names, vector<int> &TH2F_nbinsx, vector<float> &TH2F_lowx, vector<float> &TH2F_highx, vector<string> &TH2F_axisx, vector<int> &TH2F_nbinsy, vector<float> &TH2F_lowy, vector<float> &TH2F_highy, vector<string> &TH2F_axisy){\n')
    initfile.write('\n')
    for i in range(len(suites)):
        initfile.write('\\\ --- Suite ' + suites[i][0] + ': ' + suites[i][1] + ' ---\n')
        initfile.write('\n')
        for j in range(len(suites[i][2])):
            test_type = types_map[j]
            if (len(suites[i][2][j]) > 0):
                initfile.write('  num_' + test_type.upper() + 's = SUITE' + str(i) +'_' + test_type.upper() + '_NUM;\n')
                for field in types[test_type]:
                    initfile.write('  ' + cpp_types[field] + ' temp_' + test_type.upper() + '_' + field + '[num_' + test_type.upper() + 's]')
                    if (cpp_types[field] == "char"):
                                initfile.write('[100]')
                    initfile.write(' = {SUITE' + str(i) + '_' + test_type.upper() + '_' +field.upper() + '};\n')
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
    initfile.write('}\n')
    initfile.write('\n')

##### PARSING FUNCTIONS #####

def fill_data(temp_data):
    data[data_map[temp_data['type']]].append([])
    for field in types[temp_data['type']]:
        data[data_map[temp_data['type']]][-1].append(temp_data[field])

def fill_suite(temp_suite):
    suites.append([])
    for field in suites_map:
        suites[-1].append(temp_suite[field])
    suites[-1].append([])
    for field in types_map:
        suites[-1][-1].append([])
        if field in temp_suite:
            for test in temp_suite[field].split(','):
                suites[-1][-1][-1].append(test.strip())

def fill_block(temp_block,block_type,test_type,name):
    if name not in loop_data[data_map[test_type]]:
        loop_data[data_map[test_type]][name] = [[],[],[],[]]
    for line in temp_block:
        loop_data[data_map[test_type]][name][loop_map[block_type]].append(line)    
    
##### MAIN #####

in_def = 0
in_blo = 0
in_sui = 0
line_num = 0

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
                fill_suite(temp_suite) 
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
                    fill_block(temp_block,block_name,temp_data['type'],temp_data['name'])
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

print_init()
print_loop()
