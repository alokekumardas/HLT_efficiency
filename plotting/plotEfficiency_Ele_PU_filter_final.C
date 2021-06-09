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
#include <TMultiGraph.h>
using namespace std;
void plotEfficiency_Ele_PU_filter_final(TString rootfileName,TString rootfileName2, TString Output,TString filterName){

//TFile *f1 = TFile::Open("filterEff_TT_PU30to80_efficiency_tightid_nominal.root");
TFile *f1 = TFile::Open(rootfileName);
TFile *f2 = TFile::Open(rootfileName2);
std::cout<<" input file ="<<rootfileName<<std::endl;
std::cout<<" input file ="<<rootfileName2<<std::endl;

   TH1F *h_total_Run2_2018_PU,*h_total_Run2_2018_pt,*h_total_Run2_2018_eta, *h_total_Run2_2018_pt_eta; 
   TH1F *h_pass_Run2_2018_PU,*h_pass_Run2_2018_pt,*h_pass_Run2_2018_eta, *h_pass_Run2_2018_pt_eta; 
  
   TH1F *h_total_Run3_PU,*h_total_Run3_pt,*h_total_Run3_eta, *h_total_Run3_pt_eta; 
   TH1F *h_pass_Run3_PU,*h_pass_Run3_pt,*h_pass_Run3_eta, *h_pass_Run3_pt_eta; 

   TGraphAsymmErrors *graph_Run2_2018_PU=0;
   TGraphAsymmErrors *graph_Run2_2018_pt=0;
   TGraphAsymmErrors *graph_Run2_2018_eta=0;

   TGraphAsymmErrors *graph_Run3_PU=0;
   TGraphAsymmErrors *graph_Run3_pt=0;
   TGraphAsymmErrors *graph_Run3_eta=0;
//   TGraphAsymmErrors *graph_pt_eta=0;

   TString filtertemp;
 if (filterName== "hltEGL1SingleEGOrFilter") filtertemp = "_filter1";
 else if (filterName== "hltEG32L1SingleEGOrEtFilter") filtertemp = "_filter2";
 else if (filterName== "hltEle32WPTightClusterShapeFilter") filtertemp = "_filter3";
 else if (filterName== "hltEle32WPTightHEFilter") filtertemp = "_filter4";
 else if (filterName== "hltEle32WPTightEcalIsoFilter") filtertemp = "_filter5";
 else if (filterName== "hltEle32WPTightHcalIsoFilter") filtertemp = "_filter6";
 else if (filterName== "hltEle32WPTightPixelMatchFilter") filtertemp = "_filter7";
 else if (filterName== "hltEle32WPTightPMS2Filter") filtertemp = "_filter8";
 else if (filterName== "hltEle32WPTightGsfOneOEMinusOneOPFilter") filtertemp = "_filter9";
 else if (filterName== "hltEle32WPTightGsfMissingHitsFilter") filtertemp = "_filter10";
 else if (filterName== "hltEle32WPTightGsfDetaFilter") filtertemp = "_filter11";
 else if (filterName== "hltEle32WPTightGsfDphiFilter") filtertemp = "_filter12";
 else if (filterName== "hltEle32WPTightGsfTrackIsoFilter") filtertemp = "_filter13";
 else if (filterName=="HLT_Ele32_WPTight_Gsf") filtertemp="";

 std::cout<<"filter temp = "<<filtertemp<<std::endl;
  h_total_Run2_2018_PU = (TH1F*)f1->Get("Ele32_PU_total"+filtertemp);
  h_total_Run2_2018_pt = (TH1F*)f1->Get("Ele32_pt_total"+filtertemp);
  h_total_Run2_2018_eta = (TH1F*)f1->Get("Ele32_eta_total"+filtertemp);
//  h_total_Run2_2018_pt_eta = (TH1F*)f1->Get("Ele32_pt_eta_total_"+filtertemp);

  h_pass_Run2_2018_PU = (TH1F*)f1->Get("Ele32_PU_pass"+filtertemp);
  h_pass_Run2_2018_pt = (TH1F*)f1->Get("Ele32_pt_pass"+filtertemp);
  h_pass_Run2_2018_eta = (TH1F*)f1->Get("Ele32_eta_pass"+filtertemp);
//  h_pass_Run2_2018_pt_eta = (TH1F*)f1->Get("Ele32_pt_eta_pass_"+filtertemp);

  h_total_Run3_PU = (TH1F*)f2->Get("Ele32_PU_total"+filtertemp);
  h_total_Run3_pt = (TH1F*)f2->Get("Ele32_pt_total"+filtertemp);
  h_total_Run3_eta = (TH1F*)f2->Get("Ele32_eta_total"+filtertemp);
//  h_total_Run3_pt_eta = (TH1F*)f1->Get("Ele32_pt_eta_total_"+filtertemp);

  h_pass_Run3_PU = (TH1F*)f2->Get("Ele32_PU_pass"+filtertemp);
  h_pass_Run3_pt = (TH1F*)f2->Get("Ele32_pt_pass"+filtertemp);
  h_pass_Run3_eta = (TH1F*)f2->Get("Ele32_eta_pass"+filtertemp);
//  h_pass_Run3_pt_eta = (TH1F*)f1->Get("Ele32_pt_eta_pass_"+filtertemp);


  TMultiGraph *mg = new TMultiGraph();
  TMultiGraph *mg2 = new TMultiGraph();
  TMultiGraph *mg3 = new TMultiGraph();
    graph_Run2_2018_PU= new TGraphAsymmErrors(h_pass_Run2_2018_PU,h_total_Run2_2018_PU);
    graph_Run2_2018_pt= new TGraphAsymmErrors(h_pass_Run2_2018_pt,h_total_Run2_2018_pt);
    graph_Run2_2018_eta= new TGraphAsymmErrors(h_pass_Run2_2018_eta,h_total_Run2_2018_eta);
//    graph_Run2_2018_pt_eta= new TGraphAsymmErrors(h_pass_Run2_2018_pt_eta,h_total_Run2_2018_pt_eta);
    graph_Run2_2018_pt->GetXaxis()->SetTitle("p_T");
    graph_Run2_2018_PU->GetXaxis()->SetTitle("PU");
    graph_Run2_2018_eta->GetXaxis()->SetTitle("#eta");

    graph_Run2_2018_pt->GetYaxis()->SetTitle("Efficiency");
    graph_Run2_2018_PU->GetYaxis()->SetTitle("Efficiency");
    graph_Run2_2018_eta->GetYaxis()->SetTitle("Efficiency");

   graph_Run2_2018_pt->SetTitle(filterName);
   graph_Run2_2018_PU->SetTitle(filterName);
   graph_Run2_2018_eta->SetTitle(filterName);

    graph_Run3_PU= new TGraphAsymmErrors(h_pass_Run3_PU,h_total_Run3_PU);
    graph_Run3_pt= new TGraphAsymmErrors(h_pass_Run3_pt,h_total_Run3_pt);
    graph_Run3_eta= new TGraphAsymmErrors(h_pass_Run3_eta,h_total_Run3_eta);
//    graph_Run3_pt_eta= new TGraphAsymmErrors(h_pass_Run3_pt_eta,h_total_Run3_pt_eta);
    graph_Run3_PU->GetXaxis()->SetTitle("PU");
    graph_Run3_pt->GetXaxis()->SetTitle("p_T");
    graph_Run3_eta->GetXaxis()->SetTitle("#eta");

    graph_Run3_PU->GetYaxis()->SetTitle("Efficiency");
    graph_Run3_pt->GetYaxis()->SetTitle("Efficiency");
    graph_Run3_eta->GetYaxis()->SetTitle("Efficiency");

   graph_Run3_PU->SetTitle(filterName);
   graph_Run3_pt->SetTitle(filterName);
   graph_Run3_eta->SetTitle(filterName);

   graph_Run3_PU->SetLineColor(kRed);
   graph_Run3_pt->SetLineColor(kRed);
   graph_Run3_eta->SetLineColor(kRed);
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


  mg->SetTitle(h_total_Run2_2018_2018A->GetTitle());
*/
 //TLegend *legend = new TLegend(0.1,0.7,0.48,0.9);
 // legend->AddEntry(graph_Run2_2018_PU,"Run2_2018","l");
 // legend->AddEntry(graph_Run3_PU,"Run3","l");

  TCanvas *c = new TCanvas("c","Efficiency",1800,500);
////////////////////////////
   TPad *pad1 = new TPad("pad1", "pad1", 0, 0.2, 0.3, 1.0);
   pad1->SetBottomMargin(0); // Upper and lower plot are joined
   pad1->Draw();             // Draw the upper pad: pad1
   pad1->cd();               // pad1 becomes the current pad
//  c->Divide(3,1);
 // c->cd(1);
   mg->Add(graph_Run2_2018_PU);
   mg->Add(graph_Run3_PU);
   mg->GetXaxis()->SetTitle("PU");
   mg->GetYaxis()->SetTitle("Efficiency");
   mg->GetHistogram()->GetYaxis()->SetRangeUser(0.,1.2);
  //   mg->SetTitle(filterName);
   mg->Draw("APE");
   // legend->Draw("same");
  c->cd();
   TPad *pad12 = new TPad("pad12", "pad12", 0, 0.05, 0.3, 0.2);
   pad12->SetBottomMargin(0.2); // Upper and lower plot are joined
   pad12->SetTopMargin(0); // Upper and lower plot are joined
   pad12->Draw();             // Draw the upper pad: pad1
   pad12->cd();               // pad1 becomes the current pad
   TH1F *rpPU = graph_Run2_2018_PU->GetHistogram();
   rpPU->Divide(graph_Run3_PU->GetHistogram());
   rpPU->SetMinimum(0.5);
   rpPU->SetMaximum(1.5);
   rpPU->Draw("hist");
  
   rpPU->GetYaxis()->SetTitle("");
   rpPU->GetYaxis()->SetTitleSize(15);
   rpPU->GetYaxis()->SetTitleFont(43);
   rpPU->GetYaxis()->SetTitleOffset(1.55);
   rpPU->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   rpPU->GetYaxis()->SetLabelSize(15);

   rpPU->GetXaxis()->SetTitleSize(15);
   rpPU->GetXaxis()->SetTitleFont(43);
   rpPU->GetXaxis()->SetTitleOffset(4);
   rpPU->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   rpPU->GetXaxis()->SetLabelSize(15);

//////////////////////////////////////////////////   
   c->cd();
   TPad *pad2 = new TPad("pad2", "pad2", 0.33, 0.2, 0.63, 1.0);
   pad2->SetBottomMargin(0); // Upper and lower plot are joined
   pad2->Draw();             // Draw the upper pad: pad1
   pad2->cd();               // pad1 becomes the current pad
//  c->Divide(3,1);
 // c->cd(1);
   mg2->Add(graph_Run2_2018_pt);
   mg2->Add(graph_Run3_pt);
   mg2->GetXaxis()->SetTitle("p_{T}");
   mg2->GetYaxis()->SetTitle("Efficiency");
   mg2->GetHistogram()->GetYaxis()->SetRangeUser(0.,1.2);
  //   mg->SetTitle(filterName);
   mg2->Draw("APE");
   // legend->Draw("same");

  c->cd();
   TPad *pad22 = new TPad("pad22", "pad22", 0.33, 0.05, 0.63, 0.2);
   pad22->SetBottomMargin(0.2); // Upper and lower plot are joined
   pad22->SetTopMargin(0); // Upper and lower plot are joined
   pad22->Draw();             // Draw the upper pad: pad1
   pad22->cd();               // pad1 becomes the current pad
   TH1F *rppt = (TH1F*)graph_Run2_2018_pt->GetHistogram();
   rppt->Divide(graph_Run3_pt->GetHistogram());
   rppt->SetMinimum(0.7);
   rppt->SetMaximum(1.2);
   rppt->Draw();
   rppt->GetYaxis()->SetTitle("");
   rppt->GetYaxis()->SetTitleSize(15);
   rppt->GetYaxis()->SetTitleFont(43);
   rppt->GetYaxis()->SetTitleOffset(1.55);
   rppt->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   rppt->GetYaxis()->SetLabelSize(15);

   rppt->GetXaxis()->SetTitleSize(15);
   rppt->GetXaxis()->SetTitleFont(43);
   rppt->GetXaxis()->SetTitleOffset(4);
   rppt->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   rppt->GetXaxis()->SetLabelSize(15);
///////////////////////////////////
   c->cd();
   TPad *pad3 = new TPad("pad3", "pad3", 0.66, 0.2, 1.0, 1.0);
   pad3->SetBottomMargin(0); // Upper and lower plot are joined
  // pad3->SetGridx();         // Vertical grid
   pad3->Draw();             // Draw the upper pad: pad1
   pad3->cd();               // pad1 becomes the current pad
//  c->Divide(3,1);
 // c->cd(1);
   mg3->Add(graph_Run2_2018_eta);
   mg3->Add(graph_Run3_eta);
   mg3->GetXaxis()->SetTitle("#eta");
   mg3->GetYaxis()->SetTitle("Efficiency");
   mg3->GetHistogram()->GetYaxis()->SetRangeUser(0.,1.2);
  //   mg->SetTitle(filterName);
   mg3->Draw("APE");
   // legend->Draw("same");

  c->cd();
   TPad *pad32 = new TPad("pad32", "pad32", 0.66, 0.05, 1.0, 0.2);
   pad32->SetTopMargin(0); // Upper and lower plot are joined
   pad32->SetBottomMargin(0.2); // Upper and lower plot are joined
 //  pad22->SetGridx();         // Vertical grid
   pad32->Draw();             // Draw the upper pad: pad1
   pad32->cd();               // pad1 becomes the current pad
   TH1F *rpeta = (TH1F*)graph_Run2_2018_eta->GetHistogram();
   rpeta->Divide(graph_Run3_eta->GetHistogram());
   rpeta->SetMinimum(0.7);
   rpeta->SetMaximum(1.2);
   rpeta->Draw();
   rpeta->GetYaxis()->SetTitle("");
   rpeta->GetYaxis()->SetTitleSize(15);
   rpeta->GetYaxis()->SetTitleFont(43);
   rpeta->GetYaxis()->SetTitleOffset(1.55);
   rpeta->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   rpeta->GetYaxis()->SetLabelSize(15);

   rpeta->GetXaxis()->SetTitleSize(15);
   rpeta->GetXaxis()->SetTitleFont(43);
   rpeta->GetXaxis()->SetTitleOffset(4);
   rpeta->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
   rpeta->GetXaxis()->SetLabelSize(15);
  


  //c->SaveAs("efficiency_TT_PU30to70_hltEGL1SingleEGOrFilter.pdf");
  c->SaveAs("efficiency_" + Output + "_" + filterName + ".pdf");
  c->Print("efficiency_" + Output + "_" + filterName + ".ps");
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
TString filtername,rootfile,rootfile2,output;
rootfile=av[1];
rootfile2=av[2];
output=av[3];
filtername=av[4];
plotEfficiency_Ele_PU_filter_final(rootfile,rootfile2,output,filtername);
return 0;
}

