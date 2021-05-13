#include"Point.h"

Point::Point(){}

Point::Point(double x, double y) : _x(x), _y(y) {

}

void Point::setX(double x) {
	_x = x;
}

void Point::setY(double y) {
	_y = y;
}

double Point::getX() const {
	return _x;
}

double Point::getY() const {
	return _y;
}

void Point::rotatePoint(double alfa) {
	double tempX = _x;
	double tempY = _y;

	_x = tempX * cos(alfa) - tempY * sin(alfa);
	_y = tempY * cos(alfa) + tempX * sin(alfa);
}

void Point::transformPoint(double dx, double dy) {
	_x += dx;;
	_y += dy;
}

void Point::scalePoint(double dx, double dy) {
	_x *= dx;
	_y *= dy;
}