#include "cross.h"
//constructor
cross::cross(string sname, bool containsWarpSpace):shapeTwoD(sname, containsWarpSpace){

}

//get area
double cross::getArea(){
	return area;
}

//find coord bool
bool cross::findTheCoordOf(int x, int y){
	for(unsigned int a = 0; a < cross_coordinate.size(); a++){
		if((x == cross_coordinate[a].x) && (y == cross_coordinate[a].y)){
			return true;
		}
	}
	return false;
}

//return coord struc with x value
coord cross::findTheCoordinateOfX(int value) {
	for(unsigned int a = 0; a < cross_coordinate.size();a++){
		if(cross_coordinate[a].x == value){
			return cross_coordinate[a];
		}
	}
	return coord();
}

//return coord struc with y value
coord cross::findTheCoordinateOfY(int value){
	for(unsigned int a = 0; a< cross_coordinate.size();a++){
		if(cross_coordinate[a].y == value){
			return cross_coordinate[a];
		}
	}
	return coord();
}


void cross::setTheCoordOf(coord c){
	cross_coordinate.push_back(c);
}

//obtain min and max
void cross::setMinAndMax(){
	int arr_x[12];
	int arr_y[12];
	
	for(int a = 0; a < 12; a++){
		arr_x[a] = cross_coordinate[a].x;
		arr_y[a] = cross_coordinate[a].y;
		
	}
	//setMinAndMax
	minOfX = *min_element(arr_x, arr_x + (sizeof(arr_x) / sizeof(arr_x[0])));
	maxOfX = *max_element(arr_x, arr_x + (sizeof(arr_x) / sizeof(arr_x[0])));
	minOfY = *min_element(arr_y, arr_y + (sizeof(arr_y) / sizeof(arr_y[0])));
	maxOfY = *max_element(arr_y, arr_y + (sizeof(arr_y) / sizeof(arr_y[0])));
	
	top_left = findTheCoordinateOfY(maxOfY);
	top_right = findTheCoordinateOfY(maxOfY);
	left_top = findTheCoordinateOfX(minOfX);
	left_bottom = findTheCoordinateOfX(minOfX);
	bottom_left = findTheCoordinateOfY(minOfY);
	bottom_right = findTheCoordinateOfY(minOfY);
	right_bottom = findTheCoordinateOfX(maxOfX);
	right_top = findTheCoordinateOfX(maxOfX);
	for(int a = 0; a < 12; a++){
		if((cross_coordinate[a].y == maxOfY) && (findTheCoordOf(cross_coordinate[a].x, cross_coordinate[a].y) == true) && (cross_coordinate[a].x < top_left.x))
			top_left = cross_coordinate[a];
		if((cross_coordinate[a].y == maxOfY) && (findTheCoordOf(cross_coordinate[a].x, cross_coordinate[a].y) == true) && (cross_coordinate[a].x > top_right.x))
			top_right = cross_coordinate[a];
		if((cross_coordinate[a].y == minOfY) && (findTheCoordOf(cross_coordinate[a].x, cross_coordinate[a].y) == true) && (cross_coordinate[a].x < bottom_left.x))
			bottom_left = cross_coordinate[a];
		if((cross_coordinate[a].y == minOfY) && (findTheCoordOf(cross_coordinate[a].x, cross_coordinate[a].y) == true) && (cross_coordinate[a].x > bottom_right.x))
			bottom_left = cross_coordinate[a];
		if((cross_coordinate[a].x == minOfX) && (findTheCoordOf(cross_coordinate[a].x, cross_coordinate[a].y) == true) && (cross_coordinate[a].y > left_top.y))
			left_top = cross_coordinate[a];
		if((cross_coordinate[a].x == minOfX) && (findTheCoordOf(cross_coordinate[a].x, cross_coordinate[a].y) == true) && (cross_coordinate[a].y < left_bottom.y))
			left_bottom = cross_coordinate[a];
		if((cross_coordinate[a].x == maxOfX) && (findTheCoordOf(cross_coordinate[a].x, cross_coordinate[a].y) == true) && (cross_coordinate[a].y > right_top.y))
			right_top = cross_coordinate[a];	
		if((cross_coordinate[a].x == maxOfX) && (findTheCoordOf(cross_coordinate[a].x, cross_coordinate[a].y) == true) && (cross_coordinate[a].y < right_bottom.y))
			right_bottom = cross_coordinate[a];
	}
}

