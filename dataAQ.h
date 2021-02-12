#ifndef DATAAQ_H
#define DATAAQ_H

#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "stateDemog.h"
#include "stateHosp.h"
#include <memory>
#include <algorithm>
#include "comboDemogData.h"
#include "comboHospitalData.h"

using namespace std;
class dataAQ {
  public:
    dataAQ() {

    }
    void createStateDemogData(std::vector< shared_ptr<demogData> > theData){
      string state = "";
      for( shared_ptr<demogData> county: theData) {
        state = county->getState();
        //if true, key is not found
        if(allStateDemogData.count(state) == 0){
          allStateDemogData.insert(make_pair(state, make_shared<comboDemogData>(state, state))); //state and region names are the same
        }
        allStateDemogData.at(state)->addDemogtoRegion(county);
      }
    }
    
    void createStateHospData(std::vector<shared_ptr<hospitalData> > theData) {
      string state = "";
      for( shared_ptr<hospitalData> hosp: theData) {
        state = hosp->getState();
        //if true, key is not found
        if(allStateHospData.count(state) == 0){
          allStateHospData.insert(make_pair(state, make_shared<comboHospitalData>(state, state))); //state and region names are the same
        }
        allStateHospData.at(state)->addHospitaltoRegion(hosp);
      }
    }

    void createCountyHospData(std::vector<shared_ptr<hospitalData>>& theHospitalData) {}

    void sortHospRatingHighLow(vector<comboHospitalData*> &hospHighToLow) { 
        //adding elements from the hashmap to the vector
        for(map<string, shared_ptr<comboHospitalData>>::iterator i = allStateHospData.begin(); i != allStateHospData.end(); i++ ){
            hospHighToLow.push_back(&(*i->second));
        }
        sort(hospHighToLow.begin(), hospHighToLow.end(), &comboHospitalData::compareOV);
        //reverse
        reverse(hospHighToLow.begin(), hospHighToLow.end());
    }
    void sortHospRatingLowHigh(vector<comboHospitalData*> &hospLowToHigh) {
        for(map<string, shared_ptr<comboHospitalData>>::iterator i = allStateHospData.begin(); i != allStateHospData.end(); i++ ){
            hospLowToHigh.push_back(&(*i->second));
        }
       sort(hospLowToHigh.begin(), hospLowToHigh.end(), &comboHospitalData::compareOV);
    }
    void sortHospRatingHighLowForState(vector<comboHospitalData*>& hospHighToLow, string state) {
    
    }

    void read_csvCityCounty(std::string filename) {}

    map < string, shared_ptr <comboDemogData>> allStateDemogData;
    map<string, shared_ptr<comboHospitalData>> allStateHospData;

    //map for county hospital data
    std::map<string, comboHospitalData*> allCountyHData;

    //helper to create aggregates from city -> county
    std::map<string, string> cityToCounty;
 };
 #endif