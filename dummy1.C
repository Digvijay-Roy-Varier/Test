#include <iostream>

void test(){
  TFile *f = new TFile("muons105.root");
  TTree *t = (TTree*) f->Get("makeSD/sdiag");
  TH1F *h1 = new TH1F("h1","h1",50,-0.001,0.03);
  //t->Draw("steplen");
  t->Project("h1","stepE/steplen");
  TFile *f2 = new TFile("electrons105.root");
  TTree *t2 = (TTree*) f2->Get("makeSD/sdiag");

  TH1F *h2 = new TH1F("h2","practice2",50,-0.001,0.03);
  t2->Project("h2","stepE/steplen");
  h1->Scale(1.0/h1->Integral());
  h2->Scale(1.0/h2->Integral());
  h1->Draw("HIST");
  h2->Draw("HIST Same"); 
  h1->SetLineColor(010);
  h1->SetAxisRange(0,0.001,"Y");
  TLegend *legend = new TLegend(0.6,0.7,0.9,0.9);
  legend->SetHeader("muon v electron","C");
  legend->AddEntry("h1","muon dE/dX","l");
  legend->AddEntry("h2","electron dE/dX","l");
  legend->Draw();
  
  TTree *t3 = (TTree*) f->Get("SHD/shdiag");
  TH1F *h3 = new TH1F("h3","h3",50,-0.001,0.005);
  t3->Project("h3","mcedep/sqrt(pow(2.5,2)-pow(mcshd,2))","mcpdg==13 && mcproc ==56 && mcom<110 && mcom>80");
  TCanvas *c1 = new TCanvas("c1","response");
  h3->Scale(1.0/h3->Integral());
  h3->Draw("HIST");
  //t3->Draw("mcedep/sqrt(pow(2.5,2)-pow(mcshd,2))","mcpdg==13 && mcproc ==56 && 80<mcom<110");
  TTree *t4 = (TTree*) f2->Get("SHD/shdiag");
  TH1F *h4 = new TH1F("h4","h4",50,-0.001,0.005);
  t4->Project("h4","mcedep/sqrt(pow(2.5,2)-pow(mcshd,2))","mcpdg==11 && mcproc ==56 && mcom<110 && mcom>80");
  h4->Scale(1.0/h4->Integral());
  h4->Draw("HIST Same");
  h3->SetLineColor(kRed);
  // 4->SetLineColor(100);
  TLegend *legend2 = new TLegend(0.6,0.7,0.9,0.9);
  legend2->SetHeader("muon v electron response","C");
  legend2->AddEntry("h3","muon dE/dX","l");
  legend2->AddEntry("h4","electron dE/dX","l");
  legend2->Draw();
    }
   



  //TFile *f = new TFile("electrons_protons.root");
  //TTree *t3 = (TTree*) f->Get("SHD/shdiag");
  //TH1F *h3 = new TH1F("h3","h3",50,-0.001,0.005);
  //t3->Project("h3","mcedep/sqrt(pow(2.5,2)-pow(mcshd,2))","mcpdg==2212");
  //TCanvas *c1 = new TCanvas("c1","response");
  //h3->Scale(1.0/h3->Integral());
  //h3->Draw("HIST");
  //TH1F *h4 = new TH1F("h4","h4",50,-0.001,0.005);
  //t3->Project("h4","mcedep/sqrt(pow(2.5,2)-pow(mcshd,2))","mcpdg==11 && mcproc==56 && mcom>80 && mcom < 110");
  //h4->Scale(1.0/h4->Integral());
  //h4->Draw("HIST Same");
  //h3->SetLineColor(kRed);
  //h4->SetLineColor(100);
  //}






