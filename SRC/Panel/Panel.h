#pragma once
/**
 * @file
 * Class to represent drawing panel
 */
#include <wx/colour.h>
#include "../Shapes/Point.h"



class Panel
{
public:
	/**
	* constructor setting panel coordinates
	* @param four coordinates deafult set to 0 0 799 641
	 */
	Panel(double x1 = 0, double y1 = 0, double x2 = 799.0, double y2 = 641.0);

	/**
	* method to update panel coordinates
	 */
	void updateCoordinates(double x1, double y1, double x2, double y2);

	/**
	* getter of LeftDownPoint
	* @return Point
	 */
	Point getLeftDownPoint() const;

	/**
	* getter of RightUpPoint
	* @return Point
	 */
	Point getRightUpPoint() const;

	/**
	* setter to wxColur m_backgroungcolor
	* @param unsigned long
	 */
	void setBackgroundColor(unsigned long color);

	/**
	* getter of m_backgroungcolor
	* @return wxColour
	 */
	wxColour getBackgroundColor();


private:
	/** Point variable represents left down point*/
	Point m_leftDownPoint;

	/** Point variable represents right up point*/
	Point m_rightUpPoint;

	/** background color default set to white*/
	wxColour m_backgroundColor = wxColour(255, 255, 255);


};
