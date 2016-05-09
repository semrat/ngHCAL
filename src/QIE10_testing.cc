// -*- C++ -*-
//
// Package:    HFanalyzer
// Class:      HFanalyzer
// 
//class HFanalyzer HFanalyzer.cc UserCode/HFanalyzer/src/HFanalyzer.cc
/*
   Description: [one line class summary]

   Implementation:
   [Notes on implementation]
*/
//

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDAnalyzer.h"
#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/Framework/interface/ESHandle.h"

#include "FWCore/ParameterSet/interface/ParameterSet.h"
#include "FWCore/ServiceRegistry/interface/Service.h"

#include "EventFilter/HcalRawToDigi/interface/HcalHTRData.h"
#include "EventFilter/HcalRawToDigi/interface/HcalDCCHeader.h"
#include "EventFilter/HcalRawToDigi/interface/HcalUnpacker.h"
#include "DataFormats/HcalDetId/interface/HcalOtherDetId.h"
#include "DataFormats/HcalDigi/interface/HcalQIESample.h"
#include "DataFormats/HcalDigi/interface/QIE10DataFrame.h"
#include "DataFormats/HcalDetId/interface/HcalSubdetector.h"
#include "DataFormats/HcalDetId/interface/HcalCalibDetId.h"

#include "DataFormats/Common/interface/Handle.h"
#include "DataFormats/FEDRawData/interface/FEDRawDataCollection.h"
#include "DataFormats/FEDRawData/interface/FEDHeader.h"
#include "DataFormats/FEDRawData/interface/FEDTrailer.h"
#include "DataFormats/FEDRawData/interface/FEDNumbering.h"
#include "DataFormats/FEDRawData/interface/FEDRawData.h"

#include "CommonTools/UtilAlgos/interface/TFileService.h"
#include "DataFormats/HcalDigi/interface/HcalDigiCollections.h"
#include "CalibFormats/HcalObjects/interface/HcalDbService.h"
#include "CalibFormats/HcalObjects/interface/HcalDbRecord.h"
#include "CalibFormats/HcalObjects/interface/HcalCalibrations.h"
#include "CalibFormats/HcalObjects/interface/HcalCoderDb.h"

#include "HFcommissioning/Analysis/interface/ADC_Conversion.h"

#include "TH1D.h"
#include "TH2D.h"
#include "TGraph.h"
#include "TCanvas.h"
#include "TTree.h"
#include "TProfile.h"
#include "TFile.h"
#include "TSystem.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <vector>

#include "adc2q.h"
#include "QIE10_init.h"
#include "QIE10_loop.h"

using namespace std;


class HF_refl_analyzer : public edm::EDAnalyzer {

public:
  explicit HF_refl_analyzer(const edm::ParameterSet&);
  ~HF_refl_analyzer();

  static void fillDescriptions(edm::ConfigurationDescriptions& descriptions);

private:
  virtual void beginJob() ;
  virtual void analyze(const edm::Event&, const edm::EventSetup&);
  void getData(const edm::Event&, const edm::EventSetup&);
  virtual void endJob() ;

  TFile *_file;

  int _event_num;

  string _outFileName;
  int _verbosity;

  char histoName[100];
  char dirName[100];

  vector<vector<TH1F*> > TH1Fs;
  int _num_TH1Fs;
  vector<string> TH1F_names;
  vector<int> TH1F_nbinsx;
  vector<float> TH1F_lowx;
  vector<float> TH1F_highx;
  vector<string> TH1F_axisx;

  vector<vector<vector<TH1F*> > > TH1F_PerTSs;
  int _num_TH1F_PerTSs;
  vector<string> TH1F_PerTS_names;
  vector<int> TH1F_PerTS_nbinsx;
  vector<float> TH1F_PerTS_lowx;
  vector<float> TH1F_PerTS_highx;
  vector<string> TH1F_PerTS_axisx;

  vector<vector<TH2F*> > TH2Fs;
  int _num_TH2Fs;
  vector<string> TH2F_names;
  vector<int> TH2F_nbinsx;
  vector<float> TH2F_lowx;
  vector<float> TH2F_highx;
  vector<string> TH2F_axisx;
  vector<int> TH2F_nbinsy;
  vector<float> TH2F_lowy;
  vector<float> TH2F_highy;
  vector<string> TH2F_axisy;

