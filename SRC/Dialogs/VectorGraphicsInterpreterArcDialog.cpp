#include "VectorGraphicsInterpreterArcDialog.h"

VectorGraphicsInterpreterArcDialog::VectorGraphicsInterpreterArcDialog( wxWindow* parent )
:
ArcDialog( parent )
{
	m_arc = nullptr;
}

VectorGraphicsInterpreterArcDialog::VectorGraphicsInterpreterArcDialog(wxWindow* parent, ShapeArc* arc)
:
ArcDialog(parent), m_arc(arc)
{
	m_objectName->SetLabel(wxString(m_arc->getName()));
	m_objectID->SetLabel(wxString("ID: " + std::to_string(m_arc->getId())));
	m_center->SetLabel(wxString("(" + std::to_string((int)m_arc->getCenter().getX()) + ", " + std::to_string((int)m_arc->getCenter().getY()) + ")"));
	m_horizontalShaft->SetLabel(wxString(std::to_string((int)m_arc->getShaft(true))));
	m_verticalShaft->SetLabel(wxString(std::to_string((int)m_arc->getShaft(false))));
	m_startAngle->SetLabel(wxString(std::to_string((int)m_arc->getAngle(true))));
	m_stopAngle->SetLabel(wxString(std::to_string((int)m_arc->getAngle(false))));
	m_colour->SetLabel(wxString(m_arc->getHexadecimalColour(true)));
	m_transformVector->SetLabel(wxString("(" + std::to_string((int)m_arc->getTransform().getX()) + ", " + std::to_string((int)m_arc->getTransform().getY()) + ")"));
	m_rotationAngle->SetLabel(wxString(std::to_string((int)m_arc->getRotationAngle())));
}

void VectorGraphicsInterpreterArcDialog::m_centerOnTextEnter( wxCommandEvent& event )
{
	if (m_validator.convertToPoint(std::string(m_center->GetLineText(0)))) {
		m_arc->setCenter(m_validator.getX(), m_validator.getY());
	}
	else {
		m_center->SetLabel(wxString("(" + std::to_string((int)m_arc->getCenter().getX()) + ", " + std::to_string((int)m_arc->getCenter().getY()) + ")"));
	}
}

void VectorGraphicsInterpreterArcDialog::m_horizontalShaftOnTextEnter(wxCommandEvent& event)
{
	try {
		int shaft = std::stoi(std::string(m_horizontalShaft->GetLineText(0)));
		m_arc->setShaft(shaft, true);
	}
	catch (const std::invalid_argument&) {
		m_horizontalShaft->SetLabel(wxString(std::to_string((int)m_arc->getShaft(true))));
	}
}

void VectorGraphicsInterpreterArcDialog::m_verticalShaftOnTextEnter(wxCommandEvent& event)
{
	try {
		int shaft = std::stoi(std::string(m_verticalShaft->GetLineText(0)));
		m_arc->setShaft(shaft, false);
	}
	catch (const std::invalid_argument&) {
		m_verticalShaft->SetLabel(wxString(std::to_string((int)m_arc->getShaft(false))));
	}
}

void VectorGraphicsInterpreterArcDialog::m_startAngleOnTextEnter( wxCommandEvent& event )
{
	try {
		int angle = std::stoi(std::string(m_startAngle->GetLineText(0)));
		m_arc->setAngle(angle, true);
	}
	catch (const std::invalid_argument&) {
		m_startAngle->SetLabel(wxString(std::to_string((int)m_arc->getAngle(true))));
	}
}

void VectorGraphicsInterpreterArcDialog::m_stopAngleOnTextEnter( wxCommandEvent& event )
{
	try {
		int angle = std::stoi(std::string(m_stopAngle->GetLineText(0)));
		m_arc->setAngle(angle, false);
	}
	catch (const std::invalid_argument&) {
		m_stopAngle->SetLabel(wxString(std::to_string((int)m_arc->getAngle(false))));
	}
}

void VectorGraphicsInterpreterArcDialog::m_colourOnTextEnter(wxCommandEvent& event)
{
	if (m_validator.convertToColour(std::string(m_colour->GetLineText(0)))) {
		m_arc->setColour(wxColour(m_validator.getColour()));
	}
	else {
		m_colour->SetLabel(wxString(m_arc->getHexadecimalColour(true)));
	}
}

void VectorGraphicsInterpreterArcDialog::m_transformVectorOnTextEnter(wxCommandEvent& event)
{
	if (m_validator.convertToPoint(std::string(m_transformVector->GetLineText(0)))) {
		m_arc->setTransform(m_validator.getX(), m_validator.getY());
	}
	else {
		m_transformVector->SetLabel(wxString("(" + std::to_string((int)m_arc->getTransform().getX()) + ", " + std::to_string((int)m_arc->getTransform().getY()) + ")"));
	}
}

void VectorGraphicsInterpreterArcDialog::m_rotationAngleOnTextEnter(wxCommandEvent& event)
{
	try {
		int rAngle = std::stoi(std::string(m_rotationAngle->GetLineText(0)));
		m_arc->rotate(rAngle, m_arc->getRotateX(), m_arc->getRotateY());
	}
	catch (const std::invalid_argument&) {
		m_rotationAngle->SetLabel(wxString(std::to_string((int)m_arc->getRotationAngle())));
	}
}

void VectorGraphicsInterpreterArcDialog::m_deleteButtonOnButtonClick(wxCommandEvent& event)
{
	EndModal(101);
}
