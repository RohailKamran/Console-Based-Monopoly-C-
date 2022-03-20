#include "GoToJail.h"

GoToJail::GoToJail(){
	index = nextIndex;
	nextIndex++;
}

GoToJail::GoToJail(string name) {
	this->name = name;
	index = nextIndex;
	nextIndex++;
}

int GoToJail::RelevantFunction(class Player& player, int playerTurn) {
	player.SetPosition(10);
	//player.MovePosition(10);
	cout << player.GetName() << " is now in Jail" << endl;
	return -200;
}