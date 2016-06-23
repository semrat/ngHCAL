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
#define TH1F_PEREV_0_NAME "CapIDrot_EV"
#define TH1F_PEREV_0_NBINSX 7
#define TH1F_PEREV_0_LOWX -3.5
#define TH1F_PEREV_0_HIGHX 3.5
#define TH1F_PEREV_0_TITLEX "CID(N) - (CID(N-1)+1)%4"

// --- TH1F_perEV 1 ---
#define TH1F_PEREV_1_NAME "CapAllign_EV"
#define TH1F_PEREV_1_NBINSX 7
#define TH1F_PEREV_1_LOWX -3.5
#define TH1F_PEREV_1_HIGHX 3.5
#define TH1F_PEREV_1_TITLEX "CID - CID(ch0)"

// --- TH1F_perEV 2 ---
#define TH1F_PEREV_2_NAME "ADC_ped_EV"
#define TH1F_PEREV_2_NBINSX 25
#define TH1F_PEREV_2_LOWX 0
#define TH1F_PEREV_2_HIGHX 50
#define TH1F_PEREV_2_TITLEX "ADC"

// --- TH1F_perEV 3 ---
#define TH1F_PEREV_3_NAME "QSum_ped_EV"
#define TH1F_PEREV_3_NBINSX 50
#define TH1F_PEREV_3_LOWX 0
#define TH1F_PEREV_3_HIGHX 500
#define TH1F_PEREV_3_TITLEX "Integrated Charge (fC)"

// --- TH1F_perEV 4 ---
#define TH1F_PEREV_4_NAME "Qav_ped_EV"
#define TH1F_PEREV_4_NBINSX 50
#define TH1F_PEREV_4_LOWX 0
#define TH1F_PEREV_4_HIGHX 50
#define TH1F_PEREV_4_TITLEX "Q (fC)"

// --- TH1F_perEV 5 ---
#define TH1F_PEREV_5_NAME "T_abs_EV"
#define TH1F_PEREV_5_NBINSX 250
#define TH1F_PEREV_5_LOWX -0.5
#define TH1F_PEREV_5_HIGHX 249.5
#define TH1F_PEREV_5_TITLEX "t (ns)"

// #####  TH2F_perEVs  #####

// --- TH2F_perEV 0 ---
#define TH2F_PEREV_0_NAME "ADCvsTS_ped_EV"
#define TH2F_PEREV_0_NBINSX tTS
#define TH2F_PEREV_0_LOWX -0.5
#define TH2F_PEREV_0_HIGHX (float)tTS - (float)0.5
#define TH2F_PEREV_0_TITLEX "TS"
#define TH2F_PEREV_0_NBINSY 25
#define TH2F_PEREV_0_LOWY 0
#define TH2F_PEREV_0_HIGHY 50
#define TH2F_PEREV_0_TITLEY "ADC"

// --- TH2F_perEV 1 ---
#define TH2F_PEREV_1_NAME "Qav_ped_CID"
#define TH2F_PEREV_1_NBINSX 4
#define TH2F_PEREV_1_LOWX -0.5
#define TH2F_PEREV_1_HIGHX 3.5
#define TH2F_PEREV_1_TITLEX "CID"
#define TH2F_PEREV_1_NBINSY 50
#define TH2F_PEREV_1_LOWY 0
#define TH2F_PEREV_1_HIGHY 15
#define TH2F_PEREV_1_TITLEY "Q (fC)"

// --- TH2F_perEV 2 ---
#define TH2F_PEREV_2_NAME "ADC_ped_CID"
#define TH2F_PEREV_2_NBINSX 4
#define TH2F_PEREV_2_LOWX -0.5
#define TH2F_PEREV_2_HIGHX 3.5
#define TH2F_PEREV_2_TITLEX "CID"
#define TH2F_PEREV_2_NBINSY 25
#define TH2F_PEREV_2_LOWY 0
#define TH2F_PEREV_2_HIGHY 50
#define TH2F_PEREV_2_TITLEY "ADC"

