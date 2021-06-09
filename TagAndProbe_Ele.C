#define TagAndProbe_cxx
#include "TagAndProbe.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void TagAndProbe::Loop(TString output)
{
   if (fChain == 0) return;
  bool RunSystematic=false;
   vector<TString> systematicVar =  {"nominal"};
   
   if (RunSystematic)
   {
	systematicVar.push_back("TagPt_up");
	systematicVar.push_back("TagPt_down");
	systematicVar.push_back("Zmass_up");
	systematicVar.push_back("Zmass_down");
   }

for(int i=0; i<systematicVar.size();i++)
{

   double ptTag = 37; 
   double zMassL = 60; 
   double zMassR = 120;

   if(systematicVar.at(i).Contains("TagPt_up")) ptTag = 41;
   if(systematicVar.at(i).Contains("TagPt_down")) ptTag = 33;
   if(systematicVar.at(i).Contains("Zmass_up")) {zMassL = 50; zMassR = 130;}
   if(systematicVar.at(i).Contains("Zmass_down")) {zMassL = 70; zMassR = 110;}
 
   cout<<systematicVar.at(i).Data()<<endl;
   cout<<" ptTag : "<<ptTag<<" , zMassL : "<<zMassL<<" , zMassR : "<<zMassR<<endl;
   //output = "";
   output +="_efficiency_";
   output +="tightid_";
   output += systematicVar.at(i);
   output +=".root";

   std::cout<< "total events : "<<fChain->GetEntries()<<endl;
   TFile *file = new TFile(output.Data(),"RECREATE");
   Long64_t nentries = fChain->GetEntriesFast();
//   std::cout<< "total events : "<<nentries<<endl;
   double eta_bins[19] = {-2.5,-2.4,-2.3,-2.2,-2.1,-1.566,-1.4442,-0.8,-0.4,0,0.4,0.8,1.4442,1.566,2.1,2.2,2.3,2.4,2.5};
   double pt_bins_Ele32[15] = {0,30,32,33,34,35,36,37,38,40,45,50,60,100,200};
   double pt_bins_Ele25[16] = {0,25,26,27,28,30,32,35,40,45,50,60,70,80,100,200};
   double pt_bins_Ele27[16] = {0,27,28,29,30,31,32,35,40,45,50,60,70,80,100,200};
   double pt_bins_Ele23_Ele12_leg1[14] = {0,20,23,24,25,26,30,35,40,45,50,60,100,200};
   double pt_bins_Ele23_Ele12_leg2[16] = {0,10,12,13,14,15,20,25,30,35,40,45,50,60,100,200};
   double pt_bins_Ele115[15] = {0,110,115,116,117,119,122,125,130,140,150,160,175,200,500};
   double pt_bins_Ele50[15] = {0,50,51,52,53,55,57,60,65,70,80,90,100,150,200};

   double eta_bins_115[11] = {-2.5,-2.0,-1.566,-1.4442,-0.8,0,0.8,1.4442,1.566,2.0,2.5};

   double PU_bins[8] = {0,20,30,40,50,60,70,100};


/*
// HLT Ele25

   TH1F *h_Ele25_pt_total = new TH1F("Ele25_pt_total","Ele25_pt",15,pt_bins_Ele25);
   TH1F *h_Ele25_eta_total = new TH1F("Ele25_eta_total","Ele25_eta",18,eta_bins);
   TH2F *h_Ele25_pt_eta_total = new TH2F("Ele25_pt_eta_total","Ele25_pt_eta",18,eta_bins,15,pt_bins_Ele25);
   TH1F *h_Ele25_pt_pass = new TH1F("Ele25_pt_pass","Ele25_pt",15,pt_bins_Ele25);
   TH1F *h_Ele25_eta_pass = new TH1F("Ele25_eta_pass","Ele25_eta",18,eta_bins);
   TH2F *h_Ele25_pt_eta_pass = new TH2F("Ele25_pt_eta_pass","Ele25_pt_eta",18,eta_bins,15,pt_bins_Ele25);

   h_Ele25_pt_total->Sumw2();
   h_Ele25_eta_total->Sumw2();
   h_Ele25_pt_eta_total->Sumw2();
   h_Ele25_pt_pass->Sumw2();
   h_Ele25_eta_pass->Sumw2();
   h_Ele25_pt_eta_pass->Sumw2();

// HLT Ele27

   TH1F *h_Ele27_pt_total = new TH1F("Ele27_pt_total","Ele27_pt",15,pt_bins_Ele27);
   TH1F *h_Ele27_eta_total = new TH1F("Ele27_eta_total","Ele27_eta",18,eta_bins);
   TH2F *h_Ele27_pt_eta_total = new TH2F("Ele27_pt_eta_total","Ele27_pt_eta",18,eta_bins,15,pt_bins_Ele27);
   TH1F *h_Ele27_pt_pass = new TH1F("Ele27_pt_pass","Ele27_pt",15,pt_bins_Ele27);
   TH1F *h_Ele27_eta_pass = new TH1F("Ele27_eta_pass","Ele27_eta",18,eta_bins);
   TH2F *h_Ele27_pt_eta_pass = new TH2F("Ele27_pt_eta_pass","Ele27_pt_eta",18,eta_bins,15,pt_bins_Ele27);

   h_Ele27_pt_total->Sumw2();
   h_Ele27_eta_total->Sumw2();
   h_Ele27_pt_eta_total->Sumw2();
   h_Ele27_pt_pass->Sumw2();
   h_Ele27_eta_pass->Sumw2();
   h_Ele27_pt_eta_pass->Sumw2();
*/
// HLT Ele32

   TH1F *h_Ele32_PU_total = new TH1F("Ele32_PU_total","Ele32_pu",7,PU_bins);
   TH1F *h_Ele32_PU_pass = new TH1F("Ele32_PU_pass","Ele32_pu",7,PU_bins);

   TH1F *h_Ele32_pt_total = new TH1F("Ele32_pt_total","Ele32_pt",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total = new TH1F("Ele32_eta_total","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total = new TH2F("Ele32_pt_eta_total","Ele32_pt_eta",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass = new TH1F("Ele32_pt_pass","Ele32_pt",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass = new TH1F("Ele32_eta_pass","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass = new TH2F("Ele32_pt_eta_pass","Ele32_pt_eta",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total->Sumw2();
   h_Ele32_PU_pass->Sumw2();


   h_Ele32_pt_total->Sumw2();
   h_Ele32_eta_total->Sumw2();
   h_Ele32_pt_eta_total->Sumw2();
   h_Ele32_pt_pass->Sumw2();
   h_Ele32_eta_pass->Sumw2();
   h_Ele32_pt_eta_pass->Sumw2();

   TH1F *h_Ele32_PU_total_filter1 = new TH1F("Ele32_PU_total_filter1","Ele32_pu_filter1",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter1 = new TH1F("Ele32_PU_pass_filter1","Ele32_pu_filter1",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter1 = new TH1F("Ele32_pt_total_filter1","Ele32_pt_filter1",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter1 = new TH1F("Ele32_eta_total_filter1","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter1 = new TH2F("Ele32_pt_eta_total_filter1","Ele32_pt_eta_filter1",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter1 = new TH1F("Ele32_pt_pass_filter1","Ele32_pt_filter1",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter1 = new TH1F("Ele32_eta_pass_filter1","Ele32_eta_filter1",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter1 = new TH2F("Ele32_pt_eta_pass_filter1","Ele32_pt_eta_filter1",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter1->Sumw2();
   h_Ele32_PU_pass_filter1->Sumw2();


   h_Ele32_pt_total_filter1->Sumw2();
   h_Ele32_eta_total_filter1->Sumw2();
   h_Ele32_pt_eta_total_filter1->Sumw2();
   h_Ele32_pt_pass_filter1->Sumw2();
   h_Ele32_eta_pass_filter1->Sumw2();
   h_Ele32_pt_eta_pass_filter1->Sumw2();


   TH1F *h_Ele32_PU_total_filter2 = new TH1F("Ele32_PU_total_filter2","Ele32_pu_filter2",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter2 = new TH1F("Ele32_PU_pass_filter2","Ele32_pu_filter2",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter2 = new TH1F("Ele32_pt_total_filter2","Ele32_pt_filter2",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter2 = new TH1F("Ele32_eta_total_filter2","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter2 = new TH2F("Ele32_pt_eta_total_filter2","Ele32_pt_eta_filter2",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter2 = new TH1F("Ele32_pt_pass_filter2","Ele32_pt_filter2",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter2 = new TH1F("Ele32_eta_pass_filter2","Ele32_eta_filter2",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter2 = new TH2F("Ele32_pt_eta_pass_filter2","Ele32_pt_eta_filter2",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter2->Sumw2();
   h_Ele32_PU_pass_filter2->Sumw2();


   h_Ele32_pt_total_filter2->Sumw2();
   h_Ele32_eta_total_filter2->Sumw2();
   h_Ele32_pt_eta_total_filter2->Sumw2();
   h_Ele32_pt_pass_filter2->Sumw2();
   h_Ele32_eta_pass_filter2->Sumw2();
   h_Ele32_pt_eta_pass_filter2->Sumw2();

   TH1F *h_Ele32_PU_total_filter3 = new TH1F("Ele32_PU_total_filter3","Ele32_pu_filter3",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter3 = new TH1F("Ele32_PU_pass_filter3","Ele32_pu_filter3",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter3 = new TH1F("Ele32_pt_total_filter3","Ele32_pt_filter3",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter3 = new TH1F("Ele32_eta_total_filter3","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter3 = new TH2F("Ele32_pt_eta_total_filter3","Ele32_pt_eta_filter3",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter3 = new TH1F("Ele32_pt_pass_filter3","Ele32_pt_filter3",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter3 = new TH1F("Ele32_eta_pass_filter3","Ele32_etafilter3",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter3 = new TH2F("Ele32_pt_eta_pass_filter3","Ele32_pt_eta_filter3",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter3->Sumw2();
   h_Ele32_PU_pass_filter3->Sumw2();


   h_Ele32_pt_total_filter3->Sumw2();
   h_Ele32_eta_total_filter3->Sumw2();
   h_Ele32_pt_eta_total_filter3->Sumw2();
   h_Ele32_pt_pass_filter3->Sumw2();
   h_Ele32_eta_pass_filter3->Sumw2();
   h_Ele32_pt_eta_pass_filter3->Sumw2();
   TH1F *h_Ele32_PU_total_filter4 = new TH1F("Ele32_PU_total_filter4","Ele32_pu_filter4",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter4 = new TH1F("Ele32_PU_pass_filter4","Ele32_pu_filter4",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter4 = new TH1F("Ele32_pt_total_filter4","Ele32_pt_filter4",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter4 = new TH1F("Ele32_eta_total_filter4","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter4 = new TH2F("Ele32_pt_eta_total_filter4","Ele32_pt_eta_filter4",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter4 = new TH1F("Ele32_pt_pass_filter4","Ele32_pt_filter4",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter4 = new TH1F("Ele32_eta_pass_filter4","Ele32_eta_filter4",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter4 = new TH2F("Ele32_pt_eta_pass_filter4","Ele32_pt_eta_filter4",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter4->Sumw2();
   h_Ele32_PU_pass_filter4->Sumw2();


   h_Ele32_pt_total_filter4->Sumw2();
   h_Ele32_eta_total_filter4->Sumw2();
   h_Ele32_pt_eta_total_filter4->Sumw2();
   h_Ele32_pt_pass_filter4->Sumw2();
   h_Ele32_eta_pass_filter4->Sumw2();
   h_Ele32_pt_eta_pass_filter4->Sumw2();
   TH1F *h_Ele32_PU_total_filter5 = new TH1F("Ele32_PU_total_filter5","Ele32_pu_filter5",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter5 = new TH1F("Ele32_PU_pass_filter5","Ele32_pu_filter5",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter5 = new TH1F("Ele32_pt_total_filter5","Ele32_pt_filter5",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter5 = new TH1F("Ele32_eta_total_filter5","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter5 = new TH2F("Ele32_pt_eta_total_filter5","Ele32_pt_eta_filter5",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter5 = new TH1F("Ele32_pt_pass_filter5","Ele32_pt_filter5",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter5 = new TH1F("Ele32_eta_pass_filter5","Ele32_eta_filter5",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter5 = new TH2F("Ele32_pt_eta_pass_filter5","Ele32_pt_eta_filter5",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter5->Sumw2();
   h_Ele32_PU_pass_filter5->Sumw2();


   h_Ele32_pt_total_filter5->Sumw2();
   h_Ele32_eta_total_filter5->Sumw2();
   h_Ele32_pt_eta_total_filter5->Sumw2();
   h_Ele32_pt_pass_filter5->Sumw2();
   h_Ele32_eta_pass_filter5->Sumw2();
   h_Ele32_pt_eta_pass_filter5->Sumw2();
   TH1F *h_Ele32_PU_total_filter6 = new TH1F("Ele32_PU_total_filter6","Ele32_pu_filter6",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter6 = new TH1F("Ele32_PU_pass_filter6","Ele32_pu_filter6",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter6 = new TH1F("Ele32_pt_total_filter6","Ele32_pt_filter6",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter6 = new TH1F("Ele32_eta_total_filter6","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter6 = new TH2F("Ele32_pt_eta_total_filter6","Ele32_pt_eta_filter6",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter6 = new TH1F("Ele32_pt_pass_filter6","Ele32_pt_filter6",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter6 = new TH1F("Ele32_eta_pass_filter6","Ele32_eta_filter6",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter6 = new TH2F("Ele32_pt_eta_pass_filter6","Ele32_pt_eta_filter6",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter6->Sumw2();
   h_Ele32_PU_pass_filter6->Sumw2();


   h_Ele32_pt_total_filter6->Sumw2();
   h_Ele32_eta_total_filter6->Sumw2();
   h_Ele32_pt_eta_total_filter6->Sumw2();
   h_Ele32_pt_pass_filter6->Sumw2();
   h_Ele32_eta_pass_filter6->Sumw2();
   h_Ele32_pt_eta_pass_filter6->Sumw2();
   TH1F *h_Ele32_PU_total_filter7 = new TH1F("Ele32_PU_total_filter7","Ele32_pu_filter7",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter7 = new TH1F("Ele32_PU_pass_filter7","Ele32_pu_filter7",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter7 = new TH1F("Ele32_pt_total_filter7","Ele32_pt_filter7",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter7 = new TH1F("Ele32_eta_total_filter7","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter7 = new TH2F("Ele32_pt_eta_total_filter7","Ele32_pt_eta_filter7",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter7 = new TH1F("Ele32_pt_pass_filter7","Ele32_pt_filter7",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter7 = new TH1F("Ele32_eta_pass_filter7","Ele32_eta_filter7",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter7 = new TH2F("Ele32_pt_eta_pass_filter7","Ele32_pt_eta_filter7",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter7->Sumw2();
   h_Ele32_PU_pass_filter7->Sumw2();


   h_Ele32_pt_total_filter7->Sumw2();
   h_Ele32_eta_total_filter7->Sumw2();
   h_Ele32_pt_eta_total_filter7->Sumw2();
   h_Ele32_pt_pass_filter7->Sumw2();
   h_Ele32_eta_pass_filter7->Sumw2();
   h_Ele32_pt_eta_pass_filter7->Sumw2();
   TH1F *h_Ele32_PU_total_filter8 = new TH1F("Ele32_PU_total_filter8","Ele32_pu_filter8",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter8 = new TH1F("Ele32_PU_pass_filter8","Ele32_pu_filter8",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter8 = new TH1F("Ele32_pt_total_filter8","Ele32_pt_filter8",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter8 = new TH1F("Ele32_eta_total_filter8","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter8 = new TH2F("Ele32_pt_eta_total_filter8","Ele32_pt_eta_filter8",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter8 = new TH1F("Ele32_pt_pass_filter8","Ele32_pt_filter8",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter8 = new TH1F("Ele32_eta_pass_filter8","Ele32_eta_filter9",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter8 = new TH2F("Ele32_pt_eta_pass_filter8","Ele32_pt_eta_filter8",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter8->Sumw2();
   h_Ele32_PU_pass_filter8->Sumw2();


   h_Ele32_pt_total_filter8->Sumw2();
   h_Ele32_eta_total_filter8->Sumw2();
   h_Ele32_pt_eta_total_filter8->Sumw2();
   h_Ele32_pt_pass_filter8->Sumw2();
   h_Ele32_eta_pass_filter8->Sumw2();
   h_Ele32_pt_eta_pass_filter8->Sumw2();
   TH1F *h_Ele32_PU_total_filter9 = new TH1F("Ele32_PU_total_filter9","Ele32_pu_filter9",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter9 = new TH1F("Ele32_PU_pass_filter9","Ele32_pu_filter9",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter9 = new TH1F("Ele32_pt_total_filter9","Ele32_pt_filter9",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter9 = new TH1F("Ele32_eta_total_filter9","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter9 = new TH2F("Ele32_pt_eta_total_filter9","Ele32_pt_eta_filter9",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter9 = new TH1F("Ele32_pt_pass_filter9","Ele32_pt_filter9",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter9 = new TH1F("Ele32_eta_pass_filter9","Ele32_eta_filter9",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter9 = new TH2F("Ele32_pt_eta_pass_filter9","Ele32_pt_eta_filter9",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter9->Sumw2();
   h_Ele32_PU_pass_filter9->Sumw2();


   h_Ele32_pt_total_filter9->Sumw2();
   h_Ele32_eta_total_filter9->Sumw2();
   h_Ele32_pt_eta_total_filter9->Sumw2();
   h_Ele32_pt_pass_filter9->Sumw2();
   h_Ele32_eta_pass_filter9->Sumw2();
   h_Ele32_pt_eta_pass_filter9->Sumw2();
   TH1F *h_Ele32_PU_total_filter10 = new TH1F("Ele32_PU_total_filter10","Ele32_pu_filter10",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter10 = new TH1F("Ele32_PU_pass_filter10","Ele32_pu_filter10",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter10 = new TH1F("Ele32_pt_total_filter10","Ele32_pt_filter10",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter10 = new TH1F("Ele32_eta_total_filter10","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter10 = new TH2F("Ele32_pt_eta_total_filter10","Ele32_pt_eta_filter10",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter10 = new TH1F("Ele32_pt_pass_filter10","Ele32_pt_filter10",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter10 = new TH1F("Ele32_eta_pass_filter10","Ele32_eta_filter10",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter10 = new TH2F("Ele32_pt_eta_pass_filter10","Ele32_pt_eta_filter10",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter10->Sumw2();
   h_Ele32_PU_pass_filter10->Sumw2();


   h_Ele32_pt_total_filter10->Sumw2();
   h_Ele32_eta_total_filter10->Sumw2();
   h_Ele32_pt_eta_total_filter10->Sumw2();
   h_Ele32_pt_pass_filter10->Sumw2();
   h_Ele32_eta_pass_filter10->Sumw2();
   h_Ele32_pt_eta_pass_filter10->Sumw2();
   TH1F *h_Ele32_PU_total_filter11 = new TH1F("Ele32_PU_total_filter11","Ele32_pu_filter11",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter11 = new TH1F("Ele32_PU_pass_filter11","Ele32_pu_filter11",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter11 = new TH1F("Ele32_pt_total_filter11","Ele32_pt_filter11",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter11 = new TH1F("Ele32_eta_total_filter11","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter11 = new TH2F("Ele32_pt_eta_total_filter11","Ele32_pt_eta_filter11",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter11 = new TH1F("Ele32_pt_pass_filter11","Ele32_pt_filter11",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter11 = new TH1F("Ele32_eta_pass_filter11","Ele32_eta_filter11",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter11 = new TH2F("Ele32_pt_eta_pass_filter11","Ele32_pt_eta_filter11",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter11->Sumw2();
   h_Ele32_PU_pass_filter11->Sumw2();


   h_Ele32_pt_total_filter11->Sumw2();
   h_Ele32_eta_total_filter11->Sumw2();
   h_Ele32_pt_eta_total_filter11->Sumw2();
   h_Ele32_pt_pass_filter11->Sumw2();
   h_Ele32_eta_pass_filter11->Sumw2();
   h_Ele32_pt_eta_pass_filter11->Sumw2();
   TH1F *h_Ele32_PU_total_filter12 = new TH1F("Ele32_PU_total_filter12","Ele32_pu_filter12",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter12 = new TH1F("Ele32_PU_pass_filter12","Ele32_pu_filter12",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter12 = new TH1F("Ele32_pt_total_filter12","Ele32_pt_filter12",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter12 = new TH1F("Ele32_eta_total_filter12","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter12 = new TH2F("Ele32_pt_eta_total_filter12","Ele32_pt_eta_filter12",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter12 = new TH1F("Ele32_pt_pass_filter12","Ele32_pt_filter12",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter12 = new TH1F("Ele32_eta_pass_filter12","Ele32_eta_filter12",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter12 = new TH2F("Ele32_pt_eta_pass_filter12","Ele32_pt_eta_filter12",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter12->Sumw2();
   h_Ele32_PU_pass_filter12->Sumw2();


   h_Ele32_pt_total_filter12->Sumw2();
   h_Ele32_eta_total_filter12->Sumw2();
   h_Ele32_pt_eta_total_filter12->Sumw2();
   h_Ele32_pt_pass_filter12->Sumw2();
   h_Ele32_eta_pass_filter12->Sumw2();
   h_Ele32_pt_eta_pass_filter12->Sumw2();
   TH1F *h_Ele32_PU_total_filter13 = new TH1F("Ele32_PU_total_filter13","Ele32_pu_filter13",7,PU_bins);
   TH1F *h_Ele32_PU_pass_filter13 = new TH1F("Ele32_PU_pass_filter13","Ele32_pu_filter13",7,PU_bins);

   TH1F *h_Ele32_pt_total_filter13 = new TH1F("Ele32_pt_total_filter13","Ele32_pt_filter13",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_total_filter13 = new TH1F("Ele32_eta_total_filter13","Ele32_eta",18,eta_bins);
   TH2F *h_Ele32_pt_eta_total_filter13 = new TH2F("Ele32_pt_eta_total_filter13","Ele32_pt_eta_filter13",18,eta_bins,14,pt_bins_Ele32);
   TH1F *h_Ele32_pt_pass_filter13 = new TH1F("Ele32_pt_pass_filter13","Ele32_pt_filter13",14,pt_bins_Ele32);
   TH1F *h_Ele32_eta_pass_filter13 = new TH1F("Ele32_eta_pass_filter13","Ele32_eta_filter13",18,eta_bins);
   TH2F *h_Ele32_pt_eta_pass_filter13 = new TH2F("Ele32_pt_eta_pass_filter13","Ele32_pt_eta_filter13",18,eta_bins,14,pt_bins_Ele32);

   h_Ele32_PU_total_filter13->Sumw2();
   h_Ele32_PU_pass_filter13->Sumw2();


   h_Ele32_pt_total_filter13->Sumw2();
   h_Ele32_eta_total_filter13->Sumw2();
   h_Ele32_pt_eta_total_filter13->Sumw2();
   h_Ele32_pt_pass_filter13->Sumw2();
   h_Ele32_eta_pass_filter13->Sumw2();
   h_Ele32_pt_eta_pass_filter13->Sumw2();
/*
// HLT Ele50

   TH1F *h_Ele50_pt_total = new TH1F("Ele50_pt_total","Ele50_pt",14,pt_bins_Ele50);
   TH1F *h_Ele50_eta_total = new TH1F("Ele50_eta_total","Ele50_eta",18,eta_bins);
   TH2F *h_Ele50_pt_eta_total = new TH2F("Ele50_pt_eta_total","Ele50_pt_eta",18,eta_bins,14,pt_bins_Ele50);
   TH1F *h_Ele50_pt_pass = new TH1F("Ele50_pt_pass","Ele50_pt",14,pt_bins_Ele50);
   TH1F *h_Ele50_eta_pass = new TH1F("Ele50_eta_pass","Ele50_eta",18,eta_bins);
   TH2F *h_Ele50_pt_eta_pass = new TH2F("Ele50_pt_eta_pass","Ele50_pt_eta",18,eta_bins,14,pt_bins_Ele50);

   h_Ele50_pt_total->Sumw2();
   h_Ele50_eta_total->Sumw2();
   h_Ele50_pt_eta_total->Sumw2();
   h_Ele50_pt_pass->Sumw2();
   h_Ele50_eta_pass->Sumw2();
   h_Ele50_pt_eta_pass->Sumw2();


// HLT Ele115

   TH1F *h_Ele115_pt_total = new TH1F("Ele115_pt_total","Ele115_pt",14,pt_bins_Ele115);
   TH1F *h_Ele115_eta_total = new TH1F("Ele115_eta_total","Ele115_eta",10,eta_bins_115);
   TH2F *h_Ele115_pt_eta_total = new TH2F("Ele115_pt_eta_total","Ele115_pt_eta",10,eta_bins,14,pt_bins_Ele115);
   TH1F *h_Ele115_pt_pass = new TH1F("Ele115_pt_pass","Ele115_pt",14,pt_bins_Ele115);
   TH1F *h_Ele115_eta_pass = new TH1F("Ele115_eta_pass","Ele115_eta",10,eta_bins_115);
   TH2F *h_Ele115_pt_eta_pass = new TH2F("Ele115_pt_eta_pass","Ele115_pt_eta",10,eta_bins_115,14,pt_bins_Ele115);

   h_Ele115_pt_total->Sumw2();
   h_Ele115_eta_total->Sumw2();
   h_Ele115_pt_eta_total->Sumw2();
   h_Ele115_pt_pass->Sumw2();
   h_Ele115_eta_pass->Sumw2();
   h_Ele115_pt_eta_pass->Sumw2();

// HLT Ele23_Ele12 Ele23 leg
   TH1F *h_Ele23_Ele12_leg1_pt_total = new TH1F("Ele23_Ele12_leg1_pt_total","Ele23_Ele12_leg1_pt",13,pt_bins_Ele23_Ele12_leg1);
   TH1F *h_Ele23_Ele12_leg1_eta_total = new TH1F("Ele23_Ele12_leg1_eta_total","Ele23_Ele12_leg1_eta",18,eta_bins);
   TH2F *h_Ele23_Ele12_leg1_pt_eta_total = new TH2F("Ele23_Ele12_leg1_pt_eta_total","Ele23_Ele12_leg1_pt_eta",18,eta_bins,13,pt_bins_Ele23_Ele12_leg1);
   TH1F *h_Ele23_Ele12_leg1_pt_pass = new TH1F("Ele23_Ele12_leg1_pt_pass","Ele23_Ele12_leg1_pt",13,pt_bins_Ele23_Ele12_leg1);
   TH1F *h_Ele23_Ele12_leg1_eta_pass = new TH1F("Ele23_Ele12_leg1_eta_pass","Ele23_Ele12_leg1_eta",18,eta_bins);
   TH2F *h_Ele23_Ele12_leg1_pt_eta_pass = new TH2F("Ele23_Ele12_leg1_pt_eta_pass","Ele23_Ele12_leg1_pt_eta",18,eta_bins,13,pt_bins_Ele23_Ele12_leg1);
      
   h_Ele23_Ele12_leg1_pt_total->Sumw2();
   h_Ele23_Ele12_leg1_eta_total->Sumw2();
   h_Ele23_Ele12_leg1_pt_eta_total->Sumw2();
   h_Ele23_Ele12_leg1_pt_pass->Sumw2();
   h_Ele23_Ele12_leg1_eta_pass->Sumw2();
   h_Ele23_Ele12_leg1_pt_eta_pass->Sumw2();

// HLT Ele23_Ele12 Ele12 leg
   TH1F *h_Ele23_Ele12_leg2_pt_total = new TH1F("Ele23_Ele12_leg2_pt_total","Ele23_Ele12_leg2_pt",15,pt_bins_Ele23_Ele12_leg2);
   TH1F *h_Ele23_Ele12_leg2_eta_total = new TH1F("Ele23_Ele12_leg2_eta_total","Ele23_Ele12_leg2_eta",18,eta_bins);
   TH2F *h_Ele23_Ele12_leg2_pt_eta_total = new TH2F("Ele23_Ele12_leg2_pt_eta_total","Ele23_Ele12_leg2_pt_eta",18,eta_bins,15,pt_bins_Ele23_Ele12_leg2);
   TH1F *h_Ele23_Ele12_leg2_pt_pass = new TH1F("Ele23_Ele12_leg2_pt_pass","Ele23_Ele12_leg2_pt",15,pt_bins_Ele23_Ele12_leg2);
   TH1F *h_Ele23_Ele12_leg2_eta_pass = new TH1F("Ele23_Ele12_leg2_eta_pass","Ele23_Ele12_leg2_eta",18,eta_bins);
   TH2F *h_Ele23_Ele12_leg2_pt_eta_pass = new TH2F("Ele23_Ele12_leg2_pt_eta_pass","Ele23_Ele12_leg2_pt_eta",18,eta_bins,15,pt_bins_Ele23_Ele12_leg2);

   h_Ele23_Ele12_leg2_pt_total->Sumw2();
   h_Ele23_Ele12_leg2_eta_total->Sumw2();
   h_Ele23_Ele12_leg2_pt_eta_total->Sumw2();
   h_Ele23_Ele12_leg2_pt_pass->Sumw2();
   h_Ele23_Ele12_leg2_eta_pass->Sumw2();
   h_Ele23_Ele12_leg2_pt_eta_pass->Sumw2();

*/
   Long64_t nbytes = 0, nb = 0;
   for (Long64_t jentry=0; jentry<nentries;jentry++) {
      Long64_t ientry = LoadTree(jentry);
      if (ientry < 0) break;
      nb = fChain->GetEntry(jentry);   nbytes += nb;
      //if(jentry%50000 == 0)cout<<"number of events processed : "<<jentry<<endl;
      if(jentry%5000 == 0)cout<<"number of events processed : "<<jentry<<endl;
      if(nEle!=2) continue;
     //aloke
      vector<vector<string>> testfilterName32=*filterName32;
      vector<vector<bool>> testfilterDecision32=*filterDecision32;
//      cout<<"testfilterDecision32 size ="<<testfilterDecision32.size()<<endl;
      int first  = rand()%2;
      int second = (first+1)%2; 
    //  cout<<"first : second = "<<first<<"  "<<second<<endl;     
      if(ele_charge->at(first) * ele_charge->at(second)>0)continue;
      bool tag_EleId = passEleIdTight->at(first);
      bool tag_EleKin = ele_pt->at(first)>ptTag && fabs(ele_etaSC->at(first))<2.5;
     
      //bool tag_TriggerMatch = passFilterEle32->at(first);
//      cout<<" testfilterDecision32 value = "<<testfilterDecision32[first][0]<<endl;
//      cout<<" testfilterDecision32 value 2 = "<<testfilterDecision32[second][0]<<endl;
      bool tag_TriggerMatch_L1SingleEGOr		=testfilterDecision32[first][0];
      bool tag_TriggerMatch_32L1SingleEGOr		=testfilterDecision32[first][1];
      bool tag_TriggerMatch_ClusterShape		=testfilterDecision32[first][2];
      bool tag_TriggerMatch_HEFilter			=testfilterDecision32[first][3];
      bool tag_TriggerMatch_EcalIso			=testfilterDecision32[first][4];
      bool tag_TriggerMatch_HcalIso			=testfilterDecision32[first][5];
      bool tag_TriggerMatch_PixelMatch			=testfilterDecision32[first][6];
      bool tag_TriggerMatch_PMS2			=testfilterDecision32[first][7];
      bool tag_TriggerMatch_GsfOneOEMinusOneOP		=testfilterDecision32[first][8];
      bool tag_TriggerMatch_GsfMissingHits		=testfilterDecision32[first][9];
      bool tag_TriggerMatch_GsfDeta			=testfilterDecision32[first][10];
      bool tag_TriggerMatch_GsfDphi			=testfilterDecision32[first][11];
      bool tag_TriggerMatch_GsfTrackIso			=testfilterDecision32[first][12];

      bool tag_TriggerMatch =  tag_TriggerMatch_L1SingleEGOr && tag_TriggerMatch_32L1SingleEGOr && tag_TriggerMatch_ClusterShape && tag_TriggerMatch_HEFilter && tag_TriggerMatch_EcalIso && tag_TriggerMatch_HcalIso && tag_TriggerMatch_PixelMatch && tag_TriggerMatch_PMS2 && tag_TriggerMatch_GsfOneOEMinusOneOP && tag_TriggerMatch_GsfMissingHits && tag_TriggerMatch_GsfDeta && tag_TriggerMatch_GsfDphi && tag_TriggerMatch_GsfTrackIso ;

      if(!(tag_EleId && tag_EleKin && tag_TriggerMatch))continue;
//      if(!(tag_EleId && tag_EleKin && tag_TriggerMatch_L1SingleEGOr))continue;
//      if(!(tag_EleId && tag_EleKin))continue;

      bool probe_EleId = HWW_Electron_NewDef(second, ele_etaSC->at(second));
      bool probe_EleKin = fabs(ele_etaSC->at(second))<2.5;

      bool pass32Filter_L1SingleEGOr		=testfilterDecision32[second][0];
 //     cout<<" pass32Filter_L1SingleEGOr = "<<pass32Filter_L1SingleEGOr<<endl;
      bool pass32Filter_32L1SingleEGOr		=testfilterDecision32[second][1] && pass32Filter_L1SingleEGOr ;
      bool pass32Filter_ClusterShape		=testfilterDecision32[second][2] && pass32Filter_32L1SingleEGOr ;
      bool pass32Filter_HEFilter		=testfilterDecision32[second][3] && pass32Filter_ClusterShape ;
      bool pass32Filter_EcalIso			=testfilterDecision32[second][4] && pass32Filter_HEFilter;
      bool pass32Filter_HcalIso			=testfilterDecision32[second][5] && pass32Filter_EcalIso ;
      bool pass32Filter_PixelMatch		=testfilterDecision32[second][6] && pass32Filter_HcalIso;
      bool pass32Filter_PMS2			=testfilterDecision32[second][7] && pass32Filter_PixelMatch;
      bool pass32Filter_GsfOneOEMinusOneOP	=testfilterDecision32[second][8] && pass32Filter_PMS2 ;
      bool pass32Filter_GsfMissingHits		=testfilterDecision32[second][9] && pass32Filter_GsfOneOEMinusOneOP ;
      bool pass32Filter_GsfDeta			=testfilterDecision32[second][10] && pass32Filter_GsfMissingHits ;
      bool pass32Filter_GsfDphi			=testfilterDecision32[second][11] && pass32Filter_GsfDeta;
      bool pass32Filter_GsfTrackIso		=testfilterDecision32[second][12] && pass32Filter_GsfDphi;


  //    if(!(probe_EleId && probe_EleKin)) continue;

      TLorentzVector tag_eleLV, probe_eleLV, Z_candLV;
      tag_eleLV.SetPtEtaPhiM(ele_pt->at(first), ele_etaSC->at(first), ele_phi->at(first),0.);
      probe_eleLV.SetPtEtaPhiM(ele_pt->at(second), ele_etaSC->at(second), ele_phi->at(second),0.);
      Z_candLV = tag_eleLV + probe_eleLV;

      if (Z_candLV.M()<zMassL || Z_candLV.M() > zMassR) continue;

/*
      h_Ele25_pt_total->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>33)h_Ele25_eta_total->Fill(ele_etaSC->at(second));
      h_Ele25_pt_eta_total->Fill(ele_etaSC->at(second),ele_pt->at(second));

      h_Ele27_pt_total->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>35)h_Ele27_eta_total->Fill(ele_etaSC->at(second));
      h_Ele27_pt_eta_total->Fill(ele_etaSC->at(second),ele_pt->at(second));
*/  

     
      if(ele_pt->at(second)>40)h_Ele32_PU_total->Fill(nPV); //full trigger
      h_Ele32_pt_total->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total->Fill(ele_etaSC->at(second),ele_pt->at(second));

      
      if(ele_pt->at(second)>40)h_Ele32_PU_total_filter1->Fill(nPV);
      h_Ele32_pt_total_filter1->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter1->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter1->Fill(ele_etaSC->at(second),ele_pt->at(second));
   
     if(pass32Filter_L1SingleEGOr){ 
     if(ele_pt->at(second)>40) h_Ele32_PU_total_filter2->Fill(nPV);
      h_Ele32_pt_total_filter2->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter2->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter2->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
     if(pass32Filter_32L1SingleEGOr){ 
     if(ele_pt->at(second)>40) h_Ele32_PU_total_filter3->Fill(nPV);
      h_Ele32_pt_total_filter3->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter3->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter3->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
     if(pass32Filter_ClusterShape){ 
      if(ele_pt->at(second)>40)h_Ele32_PU_total_filter4->Fill(nPV);
      h_Ele32_pt_total_filter4->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter4->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter4->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
     if( pass32Filter_HEFilter){ 
      if(ele_pt->at(second)>40)h_Ele32_PU_total_filter5->Fill(nPV);
      h_Ele32_pt_total_filter5->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter5->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter5->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
     if(pass32Filter_EcalIso){ 
      if(ele_pt->at(second)>40)h_Ele32_PU_total_filter6->Fill(nPV);
      h_Ele32_pt_total_filter6->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter6->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter6->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
     if(pass32Filter_HcalIso){ 
      if(ele_pt->at(second)>40)h_Ele32_PU_total_filter7->Fill(nPV);
      h_Ele32_pt_total_filter7->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter7->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter7->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
     if(pass32Filter_PixelMatch){ 
      if(ele_pt->at(second)>40)h_Ele32_PU_total_filter8->Fill(nPV);
      h_Ele32_pt_total_filter8->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter8->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter8->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
     if(pass32Filter_PMS2){ 
      if(ele_pt->at(second)>40)h_Ele32_PU_total_filter9->Fill(nPV);
      h_Ele32_pt_total_filter9->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter9->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter9->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
     if(pass32Filter_GsfOneOEMinusOneOP){ 
      if(ele_pt->at(second)>40)h_Ele32_PU_total_filter10->Fill(nPV);
      h_Ele32_pt_total_filter10->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter10->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter10->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
     if( pass32Filter_GsfMissingHits){ 
      if(ele_pt->at(second)>40)h_Ele32_PU_total_filter11->Fill(nPV);
      h_Ele32_pt_total_filter11->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter11->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter11->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
     if(pass32Filter_GsfDeta){ 
      if(ele_pt->at(second)>40)h_Ele32_PU_total_filter12->Fill(nPV);
      h_Ele32_pt_total_filter12->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter12->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter12->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
     if( pass32Filter_GsfDphi){ 
      if(ele_pt->at(second)>40)h_Ele32_PU_total_filter13->Fill(nPV);
      h_Ele32_pt_total_filter13->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_total_filter13->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_total_filter13->Fill(ele_etaSC->at(second),ele_pt->at(second));
    }
/*
      h_Ele50_pt_total->Fill(ele_pt->at(second)); 
      if(ele_pt->at(second)>58)h_Ele50_eta_total->Fill(ele_etaSC->at(second)); 
      h_Ele50_pt_eta_total->Fill(ele_etaSC->at(second),ele_pt->at(second)); 
     
      h_Ele115_pt_total->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>123)h_Ele115_eta_total->Fill(ele_etaSC->at(second));
      h_Ele115_pt_eta_total->Fill(ele_etaSC->at(second),ele_pt->at(second));

      h_Ele23_Ele12_leg1_pt_total->Fill(ele_pt->at(second)); 
      if(ele_pt->at(second)>25)h_Ele23_Ele12_leg1_eta_total->Fill(ele_etaSC->at(second)); 
      h_Ele23_Ele12_leg1_pt_eta_total->Fill(ele_etaSC->at(second),ele_pt->at(second)); 

      h_Ele23_Ele12_leg2_pt_total->Fill(ele_pt->at(second)); 
      if(ele_pt->at(second)>15)h_Ele23_Ele12_leg2_eta_total->Fill(ele_etaSC->at(second)); 
      h_Ele23_Ele12_leg2_pt_eta_total->Fill(ele_etaSC->at(second),ele_pt->at(second)); 
*/

/*

      if (passFilterEle25->at(second)){
      h_Ele25_pt_pass->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>33)h_Ele25_eta_pass->Fill(ele_etaSC->at(second));
      h_Ele25_pt_eta_pass->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (passFilterEle27->at(second)){
      h_Ele27_pt_pass->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>35)h_Ele27_eta_pass->Fill(ele_etaSC->at(second));
      h_Ele27_pt_eta_pass->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (passFilterEle32->at(second)){
      h_Ele32_PU_pass->Fill(nPV);
      h_Ele32_pt_pass->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (passFilterEle50->at(second)){
      h_Ele50_pt_pass->Fill(ele_pt->at(second)); 
      if(ele_pt->at(second)>58)h_Ele50_eta_pass->Fill(ele_etaSC->at(second)); 
      h_Ele50_pt_eta_pass->Fill(ele_etaSC->at(second),ele_pt->at(second)); 
      }
 
      if (passFilterEle115->at(second)){
      h_Ele115_pt_pass->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>123)h_Ele115_eta_pass->Fill(ele_etaSC->at(second));
      h_Ele115_pt_eta_pass->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (passFilterEle23_12_leg1->at(second)){
      h_Ele23_Ele12_leg1_pt_pass->Fill(ele_pt->at(second)); 
      if(ele_pt->at(second)>25)h_Ele23_Ele12_leg1_eta_pass->Fill(ele_etaSC->at(second)); 
      h_Ele23_Ele12_leg1_pt_eta_pass->Fill(ele_etaSC->at(second),ele_pt->at(second)); 
      } 
      if (passFilterEle23_12_leg2->at(second)){
      h_Ele23_Ele12_leg2_pt_pass->Fill(ele_pt->at(second)); 
      if(ele_pt->at(second)>15)h_Ele23_Ele12_leg2_eta_pass->Fill(ele_etaSC->at(second)); 
       h_Ele23_Ele12_leg2_pt_eta_pass->Fill(ele_etaSC->at(second),ele_pt->at(second)); 
      } 

*/
      if (pass32Filter_L1SingleEGOr){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter1->Fill(nPV);
      h_Ele32_pt_pass_filter1->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter1->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter1->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_32L1SingleEGOr){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter2->Fill(nPV);
      h_Ele32_pt_pass_filter2->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter2->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter4->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_ClusterShape){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter3->Fill(nPV);
      h_Ele32_pt_pass_filter3->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter3->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter3->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_HEFilter){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter4->Fill(nPV);
      h_Ele32_pt_pass_filter4->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter4->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter4->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_EcalIso){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter5->Fill(nPV);
      h_Ele32_pt_pass_filter5->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter5->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter5->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_HcalIso){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter6->Fill(nPV);
      h_Ele32_pt_pass_filter6->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter6->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter6->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_PixelMatch){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter7->Fill(nPV);
      h_Ele32_pt_pass_filter7->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter7->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter7->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_PMS2){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter8->Fill(nPV);
      h_Ele32_pt_pass_filter8->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter8->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter8->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_GsfOneOEMinusOneOP){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter9->Fill(nPV);
      h_Ele32_pt_pass_filter9->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter9->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter9->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_GsfMissingHits){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter10->Fill(nPV);
      h_Ele32_pt_pass_filter10->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter10->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter10->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_GsfDeta){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter11->Fill(nPV);
      h_Ele32_pt_pass_filter11->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter11->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter11->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_GsfDphi){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter12->Fill(nPV);
      h_Ele32_pt_pass_filter12->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter12->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter12->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_GsfTrackIso){
      if(ele_pt->at(second)>40)h_Ele32_PU_pass_filter13->Fill(nPV);
      h_Ele32_pt_pass_filter13->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass_filter13->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass_filter13->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }

      if (pass32Filter_GsfTrackIso){ //full trigger since last filter passes means passes full triger path.
      if(ele_pt->at(second)>40)h_Ele32_PU_pass->Fill(nPV);
      h_Ele32_pt_pass->Fill(ele_pt->at(second));
      if(ele_pt->at(second)>40)h_Ele32_eta_pass->Fill(ele_etaSC->at(second));
      h_Ele32_pt_eta_pass->Fill(ele_etaSC->at(second),ele_pt->at(second));
      }
      // if (Cut(ientry) < 0) continue;
    }
file->Write(); 
  }
 
}

bool TagAndProbe::HWW_Electron_NewDef(int i, double eta)
{
bool mvaid = false;
bool tightid = false;
bool mediumid= false;
//cout<<"sizes = "<<ele_full5x5_sigmaIetaIeta->size()<<ele_ooEmooP->size()<<endl;
//cout<<ele_passConversionVeto->size()<<ele_relCombIsoWithEA->size()<<endl;
double sieie = ele_full5x5_sigmaIetaIeta->at(i);
double eInvMinusPInv = ele_ooEmooP->at(i);
//bool convVeto = ele_passConversionVeto->at(i);
double relIso = ele_relCombIsoWithEA->at(i);
mvaid = passMVAIsoWP90->at(i);
tightid = passEleIdTight->at(i);
mediumid = passEleIdMedium->at(i);

if(fabs(eta) < 1.479){    // Barrel
//if (!convVeto) return false;
//if (relIso >= 0.06) return false;
//if (!mvaid) return false;
if (!tightid) return false;
//if (!mediumid) return false;
if (fabs(ele_d0->at(i))>=0.05) return false;
if (fabs(ele_dz->at(i))>=0.1) return false;
}

else{
//if (sieie >= 0.03) return false;
//if (fabs(eInvMinusPInv) >= 0.014) return false;
//if (!convVeto) return false;
//if (relIso >= 0.06) return false;
//if (!mvaid) return false;
if (!tightid) return false;
//if (!mediumid) return false;
if (fabs(ele_d0->at(i))>=0.1) return false;
if (fabs(ele_dz->at(i))>=0.2) return false;
}
return true;
}
