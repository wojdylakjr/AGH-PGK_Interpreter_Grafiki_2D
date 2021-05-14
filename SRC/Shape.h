#pragma once
#include <wx/colour.h>
#include <wx/dcbuffer.h>

class Shape
{
public:
	Shape() = default;
	//konstruktor, ustawia kolor obiektu oraz przypisuje mu id
	Shape(wxColor color);

	void virtual draw(wxBufferedDC* dc, double Sx, double Sy) = 0;
	void transform(double x, double y);
	void rotate(double angle, double x = 0, double y = 0);

protected:
	int m_id;
	//kolejne zmienne, w zaleznosci od ktorych bedziemy rysowac obiekt, ustawiamy je w metodach transform i rotate
	double m_transformX = 0;
	double m_transformY = 0;
	double m_rotateX = 0;
	double m_rotateY = 0;
	double m_rotateAngle = 0;

	wxColor m_color;

private:
	static int m_counter;
};
