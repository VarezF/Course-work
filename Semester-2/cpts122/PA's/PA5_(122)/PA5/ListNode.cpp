#include "ListNode.h"

ListNode::ListNode()	//constructor
{
	mID = { '\0' };
	mName = { '\0' };
	mEmail = { '\0' };
	mUnits = { '\0' };
	mProgram = { '\0' };
	mLevel = { '\0' };
	mpNext = nullptr;
	mpStack = new Stack;
}

ListNode::~ListNode()	//destructor
{
	//std::cout << "ListNode destructor called" << std::endl;	//DELETE THIS AFTER TESTING!
	//system("pause");
}

Stack::Stack()
{
	mpTop = new std::string[10];
	mCapacity = 10;
	mSize = 0;
}

/////////////////getters///////////////////////////
std::string *Stack::getpTop()
{
	return mpTop;
}

int Stack::getmSize()
{
	return mSize;
}

int Stack::getmCapacity()
{
	return mCapacity;
}

std::string ListNode::getmID()
{
	return mID;
}

std::string ListNode::getmName()
{
	return mName;
}

std::string ListNode::getmEmail()
{
	return mEmail;
}

std::string ListNode::getUnits()
{
	return mUnits;
}

std::string ListNode::getmProgram()
{
	return mProgram;
}

std::string ListNode::getmLevel()
{
	return mLevel;
}

ListNode* ListNode::getpNext()
{
	return mpNext;
}

Stack* ListNode::getStack()
{
	return mpStack;
}

////////////////setters/////////////////////////////
void Stack::setpTop(std::string *p)
{
	mpTop = p;
}

void Stack::setmSize(int size)
{
	mSize = size;
}

void Stack::setmCapacity(int capacity)
{
	mCapacity = capacity;
}

void ListNode::setmID(std::string ID)
{
	mID = ID;
}

void ListNode::setmName(std::string name)
{
	mName = name;
}

void ListNode::setmEmail(std::string email)
{
	mEmail = email;
}

void ListNode::setUnits(std::string units)
{
	mUnits = units;
}

void ListNode::setmProgram(std::string program)
{
	mProgram = program;
}

void ListNode::setmLevel(std::string level)
{
	mLevel = level;
}

void ListNode::setpNext(ListNode *p)
{
	mpNext = p;
}

///////////////OTHERS/////////////////////////
std::string Stack::peek()
{
	return *mpTop;
}

bool Stack::isEmpty()
{
	return !mSize;
}