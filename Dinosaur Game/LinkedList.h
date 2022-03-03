#include <iostream>
#include "Dinosaur.h"
#include <list>

using namespace std;

class LinkedList
{
	private:
		struct listNode
		{
			Dinosaur* value;
			struct listNode * next;
		};
		listNode * head;
		listNode * tail;
		int numNodes;
	public:
		/*
			Function Name:  LinkedList()
			parameters: None
			Returns:   nothing
			Purpose: initialize attributes to NULL and 0
		*/
		LinkedList();
		/*
			Function Name:  ~LinkedList()
			parameters: None
			Returns:   nothing
			Purpose: delete a node pointer 
		*/
		~LinkedList();
		/*
			Function Name:  getLength()
			parameters: None
			Returns:   nothing
			Purpose: gets the length of the nodes in the length list.
		*/
		int getLength();
		/*
			Function Name:  getNodeValue()
			parameters: interger 
			Returns:   pointer to dinosaur value
			Purpose: get the value in the nodes of the length list.
		*/
		Dinosaur* getNodeValue(int);
		/*
			Function Name:  appendNode()
			parameters: Dinosaur pointer 
			Returns:   nothing
			Purpose: append the value past into the node to the end of the list.
		*/
		void appendNode(Dinosaur*);
		/*
			Function Name:  insertNode()
			parameters: dinosaur pointer and an integer
			Returns:   nothing
			Purpose: to insert a node at a given position 
		*/
		void insertNode(Dinosaur*, int);
		/*
			Function Name:  deleteNode
			parameters: dinosaur pointer
			Returns:   nothing
			Purpose: to delete all the dinosaurs in the nodes.
		*/		
		void deleteNode(Dinosaur*);
    
};

LinkedList::LinkedList()
{
	head = NULL;
	tail = NULL;
	numNodes = 0;
}

int LinkedList::getLength()
{
	int counter = 0;
	listNode * nodePtr;
	
	nodePtr = head;
	
	while(nodePtr != tail)
	{
		counter++;
		nodePtr = nodePtr->next;
		if (nodePtr == tail)
		{
			counter++;
		}
	}
	return counter;
}

Dinosaur* LinkedList::getNodeValue(int position)
{
	listNode * nodePtr;
	if(!head)
		return nodePtr->value;
	else
	{
		if (position == 0)
			return head->value;
		nodePtr = head;
		int currentPos = 0;
		while (position >= currentPos && nodePtr != NULL)
		{
			if(position == currentPos)
				return nodePtr->value;
			currentPos++;
			nodePtr = nodePtr->next;
		}
	}
	return nodePtr->value;
}

void LinkedList::appendNode(Dinosaur * one)
{
	listNode * newNode;
	
	newNode = new listNode;
	newNode->value = one;
	newNode->next = NULL;
	if(!head)
	{
		tail = newNode;
		head = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}
}

void LinkedList::insertNode(Dinosaur * one, int position)
{
	listNode * nodePtr;
	listNode * newPtr;
	
	newPtr = new listNode;
	newPtr->value = one;
	
	if(!head)
	{
		if(position != 0)
		{
			cout << "didn't print out the node" << endl;
			
			head = newPtr;
			tail = newPtr;
		}
	}
	else
	{
		nodePtr = head;
		int nodeCount = 0;
		if(position == 0)
		{
			newPtr->next = head;
			head = newPtr;
		}
		else
		{
			while(nodePtr != tail && nodeCount < position)
			{
				nodeCount++;
				if(nodeCount == position)
					break;
				nodePtr = nodePtr->next;
			}
			if(nodePtr->next == NULL)
			{
				tail = newPtr;
			}
			
			newPtr->next = nodePtr->next;
			nodePtr->next = newPtr;
		}
	}
}
			
		
		
void LinkedList::deleteNode(Dinosaur * one)
{
	listNode * nodePtr;
	listNode * previousNode;
	
	if(!head)
	{
		return;
	}
	
	if(head->value == one)
	{
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = head;
		
		while (nodePtr != NULL && nodePtr->value != one)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		
		if(nodePtr)
			if(nodePtr == tail)
				tail = previousNode;
			previousNode->next = nodePtr->next;
			delete nodePtr;
	}
}
		
		
		
LinkedList::~LinkedList()
{
	listNode *nodePtr;
	listNode *nextNode;
	
	nodePtr = head;
	
	while (nodePtr != NULL)
	{
		nextNode = nodePtr->next;
		
		delete nodePtr;
		
		nodePtr = nextNode;
	}
}

		
		
		
