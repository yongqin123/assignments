#ifndef LINE3D_H
#define LINE3D_H

#include "Point3D.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include "Line2D.h"

using namespace std;

/*struct for future use
struct coord{
	int x;
	int y;
};
*/

class Line3D {
	//overloaded operators
	friend ostream& operator<<(ostream& os, const Line3D&);
	friend bool operator<(const Line3D&, const Line3D&);
	friend bool operator==(const Line3D&, const Line3D&);
	friend bool operator>(const Line3D&, const Line3D&);
	private:
		//variable
		Point3D pt1;
		Point3D pt2;
		double length;

	public:
		//constructor
		Line3D(Point3D, Point3D);

		Point3D getPt1() const;
		Point3D getPt2() const;

		void setLength();
		double getScalarValue() const;

		//setter
		void setPt1(Point3D);
		void setPt2(Point3D);
		
		//for sorting
		string sorting;
};
#endif
