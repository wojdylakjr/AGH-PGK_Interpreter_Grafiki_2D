#include "Line.h"
#include<vector>

Line::Line(double x1, double y1, double x2, double y2, wxColor color) : Shape(color){
	_startPoint.setX(x1);
	_startPoint.setY(y1);
	_endPoint.setX(x2);
	_endPoint.setY(y2);

}

void Line::draw(wxBufferedDC* dc, double Sx, double Sy) {
	double rotateRadians = -_rotateAngle * M_PI / 180.0;
     dc->SetPen(_color);
	dc->SetBrush(*wxTRANSPARENT_BRUSH);

	


	std::vector<Point> vertices = { _startPoint, _endPoint};

	for (auto&& vertice : vertices)
	{
		vertice.transformPoint(_transformX, _transformY);
		vertice.transformPoint(-_rotateX, -_rotateY);
		vertice.rotatePoint(rotateRadians);
		vertice.transformPoint(_rotateX, _rotateY);

		//_startPoint.transformPoint(-x0, -y0);//tu jest problem
		vertice.transformPoint(0, 0);//tu jest problem

		vertice.scalePoint(Sx, Sy);
	}

	wxPoint points[2] = { wxPoint(vertices[0].getX(), vertices[0].getY()), wxPoint(vertices[1].getX(), vertices[1].getY()) };
	dc->DrawLine(points[0], points[1]);

	//wxPoint points[2] = { wxPoint(_startPoint.getX(), _startPoint.getY()), wxPoint(_endPoint.getX(), _endPoint.getY()) };
	//dc->DrawLine(points[0], points[1]);

}