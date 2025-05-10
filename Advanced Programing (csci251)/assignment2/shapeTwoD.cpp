#include "shapeTwoD.h"

//constructor
shapeTwoD::shapeTwoD(string name, bool containsWarpSpace){
	this-> name = name;
	this-> containsWarpSpace = containsWarpSpace;
}

//get name
string shapeTwoD::getName(){
	return name;
}

bool shapeTwoD::getContainsWarpSpace(){
	return containsWarpSpace;
}

void shapeTwoD::setName(string name){
	this->name = name;
}

void shapeTwoD::setContainsWarpSpace(bool containsWarpSpace) {
	this->containsWarpSpace = containsWarpSpace;
}

//print whether theres warpspace or not
string shapeTwoD::toString() {
	string k;
	if (containsWarpSpace) {
		return "Name: " + name + "\nSpecial Type: " + "WS" + '\n';
	}

	else {
		return "Name: " + name + "\nSpecial Type: " + "NS" + '\n';
	}

}