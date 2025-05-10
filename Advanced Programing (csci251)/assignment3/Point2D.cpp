#include "Point2D.h"

//overload operator << changes the printing of the object
ostream& operator<<(ostream& os, const Point2D& point2d) {
	
	os << "[" << setw(4) << point2d.x << ", " << setw(4) << point2d.y << "]"
		<< setw(3) << "" << fixed << setprecision(3) << point2d.distFrOrigin
		<< endl;
	return os;
}

bool operator==(const Point2D& point2d1, const Point2D& point2d2) {
	
	if (point2d1.x == point2d2.x && point2d1.y == point2d2.y) {
		return true;
	}
	else {
		return false;
	}
}

bool operator<(const Point2D& point2d1, const Point2D& point2d2) {
	
	if (point2d1.sorting == "X ordinate") {
		if ((point2d1.x < point2d2.x) || (point2d1.x == point2d2.x && point2d1.y < point2d2.y))
			return true;
	}
	else if (point2d1.sorting == "Y ordinate") {
		if ((point2d1.y < point2d2.y) || (point2d1.y == point2d2.y && point2d1.x < point2d2.x))
			return true;
	}
	
	else if (point2d1.sorting == "Dist. Fr Origin") {
		if (point2d1.distFrOrigin < point2d2.distFrOrigin)
			return true;
	}
	
	return false;
}

bool
	if (point2d1.sorting == "X ordinate") {
		if ((point2d1.x > point2d2.x) || (point2d1.x == point2d2.x && point2d1.y > point2d2.y))
			return true;
	}
	else if (point2d1.sorting == "Y ordinate") {
		if ((point2d1.y > point2d2.y) || (point2d1.y == point2d2.y && point2d1.x > point2d2.x))
			return true;
	}
	
	else if (point2d1.sorting == "Dist. Fr Origin") {
		if (point2d1.distFrOrigin > point2d2.distFrOrigin)
			return true;
	}
	
	return false;
}




Point2D::Point2D() {

}


Point2D::Point2D(int x, int y){
	this-> x = x;
	this-> y = y;
	setDistFrOrigin();
}

int Point2D::getX(){
	return x;
}

int Point2D::getY() {
	return y;
}

double Point2D::getScalarValue() {
	return distFrOrigin;
}

void Point2D::setX(int x){
	this-> x = x;
}

void Point2D::setY(int y){
	this-> y = y;
}

void Point2D::setDistFrOrigin() {
	distFrOrigin = sqrt(pow(x, 2) + pow(y, 2));
}


