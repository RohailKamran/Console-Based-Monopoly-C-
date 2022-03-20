#include "FreeParking.h"
#include <string>

FreeParking::FreeParking() {

	index = nextIndex;
	nextIndex++;
}

FreeParking::FreeParking(string name) {
	this->name = name;
	index = nextIndex;
	nextIndex++;
}



