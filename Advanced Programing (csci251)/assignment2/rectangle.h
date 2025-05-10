#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shapeTwoD.h"

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class rectangle : public shapeTwoD{
	private:
		int minOfX;
		int minOfY;
		int maxOfX;
		int maxOfY;
		double l;
		double br;
		double ar = 0;
		vector<coord> vector_coord;
		int shapeNumeric;
	public:
		rectangle(string, bool);
		double computeArea() override;
		bool isPointInShape(int, int) override;
		bool isPointOnShape(int, int) override;
		double getArea();
		string toString() override;

		//self created
		void setTheCoordOf(coord) override;
		//self created
		void setMinAndMax() override;
		//self created
		bool findTheCoordOf(int, int);
		//self created
		void setTheShape(int) override;
		//self created
		int getTheShape() override;
};
#endif
