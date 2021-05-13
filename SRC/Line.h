#pragma once
#include "Shape.h"
#include "Point.h"
class Line : public Shape
{
public:
	Line(double x1, double y1, double x2, double y2, wxColor _color);
	void draw(wxBufferedDC* dc, double Sx, double Sy) override;

private:
	Point _startPoint;
	Point _endPoint;

};

