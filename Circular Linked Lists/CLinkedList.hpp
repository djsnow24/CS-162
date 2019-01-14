/*********************************************************************
** Author: Daniel Snow
** Date: 11/11/2018
** Description: This is the Circular Linked List class specification 
** file, which contains the Circular Linked List function declarations.
*********************************************************************/

#ifndef CLINKEDLIST_HPP
#define CLINKEDLIST_HPP
#include <iostream>

//Circular Linked List class declaration
class CLinkedList
{
protected:
	struct QueueNode
	{
		int value;
		QueueNode *next;
		QueueNode *prev;
		QueueNode(int value1)
		{
			value = value1;
		}
	};
	QueueNode *head;
public:
	CLinkedList() { head = NULL; }
	~CLinkedList();
	bool isEmpty();
	void addBack(int number);
	int getFront();
	void removeFront();
	void printQueue();
};
#endif