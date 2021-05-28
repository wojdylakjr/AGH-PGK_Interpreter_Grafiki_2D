#include "Shape.h"
int Shape::m_counter = 0;

Shape::Shape(wxColor color) : m_color(color) {
	m_id = m_counter;
	m_counter++;
}

void Shape::transform(double x, double y) {
	m_transformX += x;
	m_transformY += y;
}

void Shape::rotate(double angle, double x, double y) {
	m_rotateX = x;
	m_rotateY = y;
	m_rotateAngle = angle;
}

int Shape::getId() const {
	return m_id;
}

void Shape::setFillColour(wxColor fillColor) {
	m_fillColor = fillColor;
	m_isTransparent = false;
}

void Shape::setColour(wxColor color) {
	m_color = color;
}

void Shape::highlight() {
	m_highlight = true;
}

void Shape::darken() {
	m_highlight = false;
}

bool Shape::isHighlighted() {
	return m_highlight;
}

void Shape::setName(std::string name) {
	m_name = name;
}

std::string Shape::getName() const {
	return m_name;
}

void Shape::setCounterToZero() {
	m_counter = 0;
}

std::string Shape::getHexadecimalColour(bool outline) const
{
	unsigned red = outline ? m_color.Red() : m_fillColor.Red();
	unsigned green = outline ? m_color.Green() : m_fillColor.Green();
	unsigned blue = outline ? m_color.Blue() : m_fillColor.Blue();
	char hexcol[8];
	snprintf(hexcol, sizeof hexcol, "#%02x%02x%02x\0", red, green, blue);
	return std::string(hexcol);
}

Point Shape::getTransform() const
{
	return Point(m_transformX, m_transformY);
}

double Shape::getRotationAngle() const
{
	return m_rotateAngle;
}

name_code Shape::hashName()
{
	if (getTypeName() == "line") return line;
	if (getTypeName() == "rectangle") return rectangle;
	if (getTypeName() == "circle") return circle;
	if (getTypeName() == "ellipse") return ellipse;
	if (getTypeName() == "arc") return arc;
}

