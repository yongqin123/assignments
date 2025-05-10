#include "circle.h"

circle::circle(string name, bool containsWarpSpace):shapeTwoD(name, containsWarpSpace){

}

double circle::getArea(){
	return ar;
}

void circle::setMinAndMax(){
	minOfX = ctr.x - rd;
	maxOfX = ctr.x + rd;
	minOfY = ctr.y - rd;
	maxOfY = ctr.y + rd;
}

void circle::setTheCoordOf(coord ct){
	ctr = ct;
}

void circle::setTheRadius(int r){
	rd = r;
}

double circle::computeArea(){
	ar = pow(rd,2) * pi;
	return pow(rd,2) * pi;
}

bool circle::isPointInShape(int x, int y){
	if((pow((x - ctr.x), 2) + pow((y - ctr.y), 2)) < pow(rd,2)){
		if((x == ctr.x) && (y == ctr.y))
			return false;
		else
			return true;
	}
	return false;
}

bool circle::isPointOnShape(int x, int y){
	if( (pow((y - ctr.y),2)  + pow((x- ctr.x), 2)) == pow(rd, 2)){
		return true;
	}
	return false;
}

void circle::setTheShape(int num){
	shapeNumeric = num;
}

int circle::getTheShape(){
	return shapeNumeric;
}

string circle::toString(){
	string cs;
	cs = "Shape[" + to_string(getTheShape()) + "]\n";
	cs += shapeTwoD::toString();
	
	cs += "Area: " + to_string((int) ar);
	cs += " units square\n";
	cs += "Vertices:\n";
	cs += "Point: (" + to_string(ctr.x) + ", ";
	cs += to_string(ctr.y) + ")\n";
	cs += "\n";
	cs += "Point on perimeter: ";
	for(int a = minOfX; a <= maxOfX;a++){
		for(int b = minOfY; b <= maxOfY; b++){
			if(isPointOnShape(a, b) == true)
				cs += "(" + to_string(a) + ", " + 
				cs += to_string(b) + "), ";
		}
	}
	cs += "\n";
	cs += "\n";
	cs += "Points within the shape: ";
	for(int a = minOfX; a <= maxOfX; a++){
		for (int b = minOfY; b <= maxOfY; b++){
			if(isPointInShape(a, b) == true){
				cs += "(" + to_string(a);
				cs += ", " + to_string(b)+ "), ";
			}
		}
	}
	if(rd == 1)
		cs += "none!";
	cs += "\n";
	
	return cs;
}
