#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>

class ShapeArc : public Shape
{
public:
	/**
	 * constructor setting coordinates of the center, radiusX, radiusY and color of ellipse on which the arc is based
	 * also sets the angles that define the start and end of drawing an arc
	 * @param x and y coordinates of center point, radiusX, radiusY , begin angle, end angle and (hexadecimal) color of ellipse
	 */
	ShapeArc(double x, double y, double rX, double rY, double begin, double end, wxColor color);

	/**
	 *destructor (deallocating memory of table wxPoint points[])
	 */
	~ShapeArc();

	/**
	 * arc drawing method
	 * @param bufferedDc and actual width and heigth of out panel
	 */
	void draw(wxBufferedDC* dc, double w, double h, Panel panel) override;

	/**
	 * returns name of the shape
	 * @return "arc"
	 */
	std::string getTypeName() override;
	/**
	 * returns shape parameters as string
	 * @return std::string coordinates of center, radiusX and radiusY, begin angle, end angle
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
	 * returns angle (start if begin, end otherwise)
	 * @param bool
	 * @return double
	 */
	double getAngle(bool begin);

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

	/**
	 * sets shaft
	 * @param double
	 * @param bool
	 */
	void setAngle(double angle, bool begin);

	

private:
	/**arc properties*/
	Point m_centerOfArc;
	double m_radiusX;
	double m_radiusY;
	double m_beginAngle;
	double m_endAngle;
	/*draws arc as points*/
	const int maxPoints = 50;
	wxPoint* points;//

};