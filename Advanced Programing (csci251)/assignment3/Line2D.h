#ifndef LINE2D_H
#define LINE2D_H
#include "Point2D.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

/*struct for future use
struct coord{
	int x;
	int y;
};
*/

class Line2D {
	//overloaded operator
	friend ostream& operator<<(ostream&, const Line2D&);
	friend bool operator<(const Line2D&, const Line2D&);
	friend bool operator==(const Line2D&, const Line2D&);
	friend bool operator>(const Line2D&, const Line2D&);

	protected:
		//variable
		Point2D pt1;
		Point2D pt2;
		double length;

	public:
		//constructor
		Line2D(Point2D, Point2D);

		//getter
		Point2D getPt1() const;
		Point2D getPt2() const;
		double getScalarValue() const;

		//setter
		void setPt1(Point2D);
		void setPt2(Point2D);
		
		void setLength();

		//variable
		string sorting;
};
#endif
