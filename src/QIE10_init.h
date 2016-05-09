// #############################################################
// #############################################################
// ###                                                       ###
// ###                      QIE10_init.h                     ###
// ###                                                       ###
// ###           This file was written by a robot!           ###
// ###                  Do not edit by hand!                 ###
// ###                                                       ###
// ###        Instead, modify the configuration file:        ###
// ###                    QIE10_testing.cfg                  ###
// ###                 and then rebuild with:                ###
// ###                       ./rebuild                       ###
// ###                                                       ###
// ###           Joseph Mariano -- jmariano@cern.ch          ###
// ###                       27-04-2016                      ###
// ###                                                       ###
// #############################################################
// #############################################################

#include <vector>

#include "TH1D.h"
#include "TH2D.h"

// #########
// # TESTS #
// #########

// #####  TH1Fs  #####

// --- TH1F 0 ---
#define TH1F_0_NAME "QSum"
#define TH1F_0_NBINSX 128
#define TH1F_0_LOWX 0
#define TH1F_0_HIGHX 10000
#define TH1F_0_TITLEX "Integrated Charge (fC)"

// --- TH1F 1 ---
#define TH1F_1_NAME "MaxTS"
#define TH1F_1_NBINSX 128
#define TH1F_1_LOWX 0
#define TH1F_1_HIGHX 10000
#define TH1F_1_TITLEX "Largest TS in a single bin (fC)"

// --- TH1F 2 ---
#define TH1F_2_NAME "Width"
#define TH1F_2_NBINSX 25
#define TH1F_2_LOWX 0
#define TH1F_2_HIGHX 75
#define TH1F_2_TITLEX "Width (ns)"

// #####  TH2Fs  #####

// --- TH2F 0 ---
#define TH2F_0_NAME "ADCpulse"
#define TH2F_0_NBINSX 10
#define TH2F_0_LOWX -0.5
#define TH2F_0_HIGHX 9.5
#define TH2F_0_TITLEX "TS"
#define TH2F_0_NBINSY 256
#define TH2F_0_LOWY -0.5
#define TH2F_0_HIGHY 255.5
#define TH2F_0_TITLEY "ADC Counts"

// --- TH2F 1 ---
#define TH2F_1_NAME "leTDCpulse"
#define TH2F_1_NBINSX 10
#define TH2F_1_LOWX -0.5
#define TH2F_1_HIGHX 9.5
#define TH2F_1_TITLEX "TS"
#define TH2F_1_NBINSY 64
#define TH2F_1_LOWY -0.5
#define TH2F_1_HIGHY 63.5
#define TH2F_1_TITLEY "TDC Counts (0.5 ns)"

// --- TH2F 2 ---
#define TH2F_2_NAME "teTDCpulse"
#define TH2F_2_NBINSX 10
#define TH2F_2_LOWX -0.5
#define TH2F_2_HIGHX 9.5
#define TH2F_2_TITLEX "TS"
#define TH2F_2_NBINSY 32
#define TH2F_2_LOWY -0.5
#define TH2F_2_HIGHY 31.5
#define TH2F_2_TITLEY "TDC Counts (25/16 ns)"

// --- TH2F 3 ---
#define TH2F_3_NAME "Qpulse"
#define TH2F_3_NBINSX 10
#define TH2F_3_LOWX -0.5
#define TH2F_3_HIGHX 9.5
#define TH2F_3_TITLEX "TS"
#define TH2F_3_NBINSY 256
#define TH2F_3_LOWY 0
#define TH2F_3_HIGHY 10000
#define TH2F_3_TITLEY "Q (fC)"

// #####  TH1F_PerTSs  #####

// --- TH1F_PerTS 0 ---
#define TH1F_PERTS_0_NAME "ADC"
#define TH1F_PERTS_0_NBINSX 256
#define TH1F_PERTS_0_LOWX -0.5
#define TH1F_PERTS_0_HIGHX 255.5
#define TH1F_PERTS_0_TITLEX "ADC Counts"

// #####  TH2F_PerTSs  #####

// --- TH2F_PerTS 0 ---
#define TH2F_PERTS_0_NAME "ADCvsTDC"
#define TH2F_PERTS_0_NBINSX 64
#define TH2F_PERTS_0_LOWX -0.5
#define TH2F_PERTS_0_HIGHX 63.5
#define TH2F_PERTS_0_TITLEX "TDC Counts (0.5 ns)"
#define TH2F_PERTS_0_NBINSY 256
#define TH2F_PERTS_0_LOWY -0.5
#define TH2F_PERTS_0_HIGHY 255.5
#define TH2F_PERTS_0_TITLEY "ADC Counts"

