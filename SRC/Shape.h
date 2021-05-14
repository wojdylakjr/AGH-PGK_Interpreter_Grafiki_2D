#pragma once
#include <wx/colour.h>
#include <wx/dcbuffer.h>

class Shape
{
public:
	Shape();
	//konstruktor, ustawia kolor obiektu oraz przypisuje mu id
	Shape(wxColor color);

	void virtual draw(wxBufferedDC* dc, double Sx, double Sy) = 0;
	void transform(double x, double y);
	void rotate(double angle, double x = 0, double y = 0);
	
protected:
	int _id;
	//kolejne zmienne, w zaleznosci od ktorych bedziemy rysowac obiekt, ustawiamy je w metodach transform i rotate
	double _transformX = 0;
	double _transformY = 0;
    double _rotateX = 0;
	double _rotateY = 0;
	double _rotateAngle = 0;

	wxColor _color;

private:
	static int _counter;
};

