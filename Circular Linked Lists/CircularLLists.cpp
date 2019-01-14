/*********************************************************************
** Author: Daniel Snow
** Date: 11/11/18
** Description: Program that Asks the user to choose the circular 
** linked list function they would like to run.  Add node to tail, 
** display front node, delete head node, display queue, or exit program
*********************************************************************/

#include "programMenu.hpp"
#include <iostream>


int main()
{
	programMenu menu;
	int run = 0;

	std::cout << "Welcome to my queue!\n" << std::endl;
	//Run program
	while (run != 5)
	{
		run = menu.menuOptions();
		if (run == 5)
		{
			return 0;
		}
	}
}