// #####  loggers  #####

// #####  stdouts  #####

// #####  TTrees  #####

// ##########
// # SUITES #
// ##########

// --- Suite 0: "full" ---
#define SUITE0_TH1F_NUM 3
#define SUITE0_TH1F_NAME TH1F_0_NAME , TH1F_1_NAME , TH1F_2_NAME , 
#define SUITE0_TH1F_NBINSX TH1F_0_NBINSX , TH1F_1_NBINSX , TH1F_2_NBINSX , 
#define SUITE0_TH1F_LOWX TH1F_0_LOWX , TH1F_1_LOWX , TH1F_2_LOWX , 
#define SUITE0_TH1F_HIGHX TH1F_0_HIGHX , TH1F_1_HIGHX , TH1F_2_HIGHX , 
#define SUITE0_TH1F_TITLEX TH1F_0_TITLEX , TH1F_1_TITLEX , TH1F_2_TITLEX , 
#define SUITE0_TH2F_NUM 4
#define SUITE0_TH2F_NAME TH2F_0_NAME , TH2F_1_NAME , TH2F_2_NAME , TH2F_3_NAME , 
#define SUITE0_TH2F_NBINSX TH2F_0_NBINSX , TH2F_1_NBINSX , TH2F_2_NBINSX , TH2F_3_NBINSX , 
#define SUITE0_TH2F_LOWX TH2F_0_LOWX , TH2F_1_LOWX , TH2F_2_LOWX , TH2F_3_LOWX , 
#define SUITE0_TH2F_HIGHX TH2F_0_HIGHX , TH2F_1_HIGHX , TH2F_2_HIGHX , TH2F_3_HIGHX , 
#define SUITE0_TH2F_TITLEX TH2F_0_TITLEX , TH2F_1_TITLEX , TH2F_2_TITLEX , TH2F_3_TITLEX , 
#define SUITE0_TH2F_NBINSY TH2F_0_NBINSY , TH2F_1_NBINSY , TH2F_2_NBINSY , TH2F_3_NBINSY , 
#define SUITE0_TH2F_LOWY TH2F_0_LOWY , TH2F_1_LOWY , TH2F_2_LOWY , TH2F_3_LOWY , 
#define SUITE0_TH2F_HIGHY TH2F_0_HIGHY , TH2F_1_HIGHY , TH2F_2_HIGHY , TH2F_3_HIGHY , 
#define SUITE0_TH2F_TITLEY TH2F_0_TITLEY , TH2F_1_TITLEY , TH2F_2_TITLEY , TH2F_3_TITLEY , 
#define SUITE0_TH1F_PERTS_NUM 1
#define SUITE0_TH1F_PERTS_NAME TH1F_PERTS_0_NAME , 
#define SUITE0_TH1F_PERTS_NBINSX TH1F_PERTS_0_NBINSX , 
#define SUITE0_TH1F_PERTS_LOWX TH1F_PERTS_0_LOWX , 
#define SUITE0_TH1F_PERTS_HIGHX TH1F_PERTS_0_HIGHX , 
#define SUITE0_TH1F_PERTS_TITLEX TH1F_PERTS_0_TITLEX , 
#define SUITE0_TH2F_PERTS_NUM 1
#define SUITE0_TH2F_PERTS_NAME TH2F_PERTS_0_NAME , 
#define SUITE0_TH2F_PERTS_NBINSX TH2F_PERTS_0_NBINSX , 
#define SUITE0_TH2F_PERTS_LOWX TH2F_PERTS_0_LOWX , 
#define SUITE0_TH2F_PERTS_HIGHX TH2F_PERTS_0_HIGHX , 
#define SUITE0_TH2F_PERTS_TITLEX TH2F_PERTS_0_TITLEX , 
#define SUITE0_TH2F_PERTS_NBINSY TH2F_PERTS_0_NBINSY , 
#define SUITE0_TH2F_PERTS_LOWY TH2F_PERTS_0_LOWY , 
#define SUITE0_TH2F_PERTS_HIGHY TH2F_PERTS_0_HIGHY , 
#define SUITE0_TH2F_PERTS_TITLEY TH2F_PERTS_0_TITLEY , 

// #################
// # INIT FUNCTION #
// #################

