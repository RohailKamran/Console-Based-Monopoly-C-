#include <iostream>
#include "Player.h"
#include "Board.h"
#include "PakistanBoard.h"
#include <time.h>
#define RESET   "\033[0m"

using namespace std;

int numberOfPlayers;
int turn;
Player* currentPlayer = nullptr;
Board* currentBoard = nullptr;
Player* listOfPlayers = nullptr;

bool isGameOver = false;

void ShowFirstScreen() {

    cout << " __  __  ___  _   _  ___  ____   ___  _  __   __" << endl;
    cout << "|  \\/  |/ _ \\| \\ | |/ _ \\|  _ \\ / _ \\| | \\ \\ / /" << endl;
    cout << "| |\\/| | | | |  \\| | | | | |_) | | | | |  \\ V /" << endl;
    cout << "| |  | | |_| | |\\  | |_| |  __/| |_| | |___| |" << endl;
    cout << "|_|  |_|\\___/|_| \\_|\\___/|_|    \\___/|_____|_|" << endl;

    cout << "---------------------------------------------------" << endl;
    cout << "By Rohail Kamran - " << endl<<endl<<endl;
}

int RollDice() {
    cout << "Turn: " << currentPlayer->GetName() << endl;
    cout << "Press any key to roll dice." << endl;
    int val = 0;
    system("pause");
    int result = (rand() % 6) + 1;
    cout << "Dice value is: " << result << endl;
    cout << "----------------------------" << endl;
    system("pause");
    return result;
}

void NextPlayerTurn() {
    system("cls");
    //PrintBoard();
    turn++;
        while (listOfPlayers[turn].GetBankruptcyStatus() == true) {
            turn++;
            if (turn >= numberOfPlayers)
                turn = 0;
        }

    if (turn >= numberOfPlayers)
        turn = 0;

}
//Player* player = &((*cell).GetOwner());
void PrintBoard() {

    system("cls");

    ShowFirstScreen();

    for(int i=0; i<40; i++) {
        if(i%5 == 0)
            cout << endl;

        Cell *cell = currentBoard->GetCellAtPosition(i);
        int totalTextLength = 30;
        int propertyTextLength = cell->GetName().length();
        int usedLength = 0;
        //Player* player = &((*cell).GetOwner());
        cout << "|" << i << "|" << (cell->GetName());//<<(player->GetColor());
        //player = nullptr;
        for(int j=0; j< numberOfPlayers; j++) {
            if(i == listOfPlayers[j].GetPosition()) {
                cout << listOfPlayers[j].GetColor() << listOfPlayers[j].GetSymbol() << "\033[0m";
                usedLength ++;
            }
        }
        if(i>9) {
            usedLength++;
        }
        for(int k=0; k<(totalTextLength-propertyTextLength)-usedLength;k++) {
            cout << " ";

        }

    }
    cout << endl << endl << endl;
    cout << "Before current move" << endl;
    for (int i = 0; i < numberOfPlayers; i++) {
        if (listOfPlayers[i].GetBankruptcyStatus()) {
            cout << listOfPlayers[i].GetColor() << listOfPlayers[i].GetName() << " is Bankrupt." << listOfPlayers[i].GetSymbol() << "\033[0m"<< endl;
        }
        else if (!listOfPlayers[i].GetBankruptcyStatus()) {
            cout << listOfPlayers[i].GetColor() << listOfPlayers[i].GetName() << " has "<< listOfPlayers[i].GetMoneyInTheWallet() << "Rs and "<< listOfPlayers[i].GetTotalPropertiesOwned() <<" properties." << listOfPlayers[i].GetSymbol() << "\033[0m" << endl;
        }
    }

    cout << endl << endl << endl;
}


void PrintGame() {
    //ShowFirstScreen();
    PrintBoard();
    for (int i = 0; i < numberOfPlayers; i++) {
        cout << listOfPlayers[i].GetName() << " is at position: " << listOfPlayers[i].GetPosition() << endl;
    }
}


