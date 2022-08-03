/*
 * Production.h
 *
 *  Created on: Sep 29, 2021
 *      Author: kilometers
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include <iostream>
#include "Board.h"
using namespace std;

class Production {
	public: Production();
	bool production(int argc, char* argv[]);
	bool getYesNo(char* query);
	virtual ~Production();
};

#endif /* PRODUCTION_H_ */
