#ifndef MyClasses_h
#define MyClasses_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>

class cut {

public:
  cut(Bool_t flag, const char *cut_name, const char *var_name, const char *condition, const Double_t threshold, const std::string comment);
  cut(Bool_t flag, const char *cut_name, const char *var_name, const char *condition, const Double_t threshold);
  cut(Bool_t flag, const char *cut_name, const char *var_name, const char *condition);
  cut(Bool_t flag, const char *cut_name, const char *var_name);
   ~cut();
   // setters
   std::string getCutDefinition() { return var_ + " " + cond_ + " " + Form("%4.1lf",thr_); }
   void setFlagTrue() { flag_ = true; }
   void setFlagFalse() { flag_ = false; }
   void setCondition(std::string condition) { cond_ = condition; }
   void setThreshold(Double_t thr) { thr_ = thr; }
   // getters
   std::string getCutName() const { return cut_; }
   std::string getVarName() const { return var_; }
   std::string getCondition() const { return cond_; }
   Double_t getThreshold() const { return thr_; }
   Int_t getId() const { return id_; }
   UInt_t get2ToId() const { return twoToId_; }
   // other member functions
   void print(ostream &, Bool_t) const;
   void printAllInfo(ostream &) const;
   Bool_t isPassed(Double_t input);
   UInt_t addToMask(Double_t input) {return (this->isPassed(input)) ? (this->get2ToId()) : 0; }
   Bool_t isActive() const { return flag_; }

   static Int_t getNCuts() { return nCuts_; }
   static std::vector<cut*> listOfCuts;
   static void printCutFlow(ostream &, const Int_t, const UInt_t *);
   static void printActiveCuts(ostream &);

private:
   Bool_t flag_;
   std::string cut_;
   std::string var_;
   std::string cond_;
   //std::string thr_;
   Double_t thr_;
   std::string comment_;
   Int_t id_;          //identifies cut in the mask (is 0 for the first cut, 1 for the second, 2 for the third ecc...)
   UInt_t twoToId_;
   static Int_t nCuts_; // total number of variables on which a cut is applied (or now, if I need different thresholds for the same variable, each one counts as a different cut

};


#endif 
