// #############################################################
// #############################################################
// ###                                                       ###
// ###                     ./QIE10_init.h                    ###
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
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "TH1D.h"
#include "TH2D.h"
#include "TProfile.h"

// #########
// # TESTS #
// #########

// #####  TH1F_perEVs  #####

// --- TH1F_perEV 0 ---
#define TH1F_PEREV_0_NAME "ADC_spectrum_EV"
#define TH1F_PEREV_0_NBINSX 256
#define TH1F_PEREV_0_LOWX -0.5
#define TH1F_PEREV_0_HIGHX 255.5
#define TH1F_PEREV_0_TITLEX "ADC"

// --- TH1F_perEV 1 ---
#define TH1F_PEREV_1_NAME "TDC_spectrum_EV"
#define TH1F_PEREV_1_NBINSX 64
#define TH1F_PEREV_1_LOWX -0.5
#define TH1F_PEREV_1_HIGHX 63.5
#define TH1F_PEREV_1_TITLEX "TDC"

// #####  TH2F_perEVs  #####

// --- TH2F_perEV 0 ---
#define TH2F_PEREV_0_NAME "ADC_vs_TS_EV"
#define TH2F_PEREV_0_NBINSX tTS
#define TH2F_PEREV_0_LOWX -0.5
#define TH2F_PEREV_0_HIGHX (float)tTS - (float)0.5
#define TH2F_PEREV_0_TITLEX "TS"
#define TH2F_PEREV_0_NBINSY 256
#define TH2F_PEREV_0_LOWY -0.5
#define TH2F_PEREV_0_HIGHY 255.5
#define TH2F_PEREV_0_TITLEY "ADC"

// --- TH2F_perEV 1 ---
#define TH2F_PEREV_1_NAME "TDC_vs_TS_EV"
#define TH2F_PEREV_1_NBINSX tTS
#define TH2F_PEREV_1_LOWX -0.5
#define TH2F_PEREV_1_HIGHX (float)tTS - (float)0.5
#define TH2F_PEREV_1_TITLEX "TS"
#define TH2F_PEREV_1_NBINSY 64
#define TH2F_PEREV_1_LOWY -0.5
#define TH2F_PEREV_1_HIGHY 63.5
#define TH2F_PEREV_1_TITLEY "TDC"

// #####  TH1F_perCHs  #####

// --- TH1F_perCH 0 ---
#define TH1F_PERCH_0_NAME "ADC_spectrum_CH"
#define TH1F_PERCH_0_NBINSX 256
#define TH1F_PERCH_0_LOWX -0.5
#define TH1F_PERCH_0_HIGHX 255.5
#define TH1F_PERCH_0_TITLEX "ADC"

// --- TH1F_perCH 1 ---
#define TH1F_PERCH_1_NAME "TDC_spectrum_CH"
#define TH1F_PERCH_1_NBINSX 64
#define TH1F_PERCH_1_LOWX -0.5
#define TH1F_PERCH_1_HIGHX 63.5
#define TH1F_PERCH_1_TITLEX "TDC"

// #####  TH2F_perCHs  #####

// --- TH2F_perCH 0 ---
#define TH2F_PERCH_0_NAME "ADC_vs_TS_CH"
#define TH2F_PERCH_0_NBINSX tTS
#define TH2F_PERCH_0_LOWX -0.5
#define TH2F_PERCH_0_HIGHX (float)tTS - (float)0.5
#define TH2F_PERCH_0_TITLEX "TS"
#define TH2F_PERCH_0_NBINSY 256
#define TH2F_PERCH_0_LOWY -0.5
#define TH2F_PERCH_0_HIGHY 255.5
#define TH2F_PERCH_0_TITLEY "ADC"

// --- TH2F_perCH 1 ---
#define TH2F_PERCH_1_NAME "TDC_vs_TS_CH"
#define TH2F_PERCH_1_NBINSX tTS
#define TH2F_PERCH_1_LOWX -0.5
#define TH2F_PERCH_1_HIGHX (float)tTS - (float)0.5
#define TH2F_PERCH_1_TITLEX "TS"
#define TH2F_PERCH_1_NBINSY 64
#define TH2F_PERCH_1_LOWY -0.5
#define TH2F_PERCH_1_HIGHY 63.5
#define TH2F_PERCH_1_TITLEY "TDC"

// #####  TH1F_PerTSs  #####

// #####  TH2F_PerTSs  #####

// #####  TProfiles  #####

// --- TProfile 0 ---
#define TPROFILE_0_NAME "ADC_vs_TS_PR"
#define TPROFILE_0_NBINSX tTS
#define TPROFILE_0_LOWX -0.5
#define TPROFILE_0_HIGHX (float)tTS - (float)0.5
#define TPROFILE_0_TITLEX "TS"
#define TPROFILE_0_NBINSY 256
#define TPROFILE_0_LOWY -0.5
#define TPROFILE_0_HIGHY 255.5
#define TPROFILE_0_TITLEY "ADC"

// #####  TTrees  #####

// #####  loggers  #####

// ##########
// # SUITES #
// ##########

