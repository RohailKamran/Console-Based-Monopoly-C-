#include "Cell.h"
#include "Player.h"


class Property :
	public Cell
{
	
	int nextUpgradePrice;
	int upgradeCount;//everytime this is incremented upto a limit, a message is printed and rent is increased, sell price is increased and nextUpgradePrice is increased
	//ownerID is inherited
	

public:

	Property();

	Property(string name, int price, int rent, int sellPrice, int nextUpgradePrice, int upgradeCount, int ownerID);

	int RelevantFunction(Player & player, int playerTurn) override;

	void SetPrice(int price);

	int GetIndex() override;

	void SetIndex(int index);

	void SetRent(int rent);

	int GetOwnerID() override;

	//void SetOwnerID(int ownerID);

	int GetNextUpgradePrice();

	void SetNextUpgradePrice(int nextUpgradePrice);

	int ShowBuyMenu(Player& player);

	//void ShowAuctionMenu();

	void ShowSellOrMortgageMenu(Player &player);

	void DeductRent(Player &player);

	void SetOwner(Player& player) override;

	void RecieveRent() override;

	Player& GetOwner()override;

	void SetOwnerID(int ownerID)override;

};

