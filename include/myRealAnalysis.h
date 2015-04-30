#ifndef my_Real_Analysis_h
#define my_Real_Analysis_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TTree.h>

#include <iostream>
#include <cstdlib>

#include "Analysis.h"

namespace myAnalyzer {

  class myRealAnalysis : public Analysis {
  public:

    myRealAnalysis(TTree *tree);
    virtual ~myRealAnalysis() { std::cout<<"~myRealAnalysis() called"<<std::endl; }
  
    void loop();

  };

}
#endif

/* #ifdef myRealAnalysis_cxx */

/* myRealAnalysis::myRealAnalysis(TTree *tree) : Analysis(tree) { */

/*   Analysis::Init(tree); */

/* } */

/* #endif */



