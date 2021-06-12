#include "Line.h"



ShapeLine::ShapeLine(double x1, double y1, double x2, double y2, wxColor color) : Shape(color) {
	m_startPoint.setX(x1);
	m_startPoint.setY(y1);
	m_endPoint.setX(x2);
	m_endPoint.setY(y2);

}

void ShapeLine::draw(wxBufferedDC* dc, double w, double h, Panel panel) {
	double rotateRadians = -m_rotateAngle * M_PI / 180.0;
	dc->SetPen(m_highlight ? *wxRED : m_color);
	double Sx = (double)w / (panel.getRightUpPoint().getX() - panel.getLeftDownPoint().getX());
	double Sy = (double)h / (panel.getRightUpPoint().getY() - panel.getLeftDownPoint().getY());



	std::vector<Point> vertices = { m_startPoint, m_endPoint };

	for (auto&& vertice : vertices)
	{
		vertice.transformPoint(m_transformX, m_transformY);
		vertice.transformPoint(-m_rotateX, -m_rotateY);
		vertice.rotatePoint(rotateRadians);
		vertice.transformPoint(m_rotateX, m_rotateY);

		vertice.transformPoint(-panel.getLeftDownPoint().getX(), -panel.getLeftDownPoint().getY());
		vertice.scalePoint(Sx, Sy);
	}

	wxPoint points[2] = { wxPoint(vertices[0].getX(), h - 1 - vertices[0].getY()), wxPoint(vertices[1].getX(), h - 1 - vertices[1].getY()) };
	dc->DrawLine(points[0], points[1]);
}

Point ShapeLine::getPoint(bool start)
{
	if (start) {
		return m_startPoint;
	}
	else {
		return m_endPoint;
	}
}

void ShapeLine::setPoint(double x, double y, bool start)
{
	if (start) {
		m_startPoint.setX(x);
		m_startPoint.setY(y);
	}
	else {
		m_endPoint.setX(x);
		m_endPoint.setY(y);
	}
}

std::string ShapeLine::getTypeName() {
	return "line";
}

std::string ShapeLine::getParameters() {
	std::string temp = "line ";
	temp += std::to_string((int)m_startPoint.getX());
	temp += " ";
	temp += std::to_string((int)m_startPoint.getY());
	temp += " ";
	temp += std::to_string((int)m_endPoint.getX());
	temp += " ";
	temp += std::to_string((int)m_endPoint.getY());
	temp += " ";
	temp += m_color.GetAsString(wxC2S_HTML_SYNTAX);
	return temp;
}