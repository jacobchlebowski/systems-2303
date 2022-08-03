/*
 * Board.cpp
 *
 *  Created on: Aug 2, 2021
 *      Author: theresesmith
 */

#include "Board.h"
#include <iostream>
#include <fstream>
using namespace std;

Board::Board() {
    // TODO Auto-generated constructor stub

}

Board::~Board() {
    // TODO Auto-generated destructor stub
}

void Board::displayBoard()
{

        std::ofstream outfile ("boards.txt");
        outfile << "--b---b-\n--------\n--------\n--------\n--------\n--------\n--------\n-r---r--\n" << endl;

        string name;
        std::ifstream dataFile("boards.txt");
        int count = 0;
        while(!dataFile.fail() && !dataFile.eof() && count < 8){
            dataFile >> name;
           cout<< name << endl;
           count++;
        }

        outfile.close();

}
void Board::printToFile(char* filename)
{
    //TODO
}
