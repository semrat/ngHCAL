// #############################################################
// #############################################################
// ###                                                       ###
// ###                      QIE10_loop.h                     ###
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

using namespace std;

// ########################
// # LOOP_VARS STRUCTURES #
// ########################

// --- Suite 0: "full" ---

struct loop_vars {

  int adcped = 3;
  float qped = adc2fC_QIE10_refl[ adcped ];
  float qsum;
  float qmax;
  int main;

};

// #############
// # PRE_LOOPS #
// #############

// --- Suite 0: "full" ---

loop_vars pre_loop() {

  loop_vars prevars;

  prevars.qsum = 0;
  prevars.qmax = 0;
  prevars.main = 1;

  return prevars;

};

// #########
// # LOOPS #
// #########

// --- Suite 0: "full" ---

loop_vars loop(int nTS, int nCH, QIE10DataFrame digis, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs, vector<vector<vector<TH1F*> > > &TH1F_PerTSs, vector<string> &TH1F_names, vector<vector<TH2F*> > &TH2Fs, vector<vector<vector<TH2F*> > > &TH2F_PerTSs, vector<string> &TH2F_names) {

  int tTS = digis.samples();
  int adc = digis[nTS].adc();
  int le_tdc = digis[nTS].le_tdc();
  int te_tdc = digis[nTS].te_tdc();
  float charge = adc2fC_QIE10_refl[ adc ];
  prevars.qsum += (charge - prevars.qped);
  if (charge > prevars.qmax){
     prevars.qmax = charge;
  }
  if ( (0 < te_tdc) && (te_tdc < 16) ) {
    if (nTS != tTS-1) {
      for (int k=nTS; k<tTS; k++) {
        if ( (digis[k].le_tdc() != 63) && (digis[k].le_tdc() != 62) ) {
          if (prevars.main ==1) {
            float wid = ((25.0/16.0)*te_tdc) + ((2 + nTS - k)*25) - ((25.0/64.0)*digis[k].le_tdc());
            TH1Fs[2][nCH]->Fill ( wid );
            prevars.main = 0;
          }
        }
      }
    }
  }
  TH2Fs[0][nCH]->Fill ( nTS, adc );
  TH2Fs[1][nCH]->Fill ( nTS, le_tdc );
  TH2Fs[2][nCH]->Fill ( nTS, te_tdc );
  TH2Fs[3][nCH]->Fill ( nTS, charge );
  TH1F_PerTSs[0][nTS][nCH]->Fill ( adc );
  TH2F_PerTSs[0][nTS][nCH]->Fill ( le_tdc , adc );

  return prevars;

};

// ##############
// # POST_LOOPS #
// ##############

// --- Suite 0: "full" ---
void post_loop(int nCH, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs, vector<vector<vector<TH1F*> > > &TH1F_PerTS, vector<string> &TH1F_names, vector<vector<TH2F*> > &TH2Fs, vector<vector<vector<TH2F*> > > &TH2F_PerTS, vector<string> &TH2F_names) {


  TH1Fs[0][nCH]->Fill ( prevars.qsum );
  TH1Fs[1][nCH]->Fill ( prevars.qmax );

};

