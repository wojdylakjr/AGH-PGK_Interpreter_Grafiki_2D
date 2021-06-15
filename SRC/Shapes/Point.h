#pragma once
/**
 * @file
 * Class to represent point
 */
#include <cmath>
class Point {
public:
	/**
	*default constructor
	 */
	Point() = default;

	/**
	*constructor to set coordinate x and y
	 */
	Point(double x, double y);

	/**
	*setter to x coordinate
	 */
	void setX(double x);

	/**
	*setter to y coordinate
	 */
	void setY(double y);

	/**
	*getter to x coordinate
	 */
	double getX() const;

	/**
	*getter to y coordinate
	 */
	double getY() const;

	/**
	*method to change coordinates after point rotate
	 */
	void rotatePoint(double alfa);

	/**
	*method to change coordinates after point move
	 */
	void transformPoint(double dx, double dy);

	/**
	*method to change coordinates after point scale
	 */
	void scalePoint(double dx, double dy);

private:
	/** x coordinate*/
	double m_x;

	/**y coordiante */
	double m_y;

};