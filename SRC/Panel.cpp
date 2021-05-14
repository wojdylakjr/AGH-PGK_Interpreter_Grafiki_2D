#include "Panel.h"


Panel::Panel(double x1, double y1, double x2, double y2) {
	_leftDownPoint.setX(x1);
	_leftDownPoint.setY(y1);
	_rightUpPoint.setX(x2);
	_rightUpPoint.setY(y2);

}

void Panel::updateCoordinates(double x1, double y1, double x2, double y2) {

}


Point Panel::getLeftDownPoint() const {
	return _leftDownPoint;
}

Point Panel::getRightUpPoint() const {
	return _rightUpPoint;
}