// #############################################################
// #############################################################
// ###                                                       ###
// ###                     ./QIE10_loop.h                    ###
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
#include <math.h>

#include "TH1D.h"
#include "TH2D.h"
#include "TProfile.h"

using namespace std;

// ########################
// # LOOP_VARS STRUCTURES #
// ########################

// --- Suite 0: "full" ---

struct loop_vars {

  int adcped = 3;
  float qped = adc2fC_QIE10_refl[ adcped ];
  int* ch0_cid_ev = new int[10];
  float qsum_ped_EV;
  float qav_ped_EV;
  bool first_tdc_EV;
  float* qav_ped_CID = new float[4];
  int* cid_count  = new int[4];
  int* ch0_cid_ch = new int[10];
  float qsum_ped_CH;
  bool first_tdc_CH;
  bool bad_flag;

};

// ###################
// # PRE_EVENT_LOOPS #
// ###################

loop_vars pre_event_loop(int suite_code, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

  loop_vars prevars;

// --- Suite 0: "full" ---

  if (suite_code == 0) {


  }

// --- Suite 1: "CapIDtesting" ---

  if (suite_code == 1) {


  }

// --- Suite 2: "PedestalData" ---

  if (suite_code == 2) {


  }

// --- Suite 3: "AbsoluteTiming" ---

  if (suite_code == 3) {


  }

// --- Suite 4: "PhaseSampler" ---

  if (suite_code == 4) {


  }

  return prevars;

}

// #############
// # PRE_LOOPS #
// #############

loop_vars pre_loop(int suite_code, loop_vars prevars, QIE10DataFrame digis, int nCH, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

// --- Suite 0: "full" ---

  if (suite_code == 0) {

    prevars.qsum_ped_EV = 0;
    prevars.qav_ped_EV = 0;
    prevars.first_tdc_EV = 1;
    for (int jj=0 ; jj < 4; jj++){
      prevars.qav_ped_CID[jj] = 0;
      prevars.cid_count[jj] = 0;
    }
    int tTS_EV = digis.samples();
    int ADCsum_EV = 0;
    for (int loopTS=0 ; loopTS < tTS_EV ; loopTS++) {
      ADCsum_EV += digis[loopTS].adc();
    }
    float avADC_EV = (float)ADCsum_EV / (float)tTS_EV;
    if (_event_num < 3300) {
      TH2F_perEVs[4]->Fill ( _event_num, avADC_EV );
    }
    prevars.qsum_ped_CH = 0;
    prevars.first_tdc_CH = 1;
    int tTS = digis.samples();
    int ADCsum = 0;
    for (int loopTS=0 ; loopTS < tTS ; loopTS++) {
      ADCsum += digis[loopTS].adc();
    }
    float avADC = (float)ADCsum / (float)tTS;
    if (_event_num < 3300) {
      TH2F_perCHs[3][nCH]->Fill ( _event_num, avADC );
    }
    DetId detid_loc = digis.detid();
    HcalDetId hcaldetid_loc = HcalDetId(detid_loc);
    int iEta_loc = hcaldetid_loc.ieta();
    int iPhi_loc = hcaldetid_loc.iphi();
    int Depth_loc = hcaldetid_loc.depth();
    prevars.bad_flag = 0;
    bool zero_event_flag = 1;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if ( (digis[iTS].capid() - (digis[iTS-1].capid()+1)%4) != 0 ) {
        prevars.bad_flag = 1;
      }
      if (digis[iTS].capid() != 0) {
        zero_event_flag = 0;
      }
    }
    if (zero_event_flag == 1){
      prevars.bad_flag = 0;
    }
    if (prevars.bad_flag == 1) {
       loggers[0] << "#############" << endl;
       loggers[0] << "# BAD EVENT" << endl;
       loggers[0] << "# HF: " << Depth_loc << endl;
       loggers[0] << "# Slot: " << iPhi_loc << endl;
       loggers[0] << "# QIE: " << iEta_loc << endl;
       loggers[0] << "# nEV:" << _event_num << endl;
       loggers[0] << "#############" << endl;
      for (int iTS=0 ; iTS<10 ; iTS++) {
        if (( (digis[iTS].capid() - (digis[iTS-1].capid()+1)%4) != 0 ) && ( iTS != 0 )) {
           loggers[0] << "TS:" << iTS << "  --  CID " << digis[iTS].capid() << "  --  ADC " << digis[iTS].adc() << "  --  leTDC " << digis[iTS].le_tdc() << "  --  teTDC " << digis[iTS].te_tdc() << "  <<<<<<<<" << endl;
        }
        else {
           loggers[0] << "TS:" << iTS << "  --  CID " << digis[iTS].capid() << "  --  ADC " << digis[iTS].adc() << "  --  leTDC " << digis[iTS].le_tdc() << "  --  teTDC " << digis[iTS].te_tdc() << endl;
        }
      }
       loggers[0] << "#############" << endl;
    }

  }

