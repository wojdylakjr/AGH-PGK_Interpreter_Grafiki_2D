///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "GUI.h"

///////////////////////////////////////////////////////////////////////////

GUI::GUI( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* MainSizer;
	MainSizer = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* LeftSizer;
	LeftSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* WorkspaceSizer;
	WorkspaceSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_workspace = new wxPanel( this, wxID_ANY, wxDefaultPosition, wxSize( 800,620 ), wxTAB_TRAVERSAL );
	m_workspace->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	m_workspace->SetBackgroundColour( wxColour( 255, 255, 255 ) );
	
	WorkspaceSizer->Add( m_workspace, 1, wxALIGN_CENTER_HORIZONTAL|wxALL|wxEXPAND, 5 );
	
	
	LeftSizer->Add( WorkspaceSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* ConsoleSizer;
	ConsoleSizer = new wxBoxSizer( wxHORIZONTAL );
	
	m_console = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 800,100 ), wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB|wxTE_MULTILINE);
	m_console->SetFont( wxFont( 12, 75, 90, 92, false, wxT("Consolas") ) );
	m_console->SetForegroundColour( wxColour( 255, 255, 255 ) );
	m_console->SetBackgroundColour( wxColour( 0, 0, 0 ) );
	m_console->SetMinSize( wxSize( 800,100 ) );
	m_console->SetMaxSize( wxSize( -1,100 ) );
	
	ConsoleSizer->Add( m_console, 1, wxALL, 5 );
	
	
	LeftSizer->Add( ConsoleSizer, 0, wxEXPAND, 5 );
	
	
	MainSizer->Add( LeftSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* RightSizer;
	RightSizer = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* ObjectsListSizer;
	ObjectsListSizer = new wxBoxSizer( wxVERTICAL );
	
	m_objectsListLabel = new wxStaticText( this, wxID_ANY, wxT("   Object          ID"), wxDefaultPosition, wxSize( 220,20 ), 0 );
	m_objectsListLabel->Wrap( -1 );
	m_objectsListLabel->SetFont( wxFont( 12, 75, 90, 90, false, wxT("Consolas") ) );
	
	ObjectsListSizer->Add( m_objectsListLabel, 0, wxALL, 5 );
	
	m_objectsList = new wxListBox( this, wxID_ANY, wxDefaultPosition, wxSize( 220,600 ), 0, NULL, 0 ); 
	m_objectsList->SetFont(wxFont(12, 75, 90, 90, false, wxT("Consolas")));
	ObjectsListSizer->Add( m_objectsList, 1, wxALL, 5 );
	
	
	RightSizer->Add( ObjectsListSizer, 1, wxEXPAND, 5 );
	
	wxBoxSizer* CursorPositionSizer;
	CursorPositionSizer = new wxBoxSizer( wxHORIZONTAL );
	
	CursorPositionSizer->SetMinSize( wxSize( 220,110 ) ); 
	m_cursorPosition = new wxStaticText( this, wxID_ANY, wxT("   x = \n   y = "), wxDefaultPosition, wxSize( 220,55 ), 0 );
	m_cursorPosition->Wrap( -1 );
	m_cursorPosition->SetFont( wxFont( 16, 75, 90, 90, false, wxT("Consolas") ) );
	
	CursorPositionSizer->Add( m_cursorPosition, 0, wxALIGN_CENTER_VERTICAL|wxALL, 5 );
	
	
	RightSizer->Add( CursorPositionSizer, 0, wxALIGN_BOTTOM, 5 );
	
	
	MainSizer->Add( RightSizer, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( MainSizer );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_workspace->Connect( wxEVT_MOTION, wxMouseEventHandler( GUI::workspaceOnMotion ), NULL, this );
	m_workspace->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( GUI::workspaceOnUpdateUI ), NULL, this );
	m_console->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI::consoleOnTextEnter ), NULL, this );
	m_objectsList->Connect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(GUI::m_objectsListOnLeaveWindow), NULL, this);
	m_objectsList->Connect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(GUI::m_objectsListOnListBox), NULL, this);
	m_objectsList->Connect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(GUI::OnRightDown), NULL, this);

}

