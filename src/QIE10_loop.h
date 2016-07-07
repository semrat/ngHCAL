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

  int pdac2poff[64] = {0,-1,-2,-3,-4,-5,-6,-7,-8,-9,-10,-11,-12,-13,-14,-15,-16,-17,-18,-19,-20,-21,-22,-23,-24,-25,-26,-27,-28,-29,-30,-31,0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31};
  int adcped = 3;
  float qped = adc2fC_QIE10_refl[ adcped ];
  bool corrupt;
  bool zero_event_CapIDrot_EV;
  int* ch0_cid_ev = new int[10];
  bool zero_event_CapAllign_EV;
  float qsum_ped_EV;
  float qav_ped_EV;
  bool first_tdc_EV;
  float qsum_qr_ev;
  float qmax_qr_ev;
  float qsum_ici7_ev;
  float qmax_ici7_ev;
  bool zero_event_CIDvsTS_EV;
  float* qav_ped_CID = new float[4];
  int* cid_count  = new int[4];
  bool first_tdc_scan_EV;
  float ici_ev[8] = {90, 180, 360, 720, 1440, 2880, 5760, 8640};
  float qsum_ici_ev;
  float qsum_qr2_ev;
  float qmax_qr2_ev;
  float qsum_vb_EV;
  float qsum_qr_vb_ev;
  float qmax_qr_vb_ev;
  float qsum_qr2_vb_ev;
  float qmax_qr2_vb_ev;
  int ts_max_ev;
  bool zero_event_CapIDrot_CH;
  int* ch0_cid_ch = new int[10];
  bool zero_event_CapAllign_CH;
  float qsum_ped_CH;
  bool first_tdc_CH;
  float qsum_qr_ch;
  float qmax_qr_ch;
  float qsum_ici7_ch;
  float qmax_ici7_ch;
  bool zero_event_CIDvsTS_CH;
  bool first_tdc_scan_CH;
  float ici_ch[8] = {90, 180, 360, 720, 1440, 2880, 5760, 8640};
  float qsum_ici_ch;
  float qsum_qr2_ch;
  float qmax_qr2_ch;
  float qsum_vb_CH;
  float qsum_qr_vb_ch;
  float qmax_qr_vb_ch;
  float qsum_qr2_vb_ch;
  float qmax_qr2_vb_ch;
  int ts_max_ch;
  float qsum_qr2_rin_ch;
  float qmax_qr2_rin_ch;
  int ts_max_rin_ch;
  float qsum_vb_PR;
  float qsum_qr_vb_pr;
  float qmax_qr_vb_pr;
  float qsum_qr2_vb_pr;
  float qmax_qr2_vb_pr;
  int ts_max_pr;
  float qsum_qr3_vb_ch;
  float qmax_qr3_vb_ch;
  int ts_max3_ch;
  float qsum_qr2_rin_pr;
  float qmax_qr2_rin_pr;
  int ts_max_rin_pr;
  bool bad_flag;

};

// ###################
// # PRE_EVENT_LOOPS #
// ###################

loop_vars pre_event_loop(std::string parameter, float val, int suite_code, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

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

// --- Suite 4: "PedScanner" ---

  if (suite_code == 4) {


  }

// --- Suite 5: "PhaseScanner" ---

  if (suite_code == 5) {


  }

// --- Suite 6: "ICIScanner" ---

  if (suite_code == 6) {


  }

// --- Suite 7: "LED_Vb_Scan" ---

  if (suite_code == 7) {


  }

// --- Suite 8: "RinSel_Scan" ---

  if (suite_code == 8) {


  }

  return prevars;

}

// #############
// # PRE_LOOPS #
// #############