// --- TH2F_perEV 3 ---
#define TH2F_PEREV_3_NAME "TDCvsTS_EV"
#define TH2F_PEREV_3_NBINSX tTS
#define TH2F_PEREV_3_LOWX -0.5
#define TH2F_PEREV_3_HIGHX (float)tTS - (float)0.5
#define TH2F_PEREV_3_TITLEX "TS"
#define TH2F_PEREV_3_NBINSY 50
#define TH2F_PEREV_3_LOWY -0.5
#define TH2F_PEREV_3_HIGHY 49.5
#define TH2F_PEREV_3_TITLEY "TDC (0.5 ns)"

// #####  TH1F_perCHs  #####

// --- TH1F_perCH 0 ---
#define TH1F_PERCH_0_NAME "CapIDrot_CH"
#define TH1F_PERCH_0_NBINSX 7
#define TH1F_PERCH_0_LOWX -3.5
#define TH1F_PERCH_0_HIGHX 3.5
#define TH1F_PERCH_0_TITLEX "CID(N) - (CID(N-1)+1)%4"

// --- TH1F_perCH 1 ---
#define TH1F_PERCH_1_NAME "CapAllign_CH"
#define TH1F_PERCH_1_NBINSX 7
#define TH1F_PERCH_1_LOWX -3.5
#define TH1F_PERCH_1_HIGHX 3.5
#define TH1F_PERCH_1_TITLEX "CID - CID(ch0)"

// --- TH1F_perCH 2 ---
#define TH1F_PERCH_2_NAME "ADC_ped_CH"
#define TH1F_PERCH_2_NBINSX 25
#define TH1F_PERCH_2_LOWX 0
#define TH1F_PERCH_2_HIGHX 50
#define TH1F_PERCH_2_TITLEX "ADC"

// --- TH1F_perCH 3 ---
#define TH1F_PERCH_3_NAME "QSum_ped_CH"
#define TH1F_PERCH_3_NBINSX 50
#define TH1F_PERCH_3_LOWX 0
#define TH1F_PERCH_3_HIGHX 500
#define TH1F_PERCH_3_TITLEX "Integrated Charge (fC)"

// --- TH1F_perCH 4 ---
#define TH1F_PERCH_4_NAME "T_abs_CH"
#define TH1F_PERCH_4_NBINSX 250
#define TH1F_PERCH_4_LOWX -0.5
#define TH1F_PERCH_4_HIGHX 249.5
#define TH1F_PERCH_4_TITLEX "t (ns)"

// #####  TH2F_perCHs  #####

// --- TH2F_perCH 0 ---
#define TH2F_PERCH_0_NAME "CIDvsTS"
#define TH2F_PERCH_0_NBINSX tTS
#define TH2F_PERCH_0_LOWX -0.5
#define TH2F_PERCH_0_HIGHX (float)tTS - (float)0.5
#define TH2F_PERCH_0_TITLEX "TS"
#define TH2F_PERCH_0_NBINSY 4
#define TH2F_PERCH_0_LOWY -0.5
#define TH2F_PERCH_0_HIGHY 3.5
#define TH2F_PERCH_0_TITLEY "CID"

// --- TH2F_perCH 1 ---
#define TH2F_PERCH_1_NAME "ADCvsTS_ped_CH"
#define TH2F_PERCH_1_NBINSX tTS
#define TH2F_PERCH_1_LOWX -0.5
#define TH2F_PERCH_1_HIGHX (float)tTS - (float)0.5
#define TH2F_PERCH_1_TITLEX "TS"
#define TH2F_PERCH_1_NBINSY 25
#define TH2F_PERCH_1_LOWY 0
#define TH2F_PERCH_1_HIGHY 50
#define TH2F_PERCH_1_TITLEY "ADC"

