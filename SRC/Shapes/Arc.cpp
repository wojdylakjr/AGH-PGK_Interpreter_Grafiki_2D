#include "Arc.h"

ShapeArc::ShapeArc(double x, double y, double rX, double rY, double begin, double end, wxColor color) : m_radiusX(2*rX), m_radiusY(2*rY), m_beginAngle(begin), m_endAngle(end), Shape(color) {

	m_centerOfArc.setX(x);
	m_centerOfArc.setY(y);
	points = new wxPoint[50 + 1];
}
ShapeArc::~ShapeArc() {
	delete[] points;
}
void ShapeArc::draw(wxBufferedDC* dc, double w, double h, Panel panel) {

	double rotateRadians = -m_rotateAngle * M_PI / 180.0;

	dc->SetPen(m_highlight ? *wxRED : m_color);
	double Sx = (double)w / (panel.getRightUpPoint().getX() - panel.getLeftDownPoint().getX());
	double Sy = (double)h / (panel.getRightUpPoint().getY() - panel.getLeftDownPoint().getY());

	double width = m_radiusX / 2.0;
	double height = m_radiusY / 2.0;
	

	
	double beginRadians = (360.0 * M_PI / 180.0) - (m_beginAngle * M_PI / 180.0);
	double endRadians = (360.0 * M_PI / 180.0) - (m_endAngle * M_PI / 180.0);
	
	double step =static_cast<double>( fabs(endRadians - beginRadians) / maxPoints);


		
	
	

	std::vector<Point> arc;
	if(beginRadians > endRadians)
		std::swap(beginRadians, endRadians);
	
	for (double angle = beginRadians; angle < endRadians + M_PI / 180.0; angle += step)
	{
		Point point( m_centerOfArc.getX() + width * cos(-angle),  m_centerOfArc.getY() + height * sin(-angle));
		arc.push_back(point);
	}
	
	
	

	
	

	int index = 0;
	for (auto&& arcPoint : arc)
	{
		arcPoint.transformPoint(m_transformX, m_transformY);

		arcPoint.transformPoint(-m_rotateX, -m_rotateY);
		arcPoint.rotatePoint(rotateRadians);
		arcPoint.transformPoint(m_rotateX, m_rotateY);

		arcPoint.transformPoint(-panel.getLeftDownPoint().getX(), -panel.getLeftDownPoint().getY());
		arcPoint.scalePoint(Sx, Sy);
		points[index] = wxPoint(arcPoint.getX(), h - 1 - arcPoint.getY());
		index++;
	}

	dc->DrawLines(maxPoints + 1, points);
	
	
	
	
}

std::string ShapeArc::getTypeName() {
	return "arc";
}
std::string ShapeArc::getParameters() {
	std::string temp = "arc ";
	temp += std::to_string((int)m_centerOfArc.getX());
	temp += " ";
	temp += std::to_string((int)m_centerOfArc.getY());
	temp += " ";
	temp += std::to_string((int)m_radiusX);
	temp += " ";
	temp += std::to_string((int)m_radiusY);
	temp += " ";
	temp += std::to_string((int)m_beginAngle);
	temp += " ";
	temp += std::to_string((int)m_endAngle);
	temp += " ";
	temp += m_color.GetAsString(wxC2S_HTML_SYNTAX);
	return temp;
}

Point ShapeArc::getCenter()
{
	return m_centerOfArc;
}

double ShapeArc::getShaft(bool horizontal)
{
	return horizontal ? m_radiusX : m_radiusY;
}

double ShapeArc::getAngle(bool begin)
{
	return begin ? m_beginAngle : m_endAngle;
}

void ShapeArc::setCenter(double x, double y)
{
	m_centerOfArc.setX(x);
	m_centerOfArc.setY(y);
}

void ShapeArc::setShaft(double shaft, bool horizontal)
{
	if (horizontal) {
		m_radiusX = shaft;
	}
	else {
		m_radiusY = shaft;
	}
}

void ShapeArc::setAngle(double angle, bool begin)
{
	if (begin) {
		m_beginAngle = angle;
	}
	else {
		m_endAngle = angle;
	}
}


Point m_centerOfArc;
double m_radiusX;
double m_radiusY;
double m_beginAngle;
double m_endAngle;