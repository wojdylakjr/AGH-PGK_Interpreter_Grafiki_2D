#include "Ellipse.h"



ShapeEllipse::ShapeEllipse(double x, double y, double rX, double rY, wxColor color) : m_radiusX(rX), m_radiusY(rY), Shape(color) {

	m_centerOfEllipse.setX(x);
	m_centerOfEllipse.setY(y);
}

void ShapeEllipse::draw(wxBufferedDC* dc, double w, double h, Panel panel) {

	double rotateRadians = -m_rotateAngle * M_PI / 180.0;
	dc->SetPen(m_highlight ? *wxRED : m_color);
	dc->SetBrush((m_isTransparent ? *wxTRANSPARENT_BRUSH : m_highlight ? m_fillColor.ChangeLightness(150) : m_fillColor));
	double Sx = (double)w / (panel.getRightUpPoint().getX() - panel.getLeftDownPoint().getX());
	double Sy = (double)h / (panel.getRightUpPoint().getY() - panel.getLeftDownPoint().getY());


	
	double width = m_radiusX;
	double height = m_radiusY;
	//double width = m_radiusX / 2.0;
	//double height = m_radiusY / 2.0;

	const int maxPoints = 50;
	double step = M_PI * 2.0 / maxPoints;

	std::vector<Point> ellipse;

	for (double angle = 0; angle < M_PI * 2.0; angle += step)
	{
		Point point(m_centerOfEllipse.getX() + width * cos(angle), m_centerOfEllipse.getY() + height * sin(angle));
		ellipse.insert(ellipse.end(), point);
	}

	wxPoint points[maxPoints];
	int index = 0;

	for (auto&& ellipsePoint : ellipse)
	{
		ellipsePoint.transformPoint(m_transformX, m_transformY);

		ellipsePoint.transformPoint(-m_rotateX, -m_rotateY);
		ellipsePoint.rotatePoint(rotateRadians);
		ellipsePoint.transformPoint(m_rotateX, m_rotateY);

		ellipsePoint.transformPoint(-panel.getLeftDownPoint().getX(), -panel.getLeftDownPoint().getY());
		ellipsePoint.scalePoint(Sx, Sy);

		points[index] = wxPoint(ellipsePoint.getX(), h - 1 - ellipsePoint.getY());
		index++;
	}
	dc->DrawPolygon(maxPoints, points);
}

std::string ShapeEllipse::getTypeName() {
	return "Ellipse";
}

std::string ShapeEllipse::getParameters() {
	std::string temp = "ellipse ";
	temp += std::to_string((int)m_centerOfEllipse.getX());
	temp += " ";
	temp += std::to_string((int)m_centerOfEllipse.getY());
	temp += " ";
	temp += std::to_string((int)m_radiusX);
	temp += " ";
	temp += std::to_string((int)m_radiusY);
	temp += " ";
	temp += m_color.GetAsString(wxC2S_HTML_SYNTAX);
	return temp;
}