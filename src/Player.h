#ifndef MONOPOLYTEST_PLAYER_H
#define MONOPOLYTEST_PLAYER_H
#include "string"
using namespace std;
class Cell;

class Player {

public: int playerID;
private:
    string name;
    int position;
    string color;
    string symbol;
    Cell** ownedCells;
    bool isBankrupt;
    int moneyInTheWallet;
    //int cellsTravelled = 0;
    int totalPropertiesOwned;
    bool canUpgrade;
    bool canSell;//Trade Functionality
    bool inJail;

public: 

    Cell** GetOwnedCells();

    int GetTotalPropertiesOwned();

    void IncrementTotalPropertiesOwned();

    void SubtractMoneyInTheWallet(int subtractionAmount);

    static int nextID;

    Player();

    int GetID();

    void SetMoneyInTheWallet(int moneyInTheWallet);

    int GetMoneyInTheWallet();

    void SetName(string name);

    string GetName();

    void MovePosition(int value);

    bool GetBankruptcyStatus();
    
    int GetPosition();

    bool Buy(class Cell& cell);

    bool Sell(class Cell& cell);

    void PayRent(class Cell &cell);

    void SetBankruptcyStatus(bool isBankrupt);

    void AddMoneyInTheWallet(int additionalAmount);

    void ReceiveRent(Player& player, Cell& cell);

    void SetColor(string color);

    string GetColor();

    string GetSymbol();

    void SetSymbol(string symbol);

    bool Unmortgage(class Cell& cell);

    bool Mortgage(class Cell& cell);

    void SetPosition(int position);

};


#endif //MONOPOLYTEST_PLAYER_H

