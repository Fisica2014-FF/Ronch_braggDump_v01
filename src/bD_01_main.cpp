//============================================================================
// Name        : braggDump_v01
// Author      : Francesco Forcher
// Version     : 1.2
// Copyright   : All rights reserved © 2015
// Description : Read the text file "bragg_events.txt"
//============================================================================

#include <iostream>
#include <fstream>

//TODO Commentare tutto!

/* DBG: Function-like macro for debug, when macro DEBUG is defined DBG_ALT is
 * expanded into its first argument, otherwise its expanded into its second
 * argument. Arguments can be void, but is preferable to use a empty statement
 * (a single semicolon) instead.
 */
#ifdef DEBUG
#define DBG(x, y) x
#else
#define DBG(x, y) y
#endif

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

	if (numpoints == 0)
		return;

	cout << "Event " << evID << ": " << numpoints << "points" << endl;
	for (unsigned int i = 0; i < numpoints; ++i) {
		cout << "    " << energies[i] << endl;
	}
	return;
}

// PROGETTO PENSATO PER SALVARE TUTTE LE VARIE OPZIONI POSSIBILI
int main(int argc, char* argv[]) {

	using namespace std;

	DBG(const char* filename = "./bragg_events.txt";
		, const char* filename = argv[1];)

	ifstream ifs(filename);
	int energies[128];
	unsigned int numpoints;
	unsigned int evID;

	while (ifs) {
		ifs >> evID;
		numpoints = read(ifs, energies);
		dump(evID, numpoints, energies);
	}

	return 0;
}
