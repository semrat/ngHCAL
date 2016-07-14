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

struct globals {

  bool corrupt;

};

// ###################
// # PRE_EVENT_LOOPS #
// ###################

globals pre_event_loop(std::string parameter, float val, int suite_code, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

  globals global;

// --- Suite 0: "full" ---

  if (suite_code == 0) {

    global.corrupt = 0;

  }

// --- Suite 1: "ADC_Study" ---

  if (suite_code == 1) {

    global.corrupt = 0;

  }

// --- Suite 2: "TDC_Study" ---

  if (suite_code == 2) {

    global.corrupt = 0;

  }

  return global;

}

// #############
// # PRE_LOOPS #
// #############

globals pre_loop(std::string parameter, float val, int suite_code, globals global, QIE10DataFrame digis, int nCH, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

// --- Suite 0: "full" ---

  if (suite_code == 0) {

    global.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if ((digis[iTS].le_tdc() == 0) && (digis[iTS].te_tdc())) {
        global.corrupt = 1;
      }
    }

  }

// --- Suite 1: "ADC_Study" ---

  if (suite_code == 1) {

    global.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if ((digis[iTS].le_tdc() == 0) && (digis[iTS].te_tdc())) {
        global.corrupt = 1;
      }
    }

  }

// --- Suite 2: "TDC_Study" ---

  if (suite_code == 2) {

    global.corrupt = 0;
    for (int iTS=0 ; iTS<10 ; iTS++) {
      if ((digis[iTS].le_tdc() == 0) && (digis[iTS].te_tdc())) {
        global.corrupt = 1;
      }
    }

  }

  return global;

}

// #########
// # LOOPS #
// #########

globals loop(std::string parameter, float val, int suite_code, globals global, QIE10DataFrame digis, int nTS, int nCH, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

// --- Suite 0: "full" ---

  if (suite_code == 0) {

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
    float charge = adc2fC_QIE10_refl[ adc ] + 14.45;
    charge = charge;
    if (global.corrupt == 0) {
      TH1F_perEVs[0]->Fill ( adc );
    }
    if (le_tdc < 50) {
      if (global.corrupt == 0) {
        TH1F_perEVs[1]->Fill ( le_tdc );
      }
    }
    if (global.corrupt == 0) {
      TH2F_perEVs[0]->Fill ( nTS , adc );
    }
    if (global.corrupt == 0) {
      TH2F_perEVs[1]->Fill ( nTS , le_tdc );
    }
    if (global.corrupt == 0) {
      TH1F_perCHs[0][nCH]->Fill ( adc );
    }
    if (le_tdc < 50) {
      if (global.corrupt == 0) {
        TH1F_perCHs[1][nCH]->Fill ( le_tdc );
      }
    }
    if (global.corrupt == 0) {
      TH2F_perCHs[0][nCH]->Fill ( nTS , adc );
    }
    if (global.corrupt == 0) {
      TH2F_perCHs[1][nCH]->Fill ( nTS , le_tdc );
    }
    if (global.corrupt == 0) {
      TProfiles[0][nCH]->Fill ( nTS , adc );
    }

  }

// --- Suite 1: "ADC_Study" ---

  if (suite_code == 1) {

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
    float charge = adc2fC_QIE10_refl[ adc ] + 14.45;
    charge = charge;
    if (global.corrupt == 0) {
      TH1F_perEVs[0]->Fill ( adc );
    }
    if (global.corrupt == 0) {
      TH2F_perEVs[0]->Fill ( nTS , adc );
    }
    if (global.corrupt == 0) {
      TH1F_perCHs[0][nCH]->Fill ( adc );
    }
    if (global.corrupt == 0) {
      TH2F_perCHs[0][nCH]->Fill ( nTS , adc );
    }
    if (global.corrupt == 0) {
      TProfiles[0][nCH]->Fill ( nTS , adc );
    }

  }

// --- Suite 2: "TDC_Study" ---

  if (suite_code == 2) {

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
    float charge = adc2fC_QIE10_refl[ adc ] + 14.45;
    charge = charge;
    if (le_tdc < 50) {
      if (global.corrupt == 0) {
        TH1F_perEVs[0]->Fill ( le_tdc );
      }
    }
    if (global.corrupt == 0) {
      TH2F_perEVs[0]->Fill ( nTS , le_tdc );
    }
    if (le_tdc < 50) {
      if (global.corrupt == 0) {
        TH1F_perCHs[0][nCH]->Fill ( le_tdc );
      }
    }
    if (global.corrupt == 0) {
      TH2F_perCHs[0][nCH]->Fill ( nTS , le_tdc );
    }

  }

  return global;

}

// ##############
// # POST_LOOPS #
// ##############

globals post_loop(std::string parameter, float val, int suite_code, globals global, QIE10DataFrame digis, int nCH, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

// --- Suite 0: "full" ---

  if (suite_code == 0) {


  }

// --- Suite 1: "ADC_Study" ---

  if (suite_code == 1) {


  }

// --- Suite 2: "TDC_Study" ---

  if (suite_code == 2) {


  }

  return global;

}

// ####################
// # POST_EVENT_LOOPS #
// ####################

void post_event_loop(std::string parameter, float val, int suite_code, globals global, int _event_num, TQIE10Info &_qie10Info, TTree** _trees, vector<TH1F*> &TH1F_perEVs, vector<vector<TH1F*> > &TH1F_perCHs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<TH2F*> &TH2F_perEVs, vector<vector<TH2F*> > &TH2F_perCHs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<vector<TH2F*> > &TProfiles, ofstream *loggers) {

// --- Suite 0: "full" ---

  if (suite_code == 0) {


  }

// --- Suite 1: "ADC_Study" ---

  if (suite_code == 1) {


  }

// --- Suite 2: "TDC_Study" ---

  if (suite_code == 2) {


  }

}

