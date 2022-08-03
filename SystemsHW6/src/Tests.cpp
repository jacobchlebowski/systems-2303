/*
 * Tests.cpp
 *
 *  Created on: Sep 29, 2021
 *      Author: kilometers
 */

#include "Tests.h"
#include <stdbool.h>


Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests() {
	bool ok1 = testInitBoard();
	bool ok2 = testPrintGameBoard();
	bool ok3 = testPutShipOnGameBoard();
	bool ok5 = testRandomlyPlaceShipsOnGameBoard();
	bool ok6 = testUpdateGameBoard();
	bool ok7 = testCheckBoundsOfCardinal();
	bool ok8 = testGetRandomNumber();
	bool ok9 = testUpdateGameBoard();
	bool ok10 = testIsWinner();
	bool ok11 = testCheckShot();
	bool ok12 = testIsValidLocation();
	bool ok13 = testGeneratePosition();
	//bool ok14 = testGetTarget();

	return ok1 && ok2 && ok3 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10 && ok11 && ok12 && ok13;
}

bool Tests::testInitBoard() {
	puts("Starting testInitBoard"); fflush(stdout);
	bool ok = true;

	Board* board = new Board();
	Cell gameBoard[ROWS][COLS];
	board->initializeGameBoard(gameBoard);

	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++) {
			if(gameBoard[i][j].symbol != '~') {
				ok = false;
			}
		}
	}

	if(ok) {
		puts("testInitBoard did pass"); fflush(stdout);
	} else {
		puts("testInitBoard did not pass."); fflush(stdout);
	}

	return ok;
}

bool Tests::testPrintGameBoard() {
	puts("Starting testPrintGameBoard"); fflush(stdout);
	bool ok = true;

	Production* pP = new Production();

	Board* board = new Board();
	Cell gameBoard[ROWS][COLS];
	board->initializeGameBoard(gameBoard);
	board->printGameBoard(gameBoard, TRUE);

	ok = pP->getYesNo((char*)"\nLooks like a battleship game board?");

	if(ok) {
		puts("testPrintGameBoard did pass"); fflush(stdout);
	} else {
		puts("testPrintGameBoard did not pass."); fflush(stdout);
	}

	return ok;
}

bool Tests::testPutShipOnGameBoard() {
	puts("Starting testPutShipOnGameBoard"); fflush(stdout);
	bool ok = true;

	Board* board = new Board();
	Cell gameboard[ROWS][COLS];
	board->initializeGameBoard(gameboard);
	board->putShipOnGameBoard(gameboard, {CARRIER, 5, "Carrier"}, {0, 0}, HORIZONTAL);

	for(int i = 0; i < 5; i++) {
		if(gameboard[0][i].symbol != CARRIER) {
			ok = false;
		}
	}

	if(ok) {
		puts("testPutShipOnGameBoard did pass"); fflush(stdout);
	} else {
		puts("testPutShipOnGameBoard did not pass."); fflush(stdout);
	}

	return ok;
}


bool Tests::testRandomlyPlaceShipsOnGameBoard() {
	puts("Starting testRandomlyPlaceShipsOnGameBoard"); fflush(stdout);
	bool ok = true;

	WaterCraft ship[NUM_OF_SHIPS] = {{'c', 5, "Carrier"},
				{'b', 4, "Battleship"},
				{'r', 3, "Cruiser"},
				{'s', 3, "Submarine"},
				{'d', 2, "Destroyer"}};

	Board* board = new Board();
	Cell gameBoard[ROWS][COLS];
	board->initializeGameBoard(gameBoard);
	board->randomlyPlaceShipsOnGameBoard(gameBoard, ship);

	int carrierCount = 0;

	for(int i = 0; i < ROWS; i++) {
		for(int j = 0; j < COLS; j++) {
			if(gameBoard[i][j].symbol == CARRIER) {
				carrierCount++;
			}
		}
	}

	if(carrierCount != 5) {
		ok = false;
	}

	if(ok) {
		puts("testRandomlyPlaceShipsOnGameBoard did pass"); fflush(stdout);
	} else {
		puts("testRandomlyPlaceShipsOnGameBoard did not pass."); fflush(stdout);
	}

	return ok;
}


bool Tests::testUpdateGameBoard() {
    puts("Starting testUpdateGameBoard"); fflush(stdout);
    bool ok = true;

    Board* board = new Board();
    Cell gameBoard[ROWS][COLS];
    board->initializeGameBoard(gameBoard);
    board->putShipOnGameBoard(gameBoard, {'d', 2, "Destroyer"}, {0, 0}, HORIZONTAL);
    board->updateGameBoard(gameBoard, {0, 0});
    board->updateGameBoard(gameBoard, {0, 1});
    if(gameBoard[0][0].symbol != HIT && gameBoard[0][1].symbol != HIT) {
        ok = false;
    }

    board->updateGameBoard(gameBoard, {0, 2});
    if(gameBoard[0][2].symbol != MISS) {
        ok = false;
    }

    if(ok) {
        puts("testUpdateGameBoard did pass"); fflush(stdout);
    } else {
        puts("testUpdateGameBoard did not pass."); fflush(stdout);
    }

    return ok;
}



