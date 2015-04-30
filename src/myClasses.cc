#include "myClasses.h"

#include <stdio.h>
#include <stdlib.h>
#include <cstdlib> //as stdlib.h
#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> //for input/output manipulators

#include <TAxis.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TChain.h>
#include <TFile.h>
#include <TH1F.h>
#include <TH2.h>
#include <TMath.h>
#include <TROOT.h>
#include <TStyle.h>
#include <TTree.h>
#include <TVector2.h>
#include <TVector3.h>

using namespace std;

//implementation of methods of class cut 

//static data members
Int_t cut::nCuts_ = 0;
vector<cut*> cut::listOfCuts; 

void cut::printCutFlow(ostream & myOutStream, const Int_t cutSteps, const UInt_t *singleCutMask) {

  //this function prints the cut flow on the appropriate ofstream (can be a file or cout). Since it's a member function of class cut, it only needs to get the number of cut steps. For now it needs the array of masks which is not a class data member yet

  myOutStream<<"**************************"<<endl;
  myOutStream<<"*          CUTS FLOW          *"<<endl;
  myOutStream<<"**************************"<<endl;
  myOutStream<<"-----------------------------------------------------------------------------------"<<endl;  
  myOutStream<<"Printing list of cuts applied at each step"<<endl;
  for (Int_t i = 0; i < cutSteps; i++) {
    myOutStream<<"-----------------------------------"<<endl;
    myOutStream<<setw(2)<<(i+1)<<endl;
    for (Int_t j = 0; j < cut::getNCuts(); j++) {
      if ((singleCutMask[i] >> j) & 1) {
	myOutStream<<"      ";
	cut::listOfCuts[j]->print(myOutStream,1); 
      }
    }
  }
  myOutStream<<"-----------------------------------"<<endl;  

}

void cut::printActiveCuts(ostream & myOutStream) {

  myOutStream<<"------------------------------------------------------------------------------------------"<<endl;
  myOutStream<<"Printing list of activated cuts"<<endl;
  myOutStream<<"------------------------------------------------------------------------------------------"<<endl;
  for (Int_t i = 0; i < cut::getNCuts(); i++ ) {
    if ( cut::listOfCuts[i]->isActive() ) {
      cut::listOfCuts[i]->printAllInfo(myOutStream);
    }
  }
  myOutStream<<"------------------------------------------------------------------------------------------"<<endl;

}

cut::cut(Bool_t flag, const char *cut_name, const char *var_name, const char *condition, const Double_t threshold, const string comment) {
  flag_ = flag;
  cut_ =cut_name;
  var_ = var_name;
  cond_ = condition;
  thr_ = threshold;
  comment_ = comment;
  id_ = nCuts_;
  twoToId_ = (UInt_t) TMath::Power(2.,id_);
  nCuts_++;
  listOfCuts.push_back(this);
}

cut::cut(Bool_t flag, const char *cut_name, const char *var_name, const char *condition, const Double_t threshold) {
  flag_ = flag;
  cut_ =cut_name;
  var_ = var_name;
  cond_ = condition;
  thr_ = threshold;
  comment_ = "";
  id_ = nCuts_;
  twoToId_ = (UInt_t) TMath::Power(2.,id_);
  nCuts_++;
  listOfCuts.push_back(this);
}

cut::cut(Bool_t flag, const char *cut_name, const char *var_name, const char *condition) {
  flag_ =flag;
  cut_ =cut_name;
  var_ = var_name;
  cond_ = condition;
  thr_ = 0.;
  comment_ = "";
  id_ = nCuts_;
  twoToId_ = (UInt_t) TMath::Power(2.,id_);
  nCuts_++;
  listOfCuts.push_back(this);
}

cut::cut(Bool_t flag, const char *cut_name, const char *var_name) {
  flag_ =flag;
  cut_ =cut_name;
  var_ = var_name;
  cond_ = " ";
  thr_ = 0.;
  comment_ = "";
  id_ = nCuts_;
  twoToId_ = (UInt_t) TMath::Power(2.,id_);
  nCuts_++;
  listOfCuts.push_back(this);
}

cut::~cut() {
  cout<<"~cut() called for "<<cut_<<endl;
  nCuts_--;
}

void cut::printAllInfo(ostream & myOutStream) const {

  myOutStream<<setw(18)<<left<<cut_<<": id = "<<setw(2)<<right<<id_<<" | "<<setw(18)<<left<<var_<<" "<<setw(2)<<cond_<<" ";
  myOutStream<<setw(4)<<right<<thr_<<"   "<<left<<comment_<<endl; 

 }

void cut::print(ostream & myOutStream = cout, Bool_t addComment = 0) const {

  //print cut definition on the right ofstream (cout is default), if addComment = 1, cut  comment is printed if any
  if (addComment) {
    myOutStream<<setw(18)<<left<<var_<<" "<<setw(2)<<cond_<<" "<<setw(4)<<right<<thr_<<"   "<<left<<comment_<<endl; 
  } else {
    myOutStream<<setw(18)<<left<<var_<<" "<<setw(2)<<cond_<<" "<<setw(4)<<right<<thr_<<endl; 
  }

 }

Bool_t cut::isPassed(Double_t input) {

  if (cond_ == "<") return (input < thr_) ? true : false;
  else if (cond_== ">") return (input > thr_) ? true : false;
  else if (cond_== "=") return (input == thr_) ? true : false;
  else if (cond_ == "<=") return (input <= thr_) ? true : false;
  else if (cond_ == ">=") return (input >= thr_) ? true : false;
  else {
    cout<<"Error in cut::isPassed()! No condition fulfilled."<<endl;
    cout<<"End of programme"<<endl;
    exit(EXIT_FAILURE);
  }

}


//----------------------------------------------------------------------------------
