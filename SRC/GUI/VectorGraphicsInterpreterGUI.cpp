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

	double Sx = (double)w / (m_drawPanel.getLeftDownPoint().getX() - m_drawPanel.getRightUpPoint().getX());
	double Sy = (double)h / (m_drawPanel.getLeftDownPoint().getY() - m_drawPanel.getRightUpPoint().getY());

	double X, Y;
	X = -(double)x / Sx + m_drawPanel.getLeftDownPoint().getX();
	Y = (double)y / Sy + m_drawPanel.getRightUpPoint().getY();

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
			shape->setInputRotationAngle(static_cast<double>(rotationCoordinates[3]));
			shape->rotate(360.0 - static_cast<double>(rotationCoordinates[2]), static_cast<double>(rotationCoordinates[0]), static_cast<double>(rotationCoordinates[1]));
		}
	}
	else {
		int id = rotationCoordinates[0];
		for (Shape* shape : m_shapes)
		{
			if (shape->getId() == id)
			{
				shape->setInputRotationAngle(static_cast<double>(rotationCoordinates[3]));
				shape->rotate(360.0 - static_cast<double>(rotationCoordinates[3]), static_cast<double>(rotationCoordinates[1]), static_cast<double>(rotationCoordinates[2]));
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
	wxBufferedDC dc(&clientDc, m_picture);
	
	dc.SetBackground(m_drawPanel.getBackgroundColor());
	dc.Clear();
	dc.SetBrush(wxBrush(wxColor(0, 0, 0)));
	dc.SetBackgroundMode(wxTRANSPARENT);
	dc.SetTextForeground(*wxBLACK);

	int w = 0;
	int h = 0;
	m_workspace->GetSize(&w, &h);

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
		Shape::setCounter(0);
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

void VectorGraphicsInterpreterGUI::updateObjectsList()
{
	m_objectsList->Clear();
	for (auto* shape : m_shapes) {
		std::string nameStr = shape->getName();
		char* name = new char[nameStr.size() + 1];
		name[nameStr.size()] = '\0';
		std::copy(nameStr.begin(), nameStr.end(), name);
		char buffer[50];
		if (sprintf(buffer, " %-17s %-4d", name, shape->getId())) {
			m_objectsList->Append(wxString(buffer));
		}
		delete[] name;
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

		int id;
		for (Shape* shape : m_shapes) {
			id = shape->getId();
			m_IDs.push_back(id);
			file << std::to_string(id) << " ";
		}
		file << "\n";

		file << "clear" << "\n";
		file << "range -5000 -5000 5000 5000 \n";

		for (Shape* shape : m_shapes) {
			file << shape->getParameters();
			file << "\n";

			if (!shape->isTransparent()) {
				m_fillCommands += "fill ";
				m_fillCommands += std::to_string(shape->getId());
				m_fillCommands += " ";
				m_fillCommands += shape->getHexadecimalColour(0);
				m_fillCommands += "\n";
			}

			m_rotateCommands += "rotate ";
			m_rotateCommands += std::to_string(shape->getId());
			m_rotateCommands += " ";
			m_rotateCommands += std::to_string(shape->getRotateX());
			m_rotateCommands += " ";
			m_rotateCommands += std::to_string(shape->getRotateY());
			m_rotateCommands += " ";
			m_rotateCommands += std::to_string(shape->getInputRotationAngle());
			m_rotateCommands += "\n";

			m_moveCommands += "move ";
			m_moveCommands += std::to_string(shape->getId());
			m_moveCommands += " ";
			m_moveCommands += std::to_string(shape->getTransform().getX());
			m_moveCommands += " ";
			m_moveCommands += std::to_string(shape->getTransform().getY());
			m_moveCommands += "\n";

		}
		file << m_fillCommands;
		file << m_moveCommands;
		file << m_rotateCommands;
		file << "range " << std::to_string((int)m_drawPanel.getLeftDownPoint().getX()) << " " << std::to_string((int)m_drawPanel.getLeftDownPoint().getY())
			 << " " << std::to_string((int)m_drawPanel.getRightUpPoint().getX()) << " " << std::to_string((int)m_drawPanel.getRightUpPoint().getY()) << "\n";
		file.close();
	}


}


void VectorGraphicsInterpreterGUI::commandRead()
{
	wxString file;
	wxFileDialog fdlog(this, _("Read data"), "", "", "xyz files (*.)|*.xyz");
	if (fdlog.ShowModal() != wxID_OK) return;
	file.Clear();
	file = fdlog.GetPath();

	wxString str;
	wxTextFile tfile;
	tfile.Open(file);


	m_shapesCounter = { 1, 1, 1, 1, 1 };
	m_fillCommands.clear();
	m_moveCommands.clear();
	m_rotateCommands.clear();
	m_IDs.clear();

	m_console->AppendText(static_cast<wxString>("\n"));
	str = tfile.GetFirstLine();
	m_commandValidator.getIDs(std::string(str), m_IDs);
	str = tfile.GetNextLine();
	int i = 0;
	while (!tfile.Eof())
	{

		if (!m_commandValidator.validate(static_cast<std::string>(str), true)) {
			m_console->AppendText(static_cast<wxString>(m_commandValidator.getHelpMessage()));
		}
		else {
			switch (m_commandValidator.getCommandID()) {
			case 0:	
				commandRange();
				break;
			case 2:	
				commandLine();
				m_shapes[i]->setID(m_IDs[i]);
				i++;
				break;
			case 3:		
				commandRectangle();
				m_shapes[i]->setID(m_IDs[i]);
				i++;
				break;
			case 4:		
				commandCircle();
				m_shapes[i]->setID(m_IDs[i]);
				i++;
				break;
			case 5:		
				commandEllipse();
				m_shapes[i]->setID(m_IDs[i]);
				i++;
				break;
			case 6:		
				commandArc();
				m_shapes[i]->setID(m_IDs[i]);
				i++;
				break;
			case 7:		
				commandFill();
				break;
			case 9:		
				commandMove();
				break;
			case 10:	
				commandRotate();
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
	Shape::setCounter(i);
	updateObjectsList();
	Repaint();

}


void VectorGraphicsInterpreterGUI::commandSave()
{
	std::vector<int> coordinates = m_commandValidator.getValues();
	m_bitMapWidth = coordinates[0];
	m_bitMapHeight = coordinates[1];
	wxFileDialog dialog(this, _("Save image"), "", "", "bmp files (*.)|*.bmp", wxFD_SAVE | wxFD_OVERWRITE_PROMPT);
	m_picture = wxBitmap(m_bitMapWidth, m_bitMapHeight);
	if (dialog.ShowModal() == wxID_OK)
	{
		wxMemoryDC mdc(m_picture);
		mdc.SetBackground(m_drawPanel.getBackgroundColor());
		mdc.Clear();
		mdc.SetBrush(wxBrush(wxColor(0, 0, 0)));
		mdc.SetBackgroundMode(wxTRANSPARENT);
		wxBufferedDC dc(&mdc, m_picture);
		for (Shape* shape : m_shapes) {
			shape->draw(&dc, m_bitMapWidth, m_bitMapHeight, m_drawPanel);
		}
		wxString path = dialog.GetPath() + dialog.GetName();
		m_picture.SaveFile(path, wxBITMAP_TYPE_BMP);
	}
}