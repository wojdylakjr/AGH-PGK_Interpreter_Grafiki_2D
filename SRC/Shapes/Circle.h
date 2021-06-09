#pragma once

#include"Shape.h"
#include"Point.h"


class ShapeCircle : public Shape
{
public:
	ShapeCircle(double x, double y, double r, wxColor color);
	void draw(wxBufferedDC* dc, double w, double h, Panel panel) override;

	std::string getTypeName() override;
	std::string getParameters() override;


	/**
	 * returns center of circle
	 * @return Point&
	 */
	Point getCenter();

	/**
	 * returns radius of circle
	 * @return double&
	 */
	double getRadius();

	/**
	 * sets center
	 * @param double
	 * @param double
	 */
	void setCenter(double x, double y);

	/**
	 * sets radius
	 * @param double
	 */
	void setRadius(double radius);

private:
	Point m_centerOfCircle;
	double m_radius;
	

};