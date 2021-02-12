#ifndef DEMOG_H
#define DEMOG_H

#include <string>
#include <iostream>
#include "placeData.h"

using namespace std;

/*
  class to represent county demographic data
  from CORGIS
*/
class demogData : public placeData{
  public:
    demogData(string inN, string inS, double in65, double in18,
        double in5, double tPop) :
            placeData(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), percentUndergraduate(-1), percentHighSchool(-1), totalPop(tPop), belowPoverty(0) {
    } 

    demogData(string inN, string inS, double in65, double in18,
        double in5, double percU, double percH, double tPop, double bp) :
            placeData(inN), state(inS), popOver65(in65), popUnder18(in18),
            popUnder5(in5), percentUndergraduate(percU), percentHighSchool(percH), totalPop(tPop), belowPoverty(bp) {
    }

    demogData(demogData &d) : placeData(d.name), state(d.state), popOver65(d.popOver65), popUnder18(d.popUnder18),
        popUnder5(d.popUnder5), percentUndergraduate(d.percentUndergraduate), percentHighSchool(d.percentHighSchool), totalPop(d.totalPop), belowPoverty(d.belowPoverty) {
    }

    demogData(string name, string s) : placeData(name), state(s), popOver65(0), popUnder18(0),
        popUnder5(0), percentUndergraduate(0), percentHighSchool(0), totalPop(0), belowPoverty(0) {}

    //string getName() { return name; }

    double getBAup() { return percentUndergraduate; }

    double getHSup() { return percentHighSchool; }

    string getState() { return state; }

    double getpopOver65() { return popOver65; }

    double getpopUnder18() { return popUnder18; }

    double getpopUnder5() { return popUnder5; }

    double getTotalPop() { return totalPop; }

    double getBelowPoverty() { return belowPoverty; }

   friend std::ostream& operator<<(std::ostream &out, const demogData &DD);

    //all these are proportions, except for totalPop
    const string state;
    double popOver65;
    double popUnder18;
    double popUnder5;
    double percentUndergraduate;
    double percentHighSchool;
    double totalPop;
    double belowPoverty;
};
#endif
