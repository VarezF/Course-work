#include "Person.h"
#include <iostream>

//constructor
Person::Person() {
	this->position = 0;
}

Person::Person(int pos) {
	this->position = pos;
}

// Destructor
Person::~Person() {//fails to delete?

}

// print the position
void Person::print() {
	std::cout << this->position << " ";
}

int Person::getPosition() {
	return this->position;
}

void Person::setPosition(int newPosition) {
	this->position = newPosition;
}