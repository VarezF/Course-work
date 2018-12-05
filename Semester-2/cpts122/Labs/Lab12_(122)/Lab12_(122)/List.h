#pragma once

template< class NODETYPE > class List;  // forward declaration

template<class NODETYPE>
class ListNode
{
	friend class List< NODETYPE >; // make List a friend
public:
	ListNode(const NODETYPE &newData);  // copy constructor
	NODETYPE getData() const;      // return data in the node
private:
	NODETYPE data;                 // data
	ListNode< NODETYPE > *nextPtr; // next node in the list
};


template< class NODETYPE >
class List
{
public:
	List();      // constructor
	~List();     // destructor
	void insertAtFront(const NODETYPE &newData);
	void insertAtBack(const NODETYPE &newData);
	bool removeFromFront(NODETYPE &removedData);
	bool removeFromBack(NODETYPE &removedData);
	bool isEmpty() const;
	void print() const;
private:
	ListNode< NODETYPE > *firstPtr;  // pointer to first node
	ListNode< NODETYPE > *lastPtr;   // pointer to last node

									 // Utility function to allocate a new node
	ListNode< NODETYPE > *getNewNode(const NODETYPE &newData);
};

template<class NODETYPE>
ListNode::ListNode<NODETYPE>(const NODETYPE &newData)  // copy constructor
{
	this->data = newData;
	this->nextPtr = nullptr;
}

template<class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData() const      // return data in the nodev
{
	return this->data;
}

template< class NODETYPE >
List::List()      // constructor
{
	this->firstPtr = nullptr;
	this->lastPtr = nullptr;
}

template< class NODETYPE >
List::~List()    // destructor
{
	ListNode pCur = this->firstPtr, pTemp;
	while (pCur != nullptr)
	{
		pTemp = pCur->getpNext();
		delete(pCur);
		pCur = pTemp;
	}
}

template< class NODETYPE >
void List::insertAtFront(const NODETYPE &newData)
{
	pMem = new ListNode(&newData);
	if (this->firstPtr == nullptr) {
		this->firstPtr = pMem;
		this->lastPtr = pMem;
	}
	else {
		this->lastPtr->nextPtr = pMem;
	}
}

template< class NODETYPE >
void List::insertAtBack(const NODETYPE &newData)
{
	pMem = new ListNode(&newData);
	if (this->firstPtr == nullptr) {
		this->firstPtr = pMem;
		this->lastPtr = pMem;
	}
	else {
		pMem->setpNext(this->firstPtr);
		this->lastPtr->nextPtr = pMem;
		this->lastPtr = pMem;
	}
}

template< class NODETYPE >
bool List::removeFromFront(NODETYPE &removedData)
{
	ListNode *pTemp = this->firstPtr->nextPtr;
	delete(this->firstPtr);
	this->firstPtr = pTemp;
}

template< class NODETYPE >
bool List::removeFromBack(NODETYPE &removedData)
{

}

template< class NODETYPE >
bool List::isEmpty() const
{

}

template< class NODETYPE > 
void List::print() const
{

}

template< class NODETYPE >
ListNode< NODETYPE >* List<NODETYPE>::getNewNode(const NODETYPE &newData)
{

}