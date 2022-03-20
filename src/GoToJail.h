#pragma once
#include "Cell.h"
class GoToJail :
	public Cell
{
public:
	GoToJail();

	GoToJail(string name);

	int RelevantFunction(class Player& player, int playerTurn)override;
};

