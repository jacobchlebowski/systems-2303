/*
 * CheckerMove.h
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#ifndef CHECKERMOVE_H_
#define CHECKERMOVE_H_
#include <string>
#include <vector>
#include "Checker.h"
using namespace std;


class CheckerMove {
public:
	std::string myArray[8][8];

    CheckerMove();
    string canMove(Checker* checker, string myArray[8][8]);
    bool move(Checker*,string /*row*/,string /*col*/,string possibleMoves, string myArray[8][8]);
    bool canMoveCPU(Checker* checker, string myArray[8][8]);
    virtual ~CheckerMove();
};



#endif /* CHECKERMOVE_H_ */