loop_vars pre_loop(std::string parameter, float val, int suite_code, loop_vars prevars, QIE10DataFrame digis, int nCH, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

// --- Suite 0: "full" ---

  if (suite_code == 0) {

    prevars.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.corrupt = 1;
      }
    }
    prevars.zero_event_CapIDrot_EV = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CapIDrot_EV = 1;
      }
    }
    prevars.zero_event_CapAllign_EV = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CapAllign_EV = 1;
      }
    }
    prevars.qsum_ped_EV = 0;
    prevars.qav_ped_EV = 0;
    prevars.first_tdc_EV = 1;
    prevars.qsum_qr_ev = 0.0;
    prevars.qmax_qr_ev = 0.0;
    prevars.qsum_ici7_ev = 0;
    prevars.qmax_ici7_ev = 0;
    prevars.zero_event_CIDvsTS_EV = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CIDvsTS_EV = 1;
      }
    }
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
    if (prevars.corrupt == 0) {
      TH2F_perEVs[5]->Fill ( _event_num, avADC_EV );
    }
    int tTS_scan_EV = digis.samples();
    int ADCsum_scan_EV = 0;
    for (int loopTS=0 ; loopTS < tTS_scan_EV ; loopTS++) {
      ADCsum_scan_EV += digis[loopTS].adc();
    }
    float avADC_scan_EV = (float)ADCsum_scan_EV / (float)tTS_scan_EV;
    if (prevars.corrupt == 0) {
      TH2F_perEVs[6]->Fill ( prevars.pdac2poff[(int)val] , avADC_scan_EV );
    }
    int tTS_scan_qav_EV = digis.samples();
    int qsum_scan_EV = 0;
    for (int loopTS=0 ; loopTS < tTS_scan_qav_EV ; loopTS++) {
      qsum_scan_EV += adc2fC_QIE10_refl[ digis[loopTS].adc() ] + 14.45;
    }
    float qav_scan_EV = (float)qsum_scan_EV / (float)tTS_scan_qav_EV;
    if (prevars.corrupt == 0) {
      TH2F_perEVs[7]->Fill ( prevars.pdac2poff[(int)val] , qav_scan_EV );
    }
    prevars.first_tdc_scan_EV = 1;
    prevars.qsum_ici_ev = 0.0;
    prevars.qsum_qr2_ev = 0.0;
    prevars.qmax_qr2_ev = 0.0;
    prevars.qsum_vb_EV = 0;
    prevars.qsum_qr_vb_ev = 0.0;
    prevars.qmax_qr_vb_ev = 0.0;
    prevars.qsum_qr2_vb_ev = 0.0;
    prevars.qmax_qr2_vb_ev = 0.0;
    prevars.ts_max_ev = 0;
    prevars.zero_event_CapIDrot_CH = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CapIDrot_CH = 1;
      }
    }
    prevars.zero_event_CapAllign_CH = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CapAllign_CH = 1;
      }
    }
    prevars.qsum_ped_CH = 0;
    prevars.first_tdc_CH = 1;
    prevars.qsum_qr_ch = 0.0;
    prevars.qmax_qr_ch = 0.0;
    prevars.qsum_ici7_ch = 0;
    prevars.qmax_ici7_ch = 0;
    prevars.zero_event_CIDvsTS_CH = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CIDvsTS_CH = 1;
      }
    }
    int tTS = digis.samples();
    int ADCsum = 0;
    for (int loopTS=0 ; loopTS < tTS ; loopTS++) {
      ADCsum += digis[loopTS].adc();
    }
    float avADC = (float)ADCsum / (float)tTS;
    if (prevars.corrupt == 0) {
      TH2F_perCHs[3][nCH]->Fill ( _event_num, avADC );
    }
    int tTS_scan_CH = digis.samples();
    int ADCsum_scan_CH = 0;
    for (int loopTS=0 ; loopTS < tTS_scan_CH ; loopTS++) {
      ADCsum_scan_CH += digis[loopTS].adc();
    }
    float avADC_scan_CH = (float)ADCsum_scan_CH / (float)tTS_scan_CH;
    if (prevars.corrupt == 0) {
      TH2F_perCHs[4][nCH]->Fill ( prevars.pdac2poff[(int)val] , avADC_scan_CH );
    }
    int tTS_scan_qav_CH = digis.samples();
    int qsum_scan_CH = 0;
    for (int loopTS=0 ; loopTS < tTS_scan_qav_CH ; loopTS++) {
      qsum_scan_CH += adc2fC_QIE10_refl[ digis[loopTS].adc() ] + 14.45;
    }
    float qav_scan_CH = (float)qsum_scan_CH / (float)tTS_scan_qav_CH;
    if (prevars.corrupt == 0) {
      TH2F_perCHs[7][nCH]->Fill ( prevars.pdac2poff[(int)val] , qav_scan_CH );
    }
    prevars.first_tdc_scan_CH = 1;
    prevars.qsum_ici_ch = 0.0;
    prevars.qsum_qr2_ch = 0.0;
    prevars.qmax_qr2_ch = 0.0;
    prevars.qsum_vb_CH = 0;
    prevars.qsum_qr_vb_ch = 0.0;
    prevars.qmax_qr_vb_ch = 0.0;
    prevars.qsum_qr2_vb_ch = 0.0;
    prevars.qmax_qr2_vb_ch = 0.0;
    prevars.ts_max_ch = 0;
    prevars.qsum_qr2_rin_ch = 0.0;
    prevars.qmax_qr2_rin_ch = 0.0;
    prevars.ts_max_rin_ch = 0;
    prevars.qsum_vb_PR = 0;
    prevars.qsum_qr_vb_pr = 0.0;
    prevars.qmax_qr_vb_pr = 0.0;
    prevars.qsum_qr2_vb_pr = 0.0;
    prevars.qmax_qr2_vb_pr = 0.0;
    prevars.ts_max_pr = 0;
    prevars.qsum_qr3_vb_ch = 0.0;
    prevars.qmax_qr3_vb_ch = 0.0;
    prevars.ts_max3_ch = 0;
    prevars.qsum_qr2_rin_pr = 0.0;
    prevars.qmax_qr2_rin_pr = 0.0;
    prevars.ts_max_rin_pr = 0;
    DetId detid_loc = digis.detid();
    HcalDetId hcaldetid_loc = HcalDetId(detid_loc);
    int iEta_loc = hcaldetid_loc.ieta();
    int iPhi_loc = hcaldetid_loc.iphi();
    int Depth_loc = hcaldetid_loc.depth();
    prevars.bad_flag = 0;
    bool zero_event_flag = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if ( (digis[iTS].capid() - (digis[iTS-1].capid()+1)%4) != 0 ) {
        prevars.bad_flag = 1;
      }
      if (digis[iTS].le_tdc() == 0) {
        zero_event_flag = 1;
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
    DetId detid_loc_z = digis.detid();
    HcalDetId hcaldetid_loc_z = HcalDetId(detid_loc_z);
    int iEta_loc_z = hcaldetid_loc_z.ieta();
    int iPhi_loc_z = hcaldetid_loc_z.iphi();
    int Depth_loc_z = hcaldetid_loc_z.depth();
    bool zero_event_flag_z = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        zero_event_flag_z = 1;
      }
    }
    if (zero_event_flag_z == 1) {
       loggers[1] << "#############" << endl;
       loggers[1] << "# BAD EVENT" << endl;
       loggers[1] << "# HF: " << Depth_loc_z << endl;
       loggers[1] << "# Slot: " << iPhi_loc_z << endl;
       loggers[1] << "# QIE: " << iEta_loc_z << endl;
       loggers[1] << "# nEV:" << _event_num << endl;
       loggers[1] << "#############" << endl;
       for (int iTS=0 ; iTS<10 ; iTS++) {
          loggers[1] << "TS:" << iTS << "  --  CID " << digis[iTS].capid() << "  --  ADC " << digis[iTS].adc() << "  --  leTDC " << digis[iTS].le_tdc() << "  --  teTDC " << digis[iTS].te_tdc() << endl;
       }
       loggers[1] << "#############" << endl;
    }

  }

// --- Suite 1: "CapIDtesting" ---

  if (suite_code == 1) {

    prevars.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.corrupt = 1;
      }
    }
    prevars.zero_event_CapIDrot_EV = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CapIDrot_EV = 1;
      }
    }
    prevars.zero_event_CapAllign_EV = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CapAllign_EV = 1;
      }
    }
    prevars.zero_event_CIDvsTS_EV = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CIDvsTS_EV = 1;
      }
    }
    prevars.zero_event_CapIDrot_CH = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CapIDrot_CH = 1;
      }
    }
    prevars.zero_event_CapAllign_CH = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CapAllign_CH = 1;
      }
    }
    prevars.zero_event_CIDvsTS_CH = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.zero_event_CIDvsTS_CH = 1;
      }
    }
    DetId detid_loc = digis.detid();
    HcalDetId hcaldetid_loc = HcalDetId(detid_loc);
    int iEta_loc = hcaldetid_loc.ieta();
    int iPhi_loc = hcaldetid_loc.iphi();
    int Depth_loc = hcaldetid_loc.depth();
    prevars.bad_flag = 0;
    bool zero_event_flag = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if ( (digis[iTS].capid() - (digis[iTS-1].capid()+1)%4) != 0 ) {
        prevars.bad_flag = 1;
      }
      if (digis[iTS].le_tdc() == 0) {
        zero_event_flag = 1;
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
    DetId detid_loc_z = digis.detid();
    HcalDetId hcaldetid_loc_z = HcalDetId(detid_loc_z);
    int iEta_loc_z = hcaldetid_loc_z.ieta();
    int iPhi_loc_z = hcaldetid_loc_z.iphi();
    int Depth_loc_z = hcaldetid_loc_z.depth();
    bool zero_event_flag_z = 0;
    for (int iTS=1 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        zero_event_flag_z = 1;
      }
    }
    if (zero_event_flag_z == 1) {
       loggers[1] << "#############" << endl;
       loggers[1] << "# BAD EVENT" << endl;
       loggers[1] << "# HF: " << Depth_loc_z << endl;
       loggers[1] << "# Slot: " << iPhi_loc_z << endl;
       loggers[1] << "# QIE: " << iEta_loc_z << endl;
       loggers[1] << "# nEV:" << _event_num << endl;
       loggers[1] << "#############" << endl;
       for (int iTS=0 ; iTS<10 ; iTS++) {
          loggers[1] << "TS:" << iTS << "  --  CID " << digis[iTS].capid() << "  --  ADC " << digis[iTS].adc() << "  --  leTDC " << digis[iTS].le_tdc() << "  --  teTDC " << digis[iTS].te_tdc() << endl;
       }
       loggers[1] << "#############" << endl;
    }

  }

