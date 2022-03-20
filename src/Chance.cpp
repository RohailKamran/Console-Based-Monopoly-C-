#include "Chance.h"

Chance::Chance() {
	index = nextIndex;
	nextIndex++;

}

Chance::Chance(string name)
{
this->name = name;
index = nextIndex;
nextIndex++;

}

int Chance::RelevantFunction(class Player& player, int playerTurn) {
	int result = rand() % 10;
	cout << "You have landed on a chance card. To see what chance has in store for you," << endl;
	system("pause");
	if (result == 0) {
		cout << "Congratulations! You have recieved 500 Rs from the bank";
		player.AddMoneyInTheWallet(500);
		cout << "Now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;
	}
	if (result == 1) {
		cout << "Congratulations! You have recieved 600 Rs from the bank";
		player.AddMoneyInTheWallet(600);
		cout << "Now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 2) {
		cout << "Congratulations! You have recieved 700 Rs from the bank";
		player.AddMoneyInTheWallet(700);
		cout << "Now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 3) {
		cout << "Congratulations! You have recieved 800 Rs from the bank";
		player.AddMoneyInTheWallet(800);
		cout << "Now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 4) {
		cout << "Congratulations! You have recieved 900 Rs from the bank";
		player.AddMoneyInTheWallet(900);
		cout << "Now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 5) {
		cout << "Congratulations! You have recieved 1000 Rs from the bank";
		player.AddMoneyInTheWallet(1000);
		cout << "Now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 6) {
		cout << "Oops! You have to give 500 Rs to the bank";
		player.SubtractMoneyInTheWallet(500);
		cout << "Now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 7) {
		cout << "Oops! You have to give 600 Rs to the bank";
		player.SubtractMoneyInTheWallet(600);
		cout << "Now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 8) {
		cout << "Oops! You have to give 700 Rs to the bank";
		player.SubtractMoneyInTheWallet(700);
		cout << "Now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	if (result == 9) {
		cout << "Oops! You have to give 800 Rs to the bank";
		player.SubtractMoneyInTheWallet(800);
		cout << "Now you have " << player.GetMoneyInTheWallet() << "Rs" << endl;

	}
	system("pause");
	return -200;
}
