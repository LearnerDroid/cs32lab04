#include "demogData.h"
#include <sstream>

/* print county demographic data */
std::ostream& operator<<(std::ostream &out, demogData &DD) {
    /*
    out << "County Demographics Info: " << DD.getName()<< ", " << DD.getState();
    out << "\nPopulation info: \n(\% over 65): " << DD.getpopOver65();
    out << "\n(\% under 18): " << DD.getpopUnder18();
    out << "\n(\% under 5): " << DD.getpopUnder5();
    out << "\nEducation info: \n(\% Bachelor degree or more): " << DD.getBAup();
    out << "\n(\% high school or more): " << DD.getHSup();
    out << "\nTotal Population: " << DD.getTotalPop();
    out << "\nProportion under the poverty line: " << DD.getBelowPoverty();
    */
    out  << DD.getName() << ", " << DD.getState() << ", " << DD.getTotalPop();
    return out;
}
