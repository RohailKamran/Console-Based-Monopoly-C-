#pragma once
#include "Cell.h"
class Station :
	public Cell
{
public:
	Station();
	Station(string name, int price, int rent);

	int ShowBuyMenu(Player& player);

	void ShowSellOrMortgageMenu(Player& player);
	void DeductRent(Player& player);

	int RelevantFunction(class Player& player, int playerTurn)override;
};



