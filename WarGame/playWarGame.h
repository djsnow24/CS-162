/*********************************************************************
** Author: Daniel Snow
** Date: 10/14/2018
** Description: This is the playWarGame class specification file, which
** contains the function declarations.
*********************************************************************/

#ifndef PLAYWARGAME_H
#define PLAYWARGAME_H
#include "LoadedDie.h"
#include<string>

//playWarGame class declaration
class playWarGame
{
private:
	LoadedDie player1;
	LoadedDie player2;
	int battles;
	int dieTypeP1;
	int dieTypeP2;
	int dieSidesP1;
	int dieSidesP2;
	int plScore;
	int p2Score;
public:
	void runGame();
	bool validInputRounds(std::string);
	bool validInputDieSides(std::string);
	int setRounds();
	bool setDieType(int);
	int setDieSides(int);
	void battleRolls();
};
#endif