// --- Suite 2: "PedestalData" ---

  if (suite_code == 2) {

    prevars.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.corrupt = 1;
      }
    }
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

    prevars.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.corrupt = 1;
      }
    }
    prevars.first_tdc_EV = 1;
    prevars.first_tdc_CH = 1;

  }

// --- Suite 4: "PedScanner" ---

  if (suite_code == 4) {

    prevars.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.corrupt = 1;
      }
    }
    int tTS_EV = digis.samples();
    int ADCsum_EV = 0;
    for (int loopTS=0 ; loopTS < tTS_EV ; loopTS++) {
      ADCsum_EV += digis[loopTS].adc();
    }
    float avADC_EV = (float)ADCsum_EV / (float)tTS_EV;
    if (prevars.corrupt == 0) {
      TH2F_perEVs[0]->Fill ( _event_num, avADC_EV );
    }
    int tTS_scan_EV = digis.samples();
    int ADCsum_scan_EV = 0;
    for (int loopTS=0 ; loopTS < tTS_scan_EV ; loopTS++) {
      ADCsum_scan_EV += digis[loopTS].adc();
    }
    float avADC_scan_EV = (float)ADCsum_scan_EV / (float)tTS_scan_EV;
    if (prevars.corrupt == 0) {
      TH2F_perEVs[1]->Fill ( prevars.pdac2poff[(int)val] , avADC_scan_EV );
    }
    int tTS_scan_qav_EV = digis.samples();
    int qsum_scan_EV = 0;
    for (int loopTS=0 ; loopTS < tTS_scan_qav_EV ; loopTS++) {
      qsum_scan_EV += adc2fC_QIE10_refl[ digis[loopTS].adc() ] + 14.45;
    }
    float qav_scan_EV = (float)qsum_scan_EV / (float)tTS_scan_qav_EV;
    if (prevars.corrupt == 0) {
      TH2F_perEVs[2]->Fill ( prevars.pdac2poff[(int)val] , qav_scan_EV );
    }
    int tTS = digis.samples();
    int ADCsum = 0;
    for (int loopTS=0 ; loopTS < tTS ; loopTS++) {
      ADCsum += digis[loopTS].adc();
    }
    float avADC = (float)ADCsum / (float)tTS;
    if (prevars.corrupt == 0) {
      TH2F_perCHs[0][nCH]->Fill ( _event_num, avADC );
    }
    int tTS_scan_CH = digis.samples();
    int ADCsum_scan_CH = 0;
    for (int loopTS=0 ; loopTS < tTS_scan_CH ; loopTS++) {
      ADCsum_scan_CH += digis[loopTS].adc();
    }
    float avADC_scan_CH = (float)ADCsum_scan_CH / (float)tTS_scan_CH;
    if (prevars.corrupt == 0) {
      TH2F_perCHs[1][nCH]->Fill ( prevars.pdac2poff[(int)val] , avADC_scan_CH );
    }
    int tTS_scan_qav_CH = digis.samples();
    int qsum_scan_CH = 0;
    for (int loopTS=0 ; loopTS < tTS_scan_qav_CH ; loopTS++) {
      qsum_scan_CH += adc2fC_QIE10_refl[ digis[loopTS].adc() ] + 14.45;
    }
    float qav_scan_CH = (float)qsum_scan_CH / (float)tTS_scan_qav_CH;
    if (prevars.corrupt == 0) {
      TH2F_perCHs[4][nCH]->Fill ( prevars.pdac2poff[(int)val] , qav_scan_CH );
    }

  }

// --- Suite 5: "PhaseScanner" ---

  if (suite_code == 5) {

    prevars.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.corrupt = 1;
      }
    }
    prevars.first_tdc_scan_EV = 1;
    prevars.first_tdc_scan_CH = 1;

  }

// --- Suite 6: "ICIScanner" ---

  if (suite_code == 6) {

    prevars.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.corrupt = 1;
      }
    }
    prevars.first_tdc_EV = 1;
    prevars.qsum_qr_ev = 0.0;
    prevars.qmax_qr_ev = 0.0;
    prevars.qsum_ici7_ev = 0;
    prevars.qmax_ici7_ev = 0;
    prevars.qsum_ici_ev = 0.0;
    prevars.qsum_qr2_ev = 0.0;
    prevars.qmax_qr2_ev = 0.0;
    prevars.first_tdc_CH = 1;
    prevars.qsum_qr_ch = 0.0;
    prevars.qmax_qr_ch = 0.0;
    prevars.qsum_ici7_ch = 0;
    prevars.qmax_ici7_ch = 0;
    prevars.qsum_ici_ch = 0.0;
    prevars.qsum_qr2_ch = 0.0;
    prevars.qmax_qr2_ch = 0.0;

  }

// --- Suite 7: "LED_Vb_Scan" ---

  if (suite_code == 7) {

    prevars.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.corrupt = 1;
      }
    }
    prevars.qsum_vb_EV = 0;
    prevars.qsum_qr_vb_ev = 0.0;
    prevars.qmax_qr_vb_ev = 0.0;
    prevars.qsum_qr2_vb_ev = 0.0;
    prevars.qmax_qr2_vb_ev = 0.0;
    prevars.ts_max_ev = 0;
    prevars.qsum_vb_CH = 0;
    prevars.qsum_qr_vb_ch = 0.0;
    prevars.qmax_qr_vb_ch = 0.0;
    prevars.qsum_qr2_vb_ch = 0.0;
    prevars.qmax_qr2_vb_ch = 0.0;
    prevars.ts_max_ch = 0;
    prevars.qsum_vb_PR = 0;
    prevars.qsum_qr_vb_pr = 0.0;
    prevars.qmax_qr_vb_pr = 0.0;
    prevars.qsum_qr2_vb_pr = 0.0;
    prevars.qmax_qr2_vb_pr = 0.0;
    prevars.ts_max_pr = 0;
    prevars.qsum_qr3_vb_ch = 0.0;
    prevars.qmax_qr3_vb_ch = 0.0;
    prevars.ts_max3_ch = 0;

  }

