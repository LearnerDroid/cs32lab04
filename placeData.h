#ifndef PLACE_H
#define PLACE_H

#include <string>
#include <iostream>

using namespace std;

/* very general data type for any kind of place data - very simple for lab04 */
class placeData {
public:
	placeData(string n) : name(n) {}
	string name;
	string getName() {
		return name;
	}
    friend std::ostream& operator<<(std::ostream& out, const placeData& DD) {
		out << "County Demographics Info: " << DD.name;
        return out;
    }
};
#endif
