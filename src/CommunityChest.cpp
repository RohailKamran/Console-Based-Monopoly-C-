#include "CommunityChest.h"


CommunityChest::CommunityChest() {
	index = nextIndex;
	nextIndex++;
}

CommunityChest::CommunityChest(string name) {
	this->name = name;
	index = nextIndex;
	nextIndex++;
}

int CommunityChest::RelevantFunction(class Player& player, int playerTurn) {
	int result = rand() % 10;
	cout <<player.GetName()<< " you have landed on a Community Chest.\nYou have "<<player.GetMoneyInTheWallet()<<" Rs.\nTo see what Community Chest has in store for you," << endl;
	system("pause");
	if (result == 0) {
		cout << "Congratulations! You have recieved 500 Rs from the bank. ";
		player.AddMoneyInTheWallet(500);
		cout << player.GetName() << " now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;
	}
	if (result == 1) {
		cout << "Congratulations! You have recieved 600 Rs from the bank. ";
		player.AddMoneyInTheWallet(600);
		cout << player.GetName() << " now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 2) {
		cout << "Congratulations! You have recieved 700 Rs from the bank. ";
		player.AddMoneyInTheWallet(700);
		cout << player.GetName() << " now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 3) {
		cout << "Congratulations! You have recieved 800 Rs from the bank. ";
		player.AddMoneyInTheWallet(800);
		cout << player.GetName() << " now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 4) {
		cout << "Congratulations! You have recieved 900 Rs from the bank. ";
		player.AddMoneyInTheWallet(900);
		cout << player.GetName() << " now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 5) {
		cout << "Congratulations! You have recieved 1000 Rs from the bank. ";
		player.AddMoneyInTheWallet(1000);
		cout << player.GetName() << " now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 6) {
		cout << "Oops! You have to give 500 Rs to the bank. ";
		system("pause");
		player.SubtractMoneyInTheWallet(500);
		cout << player.GetName() << " now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 7) {
		cout << "Oops! You have to give 600 Rs to the bank. ";
		system("pause");
		player.SubtractMoneyInTheWallet(600);
		cout << player.GetName() << " now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 8) {
		cout << "Oops! You have to give 700 Rs to the bank. ";
		system("pause");
		player.SubtractMoneyInTheWallet(700);
		cout << player.GetName() << " now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 9) {
		cout << "Oops! You have to give 800 Rs to the bank. ";
		system("pause");
		player.SubtractMoneyInTheWallet(800);
		cout << player.GetName() <<" now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	system("pause");
	return -200;
}