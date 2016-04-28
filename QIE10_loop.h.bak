#include <vector>
  
#include "TH1D.h"
#include "TH2D.h"

using namespace std;


struct loop_vars {

  int adcped = 3;
  float qped = adc2fC_QIE10_refl[ adcped ];
  float qsum = 0;
  int main = 1;
  
};


loop_vars pre_loop() {

  loop_vars output;

  output.adcped = 3;
  output.qped = adc2fC_QIE10_refl[ output.adcped ];
  output.qsum = 0;
  output.main = 1;

  return output;
}


loop_vars loop(int nTS, int nCH, QIE10DataFrame digis, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs, vector<string> &TH1F_names, vector<vector<TH2F*> > &TH2Fs, vector<string> &TH2F_names) {

  int tTS = digis.samples();

  int adc = digis[nTS].adc();
  int tdc = digis[nTS].le_tdc();
  int te_tdc = digis[nTS].te_tdc();
  //int capid = digis[nTS].capid();
  //int soi = digis[nTS].soi();
  float charge = adc2fC_QIE10_refl[ adc ];

  // log  output
  //cout << "TS " << std::setfill(' ') << std::setw(2) << i << ": " << capid << ", ";
  
  prevars.qsum += ( charge - prevars.qped );

  if ( (0 < te_tdc) && (te_tdc < 16) ) {
    if (nTS != tTS-1) {
      for (int k=nTS; k<tTS; k++) {
        if ( (digis[k].le_tdc() != 63) && (digis[k].le_tdc() != 62) ) {
          if (prevars.main ==1) {
            float wid = ((25.0/16.0)*te_tdc) + ((2 + nTS - k)*25) - ((25.0/64.0)*digis[k].le_tdc());
            TH1Fs[1][nCH]->Fill(wid);
            prevars.main = 0;
          }
        }
      }
    }
  }

  TH2Fs[0][nCH]->Fill( nTS, adc);
  TH2Fs[1][nCH]->Fill( nTS , tdc );
  TH2Fs[2][nCH]->Fill( nTS , te_tdc );
  
  return prevars;

}


void post_loop(int nCH, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs, vector<string> &TH1F_names, vector<vector<TH2F*> > &TH2Fs, vector<string> &TH2F_names) {

  // log output
  //cout << endl;

  TH1Fs[0][nCH]->Fill( prevars.qsum );
  
}
