/*
 * LinkedList.h
 *
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


typedef struct CheckerLoc
{
	int roomNumber;
	float treasure;
}CheckerLoc;

typedef struct SearchResults
{
	int roomNumber;
	float treasure;
}SearchResults;
typedef CheckerLoc Payload;
typedef SearchResults Payload2;
struct LLNode;
typedef struct LLNode
{
	struct LLNode* next;
	struct LLNode* prev;
	Payload* payP;
}LLNode;
typedef struct LLNode2
{
	struct LLNode2* next;
	struct LLNode2* prev;
	Payload2* payP;
}LLNode2;

typedef struct backFromDQFIFO
{
	Payload* mp;
	LLNode* newQHead;
}backFromDQFIFO;

class LinkedList{
public:

	bool isEmpty(LLNode* lp);
	bool isEmpty2(LLNode2* lp);
	LLNode* makeEmptyLinkedList();
	LLNode2* makeEmptyLinkedList2();
	void savePayload(LLNode* lp, Payload* mp);
	void savePayload2(LLNode2* lp, Payload2* mp);
	Payload* dequeueLIFO(LLNode* lp);
	backFromDQFIFO* dequeueFIFO(LLNode* lp);
	void printHistory(LLNode2* hp);
	LLNode* removeFromList(LLNode* hP, Payload* pP);


};


#endif /* LINKEDLIST_H_ */
