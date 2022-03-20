#pragma once
#include "Cell.h"
//#include "Section.h"
class Board//Abstract
{
protected:
	class Cell* cells[40];
	class Section* sections;

public: 
		Cell* GetCellAtPosition(int index){
		return cells[index];
	}

public:
	virtual void SetBoard() = 0;
};

