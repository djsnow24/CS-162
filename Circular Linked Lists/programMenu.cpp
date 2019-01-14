/*********************************************************************
** Author: Daniel Snow
** Date: 11/11/2018
** Description: This is the programMenu class function implementation file,
** which contains menuOptions function definitions. Asks the user to 
** choose the circular linked list function they would like to run, add
** node to tail, display front node, delete head node, display queue, 
** or exit program
*********************************************************************/

#include "programMenu.hpp"
#include "CLinkedList.hpp"

#include <iostream>
#include <string>
#include <cstring>

/*********************************************************************
** Description: Asks the user to choose the circular linked list 
** function they would like to run, add node to tail, display front 
** node, delete head node, display queue, or exit program
*********************************************************************/
int programMenu::menuOptions()
{
	CLinkedList list;
	int inputInt;
	int runProgram = 0;
	std::string choice;

	while (runProgram != 5)
	{
		do
		{
			std::cout << "Choose from the following options:\n" << std::endl;
			std::cout << "1. Enter a value to be added to the back of queue" << std::endl;
			std::cout << "2. Display first node (front) value" << std::endl;
			std::cout << "3. Remove first node (front) value" << std::endl;
			std::cout << "4. Display the queue contents" << std::endl;
			std::cout << "5. Exit.\n" << std::endl;
			getline(std::cin, choice);
			//Make sure user input is valid
			if (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5")
			{
				std::cout << "That is not a valid choice, please choose again." << std::endl;
			}
		} while (choice != "1" && choice != "2" && choice != "3" && choice != "4" && choice != "5");

		std::size_t sz;
		int numChoice = std::stoi(choice, &sz);
		//runProgram = optionSelection(numChoice);

		if (numChoice == 1)
		{
			inputInt = userInput();
			list.addBack(inputInt);
			std::cout << std::endl;
			runProgram = 1;
		}
		else if (numChoice == 2)
		{
			std::cout << "\nThe first node value is: ";
			if (list.getFront() <= -1)
			{
				std::cout << std::endl << std::endl;
			}
			else
			{
				std::cout << list.getFront() << std::endl << std::endl;
			}
			runProgram = 2;
		}
		else if (numChoice == 3)
		{
			list.removeFront();
			std::cout << std::endl;
			runProgram = 3;
		}
		else if (numChoice == 4)
		{
			std::cout << "\nYour queue is: ";
			list.printQueue();
			std::cout << std::endl << std::endl;
			runProgram = 4;
		}
		else
		{
			list.~CLinkedList();
			runProgram = 5;
		}
	}
	return runProgram;
}

/*********************************************************************
** Description: Get user input
*********************************************************************/
int programMenu::userInput()
{
	std::string numChoice;
	std::cout << "\nPlease enter a positive integer:" << std::endl << std::endl;
	getline(std::cin, numChoice);

	while (!validInputNum(numChoice))
	{
		std::cout << "\nThat is not a valid option." << std::endl;
		std::cout << "\nPlease enter a positive integer:" << std::endl << std::endl;
		std::cin.clear();
		getline(std::cin, numChoice);
	}
	std::size_t sz;
	int numInput = std::stoi(numChoice, &sz);
	return numInput;
}

/*********************************************************************
** Description: Validate user input
*********************************************************************/
bool programMenu::validInputNum(std::string num)
{
	if (num.length() == 0)
	{
		return false;
	}
	for (int i = 0; i < num.length(); i++)
	{
		if (!(num[i] >= '0' && num[i] <= '9'))
		{
			return false;
		}
	}
	std::size_t sz;
	int numChoice = std::stoi(num, &sz);
	if (numChoice < 0)
	{
		return false;
	}
	return true;
}


