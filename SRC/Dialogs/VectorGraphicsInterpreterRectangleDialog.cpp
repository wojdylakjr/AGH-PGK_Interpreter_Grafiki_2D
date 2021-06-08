#include "VectorGraphicsInterpreterRectangleDialog.h"

VectorGraphicsInterpreterRectangleDialog::VectorGraphicsInterpreterRectangleDialog( wxWindow* parent )
:
RectangleDialog( parent )
{
	m_rectangle = nullptr;
}

VectorGraphicsInterpreterRectangleDialog::VectorGraphicsInterpreterRectangleDialog(wxWindow* parent, ShapeRectangle* rectangle)
	:
	RectangleDialog(parent), m_rectangle(rectangle)
{
	m_objectName->SetLabel(wxString(m_rectangle->getName()));
	m_objectID->SetLabel(wxString("ID: " + std::to_string(m_rectangle->getId())));
	m_bottomLeft->SetLabel(wxString("(" + std::to_string((int)m_rectangle->getPoint(true).getX()) + ", " + std::to_string((int)m_rectangle->getPoint(true).getY()) + ")"));
	m_topRight->SetLabel(wxString("(" + std::to_string((int)m_rectangle->getPoint(false).getX()) + ", " + std::to_string((int)m_rectangle->getPoint(false).getY()) + ")"));
	m_colour->SetLabel(wxString(m_rectangle->getHexadecimalColour(true)));
	m_fillColour->SetLabel(wxString(m_rectangle->getHexadecimalColour(false)));
	m_transformVector->SetLabel(wxString("(" + std::to_string((int)m_rectangle->getTransform().getX()) + ", " + std::to_string((int)m_rectangle->getTransform().getY()) + ")"));
	m_rotationAngle->SetLabel(wxString(std::to_string((int)m_rectangle->getRotationAngle())));
}

void VectorGraphicsInterpreterRectangleDialog::m_startPointOnTextEnter( wxCommandEvent& event )
{
	if (m_validator.convertToPoint(std::string(m_bottomLeft->GetLineText(0)))) {
		m_rectangle->setPoint(m_validator.getX(), m_validator.getY(), true);
	}
	else {
		m_bottomLeft->SetLabel(wxString("(" + std::to_string((int)m_rectangle->getPoint(true).getX()) + ", " + std::to_string((int)m_rectangle->getPoint(true).getY()) + ")"));
	}
}

void VectorGraphicsInterpreterRectangleDialog::m_endPointOnTextEnter( wxCommandEvent& event )
{
	if (m_validator.convertToPoint(std::string(m_topRight->GetLineText(0)))) {
		m_rectangle->setPoint(m_validator.getX(), m_validator.getY(), false);
	}
	else {
		m_topRight->SetLabel(wxString("(" + std::to_string((int)m_rectangle->getPoint(false).getX()) + ", " + std::to_string((int)m_rectangle->getPoint(false).getY()) + ")"));
	}
}

void VectorGraphicsInterpreterRectangleDialog::m_colourOnTextEnter( wxCommandEvent& event )
{
	if (m_validator.convertToColour(std::string(m_colour->GetLineText(0)))) {
		m_rectangle->setColour(wxColour(m_validator.getColour()));
	}
	else {
		m_colour->SetLabel(wxString(m_rectangle->getHexadecimalColour(true)));
	}
}

void VectorGraphicsInterpreterRectangleDialog::m_fillColourOnTextEnter(wxCommandEvent& event)
{
	if (m_validator.convertToColour(std::string(m_fillColour->GetLineText(0)))) {
		m_rectangle->setFillColour(wxColour(m_validator.getColour()));
	}
	else {
		m_fillColour->SetLabel(wxString(m_rectangle->getHexadecimalColour(true)));
	}
}

void VectorGraphicsInterpreterRectangleDialog::m_transformVectorOnTextEnter( wxCommandEvent& event )
{
	if (m_validator.convertToPoint(std::string(m_transformVector->GetLineText(0)))) {
		m_rectangle->setTransform(m_validator.getX(), m_validator.getY());
	}
	else {
		m_transformVector->SetLabel(wxString("(" + std::to_string((int)m_rectangle->getTransform().getX()) + ", " + std::to_string((int)m_rectangle->getTransform().getY()) + ")"));
	}
}

void VectorGraphicsInterpreterRectangleDialog::m_rotationAngleOnTextEnter( wxCommandEvent& event )
{
	try {
		int rAngle = std::stoi(std::string(m_rotationAngle->GetLineText(0)));
		m_rectangle->rotate(rAngle, m_rectangle->getRotateX(), m_rectangle->getRotateY());
	}
	catch (const std::invalid_argument&) {
		m_rotationAngle->SetLabel(wxString(std::to_string((int)m_rectangle->getRotationAngle())));
	}
}

void VectorGraphicsInterpreterRectangleDialog::m_deleteButtonOnButtonClick( wxCommandEvent& event )
{
	EndModal(101);
}
