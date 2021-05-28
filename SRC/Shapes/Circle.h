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

private:
	Point m_centerOfCircle;
	double m_radius;

};