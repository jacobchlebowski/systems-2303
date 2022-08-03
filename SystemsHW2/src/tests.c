/*
 * tests.c
 *
 *  Created on: Jul 4, 2019
 *      Author: Therese
 */

#include "tests.h"
#include "production.h"
#include "LinkedList.h"


bool tests()
{
	bool answer = false;

	//test the functions that get used
	//order the tests from simplest first -- this produces building blocks for use in more complex tests
	//check how functions are used in production code, this gives clues about how to provide the arguments for the invocation
	bool ok1 = testReadFile();
	bool ok3 = testMakeLList();
	bool ok4 = testEnqueue();
	bool ok5 = testPrintCalls();
	bool ok6 = testInitializeBoard();
	bool ok7 = testDisplaySpace();
	bool ok8 = testIsWin();
	answer = ok1 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8;
	//answer = true;
	return answer;
}

bool testReadFile()
{
	puts("starting testReadFile"); fflush(stdout);
	bool ok = true;

//	cardCellContent** theSpaceP = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));
//	cardCellContent** nextSpace = theSpaceP+1;
//	printf("first is %x and second is %x \n", theSpaceP, nextSpace);
//
//	cardCellContent* where = (cardCellContent*) theSpaceP;
//	cardCellContent* whereNext = where+1;
//	printf("first is %x and second is %x\n", where, whereNext);






	return ok;
}


bool testMakeLList()
{
	bool ok = true;
	puts("starting testMakeLList");fflush(stdout);
	//what are the criteria for success for make LList?
	//should be able to make one, add data to it, get the data back
	//test case 1:
	LLNode* theListP = makeEmptyLinkedList();
	if(theListP == NULL)
	{
		ok = false;
	}
	bool rightAnswer = true;
	bool answer = isEmpty(theListP);
	if(answer!=rightAnswer)
	{
		ok = false;
	}
	//test case 2:
	//TODO more test cases here
	Combo* dummyCombo = (Combo*) malloc(sizeof(Combo));
	dummyCombo->letter = 'B';
	dummyCombo->num = '7';
	savePayload(theListP, dummyCombo);

	if(theListP->payP != dummyCombo) { // i don't think this is right
	    ok = false;
	}
	if(ok)
	{

		puts("test make LList did pass.");
	}
	else
	{
		puts("test make LList did not pass.");
	}

	return ok;
}
bool testEnqueue()
{
    bool ok = true;
    LLNode* theListP = makeEmptyLinkedList();

    for (int i = 0; i < 50; i++) {
        Combo* c = combination();
        savePayload(theListP, c);
    }

    int count = 0;
    while (theListP != NULL) {
        count++;
        theListP = (LLNode *) theListP->next;
    }

    if (count != 50) {
        ok = false;
    }

    if(ok)
    {
        puts("testEnqueue did pass.");
    }
    else
    {
        puts("testEnqueue did not pass.");
    }
    return ok;
}
bool testRemoveFromList()
{
	bool ok = true;
	//cases:
	//1 list is empty:return same list
	//2 list is of length one, and item is present: return empty list
	//3 list is of length one, and item is not present: return same list
	//4 list is longer than one, item is present, at first location: return list starting at second element
	//5 list is longer than one, item is present, not at first location: return list with item removed
	//6 list is longer than one, item is not present: return same list
	LLNode* case1 = makeEmptyLinkedList();
//	Payload* pay1 = (Payload*) malloc(sizeof(Room));
//	pay1->roomNumber = 1;
//	LLNode* ans = removeFromList(case1, pay1);
//	if((ans != case1) || (ans->payP != (Payload*)0))
//	{
//		ok = false;
//
//	}
//	printf("testRemove case 1 with %d\n", ok); fflush(stdout);
//	savePayload(case1, pay1);
//	//this is case2
//	ans = removeFromList(case1, pay1);
//	if((ans != case1) || (ans->payP != (Payload*)0))
//	{
//		ok = false;
//
//	}
//	printf("testRemove case 2 with %d\n", ok); fflush(stdout);
//	//now case 3
//	Payload* pay3 = (Payload*) malloc(sizeof(Room));
//	pay3->roomNumber = 3;
//	ans = removeFromList(case1, pay3);
//	if(ans != case1)//this is only a partial check for list unchanged
//	{
//		ok = false;
//
//	}
//	printf("testRemove case 3 with %d\n", ok); fflush(stdout);
//	//now case 4
//	case1 = makeEmptyLinkedList();
//	pay1 = (Payload*) malloc(sizeof(Room));
//	pay1->roomNumber = 1;
//	savePayload(case1, pay1);
//	pay3 = (Payload*) malloc(sizeof(Room));
//	pay3->roomNumber = 3;
//	savePayload(case1, pay3);
//	ans = removeFromList(case1, pay1);
//
//	if(ans == case1)
//	{
//		ok = false;
//
//	}
//	printf("testRemove case 4 with %d\n", ok); fflush(stdout);
//	//now case 5
//	case1 = makeEmptyLinkedList();
//	pay1 = (Payload*) malloc(sizeof(Room));
//	pay1->roomNumber = 1;
//	savePayload(case1, pay1);
//	pay3 = (Payload*) malloc(sizeof(Room));
//	pay3->roomNumber = 3;
//	savePayload(case1, pay3);
//	//puts("trying case 5");fflush(stdout);
//	ans = removeFromList(case1, pay3);//ans should be equal to case1
//	LLNode* theNext = (LLNode*) ans->next; //this is element where pay3 got attached
//	Payload* check = (Payload*) 0;
//	if (theNext)
//	{
//		check = theNext->payP; //this should be pay3, which should have been removed
//	}
//	//printf("testRemove returned from case 5\n"); fflush(stdout);
//	if((ans != case1) || (check != (Payload*)0))//disquiet
//	{
//		ok = false;
//
//	}
//	//printf("ans == case1 is %d\n", ans==case1);
//	//printf("check != 0 is %d\n", check != (Payload*)0);
//	printf("testRemove case 5 with %d\n", ok); fflush(stdout);
//	//now case 6
//	case1 = makeEmptyLinkedList();
//	pay1 = (Payload*) malloc(sizeof(Room));
//	pay1->roomNumber = 1;
//	savePayload(case1, pay1);
//	pay3 = (Payload*) malloc(sizeof(Room));
//	pay3->roomNumber = 3;
//	savePayload(case1, pay3);
//	Payload* another = (Payload*) malloc(sizeof(Room));
//	another->roomNumber=2;
//	ans = removeFromList(case1, another);
//	if((ans != case1))
//	{
//		ok = false;
//
//	}
//	printf("testRemove case 6 with %d\n", ok); fflush(stdout);
	return ok;
}


