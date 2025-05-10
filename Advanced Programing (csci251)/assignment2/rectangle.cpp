#include "rectangle.h"

//
rectangle::rectangle(string name, bool containsWarpSpace) : shapeTwoD(name, containsWarpSpace){

}

double rectangle::computeArea() {
	l = maxOfX - minOfX;
	br = maxOfY - minOfY;
	ar = l * br;
	return ar;
}

bool rectangle::isPointInShape( int x , int y ){
	if( (x >  minOfX  ) && ( x < maxOfX) && ( minOfY < y) && ( y < maxOfY ) ) {
		return true;
	}
	else {
		return false;
	}
}	

bool rectangle::isPointOnShape( int x , int y ){
	if( ( (x >= minOfX  ) && ( x <= maxOfX ) ) && ((y == minOfY) || (y ==maxOfY ))){
		return true;
	}
	else if(((x == maxOfX) || (x == minOfX) ) && ((y >= minOfY) && (y <= maxOfY))){
		return true;
	}
	else
		return false;
}

double rectangle::getArea(){
	return ar;
}

void rectangle::setTheCoordOf(coord b){
	vector_coord.push_back(b);
}

void rectangle::setMinAndMax(){
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

bool rectangle::findTheCoordOf(int x, int y){
	for (unsigned int a=0;a < vector_coord.size();a++) {
		if( (y== vector_coord[a].y)&&(x == vector_coord[a].x)){
			return true;
		}
	}
	return false;
}

void rectangle::setTheShape(int k){
	shapeNumeric = k;
}

int rectangle::getTheShape(){
	return shapeNumeric;
}

string rectangle::toString(){
	string s;
	s = "Shape[" + to_string(getTheShape()) + "]\n";
	s += shapeTwoD::toString();
	
	s += "Area: " + to_string((int)ar) + " units squares\nVertices: \n";
	
	//these are the vertices
	for(unsigned int a = 0; a < vector_coord.size(); a++){
		s += "Point [" + to_string(a) + "] : (" + to_string(vector_coord[a].x) + ", " + to_string(vector_coord[a].y) + ")\n";
	}
	s += "\n";
	//vertices of perimeter
	s += "Point on perimeter: ";
	for(int a = minOfX; a <= maxOfX; a++){
		for(int b = minOfY; b <= maxOfY; b++){
			if(isPointOnShape(a, b) == true && findTheCoordOf(a, b) == false){
				s += "(" + to_string(a) + ", " + to_string(b) + "), ";
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
				s += "(" + to_string(a) + ", " + to_string(b) + "), ";
			}
		}
	}
	if(((maxOfY - minOfY) == 1) || ((maxOfX - minOfX) == 1)  )
		s += "none!";
	s += "\n";
	return s;
}
