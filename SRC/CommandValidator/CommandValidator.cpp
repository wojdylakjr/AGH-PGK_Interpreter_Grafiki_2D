#include "CommandValidator.h"
#include "StringSplit.h"

bool CommandValidator::validateCommandRange(const std::vector<std::string>& instructions) {
	
	if (!checkNumberOfArguments(instructions, 4u)) {
		return false;
	}

	if(!convertToInt(instructions, 4u)) {
		return false;
	}

	if (!checkArgumentDependencies()) {
		return false;
	}

	setCorners(m_values[0], m_values[1], m_values[2], m_values[3]);

	return true;	
}

bool CommandValidator::validateCommandBackground(const std::vector<std::string>& instructions) {
	
	if (!checkNumberOfArguments(instructions, 1u)) {
		return false;
	}

	if (!convertToColour(instructions[1])) {
		return false;
	}

	return true;
}

bool CommandValidator::validateCommandLine(const std::vector<std::string>& instructions) {

	if (!checkNumberOfArguments(instructions, 4u, 5u)) {
		return false;
	}	

	if(!convertToInt(instructions, 4u)) {
		return false;
	}

	if (!checkIfPointExists(m_values[0], m_values[1]) || !checkIfPointExists(m_values[2], m_values[3])) {
		return false;
	}

	if (instructions.size() - 1 == 5u) {
		if (!convertToColour(instructions[1])) {
			return false;
		}
	} else {
		m_colour = 0;
	}

	return true;

}

bool CommandValidator::validateCommandRectangle(const std::vector<std::string>& instructions) {
	
	if (!checkNumberOfArguments(instructions, 4u, 5u)) {
		return false;
	}	

	if(!convertToInt(instructions, 4u)) {
		return false;
	}

	if (!checkIfPointExists(m_values[0], m_values[1]) || !checkIfPointExists(m_values[2], m_values[3])) {
		return false;
	}

	if (instructions.size() - 1 == 5u) {
		if (!convertToColour(instructions[1])) {
			return false;
		}
	} else {
		m_colour = 0;
	}

	if (!checkArgumentDependencies()) {
		return false;
	} 

	return true;
}

bool CommandValidator::validateCommandCircle(const std::vector<std::string>& instructions) {
	return true;
}

bool CommandValidator::validateCommandEllipse(const std::vector<std::string>& instructions) {
	return true;
}

bool CommandValidator::validateCommandArc(const std::vector<std::string>& instructions) {
	return true;
}

bool CommandValidator::validateCommandFill(const std::vector<std::string>& instructions) {
	return true;
}

bool CommandValidator::validateCommandDelete(const std::vector<std::string>& instructions) {
	return true;
}

bool CommandValidator::validateCommandMove(const std::vector<std::string>& instructions) {
	return true;
}

bool CommandValidator::validateCommandRotate(const std::vector<std::string>& instructions) {
	return true;
}

bool CommandValidator::validateCommandShow(const std::vector<std::string>& instructions) {
	return true;
}

bool CommandValidator::validateCommandClear(const std::vector<std::string>& instructions) {
	return true;
}

bool CommandValidator::validateCommandWrite(const std::vector<std::string>& instructions) {
	return true;
}	

bool CommandValidator::validateCommandRead(const std::vector<std::string>& instructions) {
	return true;
}

bool CommandValidator::validateCommandSave(const std::vector<std::string>& instructions) {
	return true;
}

bool CommandValidator::validateCommandClearcmd(const std::vector<std::string>& instructions) {
	if (!checkNumberOfArguments(instructions, 0u)) {
		return false;
	}
	return true;
}

/* -------------------- */

bool CommandValidator::checkNumberOfArguments(const std::vector<std::string>& instructions, unsigned expectedNumber1, unsigned expectedNumber2) {
	if (expectedNumber2 == 0) {
		if (instructions.size() - 1 != expectedNumber1) {
			m_helpMessage = "\nWrong number of arguments! Expected: " + std::to_string(expectedNumber1)
			+ ", given: " + std::to_string(instructions.size() - 1) + "";
			return false;
		}
	} else {
		if (instructions.size() - 1 != expectedNumber1 && instructions.size() - 1 != expectedNumber2) {
			m_helpMessage = "\nWrong number of arguments! Expected: " + std::to_string(expectedNumber1)
			+ " or " + std::to_string(expectedNumber2) + ", given: " + std::to_string(instructions.size() - 1) + "";
			return false;
		}
	}
	return true;
}

