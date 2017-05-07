#pragma once
#include <iostream>
#include <string>


class shape {
public:
	shape() = default;
	shape(double x, double y) : xSize(x), ySize(y) {}
protected:
	double xSize = 0.0, ySize = 0.0;
};

class shape_2d : public shape{
public:
	shape_2d() = default;
	shape_2d(double x, double y) : shape(x, y){}
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
};

class shape_3d : public shape {
public:
	shape_3d() = default;
	shape_3d(double x, double y, double z) : shape(x, y), zSize(z){}
	virtual double cubage() const = 0;
protected:
	double zSize = 0.0;
};

class Rectangle : public shape_2d {
public:
	Rectangle() = default;
	Rectangle(double x, double y) : shape_2d(x, y){}
	virtual double area() const override { return 2 * (xSize + ySize); }
	virtual double perimeter() const override { return xSize * ySize; }
};




