#include "List.h"

List::List()
{
	mpHead = nullptr;
}

ListNode* List::getpHead()
{
	return mpHead;
}

void List::setpHead(ListNode *p)
{
	mpHead = p;
}