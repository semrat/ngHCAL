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

using namespace std;

#define PEAKTS 4
#define DOWNTS 6
#define REFLTS 7

#define NUMCHS 120 
#define NUMTS 50
#define NUMCHSTS NUMCHS*NUMTS

#define NUMADCS 256

double adc2fC_QIE10_refl[NUMADCS]={

  // =========== RANGE 0 ===========

  // --------- subrange 1 ---------
  -14.45,-11.35,-8.25,-5.15,-2.05,1.05,4.15,7.25,10.35,13.45,16.55,19.65,22.75,25.85,28.95,32.05,
  // --------- subrange 2 ---------
  36.7,42.9,49.1,55.3,61.5,67.7,73.9,80.1,86.3,92.5,98.7,104.9,111.1,117.3,123.5,129.7,135.9,142.1,148.3,154.5,
  // --------- subrange 3 ---------
  163.8,176.2,188.6,201.0,213.4,225.8,238.2,250.6,263.0,275.4,287.8,300.2,312.6,325.0,337.4,349.8,362.2,374.6,387.0,399.4,411.8,
  // --------- subrange 4 ---------
  430.4,455.2,480.0,504.8,529.6,554.4,579.2,
  // =========== RANGE 1 ===========

  // --------- subrange 1 ---------
  529.4,554.2,579.0,603.8,628.6,653.4,678.2,703.0,727.8,752.6,777.4,802.2,827.0,851.8,876.6,901.4,
  // --------- subrange 2 ---------
  938.6,988.2,1037.8,1087.4,1137.0,1186.6,1236.2,1285.8,1335.4,1385.0,1434.6,1484.2,1533.8,1583.4,1633.0,1682.6,1732.2,1781.8,1831.4,1881.0,
  // --------- subrange 3 ---------
  1955.4,2054.6,2153.8,2253.0,2352.2,2451.4,2550.6,2649.8,2749.0,2848.2,2947.4,3046.6,3145.8,3245.0,3344.2,3443.4,3542.6,3641.8,3741.0,3840.2,3939.4,
  // --------- subrange 4 ---------
  4088.2,4286.6,4485.0,4683.4,4881.8,5080.2,5278.6,
  // =========== RANGE 2 ===========

  // --------- subrange 1 ---------
  4879.2,5077.6,5276.0,5474.4,5672.8,5871.2,6069.6,6268.0,6466.4,6664.8,6863.2,7061.6,7260.0,7458.4,7656.8,7855.2,
  // --------- subrange 2 ---------
  8152.8,8549.6,8946.4,9343.2,9740.0,10136.8,10533.6,10930.4,11327.2,11724.0,12120.8,12517.6,12914.4,13311.2,13708.0,14104.8,14501.6,14898.4,15295.2,15692.0,
  // --------- subrange 3 ---------
  16287.2,17080.8,17874.4,18668.0,19461.6,20255.2,21048.8,21842.4,22636.0,23429.6,24223.2,25016.8,25810.4,26604.0,27397.6,28191.2,28984.8,29778.4,30572.0,31365.6,32159.2,
  // --------- subrange 4 ---------
  33349.6,34936.8,36524.0,38111.2,39698.4,41285.6,42872.8,
  // =========== RANGE 3 ===========

  // --------- subrange 1 ---------
  39693.5,41280.5,42867.5,44454.5,46041.5,47628.5,49215.5,50802.5,52389.5,53976.5,55563.5,57150.5,58737.5,60324.5,61911.5,63498.5,
  // --------- subrange 2 ---------
  65879.0,69053.0,72227.0,75401.0,78575.0,81749.0,84923.0,88097.0,91271.0,94445.0,97619.0,100793.0,103967.0,107141.0,110315.0,113489.0,116663.0,119837.0,123011.0,126185.0,
  // --------- subrange 3 ---------
  130946.0,137294.0,143642.0,149990.0,156338.0,162686.0,169034.0,175382.0,181730.0,188078.0,194426.0,200774.0,207122.0,213470.0,219818.0,226166.0,232514.0,238862.0,245210.0,251558.0,257906.0,
  // --------- subrange 4 ---------
  267428.0,280124.0,292820.0,305516.0,318212.0,330908.0,343604.0

};

