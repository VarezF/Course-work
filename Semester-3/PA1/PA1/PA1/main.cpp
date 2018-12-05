/*Programmer: Freya Varez
Date: 8/27/2018
Assignment: PA1
Details: Tests the time-efficiency of node insertion into a pre-sorted linked list*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>

typedef struct Node {
	int value;
	struct Node* pNext = nullptr;
}node;

void insertNode(Node **pHead, Node **pTail, int data)
{
	Node *pMem = new Node;	//create new node
	pMem->value = data;

	if (*pHead == nullptr) {	//insert into empty list
		*pHead = pMem;
		*pTail = pMem;
	}
	else if (pMem->value < (*pHead)->value) {	//insert at front
		pMem->pNext = *pHead;
		*pHead = pMem;
	}
	else {	//insert into nonempty list (order lowest->highest
		Node *pNextNode = (*pHead)->pNext, *pPrevNode = *pHead;

		while (1) {
			if (pNextNode == nullptr) {	//insert at end
				pPrevNode->pNext = pMem;
				*pTail = pMem;
				return;
			}
			else if(pMem->value < pNextNode->value) {
				pPrevNode->pNext = pMem;
				pMem->pNext = pNextNode;
				return;
			}
			pNextNode = pNextNode->pNext;
			pPrevNode = pPrevNode->pNext;
		}
	}
}

/*clock_t t;
t = clock();
//////stuff
t = clock() - t;
printf("It took me %d clicks (%f seconds).\n", t, ((float)t) / CLOCKS_PER_SEC);
return 0;*/

int main()
{
	char fileLoc[100] = { "\0" };	//create filestream to respective (user-prompted) file location
	std::cout << "Enter file location:	";
	std::cin.getline(fileLoc, 100);
	system("cls");

	std::fstream infile;
	infile.open(fileLoc, std::fstream::in);
	Node *pHead = nullptr, *pTail = nullptr;	//pointer to head of list
	std::string tempStr; //temporary variable for integer value read from filestream

	int min = 0, max = 0, med = 0, tempInt = 0, total = 0;
	clock_t time_insert = 0, start_insert = 0, time_min = 0, time_max = 0, time_med = 0;
	//////////////////////////////////time_insert/////////////////////////////////////////////////////////////
	start_insert = clock();
	while (!infile.eof()){	//reads line-by-line until end of file
		std::getline(infile, tempStr);	//read line and capture min/max/med as neccessary
		if (tempStr == "")
			continue;
		tempInt = std::stoi(tempStr);
		insertNode(&pHead, &pTail, tempInt);	//input line into linked list
		total++;
	}
	time_insert = clock() - start_insert;
	
	Node *pCur = pHead;
	int count = 0;
	///////////////////////////////////////time_med////////////////////////////////////////////////////////////////
	clock_t start_med = clock();
	while (count < (total - 1)/ 2) {
		pCur = pCur->pNext;
		count++;
	}
	if (total % 2 == 0) {
		med = (pCur->value + pCur->pNext->value) / 2;
	}
	else med = pCur->value;
	time_med = clock() - start_med;
	/////////////////////////////////time_min and time_max/////////////////////////////////////////////////////////
	clock_t start_min = clock();
	max = pTail->value;
	time_min = clock() - start_min;

	clock_t start_max = clock();
	min = pHead->value;
	time_max = clock() - start_max;
	////////////////////////////////Message///////////////////////////////////////////////////////////////////////
	std::cout << "_____________________Message_________________________" << std::endl
		<< "min:         " << min << std::endl
		<< "max:         " << max << std::endl
		<< "med:         " << med << std::endl
		<< "time_insert: " << ((float)time_insert) * 1000/ CLOCKS_PER_SEC << " millisecond(s)" << std::endl
		<< "time_max:    " << ((float)time_max) * 1000/ CLOCKS_PER_SEC << " millisecond(s)" << std::endl
		<< "time_min:    " << ((float)time_min) * 1000/ CLOCKS_PER_SEC << " millisecond(s)" << std::endl
		<< "time_med:    " << ((float)time_med) * 1000/ CLOCKS_PER_SEC << " millisecond(s)" << std::endl;
}