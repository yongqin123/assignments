#include "square.h"

//constructor
square::square(string name, bool containsWarpSpace) : shapeTwoD(name, containsWarpSpace){

}

//calculate area
double square::computeArea(){
	//breadth
	br = maxOfY - minOfY;

	//length
	l = maxOfX - minOfX;
	
	//area = length x breadth
	ar = l * br;
	return ar;
}

bool square::isPointInShape(int x, int y){
	if ( (x > minOfX) && (x < maxOfX) && (y > minOfY) && (y < maxOfY)){
		return true;
	}
	else {
		return false;
	}
}	

bool square::isPointOnShape(int x, int y){
	if(((x >= minOfX) && (x <= maxOfX)) && ((y == maxOfY)||(y==minOfY) )){
		return true;
	}
	else if(((x==minOfX) || (x == maxOfX)) && ((minOfY <= y) && (y <= maxOfY))){
		return true;
	}
	else
		return false;
}

//return area
double square::getArea(){
	return ar;
}

//set coord with struc coordinate
void square::setTheCoordOf(coord b){
	vector_coord.push_back(b);
}

//set min and max x and y 
void square::setMinAndMax(){
	int arr_x[4];
	int arr_y[4];
	
	for(int a = 0; a < 4; a++){
		arr_x[a] = vector_coord[a].x;
		arr_y[a] = vector_coord[a].y;
		
	}
	minOfX = *min_element(arr_x, arr_x + (sizeof(arr_x) / sizeof(arr_x[0])));
	maxOfX = *max_element(arr_x, arr_x + (sizeof(arr_x) / sizeof(arr_x[0])));
	minOfY = *min_element(arr_y, arr_y + (sizeof(arr_y) / sizeof(arr_y[0])));
	maxOfY = *max_element(arr_y, arr_y + (sizeof(arr_y) / sizeof(arr_y[0])));
}

//find x and y coord boolean
bool square::findTheCoordOf(int x, int y){
	for(unsigned int a=0; a < vector_coord.size(); a++){
		if((vector_coord[a].x == x) && (vector_coord[a].y == y)){
			return true;
		}
	}
	return false;
}

void square::setTheShape(int n){
	shapeNumeric = n;
}

int square::getTheShape(){
	return shapeNumeric;
}

//print coordinates 
string square::toString(){
	string s; //shape
	s = "Shape[" + to_string(getTheShape()) + "]\n";
	s += shapeTwoD::toString();
	
	s += "Area: " + to_string((int)ar);
	s += " units square\n";
	s += "Vertices:\n";
	
	//vertices of the marked points
	for(unsigned int a = 0; a < vector_coord.size(); a++){
		s += "Point [" + to_string(a) + "] : (";
		s += to_string(vector_coord[a].x) + ", ";
		s += to_string(vector_coord[a].y) + ")\n";
	}
	
	s  =  s + "\n";
	
	//vertices of perimeter
	s  = s + "Point on perimeter: ";
	for(int a = minOfX; a <= maxOfX; a++){
		for(int b = minOfY; b <= maxOfY; b++){
			if(isPointOnShape(a, b) == true && findTheCoordOf(a, b) == false){
				s += "(" + to_string(a) + ", ";
				s += to_string(b) + "), ";
			}
		}
	}
	if(((maxOfX - minOfX) == 1) && ((maxOfY - minOfY) == 1))
		s += "none!";
	s += "\n";
	s += "\n";
	//vertices within perimeter and marked points
	s += "Point within shape: ";
	for (int a = minOfX; a <= maxOfX; a++){
		for (int b = minOfY; b <= maxOfY; b++){
			if (isPointInShape(a,b) == true){
				s += "(" + to_string(a) + ", ";
				s += to_string(b) + "), ";
			}
		}
	}
	if(((maxOfX - minOfX) == 1) || ((maxOfY - minOfY) == 1))
		s += "none!";
	s += "\n";
	return s;
}
