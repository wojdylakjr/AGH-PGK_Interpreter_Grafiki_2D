#include "VectorGraphicsInterpreterEllipseDialog.h"

VectorGraphicsInterpreterEllipseDialog::VectorGraphicsInterpreterEllipseDialog( wxWindow* parent )
:
EllipseDialog( parent )
{
	m_ellipse = nullptr;
}

VectorGraphicsInterpreterEllipseDialog::VectorGraphicsInterpreterEllipseDialog(wxWindow* parent, ShapeEllipse* ellipse) 
:
EllipseDialog(parent), m_ellipse(ellipse)
{
	m_objectName->SetLabel(wxString(m_ellipse->getName()));
	m_objectID->SetLabel(wxString("ID: " + std::to_string(m_ellipse->getId())));
	m_center->SetLabel(wxString("(" + std::to_string((int)m_ellipse->getCenter().getX()) + ", " + std::to_string((int)m_ellipse->getCenter().getY()) + ")"));
	m_horizontalShaft->SetLabel(wxString(std::to_string((int)m_ellipse->getShaft(true))));
	m_verticalShaft->SetLabel(wxString(std::to_string((int)m_ellipse->getShaft(false))));
	m_colour->SetLabel(wxString(m_ellipse->getHexadecimalColour(true)));
	m_fillColour->SetLabel(wxString(m_ellipse->getHexadecimalColour(false)));
	m_transformVector->SetLabel(wxString("(" + std::to_string((int)m_ellipse->getTransform().getX()) + ", " + std::to_string((int)m_ellipse->getTransform().getY()) + ")"));
	m_rotationAngle->SetLabel(wxString(std::to_string((int)m_ellipse->getRotationAngle())));
}

void VectorGraphicsInterpreterEllipseDialog::m_centerOnTextEnter( wxCommandEvent& event )
{
	if (m_validator.convertToPoint(std::string(m_center->GetLineText(0)))) {
		m_ellipse->setCenter(m_validator.getX(), m_validator.getY());
	}
	else {
		m_center->SetLabel(wxString("(" + std::to_string((int)m_ellipse->getCenter().getX()) + ", " + std::to_string((int)m_ellipse->getCenter().getY()) + ")"));
	}
}

void VectorGraphicsInterpreterEllipseDialog::m_horizontalShaftOnTextEnter( wxCommandEvent& event )
{
	try {
		int shaft = std::stoi(std::string(m_horizontalShaft->GetLineText(0)));
		m_ellipse->setShaft(shaft, true);
	}
	catch (const std::invalid_argument&) {
		m_horizontalShaft->SetLabel(wxString(std::to_string((int)m_ellipse->getShaft(true))));
	}
}

void VectorGraphicsInterpreterEllipseDialog::m_verticalShaftOnTextEnter( wxCommandEvent& event )
{
	try {
		int shaft = std::stoi(std::string(m_verticalShaft->GetLineText(0)));
		m_ellipse->setShaft(shaft, false);
	}
	catch (const std::invalid_argument&) {
		m_verticalShaft->SetLabel(wxString(std::to_string((int)m_ellipse->getShaft(false))));
	}
}

void VectorGraphicsInterpreterEllipseDialog::m_colourOnTextEnter(wxCommandEvent& event)
{
	if (m_validator.convertToColour(std::string(m_colour->GetLineText(0)))) {
		m_ellipse->setColour(wxColour(m_validator.getColour()));
	}
	else {
		m_colour->SetLabel(wxString(m_ellipse->getHexadecimalColour(true)));
	}
}

void VectorGraphicsInterpreterEllipseDialog::m_fillColourOnTextEnter(wxCommandEvent& event)
{
	if (m_validator.convertToColour(std::string(m_fillColour->GetLineText(0)))) {
		m_ellipse->setFillColour(wxColour(m_validator.getColour()));
	}
	else {
		m_fillColour->SetLabel(wxString(m_ellipse->getHexadecimalColour(true)));
	}
}

void VectorGraphicsInterpreterEllipseDialog::m_transformVectorOnTextEnter(wxCommandEvent& event)
{
	if (m_validator.convertToPoint(std::string(m_transformVector->GetLineText(0)))) {
		m_ellipse->setTransform(m_validator.getX(), m_validator.getY());
	}
	else {
		m_transformVector->SetLabel(wxString("(" + std::to_string((int)m_ellipse->getTransform().getX()) + ", " + std::to_string((int)m_ellipse->getTransform().getY()) + ")"));
	}
}

void VectorGraphicsInterpreterEllipseDialog::m_rotationAngleOnTextEnter(wxCommandEvent& event)
{
	try {
		int rAngle = std::stoi(std::string(m_rotationAngle->GetLineText(0)));
		m_ellipse->rotate(rAngle, m_ellipse->getRotateX(), m_ellipse->getRotateY());
	}
	catch (const std::invalid_argument&) {
		m_rotationAngle->SetLabel(wxString(std::to_string((int)m_ellipse->getRotationAngle())));
	}
}

void VectorGraphicsInterpreterEllipseDialog::m_deleteButtonOnButtonClick(wxCommandEvent& event)
{
	EndModal(101);
}
