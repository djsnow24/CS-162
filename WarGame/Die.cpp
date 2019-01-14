/*********************************************************************
** Author: Daniel Snow
** Date: 10/14/2018
** Description: This is the Die class function implementation file,
** which contains dieRoll function definition. Chooses a random number
** based on the number of sides of the die, to represent a die roll.
*********************************************************************/

#include "Die.h"
#include <iostream>
#include <algorithm>

/*********************************************************************
** Description: Chooses a random number based on the number of sides 
** of the die, to represent a die roll, and returns the roll.
*********************************************************************/
int Die::dieRoll(int sides)
{
	int randNum;
	dieSides = sides;
	int *numSides = new int[dieSides];
	for (int i = 0; i < dieSides; i++)
	{
		numSides[i] = i + 1;
	}
	std::random_shuffle(&numSides[0], &numSides[dieSides]);
	randNum = rand() % sides;
	int roll = numSides[randNum];
	delete[]numSides;
	return roll;

}