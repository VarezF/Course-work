#pragma once
#include <string>
#include <iostream>
#include <windows.h>
#include <fstream>

template <typename C, typename S>
class BSTNode {
public:
	BSTNode(C newChar = '\0', S newCode = "");	//constructor
	~BSTNode();	//destructor

	C getmChar();	//getters
	S getmCode();
	BSTNode *getmpRight();
	BSTNode *getmpLeft();

	void setmChar(C newCharacter);	//setters
	void setmCode(S newCode);
	void setmpLeft(BSTNode *p);
	void setmpRight(BSTNode *p);

	BSTNode<C, S>* findMin(BSTNode<C, S> *pSubTree);
	BSTNode<C, S>* deleteNode(C data);

private:
	C mChar;
	S mCode;
	BSTNode *mpLeft;
	BSTNode *mpRight;
};


//////////////////////////////////DeleteNode()-Extra Credit///////////////////////////////////////////////////////////////////////
template <typename C, typename S>
BSTNode<C, S>* BSTNode<C, S>::deleteNode(C data)
{
	if (data < mChar)	//Search BST for Node
		if (mpLeft == nullptr)	//if data does not exist in the BST, return nullptr
			return this;
		else setmpLeft(mpLeft->deleteNode(data));
	else if (data > mChar)
		if (mpRight == nullptr)
			return this;
		else setmpRight(mpRight->deleteNode(data));
	else {	//when node is found
		if (mpLeft == nullptr && mpRight == nullptr) {	//leaf node deletion
			delete(this);
			return nullptr;
		}
		else if (mpLeft == nullptr) {	//one right branch
			BSTNode<C, S> *pTemp = mpRight;
			delete(this);
			return pTemp;
		}
		else if (mpRight == nullptr) {	//one left branch
			BSTNode<C, S> *pTemp = mpLeft;
			delete(this);
			return pTemp;
		}
		else {	//two branches
			BSTNode<C, S> *pMin = findMin(mpRight);
			setmChar(pMin->mChar);
			pMin->deleteNode(pMin->getmChar());
		}
	}
}

template <typename C, typename S>
BSTNode<C, S>* BSTNode<C, S>::findMin(BSTNode<C, S> *pSubTree) {
	if (pSubTree->getmpLeft() == nullptr)
		return pSubTree;
	else return findMin(pSubTree->getmpLeft());
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template <typename C, typename S>
BSTNode<C, S>::BSTNode(C newChar, S newCode)	//constructor
{
	mChar = newChar;
	mCode = newCode;
	mpLeft = nullptr;
	mpRight = nullptr;
}

template <typename C, typename S>
BSTNode<C, S>::~BSTNode(){	//destructor
}

template <typename C, typename S>
C BSTNode<C, S>::getmChar()
{
	return mChar;
}

template <typename C, typename S>
S BSTNode<C, S>::getmCode()
{
	return mCode;
}

template <typename C, typename S>
BSTNode<C, S>* BSTNode<C, S>::getmpRight()
{
	return mpRight;
}

template <typename C, typename S>
BSTNode<C, S>* BSTNode<C, S>::getmpLeft()
{
	return mpLeft;
}

template <typename C, typename S>
void BSTNode<C, S>::setmChar(C newCharacter)	//setters
{
	mChar = newCharacter;
}

template <typename C, typename S>
void BSTNode<C, S>::setmCode(S newCode)
{
	mCode = newCode;
}

template <typename C, typename S>
void BSTNode<C, S>::setmpLeft(BSTNode *p)
{
	mpLeft = p;
}

template <typename C, typename S>
void BSTNode<C, S>::setmpRight(BSTNode<C, S> *p)
{
	mpRight = p;
}