bool Tests::testCheckBoundsOfCardinal() {
    puts("Starting testCheckBoundsOfCardinal"); fflush(stdout);
    bool ok = true;

    Board* board = new Board();
    Cell gameBoard[ROWS][COLS];
    board->initializeGameBoard(gameBoard);

    Boolean cardinalsTest[4];

    // check north
    board->checkBoundsOfCardinal(cardinalsTest, 0, NORTH);
    board->checkBoundsOfCardinal(cardinalsTest, 9, NORTH);
    // check south
    board->checkBoundsOfCardinal(cardinalsTest, 9, SOUTH);
    board->checkBoundsOfCardinal(cardinalsTest, 8, SOUTH);
    // check west
    board->checkBoundsOfCardinal(cardinalsTest, 0, WEST);
    board->checkBoundsOfCardinal(cardinalsTest, 9, NORTH);
    // check east
    board->checkBoundsOfCardinal(cardinalsTest, 9, SOUTH);
    board->checkBoundsOfCardinal(cardinalsTest, 8, SOUTH);

    if((cardinalsTest[0] && cardinalsTest[1] && cardinalsTest[2] && cardinalsTest[3]) == FALSE) {
        ok = false;
    }

    if(ok) {
        puts("testCheckBoundsOfCardinal did pass"); fflush(stdout);
    } else {
        puts("testCheckBoundsOfCardinal did not pass."); fflush(stdout);
    }

    return ok;
}

bool Tests::testGetRandomNumber() {
	puts("Starting testGetRandomNumber"); fflush(stdout);
	bool ok = true;

	Board* board = new Board();
	int randomOutput = board->getRandomNumber(10, 100);
	if(randomOutput < 10 || randomOutput > 100) {
		ok = false;
	}

	int randomOutput2 = board->getRandomNumber(1, 10);
	if(randomOutput2 < 1 || randomOutput2 > 10) {
		ok = false;
	}

	if(ok) {
		puts("testGetRandomNumber did pass"); fflush(stdout);
	} else {
		puts("testGetRandomNumber did not pass."); fflush(stdout);
	}

	return ok;
}

bool Tests::testIsWinner(){
	puts("Starting testIsWinner"); fflush(stdout);
	bool ok = true;
	Board* board = new Board();
	Stats players[2] = {{17, 0, 0, 0.0}, {0, 0, 0, 0.0}};

	if(!(board->isWinner(players, 0))){
		ok = false;
	}

	if(ok) {
			puts("testIsWinner did pass"); fflush(stdout);
		} else {
			puts("testIsWinner did not pass."); fflush(stdout);
		}

	return ok;
}

bool Tests::testCheckShot(){
	puts("Starting testCheckShot"); fflush(stdout);
	bool ok = true;
	Board* board = new Board();
	Cell gameBoard[ROWS][COLS];
	board->initializeGameBoard(gameBoard);
	board->putShipOnGameBoard(gameBoard, {'d', 2, "Destroyer"}, {0, 0}, HORIZONTAL);


	if(!(board->checkShot(gameBoard, {0,0})==1)){
		ok = false;
	}


	if(ok) {
				puts("testCheckShot did pass"); fflush(stdout);
			} else {
				puts("testCheckShot did not pass."); fflush(stdout);
			}

	return ok;
}

bool Tests::testIsValidLocation() {
    puts("Starting testIsValidLocation"); fflush(stdout);
    bool ok = true;

    Board* board = new Board();
    Cell gameBoard[ROWS][COLS];
    board->initializeGameBoard(gameBoard);

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(!board->isValidLocation(gameBoard, {i, j},  HORIZONTAL, 1) ||
                    !board->isValidLocation(gameBoard, {i, j},  VERTICAL, 1)) {
                ok = false;
            }
        }
    }

    board->putShipOnGameBoard(gameBoard, {CARRIER, 5, "Carrier"}, {0, 0}, HORIZONTAL);

    if(board->isValidLocation(gameBoard, {0, 0},  HORIZONTAL, 5)) {
        ok = false;
    }

    if(ok) {
        puts("testIsValidLocation did pass"); fflush(stdout);
    } else {
        puts("testIsValidLocation did not pass."); fflush(stdout);
    }

    return ok;
}

bool Tests::testGeneratePosition(){

	bool ok = true;
	Board* board = new Board();

	Coordinate pos = board->generatePosition(0,5);
	Coordinate pos2 = board->generatePosition(1,5);

	if(pos.row > 10 || pos.row< 0){
		ok = false;
	}

	if(pos2.column > 10 || pos2.column <0){
		ok = false;
	}


	if(ok) {
	        puts("testGeneratePosition did pass"); fflush(stdout);
	    } else {
	        puts("testGeneratePosition did not pass."); fflush(stdout);
	    }
	    return ok;
}

//bool Tests::testGetTarget() {
//    puts("Starting testGetTarget"); fflush(stdout);
//    bool ok = true;
//
//    Board* board = new Board();
//    Coordinate pos = board->getTarget();
//
//    Production* pP = new Production();
//
//    printf ("\nThe target is: %d, %d\n", pos.row, pos.column);
//    ok = pP->getYesNo((char*)"\nDoes the output look like what you inputed?");
//
//    if(ok) {
//        puts("testGetTarget did pass"); fflush(stdout);
//    } else {
//        puts("testGetTarget did not pass."); fflush(stdout);
//    }
//
//    return ok;
//}








