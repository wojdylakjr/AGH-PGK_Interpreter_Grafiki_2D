#include "VectorGraphicsInterpreterCircleDialog.h"

VectorGraphicsInterpreterCircleDialog::VectorGraphicsInterpreterCircleDialog( wxWindow* parent )
:
CircleDialog( parent )
{
	m_circle = nullptr;
}

VectorGraphicsInterpreterCircleDialog::VectorGraphicsInterpreterCircleDialog( wxWindow* parent, ShapeCircle* circle ) 
:
CircleDialog(parent), m_circle(circle)
{
	m_objectName->SetLabel(wxString(m_circle->getName()));
	m_objectID->SetLabel(wxString("ID: " + std::to_string(m_circle->getId())));
	m_center->SetLabel(wxString("(" + std::to_string((int)m_circle->getCenter().getX()) + ", " + std::to_string((int)m_circle->getCenter().getY()) + ")"));
	m_radius->SetLabel(wxString(std::to_string((int)m_circle->getRadius())));
	m_colour->SetLabel(wxString(m_circle->getHexadecimalColour(true)));
	m_fillColour->SetLabel(wxString(m_circle->getHexadecimalColour(false)));
	m_transformVector->SetLabel(wxString("(" + std::to_string((int)m_circle->getTransform().getX()) + ", " + std::to_string((int)m_circle->getTransform().getY()) + ")"));
	m_rotationAngle->SetLabel(wxString(std::to_string((int)m_circle->getInputRotationAngle())));
}

void VectorGraphicsInterpreterCircleDialog::m_centerOnTextEnter( wxCommandEvent& event )
{
	if (m_validator.convertToPoint(std::string(m_center->GetLineText(0)))) {
		m_circle->setCenter(m_validator.getX(), m_validator.getY());
	}
	else {
		m_center->SetLabel(wxString("(" + std::to_string((int)m_circle->getCenter().getX()) + ", " + std::to_string((int)m_circle->getCenter().getY()) + ")"));
	}
}

void VectorGraphicsInterpreterCircleDialog::m_radiusOnTextEnter( wxCommandEvent& event )
{
	try {
		int radius = std::stoi(std::string(m_radius->GetLineText(0)));
		m_circle->setRadius(radius);
	}
	catch (const std::invalid_argument&) {
		m_radius->SetLabel(wxString(std::to_string((int)m_circle->getRadius())));
	}
}

void VectorGraphicsInterpreterCircleDialog::m_colourOnTextEnter(wxCommandEvent& event)
{
	if (m_validator.convertToColour(std::string(m_colour->GetLineText(0)))) {
		m_circle->setColour(wxColour(m_validator.getColour()));
	}
	else {
		m_colour->SetLabel(wxString(m_circle->getHexadecimalColour(true)));
	}
}

void VectorGraphicsInterpreterCircleDialog::m_fillColourOnTextEnter(wxCommandEvent& event)
{
	if (m_validator.convertToColour(std::string(m_fillColour->GetLineText(0)))) {
		m_circle->setFillColour(wxColour(m_validator.getColour()));
	}
	else {
		m_fillColour->SetLabel(wxString(m_circle->getHexadecimalColour(true)));
	}
}

void VectorGraphicsInterpreterCircleDialog::m_transformVectorOnTextEnter(wxCommandEvent& event)
{
	if (m_validator.convertToPoint(std::string(m_transformVector->GetLineText(0)))) {
		m_circle->setTransform(m_validator.getX(), m_validator.getY());
	}
	else {
		m_transformVector->SetLabel(wxString("(" + std::to_string((int)m_circle->getTransform().getX()) + ", " + std::to_string((int)m_circle->getTransform().getY()) + ")"));
	}
}

void VectorGraphicsInterpreterCircleDialog::m_rotationAngleOnTextEnter(wxCommandEvent& event)
{
	try {
		int rAngle = std::stoi(std::string(m_rotationAngle->GetLineText(0)));
		m_circle->rotate(360.0 - rAngle, m_circle->getRotateX(), m_circle->getRotateY());
	}
	catch (const std::invalid_argument&) {
		m_rotationAngle->SetLabel(wxString(std::to_string((int)m_circle->getInputRotationAngle())));
	}
}

void VectorGraphicsInterpreterCircleDialog::m_deleteButtonOnButtonClick(wxCommandEvent& event)
{
	EndModal(101);
}
