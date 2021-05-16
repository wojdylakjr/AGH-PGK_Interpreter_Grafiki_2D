#include <wx/wx.h>

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
	mainFrame->Show(true);
	SetTopWindow(mainFrame);

	return true;
}