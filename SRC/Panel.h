#pragma once
#include"Point.h"

class Panel
{
public:
	Panel(double x1 = 0, double y1 = 0, double x2 = 700, double y2 = 600);
	void updateCoordinates(double x1, double y1, double x2, double y2);
	Point getLeftDownPoint() const;
	Point getRightUpPoint() const;



private:
	Point m_leftDownPoint;
	Point m_rightUpPoint;



};
