#include "VectorGraphicsInterpreterGUI.h"

VectorGraphicsInterpreterGUI::VectorGraphicsInterpreterGUI( wxWindow* parent )
:
GUI( parent )
{

}

void VectorGraphicsInterpreterGUI::workspaceOnMotion( wxMouseEvent& event )
{
	long x, y;
	event.GetPosition(&x, &y);
	m_currentX = (double)x;
	m_currentY = (double)y;
	m_cursorPosition->SetLabel("   x = " + std::to_string(m_currentX) + "\n   y = " + std::to_string(m_currentY));
}

void VectorGraphicsInterpreterGUI::workspaceOnUpdateUI( wxUpdateUIEvent& event )
{
	Repaint();
}

void VectorGraphicsInterpreterGUI::consoleOnTextEnter( wxCommandEvent& event )
{
	Repaint();

	std::string input = static_cast<std::string>(m_console->GetValue());
	std::string delimeter = " ";
	std::string command = input.substr(0, input.find(delimeter));
	input.erase(0, input.find(delimeter) + delimeter.length());

	auto it = std::find(m_commands.begin(), m_commands.end(), command);
	int commandID = -1;
	if (it != m_commands.end()) {
		commandID = it - m_commands.begin();
	}


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

	dc.Clear();
	dc.SetBackground(wxColor(255, 255, 255));
	dc.SetBrush(wxBrush(wxColor(0, 0, 0)));
	dc.SetBackgroundMode(wxTRANSPARENT);
	dc.SetTextForeground(*wxBLACK);

	int w = 0;
	int h = 0;
	m_workspace->GetSize(&w, &h);

	//wypisujemy rozmiar wektora _shapes, zwieksza sie ilosc po kazdym wywolaniu komendy line
	std::string s1 = std::to_string(m_shapes.size());
	dc.DrawText(s1, 300, 200);
	std::string s2 = std::to_string(w);
	dc.DrawText(s2, 300, 300);


	int Sx = (double)w / (m_drawPanel.getRightUpPoint().getX() - m_drawPanel.getLeftDownPoint().getX());
	int Sy = (double)h / (m_drawPanel.getRightUpPoint().getY() - m_drawPanel.getLeftDownPoint().getY());

	//rysujemy po kolei kazdy obiekt
	for (Shape* shape : m_shapes) {
		shape->draw(&dc, Sx, Sy);
	}

}

void VectorGraphicsInterpreterGUI::commandClear(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandBackground(std::string instructions)
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

	Shape* firstLine = new Line(300, 100, 400, 500, wxColor(0, 64, 255));
	m_shapes.push_back(firstLine);

}

void VectorGraphicsInterpreterGUI::commandArc(std::string instructions)
{

}

void VectorGraphicsInterpreterGUI::commandFill(std::string instructions)
{

}