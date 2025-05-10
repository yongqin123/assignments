#ifndef POINT3D_H
#define POINT3D_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

#include "Point2D.h"

using namespace std;

/*struct for future use
struct coord{
	int x;
	int y;
};
*/

class Point3D : public Point2D {
	//overloaded operators
	friend ostream& operator<<(ostream&, const Point3D&);
	friend bool operator==(const Point3D&, const Point3D&);
	friend bool operator<(const Point3D&, const Point3D&);
	friend bool operator>(const Point3D&, const Point3D&);
	
		

	public:
		//constructor
		Point3D();
		Point3D(int, int, int);

		int getZ();
		void setDistFrOrigin() override;
		

		//setter
		void setZ(int);
		
		//variable
		string sorting;

		//variable
		int z;
};
#endif
