
#include "comboHospitalData.h"
#include <sstream>
#include <string>
#include <assert.h>


void comboHospitalData::addHospitaltoRegion(shared_ptr<hospitalData> HI) {
	if (counties.size() == 0) {
		type = HI->type;
	}
	overallrate = overallrate * counties.size() + HI->overallrate;
	mortality = mortality * counties.size() + HI->overallrate;
	readmit *= counties.size();
	readmit += HI->readmit;

	counties.push_back(HI);
	overallrate /= counties.size();
	mortality /= counties.size();
	readmit /= counties.size();
}
