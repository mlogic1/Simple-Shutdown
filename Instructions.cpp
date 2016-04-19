#include "Instructions.h"

//(*InternalHeaders(Instructions)
#include <wx/font.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//(*IdInit(Instructions)
const long Instructions::ID_STATICTEXT1 = wxNewId();
const long Instructions::ID_STATICLINE1 = wxNewId();
const long Instructions::ID_STATICTEXT2 = wxNewId();
const long Instructions::ID_STATICTEXT3 = wxNewId();
const long Instructions::ID_STATICLINE2 = wxNewId();
const long Instructions::ID_STATICTEXT4 = wxNewId();
//*)

BEGIN_EVENT_TABLE(Instructions,wxDialog)
	//(*EventTable(Instructions)
	//*)
END_EVENT_TABLE()

Instructions::Instructions(wxWindow* parent,wxWindowID id,const wxPoint& pos,const wxSize& size)
{
	//(*Initialize(Instructions)
	Create(parent, wxID_ANY, _("Help"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_DIALOG_STYLE, _T("wxID_ANY"));
	SetClientSize(wxSize(583,199));
	StaticText1 = new wxStaticText(this, ID_STATICTEXT1, _("How to use the application"), wxPoint(6,8), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
	wxFont StaticText1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText1->SetFont(StaticText1Font);
	StaticLine1 = new wxStaticLine(this, ID_STATICLINE1, wxPoint(6,32), wxSize(570,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
	StaticText2 = new wxStaticText(this, ID_STATICTEXT2, _("Select the wanted action to perform on the left side and time until the action on the right side and press Set.\nYou will be notified by windows that an event was scheduled.\n\nTo cancel press the \"Cancel any existing jobs\" button to cancel any shutdown event you have scheduled."), wxPoint(6,40), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
	StaticText3 = new wxStaticText(this, ID_STATICTEXT3, _("Force"), wxPoint(6,128), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
	wxFont StaticText3Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
	StaticText3->SetFont(StaticText3Font);
	StaticLine2 = new wxStaticLine(this, ID_STATICLINE2, wxPoint(6,150), wxSize(570,-1), wxLI_HORIZONTAL, _T("ID_STATICLINE2"));
	StaticText4 = new wxStaticText(this, ID_STATICTEXT4, _("Force is an optional setting that forces the computer to shutdown/restart in case an application causes it \nto wait for user to respond."), wxPoint(6,152), wxSize(-1,-1), 0, _T("ID_STATICTEXT4"));
	Center();
	//*)
}

Instructions::~Instructions()
{
	//(*Destroy(Instructions)
	//*)
}