int Auction(Player* listOfPlayers, int numberOfPlayers, Cell& cell) {
    int nOfPla = numberOfPlayers; // step 3
    int lPlayer = 0;
    int hBid = -1;
    int bid; // step 4
    int option;

    bool* bPlayer = new bool[numberOfPlayers];

    for (int i = 0; i < numberOfPlayers; i++)
    {
        bPlayer[i] = true;
    }

    int j = 0;
    int auctionQuitters = 0; // bPlayer if false

    cout << "Bid starting." << endl; //step 2

    while (auctionQuitters != nOfPla - 1) {

        for (int i = 0; i < nOfPla; i++) {

            if (bPlayer[i] == true) {

                j++;
                cout << "Player " << listOfPlayers[i].GetName() << " do you want to place bid? \n Press 1 for Yes, 2 for No." << endl;
                cin >> option;
                if (option == 1) {

                    cout << "Place your bid" << endl;
                    cin >> bid;
                    //step 5
                    while (bid <= hBid || bPlayer[i] == false || bid > listOfPlayers[i].GetMoneyInTheWallet()) {

                        if (!bPlayer[i]) {
                            break;
                        }
                        else if (listOfPlayers[i].GetBankruptcyStatus()) {
                            break;
                        }
                        else if (bid > listOfPlayers[i].GetMoneyInTheWallet()) {
                            cout << "You only have : " << listOfPlayers[i].GetMoneyInTheWallet() << " Rs," << endl;
                            cout << "Please enter an affordable bid amount or enter -1 to quit the bid" << endl;
                        }
                        else if (bid <= hBid) {
                            cout << "Please bid higher than " << hBid << " or enter -1 to refuse to bid" << endl;
                            cin >> bid;
                        }
                        if (bid == -1) {
                            bPlayer[i] = false;
                            auctionQuitters++;
                            break;
                        }

                    }

                    if (bid > hBid) {
                        hBid = bid;
                        lPlayer = i;
                    }
                }

                if (option == 2) {
                    bPlayer[i] = false;
                    auctionQuitters++;
                }

            }

            cout << auctionQuitters << " Player(S) quit the auction" << endl;

        }

    }

    cout << "Bid Winner is Player " << lPlayer + 1 << " with a bid of " << hBid << endl;
    listOfPlayers[lPlayer].GetOwnedCells()[cell.GetIndex()] = &cell;
    cell.SetOwner(listOfPlayers[lPlayer]);
    cell.SetOwnerID(lPlayer);  
    //cout << "The  " << hBid << endl;
    listOfPlayers[lPlayer].SubtractMoneyInTheWallet(hBid);
    cout << "Now " << listOfPlayers[lPlayer].GetName() << " has " << listOfPlayers[lPlayer].GetMoneyInTheWallet() << "Rs";
    listOfPlayers[lPlayer].IncrementTotalPropertiesOwned();
    cout << "and owns " << listOfPlayers[lPlayer].GetTotalPropertiesOwned() << " Properties." << endl;
    cout << "Press any key to allow the next player to roll the dice." << endl;
    system("pause");
    return lPlayer;

}//END OF AUCTION FUNCTION


//int TurnsDecider(int& turn, int numberofplayers, Player* playerPtr) {
//    //Call CheckWinner Fuction which should return number of players not bankrupt, as soon as the number goes to 1, End Game().
//    //if true, then call ENDGAME();
//    if (turn < numberofplayers - 1) {
//        turn++;
//        while (playerPtr[turn].GetBankruptcyStatus() == true) {
//            TurnsDecider(turn, numberofplayers, playerPtr);
//        }
//    }
//    else {
//        turn = -1;
//        TurnsDecider(turn, numberofplayers, playerPtr);
//    }
//
//    return turn;
//}
int TraverseForWinner();

