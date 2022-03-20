#include "JustVisiting.h"
#include<string>

JustVisiting::JustVisiting() {
	index = nextIndex;
	nextIndex++;
}

JustVisiting::JustVisiting(string name) {
	this->name = name;
	index = nextIndex;
	nextIndex++;
}