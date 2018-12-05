#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct queueNode
{
	char *item;
	struct queueNode *pNext;
}Node;

typedef struct queue
{
	Node *pHead;
	Node *pTail;
}Queue;

int isEmpty(Queue Q);

char *dequeue(Queue *Q, Node n);

Node *makeNode(char *item);

int enqueue(Queue *Q, char *item);
/*
1.   For the following problem define a struct queueNode with data of type char *. Also define a struct queue with two pointers: 
	one for the head and one for the tail. Both pointers are struct queueNode * types. Implement the following operations for your queue data structure:
	1.    isEmpty() – a predicate function which checks to see if the queue is empty; returns true if the queue is empty; false otherwise
	2.    enqueue() – inserts a node to the tail of the queue; the node is allocated dynamically; returns true if the memory was allocated for a node, 
		false otherwise
	3.    dequeue() – deletes a node from the head of the queue; returns the data in the node; precondition: 
		queue is not empty (isEmpty () must be called before dequeue () is called)
	4.    printQueueRecursive() – recursively prints out the data in the queue
*/