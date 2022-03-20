#pragma once
#include "Board.h"
#include "Cell.h"
#include<iostream>
#include "Go.h"
#include "Property.h"
#include "FreeParking.h"
#include "CommunityChest.h"
#include "Chance.h"
#include "Tax.h"
#include "JustVisiting.h"
#include "GoToJail.h"
#include "Utility.h"
#include "Station.h"


using namespace std;

class PakistanBoard :	public Board
{
public:
	void SetBoard() override {
		this->cells[0] = new Go("Go");
		this->cells[1] = new Property("Bahria Town Block A", 2500, 800, 1300, 100, 0, -1);
		this->cells[2] = new CommunityChest("Community Chest");
		this->cells[3] = new Property("Bahria Town Block B", 3000, 900, 1500, 100, 0, -1);
		this->cells[4] = new Tax("Land Tax", 200);
		this->cells[5] = new Station("Orange Train", 2500, 350);
		this->cells[6] = new Property("Bahria Town Block C", 3000, 1000, 1500, 100, 0, -1);
		this->cells[7] = new Chance("Chance");
		this->cells[8] = new Utility("PTCL", 8000, 500);
		this->cells[9] = new Utility("SUI Gas", 2500, 350);
		this->cells[10] = new JustVisiting("Just Visiting");
		this->cells[11] = new Property("Gulberg II A", 1000, 300, 500, 100, 0, -1);
		this->cells[12] = new Utility("LESCO", 5000, 450);
		this->cells[13] = new Property("Gulberg II B", 1200, 350, 500, 100, 0, -1);
		this->cells[14] = new Property("Gulberg II C", 2500, 600, 1200, 100, 0, -1);
		this->cells[15] = new Station("Railway Station", 2500, 350);
		this->cells[16] = new Property("DHA A", 2000, 500, 1000, 100, 0, -1);
		this->cells[17] = new CommunityChest("Community Chest");
		this->cells[18] = new Property("DHA B", 2000, 500, 1000, 100, 0, -1);
		this->cells[19] = new Property("DHA Y", 2000, 1000, 1500, 100, 0, -1);
		this->cells[20] = new FreeParking("Free Parking");
		this->cells[21] = new Property("Iqbal Town A", 250, 60, 150, 100, 0, -1);
		this->cells[22] = new Chance("Chance");
		this->cells[23] = new Property("Iqbal Town B", 300, 70, 150, 100, 0, -1);
		this->cells[24] = new Property("Iqbal Town C", 400, 100, 200, 100, 0, -1);
		this->cells[25] = new Station("Metro", 2000, 200);
		this->cells[26] = new Property("Faisal Town A", 300,100,150,100,0,-1);
		this->cells[27] = new Property("Faisal Town B", 400, 130, 200, 100, 0, -1);
		this->cells[28] = new Utility("WASA",4000,400);
		this->cells[29] = new Property("Faisal Town C", 400, 130, 200, 100, 0, -1);
		this->cells[30] = new GoToJail("Go to Jail");
		this->cells[31] = new Property("Johar Town A", 200, 80, 100, 100, 0, -1);
		this->cells[32] = new Property("Johar Town B", 250, 90, 100, 100, 0, -1);
		this->cells[33] = new CommunityChest("Community Chest");
		this->cells[34] = new Property("Model Town A", 800, 200, 400, 100, 0, -1);
		this->cells[35] = new Station("Bus Station", 2000,200);
		this->cells[36] = new Chance("Chance");
		this->cells[37] = new Property("Model Town B", 850, 250, 400, 100, 0, -1);
		this->cells[38] = new Tax("Property Tax", 200);
		this->cells[39] = new Property("Model Town C", 2000, 500, 800, 100, 0, -1);
		
	}

};

