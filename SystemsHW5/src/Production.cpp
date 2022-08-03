/*
 * Production.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Production.h"
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

Production::Production() {
	// TODO Auto-generated constructor stub

}

Production::~Production() {
	// TODO Auto-generated destructor stub
}

bool Production::prod(int argc, char* argv[])
{
	printf("Starting Production\n");
	bool answer = false;

	remove("gameState.txt");
	std::ofstream outfile ("gameState.txt");
	outfile<< "--b---b-\n--------\n--------\n--------\n--------\n--------\n--------\n-r---r--\n"<< std::endl;

	remove("boardPlay.txt");
	std::ofstream outfile2 ("boardPlay.txt");
	outfile2<< "--b---b-\n--------\n--------\n--------\n--------\n--------\n--------\n-r---r--\n"<< std::endl;

	outfile.close();
	outfile2.close();

	if(argc <=1) //no interesting information
	{
		puts("Didn't find any arguments.");
		fflush(stdout);
		answer = false;
	}
	else //there is interesting information
	{
		printf("Found %d interesting arguments.\n", argc-1);
		fflush(stdout);
		char filename[FILENAMELENGTHALLOWANCE];
		char* eptr=(char*) malloc(sizeof(char*));
		long aL=-1L;
		int maxRooms;
		float maxTreasure;
		double maxTreas;

		for(int i = 1; i<argc; i++) //don't want to read argv[0]
		{//argv[i] is a string

			switch(i)
			{
			case 1:
				//this is filename
				printf("The length of the filename is %d.\n",(int)strlen(argv[i]));
				printf("The proposed filename is %s.\n", argv[i]);
				if(strlen(argv[i])>=FILENAMELENGTHALLOWANCE)
				{
					puts("Filename is too long.");
					fflush(stdout);
					answer = false;
				}
				else
				{
					strcpy(filename, argv[i]);
					printf("Filename was %s.\n", filename);
					fflush(stdout);
				}
				break;
			case 2:
				//this is maximum number of rooms

				aL = strtol(argv[i], &eptr, 10);
				maxRooms = (int) aL;
				printf("Number of rooms is %d\n",maxRooms);fflush(stdout);
				break;
			case 3:
				//this is maximum amount of treasure

				maxTreas = atof(argv[i]);
				printf("Amount of  treasure is %f\n",maxTreas);fflush(stdout);
				maxTreasure = (float) maxTreas;
				break;

			default:
				puts("Unexpected argument count."); fflush(stdout);
				answer = false;
				break;
			}//end of switch
		}//end of for loop on argument count
		puts("after reading arguments"); fflush(stdout);

		//we'll want to read the file
		Board* theBoard = new Board();

		puts("Before read file"); fflush(stdout);

		answer = readFile(filename, theBoard); //read the files

		puts("Back from read file"); fflush(stdout);






	}
	return answer;
}

bool Production::readFile(char* filename, Board* theBoard)
{
	bool ok = true;
	char temp = '-';
	FILE* fp = fopen(filename, "r"); //read the file

	if (fp == NULL)
	{
		puts("Error! opening file");

	}
	else
	{
		Checker* r1 = new Checker;
		r1->col = 1;
		r1->row = 7;
		r1->pawn = true;
		r1->red = true;
		r1->dead = false;
		Checker* r2 = new Checker;
		r2->col = 5;
		r2->row = 7;
		r2->pawn = true;
		r2->red = true;
		r2->dead = false;
		Checker* b1 = new Checker;
		b1->col = 2;
		b1->row = 0;
		b1->pawn = true;
		b1->red = false;
		b1->dead = false;
		Checker* b2 = new Checker;
		b2->col = 6;
		b2->row = 0;
		b2->pawn = true;
		b2->red = false;
		b2->dead = false;

		//bool ok = true;
		//char temp = '-';
		//FILE * fp = fopen(filename,"r"); // read the file
		//TODO read the board from the file,
		puts("\n Game Board:");
		ifstream file("gameState.txt");
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
		puts("\n");



		bool win = false;
		while (win == false) {


			//discover checkers
			//make instances of class checker as needed
			//board needs to keep track of instances of checkers
			//checkers might also know where they are...


			//instance CheckerMove
			CheckerMove* cm = new CheckerMove;
			bool legit = false;
			while (legit == false) {
				if (r1->dead == false) {
					std::cout << "Checker 1 is currently at " << "(" << r1->row << ", " << r1->col << ")" << endl;
					std::cout << "Checker 1 Possible Moves: ";
					fp = fopen("boardPlay.txt", "a");
					fprintf(fp, "Checker 1 is currently at (%d,%d)\n", r1->row, r1->col);
					fprintf(fp, "Checker 1 Possible moves: ");
					fflush(fp);
				}
				//Checker 1 = r1
				fp = fopen("boardPlay.txt", "a");
				std::string possibleMoves = cm->canMove(r1,myArray);
				std::cout << endl;
				int length = possibleMoves.length();
				for (int i = 0; i <= length - 2; i = i + 2) {
					fprintf(fp,"(%s,%s) ",possibleMoves.substr(i,1).c_str(),possibleMoves.substr(i+1,1).c_str());
					fflush(fp);
				}
				fprintf(fp,"\n");
				fflush(fp);

				if (r2->dead == false) {
					std::cout << "Checker 2 is currently at " << "(" << r2->row << ", " << r2->col << ")" << endl;
					std::cout << "Checker 2 Possible Moves: ";
					fp = fopen("boardPlay.txt", "a");
					fprintf(fp, "Checker 2 is currently at (%d,%d)\n", r2->row, r2->col);
					fprintf(fp, "Checker 2 Possible moves: ");
					fflush(fp);
				}
				//Checker 2 = r2
				std::string possibleMoves2 = cm->canMove(r2,myArray);
				std::cout << endl;
				int length2 = possibleMoves2.length();
				for (int i = 0; i <= length2 - 2; i = i + 2) {
					fprintf(fp,"(%s,%s) ",possibleMoves2.substr(i,1).c_str(),possibleMoves2.substr(i+1,1).c_str());
					fflush(fp);
				}
				fprintf(fp,"\n");
				fflush(fp);

				//User Picks which checker they want to move
				std::string whichChecker;
				std::string xCoord;
				std::string yCoord;
				bool ok = false;
				while (ok == false) {
					std::cout << "Which checker do you want to move? (Enter 1 or 2): \n";
					fflush(stdout);
					std::cin >> whichChecker;
					if (whichChecker == "1") {
						if (r1->dead == false) {
							ok = true;
						}
						else {
							cout << "That checker is dead, try a different checker." << endl;
						}
					}
					if (whichChecker == "2") {
						if (r2->dead == false) {
							ok = true;
						}
						else {
							cout << "That checker is dead, try a different checker." << endl;
						}
					}
				}
				ok = false;
				while (ok == false) {
					std::cout << "Which row do you want to move your checker to: \n";
					std::cin >> xCoord;
					if (xCoord == "0" || xCoord == "1" || xCoord == "2" || xCoord == "3" || xCoord == "4" ||  xCoord == "5" || xCoord == "6" ||  xCoord == "7") {
						ok = true;
					}
				}
				ok = false;
				while (ok == false) {
					std::cout << "Which column do you want to move your checker to: \n";
					std::cin >> yCoord;
					if ((yCoord == "0" || yCoord == "1" || yCoord == "2" || yCoord == "3" || yCoord == "4" ||  yCoord == "5" || yCoord == "6" ||  yCoord == "7")) {
						ok = true;
					}
				}

				if (whichChecker == "1") {
					legit = cm->move(r1,xCoord,yCoord,possibleMoves,myArray);
				}
				if (whichChecker == "2") {
					legit = cm->move(r2,xCoord,yCoord,possibleMoves2,myArray);
				}

				if (legit == false) {
					std::cout << "You didn't put a correct move. Try again!" << endl;
				}

				if (legit == true) {
					int checkerNum = stoi(whichChecker);
					int xCoordNum = stoi(xCoord);
					int yCoordNum = stoi(yCoord);
					fp = fopen("boardPlay.txt", "a");
					fprintf(fp, "Player Moved Checker %d to row %d and column %d. \n", checkerNum, xCoordNum, yCoordNum);
					fclose(fp);

				}
			}

			//check if opponent checkers died
			if (myArray[0][b1->row][b1->col] == '-') {
				b1->dead = true;
			}
			if (myArray[0][b2->row][b2->col] == '-') {
				b2->dead = true;
			}

			puts("\n Game Board:");
			fopen(filename,"w"); // write the file
			//TODO write the board from the array,
			ofstream myFile("gameState.txt");
			if(myFile.is_open()){
				int count = 0;
				for(int i=0;i<8;i++){
					for(int j=0;j<8;j++){
						myFile << myArray[i][j];
						cout << myArray[i][j];
						if(count % 8 == 0){
							myFile << endl;
							cout << endl;
						}
					}
					count++;
				}
			}
			cout << endl;

			//to boardPlay
			fp = fopen("boardPlay.txt", "a");
			//TODO write the board from the array,
			int count = 0;
			for(int i=0;i<8;i++){
				for(int j=0;j<8;j++){
					fprintf(fp, "%s",  myArray[i][j].c_str());
					fflush(fp);
					if(count % 8 == 0){
						fprintf(fp, "\n");
						fflush(fp);
					}
				}
				count++;
			}



			bool cpu = true;
			if (b1->dead == false && b2->dead == false) {
				cpu = cm->canMoveCPU(b1,myArray);
				if (cpu == true) {
					cpu = cm->canMoveCPU(b2,myArray);
				}
			}

			else if (b1->dead == true && b2->dead == false) {
				cpu = cm->canMoveCPU(b2,myArray);
			}

			else if (b1->dead == false && b2->dead == true) {
				cpu = cm->canMoveCPU(b1,myArray);
			}

			if (cpu == true) {
				printf("Computer cannot move.");
			}

			if (b1->row == 7) {
				b1->pawn = false;
			}

			if (b2->row == 7) {
				b2->pawn = false;
			}

			puts("\n Game Board:");
			fopen(filename,"w"); // write the file
			//TODO write the board from the array,
			if(myFile.is_open()){
				myFile << endl;
				int count = 0;
				for(int i=0;i<8;i++){
					for(int j=0;j<8;j++){
						myFile << myArray[i][j];
						cout << myArray[i][j];
						if(count % 8 == 0){
							myFile << endl;
							cout << endl;
						}
					}
					count++;
				}
			}
			cout << endl;

			//to boardPlay
			fp = fopen("boardPlay.txt", "a");
			//TODO write the board from the array,
			int count2 = 0;
			for(int i=0;i<8;i++){
				for(int j=0;j<8;j++){

					fprintf(fp, "%s",  myArray[i][j].c_str());
					fflush(fp);
					if(count2 % 8 == 0){
						fprintf(fp, "\n");
						fflush(fp);
					}
				}
				count2++;
			}




			//check if our checkers died
			if (myArray[0][r1->row][r1->col] == '-') {
				r1->dead = true;
			}
			if (myArray[0][r2->row][r2->col] == '-') {
				r2->dead = true;
			}

			if (r1->dead == true && r2->dead == true) {
				win = true;
				cout << "You lost! Sorry!" << endl;
			}

			if (b1->dead == true && b2->dead == true){
				win = true;
				cout << "You win! Congratulations!" << endl;
			}
		}
	}
	fclose(fp);

	return ok;
}

bool Production::getYesNo(char* query)
{
	bool answer = true; //so far
	char said = 'x';
	do
	{
		printf("%s (y/n):",query);
		fflush(stdout);
		fflush(stdin);
		scanf("%c",&said);
	}while((said!= 'y')&&(said!='n'));
	if(said=='n')
	{
		answer=false;
	}


	return answer;
}




