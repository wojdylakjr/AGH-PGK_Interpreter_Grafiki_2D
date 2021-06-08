#pragma once
#include"Shape.h"
#include"Point.h"
#include <vector>


class ShapeRectangle : public Shape
{
public:
	ShapeRectangle(double x1, double y1, double x2, double y2, wxColor _color);
	void draw(wxBufferedDC* dc, double w, double h, Panel panel) override;

	std::string getTypeName() override;
	std::string getParameters() override;

private:
	Point m_leftDownPoint;
	Point m_rightUpPoint;
	std::vector<Point> vertices;
};
