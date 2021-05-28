#pragma once

#include "Shape.h"
#include "Point.h"

class ShapeLine : public Shape
{
public:
	ShapeLine(double x1, double y1, double x2, double y2, wxColor _color);
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

	std::string getTypeName() override;
	std::string getParameters() override;
private:
	Point m_startPoint;
	Point m_endPoint;
};
