#pragma once
#include<cmath>
class Point {
public:
	Point();
	Point(double x, double y);
	void setX(double x);
	void setY(double y);
	double getX() const;
	double getY() const;

	//obrot danego punktu
	void rotatePoint(double alfa);

	//przesuniecie punktu
	void transformPoint(double dx, double dy);

	//przeskalowanie punktu
	void scalePoint(double dx, double dy);

private:
	double _x;
	double _y;

};