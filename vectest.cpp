#include "tests.h"
#include "suites.h"

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <stdlib.h>

using namespace std;

int get_index (const char* test) {
  
  for (int i = 0 ; i < sizeof(tester)/sizeof(tester[0]) ; i++) {
    if (test == tester[i]) {
      return i;
    }
  }
  return -1;
}

int main() {

  int type = 1;
  
  int len = 0;

  const char** tests = get_blank();
  test_maker(type, tests, &len);
 
  int ieta = 1;
  int iphi = 1;
  int depth = 1;

  char histoName[100]; 
  
  //if (get_index(TESTS1) != -1) {
  //  cout << "YES" << endl;
  //  //vector<TH2F*> TEST1;
  //}

  for (int i = 0 ; i < len ; i++) {
    if (get_index(tests[i]) != -1) {
      sprintf(histoName,"%s_iEta%i_iPhi%i_Depth%i",tests[i],ieta,iphi,(depth-1)/2+1);
      cout << histoName << endl;
      //      CapIDvsBX.push_back(new TH2F(histoName,histoName,bins_x(get_index(tests[i])),low_x(get_index(tests[i])),high_x(get_index(tests[i])),bins_y(get_index(tests[i])),low_y(get_index(tests[i])),high_y(get_index(tests[i]))));
    }
    else {
      cout << "ERROR: INVALID TEST" << endl;
    }
  }
}
