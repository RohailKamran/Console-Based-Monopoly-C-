#include "Go.h"

Go::Go() {
	index = nextIndex;
	nextIndex++;
	name = "Go";
}

Go::Go(string name) {
    this->name = name;
}

int Go::RelevantFunction(Player& player, int playerTurn) {
	cout << player.GetName()<<" because you crossed Go, You have recieved 500 Rs";
	player.AddMoneyInTheWallet(500);
	cout << "Now you have " << player.GetMoneyInTheWallet() << " Rs" << endl;
	system("pause"); 
	return 200;
}
