#pragma once
#include "Cell.h"
class Go :
	public Cell
{

public:
	Go();
    Go(string name);

	int RelevantFunction(class Player& player, int playerTurn)override;

	
};

