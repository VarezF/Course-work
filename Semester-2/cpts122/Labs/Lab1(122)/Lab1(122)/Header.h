#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*******************************************************************************************
* Programmer: Freya Varez                                                                   *
* Class: CptS 122, Summer 2018; Lab Section 1											    *
* Programming Assignment: Lab3															    *
* Date: June 13, 2018                                                                       *
* Description: Various programs																*     
*******************************************************************************************/

typedef struct data
{
	int diameter;
}Data;

typedef struct node
{
	Data item;
	struct node *pNext;
}Node;

typedef struct stack
{
	Node *pTop;
}Stack;

Node *makeNode(Data newData);

int push(Stack *pStack, Data newData);



