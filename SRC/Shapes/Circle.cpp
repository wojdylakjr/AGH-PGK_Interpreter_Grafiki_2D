#include "Circle.h"

#include <vector>

ShapeCircle::ShapeCircle(double x, double y, double r, wxColor color) : m_radius(r), Shape(color) {

	m_centerOfCircle.setX(x);
	m_centerOfCircle.setY(y);

}

void ShapeCircle::draw(wxBufferedDC* dc, double w, double h, Panel panel) {
	double rotateRadians = -m_rotateAngle * M_PI / 180.0;
	dc->SetPen(m_highlight ? *wxRED : m_color);
	dc->SetBrush((m_isTransparent ? *wxTRANSPARENT_BRUSH : m_highlight ? m_fillColor.ChangeLightness(150) : m_fillColor));
	double Sx = (double)w / (panel.getRightUpPoint().getX() - panel.getLeftDownPoint().getX());
	double Sy = (double)h / (panel.getRightUpPoint().getY() - panel.getLeftDownPoint().getY());


	R = m_radius * (Sx > Sy ? Sy : Sx);

	center = m_centerOfCircle;

	center.transformPoint(m_transformX, m_transformY);

	center.transformPoint(-m_rotateX, -m_rotateY);
	center.rotatePoint(rotateRadians);
	center.transformPoint(m_rotateX, m_rotateY);

	center.transformPoint(-panel.getLeftDownPoint().getX(), -panel.getLeftDownPoint().getY());
	center.scalePoint(Sx, Sy);

	dc->DrawCircle(center.getX(),h - 1 - center.getY(), R);


}

std::string ShapeCircle::getTypeName() {
	return "circle";
}

std::string ShapeCircle::getParameters() {
	std::string temp = "circle ";
	temp += std::to_string((int)center.getX());
	temp += " ";
	temp += std::to_string((int)center.getY());
	temp += " ";
	temp += std::to_string((int)R);
	temp += " ";
	temp += m_color.GetAsString(wxC2S_HTML_SYNTAX);
	return temp;
}

Point ShapeCircle::getCenter()
{
	return m_centerOfCircle;
}

double ShapeCircle::getRadius()
{
	return m_radius;
}

void ShapeCircle::setCenter(double x, double y)
{
	m_centerOfCircle.setX(x);
	m_centerOfCircle.setY(y);
}

void ShapeCircle::setRadius(double radius)
{
	m_radius = radius;
}