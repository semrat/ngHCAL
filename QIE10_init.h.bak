#include <vector>

#include "TH1D.h"
#include "TH2D.h"

using namespace std;

void init(vector<vector<TH1F*> > &TH1Fs, int &num_TH1Fs, vector<string> &TH1F_names, vector<int> &TH1F_nbinsx, vector<float> &TH1F_lowx, vector<float> &TH1F_highx, vector<string> &TH1F_axisx, vector<vector<TH2F*> > &TH2Fs, int &num_TH2Fs, vector<string> &TH2F_names, vector<int> &TH2F_nbinsx, vector<float> &TH2F_lowx, vector<float> &TH2F_highx, vector<string> &TH2F_axisx, vector<int> &TH2F_nbinsy, vector<float> &TH2F_lowy, vector<float> &TH2F_highy, vector<string> &TH2F_axisy){

  num_TH1Fs = 2;
  char temp_TH1F_names[num_TH1Fs][100] = {"Qsum", "Width"};
  int temp_TH1F_nbinsx[num_TH1Fs] = {64, 25};
  float temp_TH1F_lowx[num_TH1Fs] = {0, 0};
  float temp_TH1F_highx[num_TH1Fs] = {15000, 75};
  char temp_TH1F_axisx[num_TH1Fs][100] = {"Integrated Charge (fC)", "Width (ns)"};

  for (int i=0 ; i < num_TH1Fs ; i++) {
    vector<TH1F*> temp_TH1F_vector; 
    TH1Fs.push_back(temp_TH1F_vector);
    TH1F_names.push_back(temp_TH1F_names[i]);
    TH1F_nbinsx.push_back(temp_TH1F_nbinsx[i]);
    TH1F_lowx.push_back(temp_TH1F_lowx[i]);
    TH1F_highx.push_back(temp_TH1F_highx[i]);
    TH1F_axisx.push_back(temp_TH1F_axisx[i]);
  }

  num_TH2Fs = 3;
  char temp_TH2F_names[num_TH2Fs][100] = {"ADCpulse", "TDCpulse", "teTDCpulse"};
  int temp_TH2F_nbinsx[num_TH2Fs] = {10, 10, 10};
  float temp_TH2F_lowx[num_TH2Fs] = {-0.5, -0.5, -0.5};
  float temp_TH2F_highx[num_TH2Fs] = {9.5, 9.5, 9.5};
  char temp_TH2F_axisx[num_TH2Fs][100] = {"TS" , "TS", "TS"}; 
  int temp_TH2F_nbinsy[num_TH2Fs] = {256, 64, 32};
  float temp_TH2F_lowy[num_TH2Fs] = {-0.5, -0.5, -0.5};
  float temp_TH2F_highy[num_TH2Fs] = {255.5, 63.5, 31.5};  
  char temp_TH2F_axisy[num_TH2Fs][100] = {"ADC counts" , "leTDC value (0.5 ns)", "teTDC value (16/25 ns)"}; 

  for (int i=0 ; i < num_TH2Fs ; i++) {
    vector<TH2F*> temp_TH2F_vector;
    TH2Fs.push_back(temp_TH2F_vector);
    TH2F_names.push_back(temp_TH2F_names[i]);
    TH2F_nbinsx.push_back(temp_TH2F_nbinsx[i]);
    TH2F_lowx.push_back(temp_TH2F_lowx[i]);
    TH2F_highx.push_back(temp_TH2F_highx[i]);
    TH2F_axisx.push_back(temp_TH2F_axisx[i]);
    TH2F_nbinsy.push_back(temp_TH2F_nbinsy[i]);
    TH2F_lowy.push_back(temp_TH2F_lowy[i]);
    TH2F_highy.push_back(temp_TH2F_highy[i]);
    TH2F_axisy.push_back(temp_TH2F_axisy[i]);
  }

}
