#ifndef CIRCLE_H
#define CIRCLE_H

#include "shapeTwoD.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class circle:public shapeTwoD{
	private:
		int minOfX;
		int maxOfX;
		int minOfY;
		int maxOfY;
		double pi = 3.141;
		int rd;
		double ar = 0;
		coord ctr;
		int shapeNumeric;
	public:
		circle(string, bool);
		double computeArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		void setTheCoordOf(coord) override;		
		void setMinAndMax() override;
		double getArea() override;
		void setTheRadius(int) override;
		void setTheShape(int) override;
		int getTheShape() override;
		string toString() override;
};
#endif
