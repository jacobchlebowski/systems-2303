/*
 * Caller.c
 *
 *  Created on: Sep 3, 2021
 *      Author: jake1
 */

#include "Caller.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

Combo* combination(){
	Combo* c= (Combo*)malloc(sizeof(Combo));
	c->letter = 'A' + rand() % 26;
	c->num = '0' + rand() % 10;
	return c;
}


