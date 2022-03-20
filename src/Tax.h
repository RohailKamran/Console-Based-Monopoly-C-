#pragma once
#include "Cell.h"
#include<string>
class Tax :
	public Cell
{

public:
	Tax();
	Tax(string name, int tax);

	int RelevantFunction(class Player& player, int playerTurn)override;

};

