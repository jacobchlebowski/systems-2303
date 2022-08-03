/*
 * Tests.h
 *
 *  Created on: Sep 29, 2021
 *      Author: kilometers
 */

#ifndef TESTS_H_
#define TESTS_H_

#include "Production.h"

class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();
	bool testInitBoard();
	bool testPrintGameBoard();
	bool testPutShipOnGameBoard();
	bool testRandomlyPlaceShipsOnGameBoard();
	bool testUpdateGameBoard();
	bool testCheckBoundsOfCardinal();
	bool testGetRandomNumber();
	bool testIsWinner();
	bool testCheckShot();
	bool testIsValidLocation();
	bool testGeneratePosition();
	bool testGetTarget();

};

#endif /* TESTS_H_ */
