/*
 * read.cpp
 *
 *  Created on: 03 gen 2016
 *      Author: francesco
 */

#include <iostream>
#include <fstream>

// Quite bad function because it has to be called in a certain order
// from the main...
unsigned int read(std::ifstream& ifs, int energies[]) {
	using namespace std;
	unsigned int numpoints = 0;

	// (Try to) read from file
	ifs >> numpoints;
	for (unsigned int i = 0; i < numpoints; ++i) {
		ifs >> energies[i];
	}

	return numpoints;
}

