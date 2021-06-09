#pragma once
#include"Shape.h"
#include"Point.h"
#include <vector>


class ShapeRectangle : public Shape
{
public:
	ShapeRectangle(double x1, double y1, double x2, double y2, wxColor _color);
	void draw(wxBufferedDC* dc, double w, double h, Panel panel) override;

	std::string getTypeName() override;
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
	Point m_leftDownPoint;
	Point m_rightUpPoint;
	
};
