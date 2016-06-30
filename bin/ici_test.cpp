#include <iostream>
#include <sstream>
#include <array>
#include <string>
#include <fstream>

#include "TFile.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TH2F.h"
#include "TStyle.h"
#include "TPad.h"
#include "TF1.h"

#include "../src/mask.h"
#include "../src/draw_map.h"

Double_t linear_fit(Double_t *x,Double_t *par) {
  Double_t out_val;
  out_val = (x[0]*par[0]) + par[1];
  return out_val;
}

using namespace std;

void ici_test(Int_t run_num) {

  float ici_slope_low = 1.0;
  float ici_slope_high = 1.1;
  float ici_offset_low = -0.0;
  float ici_offset_high = 200.0;
  float ici_rms_high = 10.0;
  float ici_ratio_low = 0.98;

  float ici_slope;
  float ici_offset;

  char hist0_name[512];
  char hist1_name[512];
  char hist2_name[512];
  char hist3_name[512];
  char file0_name[512];
  char dir_name[512];
  char figure_name[512];

  sprintf(dir_name,"mkdir ../img/%i",run_num);
  system(dir_name);
  sprintf(dir_name,"mkdir ../img/%i/ici_test",run_num);
  system(dir_name);

  TH1F *h0_temp = new TH1F();
  TH1F *h1_temp = new TH1F();
  TH1F *h2_temp = new TH1F();
  TH1F *h3_temp = new TH1F();
  TFile *_file0 =  new TFile();
  
  TCanvas *c1 = new TCanvas("c1","c1",100,100,1024,768);
  
  sprintf(file0_name,"../dat/QIE10testing_%i_6.root",run_num);
  _file0 = TFile::Open(file0_name);

  TF1 *fit_ici = new TF1();

  bool*** lv2_err_map_slope = create_error_map();
  bool*** lv2_err_map_offset = create_error_map();
  bool*** lv2_err_map_rms = create_error_map();
  bool*** lv2_err_map_ratio = create_error_map();
  bool*** lv2_err_map_gen = create_error_map();
  for (Int_t h = 0; h < HF_num; h++) {
    if (lv0_mask[h] == 1) {
      for (Int_t s = 0 ; s < SL_num; s++) {
	if (lv1_mask[h][s] == 1) {
	  for (Int_t q = 0; q < QI_num; q++) {
	    if (lv2_mask[h][s][q] == 1) {
	      sprintf(hist0_name,"%s/%s_HF%i_Slot%i_QIE%i","ici_scan_CH","ici_scan_CH",h+1,s+1,q+1);
	      sprintf(hist1_name,"%s/%s_HF%i_Slot%i_QIE%i","T_abs_CH","T_abs_CH",h+1,s+1,q+1);
	      sprintf(hist2_name,"%s/%s_HF%i_Slot%i_QIE%i","ICI7_CH","ICI7_CH",h+1,s+1,q+1);
	      sprintf(hist3_name,"%s/%s_HF%i_Slot%i_QIE%i","pulse_ICI7_CH","pulse_ICI7_CH",h+1,s+1,q+1);
	      h0_temp = (TH1F*)_file0->Get(hist0_name);
	      h1_temp = (TH1F*)_file0->Get(hist1_name);
	      h2_temp = (TH1F*)_file0->Get(hist2_name);
	      h3_temp = (TH1F*)_file0->Get(hist3_name);
	      fit_ici = new TF1("fit_ici",linear_fit,0,10000,2);
	      fit_ici->SetParNames("slope","offset");
	      h0_temp->Fit("fit_ici","Q");
	      ici_slope = fit_ici->GetParameter(0);
	      ici_offset = fit_ici->GetParameter(1);	      
	      if ((ici_slope < ici_slope_low) || (ici_slope > ici_slope_high)) {
		lv2_err_map_slope[h][s][q] = 0;
		lv2_err_map_gen[h][s][q] = 0;
	      }	
	      if ((ici_offset < ici_offset_low) || (ici_offset > ici_offset_high)) {
		lv2_err_map_offset[h][s][q] = 0;
		lv2_err_map_gen[h][s][q] = 0;
	      }	
	      if (h1_temp->GetRMS() > ici_rms_high) {
		lv2_err_map_rms[h][s][q] = 0;
		lv2_err_map_gen[h][s][q] = 0;
	      }	
	      if (h2_temp->GetMean() < ici_ratio_low) {
		h3_temp->Draw();
		sprintf(figure_name,"../img/%i/ici_test/pulse_ICI7_HF%i_Slot%i_QIE%i.png",run_num,h+1,s+1,q+1);
		c1->SaveAs(figure_name);
		cout << "HF: " << h+1 << ", SL: " << s+1 << ", QI: " << q+1 << endl;
		cout << "Slope: " << ici_slope << ", Offset: " << ici_offset << ", RMS: " << h1_temp->GetRMS() << ", Ratio: " << h2_temp->GetMean() << endl;
		lv2_err_map_ratio[h][s][q] = 0;
		lv2_err_map_gen[h][s][q] = 0;
	      }	
	      h0_temp->Delete();
	      h1_temp->Delete();
	      h2_temp->Delete();
	      fit_ici->Delete();
	      c1->Clear();
	    }
	  }
	}
      }
    }
  }
  draw_map(lv2_err_map_slope, run_num, "ici_test", "ICIscanSlope");
  draw_map(lv2_err_map_offset, run_num, "ici_test", "ICIscanOffset");
  draw_map(lv2_err_map_rms, run_num, "ici_test", "ICItimingRMS");
  draw_map(lv2_err_map_ratio, run_num, "ici_test", "ICIratio");
  draw_map(lv2_err_map_gen, run_num, "ici_test", "ICIall");

} // close function
