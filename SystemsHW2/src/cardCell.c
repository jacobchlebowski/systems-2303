/*
 * cardCell.c
 *
 *  Created on: Feb 9, 2021
 *      Author: theresesmith
 */

#include "cardCell.h"



bool check(cardCellContent** corner, int howManyCols, Combo* ccc){
	bool isMatch = false;
	for(int row=0; row< howManyCols; row++){
		for(int col=0; col<howManyCols; col++){
			cardCellContent** thatCellP = corner + row*howManyCols + col;
			char let = (*thatCellP)->letter;
			char digit = (*thatCellP)->digit;
			char let2 = (ccc)-> letter;
			char digit2 = (ccc)->num + '0' -48;
			if((let==let2)&&(digit==digit2)){
				puts("FOUND A MATCH");
				isMatch=true;
				(*thatCellP)->matched=true;
				(*thatCellP)->letter=((*thatCellP)->letter+32);
			}
		}
	}
return isMatch;
}
