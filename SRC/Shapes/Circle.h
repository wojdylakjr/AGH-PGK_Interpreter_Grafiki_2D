#pragma once

#include"Shape.h"
#include"Point.h"


class ShapeCircle : public Shape
{
public:
	/**
	 * constructor setting coordinates of the center, radius and color of circle 
	 * @param x and y coordinates of center point, radius and (hexadecimal) color
	 */
	ShapeCircle(double x, double y, double r, wxColor color);
	/**
	 * circle drawing method
	 * @param bufferedDc and actual width and heigth of out panel
	 */
	void draw(wxBufferedDC* dc, double w, double h, Panel panel) override;

	/**
	 * returns shape name
	 * @return "circle"
	 */
	std::string getTypeName() override;
	/**
	 * returns shape parameters as string
	 * @return std::string coordinates of center and radius
	 */
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