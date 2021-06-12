#pragma once


#include "Shape.h"
#include "Point.h"
#include <vector>


class ShapeEllipse : public Shape
{
public:
	/**
	 * constructor setting coordinates of the center, radiusX, radiusY and color of ellipse
	 * @param x and y coordinates of center point, radiusX, radiusY ,and (hexadecimal) color of ellipse
	 */
	ShapeEllipse(double x, double y, double rX, double rY, wxColor color);

	/**
	 * ellipse drawing method
	 * @param bufferedDc and actual width and heigth of out panel
	 */
	void draw(wxBufferedDC* dc, double w, double h, Panel panel) override;

	/**
	 * returns shape name
	 * @return "ellipse"
	 */
	std::string getTypeName() override;
	/**
	 * returns shape parameters as string
	 * @return std::string coordinates of center, radiusX and radiusY
	 */
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
	/**ellipse properties*/
	Point m_centerOfEllipse;
	double m_radiusX;
	double m_radiusY;

};