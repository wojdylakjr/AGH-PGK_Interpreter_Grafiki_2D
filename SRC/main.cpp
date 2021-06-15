#include <wx/wx.h>
#include "./Resources/icon.xpm"

#include "GUI/VectorGraphicsInterpreterGUI.h"

class VectorGraphicsInterpreterApp : public wxApp {

public:

	virtual bool OnInit();
	virtual int OnExit() { return 0; }

};

IMPLEMENT_APP(VectorGraphicsInterpreterApp);

bool VectorGraphicsInterpreterApp::OnInit()
{
	wxFrame* mainFrame = new VectorGraphicsInterpreterGUI(NULL);
	mainFrame->SetIcon(icon_xpm);
	mainFrame->Show(true);
	SetTopWindow(mainFrame);
	return true;
}