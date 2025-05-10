#include "Point3D.h"
#include "Line3D.h"
#include "Line2D.h"

ostream& operator<<(ostream& os, const Line3D& line3d) {
	
	Point3D point3d1 = line3d.getPt1();
	Point3D point3d2 = line3d.getPt2();

	os << "[" << setw(4) << point3d1.getX()
		<< "," << setw(5) << point3d1.getY()
		<< "," << setw(5) << point3d1.getZ()
		<< "]" << setw(3) << ""
		<< "[" << setw(4) << point3d2.getX()
		<< "," << setw(5) << point3d2.getY()
		<< "," << setw(5) << point3d2.getZ()
		<< "]" << setw(3) << ""
		<< fixed << setprecision(3) << line3d.getScalarValue()
		<< endl;
	return os;
}

bool operator<(const Line3D& line3d1, const Line3D& line3d2) {
	
	if (line3d1.sorting == "Pt. 1's (x, y) records") {
		if ((line3d1.getPt1().getX() < line3d2.getPt1().getX()) ||
			(line3d1.getPt1().getX() == line3d2.getPt1().getX() &&
				line3d1.getPt1().getY() < line3d2.getPt1().getY()) ||
				(line3d1.getPt1().getX() == line3d2.getPt1().getX() &&
					line3d1.getPt1().getY() == line3d2.getPt1().getY() &&
					line3d1.getPt1().getZ() < line3d1.getPt1().getZ()))
			return true;
	}
	else if (line3d1.sorting == "Pt. 2's (x, y) records") {
		if ((line3d1.getPt2().getX() < line3d2.getPt2().getX()) ||
			(line3d1.getPt2().getX() == line3d2.getPt2().getX() &&
				line3d1.getPt2().getY() < line3d2.getPt2().getY()) ||
				(line3d1.getPt2().getX() == line3d2.getPt2().getX() &&
					line3d1.getPt2().getY() == line3d2.getPt2().getY() &&
					line3d1.getPt2().getZ() < line3d1.getPt2().getZ()))
			return true;
	}
	else if (line3d1.sorting == "Length")
		return line3d1.getScalarValue() < line3d2.getScalarValue();
	return false;
}

bool operator==(const Line3D& line3d1, const Line3D& line3d2) {
	if ((line3d1.getPt1() == line3d2.getPt1() && line3d1.getPt2() == line3d2.getPt2()) ||
		(line3d1.getPt1() == line3d2.getPt2() && line3d1.getPt2() == line3d2.getPt1()) ||
		(line3d1.getPt1() == line3d1.getPt2()) || (line3d2.getPt1() == line3d2.getPt2()))
		return true;
	return false;
}

bool operator>(const Line3D& line3d1, const Line3D& line3d2) {
	
	if (line3d1.sorting == "Pt. 1's (x, y) records") {
		if ((line3d1.getPt1().getX() > line3d2.getPt1().getX()) ||
			(line3d1.getPt1().getX() == line3d2.getPt1().getX() &&
				line3d1.getPt1().getY() > line3d2.getPt1().getY()) ||
				(line3d1.getPt1().getX() == line3d2.getPt1().getX() &&
					line3d1.getPt1().getY() == line3d2.getPt1().getY() &&
					line3d1.getPt1().getZ() > line3d1.getPt1().getZ()))
			return true;
	}
	else if (line3d1.sorting == "Pt. 2") {
		if ((line3d1.getPt2().getX() > line3d2.getPt2().getX()) ||
			(line3d1.getPt2().getX() == line3d2.getPt2().getX() &&
				line3d1.getPt2().getY() > line3d2.getPt2().getY()) ||
				(line3d1.getPt2().getX() == line3d2.getPt2().getX() &&
					line3d1.getPt2().getY() == line3d2.getPt2().getY() &&
					line3d1.getPt2().getZ() > line3d1.getPt2().getZ()))
			return true;
	}
	else if (line3d1.sorting == "Length")
		return line3d1.getScalarValue() > line3d2.getScalarValue();
	return false;
}


Line3D::Line3D(Point3D pt1, Point3D pt2) {
	this-> pt1 = pt1;
	this->pt2 = pt2;
	setLength();
}

Point3D Line3D::getPt1() const{
	return pt1;
}

Point3D Line3D::getPt2() const{
	return pt2;
}

void Line3D::setPt1(Point3D pt1){
	this-> pt1 = pt1;
}

void Line3D::setPt2(Point3D pt2) {
	this->pt2 = pt2;
}

void Line3D::setLength() {
	length = sqrt(pow(pt1.getX() - pt2.getX(), 2) + pow(pt1.getY() - pt2.getY(), 2) + pow(pt1.getZ() - pt2.getZ(), 2));
}

double Line3D::getScalarValue() const{
	return length;
}