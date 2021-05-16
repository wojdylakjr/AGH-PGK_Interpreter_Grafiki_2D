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