// --- Suite 0: "full" ---
#define SUITE0_NULL_NUM 1
#define SUITE0_TH1F_PEREV_NUM 2
#define SUITE0_TH1F_PEREV_NAME TH1F_PEREV_0_NAME , TH1F_PEREV_1_NAME , 
#define SUITE0_TH1F_PEREV_NBINSX TH1F_PEREV_0_NBINSX , TH1F_PEREV_1_NBINSX , 
#define SUITE0_TH1F_PEREV_LOWX TH1F_PEREV_0_LOWX , TH1F_PEREV_1_LOWX , 
#define SUITE0_TH1F_PEREV_HIGHX TH1F_PEREV_0_HIGHX , TH1F_PEREV_1_HIGHX , 
#define SUITE0_TH1F_PEREV_TITLEX TH1F_PEREV_0_TITLEX , TH1F_PEREV_1_TITLEX , 
#define SUITE0_TH2F_PEREV_NUM 2
#define SUITE0_TH2F_PEREV_NAME TH2F_PEREV_0_NAME , TH2F_PEREV_1_NAME , 
#define SUITE0_TH2F_PEREV_NBINSX TH2F_PEREV_0_NBINSX , TH2F_PEREV_1_NBINSX , 
#define SUITE0_TH2F_PEREV_LOWX TH2F_PEREV_0_LOWX , TH2F_PEREV_1_LOWX , 
#define SUITE0_TH2F_PEREV_HIGHX TH2F_PEREV_0_HIGHX , TH2F_PEREV_1_HIGHX , 
#define SUITE0_TH2F_PEREV_TITLEX TH2F_PEREV_0_TITLEX , TH2F_PEREV_1_TITLEX , 
#define SUITE0_TH2F_PEREV_NBINSY TH2F_PEREV_0_NBINSY , TH2F_PEREV_1_NBINSY , 
#define SUITE0_TH2F_PEREV_LOWY TH2F_PEREV_0_LOWY , TH2F_PEREV_1_LOWY , 
#define SUITE0_TH2F_PEREV_HIGHY TH2F_PEREV_0_HIGHY , TH2F_PEREV_1_HIGHY , 
#define SUITE0_TH2F_PEREV_TITLEY TH2F_PEREV_0_TITLEY , TH2F_PEREV_1_TITLEY , 
#define SUITE0_TH1F_PERCH_NUM 2
#define SUITE0_TH1F_PERCH_NAME TH1F_PERCH_0_NAME , TH1F_PERCH_1_NAME , 
#define SUITE0_TH1F_PERCH_NBINSX TH1F_PERCH_0_NBINSX , TH1F_PERCH_1_NBINSX , 
#define SUITE0_TH1F_PERCH_LOWX TH1F_PERCH_0_LOWX , TH1F_PERCH_1_LOWX , 
#define SUITE0_TH1F_PERCH_HIGHX TH1F_PERCH_0_HIGHX , TH1F_PERCH_1_HIGHX , 
#define SUITE0_TH1F_PERCH_TITLEX TH1F_PERCH_0_TITLEX , TH1F_PERCH_1_TITLEX , 
#define SUITE0_TH2F_PERCH_NUM 2
#define SUITE0_TH2F_PERCH_NAME TH2F_PERCH_0_NAME , TH2F_PERCH_1_NAME , 
#define SUITE0_TH2F_PERCH_NBINSX TH2F_PERCH_0_NBINSX , TH2F_PERCH_1_NBINSX , 
#define SUITE0_TH2F_PERCH_LOWX TH2F_PERCH_0_LOWX , TH2F_PERCH_1_LOWX , 
#define SUITE0_TH2F_PERCH_HIGHX TH2F_PERCH_0_HIGHX , TH2F_PERCH_1_HIGHX , 
#define SUITE0_TH2F_PERCH_TITLEX TH2F_PERCH_0_TITLEX , TH2F_PERCH_1_TITLEX , 
#define SUITE0_TH2F_PERCH_NBINSY TH2F_PERCH_0_NBINSY , TH2F_PERCH_1_NBINSY , 
#define SUITE0_TH2F_PERCH_LOWY TH2F_PERCH_0_LOWY , TH2F_PERCH_1_LOWY , 
#define SUITE0_TH2F_PERCH_HIGHY TH2F_PERCH_0_HIGHY , TH2F_PERCH_1_HIGHY , 
#define SUITE0_TH2F_PERCH_TITLEY TH2F_PERCH_0_TITLEY , TH2F_PERCH_1_TITLEY , 
#define SUITE0_TH1F_PERTS_NUM 0
#define SUITE0_TH2F_PERTS_NUM 0
#define SUITE0_TPROFILE_NUM 1
#define SUITE0_TPROFILE_NAME TPROFILE_0_NAME , 
#define SUITE0_TPROFILE_NBINSX TPROFILE_0_NBINSX , 
#define SUITE0_TPROFILE_LOWX TPROFILE_0_LOWX , 
#define SUITE0_TPROFILE_HIGHX TPROFILE_0_HIGHX , 
#define SUITE0_TPROFILE_TITLEX TPROFILE_0_TITLEX , 
#define SUITE0_TPROFILE_NBINSY TPROFILE_0_NBINSY , 
#define SUITE0_TPROFILE_LOWY TPROFILE_0_LOWY , 
#define SUITE0_TPROFILE_HIGHY TPROFILE_0_HIGHY , 
#define SUITE0_TPROFILE_TITLEY TPROFILE_0_TITLEY , 
#define SUITE0_TTREE_NUM 0
#define SUITE0_LOGGER_NUM 0

// --- Suite 1: "ADC_Study" ---
#define SUITE1_NULL_NUM 1
#define SUITE1_TH1F_PEREV_NUM 1
#define SUITE1_TH1F_PEREV_NAME TH1F_PEREV_0_NAME , 
#define SUITE1_TH1F_PEREV_NBINSX TH1F_PEREV_0_NBINSX , 
#define SUITE1_TH1F_PEREV_LOWX TH1F_PEREV_0_LOWX , 
#define SUITE1_TH1F_PEREV_HIGHX TH1F_PEREV_0_HIGHX , 
#define SUITE1_TH1F_PEREV_TITLEX TH1F_PEREV_0_TITLEX , 
#define SUITE1_TH2F_PEREV_NUM 1
#define SUITE1_TH2F_PEREV_NAME TH2F_PEREV_0_NAME , 
#define SUITE1_TH2F_PEREV_NBINSX TH2F_PEREV_0_NBINSX , 
#define SUITE1_TH2F_PEREV_LOWX TH2F_PEREV_0_LOWX , 
#define SUITE1_TH2F_PEREV_HIGHX TH2F_PEREV_0_HIGHX , 
#define SUITE1_TH2F_PEREV_TITLEX TH2F_PEREV_0_TITLEX , 
#define SUITE1_TH2F_PEREV_NBINSY TH2F_PEREV_0_NBINSY , 
#define SUITE1_TH2F_PEREV_LOWY TH2F_PEREV_0_LOWY , 
#define SUITE1_TH2F_PEREV_HIGHY TH2F_PEREV_0_HIGHY , 
#define SUITE1_TH2F_PEREV_TITLEY TH2F_PEREV_0_TITLEY , 
#define SUITE1_TH1F_PERCH_NUM 1
#define SUITE1_TH1F_PERCH_NAME TH1F_PERCH_0_NAME , 
#define SUITE1_TH1F_PERCH_NBINSX TH1F_PERCH_0_NBINSX , 
#define SUITE1_TH1F_PERCH_LOWX TH1F_PERCH_0_LOWX , 
#define SUITE1_TH1F_PERCH_HIGHX TH1F_PERCH_0_HIGHX , 
#define SUITE1_TH1F_PERCH_TITLEX TH1F_PERCH_0_TITLEX , 
#define SUITE1_TH2F_PERCH_NUM 1
#define SUITE1_TH2F_PERCH_NAME TH2F_PERCH_0_NAME , 
#define SUITE1_TH2F_PERCH_NBINSX TH2F_PERCH_0_NBINSX , 
#define SUITE1_TH2F_PERCH_LOWX TH2F_PERCH_0_LOWX , 
#define SUITE1_TH2F_PERCH_HIGHX TH2F_PERCH_0_HIGHX , 
#define SUITE1_TH2F_PERCH_TITLEX TH2F_PERCH_0_TITLEX , 
#define SUITE1_TH2F_PERCH_NBINSY TH2F_PERCH_0_NBINSY , 
#define SUITE1_TH2F_PERCH_LOWY TH2F_PERCH_0_LOWY , 
#define SUITE1_TH2F_PERCH_HIGHY TH2F_PERCH_0_HIGHY , 
#define SUITE1_TH2F_PERCH_TITLEY TH2F_PERCH_0_TITLEY , 
#define SUITE1_TH1F_PERTS_NUM 0
#define SUITE1_TH2F_PERTS_NUM 0
#define SUITE1_TPROFILE_NUM 1
#define SUITE1_TPROFILE_NAME TPROFILE_0_NAME , 
#define SUITE1_TPROFILE_NBINSX TPROFILE_0_NBINSX , 
#define SUITE1_TPROFILE_LOWX TPROFILE_0_LOWX , 
#define SUITE1_TPROFILE_HIGHX TPROFILE_0_HIGHX , 
#define SUITE1_TPROFILE_TITLEX TPROFILE_0_TITLEX , 
#define SUITE1_TPROFILE_NBINSY TPROFILE_0_NBINSY , 
#define SUITE1_TPROFILE_LOWY TPROFILE_0_LOWY , 
#define SUITE1_TPROFILE_HIGHY TPROFILE_0_HIGHY , 
#define SUITE1_TPROFILE_TITLEY TPROFILE_0_TITLEY , 
#define SUITE1_TTREE_NUM 0
#define SUITE1_LOGGER_NUM 0

