#pragma once
#include "BSTNode.h"
#include <ctype.h>
#include <ios>
#include <ctime>

template <typename C, typename S>
class BST {
public:
	BST();
	~BST();

	bool insert(C newCharacter, S newCode, BSTNode<C, S> *pTree);
	S search(C search, BSTNode<C, S> *p);
	bool convert();
	bool filter(std::string &searchString, int length);
	void print(BSTNode<C, S> *p);
	BSTNode<C, S> *getmpRoot();
	void setmpRoot(BSTNode<C, S> *p);

private:
	BSTNode<C, S> *mpRoot;
	void deleteTree(BSTNode<C, S> *p);
};

template <typename C, typename S>	//BST constructor
BST<C, S>::BST()
{
	mpRoot = nullptr;
	std::fstream infile;
	infile.open("MorseTable.txt");
	std::string newString;
	int newIndex = 0, temp = 0;
	int size = 0;
	for (; !infile.eof(); size++)	//finds size of file (in lines)
	{
		std::getline(infile, newString);
		if (newString == "")
			size--;	//does not count empty lines
	}
	infile.clear();	//clears any eof marker
	infile.seekg(0, infile.beg);	//moves back to beginning of file

	int *order = new int[size];
	for (int i = 0; i < size; i++)	//assign integers 0 through size within array
	{
		order[i] = i;
	}
	time_t t;	//seeds rand() (taken from https://www.tutorialspoint.com/c_standard_library/c_function_srand.htm)
	srand((unsigned)time(&t));
	for (int i = 0; i < size; i++)	//randomize array
	{
		newIndex = rand() % size;
		temp = order[i];
		order[i] = order[newIndex];
		order[newIndex] = temp;
	}

	char tempChar = '\0';
	std::string tempStr;
	int lineIndex = 0;
	for (int arrayIndex = 0; arrayIndex < size; arrayIndex++)	//read file in order of randmized list above
	{
		infile.clear();	//clears any eof marker
		infile.seekg(0, infile.beg);	//moves back to beginning of file
		lineIndex = order[arrayIndex];
		for (int i = 0; i <= lineIndex; i++)	//moves through file to correct line
		{
			std::getline(infile, newString);
		}
		tempChar = newString.at(0);	//Proccess line and and insert
		tempStr = newString.substr(4, 7);
		insert(tempChar, tempStr, mpRoot);	//creates new node based on data in BST
	}
	delete order;
	infile.close();	//close filestream
}

template <typename C, typename S>
void BST<C, S>::setmpRoot(BSTNode<C, S> *p)
{
	mpRoot = p;
}

template <typename C, typename S>	//BST destructor
BST<C, S>::~BST()	
{
	deleteTree(mpRoot);
}

template <typename C, typename S>	//getter
BSTNode<C, S>* BST<C, S>::getmpRoot()
{
	return mpRoot;
}

/*function: deleteTree()
details: assists BST destructor by recursively deleting BST
input: pointer to subtree
output: N/A
*/
template <typename C, typename S>
void BST<C, S>::deleteTree(BSTNode<C, S> *p)
{
	if (p != nullptr)
	{
		deleteTree(p->getmpLeft());
		deleteTree(p->getmpRight());
		delete p;
	}
}

/*function: insert()
details: creates a new node for data (passed in) and inserts into BST
input: new data (in the form character and string), and root node of subtree where new node will be inserted
output: boolean true if data was successfully inserted, false otherwise
*/
template <typename C, typename S>
bool BST<C, S>::insert(C newChar, S newCode, BSTNode<C, S> *pTree)
{
	bool success = false;
	if (mpRoot == nullptr) {	//if no root node exists, allocate new noode for mpRoot
		mpRoot = new BSTNode<char, std::string>(newChar, newCode);
		success = true;
	}
	else if (newChar < pTree->getmChar())	//go to left subtree
	{
		if (pTree->getmpLeft() == nullptr) {
			pTree->setmpLeft(new BSTNode<char, std::string>(newChar, newCode));	//insert into empty space
			success = true;
		}
		else insert(newChar, newCode, pTree->getmpLeft());
	}
	else if (newChar > pTree->getmChar())	//go to right subtree
	{
		if (pTree->getmpRight() == nullptr) {
			pTree->setmpRight(new BSTNode<char, std::string>(newChar, newCode));	//insert into empty space
			success = true;
		}
		else insert(newChar, newCode, pTree->getmpRight());
	}
	return success;
}

/*function: search()
details: converts an alphanumeric, ?, . or , character to morse code by recursively searching a BST with corrosponding information
input: character to be converted and root of subtree to be searched
output: corrosponding morse code to character (passed in)
*/
template <typename C, typename S>
S BST<C, S>::search(C searchC, BSTNode<C, S> *p)
{
	if (searchC == p->getmChar())
		return p->getmCode();
	else if (searchC < p->getmChar())
		return search(searchC, p->getmpLeft());
	else return search(searchC, p->getmpRight());
}

/*function: convert()
details: converts string to morse code (notifying user if string could not be converted)
input: string to be converted, length of string
output: converted string to convert.txt, or error to user in std::cout (in main()) if conversion was unsuccessful 
*/
template <typename C, typename S>
bool BST<C, S>::convert()
{
	std::fstream convertStream;
	convertStream.open("convert.txt");
	std::string temp, code;
	bool success = true;

	int strLength = 0;
	for (int i = 0; !convertStream.eof(); i++)	//reads one line (each iteration) from filestream
	{
		std::getline(convertStream, temp);
		temp += "\n"; //re-concatenate newline character to each string (was deleted during getline())
		strLength = temp.length();
		if (filter(temp, strLength) == true) {
			for (int j = 0; j < strLength; j++) {	//converts and prints string in morse code character-by-character
				if (temp[j] == ' ')	//for each space, print 3 spaces
					std::cout << "   ";
				else if (temp[j] == '\n')	//do not convert newline characters, simply print
					std::cout << '\n';
				else
					std::cout << search(temp[j], mpRoot) << " ";	//prints converted character along with a space (between each character)
			}
		}
		else {
			std::cout << "(Error: line contains non-convertable characters)" << std::endl;
			success = false;	//returned to notify user of unsuccessful conversion
		}
	}
	std::cout << std::endl;
	convertStream.close();
	return success;
}

/*function: filter()
details: prepares string for conversion, including converting characters to uppercase (as neccessary) 
		as well as notifying convert() function of non-convertable characters. 
input: String to be filtered, length of string
output: true if string was successfully filtered, false if filter found non-convertable character (notifying user in the convert() function)
*/
template <typename C, typename S>
bool BST<C, S>::filter(std::string &searchStr, int length) {
	for (int i = 0; i < length; i++)
	{
		if (!(isalnum(searchStr[i]) || searchStr[i] == ' ' || searchStr[i] == '\n' || searchStr[i] == '.'
			|| searchStr[i] == ',' || searchStr[i] == '?'))	//if string contains non-translatable characters, return and discontinue convert
			return false;
		else 
			searchStr[i] = toupper(searchStr[i]);	//converts character to uppercase, if no such uppercase character exists, charcter is unchanged
	}
	return true;
}

/*function: print()
details: recursively prints current BST in order (by asci code)
input: root of subtree (to be iterated through
output: N/A (prints each character to std::cout)
*/
template <typename C, typename S>
void BST<C, S>::print(BSTNode<C, S> *p)
{
	if(p->getmpLeft() != nullptr)
		print(p->getmpLeft());
	std::cout << p->getmChar() << "   " << p->getmCode() << std::endl;
	if (p->getmpRight() != nullptr)
		print(p->getmpRight());
}