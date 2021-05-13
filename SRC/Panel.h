#pragma once
#include"Point.h"

class Panel
{
public:
	Panel(double x1 = 0, double y1 = 0, double x2 = 800, double y2 = 800);
	void updateCoordinates(double x1, double y1, double x2, double y2);



private:
	Point _leftDownPoint;
	Point _rightUpPoint;
	
	//std::vector <Shape*> shapes;
	

};

