#pragma once
#include "Cell.h"
#include <string>
class Utility :
	public Cell
{
public:
	Utility();

	Utility(string name, int price, int rent);

	int ShowBuyMenu(Player& player);

	void ShowSellOrMortgageMenu(Player& player);

	void DeductRent(Player& player);

	int RelevantFunction(class Player& player, int playerTurn)override;

	//int RelevantFunction(class Player& player, int playerTurn)override;
};
