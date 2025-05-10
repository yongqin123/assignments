#ifndef SHAPETWOD_H
#define SHAPETWOD_H

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct coord{
	int x;
	int y;
};



class shapeTwoD {
	protected:
		//instance class variables
		string name;
		bool containsWarpSpace;
	

	public:
		//constructor
		shapeTwoD(string , bool );
		
		//getter and setters
		string getName();
		bool getContainsWarpSpace();
		void setName(string );
		void setContainsWarpSpace(bool );
		
		//virtual overide
		virtual double computeArea() {return 4.0;};
		virtual bool isPointInShape(int , int ) {return false;};
		virtual bool isPointOnShape(int , int ) {return false;};
		virtual int getTheShape(){return 1.0;};
		virtual void setTheCoordOf(coord){};
		virtual double getArea(){return 1.0;};
		virtual void setTheShape(int){};
		virtual void setTheRadius(int) {};
		virtual string toString();
		virtual void setMinAndMax(){};
		
};
#endif