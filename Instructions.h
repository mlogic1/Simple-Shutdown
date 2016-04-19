#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

//(*Headers(Instructions)
#include <wx/stattext.h>
#include <wx/statline.h>
#include <wx/dialog.h>
//*)

class Instructions: public wxDialog
{
	public:

		Instructions(wxWindow* parent,wxWindowID id=wxID_ANY,const wxPoint& pos=wxDefaultPosition,const wxSize& size=wxDefaultSize);
		virtual ~Instructions();

		//(*Declarations(Instructions)
		wxStaticText* StaticText2;
		wxStaticText* StaticText1;
		wxStaticText* StaticText3;
		wxStaticLine* StaticLine2;
		wxStaticLine* StaticLine1;
		wxStaticText* StaticText4;
		//*)

	protected:

		//(*Identifiers(Instructions)
		static const long ID_STATICTEXT1;
		static const long ID_STATICLINE1;
		static const long ID_STATICTEXT2;
		static const long ID_STATICTEXT3;
		static const long ID_STATICLINE2;
		static const long ID_STATICTEXT4;
		//*)

	private:

		//(*Handlers(Instructions)
		//*)

		DECLARE_EVENT_TABLE()
};

#endif
