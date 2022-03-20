#include "Property.h"

Property::Property() {
	price = 1000;
	rent = 500;
	sellPrice = 500;
	nextUpgradePrice = 100;
	upgradeCount = 0;
	ownerID = -1;//No Man's Land
	index = nextIndex;
	nextIndex++;
	
}

Property::Property(string name, int price, int rent, int sellPrice, int nextUpgradePrice, int upgradeCount, int ownerID) {
	this->name = name;
	this->price = price;
	this->rent = rent;
	this->sellPrice = sellPrice;
	this->nextUpgradePrice = nextUpgradePrice;
	this->upgradeCount = upgradeCount;
	this->ownerID = ownerID;//No Man's Land
	index = nextIndex;
	nextIndex++;
	this->isMortgaged = false;
}



void Property::SetPrice(int price) {
	this->price = price;
}

int Property::GetIndex() {
	return index;
}

void Property::SetIndex(int index) {
	this->index = index;
}


void Property::SetRent(int rent) {
	this->rent = rent;
}

int Property::GetOwnerID() { 
	return ownerID;
}

//void Property::SetOwnerID(int ownerID) {
//	this->ownerID = ownerID;
//}

int Property::GetNextUpgradePrice() {
	return nextUpgradePrice;
}

void Property::SetNextUpgradePrice(int nextUpgradePrice) {
	this->nextUpgradePrice = nextUpgradePrice;
}

int Property::ShowBuyMenu(Player &player) {
	cout << player.GetName() << " This property is for sale!" << endl;
	cout << "To buy this property you have to pay : " << GetPrice()<<endl;
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

//void Property::ShowAuctionMenu() {
//
//}

void Property::ShowSellOrMortgageMenu(Player &player) {
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
		cout<<"You have decided to do nothing and allow the next player to roll the dice" << endl;
		system("pause");
	}
}

void Property::DeductRent(Player &player) {
	cout << player.GetName() <<"you have come to a property that is owned by " << (*ownerPtr).GetName();
	cout << player.GetName() << " you have Rs " << player.GetMoneyInTheWallet() << " right now and";
	cout << endl << "You now have to pay " << this->GetRent() << " to " << (*ownerPtr).GetName();
	system("pause");
	player.PayRent(*this);//deducts money from player who pays rent
	cout << (*ownerPtr).GetName() << " has " << (*ownerPtr).GetMoneyInTheWallet() << " Rs before recieving rent." << endl;
	(*ownerPtr).AddMoneyInTheWallet(GetRent());//Adds that money to owner's wallet
	cout << (*ownerPtr).GetName() << " has " << (*ownerPtr).GetMoneyInTheWallet() << " Rs now." << endl;
	system("pause");

}

//int Property::SelectBuyOrAuction() {
//	int option;
//	cout<<""
//}

int Property::RelevantFunction(Player& player, int playerTurn) {
	if (this->GetOwnerID() == -1) {
		
		int returnedValue = ShowBuyMenu(player);//Also takes care of Auction
		if (returnedValue==1) {
			this->SetOwnerID(playerTurn);
			this->SetOwner(player);
		}
		else if (returnedValue == -100) {
			return -100;//Only in case of auction, baaki functionality as it is
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
			system("pause");
		}
	}
	return GetOwnerID();
}


void Property::SetOwner(Player& player) {
	this->ownerPtr = nullptr;
	this->ownerPtr = &player;
}

void Property::RecieveRent() {
	(*ownerPtr).AddMoneyInTheWallet(this->GetRent());
}

Player& Property::GetOwner() {
	return this->ownerPtr[0];
}


void Property::SetOwnerID(int ownerID) {
	this->ownerID = ownerID;
}
