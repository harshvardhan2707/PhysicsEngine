#include <cmath>
#include "PVector.h"

PVector::PVector() {
	x = 0.0; y = 0.0;
}
PVector::PVector(double x, double y) {
	this->x = x;
	this->y = y;
}
PVector PVector:: operator+(PVector& other) {
	return PVector(x + other.x, y + other.y);
}
PVector PVector:: operator-(PVector& other) {
	return PVector(x -other.x, y -other.y);
}
PVector PVector:: operator*(double f) {
	return PVector(x * f, y * f);
}
PVector PVector:: operator/(double f) {
	return PVector(x / f, y / f);
}
double PVector::mag() {
	return std::sqrt(x * x + y * y);
}
PVector PVector::normalize() {
	double Mag = mag();
	return PVector(x / Mag, y / Mag);
}

