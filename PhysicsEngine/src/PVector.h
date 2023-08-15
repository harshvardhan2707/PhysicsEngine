#pragma once
class PVector {
public:
	double x, y;
	PVector();
	PVector(double x, double y);
	PVector operator+(PVector& other);
	PVector operator-(PVector& other);
	PVector operator*(double f);
	PVector operator/(double f);
	double mag();
	PVector normalize();
};