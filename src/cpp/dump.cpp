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
	for (unsigned i = 0; i < numpoints; ++i) {
		cout << "    " << energies[i];

		// Digression: It should be noted that on modern processor complicated conditions
		// inside repeated blocks (like a for loop) are not cpu-intensive if
		// they are almost always true or false, thanks to branch prediction.
		// Anyway, since logic operators like && (=and) uses short-circuit evalutation,
		// it's better to put them in order of probability to have different values during
		// the cycle.
		if (i % 12 == 0 and i != 0) {
			cout << endl;
		}
	}
	return;
}
