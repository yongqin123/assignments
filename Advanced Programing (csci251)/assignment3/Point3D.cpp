#include "Point3D.h"

ostream& operator<<(ostream& os, const Point3D& point3d) {
	
	os << "[" << setw(4) << point3d.x << ", "
		<< setw(4) << point3d.y << ", " << setw(4) << point3d.z << "]"
		<< setw(3) << "" << fixed << setprecision(3) << point3d.distFrOrigin
		<< endl;
	return os;
}

bool operator==(const Point3D& point3d1, const Point3D& point3d2) {
	
	if (point3d1.x == point3d2.x && point3d1.y == point3d2.y && point3d1.z == point3d2.z)
		return true;
	return false;
}

bool operator<(const Point3D& point3d1, const Point3D& point3d2) {
	//check when 3rd option is X ordinate
	if (point3d1.sorting == "X ordinate") {
		if ((point3d1.x < point3d2.x) || (point3d1.x == point3d2.x && point3d1.y < point3d2.y) || (point3d1.x == point3d2.x && point3d1.y == point3d2.y && point3d1.z < point3d2.z))
			return true;
	}

	//check when 3rd option is Y ordinate
	else if (point3d1.sorting == "Y ordinate") {
		if ((point3d1.y < point3d2.y) || (point3d1.y == point3d2.y && point3d1.x < point3d2.x) || (point3d1.y == point3d2.y && point3d1.x == point3d2.x && point3d1.z < point3d2.z))
			return true;
	}

	//check when 3rd option is Z ordinate
	else if (point3d1.sorting == "Z ordinate") {
		if ((point3d1.z < point3d2.z) || (point3d1.z == point3d2.z && point3d1.x < point3d2.x) || (point3d1.z == point3d2.z && point3d1.x == point3d2.x && point3d1.y < point3d2.y))
			return true;
	}

	//check when 3rd option is distance
	else if (point3d1.sorting == "Dist. Fr Origin") {
		if (point3d1.distFrOrigin < point3d2.distFrOrigin)
			return true;
	}
	return false;
}

bool operator>(const Point3D& point3d1, const Point3D& point3d2) {
	//check when 3rd option is X ordinate
	if (point3d1.sorting == "X ordinate") {
		if ((point3d1.x > point3d2.x) || (point3d1.x == point3d2.x && point3d1.y > point3d2.y) || (point3d1.x == point3d2.x && point3d1.y == point3d2.y && point3d1.z > point3d2.z))
			return true;
	}

	//check when 3rd option is Y ordinate
	else if (point3d1.sorting == "Y ordinate") {
		if ((point3d1.y > point3d2.y) || (point3d1.y == point3d2.y && point3d1.x > point3d2.x) || (point3d1.y == point3d2.y && point3d1.x == point3d2.x && point3d1.z > point3d2.z))
			return true;
	}

	//check when 3rd option is Z ordinate
	else if (point3d1.sorting == "Z ordinate") {
		if ((point3d1.z > point3d2.z) || (point3d1.z == point3d2.z && point3d1.x > point3d2.x) || (point3d1.z == point3d2.z && point3d1.x == point3d2.x && point3d1.y > point3d2.y))
			return true;
	}

	//check when 3rd option is distance
	else if (point3d1.sorting == "Dist. Fr Origin") {
		if (point3d1.distFrOrigin > point3d2.distFrOrigin)
			return true;
	}
	return false;
}

//empty constructor
Point3D::Point3D() {
	setDistFrOrigin();
}

//constructor
Point3D::Point3D(int x, int y, int z) : Point2D(x,y) {
	this->z = z;
	setDistFrOrigin();
}


//getter z coord
int Point3D::getZ(){
	return z;
}

//setter z coord
void Point3D::setZ(int z){
	this-> z = z;
}


//set dist
void Point3D::setDistFrOrigin() {
	distFrOrigin = sqrt(pow(x,2) + pow(y,2) + pow(z,2));

}


