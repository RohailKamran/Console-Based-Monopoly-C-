#include "Tax.h"


Tax::Tax() {
	index = nextIndex;
	nextIndex++;
}

Tax::Tax(string name, int tax) {
	this->tax = tax;
	this->name = name;
	index = nextIndex;
	nextIndex++;
}

int Tax::RelevantFunction(Player& player, int playerTurn) {
	cout << player.GetName() <<" you have landed on " << GetName() << endl;
	cout << "You have " << player.GetMoneyInTheWallet() << " Rs and you have to pay "<<tax<<" Rs to continue." << endl;
//	cout << "You have to pay : " << tax << " Rs"<<endl;
	system("pause");
	cout << endl;
	if (player.GetMoneyInTheWallet() < tax) {
		player.SubtractMoneyInTheWallet(tax);
		cout << "Now you have " << player.GetMoneyInTheWallet() << " Rs"<<endl;
		system("pause");
		player.SetBankruptcyStatus(true);
		return 200;
	}
	player.SubtractMoneyInTheWallet(tax);
	cout << "Now you have " << player.GetMoneyInTheWallet() << " Rs" << endl;
	system("pause");
	return 200;
}