// --- Suite 2: "TDC_Study" ---
#define SUITE2_NULL_NUM 1
#define SUITE2_TH1F_PEREV_NUM 1
#define SUITE2_TH1F_PEREV_NAME TH1F_PEREV_1_NAME , 
#define SUITE2_TH1F_PEREV_NBINSX TH1F_PEREV_1_NBINSX , 
#define SUITE2_TH1F_PEREV_LOWX TH1F_PEREV_1_LOWX , 
#define SUITE2_TH1F_PEREV_HIGHX TH1F_PEREV_1_HIGHX , 
#define SUITE2_TH1F_PEREV_TITLEX TH1F_PEREV_1_TITLEX , 
#define SUITE2_TH2F_PEREV_NUM 1
#define SUITE2_TH2F_PEREV_NAME TH2F_PEREV_1_NAME , 
#define SUITE2_TH2F_PEREV_NBINSX TH2F_PEREV_1_NBINSX , 
#define SUITE2_TH2F_PEREV_LOWX TH2F_PEREV_1_LOWX , 
#define SUITE2_TH2F_PEREV_HIGHX TH2F_PEREV_1_HIGHX , 
#define SUITE2_TH2F_PEREV_TITLEX TH2F_PEREV_1_TITLEX , 
#define SUITE2_TH2F_PEREV_NBINSY TH2F_PEREV_1_NBINSY , 
#define SUITE2_TH2F_PEREV_LOWY TH2F_PEREV_1_LOWY , 
#define SUITE2_TH2F_PEREV_HIGHY TH2F_PEREV_1_HIGHY , 
#define SUITE2_TH2F_PEREV_TITLEY TH2F_PEREV_1_TITLEY , 
#define SUITE2_TH1F_PERCH_NUM 1
#define SUITE2_TH1F_PERCH_NAME TH1F_PERCH_1_NAME , 
#define SUITE2_TH1F_PERCH_NBINSX TH1F_PERCH_1_NBINSX , 
#define SUITE2_TH1F_PERCH_LOWX TH1F_PERCH_1_LOWX , 
#define SUITE2_TH1F_PERCH_HIGHX TH1F_PERCH_1_HIGHX , 
#define SUITE2_TH1F_PERCH_TITLEX TH1F_PERCH_1_TITLEX , 
#define SUITE2_TH2F_PERCH_NUM 1
#define SUITE2_TH2F_PERCH_NAME TH2F_PERCH_1_NAME , 
#define SUITE2_TH2F_PERCH_NBINSX TH2F_PERCH_1_NBINSX , 
#define SUITE2_TH2F_PERCH_LOWX TH2F_PERCH_1_LOWX , 
#define SUITE2_TH2F_PERCH_HIGHX TH2F_PERCH_1_HIGHX , 
#define SUITE2_TH2F_PERCH_TITLEX TH2F_PERCH_1_TITLEX , 
#define SUITE2_TH2F_PERCH_NBINSY TH2F_PERCH_1_NBINSY , 
#define SUITE2_TH2F_PERCH_LOWY TH2F_PERCH_1_LOWY , 
#define SUITE2_TH2F_PERCH_HIGHY TH2F_PERCH_1_HIGHY , 
#define SUITE2_TH2F_PERCH_TITLEY TH2F_PERCH_1_TITLEY , 
#define SUITE2_TH1F_PERTS_NUM 0
#define SUITE2_TH2F_PERTS_NUM 0
#define SUITE2_TPROFILE_NUM 0
#define SUITE2_TTREE_NUM 0
#define SUITE2_LOGGER_NUM 0

// #######################
// # TREE DATA STRUCTURE #
// #######################

// --- Suite 0: "full" ---

struct TQIE10Info
{

  int numChs;
  int numTS;

};

// #################
// # INIT FUNCTION #
// #################

using namespace std;

