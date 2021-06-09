#include "VectorGraphicsInterpreterGUI.h"

VectorGraphicsInterpreterGUI::VectorGraphicsInterpreterGUI(wxWindow* parent)
	:
	GUI(parent)
{
	m_commandValidator.setCorners(m_drawPanel);
}

VectorGraphicsInterpreterGUI::~VectorGraphicsInterpreterGUI() {
	for (auto* shape : m_shapes) {
		delete shape;
	}
}

void VectorGraphicsInterpreterGUI::workspaceOnMotion(wxMouseEvent& event)
{
	long x, y;
	event.GetPosition(&x, &y);
	int w, h;
	m_workspace->GetSize(&w, &h);

	//double Sx = (double)w / (m_drawPanel.getRightUpPoint().getX() - m_drawPanel.getLeftDownPoint().getX());
	//double Sy = (double)h / (m_drawPanel.getRightUpPoint().getY() - m_drawPanel.getLeftDownPoint().getY());

	double Sx = (double)w / (m_drawPanel.getLeftDownPoint().getX() - m_drawPanel.getRightUpPoint().getX());
	double Sy = (double)h / (m_drawPanel.getLeftDownPoint().getY() - m_drawPanel.getRightUpPoint().getY());

	double X, Y;
	//X = (double)x / Sx + m_drawPanel.getLeftDownPoint().getX();
	//Y = (double)y / Sy + m_drawPanel.getLeftDownPoint().getY();

	X = -(double)x / Sx + m_drawPanel.getLeftDownPoint().getX();
	Y = (double)y / Sy + m_drawPanel.getRightUpPoint().getY();

	//X = floor(100 * X) / 100;
	//Y = floor(100 * Y) / 100;
	m_cursorPosition->SetLabel("    x = " + std::to_string((int)X) + "\n    y = " + std::to_string((int)Y));
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

void VectorGraphicsInterpreterGUI::m_objectsListOnLeaveWindow(wxMouseEvent& event) 
{
	m_objectsList->SetSelection(-1);
}

void VectorGraphicsInterpreterGUI::m_objectsListOnListBox(wxCommandEvent& event)
{
	std::string selection = m_objectsList->GetString(m_objectsList->GetSelection());
	int id = std::stoi(selection.substr(19, 4));
	show(id);
}

void VectorGraphicsInterpreterGUI::OnRightDown(wxMouseEvent& event)
{
	if (m_objectsList->GetSelection() == wxNOT_FOUND) {
		return;
	}
	std::string selection = m_objectsList->GetString(m_objectsList->GetSelection());
	int id = std::stoi(selection.substr(19, 4));
	int index = 0;
	Shape* selectedShape = nullptr;
	for (auto* shape : m_shapes)
	{

		if (shape->getId() == id)
		{
			selectedShape = shape;
			break;
		}
		index++;
	}

	switch (selectedShape->hashName()) {
	case line: {
		VectorGraphicsInterpreterLineDialog dialog(this, dynamic_cast<ShapeLine*>(selectedShape));
		if (dialog.ShowModal() == 101) {
			delete selectedShape;
			m_shapes.erase(m_shapes.begin() + index);
			m_objectsList->Delete(index);
		}
		break;
	}
	case rectangle: {
		VectorGraphicsInterpreterRectangleDialog dialog(this, dynamic_cast<ShapeRectangle*>(selectedShape));
		if (dialog.ShowModal() == 101) {
			delete selectedShape;
			m_shapes.erase(m_shapes.begin() + index);
			m_objectsList->Delete(index);
		}
		break;
	}
	case circle: {
		VectorGraphicsInterpreterCircleDialog dialog(this, dynamic_cast<ShapeCircle*>(selectedShape));
		if (dialog.ShowModal() == 101) {
			delete selectedShape;
			m_shapes.erase(m_shapes.begin() + index);
			m_objectsList->Delete(index);
		}
		break;
	}
	case ellipse: {
		VectorGraphicsInterpreterEllipseDialog dialog(this, dynamic_cast<ShapeEllipse*>(selectedShape));
		if (dialog.ShowModal() == 101) {
			delete selectedShape;
			m_shapes.erase(m_shapes.begin() + index);
			m_objectsList->Delete(index);
		}
		break;
	}
		break;
	case arc: {
		VectorGraphicsInterpreterArcDialog dialog(this, dynamic_cast<ShapeArc*>(selectedShape));
		if (dialog.ShowModal() == 101) {
			delete selectedShape;
			m_shapes.erase(m_shapes.begin() + index);
			m_objectsList->Delete(index);
		}
		break;
	}
	default:
		break;
	}


	Repaint();

}

void VectorGraphicsInterpreterGUI::commandEllipse()
{
	std::vector<int> coordinates = m_commandValidator.getValues();
	Shape* firstEllipse = new ShapeEllipse(coordinates[0], coordinates[1], coordinates[2], coordinates[3], m_commandValidator.getColour());
	firstEllipse->setName("Ellipse_" + std::to_string(m_shapesCounter[3]++));
	m_shapes.push_back(firstEllipse);
	std::string nameStr = firstEllipse->getName();
	char* name = new char[nameStr.size() + 1];
	name[nameStr.size()] = '\0';
	std::copy(nameStr.begin(), nameStr.end(), name);
	char buffer[50];
	if (sprintf(buffer, " %-17s %-4d", name, firstEllipse->getId())) {
		m_objectsList->Append(wxString(buffer));
	}
	delete[] name;
}

void VectorGraphicsInterpreterGUI::commandRotate()
{
	std::vector<int> rotationCoordinates = m_commandValidator.getValues();
	if (m_commandValidator.getAll()) {
		for (Shape* shape : m_shapes)
		{
			shape->rotate(rotationCoordinates[2], rotationCoordinates[0], rotationCoordinates[1]);
		}
	}
	else {
		int id = rotationCoordinates[0];
		for (Shape* shape : m_shapes)
		{
			if (shape->getId() == id)
			{
				shape->rotate(rotationCoordinates[3], rotationCoordinates[1], rotationCoordinates[2]);
				return;
			}
		}
		m_console->AppendText("\nObject with id " + std::to_string(id) + " doesn`t exist!");
	}	
}

void VectorGraphicsInterpreterGUI::commandDelete()
{
	if (m_commandValidator.getAll()) {
		for (auto* shape : m_shapes) {
			delete shape;
		}
		m_shapes.clear();
	}
	else {
		int id = m_commandValidator.getValues()[0];
		int index = -1;
		for (auto* shape : m_shapes) {
			index++;
			if (shape->getId() == id) {
				delete shape;
				m_shapes.erase(m_shapes.begin() + index);
				m_objectsList->Delete(index);
				return;
			}
		}
		m_console->AppendText("\nObject with id " + std::to_string(id) + " doesn`t exist!");
	}
}


void VectorGraphicsInterpreterGUI::commandMove()
{
	std::vector<int> moveCoordinates = m_commandValidator.getValues();
	if (m_commandValidator.getAll()) {
		for (Shape* shape : m_shapes)
		{
			shape->transform(moveCoordinates[0], moveCoordinates[1]);
		}
	}
	else {
		int id = moveCoordinates[0];
		for (Shape* shape : m_shapes)
		{
			if (shape->getId() == id)
			{
				shape->transform(moveCoordinates[1], moveCoordinates[2]);
				return;
			}
		}
		m_console->AppendText("\nObject with id " + std::to_string(id) + " doesn`t exist!");
	}
}



void VectorGraphicsInterpreterGUI::Repaint()
{
	wxCoord width, height;
	wxClientDC clientDc(m_workspace);
	clientDc.GetSize(&width, &height);
	m_picture = wxBitmap(width, height);
	//
	wxBufferedDC dc(&clientDc, m_picture);

	m_picture = dc.GetSelectedBitmap();

	
	

	dc.SetBackground(m_drawPanel.getBackgroundColor());
	dc.Clear();
	//dc.SetBackground(wxColor(255, 255, 255));
	dc.SetBrush(wxBrush(wxColor(0, 0, 0)));
	dc.SetBackgroundMode(wxTRANSPARENT);
	dc.SetTextForeground(*wxBLACK);

	int w = 0;
	int h = 0;
	m_workspace->GetSize(&w, &h);

	//wypisujemy rozmiar wektora _shapes, zwieksza sie ilosc po kazdym wywolaniu komendy line
	std::string s1 = std::to_string(m_shapes.size());
	dc.DrawText(s1, 300, 200);
	std::vector<int> testValues = m_commandValidator.getValues();
	//std::string s2 = std::to_string(w);
	if (testValues.size() > 0) {
		std::string s2 = std::to_string(testValues[0]);
		dc.DrawText(s2, 300, 300);
	}
	std::string s3 = std::to_string(w);
	dc.DrawText(s3, 300, 500);
	std::string s4 = std::to_string(h);
	dc.DrawText(s4, 400, 500);



	//rysujemy po kolei kazdy obiekt
	for (Shape* shape : m_shapes) {
		shape->draw(&dc, w, h, m_drawPanel);
	}
	
	
}

void VectorGraphicsInterpreterGUI::commandClearcmd()
{
	m_console->Clear();
}

void VectorGraphicsInterpreterGUI::commandClear()
{
	if (!m_shapes.empty()) {
		dynamic_cast<Shape*>(m_shapes[0])->setCounterToZero();
		for (auto* shape : m_shapes) {
			delete shape;
		}
	}
	m_shapes.clear();
	m_objectsList->Clear();
	m_drawPanel.updateCoordinates(0, 0, 1, 1);
}

void VectorGraphicsInterpreterGUI::commandBackground()
{
	m_drawPanel.setBackgroundColor(m_commandValidator.getColour());
}



void VectorGraphicsInterpreterGUI::commandRectangle()
{
	std::vector<int> coordinates = m_commandValidator.getValues();
	Shape* firstRectangle = new ShapeRectangle(coordinates[0], coordinates[1], coordinates[2], coordinates[3], m_commandValidator.getColour());
	firstRectangle->setName("Rectangle_" + std::to_string(m_shapesCounter[1]++));
	m_shapes.push_back(firstRectangle);
	std::string nameStr = firstRectangle->getName();
	char* name = new char[nameStr.size() + 1];
	name[nameStr.size()] = '\0';
	std::copy(nameStr.begin(), nameStr.end(), name);
	char buffer[50];
	if (sprintf(buffer, " %-17s %-4d", name, firstRectangle->getId())) {
		m_objectsList->Append(wxString(buffer));
	}
	delete[] name;
}

void VectorGraphicsInterpreterGUI::commandShow()
{
	if (m_commandValidator.getAll()) {
		show(-1);
	}
	else {
		show(m_commandValidator.getValues()[0]);
	}
}

void VectorGraphicsInterpreterGUI::commandRange()
{
	std::vector<int> coordinates = m_commandValidator.getValues();
	m_drawPanel.updateCoordinates(coordinates[0], coordinates[1], coordinates[2], coordinates[3]);
	m_commandValidator.setCorners(m_drawPanel);
}

void VectorGraphicsInterpreterGUI::commandCircle()
{
	std::vector<int> coordinates = m_commandValidator.getValues();
	Shape* firstCircle = new ShapeCircle(coordinates[0], coordinates[1], coordinates[2], m_commandValidator.getColour());
	firstCircle->setName("Circle_" + std::to_string(m_shapesCounter[2]++));
	m_shapes.push_back(firstCircle);
	std::string nameStr = firstCircle->getName();
	char* name = new char[nameStr.size() + 1];
	name[nameStr.size()] = '\0';
	std::copy(nameStr.begin(), nameStr.end(), name);
	char buffer[50];
	if (sprintf(buffer, " %-17s %-4d", name, firstCircle->getId())) {
		m_objectsList->Append(wxString(buffer));
	}
	delete[] name;
}

void VectorGraphicsInterpreterGUI::commandLine()
{

	std::vector<int> coordinates = m_commandValidator.getValues();
	Shape* firstLine = new ShapeLine(coordinates[0], coordinates[1], coordinates[2], coordinates[3], m_commandValidator.getColour());
	firstLine->setName("Line_" + std::to_string(m_shapesCounter[0]++));
	m_shapes.push_back(firstLine);
	std::string nameStr = firstLine->getName();
	char* name = new char[nameStr.size() + 1];
	name[nameStr.size()] = '\0';
	std::copy(nameStr.begin(), nameStr.end(), name);
	char buffer[50];
	if (sprintf(buffer, " %-17s %-4d", name, firstLine->getId())) {
		m_objectsList->Append(wxString(buffer));
		
	}
	delete[] name;

}

void VectorGraphicsInterpreterGUI::commandArc()
{
	std::vector<int> coordinates = m_commandValidator.getValues();
	Shape* firstArc = new ShapeArc(coordinates[0], coordinates[1], coordinates[2], coordinates[3], coordinates[4], coordinates[5], m_commandValidator.getColour());
	firstArc->setName("Arc_" + std::to_string(m_shapesCounter[4]++));
	m_shapes.push_back(firstArc);
	std::string nameStr = firstArc->getName();
	char* name = new char[nameStr.size() + 1];
	name[nameStr.size()] = '\0';
	std::copy(nameStr.begin(), nameStr.end(), name);
	char buffer[50];
	if (sprintf(buffer, " %-17s %-4d", name, firstArc->getId())) {
		m_objectsList->Append(wxString(buffer));

	}
	delete[] name;
}

void VectorGraphicsInterpreterGUI::commandFill()
{
	if (m_commandValidator.getAll()) {
		for (auto* shape : m_shapes) {
			if (shape->getTypeName() != "arc" && shape->getTypeName() != "line") {
				shape->setFillColour(m_commandValidator.getColour());
			}
		}
	}
	else {
		int id = m_commandValidator.getValues()[0];
		for (auto* shape : m_shapes) {
			if (shape->getId() == id) {
				if (shape->getTypeName() != "arc" && shape->getTypeName() != "line") {
					shape->setFillColour(m_commandValidator.getColour());
				}
				else {
					m_console->AppendText("\nObject \"" + shape->getTypeName() + "\" can`t be filled !");
				}
				return;
			}
		}
		m_console->AppendText("\nObject with id " + std::to_string(id) + " doesn`t exist!");
	}
}

void VectorGraphicsInterpreterGUI::show(int id)
{
	if (id == -1) {
		for (auto* shape : m_shapes) {
			shape->highlight();
		}
		Repaint();
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		for (auto* shape : m_shapes) {
			shape->darken();
		}
		Repaint();
	}
	else {
		for (auto* shape : m_shapes) {
			if (shape->getId() == id) {
				shape->highlight();
				Repaint();
				std::this_thread::sleep_for(std::chrono::milliseconds(500));
				shape->darken();
				Repaint();
				return;
			}
		}
		m_console->AppendText("\nObject with id " + std::to_string(id) + " doesn`t exist!");
	}
}

void VectorGraphicsInterpreterGUI::commandWrite()
{
	wxFileDialog dialog(this, _("Save data"), "", "", "xyz files (*.)|*.xyz", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);

	if (dialog.ShowModal() == wxID_OK)
	{
		this->Refresh();
		wxString path = dialog.GetPath() + dialog.GetName();
		std::ofstream file(path.ToStdString());
		file << "clear" << "\n";
		file << "range " << std::to_string((int)m_drawPanel.getLeftDownPoint().getX()) << " " << std::to_string((int)m_drawPanel.getLeftDownPoint().getY()) 
			<< " " << std::to_string((int)m_drawPanel.getRightUpPoint().getX()) << " " << std::to_string((int)m_drawPanel.getRightUpPoint().getY()) << "\n";

		for (Shape* shape : m_shapes) {
			file << shape->getParameters();
			file << "\n";
		}
		file.close();
	}


}


void VectorGraphicsInterpreterGUI::commandRead()
{
	wxString        file;
	wxFileDialog fdlog(this, _("Read data"), "", "", "xyz files (*.)|*.xyz");
	if (fdlog.ShowModal() != wxID_OK) return;
	file.Clear();
	file = fdlog.GetPath();

	wxString str;
	wxTextFile tfile;
	tfile.Open(file);

	m_console->AppendText(static_cast<wxString>("\n"));
	str = tfile.GetFirstLine();
	while (!tfile.Eof())
	{

		if (!m_commandValidator.validate(static_cast<std::string>(str))) {
			m_console->AppendText(static_cast<wxString>(m_commandValidator.getHelpMessage()));
		}
		else {
			switch (m_commandValidator.getCommandID()) {
			case 0:	
				commandRange();
				break;
			case 2:	
				commandLine();
				break;
			case 3:		
				commandRectangle();
				break;
			case 4:		
				commandCircle();
				break;
			case 5:		
				commandEllipse();
				break;
			case 6:		
				commandArc();
				break;
			case 12:
				commandClear();
				break;
			default:
				break;
			}
			
		}
		
		str = tfile.GetNextLine();
	}
	Repaint();

}


void VectorGraphicsInterpreterGUI::commandSave()
{
	//// TODO: Implement saveImageMenuItemSelected
	std::vector<int> coordinates = m_commandValidator.getValues();
	m_bitMapWidth = coordinates[0];
	m_bitMapHeight = coordinates[1];
	wxFileDialog dialog(this, _("Save image"), "", "", "bmp files (*.)|*.bmp", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	//m_picture = wxBitmap(m_bitMapWidth, m_bitMapHeight);

	if (dialog.ShowModal() == wxID_OK)
	{
		this->Refresh();
		wxString path = dialog.GetPath() + dialog.GetName();

		int w, h;
		wxImage screenBufferImg = m_picture.ConvertToImage();
		//screenBufferImg = screenBufferImg.Rescale(m_bitMapWidth, m_bitMapHeight);

		m_picture.SaveFile(path, wxBITMAP_TYPE_BMP);
		screenBufferImg.SaveFile(path, wxBITMAP_TYPE_BMP);
	}
	
}
