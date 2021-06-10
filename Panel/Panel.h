#pragma once

#include <wx/colour.h>
#include "../Shapes/Point.h"



class Panel
{
public:
	Panel(double x1 = 0, double y1 = 0, double x2 = 799.0, double y2 = 640.0);
	void updateCoordinates(double x1, double y1, double x2, double y2);
	Point getLeftDownPoint() const;
	Point getRightUpPoint() const;
	void setBackgroundColor(unsigned long color);
	wxColour getBackgroundColor();


private:
	Point m_leftDownPoint;
	Point m_rightUpPoint;
	wxColour m_backgroundColor = wxColour(255, 255,255);


};
