#ifndef __VectorGraphicsInterpreterRectangleDialog__
#define __VectorGraphicsInterpreterRectangleDialog__

/**
@file
Subclass of RectangleDialog, which is generated by wxFormBuilder.
*/

//// end generated include
#include "../GUI/GUI.h"
#include "../Shapes/Rectangle.h"
#include "DialogValidator.h"

/** Implementing RectangleDialog */
class VectorGraphicsInterpreterRectangleDialog : public RectangleDialog
{
	protected:
		// Handlers for RectangleDialog events.
		void m_startPointOnTextEnter( wxCommandEvent& event );
		void m_endPointOnTextEnter( wxCommandEvent& event );
		void m_colourOnTextEnter( wxCommandEvent& event );
		void m_fillColourOnTextEnter(wxCommandEvent& event);
		void m_transformVectorOnTextEnter( wxCommandEvent& event );
		void m_rotationAngleOnTextEnter( wxCommandEvent& event );
		void m_deleteButtonOnButtonClick( wxCommandEvent& event );
	public:
		/** Constructor */
		VectorGraphicsInterpreterRectangleDialog( wxWindow* parent );
	//// end generated class members
	
		/** Constructor connected with specific rectangle shape */
		VectorGraphicsInterpreterRectangleDialog(wxWindow* parent, ShapeRectangle* rectangle);

private:
	ShapeRectangle* m_rectangle;
	DialogValidator m_validator;
};

#endif // __VectorGraphicsInterpreterRectangleDialog__
