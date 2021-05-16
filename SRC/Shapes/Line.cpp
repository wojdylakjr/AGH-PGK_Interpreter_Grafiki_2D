#include "Line.h"

#include <vector>

Line::Line(double x1, double y1, double x2, double y2, wxColor color) : Shape(color) {
	m_startPoint.setX(x1);
	m_startPoint.setY(y1);
	m_endPoint.setX(x2);
	m_endPoint.setY(y2);

}

void Line::draw(wxBufferedDC* dc, double Sx, double Sy) {
	double rotateRadians = -m_rotateAngle * M_PI / 180.0;
	dc->SetPen(m_color);
	dc->SetBrush(*wxTRANSPARENT_BRUSH);




	std::vector<Point> vertices = { m_startPoint, m_endPoint };

	for (auto&& vertice : vertices)
	{
		vertice.transformPoint(m_transformX, m_transformY);
		vertice.transformPoint(-m_rotateX, -m_rotateY);
		vertice.rotatePoint(rotateRadians);
		vertice.transformPoint(m_rotateX, m_rotateY);

		//_startPoint.transformPoint(-x0, -y0);//tu jest problem
		vertice.transformPoint(0, 0);//tu jest problem

		vertice.scalePoint(Sx, Sy);
	}

	wxPoint points[2] = { wxPoint(vertices[0].getX(), vertices[0].getY()), wxPoint(vertices[1].getX(), vertices[1].getY()) };
	dc->DrawLine(points[0], points[1]);

	//wxPoint points[2] = { wxPoint(_startPoint.getX(), _startPoint.getY()), wxPoint(_endPoint.getX(), _endPoint.getY()) };
	//dc->DrawLine(points[0], points[1]);

}