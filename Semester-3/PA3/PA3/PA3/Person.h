/*
* Person:
* This class encapsulates a person within the Josephus circle.
*/

#ifndef __PERSON_H__
#define __PERSON_H__


class Person {
public:
	Person();	// Constructor:

	Person(int pos);
	
	~Person();	// Destructor

	void print();	// print the position

	int getPosition();
	void setPosition(int newPosition);

private:
	int position; // position occupied by the person at any point of the game
				  // Note: Because each position occupies a unique position initially, 
				  // 		that initial position can also be treated as the identifier (id)
				  //		or name for that person.
				  //		And as the potato is passed around and people are eliminated,
				  //			that id can be retained.
};

#endif


