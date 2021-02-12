#ifndef HOSP_H
#define HOSP_H

#include <string>
#include <iostream>
#include <utility>
#include "rating.h"
#include "placeData.h"

using namespace std;

/*
  class to represent hospital data
  from CORGIS
*/
class hospitalData : public placeData{
  public:
	 //constructor for starting code - make complete by adding rating
    hospitalData(string inN, string inS, string inType) :
            placeData(inN), state(inS), type(inType), overallrate(-1), mortality(-1), readmit(-1) {}
    hospitalData(string inN, string inS, string inType, int o, rating m, rating r) :
            placeData(inN), state(inS), type(inType), overallrate(o), mortality(m), readmit(r){
    }
    hospitalData(hospitalData& h) : placeData(h.name), state(h.state), type(h.type), overallrate(h.overallrate), mortality(h.mortality), readmit(h.readmit) {}
    hospitalData(string name, string st) : placeData(name), state(st), type("region"), overallrate(0), mortality(), readmit() {}
    //string getName() const { return name; }
    string getState() const { return state; }
    string getType() const { return type; }
    int getOverallRate() const { return overallrate; }
    rating getMortality() const { return mortality; }
    rating getReadmit() const { return readmit; }

   friend std::ostream& operator<<(std::ostream &out, const hospitalData &HD);


    //const string name;
    string state;
    string type;
    int overallrate;
    rating mortality;
    rating readmit;

};

#endif
