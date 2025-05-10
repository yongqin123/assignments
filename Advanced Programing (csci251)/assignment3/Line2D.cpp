#include "Line2D.h"
#include "Point2D.h"

ostream& operator<<(ostream& os, const Line2D& line2d) {
	
	Point2D point2d1 = line2d.getPt1();
	Point2D point2d2 = line2d.getPt2();

	os << "[" << setw(4) << point2d1.getX() << ", "
		<< setw(4) << point2d1.getY() << "]"
		<< setw(3) << ""
		<< "[" << setw(4) << point2d2.getX() << ", "
		<< setw(4) << point2d2.getY() << "]"
		<< setw(3) << ""
		<< fixed << setprecision(3) << line2d.getScalarValue()
		<< endl;
	return os;
}

bool operator<(const Line2D& line2d1, const Line2D& line2d2) {
	
	if (line2d1.sorting == "Pt. 1's (x, y) records") {
		if ((line2d1.getPt1().getX() < line2d2.getPt1().getX()) ||
			(line2d1.getPt1().getX() == line2d2.getPt1().getX() &&
				line2d1.getPt1().getY() < line2d2.getPt1().getY()))
			return true;
	}
	else if (line2d1.sorting == "Pt. 2's (x, y) records") {
		if ((line2d1.getPt2().getX() < line2d2.getPt2().getX()) ||
			(line2d1.getPt2().getX() == line2d2.getPt2().getX() &&
				line2d1.getPt2().getY() < line2d2.getPt2().getY()))
			return true;
	}
	else if (line2d1.sorting == "Length") {
		if (line2d1.getScalarValue() < line2d2.getScalarValue())
			return true;
	}
	return false;
}

bool operator==(const Line2D& line2D1, const Line2D& line2D2) {
	if ((line2D1.getPt1() == line2D2.getPt1() && line2D1.getPt2() == line2D2.getPt2()) ||
		(line2D1.getPt1() == line2D2.getPt2() && line2D1.getPt2() == line2D2.getPt1()) ||
		(line2D1.getPt1() == line2D1.getPt2()) || (line2D2.getPt1() == line2D2.getPt2()))
		return true;
	return false;
}

bool operator>(const Line2D& line2D1, const Line2D& line2D2) {
	
	if (line2D1.sorting == "Pt. 1's (x, y) records") {
		if ((line2D1.getPt1().getX() > line2D2.getPt1().getX()) ||
			(line2D1.getPt1().getX() == line2D2.getPt1().getX() &&
				line2D1.getPt1().getY() > line2D2.getPt1().getY()))
			return true;
	}
	else if (line2D1.sorting == "Pt. 2's (x, y) records") {
		if ((line2D1.getPt2().getX() > line2D2.getPt2().getX()) ||
			(line2D1.getPt2().getX() == line2D2.getPt2().getX() &&
				line2D1.getPt2().getY() > line2D2.getPt2().getY()))
			return true;
	}
	else if (line2D1.sorting == "Length") {
		if (line2D1.getScalarValue() > line2D2.getScalarValue())
			return true;
	}
	return false;
}

Line2D::Line2D(Point2D pt1, Point2D pt2) {
	this-> pt1 = pt1;
	this-> pt2 = pt2;
	setLength();
}

Point2D Line2D::getPt1() const{
	return pt1;
}

Point2D Line2D::getPt2() const{
	return pt2;
}

void Line2D::setLength() {
	length = sqrt(pow(pt1.getX() - pt2.getX(), 2) + pow(pt1.getY() - pt2.getY(), 2));
}


double Line2D::getScalarValue() const{
	return length;
}

void Line2D::setPt1(Point2D pt1){
	this-> pt1 = pt1;
}

void Line2D::setPt2(Point2D pt2){
	this-> pt2 = pt2;
}



