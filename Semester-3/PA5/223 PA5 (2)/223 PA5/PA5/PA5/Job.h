#pragma once
#include <string>
#include <iostream>

using std::string;
class Job
{
public:
	Job();
	Job(int ID, string description, int proc_count, int tick_count);
	~Job();

	//decrements ticks
	void runJob();

	//returns ID
	int getID() const;

	//returns remaining ticks
	int getTicks();
	//int getProCount();

	//returns how many processors it's using
	int getProCount() const;

	//returns the descriptions
	string getDesc();

	//bool operator < (Job &lhs);

	//because ticks are strored as the negative value for queues
	//it flips it
	void fixTicks();

private:
	int id;
	int ticks;
	int pCount;	
	string jobDesc;
};

/*
overloaded operators for the queue and for searching the list
*/

bool operator < (Job &rhs, Job &lhs);
bool operator < (const Job &rhs, Job &lhs);
bool operator < (const Job &rhs, const Job &lhs);

bool operator == (Job &rhs, Job &lhs);
bool operator == (const Job &rhs, const Job &lhs);

void operator << (std::ostream &lhs, Job &rhs);