// --- Suite 8: "RinSel_Scan" ---

  if (suite_code == 8) {

    prevars.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if (digis[iTS].le_tdc() == 0) {
        prevars.corrupt = 1;
      }
    }
    prevars.qsum_qr2_rin_ch = 0.0;
    prevars.qmax_qr2_rin_ch = 0.0;
    prevars.ts_max_rin_ch = 0;
    prevars.qsum_qr2_rin_pr = 0.0;
    prevars.qmax_qr2_rin_pr = 0.0;
    prevars.ts_max_rin_pr = 0;

  }

  return prevars;

}

// #########
// # LOOPS #
// #########

loop_vars loop(std::string parameter, float val, int suite_code, loop_vars prevars, QIE10DataFrame digis, int nTS, int nCH, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

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
      if (prevars.zero_event_CapIDrot_EV == 0) {
        if (_event_num > 2) {
          TH1F_perEVs[0]->Fill (capid - (digis[nTS-1].capid()+1)%4 );
        }
      }
    }
    if (nCH == 0) {
      prevars.ch0_cid_ev[nTS] = digis[nTS].capid();
    }
    if (prevars.zero_event_CapAllign_EV == 0) {
      if (_event_num > 2) {
        TH1F_perEVs[1]->Fill (capid - prevars.ch0_cid_ev[nTS]);
      }
    }
    TH1F_perEVs[2]->Fill ( adc );
    prevars.qsum_ped_EV += (charge - prevars.qped);
    prevars.qav_ped_EV += (charge - prevars.qped);
    if ((prevars.first_tdc_EV == 1) && (le_tdc < 50)) {
      prevars.first_tdc_EV = 0;
      float t_abs = ((nTS-1)*25.0) + (le_tdc*0.5);
      if (prevars.corrupt == 0) {
        TH1F_perEVs[5]->Fill (t_abs);
      }
    }
    if ( val == 38.0 ) {
      if (prevars.corrupt == 0) {
        TH1F_perEVs[6]->Fill ( adc );
      }
    }
    prevars.qsum_qr_ev += charge;
    if ( charge > prevars.qmax_qr_ev ) {
      prevars.qmax_qr_ev = charge;
    }
    prevars.qsum_ici7_ev += charge;
    if (charge > prevars.qmax_ici7_ev ) {
      prevars.qmax_ici7_ev = charge;
    }
    if ( val == 7 ) {
      TH1F_perEVs[8]->Fill ( prevars.qmax_ici7_ev / prevars.qsum_ici7_ev );
    }
    if (prevars.zero_event_CIDvsTS_EV == 0) {
      if (_event_num > 2) {
        TH2F_perEVs[0]->Fill ( nTS, capid );
      }
    }
    TH2F_perEVs[1]->Fill ( nTS, adc );
    prevars.qav_ped_CID[capid] += (charge - prevars.qped);
    prevars.cid_count[capid] += 1;
    TH2F_perEVs[3]->Fill ( capid , adc );
    TH2F_perEVs[4]->Fill ( nTS, le_tdc );
    if ((prevars.first_tdc_scan_EV == 1) && (le_tdc < 50)) {
      prevars.first_tdc_scan_EV = 0;
      float t_abs = ((nTS-1)*25.0) + (le_tdc*0.5);
      if ( val < 50 ) {
         TH2F_perEVs[8]->Fill (val/2.0,t_abs);
      }
      if ( val > 63 ) {
         TH2F_perEVs[8]->Fill ((val-14.0)/2.0,t_abs);
      }
    }
    prevars.qsum_ici_ev += charge;
    prevars.qsum_qr2_ev += charge;
    if ( charge > prevars.qmax_qr2_ev ) {
      prevars.qmax_qr2_ev = charge;
    }
    prevars.qsum_vb_EV += charge;
    prevars.qsum_qr_vb_ev += charge;
    if ( charge > prevars.qmax_qr_vb_ev ) {
      prevars.qmax_qr_vb_ev = charge;
    }
    prevars.qsum_qr2_vb_ev += charge;
    if ( charge > prevars.qmax_qr2_vb_ev ) {
      prevars.qmax_qr2_vb_ev = charge;
      prevars.ts_max_ev = nTS;
    }
    if (nTS != 0) {
      if (prevars.zero_event_CapIDrot_CH == 0) {
        if (_event_num > 2) {
          TH1F_perCHs[0][nCH]->Fill (capid - (digis[nTS-1].capid()+1)%4 );
        }
      }
    }
    if (nCH == 0) {
      prevars.ch0_cid_ch[nTS] = digis[nTS].capid();
    }
    if (prevars.zero_event_CapAllign_CH == 0) {
      if (_event_num > 2) {
        TH1F_perCHs[1][nCH]->Fill (capid - prevars.ch0_cid_ch[nTS]);
      }
    }
    TH1F_perCHs[2][nCH]->Fill ( adc );
    prevars.qsum_ped_CH += (charge - prevars.qped);
    if ((prevars.first_tdc_CH == 1) && (le_tdc < 50)) {
      prevars.first_tdc_CH = 0;
      float t_abs = (nTS*25.0) + (le_tdc*0.5);
      if (prevars.corrupt == 0) {
        TH1F_perCHs[4][nCH]->Fill (t_abs);
      }
    }
    if ( val == 38.0 ) {
      if (prevars.corrupt == 0) {
        TH1F_perCHs[5][nCH]->Fill ( adc );
      }
    }
    prevars.qsum_qr_ch += charge;
    if ( charge > prevars.qmax_qr_ch ) {
      prevars.qmax_qr_ch = charge;
    }
    prevars.qsum_ici7_ch += charge;
    if (charge > prevars.qmax_ici7_ch ) {
      prevars.qmax_ici7_ch = charge;
    }
    if (prevars.zero_event_CIDvsTS_CH == 0) {
      if (_event_num > 2) {
        TH2F_perCHs[0][nCH]->Fill ( nTS, capid );
      }
    }
    TH2F_perCHs[1][nCH]->Fill ( nTS, adc );
    TH2F_perCHs[2][nCH]->Fill ( nTS, le_tdc );
    if (prevars.corrupt == 0) {
      TH2F_perCHs[5][nCH]->Fill ( prevars.pdac2poff[(int)val] , adc);
    }
    if (prevars.corrupt == 0) {
      TH2F_perCHs[6][nCH]->Fill ( prevars.pdac2poff[(int)val] , charge);
    }
    if ((prevars.first_tdc_scan_CH == 1) && (le_tdc < 50)) {
      prevars.first_tdc_scan_CH = 0;
      float t_abs = ((nTS-1)*25.0) + (le_tdc*0.5);
      if ( val < 50 ) {
         TH2F_perCHs[8][nCH]->Fill (val/2.0,t_abs);
      }
      if ( val > 63 ) {
         TH2F_perCHs[8][nCH]->Fill ((val-14.0)/2.0,t_abs);
      }
    }
    prevars.qsum_ici_ch += charge;
    prevars.qsum_qr2_ch += charge;
    if ( charge > prevars.qmax_qr2_ch ) {
      prevars.qmax_qr2_ch = charge;
    }
    if ( val == 0 ) {
      TH2F_perCHs[11][nCH]->Fill ( nTS, charge );
    }
    if ( val == 1 ) {
      TH2F_perCHs[12][nCH]->Fill ( nTS, charge );
    }
    if ( val == 2 ) {
      TH2F_perCHs[13][nCH]->Fill ( nTS, charge );
    }
    if ( val == 3 ) {
      TH2F_perCHs[14][nCH]->Fill ( nTS, charge );
    }
    if ( val == 4 ) {
      TH2F_perCHs[15][nCH]->Fill ( nTS, charge );
    }
    if ( val == 5 ) {
      TH2F_perCHs[16][nCH]->Fill ( nTS, charge );
    }
    if ( val == 6 ) {
      TH2F_perCHs[17][nCH]->Fill ( nTS, charge );
    }
    if ( val == 7 ) {
      TH2F_perCHs[18][nCH]->Fill ( nTS, charge );
    }
    prevars.qsum_vb_CH += charge;
    prevars.qsum_qr_vb_ch += charge;
    if ( charge > prevars.qmax_qr_vb_ch ) {
      prevars.qmax_qr_vb_ch = charge;
    }
    prevars.qsum_qr2_vb_ch += charge;
    if ( charge > prevars.qmax_qr2_vb_ch ) {
      prevars.qmax_qr2_vb_ch = charge;
      prevars.ts_max_ch = nTS;
    }
    TH2F_perCHs[22][nCH]->Fill ( nTS , le_tdc );
    if ( val == 2.5 ) {
      TH2F_perCHs[23][nCH]->Fill (nTS,charge);
    }
    prevars.qsum_qr2_rin_ch += charge;
    if ( charge > prevars.qmax_qr2_rin_ch ) {
      prevars.qmax_qr2_rin_ch = charge;
      prevars.ts_max_rin_ch = nTS;
    }
    if ( val == 0 ) {
      TH2F_perCHs[25][nCH]->Fill (nTS,adc);
    }
    if ( val == 1 ) {
      TH2F_perCHs[26][nCH]->Fill (nTS,adc);
    }
    if ( val == 2 ) {
      TH2F_perCHs[27][nCH]->Fill (nTS,adc);
    }
    if ( val == 3 ) {
      TH2F_perCHs[28][nCH]->Fill (nTS,adc);
    }
    if ( val == 4 ) {
      TH2F_perCHs[29][nCH]->Fill (nTS,adc);
    }
    if ( val == 5 ) {
      TH2F_perCHs[30][nCH]->Fill (nTS,adc);
    }
    if ( val == 6 ) {
      TH2F_perCHs[31][nCH]->Fill (nTS,adc);
    }
    if ( val == 7 ) {
      TH2F_perCHs[32][nCH]->Fill (nTS,adc);
    }
    if ( val == 8 ) {
      TH2F_perCHs[33][nCH]->Fill (nTS,adc);
    }
    if ( val == 9 ) {
      TH2F_perCHs[34][nCH]->Fill (nTS,adc);
    }
    if ( val == 10 ) {
      TH2F_perCHs[35][nCH]->Fill (nTS,adc);
    }
    if ( val == 11 ) {
      TH2F_perCHs[36][nCH]->Fill (nTS,adc);
    }
    if ( val == 12 ) {
      TH2F_perCHs[37][nCH]->Fill (nTS,adc);
    }
    if ( val == 13 ) {
      TH2F_perCHs[38][nCH]->Fill (nTS,adc);
    }
    if ( val == 14 ) {
      TH2F_perCHs[39][nCH]->Fill (nTS,adc);
    }
    if ( val == 15 ) {
      TH2F_perCHs[40][nCH]->Fill (nTS,adc);
    }
    prevars.qsum_vb_PR += charge;
    prevars.qsum_qr_vb_pr += charge;
    if ( charge > prevars.qmax_qr_vb_pr ) {
      prevars.qmax_qr_vb_pr = charge;
    }
    prevars.qsum_qr2_vb_pr += charge;
    if ( charge > prevars.qmax_qr2_vb_pr ) {
      prevars.qmax_qr2_vb_pr = charge;
      prevars.ts_max_pr = nTS;
    }
    prevars.qsum_qr3_vb_ch += charge;
    if ( charge > prevars.qmax_qr3_vb_ch ) {
      prevars.qmax_qr3_vb_ch = charge;
      prevars.ts_max3_ch = nTS;
    }
    prevars.qsum_qr2_rin_pr += charge;
    if ( charge > prevars.qmax_qr2_rin_pr ) {
      prevars.qmax_qr2_rin_pr = charge;
      prevars.ts_max_rin_pr = nTS;
    }

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
      if (prevars.zero_event_CapIDrot_EV == 0) {
        if (_event_num > 2) {
          TH1F_perEVs[0]->Fill (capid - (digis[nTS-1].capid()+1)%4 );
        }
      }
    }
    if (nCH == 0) {
      prevars.ch0_cid_ev[nTS] = digis[nTS].capid();
    }
    if (prevars.zero_event_CapAllign_EV == 0) {
      if (_event_num > 2) {
        TH1F_perEVs[1]->Fill (capid - prevars.ch0_cid_ev[nTS]);
      }
    }
    if (prevars.zero_event_CIDvsTS_EV == 0) {
      if (_event_num > 2) {
        TH2F_perEVs[0]->Fill ( nTS, capid );
      }
    }
    if (nTS != 0) {
      if (prevars.zero_event_CapIDrot_CH == 0) {
        if (_event_num > 2) {
          TH1F_perCHs[0][nCH]->Fill (capid - (digis[nTS-1].capid()+1)%4 );
        }
      }
    }
    if (nCH == 0) {
      prevars.ch0_cid_ch[nTS] = digis[nTS].capid();
    }
    if (prevars.zero_event_CapAllign_CH == 0) {
      if (_event_num > 2) {
        TH1F_perCHs[1][nCH]->Fill (capid - prevars.ch0_cid_ch[nTS]);
      }
    }
    if (prevars.zero_event_CIDvsTS_CH == 0) {
      if (_event_num > 2) {
        TH2F_perCHs[0][nCH]->Fill ( nTS, capid );
      }
    }

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
      if (prevars.corrupt == 0) {
        TH1F_perEVs[0]->Fill (t_abs);
      }
    }
    TH2F_perEVs[0]->Fill ( nTS, le_tdc );
    if ((prevars.first_tdc_CH == 1) && (le_tdc < 50)) {
      prevars.first_tdc_CH = 0;
      float t_abs = (nTS*25.0) + (le_tdc*0.5);
      if (prevars.corrupt == 0) {
        TH1F_perCHs[0][nCH]->Fill (t_abs);
      }
    }
    TH2F_perCHs[0][nCH]->Fill ( nTS, le_tdc );

  }

