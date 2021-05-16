#include "VectorGraphicsInterpreterGUI.h"

VectorGraphicsInterpreterGUI::VectorGraphicsInterpreterGUI( wxWindow* parent )
:
GUI( parent )
{
	m_commandValidator.setCorners(0, 0, 700, 600);
}

void VectorGraphicsInterpreterGUI::workspaceOnMotion( wxMouseEvent& event )
{
	long x, y;
	event.GetPosition(&x, &y);
	m_currentX = x;
	m_currentY = y;
	m_cursorPosition->SetLabel(" x = " + std::to_string(m_currentX) + "\n y = " + std::to_string(m_currentY));
}

void VectorGraphicsInterpreterGUI::workspaceOnUpdateUI( wxUpdateUIEvent& event )
{
	Repaint();
}

void VectorGraphicsInterpreterGUI::consoleOnTextEnter(wxCommandEvent& event)
{
	if (!m_commandValidator.validate(static_cast<std::string>(m_console->GetLineText(m_console->GetNumberOfLines() - 1)))) {
		m_console->AppendText(static_cast<wxString>(m_commandValidator.getHelpMessage()));
	}
	else {
		switch (m_commandValidator.getCommandID()) {
		case 0:		// range
			commandRange();
			break;
		case 1:		// background
			commandBackground();
			break;
		case 2:		// line
			commandLine();
			break;
		case 3:		// rectangle
			commandRectangle();
			break;
		case 4:		// circle
			commandCircle();
			break;
		case 5:		// ellipse
			commandEllipse();
			break;
		case 6:		// arc
			commandArc();
			break;
		case 7:		// fill
			commandFill();
			break;
		case 8:		// delete
			commandDelete();
			break;
		case 9:		// move
			commandMove();
			break;
		case 10:	// rotate
			commandRotate();
			break;
		case 11:	// show
			commandShow();
			break;
		case 12:	// clear
			commandClear();
			break;
		case 13:	// write
			commandWrite();
			break;
		case 14:	// read
			commandRead();
			break;
		case 15:	// save
			commandSave();
			break;
		case 16:	// cmdclear
			commandClearcmd();
			break;
		default:
			break;
		}
		Repaint();
	}
}

void VectorGraphicsInterpreterGUI::commandEllipse()
{

}

void VectorGraphicsInterpreterGUI::commandRotate()
{

}

void VectorGraphicsInterpreterGUI::commandDelete()
{

}

void VectorGraphicsInterpreterGUI::commandWrite()
{

}

void VectorGraphicsInterpreterGUI::commandMove()
{

}

void VectorGraphicsInterpreterGUI::commandRead()
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

void VectorGraphicsInterpreterGUI::commandClearcmd()
{
	m_console->Clear();
}

void VectorGraphicsInterpreterGUI::commandClear()
{

}

void VectorGraphicsInterpreterGUI::commandBackground()
{

}

void VectorGraphicsInterpreterGUI::commandSave()
{

}

void VectorGraphicsInterpreterGUI::commandRectangle()
{

}

void VectorGraphicsInterpreterGUI::commandShow()
{

}

void VectorGraphicsInterpreterGUI::commandRange()
{

}

void VectorGraphicsInterpreterGUI::commandCircle()
{

}

void VectorGraphicsInterpreterGUI::commandLine()
{

	Shape* firstLine = new Line(300, 100, 400, 500, wxColor(0, 64, 255));
	m_shapes.push_back(firstLine);

}

void VectorGraphicsInterpreterGUI::commandArc()
{

}

void VectorGraphicsInterpreterGUI::commandFill()
{

}