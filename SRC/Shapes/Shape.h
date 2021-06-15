#pragma once
/**
 * @file
 * abstract class to represent shape
 */
#include <wx/colour.h>
#include <wx/dcbuffer.h>
#include"../Panel/Panel.h"

 /**
  * enum with all shapes
  */
enum name_code {
	line,
	rectangle,
	circle,
	ellipse,
	arc
};

class Shape
{
public:
	/**
	 * default constructor
	 */
	Shape() = default;

	/**
	 *  constructor with wxColor color
	 */
	Shape(wxColor color);

	/**
	 * virtual method to draw object
	 */
	void virtual draw(wxBufferedDC * dc, double Sx, double Sy, Panel panel) = 0;

	/**
	 * getter shape name
	 */
	std::string virtual getTypeName() = 0;

	/**
	 * method returns string with parameters formatted as same as command
	 */
	std::string virtual getParameters() = 0;

	/**
	 * setter to fill colour
	 */
	void setFillColour(wxColor fillColor);

	/**
	 * set edge colour
	 */
	void setColour(wxColor color);

	/**
	 * highlights object 
	 */
	void highlight();

	/**
	 * darkens object
	 */
	void darken();

	/**
	 * returns true if objeci is highlighted, false otherwise
	 * @return bool
	 */
	bool isHighlighted();

	/**
	 * retrurns if object is transparent
	 */
	bool isTransparent() const;

	/**
	 * transform shsape
	 */
	void transform(double x, double y);

	/**
	 * rotate shape
	 */
	void rotate(double angle, double x = 0, double y = 0);

	/**
	* getter shape ID
	*/
	int getId() const;

	/**
	 * sets rotation vector
	 * @param double
	 * @param double
	 */
	virtual void setTransform(double x, double y) final;

	/**
	 * sets field name
	 * @param std::string
	 */
	void setName(std::string name);

	/**
	 * returns name
	 * @return std::string
	 */
	std::string getName() const;

	/**
	 * returns colour in hexadecimal (eg: #000000)
	 * if outline returns outline colour, fill colour otherwise
	 * @param bool
	 * @return std::string
	 */
	virtual std::string getHexadecimalColour(bool outline) const final;

	/**
	 * returns transform vector as Point
	 * @return Point
	 */
	Point getTransform() const;

	/**
	 * returns rotation angle
	 * @return double
	 */
	double getRotationAngle() const;

	/**
	 * returns input rotation angle
	 * @return double
	 */
	double getInputRotationAngle() const;

	/**
	 * returns name as enum
	 * @return name_code
	 */
	virtual name_code hashName() final;

	/**
	 * returns rotate x
	 * @return double
	 */
	double getRotateX() const;

	/**
	 * returns rotate y
	 * @return double
	 */
	double getRotateY() const;

	/**
	 * sets object ID
	 * used in read command
	 * @param ID
	 */
	void setID(int ID);

	static void setCounter(int counter);

	/**
	 * sets input rotation angle
	 * @param angle
	 */
	void setInputRotationAngle(double angle);

protected:
	/**shape ID */
	int m_id;

	/** x length to transform point*/
	double m_transformX = 0;

	/** y length to transform point*/
	double m_transformY = 0;

	/** x value to roate point*/
	double m_rotateX = 0;

	/** y value to roate point*/
	double m_rotateY = 0;

	/** rotate angle*/
	double m_rotateAngle = 0;

	/** rotate angle seted by user*/
	double m_inputRotateAngle = 0;

	/** shape edge color*/
	wxColor m_color;

	/** hape fill color*/
	wxColor m_fillColor;

	/** shape name*/
	std::string m_name;

	bool m_isTransparent = true;
	bool m_highlight = false;

private:
	/** used to set ID in constructor*/
	static int m_counter;
};
