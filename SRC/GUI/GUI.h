///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __GUI_H__
#define __GUI_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/panel.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/string.h>
#include <wx/sizer.h>
#include <wx/textctrl.h>
#include <wx/stattext.h>
#include <wx/listbox.h>
#include <wx/frame.h>
#include <wx/button.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class GUI
///////////////////////////////////////////////////////////////////////////////
class GUI : public wxFrame 
{
	private:
	
	protected:
		wxPanel* m_workspace;
		wxTextCtrl* m_console;
		wxStaticText* m_objectsListLabel;
		wxListBox* m_objectsList;
		wxStaticText* m_cursorPosition;
		
		// Virtual event handlers, overide them in your derived class
		virtual void workspaceOnMotion( wxMouseEvent& event ) { event.Skip(); }
		virtual void workspaceOnUpdateUI( wxUpdateUIEvent& event ) { event.Skip(); }
		virtual void consoleOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_objectsListOnLeaveWindow(wxMouseEvent& event) { event.Skip(); }
		virtual void m_objectsListOnListBox(wxCommandEvent& event) { event.Skip(); }
		virtual void OnRightDown(wxMouseEvent& event) { event.Skip(); }
		
	
	public:
		
		GUI( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1055,800 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~GUI();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class LineDialog
///////////////////////////////////////////////////////////////////////////////
class LineDialog : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_objectName;
		wxStaticText* m_objectID;
		wxStaticText* m_startPointName;
		wxTextCtrl* m_startPoint;
		wxStaticText* m_endPointName;
		wxTextCtrl* m_endPoint;
		wxStaticText* m_colourName;
		wxTextCtrl* m_colour;
		wxStaticText* m_transformName;
		wxTextCtrl* m_transformVector;
		wxStaticText* m_rotationAngleName;
		wxTextCtrl* m_rotationAngle;
		wxButton* m_deleteButton;
		
		// Virtual event handlers, overide them in your derived class
		virtual void m_startPointOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_endPointOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_colourOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_transformVectorOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_rotationAngleOnTextEnter( wxCommandEvent& event ) { event.Skip(); }
		virtual void m_deleteButtonOnButtonClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		LineDialog( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Line properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 250,250 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~LineDialog();
	
};


///////////////////////////////////////////////////////////////////////////////
/// Class RectangleDialog
///////////////////////////////////////////////////////////////////////////////
class RectangleDialog : public wxDialog
{
private:

protected:
	wxStaticText* m_objectName;
	wxStaticText* m_objectID;
	wxStaticText* m_bottomLeftName;
	wxTextCtrl* m_bottomLeft;
	wxStaticText* m_topRightName;
	wxTextCtrl* m_topRight;
	wxStaticText* m_colourName;
	wxTextCtrl* m_colour;
	wxStaticText* m_fillColourName;
	wxTextCtrl* m_fillColour;
	wxStaticText* m_transformName;
	wxTextCtrl* m_transformVector;
	wxStaticText* m_rotationAngleName;
	wxTextCtrl* m_rotationAngle;
	wxButton* m_deleteButton;

	// Virtual event handlers, overide them in your derived class
	virtual void m_startPointOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_endPointOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_colourOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_fillColourOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_transformVectorOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_rotationAngleOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_deleteButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }


public:

	RectangleDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Rectangle properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(250, 280), long style = wxDEFAULT_DIALOG_STYLE);
	~RectangleDialog();

};


///////////////////////////////////////////////////////////////////////////////
/// Class CircleDialog
///////////////////////////////////////////////////////////////////////////////
class CircleDialog : public wxDialog
{
private:

protected:
	wxStaticText* m_objectName;
	wxStaticText* m_objectID;
	wxStaticText* m_centerName;
	wxTextCtrl* m_center;
	wxStaticText* m_radiusName;
	wxTextCtrl* m_radius;
	wxStaticText* m_colourName;
	wxTextCtrl* m_colour;
	wxStaticText* m_fillColourName;
	wxTextCtrl* m_fillColour;
	wxStaticText* m_transformName;
	wxTextCtrl* m_transformVector;
	wxStaticText* m_rotationAngleName;
	wxTextCtrl* m_rotationAngle;
	wxButton* m_deleteButton;

	// Virtual event handlers, overide them in your derived class
	virtual void m_centerOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_radiusOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_colourOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_fillColourOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_transformVectorOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_rotationAngleOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_deleteButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }


public:

	CircleDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Circle properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(250, 280), long style = wxDEFAULT_DIALOG_STYLE);
	~CircleDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class EllipseDialog
///////////////////////////////////////////////////////////////////////////////
class EllipseDialog : public wxDialog
{
private:

protected:
	wxStaticText* m_objectName;
	wxStaticText* m_objectID;
	wxStaticText* m_centerName;
	wxTextCtrl* m_center;
	wxStaticText* m_horizontalShaftName;
	wxTextCtrl* m_horizontalShaft;
	wxStaticText* m_verticalShaftName;
	wxTextCtrl* m_verticalShaft;
	wxStaticText* m_colourName;
	wxTextCtrl* m_colour;
	wxStaticText* m_fillColourName;
	wxTextCtrl* m_fillColour;
	wxStaticText* m_transformName;
	wxTextCtrl* m_transformVector;
	wxStaticText* m_rotationAngleName;
	wxTextCtrl* m_rotationAngle;
	wxButton* m_deleteButton;

	// Virtual event handlers, overide them in your derived class
	virtual void m_centerOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_horizontalShaftOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_verticalShaftOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_colourOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_fillColourOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_transformVectorOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_rotationAngleOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_deleteButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }


public:

	EllipseDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Ellipse properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(250, 310), long style = wxDEFAULT_DIALOG_STYLE);
	~EllipseDialog();

};

///////////////////////////////////////////////////////////////////////////////
/// Class ArcDialog
///////////////////////////////////////////////////////////////////////////////
class ArcDialog : public wxDialog
{
private:

protected:
	wxStaticText* m_objectName;
	wxStaticText* m_objectID;
	wxStaticText* m_centerName;
	wxTextCtrl* m_center;
	wxStaticText* m_horizontalShaftName;
	wxTextCtrl* m_horizontalShaft;
	wxStaticText* m_verticalShaftName;
	wxTextCtrl* m_verticalShaft;
	wxStaticText* m_startAngleName;
	wxTextCtrl* m_startAngle;
	wxStaticText* m_stopAngleName;
	wxTextCtrl* m_stopAngle;
	wxStaticText* m_colourName;
	wxTextCtrl* m_colour;
	wxStaticText* m_transformName;
	wxTextCtrl* m_transformVector;
	wxStaticText* m_rotationAngleName;
	wxTextCtrl* m_rotationAngle;
	wxButton* m_deleteButton;

	// Virtual event handlers, overide them in your derived class
	virtual void m_centerOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_horizontalShaftOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_verticalShaftOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_startAngleOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_stopAngleOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_colourOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_transformVectorOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_rotationAngleOnTextEnter(wxCommandEvent& event) { event.Skip(); }
	virtual void m_deleteButtonOnButtonClick(wxCommandEvent& event) { event.Skip(); }


public:

	ArcDialog(wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Arc properties"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize(250, 370), long style = wxDEFAULT_DIALOG_STYLE);
	~ArcDialog();

};

#endif //__GUI_H__


