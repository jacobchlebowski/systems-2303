/*
 * Tests.cpp
 *
 *  Created on: Feb 1, 2020
 *      Author: Therese
 */

#include "Tests.h"
#include <stdbool.h>

Tests::Tests() {
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

bool Tests::tests()
{
	bool answer = true;

	bool ok1 = testReadFile();
	bool ok2 = testGotAdjacencyMatrix();
	bool ok3 = testMakeLList();
	bool ok4 = testEnqueue();
	//pedagogical bool ok5 = testRemoveFromList();
	bool ok6 = testPrintHistory();
	answer = ok1 && ok2 && ok3 && ok4  && ok6;
	return answer;
}

bool Tests::testReadFile()
{
	puts("starting testReadFile"); fflush(stdout);
	bool ok = false;
	//the file tells how many rooms there are
	int answer = -1;
	int rightAnswer = 8;


	AdjMat* adjMP = new AdjMat();
	Room* theRoomPs[10];//addresses for 10 rooms

	Production* pP = new Production();

	ok = pP->readFile("houseGraph.txt", &answer, adjMP, theRoomPs); //read the file
	if(ok)
	{
		if(answer!=rightAnswer)
		{
			puts("test failed on number of rooms");
		}

	}
	puts("The adjacency matrix");
	for(int i = 0; i<answer; i++)
	{
		for(int j = 0; j<answer; j++)
		{
			printf("%d",adjMP->getEdge(i, j));

		}
		printf("\n");
	}
	puts("The treasure values");
	for(int i = 0; i<answer; i++)
	{
		printf("%f\n", theRoomPs[i]->treasure);
	}
	if(ok)
	{
		puts("testReadfile did pass");
	}
	else
	{
		puts("testReadfile did not pass.");
	}

	return ok;
}
bool Tests::testEnqueue()
{
    bool ok = true;

    LinkedList* lp = new LinkedList();
    LinkedList* lp2 = new LinkedList();
    LLNode* llList = lp->makeEmptyLinkedList();
    LLNode* llList2 = lp2->makeEmptyLinkedList();


    Room* roomP = (Room*)malloc(sizeof(Room));
    roomP->treasure = 100.5;
    roomP->searched = false;
    roomP->roomNumber = 1;

    Payload* roomPayload = roomP;
    llList->payP = roomPayload;

    lp->savePayload(llList2, roomP);

    if (llList2->payP != llList->payP) {
        ok = false;
    }

    if(ok)
    {
        puts("testEnqueue did pass");
    }
    else
    {
        puts("testEnqueue did not pass.");
    }
    return ok;
}
bool Tests::testGotAdjacencyMatrix()
{
    bool ans = true;

    Room* rooms[10];
    int numberOfRooms = 8;

    AdjMat* adjP = new AdjMat();

    AdjMat* dummy = (AdjMat*) malloc(sizeof(AdjMat));

    adjP->init();

      adjP->setEdge(1, 0);
    adjP->setEdge(2, 1);
    adjP->setEdge(3, 0);
    adjP->setEdge(3, 2);
    adjP->setEdge(4, 1);
    adjP->setEdge(4, 3);
    adjP->setEdge(5, 0);
    adjP->setEdge(5, 2);
    adjP->setEdge(6, 1);
    adjP->setEdge(6, 2);
    adjP->setEdge(6, 5);
    adjP->setEdge(7, 0);
   adjP->setEdge(7, 1);
    adjP->setEdge(7, 2);
    adjP->setEdge(7, 4);


    Production* pP = new Production();
    pP->readFile((char*) "houseGraph.txt", &numberOfRooms, dummy, rooms);

    for (int i = 0; i < numberOfRooms; i++) {
        for (int j = 0; j < numberOfRooms; j++) {
            if (adjP->getEdge(i, j) != adjP->getEdge(i, j)) {
                ans = false;
            }
        }
    }

    if (ans) {
        puts("test got adjacency matrix pass");
    } else {
        puts("test got adjacency matrix not pass");
    }

    return ans;
}

bool Tests::testMakeLList()
{
	bool ok = true;
		puts("starting testMakeLList");fflush(stdout);
		//what are the criteria for success for make LList?
		//should be able to make one, add data to it, get the data back
		//test case 1:
		LinkedList* lp = new LinkedList();
		LLNode* theListP = lp->makeEmptyLinkedList();
		bool rightAnswer = true;
		bool answer = lp->isEmpty(theListP);
		if(answer!=rightAnswer)
		{
			ok = false;
		}
		//test case 2:
		//TODO more test cases here
		if(ok)
		{
			puts("test make LList did pass");
		}
		else
		{
			puts("test make LList did not pass.");
		}

		return ok;
}
bool Tests::testPrintHistory()
{
    bool ok = true;

    LinkedList* lp = new LinkedList();
    LLNode* theListP = lp->makeEmptyLinkedList();
    for (int i = 0; i < 5; i++) {
        Room* room = (Room*) malloc(sizeof(Room));
        room->roomNumber = 1+i;
        room->searched = false;
        room->treasure= 20.0+i;
        lp->savePayload(theListP, room);
    }
    lp->printHistory((LLNode2*)theListP);

    Production* pP = new Production();
    if(pP->getYesNo((char*)"Do the calls look right?")){
                puts("testprintHistory did pass");
            }
            else{
                puts("testprintHistory did not pass");
            }

    return ok;
}



