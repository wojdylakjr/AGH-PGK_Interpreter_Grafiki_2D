#include "VectorGraphicsInterpreterLineDialog.h"

VectorGraphicsInterpreterLineDialog::VectorGraphicsInterpreterLineDialog( wxWindow* parent )
:
LineDialog( parent )
{
	m_line = nullptr;
}

VectorGraphicsInterpreterLineDialog::VectorGraphicsInterpreterLineDialog( wxWindow* parent, ShapeLine* line )
:
LineDialog(parent), m_line(line)
{
	m_objectName->SetLabel(wxString(m_line->getName()));
	m_objectID->SetLabel(wxString("ID: " + std::to_string(m_line->getId())));
	m_startPoint->SetLabel(wxString("(" + std::to_string((int)m_line->getPoint(true).getX()) + ", " + std::to_string((int)m_line->getPoint(true).getY()) + ")"));
	m_endPoint->SetLabel(wxString("(" + std::to_string((int)m_line->getPoint(false).getX()) + ", " + std::to_string((int)m_line->getPoint(false).getY()) + ")"));
	m_colour->SetLabel(wxString(m_line->getHexadecimalColour(true)));
	m_transformVector->SetLabel(wxString("(" + std::to_string((int)m_line->getTransform().getX()) + ", " + std::to_string((int)m_line->getTransform().getY()) + ")"));
	m_rotationAngle->SetLabel(wxString(std::to_string((int)m_line->getRotationAngle())));
}

void VectorGraphicsInterpreterLineDialog::m_startPointOnTextEnter( wxCommandEvent& event )
{
	if (m_validator.convertToPoint(std::string(m_startPoint->GetLineText(0)))) {
		m_line->setPoint(m_validator.getX(), m_validator.getY(), true);
	}
	else {
		m_startPoint->SetLabel(wxString("(" + std::to_string((int)m_line->getPoint(true).getX()) + ", " + std::to_string((int)m_line->getPoint(true).getY()) + ")"));
	}
}

void VectorGraphicsInterpreterLineDialog::m_endPointOnTextEnter( wxCommandEvent& event )
{
	if (m_validator.convertToPoint(std::string(m_endPoint->GetLineText(0)))) {
		m_line->setPoint(m_validator.getX(), m_validator.getY(), false);
	}
	else {
		m_endPoint->SetLabel(wxString("(" + std::to_string((int)m_line->getPoint(false).getX()) + ", " + std::to_string((int)m_line->getPoint(false).getY()) + ")"));
	}
}

void VectorGraphicsInterpreterLineDialog::m_colourOnTextEnter( wxCommandEvent& event )
{
	if (m_validator.convertToColour(std::string(m_colour->GetLineText(0)))) {
		m_line->setColour(wxColour(m_validator.getColour()));
	}
	else {
		m_colour->SetLabel(wxString(m_line->getHexadecimalColour(true)));
	}
}

void VectorGraphicsInterpreterLineDialog::m_transformVectorOnTextEnter( wxCommandEvent& event )
{
	if (m_validator.convertToPoint(std::string(m_transformVector->GetLineText(0)))) {
		m_line->setTransform(m_validator.getX(), m_validator.getY());
	}
	else {
		m_transformVector->SetLabel(wxString("(" + std::to_string((int)m_line->getTransform().getX()) + ", " + std::to_string((int)m_line->getTransform().getY()) + ")"));
	}
}

void VectorGraphicsInterpreterLineDialog::m_rotationAngleOnTextEnter( wxCommandEvent& event )
{
	try {
		int rAngle = std::stoi(std::string(m_rotationAngle->GetLineText(0)));
		m_line->rotate(rAngle, m_line->getRotateX(), m_line->getRotateY());
	}
	catch (const std::invalid_argument&) {
		m_rotationAngle->SetLabel(wxString(std::to_string((int)m_line->getRotationAngle())));
	}
}

void VectorGraphicsInterpreterLineDialog::m_deleteButtonOnButtonClick( wxCommandEvent& event )
{
	EndModal(101);
}
