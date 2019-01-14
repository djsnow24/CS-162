/*********************************************************************
** Author: Daniel Snow
** Date: 10/14/2018
** Description: This is the playWarGame class function implementation file,
** which contains playWarGame function definitions. Asks the user to set
** the number of rounds, die type for each player, sides to each player's
** die, and then plays game, and counts score.
*********************************************************************/

#include "playWarGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

/*********************************************************************
** Description: Run the war game.
*********************************************************************/
void playWarGame::runGame()
{
	std::cout << "\n!! WAR WERE DECLARED !!" << std::endl;
	setRounds();
	setDieType(1);
	setDieType(2);
	setDieSides(1);
	setDieSides(2);
	battleRolls();
}

/*********************************************************************
** Description: Makes sure the input for number of rounds is valid before
** proceeding
*********************************************************************/
bool playWarGame::validInputRounds(std::string num)
{
	if (num.length() == 0 || num == "0")
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
	if (numChoice > 100)
	{
		return false;
	}
	return true;
}

/*********************************************************************
** Description: Makes sure the input for number of sides is valid before
** proceeding
*********************************************************************/
bool playWarGame::validInputDieSides(std::string num)
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
	if (numChoice > 20 || numChoice < 3)
	{
		return false;
	}
	return true;
}

/*********************************************************************
** Description: Set the number of rounds to be played im the game
*********************************************************************/
int playWarGame::setRounds()
{
	std::string num;
	std::cout << "\nHow many battles (1 - 100) will it take to achieve VICTORY?!?!" << std::endl;
	getline(std::cin, num);

	while (!validInputRounds(num))
	{
		std::cout << "\nSuch a number would lead to nothing but despair for all sides.\n";
		std::cout << "Please enter the number of battles (1 - 100) it will take to conquer your enemies:" << std::endl;
		std::cin.clear();
		getline(std::cin, num);
	}
	std::size_t sz;
	battles = std::stoi(num, &sz);
	return battles;
}

/*********************************************************************
** Description: Set the type of die to be used by each player in the 
** game, normal or loaded, and make sure input is valid.
*********************************************************************/
bool playWarGame::setDieType(int player)
{
	std::string dieType;
	if (player == 1)
	{
		std::cout << "\nPlayer 1: " << std::endl;
	}
	else
	{
		std::cout << "\nPlayer 2: " << std::endl;
	}
	std::cout << "Will the battles be fair, or will you load the die in your favor?" << std::endl;
	do
	{
		std::cout << "1. Battle with normal die" << std::endl;
		std::cout << "2. Battle with a loaded die" << std::endl;
		getline(std::cin, dieType);
		//Make sure user input is valid
		if (dieType != "1" && dieType != "2")
		{
			std::cout << "That is not a valid option, please choose again." << std::endl;
		}
	} while (dieType != "1" && dieType != "2");
	std::size_t sz;
	if (player == 1)
	{
		dieTypeP1 = std::stoi(dieType, &sz);
		return dieTypeP1;
	}
	else
	{
		dieTypeP2 = std::stoi(dieType, &sz);
		return dieTypeP2;
	}
}

/*********************************************************************
** Description: Set the number of sides for each die, between 3 and 20.
*********************************************************************/
int playWarGame::setDieSides(int player)
{
	std::string num;
	if (player == 1)
	{
		std::cout << "\nPlayer 1: " << std::endl;
		std::cout << "\nHow many sides will there be on your die (3 - 20)?" << std::endl;
		getline(std::cin, num);

		while (!validInputDieSides(num))
		{
			std::cout << "\nThat is not a valid option, please choose again.";
			std::cout << "Please enter the number of sides (3 - 20) there will be on your die:" << std::endl;
			std::cin.clear();
			getline(std::cin, num);
		}
		std::size_t sz;
		dieSidesP1 = std::stoi(num, &sz);
		return dieSidesP1;
	}
	else
	{
		std::cout << "\nPlayer 2: " << std::endl;
		std::cout << "\nHow many sides will there be on your die (3 - 20)?" << std::endl;
		getline(std::cin, num);

		while (!validInputDieSides(num))
		{
			std::cout << "\nThat is not a valid option, please choose again.";
			std::cout << "Please enter the number of sides (3 - 20) there will be on your die:" << std::endl;
			std::cin.clear();
			getline(std::cin, num);
		}
		std::size_t sz;
		dieSidesP2 = std::stoi(num, &sz);
		return dieSidesP2;
	}
}