// --- TH2F_perCH 2 ---
#define TH2F_PERCH_2_NAME "TDCvsTS_CH"
#define TH2F_PERCH_2_NBINSX tTS
#define TH2F_PERCH_2_LOWX -0.5
#define TH2F_PERCH_2_HIGHX (float)tTS - (float)0.5
#define TH2F_PERCH_2_TITLEX "TS"
#define TH2F_PERCH_2_NBINSY 50
#define TH2F_PERCH_2_LOWY -0.5
#define TH2F_PERCH_2_HIGHY 49.5
#define TH2F_PERCH_2_TITLEY "TDC (0.5 ns)"

// #####  TH1F_PerTSs  #####

// #####  TH2F_PerTSs  #####

// #####  TProfiles  #####

// #####  TTrees  #####

// #####  loggers  #####

// --- logger 0 ---
#define LOGGER_0_NAME "BadData_CH"
#define LOGGER_0_LOG_FILE "../log/bad_data.log"

// ##########
// # SUITES #
// ##########

// --- Suite 0: "full" ---
#define SUITE0_NULL_NUM 1
#define SUITE0_TH1F_PEREV_NUM 6
#define SUITE0_TH1F_PEREV_NAME TH1F_PEREV_0_NAME , TH1F_PEREV_1_NAME , TH1F_PEREV_2_NAME , TH1F_PEREV_3_NAME , TH1F_PEREV_4_NAME , TH1F_PEREV_5_NAME , 
#define SUITE0_TH1F_PEREV_NBINSX TH1F_PEREV_0_NBINSX , TH1F_PEREV_1_NBINSX , TH1F_PEREV_2_NBINSX , TH1F_PEREV_3_NBINSX , TH1F_PEREV_4_NBINSX , TH1F_PEREV_5_NBINSX , 
#define SUITE0_TH1F_PEREV_LOWX TH1F_PEREV_0_LOWX , TH1F_PEREV_1_LOWX , TH1F_PEREV_2_LOWX , TH1F_PEREV_3_LOWX , TH1F_PEREV_4_LOWX , TH1F_PEREV_5_LOWX , 
#define SUITE0_TH1F_PEREV_HIGHX TH1F_PEREV_0_HIGHX , TH1F_PEREV_1_HIGHX , TH1F_PEREV_2_HIGHX , TH1F_PEREV_3_HIGHX , TH1F_PEREV_4_HIGHX , TH1F_PEREV_5_HIGHX , 
#define SUITE0_TH1F_PEREV_TITLEX TH1F_PEREV_0_TITLEX , TH1F_PEREV_1_TITLEX , TH1F_PEREV_2_TITLEX , TH1F_PEREV_3_TITLEX , TH1F_PEREV_4_TITLEX , TH1F_PEREV_5_TITLEX , 
#define SUITE0_TH2F_PEREV_NUM 4
#define SUITE0_TH2F_PEREV_NAME TH2F_PEREV_0_NAME , TH2F_PEREV_1_NAME , TH2F_PEREV_2_NAME , TH2F_PEREV_3_NAME , 
#define SUITE0_TH2F_PEREV_NBINSX TH2F_PEREV_0_NBINSX , TH2F_PEREV_1_NBINSX , TH2F_PEREV_2_NBINSX , TH2F_PEREV_3_NBINSX , 
#define SUITE0_TH2F_PEREV_LOWX TH2F_PEREV_0_LOWX , TH2F_PEREV_1_LOWX , TH2F_PEREV_2_LOWX , TH2F_PEREV_3_LOWX , 
#define SUITE0_TH2F_PEREV_HIGHX TH2F_PEREV_0_HIGHX , TH2F_PEREV_1_HIGHX , TH2F_PEREV_2_HIGHX , TH2F_PEREV_3_HIGHX , 
#define SUITE0_TH2F_PEREV_TITLEX TH2F_PEREV_0_TITLEX , TH2F_PEREV_1_TITLEX , TH2F_PEREV_2_TITLEX , TH2F_PEREV_3_TITLEX , 
#define SUITE0_TH2F_PEREV_NBINSY TH2F_PEREV_0_NBINSY , TH2F_PEREV_1_NBINSY , TH2F_PEREV_2_NBINSY , TH2F_PEREV_3_NBINSY , 
#define SUITE0_TH2F_PEREV_LOWY TH2F_PEREV_0_LOWY , TH2F_PEREV_1_LOWY , TH2F_PEREV_2_LOWY , TH2F_PEREV_3_LOWY , 
#define SUITE0_TH2F_PEREV_HIGHY TH2F_PEREV_0_HIGHY , TH2F_PEREV_1_HIGHY , TH2F_PEREV_2_HIGHY , TH2F_PEREV_3_HIGHY , 
#define SUITE0_TH2F_PEREV_TITLEY TH2F_PEREV_0_TITLEY , TH2F_PEREV_1_TITLEY , TH2F_PEREV_2_TITLEY , TH2F_PEREV_3_TITLEY , 
#define SUITE0_TH1F_PERCH_NUM 5
#define SUITE0_TH1F_PERCH_NAME TH1F_PERCH_0_NAME , TH1F_PERCH_1_NAME , TH1F_PERCH_2_NAME , TH1F_PERCH_3_NAME , TH1F_PERCH_4_NAME , 
#define SUITE0_TH1F_PERCH_NBINSX TH1F_PERCH_0_NBINSX , TH1F_PERCH_1_NBINSX , TH1F_PERCH_2_NBINSX , TH1F_PERCH_3_NBINSX , TH1F_PERCH_4_NBINSX , 
#define SUITE0_TH1F_PERCH_LOWX TH1F_PERCH_0_LOWX , TH1F_PERCH_1_LOWX , TH1F_PERCH_2_LOWX , TH1F_PERCH_3_LOWX , TH1F_PERCH_4_LOWX , 
#define SUITE0_TH1F_PERCH_HIGHX TH1F_PERCH_0_HIGHX , TH1F_PERCH_1_HIGHX , TH1F_PERCH_2_HIGHX , TH1F_PERCH_3_HIGHX , TH1F_PERCH_4_HIGHX , 
#define SUITE0_TH1F_PERCH_TITLEX TH1F_PERCH_0_TITLEX , TH1F_PERCH_1_TITLEX , TH1F_PERCH_2_TITLEX , TH1F_PERCH_3_TITLEX , TH1F_PERCH_4_TITLEX , 
#define SUITE0_TH2F_PERCH_NUM 3
#define SUITE0_TH2F_PERCH_NAME TH2F_PERCH_0_NAME , TH2F_PERCH_1_NAME , TH2F_PERCH_2_NAME , 
#define SUITE0_TH2F_PERCH_NBINSX TH2F_PERCH_0_NBINSX , TH2F_PERCH_1_NBINSX , TH2F_PERCH_2_NBINSX , 
#define SUITE0_TH2F_PERCH_LOWX TH2F_PERCH_0_LOWX , TH2F_PERCH_1_LOWX , TH2F_PERCH_2_LOWX , 
#define SUITE0_TH2F_PERCH_HIGHX TH2F_PERCH_0_HIGHX , TH2F_PERCH_1_HIGHX , TH2F_PERCH_2_HIGHX , 
#define SUITE0_TH2F_PERCH_TITLEX TH2F_PERCH_0_TITLEX , TH2F_PERCH_1_TITLEX , TH2F_PERCH_2_TITLEX , 
#define SUITE0_TH2F_PERCH_NBINSY TH2F_PERCH_0_NBINSY , TH2F_PERCH_1_NBINSY , TH2F_PERCH_2_NBINSY , 
#define SUITE0_TH2F_PERCH_LOWY TH2F_PERCH_0_LOWY , TH2F_PERCH_1_LOWY , TH2F_PERCH_2_LOWY , 
#define SUITE0_TH2F_PERCH_HIGHY TH2F_PERCH_0_HIGHY , TH2F_PERCH_1_HIGHY , TH2F_PERCH_2_HIGHY , 
#define SUITE0_TH2F_PERCH_TITLEY TH2F_PERCH_0_TITLEY , TH2F_PERCH_1_TITLEY , TH2F_PERCH_2_TITLEY , 
#define SUITE0_TH1F_PERTS_NUM 0
#define SUITE0_TH2F_PERTS_NUM 0
#define SUITE0_TPROFILE_NUM 0
#define SUITE0_TTREE_NUM 0
#define SUITE0_LOGGER_NUM 1
#define SUITE0_LOGGER_NAME LOGGER_0_NAME , 
#define SUITE0_LOGGER_LOG_FILE LOGGER_0_LOG_FILE , 

