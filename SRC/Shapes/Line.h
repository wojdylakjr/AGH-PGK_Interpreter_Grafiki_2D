#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>

class ShapeLine : public Shape
{
public:
	/**
	 * constructor sets coordinates of start point, end point and color line
	 * @param x and y coordinates of start and end point of line and (hexadecimal) color
	 */
	ShapeLine(double x1, double y1, double x2, double y2, wxColor _color);
	/**
	 * line drawing method
	 * @param bufferedDc and actual width and heigth of out panel
	 */
	void draw(wxBufferedDC* dc, double w, double h, Panel panel) override;

	/**
	 * returns start Point if start, end Point otherwise
	 * @param bool
	 * @return Point
	 */
	Point getPoint(bool start);

	/**
	 * sets Point with given arguments
	 * if start sets start Point, end Point otherwise
	 * @param double
	 * @param double
	 * @param bool
	 */
	void setPoint(double x, double y, bool start);
	/**
	 * returns shape name
	 * @return "line"
	 */
	std::string getTypeName() override;
	/**
	 * returns shape parameters as string
	 * @return std::string coordinates of start point and end point of line
	 */
	std::string getParameters() override;
private:
	/**start and end Points of line */
	Point m_startPoint;
	Point m_endPoint;
};