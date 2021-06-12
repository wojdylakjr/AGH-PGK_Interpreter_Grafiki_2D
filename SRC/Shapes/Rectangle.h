#pragma once
#include"Shape.h"
#include"Point.h"
#include <vector>


class ShapeRectangle : public Shape
{
public:
	/**
	 * constructor setting coordinates of left down point and right up point and color of rectangle
	 * @param x and y coordinates of left down and righ up point of rectangle and (hexadecimal) color
	 */
	ShapeRectangle(double x1, double y1, double x2, double y2, wxColor _color);

	/**
	 * rectangle drawing method
	 * @param bufferedDc and actual width and heigth of out panel
	 */
	void draw(wxBufferedDC* dc, double w, double h, Panel panel) override;

	/**
	 * returns name of the shape
	 * @return rectangle
	 */
	std::string getTypeName() override;
	/**
	 * returns shape parameters as string 
	 * @return std::string coordinates ofleft down and right up points in rectangle
	 */
	std::string getParameters() override;

	/**
	 * returns bottom left Point if start, top right Point otherwise
	 * @param bool
	 * @return Point
	 */
	Point getPoint(bool bottomLeft);

	/**
	 * sets Point with given arguments
	 * if bottom left sets bottom left Point, top right Point otherwise
	 * @param double
	 * @param double
	 * @param bool
	 */
	void setPoint(double x, double y, bool bottomLeft);

private:
	/** our start points of rectangle */
	Point m_leftDownPoint;
	Point m_rightUpPoint;
	
};
