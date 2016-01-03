/*
 * dump.cpp
 *
 *  Created on: 03 gen 2016
 *      Author: francesco
 */

#include <iostream>


// Print a event
void dump(unsigned int evID, unsigned int numpoints, int energies[]) {
	using namespace std;

	//If numpoints is 0 then the file has ended/is invalid.
	if (numpoints == 0)
		return;

	cout << "Event " << evID << ": " << numpoints << " points" << endl;
	for (unsigned int i = 0; i < numpoints; ++i) {
		cout << "    " << energies[i] << endl;
	}
	return;
}