// --- Suite 1: "CapIDtesting" ---

  if (suite_code == 1) {


  }

// --- Suite 2: "PedestalData" ---

  if (suite_code == 2) {

    prevars.qsum_ped_EV = 0;
    prevars.qav_ped_EV = 0;
    for (int jj=0 ; jj < 4; jj++){
      prevars.qav_ped_CID[jj] = 0;
      prevars.cid_count[jj] = 0;
    }
    prevars.qsum_ped_CH = 0;

  }

// --- Suite 3: "AbsoluteTiming" ---

  if (suite_code == 3) {

    prevars.first_tdc_EV = 1;
    prevars.first_tdc_CH = 1;

  }

// --- Suite 4: "PhaseSampler" ---

  if (suite_code == 4) {

    int tTS_EV = digis.samples();
    int ADCsum_EV = 0;
    for (int loopTS=0 ; loopTS < tTS_EV ; loopTS++) {
      ADCsum_EV += digis[loopTS].adc();
    }
    float avADC_EV = (float)ADCsum_EV / (float)tTS_EV;
    if (_event_num < 3300) {
      TH2F_perEVs[0]->Fill ( _event_num, avADC_EV );
    }
    int tTS = digis.samples();
    int ADCsum = 0;
    for (int loopTS=0 ; loopTS < tTS ; loopTS++) {
      ADCsum += digis[loopTS].adc();
    }
    float avADC = (float)ADCsum / (float)tTS;
    if (_event_num < 3300) {
      TH2F_perCHs[0][nCH]->Fill ( _event_num, avADC );
    }

  }

  return prevars;

}

// #########
// # LOOPS #
// #########