  vector<vector<vector<TH2F*> > > TH2F_PerTSs;
  int _num_TH2F_PerTSs;
  vector<string> TH2F_PerTS_names;
  vector<int> TH2F_PerTS_nbinsx;
  vector<float> TH2F_PerTS_lowx;
  vector<float> TH2F_PerTS_highx;
  vector<string> TH2F_PerTS_axisx;
  vector<int> TH2F_PerTS_nbinsy;
  vector<float> TH2F_PerTS_lowy;
  vector<float> TH2F_PerTS_highy;
  vector<string> TH2F_PerTS_axisy;

  virtual void beginRun(edm::Run const&, edm::EventSetup const&);
  virtual void endRun(edm::Run const&, edm::EventSetup const&);
  virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
  virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

  edm::EDGetTokenT<HcalDataFrameContainer<QIE10DataFrame> > tok_QIE10DigiCollection_;
  edm::EDGetTokenT<HFDigiCollection> hf_token;
  edm::Handle<QIE10DigiCollection> qie10DigiCollection;
  
};


HF_refl_analyzer::HF_refl_analyzer(const edm::ParameterSet& iConfig) :
  _outFileName(iConfig.getUntrackedParameter<string>("OutFileName")),
  _verbosity(iConfig.getUntrackedParameter<int>("Verbosity"))
{

  tok_QIE10DigiCollection_ = consumes<HcalDataFrameContainer<QIE10DataFrame> >(edm::InputTag("hcalDigis"));
  hf_token = consumes<HFDigiCollection>(edm::InputTag("hcalDigis"));

  _file = new TFile(_outFileName.c_str(), "recreate");

  init(TH1Fs,_num_TH1Fs,TH1F_names,TH1F_nbinsx,TH1F_lowx,TH1F_highx,TH1F_axisx,TH1F_PerTSs,_num_TH1F_PerTSs,TH1F_PerTS_names,TH1F_PerTS_nbinsx,TH1F_PerTS_lowx,TH1F_PerTS_highx,TH1F_PerTS_axisx,TH2Fs,_num_TH2Fs,TH2F_names,TH2F_nbinsx,TH2F_lowx,TH2F_highx,TH2F_axisx,TH2F_nbinsy,TH2F_lowy,TH2F_highy,TH2F_axisy,TH2F_PerTSs,_num_TH2F_PerTSs,TH2F_PerTS_names,TH2F_PerTS_nbinsx,TH2F_PerTS_lowx,TH2F_PerTS_highx,TH2F_PerTS_axisx,TH2F_PerTS_nbinsy,TH2F_PerTS_lowy,TH2F_PerTS_highy,TH2F_PerTS_axisy);

  _event_num = 0;

}

HF_refl_analyzer::~HF_refl_analyzer()
{
  
  _file->cd();

  for (int i = 0 ; i < _num_TH1Fs ; i++) {
    _file->mkdir(TH1F_names[i].c_str());
    _file->cd(TH1F_names[i].c_str());
    for( unsigned int j = 0 ; j < TH1Fs[i].size() ; j++ ){
      TH1Fs[i][j]->Write();
    }
  }

  for (int i = 0 ; i < _num_TH1F_PerTSs ; i++) {
    for (unsigned int j = 0 ; j < TH1F_PerTSs[i].size() ; j++) {
      sprintf(dirName,"%s_perTS/%s_TS%i",TH1F_PerTS_names[i].c_str(),TH1F_PerTS_names[i].c_str(),j);
      _file->mkdir(dirName);
      _file->cd(dirName);
      for( unsigned int k = 0 ; k < TH1F_PerTSs[i][j].size() ; k++ ){
	TH1F_PerTSs[i][j][k]->Write();
      }
    }
  }

  for (int i = 0 ; i < _num_TH2Fs ; i++) {
    _file->mkdir(TH2F_names[i].c_str());
    _file->cd(TH2F_names[i].c_str());
    for( unsigned int j = 0 ; j < TH2Fs[i].size() ; j++ ){    
      TH2Fs[i][j]->Write();
    }
  }

  for (int i = 0 ; i < _num_TH2F_PerTSs ; i++) {
    for (unsigned int j = 0 ; j < TH2F_PerTSs[i].size() ; j++) {
      sprintf(dirName,"%s_PerTS/%s_TS%i",TH2F_PerTS_names[i].c_str(),TH2F_PerTS_names[i].c_str(),j);
      _file->mkdir(dirName);
      _file->cd(dirName);
      for( unsigned int k = 0 ; k < TH2F_PerTSs[i][j].size() ; k++ ){
	TH2F_PerTSs[i][j][k]->Write();
      }
    }
  }

  _file->Write();
  _file->Close();

}
	
