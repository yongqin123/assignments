#ifndef MYTEMPLATES_H
#define MYTEMPLATES_H

#include <math.h>

//getting the length value of x and y
//minus them
template <class T>
double scalar_difference(T x, T y) {
	return fabs(x.getScalarValue() - y.getScalarValue());
}

//equals
template <class T>
bool equals(T x, T y) {
	if (x == y)
		return true;
	return false;
}

//descending
template <typename T>
bool DSC(const T& t1, const T& t2) {
	return t1 > t2;
}

//ascending
template <typename T>
bool ASC(const T& t1, const T& t2) {
	return t1 < t2;
}


#endif