void SetBoard() {
    int boardType = 0;
    cout << "Board Type" << endl;
    cin >> boardType;
    if (boardType != 2) {
        currentBoard = new PakistanBoard();
        currentBoard->SetBoard();
    }
}

int Game() {
    while (!isGameOver) {

        PrintGame();

        currentPlayer = &listOfPlayers[turn];
        int diceResult = RollDice();
        currentPlayer->MovePosition(diceResult);
        Cell* cell = currentBoard->GetCellAtPosition(currentPlayer->GetPosition());
        

        PrintBoard();
        cout << currentPlayer->GetName() << " reached " + cell->GetName() << endl;
        system("pause");
        int OwnerID = cell->RelevantFunction(*currentPlayer, currentPlayer->GetID());
        if (OwnerID == -100) {//Player chose Auction
            Auction(listOfPlayers, numberOfPlayers, *cell);//Auction will return leading player, but as it is assigning cells to owners and owners to cells within the function, I dont see any need to store the returned value
        }
        //cout << OwnerID;
        //if (OwnerID > -1) {
        //    cell->SetOwner(listOfPlayers[OwnerID]);
        //    if (cell->GetOwnerID() != currentPlayer->GetID()) {//if player turn and owner id are same, then dont give owner rent, else give rent
        //        cell->RecieveRent();
        //    }
        //}

        //PrintGame();

        int Winner = TraverseForWinner();
        if (Winner > -1) {
            isGameOver = true;
            PrintBoard();
            cout << endl << endl<<"The winner of this game is "<<listOfPlayers[Winner].GetName()<<endl;
            cout << listOfPlayers[Winner].GetName() << " Congratuluations on your win!!"<<endl;
            system("pause");
            return 0;
        }
        NextPlayerTurn();
    }


}


int ReturnWinner() {
    for (int i = 0; i < numberOfPlayers; i++) {
        if (listOfPlayers[i].GetBankruptcyStatus() == false) {
            return i;
        }

    }
    return 0;
}

int TraverseForWinner() {
    int returnvalue = -1;
    int count = 0;
    for (int i = 0; i < numberOfPlayers; i++) {
        if (listOfPlayers[i].GetBankruptcyStatus() == true) {
            count++;
        }
    }
    if (count == numberOfPlayers - 1) {
        returnvalue = ReturnWinner();
    }
    return returnvalue;
}

void AddMoneyForPlayer(int additionalAmount) {

}

string getRandomSymbol() {
    srand(time(0));
    int i = rand()%6 + 1;
    return "\xfb";
    switch (i) {
        case 0:
            return "\xfa";
        case 1:
            return "\xfb";
        case 2:
            return "\xfc";
        case 3:
            return "\xfd";
        case 4:
            return "\xfe";
        case 5:
            return "O";
        case 6:
            return "Z";
        case 7:
            return "X";
        case 8:
            return "P";
        case 9:
            return "H";
        case 10:
            return "Q";
        case 11:
            return "W";
        case 12:
            return "E";
    }
    return "♥";
}

int main() {
    ShowFirstScreen();
    cout << "How many Players are in the game?" << endl << ": ";
    cin >> numberOfPlayers;
    listOfPlayers = new Player[numberOfPlayers];
    for (int i = 0; i < numberOfPlayers; i++) {
        string nameOfPlayer = "";
        cout << "Enter Player " << (i + 1) << " Name : " << endl;
        cin >> nameOfPlayer;
        listOfPlayers[i].SetName(nameOfPlayer);
        listOfPlayers[i].SetColor("\033[3" + to_string(i+1) + "m");
        string symbol = getRandomSymbol();
        listOfPlayers[i].SetSymbol(symbol);
        cout << listOfPlayers[i].GetColor() << "Your color is this and symbol is " << symbol << RESET << endl;
    }
    
    SetBoard();
    
    cout << "Starting Game ..." << endl << endl;
    turn = 0;
    Game();
    return 0;
}