bool testInitializeBoard(){
	bool ok = true;
	cardCellContent** corner = (cardCellContent**) malloc(1*1*sizeof(cardCellContent*));
	initSpace(corner, 1);
	if(corner==NULL){
		ok=false;
	}
	if((*corner)->matched){
		ok=false;
	}
	if((*corner)->col==-1){
		ok=false;
	}
	if((*corner)->row==-1){
			ok=false;
		}

	if(ok){
		puts("testInitializeBoard did pass");
	}
	else{
		puts("testInitializeBoard did not pass");
	}

	return ok;
}










bool testDisplaySpace(){
	bool ok=true;
	cardCellContent** corner = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));
	for(int row = 0; row< 5; row++)
		{
			for(int col = 0; col < 5; col++)
			{
				cardCellContent* x = (cardCellContent*) malloc (sizeof(cardCellContent)); //reserve a cardCell on heap
				x->row = 0;
				x->col = 0;
				x->matched = false;
				x->letter = 'A';
				x->digit = '0';
				cardCellContent**  thatCellP = corner + row*5 + col;
				*thatCellP = x; //put its address into bingo card space

			}
		}

	displaySpace(corner, 5);

	if(getYesNo("Does it look right?")){
			puts("testDisplaySpace did pass");
		}
		else{
			puts("testDisplaySpace did not pass");
		}

	return ok;
}


bool testPrintCalls()
{
    bool ok = true;

    LLNode* theListP = makeEmptyLinkedList();
    for (int i = 0; i < 5; i++) {
        Combo* combo = (Combo*) malloc(sizeof(Combo));
        combo->letter = 'A';
        combo->num = '0' + i;
        savePayload(theListP, combo);
    }
    printCalls(theListP);

    if(getYesNo("Do the calls look right?")){
    			puts("testprintCalls did pass");
    		}
    		else{
    			puts("testprintCalls did not pass");
    		}



    return ok;
}



bool testIsWin(){
    bool ok = true;
    cardCellContent** testWin = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));
    initSpace(testWin, 5);

    if(isWin(testWin, 5)){
        ok = false;
    }
    for(int row = 0; row< 5; row++)
        {

            for(int col = 0; col < 5; col++)
            {
                cardCellContent**  thatCellP = testWin + row*5 + col;
                (*thatCellP)->matched = true;

            }
        }
    if(isWin(testWin, 5) == false){
        ok = false;
    }


    if(ok){
            puts("testIsWin");
        }
        else
        {
            puts("testIsWin");
        }

        return ok;

}



