
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>

#include <TTree.h>
#include <TChain.h>
#include <TROOT.h>
#include <TFile.h>
#include <TH2.h>
#include <TH1F.h>
#include <TStyle.h>
#include <TCanvas.h>
#include <TVector2.h>
#include <TVector3.h>
#include <TAxis.h>

#include "myRealAnalysis.h"

using namespace std;
using namespace myAnalyzer;

int main(int argc, char* argv[]) {


      //================ Creating chain 
 

  //TFile* fin= new TFile("~/Documents/myRootWorkDir/provevarie/treeFromCmsrm/tree.root"); // don't need it
  
  TChain* chain =new TChain("tree/tree");

  //chain->Add("~/Documents/myRootWorkDir/provevarie/treeFromCmsrm/tree.root/tree/tree");  
  chain->Add("~/Analysis/trees/znunujets/tree.root");  

  for (Int_t i = 0; i < argc; i++) {
    std::cout<<"argv["<<i<<"] = "<<argv[i]<<std::endl;
  }

  std::cout<<chain->GetEntries()<<std::endl;      
  //================ Run Analysis

  myRealAnalysis tree( chain );
  tree.loop();
  
  //delete fin;
  delete chain;
  return 0;
}
