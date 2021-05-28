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

private:
	Point m_centerOfArc;
	double m_radiusX;
	double m_radiusY;
	double m_beginAngle;
	double m_endAngle;
	const int maxPoints = 50;
	wxPoint* points;

};