#include "Player.h"
#include "string"
#include "Cell.h"
using namespace std;

Cell** Player::GetOwnedCells() {
    return (this->ownedCells);
}

int Player::GetTotalPropertiesOwned() {
        return totalPropertiesOwned;
}


void Player::SubtractMoneyInTheWallet(int subtractionAmount) {
    moneyInTheWallet = moneyInTheWallet - subtractionAmount;
    if (GetMoneyInTheWallet() < 0) {
        SetBankruptcyStatus(true);
        cout << "You have " << GetMoneyInTheWallet() << " Rs, hence you have gone bankrupt." << endl;
        cout << "Thank you for playing Monopoly Pakistan Edition, but this is the end of the line for now. Hope to see you win next time!" << endl;
        system("pause");
    }
}

void Player::IncrementTotalPropertiesOwned() {
    totalPropertiesOwned++;
}

Player::Player() {
    this->playerID = nextID;
    nextID++;
    this->position = 0;
    this->name = "";
    //Cell cells* ownedCells = nullptr;
    this->isBankrupt = false;
    this->moneyInTheWallet = 5000;
    //cellsTravelled = 0;
    this->totalPropertiesOwned = 0;
    this->canUpgrade = false;
    this->canSell = false;
    this->inJail = false;
    this->ownedCells = nullptr;
    ownedCells = new Cell* [40];
    for (int i = 0; i < 40; i++) {
        ownedCells[i] = nullptr;
    }
}

int Player::GetID() {
    return this->playerID;
}

void Player::SetMoneyInTheWallet(int moneyInTheWallet) {
    this->moneyInTheWallet = moneyInTheWallet;
}

int Player::GetMoneyInTheWallet() {
    return moneyInTheWallet;
}


void Player:: SetName(string name) {
    this->name = name;
}

void Player:: SetColor(string color) {
    this->color = color;
}

string Player:: GetColor() {
    return this->color;
}

void Player:: SetSymbol(string symbol) {
    this->symbol = symbol;
}

string Player:: GetSymbol() {
    return this->symbol;
}

string Player:: GetName() {
    return this->name;
}


void Player::MovePosition(int value) {
    this->position += value;
    if (this->position >= 40) {
        this->position = this->position - 40;
    }
}

bool Player::GetBankruptcyStatus() {
    return isBankrupt;
}

int Player::GetPosition() {
    return this->position;
}

void Player::SetBankruptcyStatus(bool isBankrupt) {
    this->isBankrupt = isBankrupt;
}

bool Player::Buy(Cell &cell){
    cout << "You have Rs " << GetMoneyInTheWallet() << " right now" << endl;
        if (cell.GetPrice() > moneyInTheWallet) {
            cout << "\nYou can not buy this property because you don't have enough money" << endl;
            return false;
        }
        //update moneyInTheBank, propertiesOwned
        moneyInTheWallet = moneyInTheWallet - cell.GetPrice();
        cout << "Now you have " << moneyInTheWallet << " Rs Remaining..." << endl;
        totalPropertiesOwned++;
        cout << "You now have " << totalPropertiesOwned << " properties" << endl;
        ownedCells[cell.GetIndex()] = &cell;
        cout << "You have bought this Property, congratulations!" << endl;
        system("pause");
        return true;
    
}

bool Player::Sell(class Cell& cell) {
    //*(GetOwnedCells()) = nullptr;
    cout << "You had " << GetMoneyInTheWallet() << " Rs" << endl;
    cout << "then you decided to sell this property for " << cell.GetSellPrice();
    this->AddMoneyInTheWallet(cell.GetSellPrice());
    cout << endl << "Now you have : " << GetMoneyInTheWallet() << " Rs" << endl;
    system("pause");
    *(GetOwnedCells()) = nullptr;
    return true;
}

//void Player::ReceiveRent(Player &player, Cell &cell) {
//    player.GetMoneyInTheWallet() = player.SetMoneyInTheWallet() + cell.GetRent();
//}

void Player::PayRent(Cell &cell) {
    //int y = playerPtr[owned].GetMoneyInTheWallet() + rent;
    //cout << "You have come to a property that is owned by Player " << (cell.GetOwnerID() + 1)<< endl;
    //cout << "You have to pay " << cell.GetRent() << " Rs to player " << (cell.GetOwnerID() + 1) << endl;
    //cout << "Press any key to pay the rent and allow next player to the roll dice." << endl;
    //cout << "Press any key to pay the rent and allow next player to the roll dice." << endl;
    //playerPtr[owned].AddMoneyInTheWallet(rent);
    if (cell.GetIsMortgaged() == false) {
        int remainingMoney = this->GetMoneyInTheWallet();
        if (remainingMoney - cell.GetRent() < 0)
        {
            remainingMoney = remainingMoney - cell.GetRent();
            this->SetBankruptcyStatus(true);
            cout << GetName() << " has gone bankrupt, that means " << GetName() << " can no longer play." << endl;
            system("pause");
        }
        else
        {
            remainingMoney = remainingMoney - cell.GetRent();
            this->SetMoneyInTheWallet(remainingMoney);
        }
    }
}

void Player::AddMoneyInTheWallet(int additionalAmount) {
    this->SetMoneyInTheWallet(this->GetMoneyInTheWallet() + additionalAmount);
}

bool Player::Mortgage(class Cell& cell) {
    //*(GetOwnedCells()) = nullptr;
    cout << "You had " << GetMoneyInTheWallet() << " Rs" << endl;
    cout << "then you decided to morgage this property for " << ((cell.GetSellPrice())/2);
    this->AddMoneyInTheWallet(((cell.GetSellPrice()) / 2));
    cout << endl << "Now you have : " << GetMoneyInTheWallet() << " Rs" << endl;
    system("pause");
    //*(GetOwnedCells()) = nullptr;
    return true;
}

bool Player::Unmortgage(class Cell& cell) {
    if (GetMoneyInTheWallet() < ((cell.GetSellPrice()) / 2)) {
        cout << "Sorry, you can not unmortgage this property because you don't have enough money" << endl;
        cout << "You have : " << GetMoneyInTheWallet() << " and the unmortgage price for " << cell.GetName() << " is " << ((cell.GetSellPrice()) / 2);
        system("pause");
        return false;
    }
    SubtractMoneyInTheWallet(((cell.GetSellPrice()) / 2));
    return true;
}

void Player::SetPosition(int position) {
    this->position = position;
}

//bool Player::DeductRent(Cell& cell) {
//
//}


int Player::nextID = 1;
//MONOPOLYTEST_PLAYER_H
