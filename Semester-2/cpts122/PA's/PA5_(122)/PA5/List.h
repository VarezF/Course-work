#pragma once
#include "ListNode.h"


class List {
public:
	List();
	ListNode *getpHead();
	void push(std::string newDate, ListNode *pCur);
	void setpHead(ListNode *p);

private:
	ListNode *mpHead;	//head of singly linked list
};