bool CommandValidator::checkArgumentDependencies() {
	if (!(m_values[0] < m_values[2] && m_values[1] < m_values[3])) {
		m_helpMessage = "\nWrong arguments dependencies! Expected: x1 < x2, y1 < y2";
		return false;
	}
	return true;
}

bool CommandValidator::convertToInt(const std::vector<std::string>& instructions, unsigned argumentsNumber) {
	m_values.clear();
	for (unsigned i = 1; i <= argumentsNumber; i++) {
		try {
	        m_values.push_back(std::stoi(instructions[i]));
	    } catch (const std::invalid_argument&) {
	        m_helpMessage = "\nArgument at index " + std::to_string(i) + " is invalid! Expected int type";
	        return false;
	    }
	}
	return true;
}	

bool CommandValidator::convertToColour(const std::string& colour) {

	if(!regex_match(colour, m_pattern)) {
		m_helpMessage = "\nColour doesn`t match hexadecimal colour pattern! Valid example: \"#000000\"";
    	return false;
  	}

  	std::string c = colour.substr(1, colour.size() - 1);
	std::istringstream converter(c);
    converter >> std::hex >> m_colour;
    return true;
}

bool CommandValidator::checkIfPointExists(int x, int y) {
	if (x >= m_bottomLeftCornerX && x <= m_upRightCornerX
		&& y >= m_bottomLeftCornerY && y <= m_upRightCornerY) {
		return true;
	}
	m_helpMessage = "\nPoint (" + std::to_string(x) + ", " + std::to_string(y) + 
					") outside of panel, current Panel corners: (" + std::to_string(m_bottomLeftCornerX) + 
					", " + std::to_string(m_bottomLeftCornerY) + "), (" +
					std::to_string(m_upRightCornerX) +	", " + std::to_string(m_upRightCornerY) + ")";
	return false;
}

/* -------------------- */

bool CommandValidator::validate(std::string input) {

	if (input.empty()) {
		m_helpMessage = "";
		return false;
	}

	std::vector<std::string> instructions = StringSplit::split(input);
	std::string command = instructions[0];

	auto it = std::find(m_commands.begin(), m_commands.end(), command);
	m_commandID = -1;
	if (it != m_commands.end()) {
		m_commandID = it - m_commands.begin();
	}

	switch (m_commandID) {
	case -1:	// command doesn`t exist
		m_helpMessage = "\nCommand \"" + command + "\" doesn`t exist";
		return false;
	case 0:		// range
		return validateCommandRange(instructions);
	case 1:		// background
		return validateCommandBackground(instructions);
	case 2:		// line
		return validateCommandLine(instructions);
	case 3:		// rectangle
		return validateCommandRectangle(instructions);
	case 4:		// circle
		return validateCommandCircle(instructions);
	case 5:		// ellipse
		return validateCommandEllipse(instructions);
	case 6:		// arc
		return validateCommandArc(instructions);
	case 7:		// fill
		return validateCommandFill(instructions);
	case 8:		// delete
		return validateCommandDelete(instructions);
	case 9:		// move
		return validateCommandMove(instructions);
	case 10:	// rotate
		return validateCommandRotate(instructions);
	case 11:	// show
		return validateCommandShow(instructions);
	case 12:	// clear
		return validateCommandClear(instructions);
	case 13:	// write
		return validateCommandWrite(instructions);
	case 14:	// read
		return validateCommandRead(instructions);
	case 15:	// save
		return validateCommandSave(instructions);
	case 16:	// cmdclear
		return validateCommandClearcmd(instructions);
	default:
		m_helpMessage = "\nUnexpected error occured";
		return false;
	}
}

int CommandValidator::getCommandID() const {
	return m_commandID;
}

std::string CommandValidator::getHelpMessage() const {
	return m_helpMessage;
}

std::vector<int>& CommandValidator::getValues() {
	return m_values;
}

unsigned long CommandValidator::getColour() const {
	return m_colour;
}

void CommandValidator::setCorners(int x1, int y1, int x2, int y2) {
	m_bottomLeftCornerX = x1;
	m_bottomLeftCornerY = y1;
	m_upRightCornerX = x2;
	m_upRightCornerY = y2;
}