void init_TH1Fs(vector<vector<TH1F*> > &TH1Fs, vector<vector<TH2F*> > &TH2Fs){

  vector<TH1F*> QSum;
  vector<TH1F*> Width;

  TH1Fs.push_back(QSum);
  TH1Fs.push_back(Width);

  vector<TH2F*> ADCpulse;			// 2D hist: charge vs. time sample (BX)
  vector<TH2F*> TDCpulse;                // 2D hist: TDC leading edge vs. BX
  vector<TH2F*> teTDCpulse;

  TH2Fs.push_back(ADCpulse);
  TH2Fs.push_back(TDCpulse);
  TH2Fs.push_back(teTDCpulse);

}

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

loop_vars loop(int nTS, int nCH, int tTS, QIE10DataFrame digis, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs, vector<vector<TH2F*> > &TH2Fs) {

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

  //  _qie10Info.pulse[nCH][nTS] = charge;
  //  _qie10Info.pulse_adc[nCH][nTS] = adc;
  //  _qie10Info.soi[nCH][nTS] = soi;

}

void post_loop(int nCH, loop_vars prevars, vector<vector<TH1F*> > &TH1Fs) {

  // log output
  //cout << endl;
  
  TH1Fs[0][nCH]->Fill( prevars.qsum );
  
}

/*
struct TQIE10Info
{
  int numChs;
  int numTS;
  int iphi[NUMCHS];
  int ieta[NUMCHS];
  int depth[NUMCHS];
  double pulse[NUMCHS][NUMTS];
  double ped[NUMCHS];
  double pulse_adc[NUMCHS][NUMTS];
  double ped_adc[NUMCHS];
  bool link_error[NUMCHS];
  bool soi[NUMCHS][NUMTS];
};
*/

//
// class declaration
//

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
  TTree *_treeQIE10;

  vector<vector<TH1F*> > TH1Fs;

  //in external file
  static const int _num_TH1Fs = 2;

  vector<vector<TH2F*> > TH2Fs;

  //in external file
  static const int _num_TH2Fs = 3;

  string _outFileName;
  int _verbosity;

  //  TQIE10Info _qie10Info;

  char histoName[100];

  // in external file
  char TH1F_names[_num_TH1Fs][100] = {"Qsum" , "Width"};
  int TH1F_nbinsx[_num_TH1Fs] = {64, 25};
  float TH1F_lowx[_num_TH1Fs] = {0, 0};
  float TH1F_highx[_num_TH1Fs] = {15000, 75};

  // in external file    
  char TH2F_names[_num_TH2Fs][100] = {"ADCpulse", "TDCpulse", "teTDCpulse"};
  int TH2F_nbinsx[_num_TH2Fs] = {10, 10, 10};
  float TH2F_lowx[_num_TH2Fs] = {-0.5, -0.5, -0.5};
  float TH2F_highx[_num_TH2Fs] = {9.5, 9.5, 9.5};
  int TH2F_nbinsy[_num_TH2Fs] = {256, 64, 32};
  float TH2F_lowy[_num_TH2Fs] = {-0.5, -0.5, -0.5};
  float TH2F_highy[_num_TH2Fs] = {255.5, 63.5, 31.5};

  virtual void beginRun(edm::Run const&, edm::EventSetup const&);
  virtual void endRun(edm::Run const&, edm::EventSetup const&);
  virtual void beginLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);
  virtual void endLuminosityBlock(edm::LuminosityBlock const&, edm::EventSetup const&);

  edm::EDGetTokenT<HcalDataFrameContainer<QIE10DataFrame> > tok_QIE10DigiCollection_;
  edm::EDGetTokenT<HFDigiCollection> hf_token;
  edm::Handle<QIE10DigiCollection> qie10DigiCollection;
  
  // ----------member data ---------------------------
};

