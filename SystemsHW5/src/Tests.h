/*
 * Tests.h
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#ifndef TESTS_H_
#define TESTS_H_
#include "Production.h"
#include <stdio.h>


class Tests {
public:
	Tests();
	virtual ~Tests();
	bool tests();

private:
	bool testDisplayBoard();
	bool testCanMove();
	bool testMove();
	bool testCanMoveCPU();
};

#endif /* TESTS_H_ */
