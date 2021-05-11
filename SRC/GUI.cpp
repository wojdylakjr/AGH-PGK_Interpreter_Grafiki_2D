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
	
	m_console = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize( 800,100 ), wxTE_PROCESS_ENTER|wxTE_PROCESS_TAB );
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
	m_workspace->Connect( wxEVT_MOTION, wxMouseEventHandler( GUI::m_workspaceOnMotion ), NULL, this );
	m_workspace->Connect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( GUI::m_workspaceOnUpdateUI ), NULL, this );
	m_console->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI::m_consoleOnTextEnter ), NULL, this );
}

GUI::~GUI()
{
	// Disconnect Events
	m_workspace->Disconnect( wxEVT_MOTION, wxMouseEventHandler( GUI::m_workspaceOnMotion ), NULL, this );
	m_workspace->Disconnect( wxEVT_UPDATE_UI, wxUpdateUIEventHandler( GUI::m_workspaceOnUpdateUI ), NULL, this );
	m_console->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( GUI::m_consoleOnTextEnter ), NULL, this );
	
}
