#pragma once

/**
 * @file 
 * Header for dialog validator class
 */

#include <stdexcept>
#include <string>
#include <regex>
#include <algorithm>
#include <sstream>
#include <iterator>

/** class responsible for validation of dialog inputs */
class DialogValidator {

private:
	/** last inserted x */
	int m_x;
	/** last inserted y */
	int m_y;
	/** stores colour */
	unsigned long m_colour = 0;
	/** regex used to validate colour */
	const std::regex m_pattern = std::regex("^#([A-Fa-f0-9]{6})$");
public:
	/** returns x */
	int getX() const;
	/** returns y */
	int getY() const;
	/** converts to Point */
	bool convertToPoint(std::string input);
	/** converts to colour */
	bool convertToColour(std::string input);
	/** returns colour */
	unsigned long getColour() const;
	
};