void HF_refl_analyzer::getData(const edm::Event &iEvent, const edm::EventSetup &iSetup)
{
  using namespace edm;

  //  Extracting All the Collections containing useful Info
  iEvent.getByToken(tok_QIE10DigiCollection_,qie10DigiCollection);
  const QIE10DigiCollection& qie10dc=*(qie10DigiCollection);

  if (_verbosity>0){
      cout << "### Before Loop: " << endl;
      cout << "### QIE10 Digis=" << qie10dc.size() << endl;
  }

  for (unsigned int j=0; j < qie10dc.size(); j++){

    QIE10DataFrame qie10df = static_cast<QIE10DataFrame>(qie10dc[j]);

    // Extract info on detector location
    DetId detid = qie10df.detid();
    HcalDetId hcaldetid = HcalDetId(detid);
    int ieta = hcaldetid.ieta();
    int iphi = hcaldetid.iphi();
    int depth = hcaldetid.depth();

    int nTS = qie10df.samples();
    
    if( TH1Fs[0].size() <= j ){

      for (int i = 0 ; i < _num_TH1Fs ; i++) {
	sprintf(histoName,"%s_iEta%i_iPhi%i_Depth%i",TH1F_names.at(i).c_str(),ieta,iphi,(depth-1)/2+1);
	TH1Fs[i].push_back(new TH1F(histoName,histoName,TH1F_nbinsx[i],TH1F_lowx[i],TH1F_highx[i]));
	TH1Fs[i].back()->GetXaxis()->SetTitle(TH1F_axisx.at(i).c_str());
      }

      for (int i = 0 ; i < _num_TH1F_PerTSs ; i++) {
	for(int k = 0; k < nTS ; k++) {
	  if (j == 0) { 
	    vector<TH1F*> temp_TH1F_vector;  
	    TH1F_PerTSs[i].push_back(temp_TH1F_vector);
	  }  
	  sprintf(histoName,"%s_TS%i_iEta%i_iPhi%i_Depth%i",TH1F_PerTS_names.at(i).c_str(),k,ieta,iphi,(depth-1)/2+1);
	  TH1F_PerTSs[i][k].push_back(new TH1F(histoName,histoName,TH1F_PerTS_nbinsx[i],TH1F_PerTS_lowx[i],TH1F_PerTS_highx[i]));
	  TH1F_PerTSs[i][k].back()->GetXaxis()->SetTitle(TH1F_PerTS_axisx.at(i).c_str());
	}
      }

      for (int i = 0 ; i < _num_TH2Fs ; i++) {
	sprintf(histoName,"%s_iEta%i_iPhi%i_Depth%i",TH2F_names.at(i).c_str(),ieta,iphi,(depth-1)/2+1);
	TH2Fs[i].push_back(new TH2F(histoName,histoName,TH2F_nbinsx[i],TH2F_lowx[i],TH2F_highx[i],TH2F_nbinsy[i],TH2F_lowy[i],TH2F_highy[i]));      
	TH2Fs[i].back()->GetXaxis()->SetTitle(TH2F_axisx.at(i).c_str());
	TH2Fs[i].back()->GetYaxis()->SetTitle(TH2F_axisy.at(i).c_str());
      }      

      for (int i = 0 ; i < _num_TH2F_PerTSs ; i++) {
	for(int k = 0; k < nTS ; k++) {
	  if (j == 0) {
	    vector<TH2F*> temp_TH2F_vector;
	    TH2F_PerTSs[i].push_back(temp_TH2F_vector);
	  }
	  sprintf(histoName,"%s_TS%i_iEta%i_iPhi%i_Depth%i",TH2F_PerTS_names.at(i).c_str(),k,ieta,iphi,(depth-1)/2+1);
	  TH2F_PerTSs[i][k].push_back(new TH2F(histoName,histoName,TH2F_PerTS_nbinsx[i],TH2F_PerTS_lowx[i],TH2F_PerTS_highx[i],TH2F_PerTS_nbinsy[i],TH2F_PerTS_lowy[i],TH2F_PerTS_highy[i]));      
	  TH2F_PerTSs[i][k].back()->GetXaxis()->SetTitle(TH2F_PerTS_axisx.at(i).c_str());
	  TH2F_PerTSs[i][k].back()->GetYaxis()->SetTitle(TH2F_PerTS_axisy.at(i).c_str());
	}      
      }
    }

    if (_verbosity>0){
      std::cout << "Printing raw dataframe" << std::endl;
      std::cout << qie10df << std::endl;
            
      std::cout << "Printing content of samples() method" << std::endl;
      std::cout << qie10df.samples() << std::endl;
    }
        
    if (_verbosity>0){
      std::cout << " detid: " << detid.rawId() << std::endl;
      std::cout << " ieta: " << ieta << "\n"
		<< " iphi: " << iphi << "\n"
		<< " depth: " << depth << std::endl;
    }
        
    //******** PRELOOP ***********

    loop_vars prevars;
    prevars = pre_loop();

    //********** LOOP ************
	
    for(int i=0; i<nTS; ++i)
      {

	prevars = loop(i,j,qie10df,prevars,TH1Fs,TH1F_PerTSs,TH1F_names,TH2Fs,TH2F_PerTSs,TH2F_names);

      }

    //******** POSTLOOP ********

    post_loop(j,prevars,TH1Fs,TH1F_PerTSs,TH1F_names,TH2Fs,TH2F_PerTSs,TH2F_names);

    if (_verbosity>0)
      std::cout << "The pedestal for this channel is " << prevars.adcped << "ADC counts and " << prevars.qped << " fC" << std::endl;
    
  }

  _event_num++;

  return;
}


