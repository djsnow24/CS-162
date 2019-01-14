/*********************************************************************
** Author: Daniel Snow
** Date: 11/11/2018
** Description: This is the programMenu class specification file, which
** contains the menuOptions function declaration.
*********************************************************************/

#ifndef PROGRAMMENU_HPP
#define PROGRAMMENU_HPP

#include <string>

//programMenu class declaration
class programMenu
{
private:
public:
	int menuOptions();
	int userInput();
	bool validInputNum(std::string);
};
#endif