#include "DialogValidator.h"

int DialogValidator::getX() const
{
	return m_x;
}

int DialogValidator::getY() const
{
	return m_y;
}

bool DialogValidator::convertToPoint(std::string input)
{
	if (input.empty()) {
		return false;
	}

	size_t coma = input.find(",");
	if (coma == -1) {
		return false;
	}

	size_t start = input.find("(");
	if (start == -1) {
		return false;
	}

	size_t end = input.find(")");
	if (end == -1) {
		return false;
	}

	try {
		m_x = std::stoi(input.substr(start + 1, coma - start - 1));
		m_y = std::stoi(input.substr(coma + 2, end - coma - 2));
	}
	catch (const std::invalid_argument&) {
		return false;
	}

	return true;
}

bool DialogValidator::convertToColour(std::string colour)
{

	if (!regex_match(colour, m_pattern)) {
		return false;
	}

	unsigned long r, g, b;

	std::string red = colour.substr(1, 2);
	std::string green = colour.substr(3, 2);
	std::string blue = colour.substr(5, 2);

	std::istringstream isR(red);
	isR >> std::hex >> r;
	std::istringstream isG(green);
	isG >> std::hex >> g;
	std::istringstream isB(blue);
	isB >> std::hex >> b;

	m_colour = b << 16 | g << 8 | r;

	return true;
}

unsigned long DialogValidator::getColour() const
{
	return m_colour;
}