// --- Suite 4: "PedScanner" ---

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
    if ( val == 38.0 ) {
      if (prevars.corrupt == 0) {
        TH1F_perEVs[0]->Fill ( adc );
      }
    }
    if ( val == 38.0 ) {
      if (prevars.corrupt == 0) {
        TH1F_perCHs[0][nCH]->Fill ( adc );
      }
    }
    if (prevars.corrupt == 0) {
      TH2F_perCHs[2][nCH]->Fill ( prevars.pdac2poff[(int)val] , adc);
    }
    if (prevars.corrupt == 0) {
      TH2F_perCHs[3][nCH]->Fill ( prevars.pdac2poff[(int)val] , charge);
    }

  }

// --- Suite 5: "PhaseScanner" ---

  if (suite_code == 5) {

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
    if ((prevars.first_tdc_scan_EV == 1) && (le_tdc < 50)) {
      prevars.first_tdc_scan_EV = 0;
      float t_abs = ((nTS-1)*25.0) + (le_tdc*0.5);
      if ( val < 50 ) {
         TH2F_perEVs[0]->Fill (val/2.0,t_abs);
      }
      if ( val > 63 ) {
         TH2F_perEVs[0]->Fill ((val-14.0)/2.0,t_abs);
      }
    }
    if ((prevars.first_tdc_scan_CH == 1) && (le_tdc < 50)) {
      prevars.first_tdc_scan_CH = 0;
      float t_abs = ((nTS-1)*25.0) + (le_tdc*0.5);
      if ( val < 50 ) {
         TH2F_perCHs[0][nCH]->Fill (val/2.0,t_abs);
      }
      if ( val > 63 ) {
         TH2F_perCHs[0][nCH]->Fill ((val-14.0)/2.0,t_abs);
      }
    }

  }