// --- Suite 1: "CapIDtesting" ---
#define SUITE1_NULL_NUM 1
#define SUITE1_TH1F_PEREV_NUM 2
#define SUITE1_TH1F_PEREV_NAME TH1F_PEREV_0_NAME , TH1F_PEREV_1_NAME , 
#define SUITE1_TH1F_PEREV_NBINSX TH1F_PEREV_0_NBINSX , TH1F_PEREV_1_NBINSX , 
#define SUITE1_TH1F_PEREV_LOWX TH1F_PEREV_0_LOWX , TH1F_PEREV_1_LOWX , 
#define SUITE1_TH1F_PEREV_HIGHX TH1F_PEREV_0_HIGHX , TH1F_PEREV_1_HIGHX , 
#define SUITE1_TH1F_PEREV_TITLEX TH1F_PEREV_0_TITLEX , TH1F_PEREV_1_TITLEX , 
#define SUITE1_TH2F_PEREV_NUM 0
#define SUITE1_TH1F_PERCH_NUM 2
#define SUITE1_TH1F_PERCH_NAME TH1F_PERCH_0_NAME , TH1F_PERCH_1_NAME , 
#define SUITE1_TH1F_PERCH_NBINSX TH1F_PERCH_0_NBINSX , TH1F_PERCH_1_NBINSX , 
#define SUITE1_TH1F_PERCH_LOWX TH1F_PERCH_0_LOWX , TH1F_PERCH_1_LOWX , 
#define SUITE1_TH1F_PERCH_HIGHX TH1F_PERCH_0_HIGHX , TH1F_PERCH_1_HIGHX , 
#define SUITE1_TH1F_PERCH_TITLEX TH1F_PERCH_0_TITLEX , TH1F_PERCH_1_TITLEX , 
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
#define SUITE1_TPROFILE_NUM 0
#define SUITE1_TTREE_NUM 0
#define SUITE1_LOGGER_NUM 0

