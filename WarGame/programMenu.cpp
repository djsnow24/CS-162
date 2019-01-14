/*********************************************************************
** Author: Daniel Snow
** Date: 10/14/2018
** Description: This is the programMenu class function implementation file,
** which contains menuOptions function definition. Asks the user to start
** the War game or quit
*********************************************************************/

#include "programMenu.h"
#include <iostream>
#include <string>

/*********************************************************************
** Description: Asks the user to start War game or quit
*********************************************************************/
bool programMenu::menuOptions()
{
	bool runProgram;
	std::string choice;
	//Asks user if they would like to run the game or quit
	do
	{
		std::cout << "1. Play War Game with Dice" << std::endl;
		std::cout << "2. Exit" << std::endl;
		getline(std::cin, choice);
		//Make sure user input is valid
		if (choice != "1" && choice != "2")
		{
			std::cout << "That is not a valid choice, please choose again." << std::endl;
		}
	} while (choice != "1" && choice != "2");

	if (choice == "1")
	{
		runProgram = true;
	}
	else
	{
		runProgram = false;
	}

	return runProgram;
}