using namespace std;

void init(
vector<vector<TH1F*> > &TH1Fs, int &num_TH1Fs, vector<string> &TH1F_names, vector<int> &TH1F_nbinsx, vector<float> &TH1F_lowx, vector<float> &TH1F_highx, vector<string> &TH1F_axisx,
vector<vector<vector<TH1F*> > > &TH1F_PerTSs, int &num_TH1F_PerTSs, vector<string> &TH1F_PerTS_names, vector<int> &TH1F_PerTS_nbinsx, vector<float> &TH1F_PerTS_lowx, vector<float> &TH1F_PerTS_highx, vector<string> &TH1F_PerTS_axisx,
vector<vector<TH2F*> > &TH2Fs, int &num_TH2Fs, vector<string> &TH2F_names, vector<int> &TH2F_nbinsx, vector<float> &TH2F_lowx, vector<float> &TH2F_highx, vector<string> &TH2F_axisx, vector<int> &TH2F_nbinsy, vector<float> &TH2F_lowy, vector<float> &TH2F_highy, vector<string> &TH2F_axisy,
vector<vector<vector<TH2F*> > > &TH2F_PerTSs, int &num_TH2F_PerTSs, vector<string> &TH2F_PerTS_names, vector<int> &TH2F_PerTS_nbinsx, vector<float> &TH2F_PerTS_lowx, vector<float> &TH2F_PerTS_highx, vector<string> &TH2F_PerTS_axisx, vector<int> &TH2F_PerTS_nbinsy, vector<float> &TH2F_PerTS_lowy, vector<float> &TH2F_PerTS_highy, vector<string> &TH2F_PerTS_axisy){

// --- Suite 0: "full" ---

  num_TH1Fs = SUITE0_TH1F_NUM;
  char temp_TH1F_name[num_TH1Fs][100] = {SUITE0_TH1F_NAME};
  int temp_TH1F_nbinsx[num_TH1Fs] = {SUITE0_TH1F_NBINSX};
  float temp_TH1F_lowx[num_TH1Fs] = {SUITE0_TH1F_LOWX};
  float temp_TH1F_highx[num_TH1Fs] = {SUITE0_TH1F_HIGHX};
  char temp_TH1F_titlex[num_TH1Fs][100] = {SUITE0_TH1F_TITLEX};

  num_TH2Fs = SUITE0_TH2F_NUM;
  char temp_TH2F_name[num_TH2Fs][100] = {SUITE0_TH2F_NAME};
  int temp_TH2F_nbinsx[num_TH2Fs] = {SUITE0_TH2F_NBINSX};
  float temp_TH2F_lowx[num_TH2Fs] = {SUITE0_TH2F_LOWX};
  float temp_TH2F_highx[num_TH2Fs] = {SUITE0_TH2F_HIGHX};
  char temp_TH2F_titlex[num_TH2Fs][100] = {SUITE0_TH2F_TITLEX};
  int temp_TH2F_nbinsy[num_TH2Fs] = {SUITE0_TH2F_NBINSY};
  float temp_TH2F_lowy[num_TH2Fs] = {SUITE0_TH2F_LOWY};
  float temp_TH2F_highy[num_TH2Fs] = {SUITE0_TH2F_HIGHY};
  char temp_TH2F_titley[num_TH2Fs][100] = {SUITE0_TH2F_TITLEY};

  num_TH1F_PerTSs = SUITE0_TH1F_PERTS_NUM;
  char temp_TH1F_PerTS_name[num_TH1F_PerTSs][100] = {SUITE0_TH1F_PERTS_NAME};
  int temp_TH1F_PerTS_nbinsx[num_TH1F_PerTSs] = {SUITE0_TH1F_PERTS_NBINSX};
  float temp_TH1F_PerTS_lowx[num_TH1F_PerTSs] = {SUITE0_TH1F_PERTS_LOWX};
  float temp_TH1F_PerTS_highx[num_TH1F_PerTSs] = {SUITE0_TH1F_PERTS_HIGHX};
  char temp_TH1F_PerTS_titlex[num_TH1F_PerTSs][100] = {SUITE0_TH1F_PERTS_TITLEX};

  num_TH2F_PerTSs = SUITE0_TH2F_PERTS_NUM;
  char temp_TH2F_PerTS_name[num_TH2F_PerTSs][100] = {SUITE0_TH2F_PERTS_NAME};
  int temp_TH2F_PerTS_nbinsx[num_TH2F_PerTSs] = {SUITE0_TH2F_PERTS_NBINSX};
  float temp_TH2F_PerTS_lowx[num_TH2F_PerTSs] = {SUITE0_TH2F_PERTS_LOWX};
  float temp_TH2F_PerTS_highx[num_TH2F_PerTSs] = {SUITE0_TH2F_PERTS_HIGHX};
  char temp_TH2F_PerTS_titlex[num_TH2F_PerTSs][100] = {SUITE0_TH2F_PERTS_TITLEX};
  int temp_TH2F_PerTS_nbinsy[num_TH2F_PerTSs] = {SUITE0_TH2F_PERTS_NBINSY};
  float temp_TH2F_PerTS_lowy[num_TH2F_PerTSs] = {SUITE0_TH2F_PERTS_LOWY};
  float temp_TH2F_PerTS_highy[num_TH2F_PerTSs] = {SUITE0_TH2F_PERTS_HIGHY};
  char temp_TH2F_PerTS_titley[num_TH2F_PerTSs][100] = {SUITE0_TH2F_PERTS_TITLEY};

  for (int i=0 ; i < num_TH1Fs ; i++) {
    vector<TH1F*> temp_TH1F_vector;
    TH1Fs.push_back(temp_TH1F_vector);
    TH1F_names.push_back(temp_TH1F_name[i]);
    TH1F_nbinsx.push_back(temp_TH1F_nbinsx[i]);
    TH1F_lowx.push_back(temp_TH1F_lowx[i]);
    TH1F_highx.push_back(temp_TH1F_highx[i]);
    TH1F_axisx.push_back(temp_TH1F_titlex[i]);
  }

  for (int i=0 ; i < num_TH2Fs ; i++) {
    vector<TH2F*> temp_TH2F_vector;
    TH2Fs.push_back(temp_TH2F_vector);
    TH2F_names.push_back(temp_TH2F_name[i]);
    TH2F_nbinsx.push_back(temp_TH2F_nbinsx[i]);
    TH2F_lowx.push_back(temp_TH2F_lowx[i]);
    TH2F_highx.push_back(temp_TH2F_highx[i]);
    TH2F_axisx.push_back(temp_TH2F_titlex[i]);
    TH2F_nbinsy.push_back(temp_TH2F_nbinsy[i]);
    TH2F_lowy.push_back(temp_TH2F_lowy[i]);
    TH2F_highy.push_back(temp_TH2F_highy[i]);
    TH2F_axisy.push_back(temp_TH2F_titley[i]);
  }

  for (int i=0 ; i < num_TH1F_PerTSs ; i++) {
    vector<vector<TH1F*> > temp_TH1F_vector_vector;
    TH1F_PerTSs.push_back(temp_TH1F_vector_vector);
    TH1F_PerTS_names.push_back(temp_TH1F_PerTS_name[i]);
    TH1F_PerTS_nbinsx.push_back(temp_TH1F_PerTS_nbinsx[i]);
    TH1F_PerTS_lowx.push_back(temp_TH1F_PerTS_lowx[i]);
    TH1F_PerTS_highx.push_back(temp_TH1F_PerTS_highx[i]);
    TH1F_PerTS_axisx.push_back(temp_TH1F_PerTS_titlex[i]);
  }

  for (int i=0 ; i < num_TH2F_PerTSs ; i++) {
    vector<vector<TH2F*> > temp_TH2F_vector_vector;
    TH2F_PerTSs.push_back(temp_TH2F_vector_vector);
    TH2F_PerTS_names.push_back(temp_TH2F_PerTS_name[i]);
    TH2F_PerTS_nbinsx.push_back(temp_TH2F_PerTS_nbinsx[i]);
    TH2F_PerTS_lowx.push_back(temp_TH2F_PerTS_lowx[i]);
    TH2F_PerTS_highx.push_back(temp_TH2F_PerTS_highx[i]);
    TH2F_PerTS_axisx.push_back(temp_TH2F_PerTS_titlex[i]);
    TH2F_PerTS_nbinsy.push_back(temp_TH2F_PerTS_nbinsy[i]);
    TH2F_PerTS_lowy.push_back(temp_TH2F_PerTS_lowy[i]);
    TH2F_PerTS_highy.push_back(temp_TH2F_PerTS_highy[i]);
    TH2F_PerTS_axisy.push_back(temp_TH2F_PerTS_titley[i]);
  }

}

