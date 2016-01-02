//============================================================================
// Name        : braggDump_v01
// Author      : Francesco Forcher
// Version     : 0.1
// Copyright   : All rights reserved © 2015
// Description : Read the text file "bragg_events.txt"
//============================================================================

#include <iostream>
#include <fstream>



unsigned int read(std::ifstream& ifs, int energies[]) {
	using namespace std;
	unsigned int numpoints = 0;

	ifs >> numpoints;

	for (unsigned int i = 0; i < numpoints; ++i) {
		ifs >> energies[i];
	}

	return numpoints;
}

void dump(unsigned int evID, unsigned int numpoints, int energies[]) {
	using namespace std;
	cout << "Event " << evID << ": " << numpoints << "points" << endl;
	for (unsigned int i = 0; i < numpoints; ++i) {
		cout << "    " << energies[i] << endl;
	}
	return;
}

// PROGETTO PENSATO PER SALVARE TUTTE LE VARIE OPZIONI POSSIBILI
int main(int argc, char* argv[]) {

	using namespace std;

	char* filename = argv[1];
	ifstream ifs(filename);
	int energies[128];
	unsigned int numpoints;
	unsigned int evID;

	while (ifs) {
		ifs >> evID;
		numpoints = read(ifs,energies);

		if (numpoints == 0) break;

		dump(evID,numpoints,energies);
	}

	return 0;
}