// ------------ method called for each event  ------------
void 
HF_refl_analyzer::analyze(const edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  using namespace edm;

  getData(iEvent, iSetup);

#ifdef THIS_IS_AN_EVENT_EXAMPLE
  Handle<ExampleData> pIn;
  iEvent.getByLabel("example",pIn);
#endif

#ifdef THIS_IS_AN_EVENTSETUP_EXAMPLE
  ESHandle<SetupData> pSetup;
  iSetup.get<SetupRecord>().get(pSetup);
#endif
}


// ------------ method called once each job just before starting event loop  ------------
void 
HF_refl_analyzer::beginJob()
{
}

// ------------ method called once each job just after ending the event loop  ------------
void 
HF_refl_analyzer::endJob() 
{
  //      _file->Write();
  //      _file->Close();
}

// ------------ method called when starting to processes a run  ------------
void 
HF_refl_analyzer::beginRun(edm::Run const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a run  ------------
void 
HF_refl_analyzer::endRun(edm::Run const&, edm::EventSetup const&)
{
  //      _file->Write();
  //      _file->Close();
}

// ------------ method called when starting to processes a luminosity block  ------------
void 
HF_refl_analyzer::beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method called when ending the processing of a luminosity block  ------------
void 
HF_refl_analyzer::endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&)
{
}

// ------------ method fills 'descriptions' with the allowed parameters for the module  ------------
void
HF_refl_analyzer::fillDescriptions(edm::ConfigurationDescriptions& descriptions) {
  //The following says we do not know what parameters are allowed so do no validation
  // Please change this to state exactly what you do use, even if it is no parameters
  edm::ParameterSetDescription desc;
  desc.setUnknown();
  descriptions.addDefault(desc);
}

//define this as a plug-in
DEFINE_FWK_MODULE(HF_refl_analyzer);
