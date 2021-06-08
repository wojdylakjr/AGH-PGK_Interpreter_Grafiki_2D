#pragma once

#include "Shape.h"
#include "Point.h"
#include <vector>

class ShapeArc : public Shape
{
public:
	ShapeArc(double x, double y, double rX, double rY, double begin, double end, wxColor color);
	~ShapeArc();
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
	Point m_centerOfArc;
	double m_radiusX;
	double m_radiusY;
	double m_beginAngle;
	double m_endAngle;
	const int maxPoints = 50;
	wxPoint* points;

};