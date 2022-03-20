#pragma once
#include "Cell.h"
#include<string>
class Chance :
	public Cell
{
public:
	Chance();
	Chance(string name);

	int RelevantFunction(class Player& player, int playerTurn)override;

};

