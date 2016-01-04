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

#include "dbg_macro.h"

// Quite bad function because it has to be called in a certain order
// from the main...
unsigned int read(std::ifstream& ifs, int energies[]);

void dump(unsigned int evID, unsigned int numpoints, int energies[]);

int main(int argc, char* argv[]) {

	using namespace std;

	//Read file name.
	DBG(const char* filename = "./bragg_events.txt";
		, const char* filename = argv[1];)

	//Try to open the file and check the stream.
	ifstream ifs(filename);
	if (!ifs) {
		cerr << "[ERROR] File not opened";
		return -1;
	}

	//Create variables.
	int energies[128];
	unsigned int numpoints;
	unsigned int evID;

	//Dump every line of the file
	while (ifs) {
		ifs >> evID;
		numpoints = read(ifs, energies);
		dump(evID, numpoints, energies);
	}

	return 0;
}