GUI::~GUI()
{
	// Disconnect Events
	m_workspace->Disconnect( wxEVT_MOTION, wxMouseEventHandler( GUI::workspaceOnMotion ), NULL, this );
	m_workspace->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( GUI::workspaceOnUpdateUI ), NULL, this );
	m_console->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI::consoleOnTextEnter ), NULL, this );
	m_objectsList->Disconnect(wxEVT_LEAVE_WINDOW, wxMouseEventHandler(GUI::m_objectsListOnLeaveWindow), NULL, this);
	m_objectsList->Disconnect(wxEVT_COMMAND_LISTBOX_SELECTED, wxCommandEventHandler(GUI::m_objectsListOnListBox), NULL, this);
	m_objectsList->Disconnect(wxEVT_RIGHT_DOWN, wxMouseEventHandler(GUI::OnRightDown), NULL, this);
	
}

LineDialog::LineDialog(wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style) : wxDialog(parent, id, title, pos, size, style)
{
	this->SetSizeHints(wxDefaultSize, wxDefaultSize);

	wxBoxSizer* DialogSizer;
	DialogSizer = new wxBoxSizer(wxVERTICAL);

	wxBoxSizer* objectNameSizer;
	objectNameSizer = new wxBoxSizer(wxHORIZONTAL);

	m_objectName = new wxStaticText(this, wxID_ANY, wxT("none"), wxDefaultPosition, wxSize(120, 20), 0);
	m_objectName->Wrap(-1);
	m_objectName->SetFont(wxFont(10, 75, 90, 90, false, wxT("Consolas")));

	objectNameSizer->Add(m_objectName, 0, wxALIGN_LEFT | wxALL, 5);

	m_objectID = new wxStaticText(this, wxID_ANY, wxT("ID:"), wxDefaultPosition, wxSize(120, 20), 0);
	m_objectID->Wrap(-1);
	objectNameSizer->Add(m_objectID, 0, wxALIGN_RIGHT | wxALL, 5);


	DialogSizer->Add(objectNameSizer, 1, wxEXPAND, 5);

	wxBoxSizer* startPointSizer;
	startPointSizer = new wxBoxSizer(wxHORIZONTAL);

	m_startPointName = new wxStaticText(this, wxID_ANY, wxT("Start point:"), wxDefaultPosition, wxSize(120, 20), 0);
	m_startPointName->Wrap(-1);
	m_startPointName->SetFont(wxFont(10, 75, 90, 90, false, wxT("Consolas")));

	startPointSizer->Add(m_startPointName, 0, wxALL, 5);

	m_startPoint = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(120, 20), 0);
	m_startPoint->SetFont(wxFont(10, 75, 90, 90, false, wxT("Consolas")));

	startPointSizer->Add(m_startPoint, 0, wxALL, 5);


	DialogSizer->Add(startPointSizer, 1, wxEXPAND, 5);

	wxBoxSizer* endPointSizer;
	endPointSizer = new wxBoxSizer(wxHORIZONTAL);

	m_endPointName = new wxStaticText(this, wxID_ANY, wxT("End point:"), wxDefaultPosition, wxSize(120, 20), 0);
	m_endPointName->Wrap(-1);
	m_endPointName->SetFont(wxFont(10, 75, 90, 90, false, wxT("Consolas")));

	endPointSizer->Add(m_endPointName, 0, wxALL, 5);

	m_endPoint = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(120, 20), 0);
	m_endPoint->SetFont(wxFont(10, 75, 90, 90, false, wxT("Consolas")));

	endPointSizer->Add(m_endPoint, 0, wxALL, 5);


	DialogSizer->Add(endPointSizer, 1, wxEXPAND, 5);

	wxBoxSizer* colourSizer;
	colourSizer = new wxBoxSizer(wxHORIZONTAL);

	m_colourName = new wxStaticText(this, wxID_ANY, wxT("Colour:"), wxDefaultPosition, wxSize(120, 20), 0);
	m_colourName->Wrap(-1);
	m_colourName->SetFont(wxFont(10, 75, 90, 90, false, wxT("Consolas")));

	colourSizer->Add(m_colourName, 0, wxALL, 5);

	m_colour = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(120, 20), 0);
	m_colour->SetFont(wxFont(10, 75, 90, 90, false, wxT("Consolas")));

	colourSizer->Add(m_colour, 0, wxALL, 5);


	DialogSizer->Add(colourSizer, 1, wxEXPAND, 5);

	wxBoxSizer* transformSizer;
	transformSizer = new wxBoxSizer(wxHORIZONTAL);

	m_transformName = new wxStaticText(this, wxID_ANY, wxT("Transform vector:"), wxDefaultPosition, wxSize(120, 20), 0);
	m_transformName->Wrap(-1);
	m_transformName->SetFont(wxFont(10, 75, 90, 90, false, wxT("Consolas")));

	transformSizer->Add(m_transformName, 0, wxALL, 5);

	m_transformVector = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(120, 20), 0);
	m_transformVector->SetFont(wxFont(10, 75, 90, 90, false, wxT("Consolas")));

	transformSizer->Add(m_transformVector, 0, wxALL, 5);


	DialogSizer->Add(transformSizer, 1, wxEXPAND, 5);

	wxBoxSizer* rotationSizer;
	rotationSizer = new wxBoxSizer(wxHORIZONTAL);

	m_rotationAngleName = new wxStaticText(this, wxID_ANY, wxT("Rotation angle:"), wxDefaultPosition, wxSize(120, 20), 0);
	m_rotationAngleName->Wrap(-1);
	m_rotationAngleName->SetFont(wxFont(10, 75, 90, 90, false, wxT("Consolas")));

	rotationSizer->Add(m_rotationAngleName, 0, wxALL, 5);

	m_rotationAngle = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(120, 20), 0);
	m_rotationAngle->SetFont(wxFont(10, 75, 90, 90, false, wxT("Consolas")));

	rotationSizer->Add(m_rotationAngle, 0, wxALL, 5);


	DialogSizer->Add(rotationSizer, 1, wxEXPAND, 5);

	wxBoxSizer* deleteSizer;
	deleteSizer = new wxBoxSizer(wxVERTICAL);

	m_deleteButton = new wxButton(this, wxID_ANY, wxT("Delete"), wxDefaultPosition, wxSize(120, 25), 0);
	deleteSizer->Add(m_deleteButton, 0, wxALIGN_CENTER | wxALL, 5);


	DialogSizer->Add(deleteSizer, 1, wxEXPAND, 5);


	this->SetSizer(DialogSizer);
	this->Layout();

	this->Centre(wxBOTH);

	// Connect Events
	m_startPoint->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LineDialog::m_startPointOnTextEnter), NULL, this);
	m_endPoint->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LineDialog::m_endPointOnTextEnter), NULL, this);
	m_colour->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LineDialog::m_colourOnTextEnter), NULL, this);
	m_transformVector->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LineDialog::m_transformVectorOnTextEnter), NULL, this);
	m_rotationAngle->Connect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LineDialog::m_rotationAngleOnTextEnter), NULL, this);
	m_deleteButton->Connect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LineDialog::m_deleteButtonOnButtonClick), NULL, this);
}

LineDialog::~LineDialog()
{
	// Disconnect Events
	m_startPoint->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LineDialog::m_startPointOnTextEnter), NULL, this);
	m_endPoint->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LineDialog::m_endPointOnTextEnter), NULL, this);
	m_colour->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LineDialog::m_colourOnTextEnter), NULL, this);
	m_transformVector->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LineDialog::m_transformVectorOnTextEnter), NULL, this);
	m_rotationAngle->Disconnect(wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler(LineDialog::m_rotationAngleOnTextEnter), NULL, this);
	m_deleteButton->Disconnect(wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler(LineDialog::m_deleteButtonOnButtonClick), NULL, this);

}