/*********************************************************************
** Description: Start the actual gameplay/rolling and determines who
** rolled the higher number, then keeps track of score, and declares 
** a winner after all rounds have ended.
*********************************************************************/
void playWarGame::battleRolls()
{
	int p1Roll;
	int p2Roll;
	int p1Score = 0;
	int p2Score = 0;
	//srand to make sure every roll is random.
	unsigned seed;
	seed = time(0);
	srand(seed);
	//std::cout << dieSidesP1 << " - " << dieSidesP2 << std::endl;
	for (int i = 0; i < battles; i++)
	{
		std::cout << "\nBattle number " << i + 1 << ":  " << std::endl;
		if (dieTypeP1 == 1)
		{
			p1Roll = player1.dieRoll(dieSidesP1);
			std::cout << "Player 1, using a normal die with " << dieSidesP1 << " sides, rolls:  " << p1Roll;
		}
		else
		{
			p1Roll = player1.loadedDieRoll(dieSidesP1);
			std::cout << "Player 1, using a loaded die with " << dieSidesP1 << " sides, rolls:  " << p1Roll;
		}
		if (dieTypeP2 == 1)
		{
			p2Roll = player2.dieRoll(dieSidesP2);
			std::cout << "          Player 2, using a normal die with " << dieSidesP2 << " sides, rolls:  " << p2Roll << std::endl;
		}
		else
		{
			p2Roll = player2.loadedDieRoll(dieSidesP2);
			std::cout << "          Player 2, using a loaded die with " << dieSidesP2 << " sides, rolls:  " << p2Roll << std::endl;
		}
		if (p1Roll > p2Roll)
		{
			p1Score++;
			std::cout << "Player 1 has achieved VICTORY in battle!!" << std::endl;
			std::cout << "Score:\nPlayer1:  " << p1Score << "          Player 2:  " << p2Score << std::endl;
		}
		else if (p2Roll > p1Roll)
		{
			p2Score++;
			std::cout << "Player 2 has achieved VICTORY in battle!!" << std::endl;
			std::cout << "Score:\nPlayer1:  " << p1Score << "          Player 2:  " << p2Score << std::endl;
		}
		else
		{
			std::cout << "STALEMATE!!  Nothing could be gained during this battle." << std::endl;
			std::cout << "Score:\nPlayer1:  " << p1Score << "          Player 2:  " << p2Score << std::endl;
		}
	}
	if (p1Score > p2Score)
	{
		std::cout << "\nPlayer 1 has hit the Bullseye and the rest of the dominoes have fallen like a house of card. ";
		std::cout << "Checkmate!!" << std::endl;
		std::cout << "Final Score:\nPlayer1:  " << p1Score << "          Player 2:  " << p2Score << std::endl << std::endl;
	}
	else if (p2Score > p1Score)
	{
		std::cout << "\nPlayer 2 has hit the Bullseye and the rest of the dominoes have fallen like a house of card. ";
		std::cout << "Checkmate!!" << std::endl;
		std::cout << "Final Score:\nPlayer1:  " << p1Score << "          Player 2:  " << p2Score << std::endl << std::endl;
	}
	else
	{
		std::cout << "STALEMATE!! There were no winners in this war." << std::endl;
		std::cout << "Final Score:\nPlayer1:  " << p1Score << "          Player 2:  " << p2Score << std::endl << std::endl;
	}
}