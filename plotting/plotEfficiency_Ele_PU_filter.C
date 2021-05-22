#include "TGraphAsymmErrors.h"
#include <TH1.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TRatioPlot.h>
#include <stdio.h>
#include <iostream>
#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
using namespace std;
void plotEfficiency_Ele_PU_filter(TString rootfileName, TString Output,TString filterName){

//TFile *f1 = TFile::Open("filterEff_TT_PU30to80_efficiency_tightid_nominal.root");
TFile *f1 = TFile::Open(rootfileName);
std::cout<<" input file ="<<rootfileName<<std::endl;

   TH1F *h_total_PU,*h_total_pt,*h_total_eta, *h_total_pt_eta; 
   TH1F *h_pass_PU,*h_pass_pt,*h_pass_eta, *h_pass_pt_eta; 
  
   TGraphAsymmErrors *graph_PU=0;
   TGraphAsymmErrors *graph_pt=0;
   TGraphAsymmErrors *graph_eta=0;
//   TGraphAsymmErrors *graph_pt_eta=0;

   TString filtertemp;
 if (filterName== "hltEGL1SingleEGOrFilter") filtertemp = "filter1";
 if (filterName== "hltEG32L1SingleEGOrEtFilter") filtertemp = "filter2";
 if (filterName== "hltEle32WPTightClusterShapeFilter") filtertemp = "filter3";
 if (filterName== "hltEle32WPTightHEFilter") filtertemp = "filter4";
 if (filterName== "hltEle32WPTightEcalIsoFilter") filtertemp = "filter5";
 if (filterName== "hltEle32WPTightHcalIsoFilter") filtertemp = "filter6";
 if (filterName== "hltEle32WPTightPixelMatchFilter") filtertemp = "filter7";
 if (filterName== "hltEle32WPTightPMS2Filter") filtertemp = "filter8";
 if (filterName== "hltEle32WPTightGsfOneOEMinusOneOPFilter") filtertemp = "filter9";
 if (filterName== "hltEle32WPTightGsfMissingHitsFilter") filtertemp = "filter10";
 if (filterName== "hltEle32WPTightGsfDetaFilter") filtertemp = "filter11";
 if (filterName== "hltEle32WPTightGsfDphiFilter") filtertemp = "filter12";
 if (filterName== "hltEle32WPTightGsfTrackIsoFilter") filtertemp = "filter13";
 std::cout<<"filter temp = "<<filtertemp<<std::endl;
  h_total_PU = (TH1F*)f1->Get("Ele32_PU_total_"+filtertemp);
  h_total_pt = (TH1F*)f1->Get("Ele32_pt_total_"+filtertemp);
  h_total_eta = (TH1F*)f1->Get("Ele32_eta_total_"+filtertemp);
//  h_total_pt_eta = (TH1F*)f1->Get("Ele32_pt_eta_total_"+filtertemp);

  h_pass_PU = (TH1F*)f1->Get("Ele32_PU_pass_"+filtertemp);
  h_pass_pt = (TH1F*)f1->Get("Ele32_pt_pass_"+filtertemp);
  h_pass_eta = (TH1F*)f1->Get("Ele32_eta_pass_"+filtertemp);
//  h_pass_pt_eta = (TH1F*)f1->Get("Ele32_pt_eta_pass_"+filtertemp);


    graph_PU= new TGraphAsymmErrors(h_pass_PU,h_total_PU);
    graph_pt= new TGraphAsymmErrors(h_pass_pt,h_total_pt);
    graph_eta= new TGraphAsymmErrors(h_pass_eta,h_total_eta);
//    graph_pt_eta= new TGraphAsymmErrors(h_pass_pt_eta,h_total_pt_eta);
    graph_pt->GetXaxis()->SetTitle("p_T");
    graph_PU->GetXaxis()->SetTitle("PU");
    graph_eta->GetXaxis()->SetTitle("#eta");

    graph_pt->GetYaxis()->SetTitle("Efficiency");
    graph_PU->GetYaxis()->SetTitle("Efficiency");
    graph_eta->GetYaxis()->SetTitle("Efficiency");

   graph_pt->SetTitle(filterName);
   graph_PU->SetTitle(filterName);
   graph_eta->SetTitle(filterName);

/*

  gra_2018A->SetLineColor(1);
  gra_2018B->SetLineColor(2);
  gra_2018C->SetLineColor(3);

  gra_2018A->SetMarkerStyle(20);
  gra_2018B->SetMarkerStyle(20);
  gra_2018C->SetMarkerStyle(20);

  gra_2018A->SetMarkerColor(1);
  gra_2018B->SetMarkerColor(2);
  gra_2018C->SetMarkerColor(3);


  mg->SetTitle(h_total_2018A->GetTitle());
*/
  TCanvas *c = new TCanvas("c","Efficiency",200,10,1800,500);
  c->Divide(3,1);
  c->cd(1);
      graph_PU->Draw("APE");
  c->cd(2);
      graph_pt->Draw("APE");
  c->cd(3);
      graph_eta->Draw("APE");

  //c->SaveAs("efficiency_TT_PU30to70_hltEGL1SingleEGOrFilter.pdf");
  c->SaveAs("efficiency_" + Output + "_" + filterName + ".pdf");
  c->Clear();
  delete c;
/*
//  c->SetLogx();
  mg->Draw("APE");
  mg->SetMinimum(0.2);
  mg->SetMaximum(1.02);
  mg->GetXaxis()->CenterTitle(1);
  mg->GetXaxis()->SetTitleOffset(1.2);
  mg->GetYaxis()->CenterTitle(1);
  mg->GetYaxis()->SetTitleOffset(1.4);

   TLegend *legend = new TLegend(0.5,0.3,0.7,0.5);
   legend->AddEntry(gra_2018A,"2018","p");
   legend->AddEntry(gra_2018B,"2021","p");
//   legend->AddEntry(gra_2018C,"2023","p");
   legend->Draw();

  TString pngFileName = trigger_name.Data() ;
  pngFileName +=  "_efficiency.png";
  c->SaveAs(pngFileName.Data());
  c->Clear();
//  gSystem->Exec("mkdir -p results_Ele");
//  TString dirName = "results_Ele/";
//  dirName+=trigger_name.Data();
 // gSystem->Exec("mkdir -p  "+ dirName);
//  gSystem->Exec("mv " + trigger_name+"*.png  "+dirName);
*/

}// end of program
int main(int ac, char** av){
gROOT->SetBatch(true);
TString filtername,rootfile,output;
rootfile=av[1];
output=av[2];
filtername=av[3];
plotEfficiency_Ele_PU_filter(rootfile,output,filtername);
return 0;
}

