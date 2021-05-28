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
// TODO: Implement m_startPointOnTextEnter
}

void VectorGraphicsInterpreterLineDialog::m_endPointOnTextEnter( wxCommandEvent& event )
{
// TODO: Implement m_endPointOnTextEnter
}

void VectorGraphicsInterpreterLineDialog::m_colourOnTextEnter( wxCommandEvent& event )
{
// TODO: Implement m_colourOnTextEnter
}

void VectorGraphicsInterpreterLineDialog::m_transformVectorOnTextEnter( wxCommandEvent& event )
{
// TODO: Implement m_transformVectorOnTextEnter
}

void VectorGraphicsInterpreterLineDialog::m_rotationAngleOnTextEnter( wxCommandEvent& event )
{
// TODO: Implement m_rotationAngleOnTextEnter
}

void VectorGraphicsInterpreterLineDialog::m_deleteButtonOnButtonClick( wxCommandEvent& event )
{
// TODO: Implement m_deleteButtonOnButtonClick
}