// --- Suite 2: "PedestalData" ---
#define SUITE2_NULL_NUM 1
#define SUITE2_TH1F_PEREV_NUM 3
#define SUITE2_TH1F_PEREV_NAME TH1F_PEREV_2_NAME , TH1F_PEREV_3_NAME , TH1F_PEREV_4_NAME , 
#define SUITE2_TH1F_PEREV_NBINSX TH1F_PEREV_2_NBINSX , TH1F_PEREV_3_NBINSX , TH1F_PEREV_4_NBINSX , 
#define SUITE2_TH1F_PEREV_LOWX TH1F_PEREV_2_LOWX , TH1F_PEREV_3_LOWX , TH1F_PEREV_4_LOWX , 
#define SUITE2_TH1F_PEREV_HIGHX TH1F_PEREV_2_HIGHX , TH1F_PEREV_3_HIGHX , TH1F_PEREV_4_HIGHX , 
#define SUITE2_TH1F_PEREV_TITLEX TH1F_PEREV_2_TITLEX , TH1F_PEREV_3_TITLEX , TH1F_PEREV_4_TITLEX , 
#define SUITE2_TH2F_PEREV_NUM 3
#define SUITE2_TH2F_PEREV_NAME TH2F_PEREV_0_NAME , TH2F_PEREV_1_NAME , TH2F_PEREV_2_NAME , 
#define SUITE2_TH2F_PEREV_NBINSX TH2F_PEREV_0_NBINSX , TH2F_PEREV_1_NBINSX , TH2F_PEREV_2_NBINSX , 
#define SUITE2_TH2F_PEREV_LOWX TH2F_PEREV_0_LOWX , TH2F_PEREV_1_LOWX , TH2F_PEREV_2_LOWX , 
#define SUITE2_TH2F_PEREV_HIGHX TH2F_PEREV_0_HIGHX , TH2F_PEREV_1_HIGHX , TH2F_PEREV_2_HIGHX , 
#define SUITE2_TH2F_PEREV_TITLEX TH2F_PEREV_0_TITLEX , TH2F_PEREV_1_TITLEX , TH2F_PEREV_2_TITLEX , 
#define SUITE2_TH2F_PEREV_NBINSY TH2F_PEREV_0_NBINSY , TH2F_PEREV_1_NBINSY , TH2F_PEREV_2_NBINSY , 
#define SUITE2_TH2F_PEREV_LOWY TH2F_PEREV_0_LOWY , TH2F_PEREV_1_LOWY , TH2F_PEREV_2_LOWY , 
#define SUITE2_TH2F_PEREV_HIGHY TH2F_PEREV_0_HIGHY , TH2F_PEREV_1_HIGHY , TH2F_PEREV_2_HIGHY , 
#define SUITE2_TH2F_PEREV_TITLEY TH2F_PEREV_0_TITLEY , TH2F_PEREV_1_TITLEY , TH2F_PEREV_2_TITLEY , 
#define SUITE2_TH1F_PERCH_NUM 2
#define SUITE2_TH1F_PERCH_NAME TH1F_PERCH_2_NAME , TH1F_PERCH_3_NAME , 
#define SUITE2_TH1F_PERCH_NBINSX TH1F_PERCH_2_NBINSX , TH1F_PERCH_3_NBINSX , 
#define SUITE2_TH1F_PERCH_LOWX TH1F_PERCH_2_LOWX , TH1F_PERCH_3_LOWX , 
#define SUITE2_TH1F_PERCH_HIGHX TH1F_PERCH_2_HIGHX , TH1F_PERCH_3_HIGHX , 
#define SUITE2_TH1F_PERCH_TITLEX TH1F_PERCH_2_TITLEX , TH1F_PERCH_3_TITLEX , 
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

