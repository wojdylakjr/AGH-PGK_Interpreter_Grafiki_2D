#include "Line.h"

Line::Line(double x1, double y1, double x2, double y2, wxColor color) : Shape(color){
	_startPoint.setX(x1);
	_startPoint.setY(y1);
	_endPoint.setX(x2);
	_endPoint.setY(x2);

}

void Line::draw(wxBufferedDC* dc, double Sx, double Sy) {
	double rotateRadians = -_rotateAngle * M_PI / 180.0;
     dc->SetPen(_color);
	dc->SetBrush(*wxTRANSPARENT_BRUSH);

	_startPoint.transformPoint(_transformX, _transformY);
	_startPoint.transformPoint(-_rotateX, -_rotateY);
	_startPoint.rotatePoint(rotateRadians);
	_startPoint.transformPoint(_rotateX, _rotateY);

	//_startPoint.transformPoint(-x0, -y0);//tu jest problem
	_startPoint.scalePoint(Sx, Sy);

	_endPoint.transformPoint(_transformX, _transformY);
	_endPoint.transformPoint(-_rotateX, -_rotateY);
	_endPoint.rotatePoint(rotateRadians);
	_endPoint.transformPoint(_rotateX, _rotateY);

	//_endPoint.transformPoint(-x0, -y0);//tu jest problem
	_endPoint.scalePoint(Sx, Sy);

	dc->DrawLine(wxPoint(_startPoint.getX(), _startPoint.getY()), wxPoint(_endPoint.getX(), _endPoint.getY()));

}