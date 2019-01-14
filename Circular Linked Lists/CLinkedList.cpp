/*********************************************************************
** Author: Daniel Snow
** Date: 11/11/2018
** Description: This is the Circular Linked List class function 
** implementation file, which contains Circular Linked List function 
** definitions. Functions that add node to tail, display front node, 
** delete head node, display queue, or exit program
*********************************************************************/

#include "CLinkedList.hpp"
#include <iostream>
#include <string>
#include <cstring>


/*********************************************************************
** Description: Checks if queue is empty
*********************************************************************/
bool CLinkedList::isEmpty()
{
	if (!head)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/*********************************************************************
** Description: Adds a node to the tail of the linked list
*********************************************************************/
void CLinkedList::addBack(int number)
{

	QueueNode *newNode = new QueueNode(number);
	newNode->value = number;

	if (!head)
	{
		//QueueNode *newNode = new QueueNode(number);
		//newNode->value = number;
		newNode->next = newNode->prev = newNode;
		head = newNode;
	}
	else
	{

		//QueueNode *newNode = new QueueNode(number);
		//newNode->value = number;
		QueueNode *tail = head->prev;
		newNode->next = head;
		head->prev = newNode;
		newNode->prev = tail;
		tail->next = newNode;
	}
}

/*********************************************************************
** Description: Get the head of the circular linked lists value
*********************************************************************/
int CLinkedList::getFront()
{
	QueueNode *nodePtr = head;
	if (!isEmpty())
	{
		return head->value;
	}
	else
	{
		return -1;
	}
}

/*********************************************************************
** Description: Deletes the head of the circular linked list
*********************************************************************/
void CLinkedList::removeFront()
{
	if (!head)
	{
		return;
	}
	QueueNode *tail = head->prev;
	QueueNode *nodePtr = head;
	if (head == tail)
	{
		head = tail = NULL;
		delete nodePtr;
		return;
	}
	head = head->next;
	tail->next = head;
	head->prev = tail;
	delete nodePtr;
}

/*********************************************************************
** Description: Displays the circular linked list 
*********************************************************************/
void CLinkedList::printQueue()
{
	if (head == NULL)
	{
		return;
	}
	QueueNode *tail = head->prev;
	QueueNode *nodePtr = head;

	while (nodePtr != tail)
	{
		std::cout << nodePtr->value << " ";
		nodePtr = nodePtr->next;
	}
	std::cout << tail->value;

}

/*********************************************************************
** Description: Destructor
*********************************************************************/
CLinkedList::~CLinkedList()
{
	QueueNode *nodePtr = head;
	while (nodePtr != head)
	{
		QueueNode *garbage = nodePtr;
		nodePtr = nodePtr->next;
		delete garbage;
	}
}


