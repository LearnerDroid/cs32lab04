#ifndef COMBOH_H
#define COMBOH_H

#include <memory>
#include <string>
#include <iostream>
#include "hospitalData.h"
#include <vector>

using namespace std;

/*
  aggregated hospital data for a given regional level (county or state)
*/
class comboHospitalData : public hospitalData {
public:
	comboHospitalData(string r, string s) : hospitalData(r, s) {}
	void addHospitaltoRegion(shared_ptr<hospitalData> HI);
	string getRegion() {
		return name;
	}
	static bool compareOV(comboHospitalData* ph1, comboHospitalData* ph2) { return ph1->overallrate < ph2->overallrate; }
	vector<shared_ptr<hospitalData>> counties;
};
#endif