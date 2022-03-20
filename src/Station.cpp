#include "Station.h"

Station::Station() {
	this->ownerID = -1;
	this->price = 0;
	index = nextIndex;
	nextIndex++;

}

Station::Station(string name, int price, int rent) {
	this->ownerID = -1;
	this->price = price;
	this->name = name;
	this->rent = rent;
	index = nextIndex;
	nextIndex++;

}

int Station::ShowBuyMenu(Player& player) {
	cout << player.GetName() << " now you have " << player.GetMoneyInTheWallet() << " Rs." << endl;
	cout << player.GetName() << " You can buy this Station!" << endl;
	cout << "To buy this Station you have to pay : " << GetPrice() << endl;
	cout << "If you want to Buy, press B.\nPress A to start Auction\nElse press any Key to continue.";
	char s;
	cin >> s;
	bool isBought = false;
	int returnValue;
	if (s == 'B' || s == 'b') {
		isBought = player.Buy(*this);
		if (isBought) {
			returnValue = 1;
		}
		if (!isBought) {
			returnValue = -1;
		}
		system("pause");
	}
	else if (s == 'A' || s == 'a') {
		returnValue = -100;
	}
	else {
		cout << "\nYou have chosen not to buy this property or";
		isBought = false;
		returnValue = -1;
	}
	//player.Buy()
	return returnValue;

}

void Station::ShowSellOrMortgageMenu(Player& player) {
	if (!isMortgaged) {
		cout << "You are the owner of this property\nif you wish to sell this property press S\nif you wish to Mortgage this Property press M\nPress any other key to allow next player to roll dice" << endl;
		char s;
		cin >> s;
		if (s == 'S' || s == 's') {
			player.Sell(*this);
			ownerPtr = nullptr;
			ownerID = -1;
		}
		else if (s == 'M' || s == 'm') {
			player.Mortgage(*this);
			isMortgaged = true;

		}
	}//else unmortgage menu
	else if (isMortgaged) {
		cout << "This is a property that you have mortgaged.\nIn order to Un-Mortgage this property, press U\nOr Press any other key to move on and allow next player to roll dice." << endl;
		char s;
		cin >> s;
		if (s == 'U' || s == 's') {
			bool wasSuccess = player.Unmortgage(*this);
			if (wasSuccess) {
				isMortgaged = false;
			}
		}
	}

	//else if upgrade
	else {
		cout << "You have decided to do nothing and allow the next player to roll the dice" << endl;
		system("pause");
	}
}

void Station::DeductRent(Player& player) {
	cout << player.GetName() << "you have come to a property that is owned by " << (*ownerPtr).GetName();
	cout << endl << "You now have to pay " << this->GetRent() << " to " << (*ownerPtr).GetName();
	system("pause");
	player.PayRent(*this);//deducts money from player who pays rent
	cout << (*ownerPtr).GetName() << " has " << (*ownerPtr).GetMoneyInTheWallet() << " Rs before recieving rent." << endl;
	(*ownerPtr).AddMoneyInTheWallet(GetRent());//Adds that money to owner's wallet
	cout << (*ownerPtr).GetName() << " has " << (*ownerPtr).GetMoneyInTheWallet() << " Rs now." << endl;
	system("pause");

}

int Station::RelevantFunction(class Player& player, int playerTurn) {
	cout << "You have landed on " << GetName() << endl;

	if (this->GetOwnerID() == -1) {
		cout << "You have to pay " << GetRent() << endl;
		cout << "Press any key to pay rent" << endl;
		system("pause");
		player.SubtractMoneyInTheWallet(GetRent());

		if (player.GetBankruptcyStatus() == false) {
			int returnedValue = ShowBuyMenu(player);//Also takes care of Auction
			if (returnedValue == 1) {
				this->SetOwnerID(playerTurn);
				this->SetOwner(player);
			}
			else if (returnedValue == -100) {
				return -100;//Only in case of auction, baaki functionality as it is
			}
		}
	}
	else if (this->GetOwnerID() == player.playerID) {
		ShowSellOrMortgageMenu(player);
	}
	else {
		if (!isMortgaged) {
			DeductRent(player);
		}
		else if (isMortgaged) {
			cout << "Even though you have come to " << (*ownerPtr).GetName() << "'s property, you don't have to pay any rent as this property is mortgaged." << endl;
		}
	}
	return GetOwnerID();
}
