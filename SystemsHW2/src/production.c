/*
 * production.c
 *
 *  Created on: Feb 6, 2021
 *      Author: theresesmith
 */

#include "production.h"

bool production(int argc, char* argv[])
{
	bool answer = true;
	int nCalls = -1;

		if(argc <=1) //no interesting information
		{
			puts("Didn't find any arguments.");
			fflush(stdout);
			answer = false;
		}
		else //there is interesting information
		{
			printf("Found %d arguments.\n", argc);
			fflush(stdout);
			long aL=-1L;


			for(int i = 1; i<argc; i++) //don't want to read argv[0]
			{//argv[i] is a string
				//in this program our arguments are a filename followed by the max of rooms, followed by max of treasure
				switch(i)
				{
				case 1:

					//this is the number of calls

					aL= strtol(argv[i], NULL, 10);
					nCalls = (int) aL;
					if(nCalls <0)
					{
						answer = false;
					}
					printf("Number of calls is %d\n",nCalls);fflush(stdout);
					break;

				default:
					puts("Unexpected argument count."); fflush(stdout);
					answer = false;
					break;
				}//end of switch
			}//end of for loop on argument count
			puts("after reading arguments"); fflush(stdout);

		}//end of command line arguments


		//initialize a linked list
		LLNode* theListP = makeEmptyLinkedList();
		LLNode* theListMatch = makeEmptyLinkedList();

		//obtain space for bingo card

		cardCellContent** theSpaceP = (cardCellContent**) malloc(5*5*sizeof(cardCellContent*));
	    initSpace(theSpaceP, 5);

	   // displayCard
	    puts("\nStarting Board:");
        displaySpace(theSpaceP, 5);
        //the caller is going call some random values


        bool done=false;
	    for(int i = 0; i<nCalls&&(!done); i++)
	    {
	    	//get what caller calls
	    	Combo* c = combination();
	    	printf("\nLetter: %c ", c->letter);
	    	printf("Number: %c\n", c->num);

	    	//store in LinkedList
	    	savePayload(theListP,c);

	    	//check?
	    	if(check(theSpaceP, 5, c)){
	    		savePayload(theListMatch,c);
	    	}



	    	//show/display the board //lowercase?
	    	displaySpace(theSpaceP, 5);


	    	//did we win?
	    	if(isWin(theSpaceP,5)){
	    	 puts("I WIN!\n");
	    	 done=true;
	    	}

	    }

	    //printCalls
	    printCalls(theListMatch);


		return answer;
}
bool getYesNo(char* query)
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