loop_vars loop(int suite_code, loop_vars prevars, QIE10DataFrame digis, int nTS, int nCH, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

// --- Suite 0: "full" ---

  if (suite_code == 0) {

    prevars.adcped = prevars.adcped;
    prevars.qped = prevars.qped;
    int tTS = digis.samples();
    tTS = tTS;
    int adc = digis[nTS].adc();
    adc = adc;
    int le_tdc = digis[nTS].le_tdc();
    le_tdc = le_tdc;
    int te_tdc = digis[nTS].te_tdc();
    te_tdc = te_tdc;
    int capid = digis[nTS].capid();
    capid = capid;
    int soi = digis[nTS].soi();
    soi = soi;
    float charge = adc2fC_QIE10_refl[ adc ] + 14.45;
    charge = charge;
    float acharge = charge - prevars.qped;
    acharge = acharge;
    if (nTS != 0) {
      TH1F_perEVs[0]->Fill (capid - (digis[nTS-1].capid()+1)%4 );
    }
    if (nCH == 0) {
      prevars.ch0_cid_ev[nTS] = digis[nTS].capid();
    }
    TH1F_perEVs[1]->Fill (capid - prevars.ch0_cid_ev[nTS]);
    TH1F_perEVs[2]->Fill ( adc );
    prevars.qsum_ped_EV += (charge - prevars.qped);
    prevars.qav_ped_EV += (charge - prevars.qped);
    if ((prevars.first_tdc_EV == 1) && (le_tdc < 50)) {
      prevars.first_tdc_EV = 0;
      float t_abs = ((nTS-1)*25.0) + (le_tdc*0.5);
      TH1F_perEVs[5]->Fill (t_abs);
    }
    TH2F_perEVs[0]->Fill ( nTS, adc );
    prevars.qav_ped_CID[capid] += (charge - prevars.qped);
    prevars.cid_count[capid] += 1;
    TH2F_perEVs[2]->Fill ( capid , adc );
    TH2F_perEVs[3]->Fill ( nTS, le_tdc );
    if (nTS != 0) {
      TH1F_perCHs[0][nCH]->Fill (capid - (digis[nTS-1].capid()+1)%4 );
    }
    if (nCH == 0) {
      prevars.ch0_cid_ch[nTS] = digis[nTS].capid();
    }
    TH1F_perCHs[1][nCH]->Fill (capid - prevars.ch0_cid_ch[nTS]);
    TH1F_perCHs[2][nCH]->Fill ( adc );
    prevars.qsum_ped_CH += (charge - prevars.qped);
    if ((prevars.first_tdc_CH == 1) && (le_tdc < 50)) {
      prevars.first_tdc_CH = 0;
      float t_abs = (nTS*25.0) + (le_tdc*0.5);
      TH1F_perCHs[4][nCH]->Fill (t_abs);
    }
    TH2F_perCHs[0][nCH]->Fill ( nTS, capid );
    TH2F_perCHs[1][nCH]->Fill ( nTS, adc );
    TH2F_perCHs[2][nCH]->Fill ( nTS, le_tdc );

  }

// --- Suite 1: "CapIDtesting" ---

  if (suite_code == 1) {

    prevars.adcped = prevars.adcped;
    prevars.qped = prevars.qped;
    int tTS = digis.samples();
    tTS = tTS;
    int adc = digis[nTS].adc();
    adc = adc;
    int le_tdc = digis[nTS].le_tdc();
    le_tdc = le_tdc;
    int te_tdc = digis[nTS].te_tdc();
    te_tdc = te_tdc;
    int capid = digis[nTS].capid();
    capid = capid;
    int soi = digis[nTS].soi();
    soi = soi;
    float charge = adc2fC_QIE10_refl[ adc ] + 14.45;
    charge = charge;
    float acharge = charge - prevars.qped;
    acharge = acharge;
    if (nTS != 0) {
      TH1F_perEVs[0]->Fill (capid - (digis[nTS-1].capid()+1)%4 );
    }
    if (nCH == 0) {
      prevars.ch0_cid_ev[nTS] = digis[nTS].capid();
    }
    TH1F_perEVs[1]->Fill (capid - prevars.ch0_cid_ev[nTS]);
    if (nTS != 0) {
      TH1F_perCHs[0][nCH]->Fill (capid - (digis[nTS-1].capid()+1)%4 );
    }
    if (nCH == 0) {
      prevars.ch0_cid_ch[nTS] = digis[nTS].capid();
    }
    TH1F_perCHs[1][nCH]->Fill (capid - prevars.ch0_cid_ch[nTS]);
    TH2F_perCHs[0][nCH]->Fill ( nTS, capid );

  }

// --- Suite 2: "PedestalData" ---

  if (suite_code == 2) {

    prevars.adcped = prevars.adcped;
    prevars.qped = prevars.qped;
    int tTS = digis.samples();
    tTS = tTS;
    int adc = digis[nTS].adc();
    adc = adc;
    int le_tdc = digis[nTS].le_tdc();
    le_tdc = le_tdc;
    int te_tdc = digis[nTS].te_tdc();
    te_tdc = te_tdc;
    int capid = digis[nTS].capid();
    capid = capid;
    int soi = digis[nTS].soi();
    soi = soi;
    float charge = adc2fC_QIE10_refl[ adc ] + 14.45;
    charge = charge;
    float acharge = charge - prevars.qped;
    acharge = acharge;
    TH1F_perEVs[0]->Fill ( adc );
    prevars.qsum_ped_EV += (charge - prevars.qped);
    prevars.qav_ped_EV += (charge - prevars.qped);
    TH2F_perEVs[0]->Fill ( nTS, adc );
    prevars.qav_ped_CID[capid] += (charge - prevars.qped);
    prevars.cid_count[capid] += 1;
    TH2F_perEVs[2]->Fill ( capid , adc );
    TH1F_perCHs[0][nCH]->Fill ( adc );
    prevars.qsum_ped_CH += (charge - prevars.qped);
    TH2F_perCHs[0][nCH]->Fill ( nTS, adc );

  }

// --- Suite 3: "AbsoluteTiming" ---

  if (suite_code == 3) {

    prevars.adcped = prevars.adcped;
    prevars.qped = prevars.qped;
    int tTS = digis.samples();
    tTS = tTS;
    int adc = digis[nTS].adc();
    adc = adc;
    int le_tdc = digis[nTS].le_tdc();
    le_tdc = le_tdc;
    int te_tdc = digis[nTS].te_tdc();
    te_tdc = te_tdc;
    int capid = digis[nTS].capid();
    capid = capid;
    int soi = digis[nTS].soi();
    soi = soi;
    float charge = adc2fC_QIE10_refl[ adc ] + 14.45;
    charge = charge;
    float acharge = charge - prevars.qped;
    acharge = acharge;
    if ((prevars.first_tdc_EV == 1) && (le_tdc < 50)) {
      prevars.first_tdc_EV = 0;
      float t_abs = ((nTS-1)*25.0) + (le_tdc*0.5);
      TH1F_perEVs[0]->Fill (t_abs);
    }
    TH2F_perEVs[0]->Fill ( nTS, le_tdc );
    if ((prevars.first_tdc_CH == 1) && (le_tdc < 50)) {
      prevars.first_tdc_CH = 0;
      float t_abs = (nTS*25.0) + (le_tdc*0.5);
      TH1F_perCHs[0][nCH]->Fill (t_abs);
    }
    TH2F_perCHs[0][nCH]->Fill ( nTS, le_tdc );

  }

// --- Suite 4: "PhaseSampler" ---

  if (suite_code == 4) {

    prevars.adcped = prevars.adcped;
    prevars.qped = prevars.qped;
    int tTS = digis.samples();
    tTS = tTS;
    int adc = digis[nTS].adc();
    adc = adc;
    int le_tdc = digis[nTS].le_tdc();
    le_tdc = le_tdc;
    int te_tdc = digis[nTS].te_tdc();
    te_tdc = te_tdc;
    int capid = digis[nTS].capid();
    capid = capid;
    int soi = digis[nTS].soi();
    soi = soi;
    float charge = adc2fC_QIE10_refl[ adc ] + 14.45;
    charge = charge;
    float acharge = charge - prevars.qped;
    acharge = acharge;

  }

  return prevars;

}

