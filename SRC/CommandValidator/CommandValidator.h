#pragma once

/**
 * @file
 * Header for CommandValidator class
 */

#include "../Panel/Panel.h"

#include <string>
#include <vector>
#include <algorithm>
#include <regex>

 /**
  * class representing command validator
  */
class CommandValidator {
private:

	/** vector of names of existing commands */
	const std::vector<std::string> m_commands = {
		"range", "background", "line", "rectangle", "circle",
		"ellipse", "arc", "fill", "delete", "move", "rotate",
		"show", "clear", "write", "read", "save", "clearcmd"
	};


	/** ID of last entered command */
	int m_commandID = -1;

	/** help message to be printed if input is invalid */
	std::string m_helpMessage = "";

	/** vector of double */
	std::vector<int> m_values;

	/** regex used to validate colour */
	const std::regex m_pattern = std::regex("^#([A-Fa-f0-9]{6})$");

	/** colur stored in unsigned long */
	unsigned long m_colour = 0;

	/** current Panel size */
	int m_bottomLeftCornerX = -1;
	int m_bottomLeftCornerY = -1;
	int m_upRightCornerX = -1;
	int m_upRightCornerY = -1;

	/** was command invoked for all objects? */
	bool m_all = false;

	// commands validation
	bool validateCommandRange(const std::vector<std::string>& instructions);
	bool validateCommandBackground(const std::vector<std::string>& instructions);
	bool validateCommandLine(const std::vector<std::string>& instructions);
	bool validateCommandRectangle(const std::vector<std::string>& instructions);
	bool validateCommandCircle(const std::vector<std::string>& instructions);
	bool validateCommandEllipse(const std::vector<std::string>& instructions);
	bool validateCommandArc(const std::vector<std::string>& instructions);
	bool validateCommandFill(const std::vector<std::string>& instructions);
	bool validateCommandDelete(const std::vector<std::string>& instructions);
	bool validateCommandMove(const std::vector<std::string>& instructions);
	bool validateCommandRotate(const std::vector<std::string>& instructions);
	bool validateCommandShow(const std::vector<std::string>& instructions);
	bool validateCommandClear(const std::vector<std::string>& instructions);
	bool validateCommandWrite(const std::vector<std::string>& instructions);
	bool validateCommandRead(const std::vector<std::string>& instructions);
	bool validateCommandSave(const std::vector<std::string>& instructions);
	bool validateCommandClearcmd(const std::vector<std::string>& instructions);

	/**
	 * checks if number of arguments in instructions is equal to expected number
	 * @param std::vector<std::string>&
	 * @param unsigned
	 * @return bool
	 */
	bool checkNumberOfArguments(const std::vector<std::string>& instructions, unsigned expectedNumber1, unsigned expectedNumber2 = 0);

	/**
	 * check if argument dependencies are ok
	 * @return bool
	 */
	bool checkArgumentDependencies();

	/**
	 * converts instruction arguments to double (if possible)
	 * @param std::vector<std::string>&
	 * @param unsigned
	 * @return bool
	 */
	bool convertToInt(const std::vector<std::string>& instructions, unsigned argumentsNumber, unsigned start =1 );

	/**
	 * converts string with hexadecimal colour to rgb colour
	 * @param std::string
	 * @return bool
	 */
	bool convertToColour(const std::string& colour);

	/**
	 * check if point exists inside panel
	 * @param int
	 * @param int
	 * @return bool
	 */
	bool checkIfPointExists(int x, int y);

public:
	/** validates input string
	 * @param std::string
	 * @return bool
	 */
	bool validate(std::string input);

	/**
	 * returns ID of last entered command
	 * @return bool
	 */
	int getCommandID() const;

	/**
	 * returns help message
	 * @return std::string
	 */
	std::string getHelpMessage() const;

	/**
	 * returns values
	 * @return std::vector<double>&
	 */
	std::vector<int>& getValues();

	/**
	 * returns colour
	 * @return unsigned long
	 */
	unsigned long getColour() const;

	/**
	 * sets m_bottomLeftCorner and m_upRightCorner
	 * @param int
	 * @param int
	 * @param int
	 * @param int
	 */
	void setCorners(const Panel& panel);

	/**
	 * returns true if command was invoked for all
	 * false otherwise
	 * @return bool
	 */
	bool getAll();
};