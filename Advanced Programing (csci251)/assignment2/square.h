#ifndef SQUARE_H
#define SQUARE_H

#include "shapeTwoD.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class square:public shapeTwoD{
	private:
		int minOfX;
		int minOfY;
		int maxOfX;
		int maxOfY;
		double l;
		double br;
		double ar = 0;
		vector<coord>vector_coord;
		int shapeNumeric;
	public:
		square(string, bool);
		double computeArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		double getArea();
		void setTheCoordOf(coord) override;
		void setMinAndMax() override;
		bool findTheCoordOf(int, int);
		string toString() override;
		void setTheShape(int) override;
		int getTheShape() override;
};
#endif
