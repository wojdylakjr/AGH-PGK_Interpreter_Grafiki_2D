#include "VectorGraphicsInterpreterGUI.h"

VectorGraphicsInterpreterGUI::VectorGraphicsInterpreterGUI(wxWindow* parent)
	:
	GUI(parent)
{

}

void VectorGraphicsInterpreterGUI::m_workspaceOnMotion(wxMouseEvent& event)
{
	long x, y;
	event.GetPosition(&x, &y);
	m_currentX = (double)x;
	m_currentY = (double)y;
	m_cursorPosition->SetLabel("   x = " + std::to_string(m_currentX) + "\n   y = " + std::to_string(m_currentY));

}

void VectorGraphicsInterpreterGUI::m_workspaceOnUpdateUI(wxUpdateUIEvent& event)
{
	Repaint();
}

void VectorGraphicsInterpreterGUI::m_consoleOnTextEnter(wxCommandEvent& event)
{

	Repaint();

	std::string input = static_cast<std::string>(m_console->GetValue());
	std::string delimeter = " ";
	std::string command = input.substr(0, input.find(delimeter));
	//input.erase(0, input.find(delimeter) + delimeter.length());

	auto it = std::find(m_commands.begin(), m_commands.end(), command);
	int commandID = -1;
	if (it != m_commands.end()) {
		int commandID = it - m_commands.begin();
	}

	m_testCommand = std::to_string(commandID) + ": " + input;

	switch (commandID) {
	case -1:	// command doesn`t exist
		break;
	case 0:		// range
		commandRange(input);
		break;
	case 1:		// background
		commandBackground(input);
		break;
	case 2:		// line
		commandLine(input);
		break;
	case 3:		// rectangle
		commandRectangle(input);
		break;
	case 4:		// circle
		commandCircle(input);
		break;
	case 5:		// ellipse
		commandEllipse(input);
		break;
	case 6:		// arc
		commandArc(input);
		break;
	case 7:		// fill
		commandFill(input);
		break;
	case 8:		// delete
		commandDelete(input);
		break;
	case 9:		// move
		commandMove(input);
		break;
	case 10:	// rotate
		commandRotate(input);
		break;
	case 11:	// show
		commandShow(input);
		break;
	case 12:	// clear
		commandClear(input);
		break;
	case 13:	// write
		commandWrite(input);
		break;
	case 14:	// read
		commandRead(input);
		break;
	case 15:	//save
		commandSave(input);
		break;
	}
	Repaint();

}


void VectorGraphicsInterpreterGUI::commandEllipse(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandRotate(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandDelete(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandWrite(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandMove(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandRead(std::string instructions)
{

}
;
void VectorGraphicsInterpreterGUI::Repaint()
{
	wxCoord width, height;
	wxClientDC clientDc(m_workspace);
	clientDc.GetSize(&width, &height);
	m_picture = wxBitmap(width, height);
	wxBufferedDC dc(&clientDc, m_picture);
	width /= 2;
	height /= 2;
	dc.Clear();
	dc.SetBackground(wxColor(255, 255, 255));
	dc.SetBrush(wxBrush(wxColor(0, 1, 255)));

	// glowa
	dc.DrawCircle(width, height - 80, 50);
	dc.SetFont(wxFont(10, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_BOLD));
	dc.DrawText(wxString(m_testCommand), width - 150, height - 200);
	dc.DrawText(wxString("co u diabla"), width, height);
	dc.DrawText("co u diabla", width, height);


}

void VectorGraphicsInterpreterGUI::commandBackground(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandClear(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandSave(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandRectangle(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandShow(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandRange(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandCircle(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandLine(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandFill(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandArc(std::string instructions)
{

}