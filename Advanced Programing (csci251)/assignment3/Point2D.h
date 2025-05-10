#ifndef POINT2D_H
#define POINT2D_H
#include<string>
#include<iostream>
#include<math.h>
#include<iomanip>

using namespace std;

/*struct for future use
struct coord{
	int x;
	int y;
};
*/



class Point2D {
	//overloading operators
	friend ostream& operator<<(ostream&, const Point2D&);
	friend bool operator==(const Point2D&, const Point2D&);
	friend bool operator<(const Point2D&, const Point2D&);
	friend bool operator>(const Point2D&, const Point2D&);

	
	public:
		//variables, sorting is set inside int main
		string sorting;

		//constructor
		Point2D();
		Point2D(int, int);

		//getter
		int getX();
		int getY();
		virtual void setDistFrOrigin();

		double getScalarValue();

		//setter
		void setX(int);
		void setY(int);
		
		//variable
		int x;
		int y;
		double distFrOrigin;

};
#endif
