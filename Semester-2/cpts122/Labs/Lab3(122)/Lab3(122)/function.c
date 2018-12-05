#include "Header.h"

int isEmpty(Queue Q)
{
	return Q.pHead == NULL;
}

char *dequeue(Queue *Q, Node n)
{
	char *s = NULL;
	Node *pTemp = Q->pHead;
	if (!isEmpty(*Q))
	{
		s = (char*)malloc(sizeof(char) * strlen(Q->pHead->item) + 1);
		strcpy(s, Q->pHead->pNext);
		if (Q->pHead == Q->pTail)
		{
			Q->pHead = Q->pHead->pNext;
			Q->pTail = NULL;
		}
		free(pTemp);
	}
	return s;
}

Node *makeNode(char *item)
{
	Node *pMem = (Node*)malloc(sizeof(Node));
	pMem->pNext = NULL;
	pMem->item = (char*)malloc(sizeof(char) * strlen(item) + 1);
	strcpy(pMem->item, item);

	return pMem;
}

int enqueue(Queue *Q, char *item)
{
	int success = 0;
	Node *pMem = makeNode(item);
	if (pMem == NULL)
		Q->pHead = Q->pTail = pMem;
	else
	{
		Q->pTail->pNext = pMem;
		Q->pTail = pMem;
	}
	return success;
}

void printQueueRecursive(Node *pHead)
{
	if (pHead == NULL)
		return;
	else
	{
		printf("%s\n", pHead->item);
		printQueueRecursive(pHead->pNext);
	}
}