#ifndef COMBOD_H
#define COMBOD_H

#include <memory>
#include <string>
#include <iostream>
#include "demogData.h"
#include "placeData.h"
#include <vector>

using namespace std;

/*
  aggregated demographic data for a given regional level (state - or larger region)
*/
class comboDemogData : public demogData  {
public:
	comboDemogData(string r, string s) : demogData(r, s) {}
	void addDemogtoRegion(shared_ptr<demogData> CD);
	string getRegion() {
		return name;
	}

	vector<shared_ptr<demogData>> counties;
};
#endif