// --- Suite 3: "AbsoluteTiming" ---
#define SUITE3_NULL_NUM 1
#define SUITE3_TH1F_PEREV_NUM 1
#define SUITE3_TH1F_PEREV_NAME TH1F_PEREV_5_NAME , 
#define SUITE3_TH1F_PEREV_NBINSX TH1F_PEREV_5_NBINSX , 
#define SUITE3_TH1F_PEREV_LOWX TH1F_PEREV_5_LOWX , 
#define SUITE3_TH1F_PEREV_HIGHX TH1F_PEREV_5_HIGHX , 
#define SUITE3_TH1F_PEREV_TITLEX TH1F_PEREV_5_TITLEX , 
#define SUITE3_TH2F_PEREV_NUM 1
#define SUITE3_TH2F_PEREV_NAME TH2F_PEREV_3_NAME , 
#define SUITE3_TH2F_PEREV_NBINSX TH2F_PEREV_3_NBINSX , 
#define SUITE3_TH2F_PEREV_LOWX TH2F_PEREV_3_LOWX , 
#define SUITE3_TH2F_PEREV_HIGHX TH2F_PEREV_3_HIGHX , 
#define SUITE3_TH2F_PEREV_TITLEX TH2F_PEREV_3_TITLEX , 
#define SUITE3_TH2F_PEREV_NBINSY TH2F_PEREV_3_NBINSY , 
#define SUITE3_TH2F_PEREV_LOWY TH2F_PEREV_3_LOWY , 
#define SUITE3_TH2F_PEREV_HIGHY TH2F_PEREV_3_HIGHY , 
#define SUITE3_TH2F_PEREV_TITLEY TH2F_PEREV_3_TITLEY , 
#define SUITE3_TH1F_PERCH_NUM 1
#define SUITE3_TH1F_PERCH_NAME TH1F_PERCH_4_NAME , 
#define SUITE3_TH1F_PERCH_NBINSX TH1F_PERCH_4_NBINSX , 
#define SUITE3_TH1F_PERCH_LOWX TH1F_PERCH_4_LOWX , 
#define SUITE3_TH1F_PERCH_HIGHX TH1F_PERCH_4_HIGHX , 
#define SUITE3_TH1F_PERCH_TITLEX TH1F_PERCH_4_TITLEX , 
#define SUITE3_TH2F_PERCH_NUM 1
#define SUITE3_TH2F_PERCH_NAME TH2F_PERCH_2_NAME , 
#define SUITE3_TH2F_PERCH_NBINSX TH2F_PERCH_2_NBINSX , 
#define SUITE3_TH2F_PERCH_LOWX TH2F_PERCH_2_LOWX , 
#define SUITE3_TH2F_PERCH_HIGHX TH2F_PERCH_2_HIGHX , 
#define SUITE3_TH2F_PERCH_TITLEX TH2F_PERCH_2_TITLEX , 
#define SUITE3_TH2F_PERCH_NBINSY TH2F_PERCH_2_NBINSY , 
#define SUITE3_TH2F_PERCH_LOWY TH2F_PERCH_2_LOWY , 
#define SUITE3_TH2F_PERCH_HIGHY TH2F_PERCH_2_HIGHY , 
#define SUITE3_TH2F_PERCH_TITLEY TH2F_PERCH_2_TITLEY , 
#define SUITE3_TH1F_PERTS_NUM 0
#define SUITE3_TH2F_PERTS_NUM 0
#define SUITE3_TPROFILE_NUM 0
#define SUITE3_TTREE_NUM 0
#define SUITE3_LOGGER_NUM 0

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

    num_TTrees = SUITE0_TTREE_NUM;
    num_TTrees = num_TTrees;

    num_loggers = SUITE0_LOGGER_NUM;
    num_loggers = num_loggers;
    char temp_logger_name[num_loggers][100] = {SUITE0_LOGGER_NAME};
    char temp_logger_log_file[num_loggers][100] = {SUITE0_LOGGER_LOG_FILE};

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

    for (int i=0 ; i < num_loggers ; i++) {
      logger_name.push_back(temp_logger_name[i]);
      logger_log_file.push_back(temp_logger_log_file[i]);
    }

    loggers = new ofstream[num_loggers];

  }

