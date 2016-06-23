#include <iostream>
#include <sstream>
#include <array>
#include <string>
#include <fstream>

#include "TFile.h"
#include "TCanvas.h"
#include "TH1F.h"
#include "TStyle.h"
#include "TPad.h"
#include "TF1.h"

#include "../src/mask.h"
#include "../src/draw_map.h"

using namespace std;

void ped_test(Int_t run0_num, Int_t run1_num) {

  float ped_mean_low = 2.0;
  float ped_mean_high = 6.0;
  float ped_rms_high = 1.5;
  float ped_shift_low = 6.5;

  char hist_name[512];
  char root_file0_name[512];
  char root_file1_name[512];
  char dir_name[512];

  sprintf(dir_name,"mkdir ../img/%i",run0_num);
  system(dir_name);
  sprintf(dir_name,"mkdir ../img/%i/ped_test",run0_num);
  system(dir_name);

  TH1F *h0_temp = new TH1F();
  TH1F *h1_temp = new TH1F();
  TFile *_file0 =  new TFile();
  TFile *_file1 =  new TFile();
  
  sprintf(root_file0_name,"../dat/QIE10testing_%i_0.root",run0_num);
  sprintf(root_file1_name,"../dat/QIE10testing_%i_0.root",run1_num);
  _file0 = TFile::Open(root_file0_name);
  _file1 = TFile::Open(root_file1_name);

  bool*** lv2_err_map_mean = create_error_map();
  bool*** lv2_err_map_rms = create_error_map();
  bool*** lv2_err_map_shift = create_error_map();
  bool*** lv2_err_map_gen = create_error_map();
  for (Int_t h = 0; h < HF_num; h++) {
    if (lv0_mask[h] == 1) {
      for (Int_t s = 0 ; s < SL_num; s++) {
	if (lv1_mask[h][s] == 1) {
	  for (Int_t q = 0; q < QI_num; q++) {
	    if (lv2_mask[h][s][q] == 1) {
	      //sprintf(hist_name,"%s/%s_HF%i_Slot%i_QIE%i","ADC_ped_CH","ADC_ped_CH",lv0_map[h],lv1_map[h][s],lv2_map[h][s][q]);
	      sprintf(hist_name,"%s/%s_HF%i_Slot%i_QIE%i","ADC_ped_CH","ADC_ped_CH",h+1,s+1,q+1);
	      h0_temp = (TH1F*)_file0->Get(hist_name);
	      h1_temp = (TH1F*)_file1->Get(hist_name);
	      if ((h0_temp->GetMean() < ped_mean_low) || (h0_temp->GetMean() > ped_mean_high)) {
		lv2_err_map_mean[h][s][q] = 0;
		lv2_err_map_gen[h][s][q] = 0;
	      }	
	      if (h0_temp->GetRMS() > ped_rms_high) {
		lv2_err_map_rms[h][s][q] = 0;
		lv2_err_map_gen[h][s][q] = 0;
	      }	
	      if ((h1_temp->GetMean()-h0_temp->GetMean()) < ped_shift_low) {
		lv2_err_map_shift[h][s][q] = 0;
		lv2_err_map_gen[h][s][q] = 0;
	      }
	      h0_temp->Delete();
	      h1_temp->Delete();
	    }
	  }
	}
      }
    }
  }
  draw_map(lv2_err_map_mean, run0_num, "ped_test", "PedestalMean");
  draw_map(lv2_err_map_rms, run0_num, "ped_test", "PedestalRMS");
  draw_map(lv2_err_map_shift, run0_num, "ped_test", "PedestalShift");
  draw_map(lv2_err_map_gen, run0_num, "ped_test", "PedestalAll");

} // close function
