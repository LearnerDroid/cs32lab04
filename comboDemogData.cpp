#include "comboDemogData.h"
#include "demogData.h"
#include <sstream>
#include <string>
#include <assert.h>
#include <iomanip>


void comboDemogData::addDemogtoRegion(shared_ptr<demogData> CD) {
	popOver65 = popOver65 * totalPop + CD->popOver65 * CD->totalPop;
	popUnder18 = popUnder18 * totalPop + CD->popUnder18 * CD->totalPop;
	popUnder5 = popUnder5* totalPop + CD->popUnder5 * CD->totalPop;
	percentUndergraduate = percentUndergraduate * totalPop + CD->percentUndergraduate * CD->totalPop;
	percentHighSchool = percentHighSchool * totalPop + CD->percentHighSchool * CD->totalPop;
	belowPoverty = belowPoverty * totalPop + CD->belowPoverty * CD->totalPop;

	totalPop += CD->totalPop;
	popOver65 /= totalPop;
	popUnder18 /= totalPop;
	popUnder5 /= totalPop;
	percentUndergraduate /= totalPop;
	percentHighSchool /= totalPop;
	belowPoverty /= totalPop;

	counties.push_back(CD);
}