void init(int suite_code, int tTS, int nCH,
           ofstream*& loggers, int &num_loggers, vector<string> &logger_name, vector<string> &logger_log_file,
          TFile* _file, TTree**& _trees, TQIE10Info &_qie10Info, vector<string> &TTree_name, int &num_TTrees,
          vector<TH1F*> &TH1F_perEVs, int &num_TH1F_perEVs, vector<string> &TH1F_perEV_name, vector<int> &TH1F_perEV_nbinsx, vector<float> &TH1F_perEV_lowx, vector<float> &TH1F_perEV_highx, vector<string> &TH1F_perEV_titlex,
          vector<vector<TH1F*> > &TH1F_perCHs, int &num_TH1F_perCHs, vector<string> &TH1F_perCH_name, vector<int> &TH1F_perCH_nbinsx, vector<float> &TH1F_perCH_lowx, vector<float> &TH1F_perCH_highx, vector<string> &TH1F_perCH_titlex,
          vector<vector<vector<TH1F*> > > &TH1F_PerTSs, int &num_TH1F_PerTSs, vector<string> &TH1F_PerTS_name, vector<int> &TH1F_PerTS_nbinsx, vector<float> &TH1F_PerTS_lowx, vector<float> &TH1F_PerTS_highx, vector<string> &TH1F_PerTS_titlex,
          vector<TH2F*> &TH2F_perEVs, int &num_TH2F_perEVs, vector<string> &TH2F_perEV_name, vector<int> &TH2F_perEV_nbinsx, vector<float> &TH2F_perEV_lowx, vector<float> &TH2F_perEV_highx, vector<string> &TH2F_perEV_titlex, vector<int> &TH2F_perEV_nbinsy, vector<float> &TH2F_perEV_lowy, vector<float> &TH2F_perEV_highy, vector<string> &TH2F_perEV_titley,
          vector<vector<TH2F*> > &TH2F_perCHs, int &num_TH2F_perCHs, vector<string> &TH2F_perCH_name, vector<int> &TH2F_perCH_nbinsx, vector<float> &TH2F_perCH_lowx, vector<float> &TH2F_perCH_highx, vector<string> &TH2F_perCH_titlex, vector<int> &TH2F_perCH_nbinsy, vector<float> &TH2F_perCH_lowy, vector<float> &TH2F_perCH_highy, vector<string> &TH2F_perCH_titley,
          vector<vector<vector<TH2F*> > > &TH2F_PerTSs, int &num_TH2F_PerTSs, vector<string> &TH2F_PerTS_name, vector<int> &TH2F_PerTS_nbinsx, vector<float> &TH2F_PerTS_lowx, vector<float> &TH2F_PerTS_highx, vector<string> &TH2F_PerTS_titlex, vector<int> &TH2F_PerTS_nbinsy, vector<float> &TH2F_PerTS_lowy, vector<float> &TH2F_PerTS_highy, vector<string> &TH2F_PerTS_titley,
          vector<vector<TH2F*> > &TProfiles, int &num_TProfiles, vector<string> &TProfile_name, vector<int> &TProfile_nbinsx, vector<float> &TProfile_lowx, vector<float> &TProfile_highx, vector<string> &TProfile_titlex, vector<int> &TProfile_nbinsy, vector<float> &TProfile_lowy, vector<float> &TProfile_highy, vector<string> &TProfile_titley){

// --- Suite 0: "full" ---

  if (suite_code == 0) {


    int num_nulls = SUITE0_NULL_NUM;
    num_nulls = num_nulls;

    num_TH1F_perEVs = SUITE0_TH1F_PEREV_NUM;
    num_TH1F_perEVs = num_TH1F_perEVs;
    char temp_TH1F_perEV_name[num_TH1F_perEVs][100] = {SUITE0_TH1F_PEREV_NAME};
    int temp_TH1F_perEV_nbinsx[num_TH1F_perEVs] = {SUITE0_TH1F_PEREV_NBINSX};
    float temp_TH1F_perEV_lowx[num_TH1F_perEVs] = {SUITE0_TH1F_PEREV_LOWX};
    float temp_TH1F_perEV_highx[num_TH1F_perEVs] = {SUITE0_TH1F_PEREV_HIGHX};
    char temp_TH1F_perEV_titlex[num_TH1F_perEVs][100] = {SUITE0_TH1F_PEREV_TITLEX};

    num_TH2F_perEVs = SUITE0_TH2F_PEREV_NUM;
    num_TH2F_perEVs = num_TH2F_perEVs;
    char temp_TH2F_perEV_name[num_TH2F_perEVs][100] = {SUITE0_TH2F_PEREV_NAME};
    int temp_TH2F_perEV_nbinsx[num_TH2F_perEVs] = {SUITE0_TH2F_PEREV_NBINSX};
    float temp_TH2F_perEV_lowx[num_TH2F_perEVs] = {SUITE0_TH2F_PEREV_LOWX};
    float temp_TH2F_perEV_highx[num_TH2F_perEVs] = {SUITE0_TH2F_PEREV_HIGHX};
    char temp_TH2F_perEV_titlex[num_TH2F_perEVs][100] = {SUITE0_TH2F_PEREV_TITLEX};
    int temp_TH2F_perEV_nbinsy[num_TH2F_perEVs] = {SUITE0_TH2F_PEREV_NBINSY};
    float temp_TH2F_perEV_lowy[num_TH2F_perEVs] = {SUITE0_TH2F_PEREV_LOWY};
    float temp_TH2F_perEV_highy[num_TH2F_perEVs] = {SUITE0_TH2F_PEREV_HIGHY};
    char temp_TH2F_perEV_titley[num_TH2F_perEVs][100] = {SUITE0_TH2F_PEREV_TITLEY};

    num_TH1F_perCHs = SUITE0_TH1F_PERCH_NUM;
    num_TH1F_perCHs = num_TH1F_perCHs;
    char temp_TH1F_perCH_name[num_TH1F_perCHs][100] = {SUITE0_TH1F_PERCH_NAME};
    int temp_TH1F_perCH_nbinsx[num_TH1F_perCHs] = {SUITE0_TH1F_PERCH_NBINSX};
    float temp_TH1F_perCH_lowx[num_TH1F_perCHs] = {SUITE0_TH1F_PERCH_LOWX};
    float temp_TH1F_perCH_highx[num_TH1F_perCHs] = {SUITE0_TH1F_PERCH_HIGHX};
    char temp_TH1F_perCH_titlex[num_TH1F_perCHs][100] = {SUITE0_TH1F_PERCH_TITLEX};

    num_TH2F_perCHs = SUITE0_TH2F_PERCH_NUM;
    num_TH2F_perCHs = num_TH2F_perCHs;
    char temp_TH2F_perCH_name[num_TH2F_perCHs][100] = {SUITE0_TH2F_PERCH_NAME};
    int temp_TH2F_perCH_nbinsx[num_TH2F_perCHs] = {SUITE0_TH2F_PERCH_NBINSX};
    float temp_TH2F_perCH_lowx[num_TH2F_perCHs] = {SUITE0_TH2F_PERCH_LOWX};
    float temp_TH2F_perCH_highx[num_TH2F_perCHs] = {SUITE0_TH2F_PERCH_HIGHX};
    char temp_TH2F_perCH_titlex[num_TH2F_perCHs][100] = {SUITE0_TH2F_PERCH_TITLEX};
    int temp_TH2F_perCH_nbinsy[num_TH2F_perCHs] = {SUITE0_TH2F_PERCH_NBINSY};
    float temp_TH2F_perCH_lowy[num_TH2F_perCHs] = {SUITE0_TH2F_PERCH_LOWY};
    float temp_TH2F_perCH_highy[num_TH2F_perCHs] = {SUITE0_TH2F_PERCH_HIGHY};
    char temp_TH2F_perCH_titley[num_TH2F_perCHs][100] = {SUITE0_TH2F_PERCH_TITLEY};

    num_TH1F_PerTSs = SUITE0_TH1F_PERTS_NUM;
    num_TH1F_PerTSs = num_TH1F_PerTSs;

    num_TH2F_PerTSs = SUITE0_TH2F_PERTS_NUM;
    num_TH2F_PerTSs = num_TH2F_PerTSs;

    num_TProfiles = SUITE0_TPROFILE_NUM;
    num_TProfiles = num_TProfiles;
    char temp_TProfile_name[num_TProfiles][100] = {SUITE0_TPROFILE_NAME};
    int temp_TProfile_nbinsx[num_TProfiles] = {SUITE0_TPROFILE_NBINSX};
    float temp_TProfile_lowx[num_TProfiles] = {SUITE0_TPROFILE_LOWX};
    float temp_TProfile_highx[num_TProfiles] = {SUITE0_TPROFILE_HIGHX};
    char temp_TProfile_titlex[num_TProfiles][100] = {SUITE0_TPROFILE_TITLEX};
    int temp_TProfile_nbinsy[num_TProfiles] = {SUITE0_TPROFILE_NBINSY};
    float temp_TProfile_lowy[num_TProfiles] = {SUITE0_TPROFILE_LOWY};
    float temp_TProfile_highy[num_TProfiles] = {SUITE0_TPROFILE_HIGHY};
    char temp_TProfile_titley[num_TProfiles][100] = {SUITE0_TPROFILE_TITLEY};

    num_TTrees = SUITE0_TTREE_NUM;
    num_TTrees = num_TTrees;

    num_loggers = SUITE0_LOGGER_NUM;
    num_loggers = num_loggers;

    for (int i=0 ; i < num_TH1F_perEVs ; i++) {
      TH1F_perEV_name.push_back(temp_TH1F_perEV_name[i]);
      TH1F_perEV_nbinsx.push_back(temp_TH1F_perEV_nbinsx[i]);
      TH1F_perEV_lowx.push_back(temp_TH1F_perEV_lowx[i]);
      TH1F_perEV_highx.push_back(temp_TH1F_perEV_highx[i]);
      TH1F_perEV_titlex.push_back(temp_TH1F_perEV_titlex[i]);
    }

    for (int i=0 ; i < num_TH2F_perEVs ; i++) {
      TH2F_perEV_name.push_back(temp_TH2F_perEV_name[i]);
      TH2F_perEV_nbinsx.push_back(temp_TH2F_perEV_nbinsx[i]);
      TH2F_perEV_lowx.push_back(temp_TH2F_perEV_lowx[i]);
      TH2F_perEV_highx.push_back(temp_TH2F_perEV_highx[i]);
      TH2F_perEV_titlex.push_back(temp_TH2F_perEV_titlex[i]);
      TH2F_perEV_nbinsy.push_back(temp_TH2F_perEV_nbinsy[i]);
      TH2F_perEV_lowy.push_back(temp_TH2F_perEV_lowy[i]);
      TH2F_perEV_highy.push_back(temp_TH2F_perEV_highy[i]);
      TH2F_perEV_titley.push_back(temp_TH2F_perEV_titley[i]);
    }

    for (int i=0 ; i < num_TH1F_perCHs ; i++) {
      vector<TH1F*> temp_TH1F_perCH_vector;
      TH1F_perCHs.push_back(temp_TH1F_perCH_vector);
      TH1F_perCH_name.push_back(temp_TH1F_perCH_name[i]);
      TH1F_perCH_nbinsx.push_back(temp_TH1F_perCH_nbinsx[i]);
      TH1F_perCH_lowx.push_back(temp_TH1F_perCH_lowx[i]);
      TH1F_perCH_highx.push_back(temp_TH1F_perCH_highx[i]);
      TH1F_perCH_titlex.push_back(temp_TH1F_perCH_titlex[i]);
    }

    for (int i=0 ; i < num_TH2F_perCHs ; i++) {
      vector<TH2F*> temp_TH2F_perCH_vector;
      TH2F_perCHs.push_back(temp_TH2F_perCH_vector);
      TH2F_perCH_name.push_back(temp_TH2F_perCH_name[i]);
      TH2F_perCH_nbinsx.push_back(temp_TH2F_perCH_nbinsx[i]);
      TH2F_perCH_lowx.push_back(temp_TH2F_perCH_lowx[i]);
      TH2F_perCH_highx.push_back(temp_TH2F_perCH_highx[i]);
      TH2F_perCH_titlex.push_back(temp_TH2F_perCH_titlex[i]);
      TH2F_perCH_nbinsy.push_back(temp_TH2F_perCH_nbinsy[i]);
      TH2F_perCH_lowy.push_back(temp_TH2F_perCH_lowy[i]);
      TH2F_perCH_highy.push_back(temp_TH2F_perCH_highy[i]);
      TH2F_perCH_titley.push_back(temp_TH2F_perCH_titley[i]);
    }

    for (int i=0 ; i < num_TProfiles ; i++) {
      vector<TH2F*> temp_TProfile_vector;
      TProfiles.push_back(temp_TProfile_vector);
      TProfile_name.push_back(temp_TProfile_name[i]);
      TProfile_nbinsx.push_back(temp_TProfile_nbinsx[i]);
      TProfile_lowx.push_back(temp_TProfile_lowx[i]);
      TProfile_highx.push_back(temp_TProfile_highx[i]);
      TProfile_titlex.push_back(temp_TProfile_titlex[i]);
      TProfile_nbinsy.push_back(temp_TProfile_nbinsy[i]);
      TProfile_lowy.push_back(temp_TProfile_lowy[i]);
      TProfile_highy.push_back(temp_TProfile_highy[i]);
      TProfile_titley.push_back(temp_TProfile_titley[i]);
    }

  }

// --- Suite 1: "ADC_Study" ---

  if (suite_code == 1) {


    int num_nulls = SUITE1_NULL_NUM;
    num_nulls = num_nulls;

    num_TH1F_perEVs = SUITE1_TH1F_PEREV_NUM;
    num_TH1F_perEVs = num_TH1F_perEVs;
    char temp_TH1F_perEV_name[num_TH1F_perEVs][100] = {SUITE1_TH1F_PEREV_NAME};
    int temp_TH1F_perEV_nbinsx[num_TH1F_perEVs] = {SUITE1_TH1F_PEREV_NBINSX};
    float temp_TH1F_perEV_lowx[num_TH1F_perEVs] = {SUITE1_TH1F_PEREV_LOWX};
    float temp_TH1F_perEV_highx[num_TH1F_perEVs] = {SUITE1_TH1F_PEREV_HIGHX};
    char temp_TH1F_perEV_titlex[num_TH1F_perEVs][100] = {SUITE1_TH1F_PEREV_TITLEX};

    num_TH2F_perEVs = SUITE1_TH2F_PEREV_NUM;
    num_TH2F_perEVs = num_TH2F_perEVs;
    char temp_TH2F_perEV_name[num_TH2F_perEVs][100] = {SUITE1_TH2F_PEREV_NAME};
    int temp_TH2F_perEV_nbinsx[num_TH2F_perEVs] = {SUITE1_TH2F_PEREV_NBINSX};
    float temp_TH2F_perEV_lowx[num_TH2F_perEVs] = {SUITE1_TH2F_PEREV_LOWX};
    float temp_TH2F_perEV_highx[num_TH2F_perEVs] = {SUITE1_TH2F_PEREV_HIGHX};
    char temp_TH2F_perEV_titlex[num_TH2F_perEVs][100] = {SUITE1_TH2F_PEREV_TITLEX};
    int temp_TH2F_perEV_nbinsy[num_TH2F_perEVs] = {SUITE1_TH2F_PEREV_NBINSY};
    float temp_TH2F_perEV_lowy[num_TH2F_perEVs] = {SUITE1_TH2F_PEREV_LOWY};
    float temp_TH2F_perEV_highy[num_TH2F_perEVs] = {SUITE1_TH2F_PEREV_HIGHY};
    char temp_TH2F_perEV_titley[num_TH2F_perEVs][100] = {SUITE1_TH2F_PEREV_TITLEY};

    num_TH1F_perCHs = SUITE1_TH1F_PERCH_NUM;
    num_TH1F_perCHs = num_TH1F_perCHs;
    char temp_TH1F_perCH_name[num_TH1F_perCHs][100] = {SUITE1_TH1F_PERCH_NAME};
    int temp_TH1F_perCH_nbinsx[num_TH1F_perCHs] = {SUITE1_TH1F_PERCH_NBINSX};
    float temp_TH1F_perCH_lowx[num_TH1F_perCHs] = {SUITE1_TH1F_PERCH_LOWX};
    float temp_TH1F_perCH_highx[num_TH1F_perCHs] = {SUITE1_TH1F_PERCH_HIGHX};
    char temp_TH1F_perCH_titlex[num_TH1F_perCHs][100] = {SUITE1_TH1F_PERCH_TITLEX};

    num_TH2F_perCHs = SUITE1_TH2F_PERCH_NUM;
    num_TH2F_perCHs = num_TH2F_perCHs;
    char temp_TH2F_perCH_name[num_TH2F_perCHs][100] = {SUITE1_TH2F_PERCH_NAME};
    int temp_TH2F_perCH_nbinsx[num_TH2F_perCHs] = {SUITE1_TH2F_PERCH_NBINSX};
    float temp_TH2F_perCH_lowx[num_TH2F_perCHs] = {SUITE1_TH2F_PERCH_LOWX};
    float temp_TH2F_perCH_highx[num_TH2F_perCHs] = {SUITE1_TH2F_PERCH_HIGHX};
    char temp_TH2F_perCH_titlex[num_TH2F_perCHs][100] = {SUITE1_TH2F_PERCH_TITLEX};
    int temp_TH2F_perCH_nbinsy[num_TH2F_perCHs] = {SUITE1_TH2F_PERCH_NBINSY};
    float temp_TH2F_perCH_lowy[num_TH2F_perCHs] = {SUITE1_TH2F_PERCH_LOWY};
    float temp_TH2F_perCH_highy[num_TH2F_perCHs] = {SUITE1_TH2F_PERCH_HIGHY};
    char temp_TH2F_perCH_titley[num_TH2F_perCHs][100] = {SUITE1_TH2F_PERCH_TITLEY};

    num_TH1F_PerTSs = SUITE1_TH1F_PERTS_NUM;
    num_TH1F_PerTSs = num_TH1F_PerTSs;

    num_TH2F_PerTSs = SUITE1_TH2F_PERTS_NUM;
    num_TH2F_PerTSs = num_TH2F_PerTSs;

    num_TProfiles = SUITE1_TPROFILE_NUM;
    num_TProfiles = num_TProfiles;
    char temp_TProfile_name[num_TProfiles][100] = {SUITE1_TPROFILE_NAME};
    int temp_TProfile_nbinsx[num_TProfiles] = {SUITE1_TPROFILE_NBINSX};
    float temp_TProfile_lowx[num_TProfiles] = {SUITE1_TPROFILE_LOWX};
    float temp_TProfile_highx[num_TProfiles] = {SUITE1_TPROFILE_HIGHX};
    char temp_TProfile_titlex[num_TProfiles][100] = {SUITE1_TPROFILE_TITLEX};
    int temp_TProfile_nbinsy[num_TProfiles] = {SUITE1_TPROFILE_NBINSY};
    float temp_TProfile_lowy[num_TProfiles] = {SUITE1_TPROFILE_LOWY};
    float temp_TProfile_highy[num_TProfiles] = {SUITE1_TPROFILE_HIGHY};
    char temp_TProfile_titley[num_TProfiles][100] = {SUITE1_TPROFILE_TITLEY};

    num_TTrees = SUITE1_TTREE_NUM;
    num_TTrees = num_TTrees;

    num_loggers = SUITE1_LOGGER_NUM;
    num_loggers = num_loggers;

    for (int i=0 ; i < num_TH1F_perEVs ; i++) {
      TH1F_perEV_name.push_back(temp_TH1F_perEV_name[i]);
      TH1F_perEV_nbinsx.push_back(temp_TH1F_perEV_nbinsx[i]);
      TH1F_perEV_lowx.push_back(temp_TH1F_perEV_lowx[i]);
      TH1F_perEV_highx.push_back(temp_TH1F_perEV_highx[i]);
      TH1F_perEV_titlex.push_back(temp_TH1F_perEV_titlex[i]);
    }

    for (int i=0 ; i < num_TH2F_perEVs ; i++) {
      TH2F_perEV_name.push_back(temp_TH2F_perEV_name[i]);
      TH2F_perEV_nbinsx.push_back(temp_TH2F_perEV_nbinsx[i]);
      TH2F_perEV_lowx.push_back(temp_TH2F_perEV_lowx[i]);
      TH2F_perEV_highx.push_back(temp_TH2F_perEV_highx[i]);
      TH2F_perEV_titlex.push_back(temp_TH2F_perEV_titlex[i]);
      TH2F_perEV_nbinsy.push_back(temp_TH2F_perEV_nbinsy[i]);
      TH2F_perEV_lowy.push_back(temp_TH2F_perEV_lowy[i]);
      TH2F_perEV_highy.push_back(temp_TH2F_perEV_highy[i]);
      TH2F_perEV_titley.push_back(temp_TH2F_perEV_titley[i]);
    }

    for (int i=0 ; i < num_TH1F_perCHs ; i++) {
      vector<TH1F*> temp_TH1F_perCH_vector;
      TH1F_perCHs.push_back(temp_TH1F_perCH_vector);
      TH1F_perCH_name.push_back(temp_TH1F_perCH_name[i]);
      TH1F_perCH_nbinsx.push_back(temp_TH1F_perCH_nbinsx[i]);
      TH1F_perCH_lowx.push_back(temp_TH1F_perCH_lowx[i]);
      TH1F_perCH_highx.push_back(temp_TH1F_perCH_highx[i]);
      TH1F_perCH_titlex.push_back(temp_TH1F_perCH_titlex[i]);
    }

    for (int i=0 ; i < num_TH2F_perCHs ; i++) {
      vector<TH2F*> temp_TH2F_perCH_vector;
      TH2F_perCHs.push_back(temp_TH2F_perCH_vector);
      TH2F_perCH_name.push_back(temp_TH2F_perCH_name[i]);
      TH2F_perCH_nbinsx.push_back(temp_TH2F_perCH_nbinsx[i]);
      TH2F_perCH_lowx.push_back(temp_TH2F_perCH_lowx[i]);
      TH2F_perCH_highx.push_back(temp_TH2F_perCH_highx[i]);
      TH2F_perCH_titlex.push_back(temp_TH2F_perCH_titlex[i]);
      TH2F_perCH_nbinsy.push_back(temp_TH2F_perCH_nbinsy[i]);
      TH2F_perCH_lowy.push_back(temp_TH2F_perCH_lowy[i]);
      TH2F_perCH_highy.push_back(temp_TH2F_perCH_highy[i]);
      TH2F_perCH_titley.push_back(temp_TH2F_perCH_titley[i]);
    }

    for (int i=0 ; i < num_TProfiles ; i++) {
      vector<TH2F*> temp_TProfile_vector;
      TProfiles.push_back(temp_TProfile_vector);
      TProfile_name.push_back(temp_TProfile_name[i]);
      TProfile_nbinsx.push_back(temp_TProfile_nbinsx[i]);
      TProfile_lowx.push_back(temp_TProfile_lowx[i]);
      TProfile_highx.push_back(temp_TProfile_highx[i]);
      TProfile_titlex.push_back(temp_TProfile_titlex[i]);
      TProfile_nbinsy.push_back(temp_TProfile_nbinsy[i]);
      TProfile_lowy.push_back(temp_TProfile_lowy[i]);
      TProfile_highy.push_back(temp_TProfile_highy[i]);
      TProfile_titley.push_back(temp_TProfile_titley[i]);
    }

  }

// --- Suite 2: "TDC_Study" ---

  if (suite_code == 2) {


    int num_nulls = SUITE2_NULL_NUM;
    num_nulls = num_nulls;

    num_TH1F_perEVs = SUITE2_TH1F_PEREV_NUM;
    num_TH1F_perEVs = num_TH1F_perEVs;
    char temp_TH1F_perEV_name[num_TH1F_perEVs][100] = {SUITE2_TH1F_PEREV_NAME};
    int temp_TH1F_perEV_nbinsx[num_TH1F_perEVs] = {SUITE2_TH1F_PEREV_NBINSX};
    float temp_TH1F_perEV_lowx[num_TH1F_perEVs] = {SUITE2_TH1F_PEREV_LOWX};
    float temp_TH1F_perEV_highx[num_TH1F_perEVs] = {SUITE2_TH1F_PEREV_HIGHX};
    char temp_TH1F_perEV_titlex[num_TH1F_perEVs][100] = {SUITE2_TH1F_PEREV_TITLEX};

    num_TH2F_perEVs = SUITE2_TH2F_PEREV_NUM;
    num_TH2F_perEVs = num_TH2F_perEVs;
    char temp_TH2F_perEV_name[num_TH2F_perEVs][100] = {SUITE2_TH2F_PEREV_NAME};
    int temp_TH2F_perEV_nbinsx[num_TH2F_perEVs] = {SUITE2_TH2F_PEREV_NBINSX};
    float temp_TH2F_perEV_lowx[num_TH2F_perEVs] = {SUITE2_TH2F_PEREV_LOWX};
    float temp_TH2F_perEV_highx[num_TH2F_perEVs] = {SUITE2_TH2F_PEREV_HIGHX};
    char temp_TH2F_perEV_titlex[num_TH2F_perEVs][100] = {SUITE2_TH2F_PEREV_TITLEX};
    int temp_TH2F_perEV_nbinsy[num_TH2F_perEVs] = {SUITE2_TH2F_PEREV_NBINSY};
    float temp_TH2F_perEV_lowy[num_TH2F_perEVs] = {SUITE2_TH2F_PEREV_LOWY};
    float temp_TH2F_perEV_highy[num_TH2F_perEVs] = {SUITE2_TH2F_PEREV_HIGHY};
    char temp_TH2F_perEV_titley[num_TH2F_perEVs][100] = {SUITE2_TH2F_PEREV_TITLEY};

    num_TH1F_perCHs = SUITE2_TH1F_PERCH_NUM;
    num_TH1F_perCHs = num_TH1F_perCHs;
    char temp_TH1F_perCH_name[num_TH1F_perCHs][100] = {SUITE2_TH1F_PERCH_NAME};
    int temp_TH1F_perCH_nbinsx[num_TH1F_perCHs] = {SUITE2_TH1F_PERCH_NBINSX};
    float temp_TH1F_perCH_lowx[num_TH1F_perCHs] = {SUITE2_TH1F_PERCH_LOWX};
    float temp_TH1F_perCH_highx[num_TH1F_perCHs] = {SUITE2_TH1F_PERCH_HIGHX};
    char temp_TH1F_perCH_titlex[num_TH1F_perCHs][100] = {SUITE2_TH1F_PERCH_TITLEX};

    num_TH2F_perCHs = SUITE2_TH2F_PERCH_NUM;
    num_TH2F_perCHs = num_TH2F_perCHs;
    char temp_TH2F_perCH_name[num_TH2F_perCHs][100] = {SUITE2_TH2F_PERCH_NAME};
    int temp_TH2F_perCH_nbinsx[num_TH2F_perCHs] = {SUITE2_TH2F_PERCH_NBINSX};
    float temp_TH2F_perCH_lowx[num_TH2F_perCHs] = {SUITE2_TH2F_PERCH_LOWX};
    float temp_TH2F_perCH_highx[num_TH2F_perCHs] = {SUITE2_TH2F_PERCH_HIGHX};
    char temp_TH2F_perCH_titlex[num_TH2F_perCHs][100] = {SUITE2_TH2F_PERCH_TITLEX};
    int temp_TH2F_perCH_nbinsy[num_TH2F_perCHs] = {SUITE2_TH2F_PERCH_NBINSY};
    float temp_TH2F_perCH_lowy[num_TH2F_perCHs] = {SUITE2_TH2F_PERCH_LOWY};
    float temp_TH2F_perCH_highy[num_TH2F_perCHs] = {SUITE2_TH2F_PERCH_HIGHY};
    char temp_TH2F_perCH_titley[num_TH2F_perCHs][100] = {SUITE2_TH2F_PERCH_TITLEY};

    num_TH1F_PerTSs = SUITE2_TH1F_PERTS_NUM;
    num_TH1F_PerTSs = num_TH1F_PerTSs;

    num_TH2F_PerTSs = SUITE2_TH2F_PERTS_NUM;
    num_TH2F_PerTSs = num_TH2F_PerTSs;

    num_TProfiles = SUITE2_TPROFILE_NUM;
    num_TProfiles = num_TProfiles;

    num_TTrees = SUITE2_TTREE_NUM;
    num_TTrees = num_TTrees;

    num_loggers = SUITE2_LOGGER_NUM;
    num_loggers = num_loggers;

    for (int i=0 ; i < num_TH1F_perEVs ; i++) {
      TH1F_perEV_name.push_back(temp_TH1F_perEV_name[i]);
      TH1F_perEV_nbinsx.push_back(temp_TH1F_perEV_nbinsx[i]);
      TH1F_perEV_lowx.push_back(temp_TH1F_perEV_lowx[i]);
      TH1F_perEV_highx.push_back(temp_TH1F_perEV_highx[i]);
      TH1F_perEV_titlex.push_back(temp_TH1F_perEV_titlex[i]);
    }

    for (int i=0 ; i < num_TH2F_perEVs ; i++) {
      TH2F_perEV_name.push_back(temp_TH2F_perEV_name[i]);
      TH2F_perEV_nbinsx.push_back(temp_TH2F_perEV_nbinsx[i]);
      TH2F_perEV_lowx.push_back(temp_TH2F_perEV_lowx[i]);
      TH2F_perEV_highx.push_back(temp_TH2F_perEV_highx[i]);
      TH2F_perEV_titlex.push_back(temp_TH2F_perEV_titlex[i]);
      TH2F_perEV_nbinsy.push_back(temp_TH2F_perEV_nbinsy[i]);
      TH2F_perEV_lowy.push_back(temp_TH2F_perEV_lowy[i]);
      TH2F_perEV_highy.push_back(temp_TH2F_perEV_highy[i]);
      TH2F_perEV_titley.push_back(temp_TH2F_perEV_titley[i]);
    }

    for (int i=0 ; i < num_TH1F_perCHs ; i++) {
      vector<TH1F*> temp_TH1F_perCH_vector;
      TH1F_perCHs.push_back(temp_TH1F_perCH_vector);
      TH1F_perCH_name.push_back(temp_TH1F_perCH_name[i]);
      TH1F_perCH_nbinsx.push_back(temp_TH1F_perCH_nbinsx[i]);
      TH1F_perCH_lowx.push_back(temp_TH1F_perCH_lowx[i]);
      TH1F_perCH_highx.push_back(temp_TH1F_perCH_highx[i]);
      TH1F_perCH_titlex.push_back(temp_TH1F_perCH_titlex[i]);
    }

    for (int i=0 ; i < num_TH2F_perCHs ; i++) {
      vector<TH2F*> temp_TH2F_perCH_vector;
      TH2F_perCHs.push_back(temp_TH2F_perCH_vector);
      TH2F_perCH_name.push_back(temp_TH2F_perCH_name[i]);
      TH2F_perCH_nbinsx.push_back(temp_TH2F_perCH_nbinsx[i]);
      TH2F_perCH_lowx.push_back(temp_TH2F_perCH_lowx[i]);
      TH2F_perCH_highx.push_back(temp_TH2F_perCH_highx[i]);
      TH2F_perCH_titlex.push_back(temp_TH2F_perCH_titlex[i]);
      TH2F_perCH_nbinsy.push_back(temp_TH2F_perCH_nbinsy[i]);
      TH2F_perCH_lowy.push_back(temp_TH2F_perCH_lowy[i]);
      TH2F_perCH_highy.push_back(temp_TH2F_perCH_highy[i]);
      TH2F_perCH_titley.push_back(temp_TH2F_perCH_titley[i]);
    }

  }

}