// --- Suite 1: "CapIDtesting" ---

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

// --- Suite 2: "PedestalData" ---

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

// --- Suite 3: "AbsoluteTiming" ---

  if (suite_code == 3) {


    int num_nulls = SUITE3_NULL_NUM;
    num_nulls = num_nulls;

    num_TH1F_perEVs = SUITE3_TH1F_PEREV_NUM;
    num_TH1F_perEVs = num_TH1F_perEVs;
    char temp_TH1F_perEV_name[num_TH1F_perEVs][100] = {SUITE3_TH1F_PEREV_NAME};
    int temp_TH1F_perEV_nbinsx[num_TH1F_perEVs] = {SUITE3_TH1F_PEREV_NBINSX};
    float temp_TH1F_perEV_lowx[num_TH1F_perEVs] = {SUITE3_TH1F_PEREV_LOWX};
    float temp_TH1F_perEV_highx[num_TH1F_perEVs] = {SUITE3_TH1F_PEREV_HIGHX};
    char temp_TH1F_perEV_titlex[num_TH1F_perEVs][100] = {SUITE3_TH1F_PEREV_TITLEX};

    num_TH2F_perEVs = SUITE3_TH2F_PEREV_NUM;
    num_TH2F_perEVs = num_TH2F_perEVs;
    char temp_TH2F_perEV_name[num_TH2F_perEVs][100] = {SUITE3_TH2F_PEREV_NAME};
    int temp_TH2F_perEV_nbinsx[num_TH2F_perEVs] = {SUITE3_TH2F_PEREV_NBINSX};
    float temp_TH2F_perEV_lowx[num_TH2F_perEVs] = {SUITE3_TH2F_PEREV_LOWX};
    float temp_TH2F_perEV_highx[num_TH2F_perEVs] = {SUITE3_TH2F_PEREV_HIGHX};
    char temp_TH2F_perEV_titlex[num_TH2F_perEVs][100] = {SUITE3_TH2F_PEREV_TITLEX};
    int temp_TH2F_perEV_nbinsy[num_TH2F_perEVs] = {SUITE3_TH2F_PEREV_NBINSY};
    float temp_TH2F_perEV_lowy[num_TH2F_perEVs] = {SUITE3_TH2F_PEREV_LOWY};
    float temp_TH2F_perEV_highy[num_TH2F_perEVs] = {SUITE3_TH2F_PEREV_HIGHY};
    char temp_TH2F_perEV_titley[num_TH2F_perEVs][100] = {SUITE3_TH2F_PEREV_TITLEY};

    num_TH1F_perCHs = SUITE3_TH1F_PERCH_NUM;
    num_TH1F_perCHs = num_TH1F_perCHs;
    char temp_TH1F_perCH_name[num_TH1F_perCHs][100] = {SUITE3_TH1F_PERCH_NAME};
    int temp_TH1F_perCH_nbinsx[num_TH1F_perCHs] = {SUITE3_TH1F_PERCH_NBINSX};
    float temp_TH1F_perCH_lowx[num_TH1F_perCHs] = {SUITE3_TH1F_PERCH_LOWX};
    float temp_TH1F_perCH_highx[num_TH1F_perCHs] = {SUITE3_TH1F_PERCH_HIGHX};
    char temp_TH1F_perCH_titlex[num_TH1F_perCHs][100] = {SUITE3_TH1F_PERCH_TITLEX};

    num_TH2F_perCHs = SUITE3_TH2F_PERCH_NUM;
    num_TH2F_perCHs = num_TH2F_perCHs;
    char temp_TH2F_perCH_name[num_TH2F_perCHs][100] = {SUITE3_TH2F_PERCH_NAME};
    int temp_TH2F_perCH_nbinsx[num_TH2F_perCHs] = {SUITE3_TH2F_PERCH_NBINSX};
    float temp_TH2F_perCH_lowx[num_TH2F_perCHs] = {SUITE3_TH2F_PERCH_LOWX};
    float temp_TH2F_perCH_highx[num_TH2F_perCHs] = {SUITE3_TH2F_PERCH_HIGHX};
    char temp_TH2F_perCH_titlex[num_TH2F_perCHs][100] = {SUITE3_TH2F_PERCH_TITLEX};
    int temp_TH2F_perCH_nbinsy[num_TH2F_perCHs] = {SUITE3_TH2F_PERCH_NBINSY};
    float temp_TH2F_perCH_lowy[num_TH2F_perCHs] = {SUITE3_TH2F_PERCH_LOWY};
    float temp_TH2F_perCH_highy[num_TH2F_perCHs] = {SUITE3_TH2F_PERCH_HIGHY};
    char temp_TH2F_perCH_titley[num_TH2F_perCHs][100] = {SUITE3_TH2F_PERCH_TITLEY};

    num_TH1F_PerTSs = SUITE3_TH1F_PERTS_NUM;
    num_TH1F_PerTSs = num_TH1F_PerTSs;

    num_TH2F_PerTSs = SUITE3_TH2F_PERTS_NUM;
    num_TH2F_PerTSs = num_TH2F_PerTSs;

    num_TProfiles = SUITE3_TPROFILE_NUM;
    num_TProfiles = num_TProfiles;

    num_TTrees = SUITE3_TTREE_NUM;
    num_TTrees = num_TTrees;

    num_loggers = SUITE3_LOGGER_NUM;
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

