#include "Job.h"



Job::Job()
{
}

Job::Job(int ID, string description, int proc_count, int tick_count)
{
	id = ID;
	jobDesc = description;;
	pCount = proc_count;
	ticks = tick_count;
}


Job::~Job()
{
}

void Job::runJob()
{
	ticks--;
}

int Job::getID() const
{
	return id;
}

int Job::getTicks()
{
	return ticks;
}


int Job::getProCount() const
{
	return pCount;
}

string Job::getDesc()
{
	return jobDesc;
}

void Job::fixTicks()
{
	ticks *= -1;
}



bool operator<(Job & rhs, Job & lhs)
{
	return rhs.getProCount() < lhs.getProCount();
}

bool operator<(const Job & rhs, Job & lhs)
{
	return rhs.getProCount() < lhs.getProCount();
}

bool operator<(const Job & rhs, const Job & lhs)
{
	return rhs.getProCount() < lhs.getProCount();
}

bool operator==(Job & rhs, Job & lhs)
{
	return rhs.getID() == rhs.getID();
}

bool operator==(const Job & rhs, const Job & lhs)
{
	return rhs.getID() == rhs.getID();
}

void operator << (std::ostream & lhs, Job & rhs)
{
	lhs << "Description:\t" << rhs.getDesc() << "\nProcessors:\t" << rhs.getProCount() << "\nTicks:\t\t" << rhs.getTicks() << std::endl;
	//return lhs;
}