// --- Suite 6: "ICIScanner" ---

  if (suite_code == 6) {

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
      if (prevars.corrupt == 0) {
        TH1F_perEVs[0]->Fill (t_abs);
      }
    }
    prevars.qsum_qr_ev += charge;
    if ( charge > prevars.qmax_qr_ev ) {
      prevars.qmax_qr_ev = charge;
    }
    prevars.qsum_ici7_ev += charge;
    if (charge > prevars.qmax_ici7_ev ) {
      prevars.qmax_ici7_ev = charge;
    }
    if ( val == 7 ) {
      TH1F_perEVs[2]->Fill ( prevars.qmax_ici7_ev / prevars.qsum_ici7_ev );
    }
    prevars.qsum_ici_ev += charge;
    prevars.qsum_qr2_ev += charge;
    if ( charge > prevars.qmax_qr2_ev ) {
      prevars.qmax_qr2_ev = charge;
    }
    if ((prevars.first_tdc_CH == 1) && (le_tdc < 50)) {
      prevars.first_tdc_CH = 0;
      float t_abs = (nTS*25.0) + (le_tdc*0.5);
      if (prevars.corrupt == 0) {
        TH1F_perCHs[0][nCH]->Fill (t_abs);
      }
    }
    prevars.qsum_qr_ch += charge;
    if ( charge > prevars.qmax_qr_ch ) {
      prevars.qmax_qr_ch = charge;
    }
    prevars.qsum_ici7_ch += charge;
    if (charge > prevars.qmax_ici7_ch ) {
      prevars.qmax_ici7_ch = charge;
    }
    prevars.qsum_ici_ch += charge;
    prevars.qsum_qr2_ch += charge;
    if ( charge > prevars.qmax_qr2_ch ) {
      prevars.qmax_qr2_ch = charge;
    }
    if ( val == 0 ) {
      TH2F_perCHs[2][nCH]->Fill ( nTS, charge );
    }
    if ( val == 1 ) {
      TH2F_perCHs[3][nCH]->Fill ( nTS, charge );
    }
    if ( val == 2 ) {
      TH2F_perCHs[4][nCH]->Fill ( nTS, charge );
    }
    if ( val == 3 ) {
      TH2F_perCHs[5][nCH]->Fill ( nTS, charge );
    }
    if ( val == 4 ) {
      TH2F_perCHs[6][nCH]->Fill ( nTS, charge );
    }
    if ( val == 5 ) {
      TH2F_perCHs[7][nCH]->Fill ( nTS, charge );
    }
    if ( val == 6 ) {
      TH2F_perCHs[8][nCH]->Fill ( nTS, charge );
    }
    if ( val == 7 ) {
      TH2F_perCHs[9][nCH]->Fill ( nTS, charge );
    }

  }

// --- Suite 7: "LED_Vb_Scan" ---

  if (suite_code == 7) {

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
    prevars.qsum_vb_EV += charge;
    prevars.qsum_qr_vb_ev += charge;
    if ( charge > prevars.qmax_qr_vb_ev ) {
      prevars.qmax_qr_vb_ev = charge;
    }
    prevars.qsum_qr2_vb_ev += charge;
    if ( charge > prevars.qmax_qr2_vb_ev ) {
      prevars.qmax_qr2_vb_ev = charge;
      prevars.ts_max_ev = nTS;
    }
    prevars.qsum_vb_CH += charge;
    prevars.qsum_qr_vb_ch += charge;
    if ( charge > prevars.qmax_qr_vb_ch ) {
      prevars.qmax_qr_vb_ch = charge;
    }
    prevars.qsum_qr2_vb_ch += charge;
    if ( charge > prevars.qmax_qr2_vb_ch ) {
      prevars.qmax_qr2_vb_ch = charge;
      prevars.ts_max_ch = nTS;
    }
    TH2F_perCHs[3][nCH]->Fill ( nTS , le_tdc );
    if ( val == 2.5 ) {
      TH2F_perCHs[4][nCH]->Fill (nTS,charge);
    }
    prevars.qsum_vb_PR += charge;
    prevars.qsum_qr_vb_pr += charge;
    if ( charge > prevars.qmax_qr_vb_pr ) {
      prevars.qmax_qr_vb_pr = charge;
    }
    prevars.qsum_qr2_vb_pr += charge;
    if ( charge > prevars.qmax_qr2_vb_pr ) {
      prevars.qmax_qr2_vb_pr = charge;
      prevars.ts_max_pr = nTS;
    }
    prevars.qsum_qr3_vb_ch += charge;
    if ( charge > prevars.qmax_qr3_vb_ch ) {
      prevars.qmax_qr3_vb_ch = charge;
      prevars.ts_max3_ch = nTS;
    }

  }

