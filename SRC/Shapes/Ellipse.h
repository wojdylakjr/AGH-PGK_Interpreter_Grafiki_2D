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

private:
	Point m_centerOfEllipse;
	double m_radiusX;
	double m_radiusY;

};