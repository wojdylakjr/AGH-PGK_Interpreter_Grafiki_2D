#pragma once


#include "Shape.h"
#include "Point.h"
#include <vector>


class ShapeEllipse : public Shape
{
public:
	ShapeEllipse(double x, double y, double rX, double rY, wxColor color);
	void draw(wxBufferedDC* dc, double w, double h, Panel panel) override;

	std::string getTypeName() override;
	std::string getParameters() override;

	/**
	 * returns centre of ellipse
	 * @return Point
	 */
	Point getCenter();

	/**
	 * returns shaft (horizontal if horizontal, vertical otherwise)
	 * @param bool
	 * @return double
	 */
	double getShaft(bool horizontal);

	/**
	 * sets center
	 * @param double
	 * @param double
	 */
	void setCenter(double x, double y);

	/**
	 * sets shaft
	 * @param double
	 * @param bool
	 */
	void setShaft(double shaft, bool horizontal);

private:
	Point m_centerOfEllipse;
	double m_radiusX;
	double m_radiusY;

};