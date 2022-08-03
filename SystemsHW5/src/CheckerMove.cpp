/*
 * CheckerMove.cpp
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#include "CheckerMove.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stdio.h>
using namespace std;

CheckerMove::CheckerMove() {
	// TODO Auto-generated constructor stub

}

CheckerMove::~CheckerMove() {
	// TODO Auto-generated destructor stub
}


string CheckerMove::canMove(Checker* checker, string myArray[8][8]) {
	std::string possibleMoves;
	//Pawn

	if (checker->pawn && checker->dead == false) {
		//RIGHT WALL PAWN
		if (checker->col == 7){
			if (myArray[0][checker->row-1][checker->col-1] == '-'){

				printf("(%d, %d)",(checker->row-1), (checker->col-1));
				fflush(stdout);
				possibleMoves.append(std::to_string(checker->row-1));
				possibleMoves.append(std::to_string(checker->col-1));

			}
			else {
				//JUMP OVER THE CHECKER
				if (myArray[0][checker->row-2][checker->col-2] == '-' && myArray[0][checker->row-1][checker->col-1] != 'r') {
					printf("(%d, %d)",(checker->row-2), (checker->col-2));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row-2));
					possibleMoves.append(std::to_string(checker->col-2));
				}
			}
		}
		//LEFT WALL PAWN
		else if (checker->col == 0){
			if (myArray[0][checker->row-1][checker->col+1] == '-'){
				printf("(%d, %d)",(checker->row-1), (checker->col+1));
				fflush(stdout);
				possibleMoves.append(std::to_string(checker->row-1));
				possibleMoves.append(std::to_string(checker->col+1));
			}
			else {
				//JUMP OVER THE CHECKER
				if (myArray[0][checker->row-2][checker->col+2] == '-' && myArray[0][checker->row-1][checker->col+1] != 'r') {
					printf("(%d, %d)",(checker->row-2), (checker->col+2));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row-2));
					possibleMoves.append(std::to_string(checker->col+2));
				}
			}
		}
		//NOT WALL PAWN
		else {
			//top left
			if (checker->row-1 >= 0 && myArray[0][checker->row-1][checker->col-1] == '-') {
				printf("(%d, %d) ",(checker->row-1), (checker->col-1));
				fflush(stdout);
				possibleMoves.append(std::to_string(checker->row-1));
				possibleMoves.append(std::to_string(checker->col-1));
			}
			else {
				if (checker->row - 2 >= 0 && checker->col - 2 >= 0 && myArray[0][checker->row-2][checker->col-2] == '-' && myArray[0][checker->row-1][checker->col-1] != 'r') {
					printf("(%d, %d) ",(checker->row-2), (checker->col-2));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row-2));
					possibleMoves.append(std::to_string(checker->col-2));
				}
			}

			//top right
			if (checker->row-1 >= 0 && myArray[0][checker->row-1][checker->col+1] == '-') {
				printf("(%d, %d) ",(checker->row-1), (checker->col+1));
				fflush(stdout);
				possibleMoves.append(std::to_string(checker->row-1));
				possibleMoves.append(std::to_string(checker->col+1));
			}
			else {
				if (checker->row - 2 >= 0 && checker->col + 2 >= 0 && myArray[0][checker->row-2][checker->col+2] == '-' && myArray[0][checker->row-1][checker->col+1] != 'r') {
					printf("(%d, %d) ",(checker->row-2), (checker->col+2));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row-2));
					possibleMoves.append(std::to_string(checker->col+2));
				}
			}
		}

	}

	//KING
	if (!(checker->pawn) && checker->dead == false) {
		//RIGHT WALL KING
		if (checker->col == 7){
			//RIGHT WALL NOT CORNER
			if (checker->row != 0  && checker->row != 7) {
				if (checker->row-1 > 0 && myArray[0][checker->row-1][checker->col-1] == '-'){
					printf("(%d, %d) ",(checker->row-1), (checker->col-1));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row-1));
					possibleMoves.append(std::to_string(checker->col-1));
				}

				else {
					//JUMP OVER THE CHECKER
					if (checker->row-2 >= 0 && myArray[0][checker->row-2][checker->col-2] == '-'  && myArray[0][checker->row-1][checker->col-1] != 'r') {
						printf("(%d, %d) ",(checker->row-2), (checker->col-2));
						fflush(stdout);
						possibleMoves.append(std::to_string(checker->row-2));
						possibleMoves.append(std::to_string(checker->col-2));
					}
				}

				if (checker ->row+1 <= 7 && myArray[0][checker->row+1][checker->col-1] == '-'){
					printf("(%d, %d) ",(checker->row+1), (checker->col-1));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row+1));
					possibleMoves.append(std::to_string(checker->col-1));
				}

				else {
					//JUMP OVER THE CHECKER
					if (checker ->row+2 <= 7 && myArray[0][checker->row+2][checker->col-2] == '-' && myArray[0][checker->row+1][checker->col-1] != 'r') {
						printf("(%d, %d) ",(checker->row+2), (checker->col-2));
						fflush(stdout);
						possibleMoves.append(std::to_string(checker->row+2));
						possibleMoves.append(std::to_string(checker->col-2));
					}
				}
			}

			//RIGHT WALL TOP CORNER
			if (checker->row == 0) {
				if (myArray[0][checker->row+1][checker->col-1] == '-'){
					printf("(%d, %d) ",(checker->row+1), (checker->col-1));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row+1));
					possibleMoves.append(std::to_string(checker->col-1));
				}

				else {
					//JUMP OVER THE CHECKER
					if (myArray[0][checker->row+2][checker->col-2] == '-' && myArray[0][checker->row+1][checker->col-1] != 'r') {
						printf("(%d, %d) ",(checker->row+2), (checker->col-2));
						fflush(stdout);
						possibleMoves.append(std::to_string(checker->row+2));
						possibleMoves.append(std::to_string(checker->col-2));
					}
				}
			}

			//RIGHT WALL BOTTOM CORNER
			if (checker->row == 7) {
				if (myArray[0][checker->row-1][checker->col-1] == '-'){
					printf("(%d, %d) ",(checker->row-1), (checker->col-1));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row-1));
					possibleMoves.append(std::to_string(checker->col-1));
				}
				else {
					//JUMP OVER THE CHECKER
					if (myArray[0][checker->row-2][checker->col-2] == '-' && myArray[0][checker->row-1][checker->col-1] != 'r') {
						printf("(%d, %d) ",(checker->row-2), (checker->col-2));
						fflush(stdout);
						possibleMoves.append(std::to_string(checker->row-2));
						possibleMoves.append(std::to_string(checker->col-2));
					}
				}
			}

		}
		//LEFT WALL KING
		if (checker->col == 0){
			//LEFT WALL NOT CORNER
			if (checker->row-1 >= 0 && checker->row != 0  && checker->row != 7) {
				if (myArray[0][checker->row-1][checker->col+1] == '-'){
					printf("(%d, %d) ",(checker->row-1), (checker->col+1));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row-1));
					possibleMoves.append(std::to_string(checker->col+1));
				}

				else {
					//JUMP OVER THE CHECKER
					if (checker->row-2 >= 0 && myArray[0][checker->row-2][checker->col+2] == '-' && myArray[0][checker->row-1][checker->col+1] != 'r') {
						printf("(%d, %d) ",(checker->row-2), (checker->col+2));
						fflush(stdout);
						possibleMoves.append(std::to_string(checker->row-2));
						possibleMoves.append(std::to_string(checker->col+2));
					}
				}

				if (checker ->row+1 <= 7 && myArray[0][checker->row+1][checker->col+1] == '-'){
					printf("(%d, %d) ",(checker->row+1), (checker->col+1));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row+1));
					possibleMoves.append(std::to_string(checker->col+1));
				}

				else {
					//JUMP OVER THE CHECKER
					if (checker ->row+2 <= 7 && myArray[0][checker->row+2][checker->col-2] == '-' && myArray[0][checker->row+1][checker->col-1] != 'r') {
						printf("(%d, %d) ",(checker->row+2), (checker->col+2));
						fflush(stdout);
						possibleMoves.append(std::to_string(checker->row+2));
						possibleMoves.append(std::to_string(checker->col+2));
					}
				}
			}

			//LEFT WALL TOP CORNER
			if (checker->row == 0) {
				if (myArray[0][checker->row+1][checker->col+1] == '-'){
					printf("(%d, %d) ",(checker->row+1), (checker->col+1));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row+1));
					possibleMoves.append(std::to_string(checker->col+1));
				}

				else {
					//JUMP OVER THE CHECKER
					if (myArray[0][checker->row+1][checker->col+1] != '-' && myArray[0][checker->row+2][checker->col+2] == '-' && myArray[0][checker->row+1][checker->col+1] != 'r') {
						printf("(%d, %d) ",(checker->row+2), (checker->col+2));
						fflush(stdout);
						possibleMoves.append(std::to_string(checker->row+2));
						possibleMoves.append(std::to_string(checker->col+2));
					}
				}
			}

			//LEFT WALL BOTTOM CORNER
			if (checker->row == 7) {
				if (myArray[0][checker->row-1][checker->col+1] == '-'){
					printf("(%d, %d) ",(checker->row-1), (checker->col+1));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row-1));
					possibleMoves.append(std::to_string(checker->col+1));
				}

				else {
					//JUMP OVER THE CHECKER
					if (myArray[0][checker->row-2][checker->col+2] == '-' && myArray[0][checker->row-1][checker->col+1] != 'r') {
						printf("(%d, %d) ",(checker->row-2), (checker->col+2));
						fflush(stdout);
						possibleMoves.append(std::to_string(checker->row-2));
						possibleMoves.append(std::to_string(checker->col+2));
					}
				}
			}
		}
		//NO WALL KING
		if(checker->col != 7 && checker->col != 0) {
			//top left
			if (checker->row-1 >= 0 && myArray[0][checker->row-1][checker->col-1] == '-') {
				printf("(%d, %d) ",(checker->row-1), (checker->col-1));
				fflush(stdout);
				possibleMoves.append(std::to_string(checker->row-1));
				possibleMoves.append(std::to_string(checker->col-1));
			}
			else {
				if (checker->row - 2 >= 0 && checker->col - 2 >= 0 && myArray[0][checker->row-2][checker->col-2] == '-' && myArray[0][checker->row-1][checker->col-1] != 'r') {
					printf("(%d, %d) ",(checker->row-2), (checker->col-2));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row-2));
					possibleMoves.append(std::to_string(checker->col-2));
				}
			}

			//top right
			if (checker->row-1 >= 0 && myArray[0][checker->row-1][checker->col+1] == '-') {
				printf("(%d, %d) ",(checker->row-1), (checker->col+1));
				fflush(stdout);
				possibleMoves.append(std::to_string(checker->row-1));
				possibleMoves.append(std::to_string(checker->col+1));
			}
			else {
				if (checker->row - 2 >= 0 && checker->col + 2 >= 0 && myArray[0][checker->row-2][checker->col+2] == '-' && myArray[0][checker->row-1][checker->col+1] != 'r') {
					printf("(%d, %d) ",(checker->row-2), (checker->col+2));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row-2));
					possibleMoves.append(std::to_string(checker->col+2));
				}
			}

			//bottom left
			if (checker->row+1 >= 0 && checker->row+1 <= 7 && myArray[0][checker->row+1][checker->col-1] == '-') {
				printf("(%d, %d) ",(checker->row+1), (checker->col-1));
				fflush(stdout);
				possibleMoves.append(std::to_string(checker->row+1));
				possibleMoves.append(std::to_string(checker->col-1));
			}
			else {
				if (checker->row + 2 >= 0 && checker->row+2 <= 7 && checker->col - 2 >= 0 && myArray[0][checker->row+2][checker->col-2] == '-' && myArray[0][checker->row+1][checker->col-1] != 'r') {
					printf("(%d, %d) ",(checker->row+2), (checker->col-2));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row+2));
					possibleMoves.append(std::to_string(checker->col-2));
				}
			}

			//bottom right
			if (checker->row+1 >= 0 && checker->row+1 <= 7 && myArray[0][checker->row+1][checker->col+1] == '-') {
				printf("(%d, %d) ",(checker->row+1), (checker->col+1));
				fflush(stdout);
				possibleMoves.append(std::to_string(checker->row+1));
				possibleMoves.append(std::to_string(checker->col+1));
			}
			else {
				if (checker->row + 2 >= 0 && checker->row+2 <= 7 && checker->col + 2 >= 0 && myArray[0][checker->row+2][checker->col+2] == '-' && myArray[0][checker->row+1][checker->col+1] != 'r') {
					printf("(%d, %d) ",(checker->row+2), (checker->col+2));
					fflush(stdout);
					possibleMoves.append(std::to_string(checker->row+2));
					possibleMoves.append(std::to_string(checker->col+2));
				}
			}

		}
	}

	if (checker->dead == true) {
		printf("Checker is dead.");
	}
	return possibleMoves;

}

bool CheckerMove::move(Checker* checker, string xCoord, string yCoord, string possibleMoves, string myArray[8][8]) {
	bool ok = false;
	std::string coordinates = "";
	coordinates = coordinates.append(xCoord);
	coordinates = coordinates.append(yCoord);
	int length = possibleMoves.length();
	for (int i = 0; i <= length - 2; i = i + 2) {
		if (possibleMoves.substr(i,2) == coordinates) {
			ok = true;
			// BLACK CHECKER DEAD HERE
			if (checker->row + 2 <= 7 && checker->col + 2 <= 7) {
				if (checker->row + 2 == std::stoi(xCoord) && checker->col + 2 == std::stoi(yCoord)) {
					myArray[0][checker->row + 1][checker->col + 1] = '-';
				}
			}
			if (checker->row + 2 <= 7 && checker->col - 2 >= 0) {
				if (checker->row + 2 == std::stoi(xCoord) && checker->col - 2 == std::stoi(yCoord)) {
					myArray[0][checker->row + 1][checker->col - 1] = '-';
				}
			}
			if (checker->row - 2 >= 0 && checker->col + 2 <= 7) {
				if (checker->row - 2 == std::stoi(xCoord) && checker->col + 2 == std::stoi(yCoord)) {
					myArray[0][checker->row - 1][checker->col + 1] = '-';
				}
			}
			if (checker->row - 2 >= 0 && checker->col - 2 >= 0) {
				if (checker->row - 2 == std::stoi(xCoord) && checker->col - 2 == std::stoi(yCoord)) {
					myArray[0][checker->row - 1][checker->col - 1] = '-';
				}
			}
			myArray[0][checker->row][checker->col] = '-';
			checker->row = std::stoi(xCoord);
			checker->col = std::stoi(yCoord);
			myArray[0][checker->row][checker->col] = 'r';
		}

	}
	if (checker->row == 0 && checker->red == true) {
		checker->pawn = false;
	}

	if (checker->row == 7 && checker->red == false) {
		checker->pawn = false;
	}


	return ok;
}

bool CheckerMove::canMoveCPU(Checker* checker, string myArray[8][8]) {
	bool finished = true;
	//Pawn
	if (checker->pawn) {
		//RIGHT WALL PAWN
		if (checker->col == 7){
			if (myArray[0][checker->row+1][checker->col-1] == '-' && finished){
				printf("(%d, %d)",(checker->row+1), (checker->col-1));
				fflush(stdout);
				myArray[0][checker->row+1][checker->col-1] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				checker->row = checker->row+1;
				checker->col = checker->col+1;
				finished = false;

				FILE* fr = fopen("boardPlay.txt", "a");
				fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
				fclose(fr);

			}
			else {
				//JUMP OVER THE CHECKER
				if (myArray[0][checker->row+2][checker->col-2] == '-' && finished) {
					printf("(%d, %d)",(checker->row+2), (checker->col-2));
					fflush(stdout);
					myArray[0][checker->row+2][checker->col-2] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					myArray[0][checker->row + 1][checker->col - 1] = '-';
					checker->row = checker->row+2;
					checker->col = checker->col-2;
					finished = false;

					FILE* fr = fopen("boardPlay.txt", "a");
					fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
					fclose(fr);
				}
			}
		}
		//LEFT WALL PAWN
		else if (checker->col == 0){
			if (myArray[0][checker->row+1][checker->col+1] == '-' && finished){
				printf("(%d, %d)",(checker->row+1), (checker->col+1));
				fflush(stdout);
				finished = false;
				myArray[0][checker->row+1][checker->col+1] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				checker->row = checker->row+1;
				checker->col = checker->col+1;

				FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
			}
			else {
				//JUMP OVER THE CHECKER
				if (myArray[0][checker->row+2][checker->col+2] == '-' && finished) {
					printf("(%d, %d)",(checker->row+2), (checker->col+2));
					fflush(stdout);
					myArray[0][checker->row+2][checker->col+2] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					myArray[0][checker->row + 1][checker->col + 1] = '-';
					checker->row = checker->row+2;
					checker->col = checker->col+2;
					finished = false;

					FILE* fr = fopen("boardPlay.txt", "a");
										fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
										fclose(fr);
				}
			}
		}
		//NOT WALL PAWN
		else {
			bool ok1 = false;
			bool ok2 = false;
			//JUMP OVER THE CHECKER BOTTOM LEFT
			if (myArray[0][checker->row+1][checker->col-1] != '-' && checker->row + 2 <= 7 && checker->col - 2 >= 0 && myArray[0][checker->row+2][checker->col-2] == '-'  && finished) {
				printf("(%d, %d) ",(checker->row+2), (checker->col-2));
				fflush(stdout);
				ok1 = true;
				finished = false;
				myArray[0][checker->row+2][checker->col-2] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				myArray[0][checker->row + 1][checker->col - 1] = '-';
				checker->row = checker->row+2;
				checker->col = checker->col-2;

				FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %c column %c\n", checker->row, checker ->col);
									fclose(fr);
			}
			//JUMP OVER THE CHECKER BOTTOM RIGHT
			else if (myArray[0][checker->row+1][checker->col+1] != '-' && checker->row + 2 <= 7 && checker->col + 2 <= 7 && myArray[0][checker->row+2][checker->col+2] == '-'  && finished) {
				printf("(%d, %d) ",(checker->row+2), (checker->col+2));
				fflush(stdout);
				ok2 = true;
				finished = false;
				myArray[0][checker->row+2][checker->col+2] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				myArray[0][checker->row + 1][checker->col + 1] = '-';
				checker->row = checker->row+2;
				checker->col = checker->col+2;

				FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %c column %c\n", checker->row, checker ->col);
									fclose(fr);
			}
			//			//BOTH BOTTOM LEFT AND BOTTOM RIGHT NOT JUMPED
			//			else if (!ok1 && !ok2 && myArray[0][checker->row+1][checker->col-1] == '-' && myArray[0][checker->row+1][checker->col+1] == '-' && finished){
			//				printf("(%d, %d) (%d, %d)",(checker->row+1), (checker->col-1), (checker->row+1), (checker->col+1));
			//				fflush(stdout);
			//				finished = false;
			//			}

			//BOTH BOTTOM LEFT AND BOTTOM RIGHT NOT JUMPED AND NO AVAILABLE SPOTS
			//			else if (!ok1 && !ok2 && myArray[0][checker->row+1][checker->col-1] != '-' && myArray[0][checker->row+1][checker->col+1] != '-' && finished){
			//
			//			}

			//MOVE BOTTOM LEFT
			else if (myArray[0][checker->row+1][checker->col-1] == '-' && finished){
				printf("(%d, %d)\n",(checker->row+1), (checker->col-1));
				fflush(stdout);
				finished = false;
				myArray[0][checker->row+1][checker->col-1] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				checker->row = checker->row+1;
				checker->col = checker->col-1;
				FILE* fr = fopen("boardPlay.txt", "a");
								fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
								fclose(fr);
			}
			//MOVE BOTTOM RIGHT
			else if (myArray[0][checker->row+1][checker->col+1] == '-' && finished){
				printf("(%d, %d)\n",(checker->row+1), (checker->col+1));
				fflush(stdout);
				finished = false;
				myArray[0][checker->row+1][checker->col+1] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				checker->row = checker->row+1;
				checker->col = checker->col+1;
				FILE* fr = fopen("boardPlay.txt", "a");
								fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
								fclose(fr);
			}

			//ONLY ABLE TO GO BOTTOM RIGHT
			else if (!ok1 && !ok2 && myArray[0][checker->row+1][checker->col+1] == '-' && finished){
				printf("(%d, %d)\n",(checker->row+1), (checker->col+1));
				fflush(stdout);
				finished = false;
				myArray[0][checker->row+1][checker->col+1] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				checker->row = checker->row+1;
				checker->col = checker->col+1;
				FILE* fr = fopen("boardPlay.txt", "a");
								fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
								fclose(fr);
			}

			//ONLY ABLE TO GO BOTTOM LEFT
			else if (!ok1 && !ok2 && myArray[0][checker->row+1][checker->col-1] == '-' && finished){
				printf("(%d, %d)\n",(checker->row+1), (checker->col-1));
				fflush(stdout);
				finished = false;
				myArray[0][checker->row+1][checker->col-1] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				checker->row = checker->row+1;
				checker->col = checker->col-1;
				FILE* fr = fopen("boardPlay.txt", "a");
								fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
								fclose(fr);
			}

		}

	}

	//KING
	if (!(checker->pawn)) {
		//RIGHT WALL KING
		if (checker->col == 7){
			//RIGHT WALL NOT CORNER
			if (checker->row != 0  && checker->row != 7) {
				if (checker->row-1 > 0 && myArray[0][checker->row-1][checker->col-1] == '-' && finished){
					printf("(%d, %d) ",(checker->row-1), (checker->col-1));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row-1][checker->col-1] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					checker->row = checker->row-1;
					checker->col = checker->col-1;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}

				else {
					//JUMP OVER THE CHECKER
					if (checker->row-2 >= 0 && myArray[0][checker->row-2][checker->col-2] == '-' && finished) {
						printf("(%d, %d) ",(checker->row-2), (checker->col-2));
						fflush(stdout);
						finished = false;
						myArray[0][checker->row-2][checker->col-2] = 'b';
						myArray[0][checker->row][checker->col] = '-';
						myArray[0][checker->row - 1][checker->col - 1] = '-';
						checker->row = checker->row-2;
						checker->col = checker->col-2;
						FILE* fr = fopen("boardPlay.txt", "a");
										fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
										fclose(fr);
					}
				}

				if (checker ->row+1 <= 7 && myArray[0][checker->row+1][checker->col-1] == '-' && finished){
					printf("(%d, %d) ",(checker->row+1), (checker->col-1));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row+1][checker->col-1] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					checker->row = checker->row+1;
					checker->col = checker->col-1;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}

				else {
					//JUMP OVER THE CHECKER
					if (checker ->row+2 <= 7 && myArray[0][checker->row+2][checker->col-2] == '-' && finished) {
						printf("(%d, %d) ",(checker->row+2), (checker->col-2));
						fflush(stdout);
						finished = false;
						myArray[0][checker->row+2][checker->col-2] = 'b';
						myArray[0][checker->row][checker->col] = '-';
						myArray[0][checker->row + 1][checker->col - 1] = '-';
						checker->row = checker->row+2;
						checker->col = checker->col-2;
						FILE* fr = fopen("boardPlay.txt", "a");
										fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
										fclose(fr);
					}
				}
			}

			//RIGHT WALL TOP CORNER
			if (checker->row == 0) {
				if (myArray[0][checker->row+1][checker->col-1] == '-' && finished){
					printf("(%d, %d) ",(checker->row+1), (checker->col-1));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row+1][checker->col-1] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					checker->row = checker->row+1;
					checker->col = checker->col-1;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}

				else {
					//JUMP OVER THE CHECKER
					if (myArray[0][checker->row+2][checker->col-2] == '-' && finished) {
						printf("(%d, %d) ",(checker->row+2), (checker->col-2));
						fflush(stdout);
						finished = false;
						myArray[0][checker->row+2][checker->col-2] = 'b';
						myArray[0][checker->row][checker->col] = '-';
						myArray[0][checker->row + 1][checker->col - 1] = '-';
						checker->row = checker->row+2;
						checker->col = checker->col-2;
						FILE* fr = fopen("boardPlay.txt", "a");
										fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
										fclose(fr);
					}
				}
			}

			//RIGHT WALL BOTTOM CORNER
			if (checker->row == 7) {
				if (myArray[0][checker->row-1][checker->col-1] == '-' && finished){
					printf("(%d, %d) ",(checker->row-1), (checker->col-1));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row-1][checker->col-1] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					checker->row = checker->row-1;
					checker->col = checker->col-1;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}
				else {
					//JUMP OVER THE CHECKER
					if (myArray[0][checker->row-2][checker->col-2] == '-' && finished) {
						printf("(%d, %d) ",(checker->row-2), (checker->col-2));
						fflush(stdout);
						finished = false;
						myArray[0][checker->row-2][checker->col-2] = 'b';
						myArray[0][checker->row][checker->col] = '-';
						myArray[0][checker->row - 1][checker->col - 1] = '-';
						checker->row = checker->row-2;
						checker->col = checker->col-2;
						FILE* fr = fopen("boardPlay.txt", "a");
										fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
										fclose(fr);
					}
				}
			}

		}
		//LEFT WALL KING
		if (checker->col == 0){
			//LEFT WALL NOT CORNER
			if (checker->row-1 >= 0 && checker->row != 0  && checker->row != 7) {
				if (finished && myArray[0][checker->row-1][checker->col+1] == '-'){
					printf("(%d, %d) ",(checker->row-1), (checker->col+1));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row-1][checker->col+1] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					checker->row = checker->row-1;
					checker->col = checker->col+1;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}

				else {
					//JUMP OVER THE CHECKER
					if (finished && checker->row-2 >= 0 && myArray[0][checker->row-2][checker->col+2] == '-') {
						printf("(%d, %d) ",(checker->row-2), (checker->col+2));
						fflush(stdout);
						finished = false;
						myArray[0][checker->row-2][checker->col+2] = 'b';
						myArray[0][checker->row][checker->col] = '-';
						myArray[0][checker->row - 1][checker->col + 1] = '-';
						checker->row = checker->row-2;
						checker->col = checker->col+2;
						FILE* fr = fopen("boardPlay.txt", "a");
										fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
										fclose(fr);
					}
				}

				if (finished && checker ->row+1 <= 7 && myArray[0][checker->row+1][checker->col+1] == '-'){
					printf("(%d, %d) ",(checker->row+1), (checker->col+1));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row+1][checker->col+1] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					checker->row = checker->row+1;
					checker->col = checker->col+1;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}

				else {
					//JUMP OVER THE CHECKER
					if (finished && checker ->row+2 <= 7 && myArray[0][checker->row+2][checker->col-2] == '-') {
						printf("(%d, %d) ",(checker->row+2), (checker->col+2));
						fflush(stdout);
						finished = false;
						myArray[0][checker->row+2][checker->col+2] = 'b';
						myArray[0][checker->row][checker->col] = '-';
						myArray[0][checker->row + 1][checker->col + 1] = '-';
						checker->row = checker->row+2;
						checker->col = checker->col+2;
						FILE* fr = fopen("boardPlay.txt", "a");
										fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
										fclose(fr);
					}
				}
			}

			//LEFT WALL TOP CORNER
			if (checker->row == 0) {
				if (finished && myArray[0][checker->row+1][checker->col+1] == '-'){
					printf("(%d, %d) ",(checker->row+1), (checker->col+1));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row+1][checker->col+1] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					checker->row = checker->row+1;
					checker->col = checker->col+1;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}

				else {
					//JUMP OVER THE CHECKER
					if (finished && myArray[0][checker->row+1][checker->col+1] != '-' && myArray[0][checker->row+2][checker->col+2] == '-') {
						printf("(%d, %d) ",(checker->row+2), (checker->col+2));
						fflush(stdout);
						finished = false;
						myArray[0][checker->row+2][checker->col+2] = 'b';
						myArray[0][checker->row][checker->col] = '-';
						myArray[0][checker->row + 1][checker->col + 1] = '-';
						checker->row = checker->row+2;
						checker->col = checker->col+2;
						FILE* fr = fopen("boardPlay.txt", "a");
										fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
										fclose(fr);
					}
				}
			}

			//LEFT WALL BOTTOM CORNER
			if (checker->row == 7) {
				if (finished && myArray[0][checker->row-1][checker->col+1] == '-'){
					printf("(%d, %d) ",(checker->row-1), (checker->col+1));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row-1][checker->col+1] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					checker->row = checker->row-1;
					checker->col = checker->col+1;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}

				else {
					//JUMP OVER THE CHECKER
					if (finished && myArray[0][checker->row-2][checker->col+2] == '-') {
						printf("(%d, %d) ",(checker->row-2), (checker->col+2));
						fflush(stdout);
						finished = false;
						myArray[0][checker->row-2][checker->col+2] = 'b';
						myArray[0][checker->row][checker->col] = '-';
						myArray[0][checker->row - 1][checker->col + 1] = '-';
						checker->row = checker->row-2;
						checker->col = checker->col+2;
						FILE* fr = fopen("boardPlay.txt", "a");
										fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
										fclose(fr);
					}
				}
			}
		}
		//NO WALL KING
		if(checker->col != 7 && checker->col != 0) {
			//top left
			if (finished && checker->row-1 >= 0 && myArray[0][checker->row-1][checker->col-1] == '-') {
				printf("(%d, %d) ",(checker->row-1), (checker->col-1));
				fflush(stdout);
				finished = false;
				myArray[0][checker->row-1][checker->col-1] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				checker->row = checker->row-1;
				checker->col = checker->col-1;
				FILE* fr = fopen("boardPlay.txt", "a");
								fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
								fclose(fr);
			}
			else {
				if (finished && checker->row - 2 >= 0 && checker->col - 2 >= 0 && myArray[0][checker->row-2][checker->col-2] == '-') {
					printf("(%d, %d) ",(checker->row-2), (checker->col-2));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row-2][checker->col-2] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					myArray[0][checker->row - 1][checker->col - 1] = '-';
					checker->row = checker->row-2;
					checker->col = checker->col-2;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}
			}
			//top right
			if (finished && checker->row-1 >= 0 && myArray[0][checker->row-1][checker->col+1] == '-') {
				printf("(%d, %d) ",(checker->row-1), (checker->col+1));
				fflush(stdout);
				finished = false;
				myArray[0][checker->row-1][checker->col+1] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				checker->row = checker->row-1;
				checker->col = checker->col+1;
				FILE* fr = fopen("boardPlay.txt", "a");
								fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
								fclose(fr);
			}
			else {
				if (finished && checker->row - 2 >= 0 && checker->col + 2 >= 0 && myArray[0][checker->row-2][checker->col+2] == '-') {
					printf("(%d, %d) ",(checker->row-2), (checker->col+2));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row-2][checker->col+2] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					myArray[0][checker->row - 1][checker->col + 1] = '-';
					checker->row = checker->row-2;
					checker->col = checker->col+2;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}
			}
			//bottom left
			if (finished && checker->row+1 >= 0 && checker->row+1 <= 7 && myArray[0][checker->row+1][checker->col-1] == '-') {
				printf("(%d, %d) ",(checker->row+1), (checker->col-1));
				fflush(stdout);
				finished = false;
				myArray[0][checker->row+1][checker->col-1] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				checker->row = checker->row+1;
				checker->col = checker->col-1;
				FILE* fr = fopen("boardPlay.txt", "a");
								fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
								fclose(fr);
			}
			else {
				if (finished && checker->row + 2 >= 0 && checker->row+2 <= 7 && checker->col - 2 > 0 && myArray[0][checker->row+2][checker->col-2] == '-') {
					printf("(%d, %d) ",(checker->row+2), (checker->col-2));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row+2][checker->col-2] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					myArray[0][checker->row + 1][checker->col - 1] = '-';
					checker->row = checker->row+2;
					checker->col = checker->col-2;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}
			}
			//bottom right
			if (finished && checker->row+1 >= 0 && checker->row+1 <= 7 && myArray[0][checker->row+1][checker->col+1] == '-') {
				printf("(%d, %d) ",(checker->row+1), (checker->col+1));
				fflush(stdout);
				finished = false;
				myArray[0][checker->row+1][checker->col+1] = 'b';
				myArray[0][checker->row][checker->col] = '-';
				checker->row = checker->row+1;
				checker->col = checker->col+1;
				FILE* fr = fopen("boardPlay.txt", "a");
								fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
								fclose(fr);
			}
			else {
				if (finished && checker->row + 2 >= 0 && checker->row+2 <= 7 && checker->col + 2 > 0 && myArray[0][checker->row+2][checker->col+2] == '-') {
					printf("(%d, %d) ",(checker->row+2), (checker->col+2));
					fflush(stdout);
					finished = false;
					myArray[0][checker->row+2][checker->col+2] = 'b';
					myArray[0][checker->row][checker->col] = '-';
					myArray[0][checker->row + 1][checker->col + 1] = '-';
					checker->row = checker->row+2;
					checker->col = checker->col+2;
					FILE* fr = fopen("boardPlay.txt", "a");
									fprintf(fr, "CPU moved a checker to row %d column %d\n", checker->row, checker ->col);
									fclose(fr);
				}
			}

		}
	}
	return finished;

}






