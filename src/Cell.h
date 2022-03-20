#ifndef MONOPOLYTEST_CELL_H
#define MONOPOLYTEST_CELL_H
#include "string"
class Player;
#include "Player.h"

using namespace std;
#include <iostream>



class Cell {

protected:
    int price;
    int ownerID;
    int sellPrice;
    class Player* ownerPtr = nullptr;
    int rent;
    int index;
    string name;
    bool isMortgaged;
    int tax;

public:
    static int nextIndex;
    virtual int RelevantFunction(class Player& player, int playerTurn){
        //cout << "Cell Function was called, override failed";
        return -2;
    }

    virtual void Test() {
        ///cout << "Cell functrion was called on parent" << endl;
    }

    bool GetIsMortgaged() {
        return this->isMortgaged;
    }

    int GetPrice() {
        return this->price;
    }

    int GetRent() {
        return this->rent;
    }
    int GetSellPrice() {
        return this->sellPrice;
    }

    virtual int GetIndex() {
        return index;
    }

    string GetName() {
        return this->name;
    }

    virtual int GetOwnerID() {
        return this->ownerID;
    }

    virtual void SetOwnerID(int ownerID) {
        this->ownerID = ownerID;
    }

    virtual void SetOwner(Player& player) {
        this->ownerPtr = nullptr;
        this->ownerPtr = &player;
    }

    virtual void RecieveRent() {
        ownerPtr->AddMoneyInTheWallet(this->GetRent());
    }

    virtual Player& GetOwner() {
        return this->ownerPtr[0];
    }
};


#endif //MONOPOLYTEST_CELL_H
