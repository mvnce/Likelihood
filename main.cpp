// Created by Vincent Ma

#include <stdlib.h>
#include <iostream>
#include <map>
#include "Adapter.h"

using namespace std;

int main(int argc, char* argv[]) {
	if (argc != 2) {
		cerr << "Incorrect number of command line arguments." << endl;
		cerr << "Usage: " << argv[0] << " <N>" << endl;
		exit(EXIT_FAILURE);
	}
	int N = atoi(argv[1]);

	Adapter adp(N);
	adp.Process();
	std::map<std::string, double> result = adp.GetResult();

	cout << "Percentage likelihood of the last ball in the bag being black: "
		<< result["black"] * 100 << "%" << endl;
	cout << "Percentage likelihood of the last ball in the bag being white: "
		<< result["white"] * 100 << "%" << endl;
    return 0;
}
