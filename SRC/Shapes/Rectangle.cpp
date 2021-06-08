#include "Rectangle.h"
//#include <vector>

ShapeRectangle::ShapeRectangle(double x1, double y1, double x2, double y2, wxColor color) : Shape(color) {
	m_leftDownPoint.setX(x1);
	m_leftDownPoint.setY(y1);
	m_rightUpPoint.setX(x2);
	m_rightUpPoint.setY(y2);

}

void ShapeRectangle::draw(wxBufferedDC* dc, double w, double h, Panel panel) {
	double rotateRadians = -m_rotateAngle * M_PI / 180.0;
	dc->SetPen(m_highlight ? *wxRED : m_color);
	dc->SetBrush((m_isTransparent ? *wxTRANSPARENT_BRUSH : m_highlight ? m_fillColor.ChangeLightness(150) : m_fillColor));
	double Sx = (double)w / (panel.getRightUpPoint().getX() - panel.getLeftDownPoint().getX());
	double Sy = (double)h / (panel.getRightUpPoint().getY() - panel.getLeftDownPoint().getY());




	vertices = { m_leftDownPoint, m_rightUpPoint };

	for (auto&& vertice : vertices)
	{
		vertice.transformPoint(m_transformX, m_transformY);
		vertice.transformPoint(-m_rotateX, -m_rotateY);
		vertice.rotatePoint(rotateRadians);
		vertice.transformPoint(m_rotateX, m_rotateY);


		vertice.transformPoint(-panel.getLeftDownPoint().getX(), -panel.getLeftDownPoint().getY());

		vertice.scalePoint(Sx, Sy);
	}

	wxPoint points[4] = { wxPoint(vertices[0].getX(),h - 1 - vertices[0].getY()), wxPoint(vertices[0].getX(),h - 1 - vertices[1].getY()) ,wxPoint(vertices[1].getX(), h - 1 - vertices[1].getY()), wxPoint(vertices[1].getX(),  h - 1 - vertices[0].getY()) };
	dc->DrawPolygon(4, points);
}

std::string ShapeRectangle::getTypeName() {
	return "rectangle";
}

std::string ShapeRectangle::getParameters() {
	std::string temp = "rectangle ";
	temp += std::to_string((int)vertices[0].getX());
	temp += " ";
	temp += std::to_string((int)(vertices[0].getY()));
	temp += " ";
	temp += std::to_string((int)vertices[1].getX());
	temp += " ";
	temp += std::to_string((int)(vertices[1].getY()));
	temp += " ";
	temp += m_color.GetAsString(wxC2S_HTML_SYNTAX);
	return temp;
}

Point ShapeRectangle::getPoint(bool bottomLeft)
{
	if (bottomLeft) {
		return m_leftDownPoint;
	}
	else {
		return m_rightUpPoint;
	}
}

void ShapeRectangle::setPoint(double x, double y, bool bottomLeft)
{
	if (bottomLeft) {
		m_leftDownPoint.setX(x);
		m_leftDownPoint.setY(y);
	}
	else {
		m_rightUpPoint.setX(x);
		m_rightUpPoint.setY(y);
	}
}