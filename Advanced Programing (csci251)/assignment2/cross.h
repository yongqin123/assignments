#ifndef CROSS_H
#define CROSS_H

#include "shapeTwoD.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class cross : public shapeTwoD{
	private:
		coord top_left;
		coord left_top;
		coord left_bottom;
		int minOfX;
		int minOfY;
		int maxOfX;
		int maxOfY;
		double area = 2.0;
		
		coord bottom_left;
		coord top_right;
		coord right_top;
		coord right_bottom;
		coord bottom_right;
		vector<coord>cross_coordinate; //cC
		int shapeNumeric;
	public:
		cross(string, bool);
		
		coord findTheCoordinateOfX(int); //findCoordX()
		
		coord findTheCoordinateOfY(int); //findCoordY()

		double computeArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		void setTheCoordOf(coord) override;	
		void setMinAndMax() override;
		
		double getArea();
		bool findTheCoordOf(int, int);
		
		void setTheShape(int) override;
		int getTheShape() override;
		string toString() override;
};
#endif