//
// constructors and destructor
//
HF_refl_analyzer::HF_refl_analyzer(const edm::ParameterSet& iConfig) :
  _outFileName(iConfig.getUntrackedParameter<string>("OutFileName")),
  _verbosity(iConfig.getUntrackedParameter<int>("Verbosity"))
{


  tok_QIE10DigiCollection_ = consumes<HcalDataFrameContainer<QIE10DataFrame> >(edm::InputTag("hcalDigis"));
  hf_token = consumes<HFDigiCollection>(edm::InputTag("hcalDigis"));

  _file = new TFile(_outFileName.c_str(), "recreate");

  /*
  _file->mkdir("QIE10Data");

  _file->cd("QIE10Data");
  _treeQIE10 = new TTree("Events", "Events");
  _treeQIE10->Branch("numChs", &_qie10Info.numChs, "numChs/I");
  _treeQIE10->Branch("numTS", &_qie10Info.numTS, "numTS/I");
  _treeQIE10->Branch("iphi", _qie10Info.iphi, "iphi[numChs]/I");
  _treeQIE10->Branch("ieta", _qie10Info.ieta, "ieta[numChs]/I");
  _treeQIE10->Branch("depth", _qie10Info.depth, "depth[numChs]/I");
  _treeQIE10->Branch("pulse", _qie10Info.pulse, "pulse[numChs][50]/D");
  _treeQIE10->Branch("ped", _qie10Info.ped, "ped[numChs]/D");
  _treeQIE10->Branch("pulse_adc", _qie10Info.pulse_adc, "pulse_adc[numChs][50]/D");
  _treeQIE10->Branch("ped_adc", _qie10Info.ped_adc, "ped_adc[numChs]/D");
  _treeQIE10->Branch("link_error", _qie10Info.link_error, "link_error[numChs]/O");
  _treeQIE10->Branch("soi", _qie10Info.soi, "soi[numChs][50]/O");
  */

  init_TH1Fs(TH1Fs,TH2Fs);

}

HF_refl_analyzer::~HF_refl_analyzer()
{
  
  _file->cd();


  for (int i = 0 ; i < _num_TH1Fs ; i++) {

    for( unsigned int j = 0 ; j < TH1Fs[0].size() ; j++ ){
      TH1Fs[i][j]->Write();
    }

  }

  for (int i = 0 ; i < _num_TH2Fs ; i++) {

    for( unsigned int j = 0 ; j < TH2Fs[0].size() ; j++ ){    
      TH2Fs[i][j]->Write();
    }
 
  }

  _file->Write();
  _file->Close();

}
	
void HF_refl_analyzer::getData(const edm::Event &iEvent, const edm::EventSetup &iSetup)
{
  using namespace edm;

  //
  //  Extracting All the Collections containing useful Info
  iEvent.getByToken(tok_QIE10DigiCollection_,qie10DigiCollection);
  const QIE10DigiCollection& qie10dc=*(qie10DigiCollection);

  // --------------------------
  // --   QIE10 Information  --
  // --------------------------
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
    
    if( TH1Fs[0].size() <= j ){

      for (int i = 0 ; i < _num_TH1Fs ; i++) {

	sprintf(histoName,"%s_iEta%i_iPhi%i_Depth%i",TH1F_names[i],ieta,iphi,(depth-1)/2+1);
	TH1Fs[i].push_back(new TH1F(histoName,histoName,TH1F_nbinsx[i],TH1F_lowx[i],TH1F_highx[i]));


      }
      
      for (int i = 0 ; i < _num_TH2Fs ; i++) {

	sprintf(histoName,"%s_iEta%i_iPhi%i_Depth%i",TH2F_names[i],ieta,iphi,(depth-1)/2+1);
	TH2Fs[i].push_back(new TH2F(histoName,histoName,TH2F_nbinsx[i],TH2F_lowx[i],TH2F_highx[i],TH2F_nbinsy[i],TH2F_lowy[i],TH2F_highy[i]));      
 
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
	
    int nTS = qie10df.samples();

    for(int i=0; i<nTS; ++i)
      {

	prevars = loop(i,j,nTS,qie10df,prevars,TH1Fs,TH2Fs);

      }

    //******** POSTLOOP ********

    post_loop(j,prevars,TH1Fs);

    if (_verbosity>0)
      std::cout << "The pedestal for this channel is " << prevars.adcped << "ADC counts and " << prevars.qped << " fC" << std::endl;
  
    // -------------------------------------
    // --    Set the Branched arrays      --
    // -------------------------------------
    /*
    _qie10Info.iphi[j] = iphi;
    _qie10Info.ieta[j] = ieta;
    _qie10Info.depth[j] = depth;
    _qie10Info.ped[j] = prevars.qped;
    _qie10Info.ped_adc[j] = prevars.adcped;
    _qie10Info.link_error[j] = qie10df.linkError();
    */  
  }

  //_qie10Info.numChs = qie10dc.size();
  //_qie10Info.numTS = qie10dc.samples();

  //_treeQIE10->Fill();


  return;
}


//
// member functions
//

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