//find area
double cross::computeArea(){
	
	
	area = ((maxOfY-minOfY)*(maxOfX-minOfX)) - ((top_left.y-left_top.y)*(top_left.x-left_top.x)) - ((top_right.y-right_top.y)*(right_top.x-top_right.x)) - ((right_bottom.y-bottom_right.y)*(right_bottom.x-bottom_right.x)) - ((left_bottom.y-bottom_left.y)*(bottom_left.x-left_bottom.x));
	
	return area;
}

bool cross::isPointInShape(int x, int y){
	bool abool;
	if((left_bottom.y < y && y < left_top.y) && (left_top.x < x && x < right_top.x))
			abool = true;
	else if((x < top_right.x && top_left.x < x)  && (y < top_left.y  && bottom_left.y < y))
			abool = true;
	else
		abool = false;
	return abool;
}

bool cross::isPointOnShape(int x, int y){
	bool abool = false;
	int b;
	for(int a = 0; a < 12; a++){
		b = a + 1;
		if(a == 11)
			b = 0;
		if(x==cross_coordinate[a].x){
			if(y > cross_coordinate[b].y &&  cross_coordinate[a].y > y)
				abool = true;
			else if(cross_coordinate[a].y < y && y < cross_coordinate[b].y)
				abool = true;
		}
		if(cross_coordinate[a].y == y){
			if(cross_coordinate[a].x > x && x > cross_coordinate[b].x)
				abool = true;
			else if(cross_coordinate[a].x < x && x < cross_coordinate[b].x)
				abool = true;
		}
	}
	return abool;
}

void cross::setTheShape(int num){
	shapeNumeric = num;
}

int cross::getTheShape(){
	return shapeNumeric;
}

//print coord of points and results
string cross::toString(){
	string s;
	s = "Shape["+ to_string(getTheShape()) + "]\n";
	s += shapeTwoD::toString();

	s += "Area: " + to_string( (int) area) + " units square\nVertices:\n";
	
	for(int a = 0; a < cross_coordinate.size(); a++) {
		s += "Points [";
		s += to_string(a) + "] : (";
		s += to_string(cross_coordinate[a].x) + ", ";
		s += to_string(cross_coordinate[a].y) + ")\n";
	}
	s += "\n";
	s += "Point on perimeter: ";
	for(int a = minOfX; a <= maxOfX; a++){
		for (int b = minOfY; b <= maxOfY; b++){
			if(isPointOnShape(a, b) == true && findTheCoordOf(a, b) == false)
				s += "(";
				s += to_string(a) + ", ";
				s += to_string(b) + "), ";
		}
	}
	
	if(((top_left.x - left_top.x) == 1) && ((top_right.x - top_left.x) == 1) && ((right_top.x - top_right.x) == 1) && ((top_left.y - left_top.y) == 1) && ((left_top.y - left_bottom.y) == 1) && ((left_bottom.y - bottom_left.y) == 1))
		s += "none!";
	s += "\n";
	s += "\n";
	s += "Point within shape: ";
	
	for(int a = minOfX; a <= maxOfX; a++){
		for(int b = minOfY; b <= maxOfY; b++){
			if (isPointInShape(a, b) )
				s += "(" + to_string(a);
				s += ", " + to_string(b) + "), ";
		}
	}
	
	if(((top_left.x - left_top.x) == 1) && ((top_right.x - top_left.x) == 1) && ((right_top.x - top_right.x) == 1) && ((top_left.y - left_top.y) == 1) && ((left_top.y - left_bottom.y) == 1) && ((left_bottom.y - bottom_left.y) == 1))
		s += "none!";
	
	s += "\n";
	return s;
}
