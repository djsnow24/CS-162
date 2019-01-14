/*********************************************************************
** Author: Daniel Snow
** Date: 10/14/2018
** Description: This is the LoadedDie class function implementation file,
** which contains loadedDieRoll function definition. Takes a random
** number from the inherited dieRoll function, and then rerolls with
** that number and higher numbers, improving the probability of rolling
** a higher number.
*********************************************************************/

#include "LoadedDie.h"
#include <iostream>
#include <algorithm>

/*********************************************************************
** Description: Takes a random number from the inherited dieRoll function,
** then adds it to an array that is made up of at least 50% that number, 
** and then numbers higher than it on the die, and rerolls, improving
** the probability of rolling a higher number, and returns it.
*********************************************************************/
int LoadedDie::loadedDieRoll(int sides)
{
	int randNum;
	int rollDie = dieRoll(sides);
	int *numSides = new int[((sides - 1) * 2)];
	for (int i = 0; i < ((sides - 1) * 2); i++)
	{
		numSides[i] = rollDie;
		if (i > (sides - 1))
		{
			while (rollDie + i + 1 < sides)
			{
				numSides[i] = rollDie + i + 1;
			}
		}
	}
	std::random_shuffle(&numSides[0], &numSides[((sides - 1) * 2)]);
	randNum = rand() % ((sides - 1) * 2);
	int roll = numSides[randNum];
	delete[]numSides;
	return roll;

}