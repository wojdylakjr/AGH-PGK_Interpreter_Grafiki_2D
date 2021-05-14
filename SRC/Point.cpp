#include"Point.h"

Point::Point(double x, double y) : m_x(x), m_y(y) {}

void Point::setX(double x) {
	m_x = x;
}

void Point::setY(double y) {
	m_y = y;
}

double Point::getX() const {
	return m_x;
}

double Point::getY() const {
	return m_y;
}

void Point::rotatePoint(double alfa) {
	double tempX = m_x;
	double tempY = m_y;

	m_x = tempX * cos(alfa) - tempY * sin(alfa);
	m_y = tempY * cos(alfa) + tempX * sin(alfa);
}

void Point::transformPoint(double dx, double dy) {
	m_x += dx;;
	m_y += dy;
}

void Point::scalePoint(double dx, double dy) {
	m_x *= dx;
	m_y *= dy;
}

