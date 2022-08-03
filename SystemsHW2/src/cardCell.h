/*
 * cardCell.h
 *
 *  Created on: Feb 9, 2021
 *      Author: theresesmith
 */

#ifndef CARDCELL_H_
#define CARDCELL_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "Caller.h"

typedef struct
{
	int row;
	int col;
	char letter;
	char digit;
	bool matched;
}cardCellContent;

bool check(cardCellContent** corner, int howManyCols, Combo* ccc);

#endif