// ##############
// # POST_LOOPS #
// ##############

loop_vars post_loop(int suite_code, loop_vars prevars, QIE10DataFrame digis, int nCH, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

// --- Suite 0: "full" ---

  if (suite_code == 0) {

    TH1F_perEVs[3]->Fill ( prevars.qsum_ped_EV );
    TH1F_perEVs[4]->Fill ( prevars.qsum_ped_EV / float(digis.samples()) );
    for (int jj=0 ; jj < 4; jj++){
      TH2F_perEVs[1]->Fill ( jj , (prevars.qav_ped_CID[jj] / prevars.cid_count[jj]) );
    }
    TH1F_perCHs[3][nCH]->Fill ( prevars.qsum_ped_CH );

  }

// --- Suite 1: "CapIDtesting" ---

  if (suite_code == 1) {


  }

// --- Suite 2: "PedestalData" ---

  if (suite_code == 2) {

    TH1F_perEVs[1]->Fill ( prevars.qsum_ped_EV );
    TH1F_perEVs[2]->Fill ( prevars.qsum_ped_EV / float(digis.samples()) );
    for (int jj=0 ; jj < 4; jj++){
      TH2F_perEVs[1]->Fill ( jj , (prevars.qav_ped_CID[jj] / prevars.cid_count[jj]) );
    }
    TH1F_perCHs[1][nCH]->Fill ( prevars.qsum_ped_CH );

  }

// --- Suite 3: "AbsoluteTiming" ---

  if (suite_code == 3) {


  }

// --- Suite 4: "PhaseSampler" ---

  if (suite_code == 4) {


  }

  return prevars;

}

// ####################
// # POST_EVENT_LOOPS #
// ####################

void post_event_loop(int suite_code, loop_vars prevars, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

// --- Suite 0: "full" ---

  if (suite_code == 0) {


  }

// --- Suite 1: "CapIDtesting" ---

  if (suite_code == 1) {


  }

// --- Suite 2: "PedestalData" ---

  if (suite_code == 2) {


  }

// --- Suite 3: "AbsoluteTiming" ---

  if (suite_code == 3) {


  }

// --- Suite 4: "PhaseSampler" ---

  if (suite_code == 4) {


  }

}

