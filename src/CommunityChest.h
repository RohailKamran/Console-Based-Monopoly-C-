#pragma once
#include "Cell.h"
#include<string>
class CommunityChest :
	public Cell
{
public:
	CommunityChest();
	CommunityChest(string name);
	int RelevantFunction(class Player& player, int playerTurn)override;

};


