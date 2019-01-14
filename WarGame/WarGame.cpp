/*********************************************************************
** Author: Daniel Snow
** Date: 10/14/18
** Description: Program lets user play a game of War, where user can
** decide on the number of rounds, type of dice and how many sides to 
** the die.
*********************************************************************/

#include "programMenu.h"
#include "playWarGame.h"
#include <iostream>

int main()
{
	playWarGame game;
	programMenu menu;
	bool run = true;
	//Run program
	while (run = true)
	{
		run = menu.menuOptions();
		if (run == true)
		{
			game.runGame();
		}
		else
		{
			return 0;
		}
	}
}