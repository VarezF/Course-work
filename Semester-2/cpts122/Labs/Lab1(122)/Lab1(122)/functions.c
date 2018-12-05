#include "Header.h"

Node *makeNode(Data newData)
{
	Node *pMem = (Node *)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		pMem->item = newData;
		pMem->pNext = NULL;
	}

	return pMem;
}

int push(Stack *pStack, Data newData)
{
	Node *pMem = makeNode(newData);
	int success = 0;

	if (pMem != NULL)
	{
		success = 1;

		pMem->pNext = pStack->pTop;
		pStack->pTop = pMem;
	}

	return success;
}

void pop(Stack *pStack)
{
	Node *pTemp = pStack->pTop;

	pStack->pTop = pStack->pTop->pNext;

	free(pTemp);
}
/*1.   For the following problem define a stackNode struct with data of type double.Implement the following operations for your stack data structure :

1.    isEmpty() – a predicate function which checks to see if the stack is empty; returns true if the stack is empty; false otherwise
2.    push() – inserts a node, with a double precision value, to the top of the stack; the node is allocated dynamically;
		the double precision value should be passed in as an argument, along with a double pointer to the top of the stack
3.    pop() – deletes a node from the top of the stack; accepts a double pointer to the top of the stack; does not return a value; 
		this function should only be called after isEmpty() is called
4.    top() or peek() – returns the data in the node at the top of the stack; does not modify the stack
*/

