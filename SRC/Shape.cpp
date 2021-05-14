#include "Shape.h"
int Shape::_counter = 0;

Shape::Shape(){}
Shape::Shape(wxColor color) : _color(color){
	_id = _counter;
	_counter++;
}

void Shape::transform(double x, double y) {
	_transformX += x;
	_transformY += y;
}

void Shape::rotate(double angle, double x , double y) {
	_rotateX = x; 
	_rotateY = y; 
	_rotateAngle = angle;
}

