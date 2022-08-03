/*
 * Caller.c
 *
 *  Created on: Sep 3, 2021
 *      Author: jake1
 */

#include "Caller.h"

Combo combination(){
	Combo c;
	c.letter = 'A' + rand() % 26;
	c.num = 0 + rand() % 10;
	return c;
}


