#pragma once

#include <wx/colour.h>
#include <wx/dcbuffer.h>
#include"../Panel/Panel.h"

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
	Shape() = default;
	//konstruktor, ustawia kolor obiektu oraz przypisuje mu id
	Shape(wxColor color);

	void virtual draw(wxBufferedDC* dc, double Sx, double Sy, Panel panel) = 0;
	std::string virtual getTypeName() = 0; //zwraca nazwe obiketu, czyli "line", "rectangle", "circle", "arc"
	std::string virtual getParameters() = 0;
	void setFillColour(wxColor fillColor);
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

	void transform(double x, double y);
	void rotate(double angle, double x = 0, double y = 0);
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

	/**
	 * sets counter
	 * used in read and clear commands
	 * @param counter
	 */
	static void setCounter(int counter);

protected:
	int m_id;
	//kolejne zmienne, w zaleznosci od ktorych bedziemy rysowac obiekt, ustawiamy je w metodach transform i rotate
	double m_transformX = 0;
	double m_transformY = 0;
	double m_rotateX = 0;
	double m_rotateY = 0;
	double m_rotateAngle = 0;

	wxColor m_color;
	wxColor m_fillColor;

	std::string m_name;

	bool m_isTransparent = true;
	bool m_highlight = false;

private:
	static int m_counter;
};
