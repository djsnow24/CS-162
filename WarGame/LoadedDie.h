/*********************************************************************
** Author: Daniel Snow
** Date: 10/14/2018
** Description: This is the LoadedDie class specification file, which
** contains the loadedDieRoll function declaration.
*********************************************************************/

#ifndef LOADEDDIE_H
#define LOADEDDIE_H
#include "Die.h"

//programMenu class declaration
class LoadedDie : public Die
{
private:
public:
	int loadedDieRoll(int);
};
#endif