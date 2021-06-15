#include "Panel.h"


Panel::Panel(double x1, double y1, double x2, double y2) {
	m_leftDownPoint.setX(x1);
	m_leftDownPoint.setY(y1);
	m_rightUpPoint.setX(x2);
	m_rightUpPoint.setY(y2);

}

void Panel::updateCoordinates(double x1, double y1, double x2, double y2) {
	m_leftDownPoint.setX(x1);
	m_leftDownPoint.setY(y1);
	m_rightUpPoint.setX(x2);
	m_rightUpPoint.setY(y2);
}


Point Panel::getLeftDownPoint() const {
	return m_leftDownPoint;
}

Point Panel::getRightUpPoint() const {
	return m_rightUpPoint;
}

void Panel::setBackgroundColor(unsigned long color) {
	m_backgroundColor.Set(color);
}

wxColour Panel::getBackgroundColor() {
	return m_backgroundColor;
}