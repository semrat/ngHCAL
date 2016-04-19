import os

parameters = ['bins_x','low_x','high_x','bins_y','low_y','high_y']

def main():
    cfg_data = read_cfg()
    tests,suites = parse_cfg(cfg_data)
    generate_tests_file(tests)
    generate_suites_file(suites)
    
def read_cfg():
    cfg_file = open('tests.cfg','r')
    lines = cfg_file.readlines()
    cfg_file.close()
    return lines

def parse_cfg(lines):
    tests = {}
    suites = {}
    kind = 'null'
    for line in lines:
        if (line.rstrip() != '') and (len(line.split()) > 1):
            if line.split()[1] == 'test_name':
                kind = 'test'
            elif line.split()[1] == 'suite_number':
                kind = 'suite'
            if (line[0] != '#'):
                if (kind == 'test'):
                    test_name = line.split()[0]
                    tests[test_name] = {}
                    for i in range(len(parameters)):
                        tests[test_name][parameters[i]] = line.split()[i+1]
                if (kind == 'suite'):
                    suite_number = line.split()[0]
                    tests_string = line.split()[1]
                    num_tests = len(line.split()[1].split(','))
                    suites[suite_number] = {}
                    suites[suite_number]['tests_string'] = tests_string
                    suites[suite_number]['num_tests'] = num_tests
    return tests, suites

def generate_tests_file(tests):
    os.system('rm ./tests.h')
    os.system('touch ./tests.h')
    tests_file = open('tests.h','w')
    tests_file.write('#define NUM ' + str(len(tests)) + '\n')
    tests_file.write('\n')
    tests_file.write('const char *tester[] = {')
    for test in tests:
        tests_file.write(test)
        if (test != tests.keys()[-1]):
            tests_file.write(', ')
    tests_file.write('};\n')
    tests_file.write('\n')
    tests_file.write('const char *tests[NUM];\n')
    tests_file.write('\n')
    tests_file.write('const char** get_blank(){\n')
    tests_file.write('  for (int i = 0 ; i < sizeof(tests)/sizeof(tests[0]) ; i++) {\n')
    tests_file.write('    tests[i] = "";\n')
    tests_file.write('  }\n')
    tests_file.write('  return tests;\n')
    tests_file.write('}\n')
    tests_file.write('\n')
    for parameter in parameters:
        tests_file.write('const int ' + parameter + ' [NUM] =\n')
        tests_file.write('\n')
        tests_file.write('  {\n')
        tests_file.write('\n')
        for test in tests:
            tests_file.write('    ' + tests[test][parameter])
            if (test != tests.keys()[-1]):
                tests_file.write(',')
            tests_file.write('   // ' + test + '\n')
        tests_file.write('\n')
        tests_file.write('  };\n')
        tests_file.write('\n')
    tests_file.close()

def generate_suites_file(suites):
    os.system('rm ./suites.h')
    os.system('touch ./suites.h')
    suites_file = open('suites.h','w')
    suites_file.write('#include <iostream>\n')
    suites_file.write('\n')
    for suite in suites:
        suites_file.write('#define TESTS' + suite + ' ' + suites[suite]['tests_string'] + '\n')
        suites_file.write('#define LEN' + suite + '  ' + str(suites[suite]['num_tests']) + '\n')
    suites_file.write('\n')
    suites_file.write('using namespace std;\n')
    suites_file.write('\n')
    suites_file.write('void test_maker(int type, const char** tests, int *len){\n')
    suites_file.write('\n')
    suites_file.write('  switch(type) {\n')
    suites_file.write('\n')
    for suite in suites:
        suites_file.write('  case ' + suite + ': {\n')
        suites_file.write('    const char *temp[] = {TESTS' + suite + '};\n')
        suites_file.write('    for (int i = 0 ; i < LEN' + suite + ' ; i++) {\n')
        suites_file.write('      tests[i] = temp[i];\n')
        suites_file.write('    }\n')
        suites_file.write('    *len = LEN' + suite + ';\n')
        suites_file.write('    break;\n')
        suites_file.write('  }\n')
        suites_file.write('\n')
    suites_file.write('  default: {\n')
    suites_file.write('    cout << "ERROR: INVALID TEST CODE" << endl;\n')
    suites_file.write('  }\n')
    suites_file.write('\n')
    suites_file.write('  }\n')
    suites_file.write('\n')
    suites_file.write('}\n')
    suites_file.write('\n')
    suites_file.close()
    
main()
