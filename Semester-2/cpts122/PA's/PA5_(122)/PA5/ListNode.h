#pragma once
#include <string>
#include <iostream>


class Stack{
public:
	Stack();	//constructor

	std::string *getpTop();	//getter
	int getmSize();
	int getmCapacity();

	void setpTop(std::string *p);	//setter
	void setmSize(int size);
	void setmCapacity(int capacity);

	void push(std::string newData);
	void pop(std::string *pTop);
	std::string peek();
	bool isEmpty();

private:
	std::string *mpTop;	//takes the place of pTop
	int mSize;
	int mCapacity;
};
///////////////////////////////////////////////////////////////
class ListNode{
public:
	ListNode();	//constructor
	~ListNode();	//destructor

	std::string getmID();	//getters
	std::string getmName();
	std::string getmEmail();
	std::string getUnits();
	std::string getmProgram();
	std::string getmLevel();
	ListNode *getpNext();
	Stack *getStack();

	void setmID(std::string ID);	//setters
	void setmName(std::string name);
	void setmEmail(std::string email);
	void setUnits(std::string units);
	void setmProgram(std::string program);
	void setmLevel(std::string level);
	void setpNext(ListNode *p);

private:
	std::string mID;
	std::string mName;
	std::string mEmail;
	std::string mUnits;
	std::string mProgram;
	std::string mLevel;
	ListNode *mpNext;
	Stack *mpStack;
};