// --- Suite 8: "RinSel_Scan" ---

  if (suite_code == 8) {

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
    prevars.qsum_qr2_rin_ch += charge;
    if ( charge > prevars.qmax_qr2_rin_ch ) {
      prevars.qmax_qr2_rin_ch = charge;
      prevars.ts_max_rin_ch = nTS;
    }
    if ( val == 0 ) {
      TH2F_perCHs[1][nCH]->Fill (nTS,adc);
    }
    if ( val == 1 ) {
      TH2F_perCHs[2][nCH]->Fill (nTS,adc);
    }
    if ( val == 2 ) {
      TH2F_perCHs[3][nCH]->Fill (nTS,adc);
    }
    if ( val == 3 ) {
      TH2F_perCHs[4][nCH]->Fill (nTS,adc);
    }
    if ( val == 4 ) {
      TH2F_perCHs[5][nCH]->Fill (nTS,adc);
    }
    if ( val == 5 ) {
      TH2F_perCHs[6][nCH]->Fill (nTS,adc);
    }
    if ( val == 6 ) {
      TH2F_perCHs[7][nCH]->Fill (nTS,adc);
    }
    if ( val == 7 ) {
      TH2F_perCHs[8][nCH]->Fill (nTS,adc);
    }
    if ( val == 8 ) {
      TH2F_perCHs[9][nCH]->Fill (nTS,adc);
    }
    if ( val == 9 ) {
      TH2F_perCHs[10][nCH]->Fill (nTS,adc);
    }
    if ( val == 10 ) {
      TH2F_perCHs[11][nCH]->Fill (nTS,adc);
    }
    if ( val == 11 ) {
      TH2F_perCHs[12][nCH]->Fill (nTS,adc);
    }
    if ( val == 12 ) {
      TH2F_perCHs[13][nCH]->Fill (nTS,adc);
    }
    if ( val == 13 ) {
      TH2F_perCHs[14][nCH]->Fill (nTS,adc);
    }
    if ( val == 14 ) {
      TH2F_perCHs[15][nCH]->Fill (nTS,adc);
    }
    if ( val == 15 ) {
      TH2F_perCHs[16][nCH]->Fill (nTS,adc);
    }
    prevars.qsum_qr2_rin_pr += charge;
    if ( charge > prevars.qmax_qr2_rin_pr ) {
      prevars.qmax_qr2_rin_pr = charge;
      prevars.ts_max_rin_pr = nTS;
    }

  }

  return prevars;

}

// ##############
// # POST_LOOPS #
// ##############

loop_vars post_loop(std::string parameter, float val, int suite_code, loop_vars prevars, QIE10DataFrame digis, int nCH, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

// --- Suite 0: "full" ---

  if (suite_code == 0) {

    TH1F_perEVs[3]->Fill ( prevars.qsum_ped_EV );
    TH1F_perEVs[4]->Fill ( prevars.qsum_ped_EV / float(digis.samples()) );
    TH1F_perEVs[7]->Fill ( prevars.qmax_qr_ev / prevars.qsum_qr_ev );
    for (int jj=0 ; jj < 4; jj++){
      TH2F_perEVs[2]->Fill ( jj , (prevars.qav_ped_CID[jj] / prevars.cid_count[jj]) );
    }
    if (val < 8 ) {
      TH2F_perEVs[9]->Fill ( prevars.ici_ev[(int)val] , prevars.qsum_ici_ev );
    }
    TH2F_perEVs[10]->Fill ( val , prevars.qmax_qr2_ev / prevars.qsum_qr2_ev );
    if ( prevars.corrupt == 0 ) {
      TH2F_perEVs[11]->Fill ( val , prevars.qsum_vb_EV );
    }
    TH2F_perEVs[12]->Fill ( val , prevars.qmax_qr_vb_ev / prevars.qsum_qr_vb_ev );
    float max2_ev = 0;
    if (prevars.ts_max_ev == 9) {
      max2_ev = adc2fC_QIE10_refl[ digis[prevars.ts_max_ev].adc() ] + 14.45;
    }
    else {
      max2_ev = adc2fC_QIE10_refl[ digis[prevars.ts_max_ev].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max_ev+1].adc() ] + 14.45;
    }
    TH2F_perEVs[13]->Fill ( val , (max2_ev) / prevars.qsum_qr2_vb_ev );
    TH1F_perCHs[3][nCH]->Fill ( prevars.qsum_ped_CH );
    TH1F_perCHs[6][nCH]->Fill ( prevars.qmax_qr_ch / prevars.qsum_qr_ch );
    if ( val == 7 ) {
      TH1F_perCHs[7][nCH]->Fill ( prevars.qmax_ici7_ch / prevars.qsum_ici7_ch );
    }
    if (val < 8 ) {
      TH2F_perCHs[9][nCH]->Fill ( prevars.ici_ch[(int)val] , prevars.qsum_ici_ch );
    }
    TH2F_perCHs[10][nCH]->Fill ( val , prevars.qmax_qr2_ch / prevars.qsum_qr2_ch );
    if ( prevars.corrupt == 0 ) {
      TH2F_perCHs[19][nCH]->Fill ( val , prevars.qsum_vb_CH );
    }
    TH2F_perCHs[20][nCH]->Fill ( val , prevars.qmax_qr_vb_ch / prevars.qsum_qr_vb_ch );
    float max2_ch = 0;
    if (prevars.ts_max_ch == 9) {
      max2_ch = adc2fC_QIE10_refl[ digis[prevars.ts_max_ch].adc() ] + 14.45;
    }
    else {
      max2_ch = adc2fC_QIE10_refl[ digis[prevars.ts_max_ch].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max_ch+1].adc() ] + 14.45;
    }
    TH2F_perCHs[21][nCH]->Fill ( val , (max2_ch) / prevars.qsum_qr2_vb_ch );
    float max2_rin_ch = 0;
    if (prevars.ts_max_rin_ch == 9) {
      max2_rin_ch = adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_ch].adc() ] + 14.45;
    }
    else {
      max2_rin_ch = adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_ch].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_ch+1].adc() ] + 14.45;
    }
    TH2F_perCHs[24][nCH]->Fill ( val , (max2_rin_ch) / prevars.qsum_qr2_rin_ch );
    if ( prevars.corrupt == 0 ) {
      TProfiles[0][nCH]->Fill ( val , prevars.qsum_vb_PR );
    }
    TProfiles[1][nCH]->Fill ( val , prevars.qmax_qr_vb_pr / prevars.qsum_qr_vb_pr );
    float max2_pr = 0;
    if (prevars.ts_max_pr == 9) {
      max2_pr = adc2fC_QIE10_refl[ digis[prevars.ts_max_pr].adc() ] + 14.45;
    }
    else {
      max2_pr = adc2fC_QIE10_refl[ digis[prevars.ts_max_pr].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max_pr+1].adc() ] + 14.45;
    }
    TProfiles[2][nCH]->Fill ( val , (max2_pr) / prevars.qsum_qr2_vb_pr );
    float max3_ch = 0;
    if ( (prevars.ts_max3_ch != 9) && (prevars.ts_max3_ch != 0) ) {
      max3_ch = adc2fC_QIE10_refl[ digis[prevars.ts_max3_ch].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max3_ch+1].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max3_ch-1].adc() ] + 14.45;
      TProfiles[3][nCH]->Fill ( val , (max3_ch) / prevars.qsum_qr3_vb_ch );
    }
    float max2_rin_pr = 0;
    if (prevars.ts_max_rin_pr == 9) {
      max2_rin_pr = adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_pr].adc() ] + 14.45;
    }
    else {
      max2_rin_pr = adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_pr].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_pr+1].adc() ] + 14.45;
    }
    TProfiles[4][nCH]->Fill ( val , (max2_rin_pr) / prevars.qsum_qr2_rin_pr );

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

