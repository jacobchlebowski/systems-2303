/*
 * space.c
 *
 *  Created on: Jan 27, 2020
 *      Author: Therese
 */
#include "space.h"
#include "cardCell.h"
#include "LinkedList.h"

void initSpace(cardCellContent** corner, int howManyCols)
{
	for(int row = 0; row< howManyCols; row++)
	{
		for(int col = 0; col < howManyCols; col++)
		{
			cardCellContent* x = (cardCellContent*) malloc (sizeof(cardCellContent)); //reserve a cardCell on heap
			x->row = 0;
			x->col = 0;
			x->matched = false;
			//call rand
			x->letter = 'A' + rand() % 26;
			x->digit = '0' + rand() % 10;
			cardCellContent**  thatCellP = corner + row*howManyCols + col;
			*thatCellP = x; //put its address into bingo card space
		}
	}
}




void displaySpace(cardCellContent** corner, int howManyCols)
{
	for(int row = 0; row< howManyCols; row++)
	{
		for(int col = 0; col < howManyCols; col++)
		{
			cardCellContent**  thatCellP = corner + row*howManyCols + col;
			char let = (*thatCellP)->letter;
			char digit = (*thatCellP)->digit;
			printf("|%c%c", let, digit);
		}
		printf("|\n");
	}
}















bool isWin(cardCellContent** corner, int howManyCols)
{

	bool win = false;
	//ROW
	for(int row = 0; row< howManyCols; row++)
	{
		int count=0;
		for(int col = 0; col < howManyCols; col++)
		{
			cardCellContent**  thatCellP = corner + row*howManyCols + col;
			bool matching = (*thatCellP)->matched;
			if(matching){
				count++;
			}
			if(count==5){
				win=true;
			}
		}
	}

	//COLS
	for(int col = 0; col< howManyCols; col++)
	{
		int count=0;
		for(int row = 0; row < howManyCols; row=row+5)
		{
			cardCellContent**  thatCellP = corner + row*howManyCols + col;
			bool matching = (*thatCellP)->matched;
			if(matching){
				count++;
			}
			if(count==5){
				win=true;
			}

		}
	}


	//TOP LEFT BOTTOM RIGHT
	for(int row = 0; row< howManyCols; row++)
	{
		int count=0;
		int col=row;
		cardCellContent**  thatCellP = corner + row*howManyCols + col;
		bool matching = (*thatCellP)->matched;
		if(matching){
			count++;
		}
		if(count==5){
			win=true;
		}
	}



	//TOP RIGHT BOTTOM LEFT
	for(int row = 0; row< howManyCols; row++)
		{
			int count=0;
			int col=4-row;
			cardCellContent**  thatCellP = corner + row*howManyCols + col;
			bool matching = (*thatCellP)->matched;
			if(matching){
				count++;
			}
			if(count==5){
				win=true;
			}
		}

	return win;
}





