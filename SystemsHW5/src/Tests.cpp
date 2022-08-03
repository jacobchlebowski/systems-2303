/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include <stdbool.h>
#include <iostream>
#include <fstream>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool answer = true;

	bool ok1 = testCanMove();
	bool ok2 = testMove();
	bool ok3 = testCanMoveCPU();
	bool ok4 = testDisplayBoard();
	answer = ok1 && ok2 && ok3 && ok4;
	return answer;
}

bool Tests::testDisplayBoard()
{
    puts("starting testDisplayBoard"); fflush(stdout);
    bool ok = true;
        //the file tells how many rooms there are


        Board* theBoard = new Board();


        Production* pP = new Production();


        theBoard->displayBoard();


        ok = pP->getYesNo((char*)"Does the displayBoard look right?");
        if(ok)
        {
            puts("testDisplayBoard did pass");
        }
        else
        {
            puts("testDisplayBoard did not pass.");
        }

    return ok;
}



bool Tests::testCanMove(){


	//move a checker and ask if it looks right?
	Checker* r1 = new Checker;
	r1->col = 1;
	r1->row = 7;
	r1->pawn = true;
	r1->red = true;
	r1->dead = false;

	puts("DISPLAYING BOARD... ");
	ifstream file("boards.txt");
	string myArray[8][8];
	if(file.is_open()){

		int count = 0;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				file >> myArray[i][j];
				cout << myArray[i][j];
				if(count%8==0){
					cout << '\n';
				}
			}
			count++;
		}
	}

	Production* pP = new Production();
	bool ok =true;
	CheckerMove* cm = new CheckerMove();
	puts("\nCHECKER 1 MOVES: ");
	cm->canMove(r1, myArray);
	ok = pP->getYesNo((char*)"\nDO THE MOVES LOOK CORRECT? y/n ? \n");

	if(ok)
	{
		puts("testCanMove did pass");
	}
	else
	{
		puts("testCanMove did not pass.");
	}


	return ok;
}



bool Tests::testMove(){
	Checker* r1 = new Checker;
	r1->col = 1;
	r1->row = 7;
	r1->pawn = true;
	r1->red = true;
	r1->dead = false;

	//MAKING ARRAY
	ifstream file("boards.txt");
	string myArray[8][8];
	if(file.is_open()){
		int count = 0;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				file >> myArray[i][j];
				if(count%8==0){
				}
			}
			count++;
		}
	}

	Production* pP = new Production();
	bool ok =true;
	CheckerMove* cm = new CheckerMove();

	cm->move(r1, "6", "0", "6062", myArray);


	//PRINTING ARRAY
	puts("\nDISPLAYING BOARD... ");

	int count = 0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			file >> myArray[i][j];
			cout << myArray[i][j];
			if(count%8==0){
				cout << '\n';
			}
		}
		count++;
	}

	ok=pP->getYesNo((char*)"\nDid the Checker correctly MOVE?");

	if(ok)
	{
		puts("testMove did pass");
	}
	else
	{
		puts("testMove did not pass.");
	}


	return ok;
}




bool Tests::testCanMoveCPU(){
	Checker* b1 = new Checker;
	b1->col = 2;
	b1->row = 0;
	b1->pawn = true;
	b1->red = false;
	b1->dead = false;

	//MAKING ARRAY
	ifstream file("boards.txt");
	string myArray[8][8];
	if(file.is_open()){
		int count = 0;
		for(int i=0;i<8;i++){
			for(int j=0;j<8;j++){
				file >> myArray[i][j];
				if(count%8==0){
				}
			}
			count++;
		}
	}

	Production* pP = new Production();
	bool ok =true;
	CheckerMove* cm = new CheckerMove();


	cm->canMoveCPU(b1, myArray);

	//PRINTING ARRAY
	puts("\nDISPLAYING BOARD... ");

	int count = 0;
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			file >> myArray[i][j];
			cout << myArray[i][j];
			if(count%8==0){
				cout << '\n';
			}
		}
		count++;
	}

	ok=pP->getYesNo((char*)"\nDid the CPU correctly MOVE?");

	if(ok)
	{
		puts("testCanMoveCPU did pass");
	}
	else
	{
		puts("testCanMoveCPU did not pass.");
	}


	return ok;
}