// --- Suite 4: "PedScanner" ---

  if (suite_code == 4) {


  }

// --- Suite 5: "PhaseScanner" ---

  if (suite_code == 5) {


  }

// --- Suite 6: "ICIScanner" ---

  if (suite_code == 6) {

    TH1F_perEVs[1]->Fill ( prevars.qmax_qr_ev / prevars.qsum_qr_ev );
    if (val < 8 ) {
      TH2F_perEVs[0]->Fill ( prevars.ici_ev[(int)val] , prevars.qsum_ici_ev );
    }
    TH2F_perEVs[1]->Fill ( val , prevars.qmax_qr2_ev / prevars.qsum_qr2_ev );
    TH1F_perCHs[1][nCH]->Fill ( prevars.qmax_qr_ch / prevars.qsum_qr_ch );
    if ( val == 7 ) {
      TH1F_perCHs[2][nCH]->Fill ( prevars.qmax_ici7_ch / prevars.qsum_ici7_ch );
    }
    if (val < 8 ) {
      TH2F_perCHs[0][nCH]->Fill ( prevars.ici_ch[(int)val] , prevars.qsum_ici_ch );
    }
    TH2F_perCHs[1][nCH]->Fill ( val , prevars.qmax_qr2_ch / prevars.qsum_qr2_ch );

  }

// --- Suite 7: "LED_Vb_Scan" ---

  if (suite_code == 7) {

    if ( prevars.corrupt == 0 ) {
      TH2F_perEVs[0]->Fill ( val , prevars.qsum_vb_EV );
    }
    TH2F_perEVs[1]->Fill ( val , prevars.qmax_qr_vb_ev / prevars.qsum_qr_vb_ev );
    float max2_ev = 0;
    if (prevars.ts_max_ev == 9) {
      max2_ev = adc2fC_QIE10_refl[ digis[prevars.ts_max_ev].adc() ] + 14.45;
    }
    else {
      max2_ev = adc2fC_QIE10_refl[ digis[prevars.ts_max_ev].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max_ev+1].adc() ] + 14.45;
    }
    TH2F_perEVs[2]->Fill ( val , (max2_ev) / prevars.qsum_qr2_vb_ev );
    if ( prevars.corrupt == 0 ) {
      TH2F_perCHs[0][nCH]->Fill ( val , prevars.qsum_vb_CH );
    }
    TH2F_perCHs[1][nCH]->Fill ( val , prevars.qmax_qr_vb_ch / prevars.qsum_qr_vb_ch );
    float max2_ch = 0;
    if (prevars.ts_max_ch == 9) {
      max2_ch = adc2fC_QIE10_refl[ digis[prevars.ts_max_ch].adc() ] + 14.45;
    }
    else {
      max2_ch = adc2fC_QIE10_refl[ digis[prevars.ts_max_ch].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max_ch+1].adc() ] + 14.45;
    }
    TH2F_perCHs[2][nCH]->Fill ( val , (max2_ch) / prevars.qsum_qr2_vb_ch );
    if ( prevars.corrupt == 0 ) {
      TProfiles[0][nCH]->Fill ( val , prevars.qsum_vb_PR );
    }
    TProfiles[1][nCH]->Fill ( val , prevars.qmax_qr_vb_pr / prevars.qsum_qr_vb_pr );
    float max2_pr = 0;
    if (prevars.ts_max_pr == 9) {
      max2_pr = adc2fC_QIE10_refl[ digis[prevars.ts_max_pr].adc() ] + 14.45;
    }
    else {
      max2_pr = adc2fC_QIE10_refl[ digis[prevars.ts_max_pr].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max_pr+1].adc() ] + 14.45;
    }
    TProfiles[2][nCH]->Fill ( val , (max2_pr) / prevars.qsum_qr2_vb_pr );
    float max3_ch = 0;
    if ( (prevars.ts_max3_ch != 9) && (prevars.ts_max3_ch != 0) ) {
      max3_ch = adc2fC_QIE10_refl[ digis[prevars.ts_max3_ch].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max3_ch+1].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max3_ch-1].adc() ] + 14.45;
      TProfiles[3][nCH]->Fill ( val , (max3_ch) / prevars.qsum_qr3_vb_ch );
    }

  }

// --- Suite 8: "RinSel_Scan" ---

  if (suite_code == 8) {

    float max2_rin_ch = 0;
    if (prevars.ts_max_rin_ch == 9) {
      max2_rin_ch = adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_ch].adc() ] + 14.45;
    }
    else {
      max2_rin_ch = adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_ch].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_ch+1].adc() ] + 14.45;
    }
    TH2F_perCHs[0][nCH]->Fill ( val , (max2_rin_ch) / prevars.qsum_qr2_rin_ch );
    float max2_rin_pr = 0;
    if (prevars.ts_max_rin_pr == 9) {
      max2_rin_pr = adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_pr].adc() ] + 14.45;
    }
    else {
      max2_rin_pr = adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_pr].adc() ] + 14.45 + adc2fC_QIE10_refl[ digis[prevars.ts_max_rin_pr+1].adc() ] + 14.45;
    }
    TProfiles[0][nCH]->Fill ( val , (max2_rin_pr) / prevars.qsum_qr2_rin_pr );

  }

  return prevars;

}

// ####################
// # POST_EVENT_LOOPS #
// ####################

void post_event_loop(std::string parameter, float val, int suite_code, loop_vars prevars, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

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

// --- Suite 4: "PedScanner" ---

  if (suite_code == 4) {


  }

// --- Suite 5: "PhaseScanner" ---

  if (suite_code == 5) {


  }

// --- Suite 6: "ICIScanner" ---

  if (suite_code == 6) {


  }

// --- Suite 7: "LED_Vb_Scan" ---

  if (suite_code == 7) {


  }

// --- Suite 8: "RinSel_Scan" ---

  if (suite_code == 8) {


  }

}

