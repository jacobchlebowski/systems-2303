//============================================================================
// Name        : HW6.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Tests.h"
#include "Production.h"
using namespace std;

int main(int argc, char* argv[]) {
	cout << "!!!Hello World, Let's do HW6!!!" << endl; // prints !!!Hello World!!!
	fflush(stdout);
	Tests* test = new Tests();
	Production* prod = new Production();

	if(test->tests()){
		std::cout << "Tests passed!" << endl;
		fflush(stdout);
		prod->production(argc, argv);
	} else {
		cout << "tests did not pass..." << endl;
	}

	return 0;
}
