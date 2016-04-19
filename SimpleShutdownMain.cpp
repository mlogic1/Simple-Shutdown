/***************************************************************
 * Name:      SimpleShutdownMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Filip Radić (multilogic@outlook.com)
 * Created:   2016-04-15
 * Copyright: Filip Radić ()
 * License:
 **************************************************************/

#include "SimpleShutdownMain.h"
#include <wx/msgdlg.h>

#include <windows.h>

//(*InternalHeaders(SimpleShutdownFrame)
#include <wx/bitmap.h>
#include <wx/icon.h>
#include <wx/intl.h>
#include <wx/image.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(SimpleShutdownFrame)
const long SimpleShutdownFrame::ID_STATICBOX1 = wxNewId();
const long SimpleShutdownFrame::ID_RADIOBUTTON1 = wxNewId();
const long SimpleShutdownFrame::ID_RADIOBUTTON2 = wxNewId();
const long SimpleShutdownFrame::ID_CHECKBOX1 = wxNewId();
const long SimpleShutdownFrame::ID_STATICBOX2 = wxNewId();
const long SimpleShutdownFrame::ID_STATICTEXT1 = wxNewId();
const long SimpleShutdownFrame::ID_CHOICE1 = wxNewId();
const long SimpleShutdownFrame::ID_STATICTEXT2 = wxNewId();
const long SimpleShutdownFrame::ID_STATICTEXT3 = wxNewId();
const long SimpleShutdownFrame::ID_STATICTEXT4 = wxNewId();
const long SimpleShutdownFrame::ID_CHOICE2 = wxNewId();
const long SimpleShutdownFrame::ID_CHOICE3 = wxNewId();
const long SimpleShutdownFrame::ID_BUTTON1 = wxNewId();
const long SimpleShutdownFrame::ID_BUTTON2 = wxNewId();
const long SimpleShutdownFrame::ID_STATICLINE1 = wxNewId();
const long SimpleShutdownFrame::ID_RADIOBUTTON3 = wxNewId();
const long SimpleShutdownFrame::ID_RADIOBUTTON4 = wxNewId();
const long SimpleShutdownFrame::ID_PANEL1 = wxNewId();
const long SimpleShutdownFrame::ID_SYSTEMTRAY = wxNewId();
const long SimpleShutdownFrame::ID_EXIT = wxNewId();
const long SimpleShutdownFrame::ID_INSTRUCTIONS = wxNewId();
const long SimpleShutdownFrame::ID_ABOUT = wxNewId();
const long SimpleShutdownFrame::ID_STATUSBAR1 = wxNewId();
//*)

const long SimpleShutdownFrame::ID_TIMER = wxNewId();

BEGIN_EVENT_TABLE(SimpleShutdownFrame,wxFrame)
    //(*EventTable(SimpleShutdownFrame)
    //*)

    EVT_MENU(ID_EXIT, SimpleShutdownFrame::OnQuit)
    EVT_MENU(ID_ABOUT, SimpleShutdownFrame::OnAbout)
    EVT_MENU(ID_INSTRUCTIONS, SimpleShutdownFrame::OnInstructions)
    EVT_MENU(ID_SYSTEMTRAY, SimpleShutdownFrame::ToSystemTray)
    EVT_TIMER(ID_TIMER, SimpleShutdownFrame::OnTimerTick)
END_EVENT_TABLE()

SimpleShutdownFrame::SimpleShutdownFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(SimpleShutdownFrame)
    Create(parent, wxID_ANY, _("Simple Shutdown"), wxDefaultPosition, wxDefaultSize, wxCAPTION|wxCLOSE_BOX|wxMINIMIZE_BOX, _T("wxID_ANY"));
    SetClientSize(wxSize(259,257));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("icon.ico"))));
    	SetIcon(FrameIcon);
    }
    Panel1 = new wxPanel(this, ID_PANEL1, wxPoint(208,256), wxSize(259,288), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    StaticBox1 = new wxStaticBox(Panel1, ID_STATICBOX1, _("Action"), wxPoint(8,8), wxSize(104,200), 0, _T("ID_STATICBOX1"));
    RadioButtonShutdown = new wxRadioButton(Panel1, ID_RADIOBUTTON1, _("Shutdown"), wxPoint(16,28), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON1"));
    RadioButtonRestart = new wxRadioButton(Panel1, ID_RADIOBUTTON2, _("Restart"), wxPoint(16,48), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON2"));
    CheckBoxForce = new wxCheckBox(Panel1, ID_CHECKBOX1, _("Force"), wxPoint(16,120), wxDefaultSize, 0, wxDefaultValidator, _T("ID_CHECKBOX1"));
    CheckBoxForce->SetValue(true);
    StaticBox2 = new wxStaticBox(Panel1, ID_STATICBOX2, _("Time"), wxPoint(120,8), wxSize(136,200), 0, _T("ID_STATICBOX2"));
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Set time until the event"), wxPoint(128,24), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    ChoiceM = new wxChoice(Panel1, ID_CHOICE1, wxPoint(128,96), wxSize(112,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE1"));
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("Hours"), wxPoint(128,40), wxDefaultSize, 0, _T("ID_STATICTEXT2"));
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("Minutes"), wxPoint(128,80), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    StaticText4 = new wxStaticText(Panel1, ID_STATICTEXT4, _("Seconds"), wxPoint(128,120), wxDefaultSize, 0, _T("ID_STATICTEXT4"));
    ChoiceS = new wxChoice(Panel1, ID_CHOICE2, wxPoint(128,136), wxSize(112,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE2"));
    ChoiceH = new wxChoice(Panel1, ID_CHOICE3, wxPoint(128,56), wxSize(112,21), 0, 0, 0, wxDefaultValidator, _T("ID_CHOICE3"));
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Cancel any\nexisting jobs"), wxPoint(16,160), wxSize(88,40), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    Button2 = new wxButton(Panel1, ID_BUTTON2, _("  Set"), wxPoint(176,165), wxSize(64,32), wxBU_LEFT, wxDefaultValidator, _T("ID_BUTTON2"));
    StaticLine1 = new wxStaticLine(Panel1, ID_STATICLINE1, wxPoint(16,145), wxSize(90,2), wxLI_HORIZONTAL, _T("ID_STATICLINE1"));
    RadioButtonSleep = new wxRadioButton(Panel1, ID_RADIOBUTTON3, _("Sleep"), wxPoint(16,68), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON3"));
    RadioButtonHibernate = new wxRadioButton(Panel1, ID_RADIOBUTTON4, _("Hibernate"), wxPoint(16,88), wxDefaultSize, 0, wxDefaultValidator, _T("ID_RADIOBUTTON4"));
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem4 = new wxMenuItem(Menu1, ID_SYSTEMTRAY, _("Send to system tray"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem4);
    MenuItem2 = new wxMenuItem(Menu1, ID_EXIT, _("Exit\tAlt-F4"), wxEmptyString, wxITEM_NORMAL);
    Menu1->Append(MenuItem2);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem3 = new wxMenuItem(Menu2, ID_INSTRUCTIONS, _("Help\tF1"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem3);
    MenuItem1 = new wxMenuItem(Menu2, ID_ABOUT, _("About\tF2"), wxEmptyString, wxITEM_NORMAL);
    Menu2->Append(MenuItem1);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -10 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_CHECKBOX1,wxEVT_COMMAND_CHECKBOX_CLICKED,(wxObjectEventFunction)&SimpleShutdownFrame::OnForceCheck);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SimpleShutdownFrame::OnButton1Click);
    Connect(ID_BUTTON2,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&SimpleShutdownFrame::OnButton2Click);
    //*)



    TrayIcon = new Taskicon(this);

    Checkbox.LoadFile("check.png", wxBITMAP_TYPE_PNG);
    Button2->SetBitmap(Checkbox, wxRIGHT);

    wxPoint x;
    wxRect r;
    StatusBar1->GetFieldRect(0, r);
    x = r.GetLeftTop();
    x.x = x.x + 4;
    Status = new wxStaticText(StatusBar1, wxID_ANY, "", x);
    Status->CenterOnParent(wxVERTICAL);

    Countdown = new wxTimer(this, ID_TIMER);

    //Assign values to the checkboxes
    for(int i=0;i<61;i++){
        wxString temp;
        temp = wxString::Format(wxT("%i"), i);
        ChoiceS->Append(temp);
        ChoiceM->Append(temp);
        ChoiceH->Append(temp);
    }

    ChoiceS->SetSelection(0);
    ChoiceM->SetSelection(0);
    ChoiceH->SetSelection(0);
}

SimpleShutdownFrame::~SimpleShutdownFrame()
{
    //(*Destroy(SimpleShutdownFrame)
    //*)
    if(Countdown->IsRunning()){
        Countdown->Stop();
    }

    delete Countdown;
    delete Status;
    delete TrayIcon;
}

void SimpleShutdownFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void SimpleShutdownFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("Code: Filip Radic\n\nCredits to:\nPower icon - MazeNL77\nCheck icon - Icojam\n\n\n For Jerryy and Schifty :) ", _("About"));
}


void SimpleShutdownFrame::OnInstructions(wxCommandEvent &event){
    Instructions i(this);
    i.ShowModal();
}



void SimpleShutdownFrame::Shutdown(){

    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;

    // Get a token for this process.

    if (!OpenProcessToken(GetCurrentProcess(),
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)){
        wxMessageBox("Something went wrong with privileges, please try running the application as administrator");
        return;
    }


    // Get the LUID for the shutdown privilege.
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
    &tkp.Privileges[0].Luid);

    tkp.PrivilegeCount = 1;  // one privilege to set
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    // Get the shutdown privilege for this process.
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

    if (GetLastError() != ERROR_SUCCESS){
        return;// FALSE;
    }


    if(!InitiateSystemShutdown(NULL, NULL, timeout, FALSE, FALSE)){
        wxMessageBox("An error occurred, you probably already scheduled a shutdown previously. Please cancel any existing shutdown schedules and try again. If the problem persists try running as administrator", "Information");
    }else{
        //Success
    }

}




void SimpleShutdownFrame::Restart(){

    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;

    // Get a token for this process.

    if (!OpenProcessToken(GetCurrentProcess(),
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)){
        wxMessageBox("Something went wrong with privileges, please try running the application as administrator");
        return;
    }


    // Get the LUID for the shutdown privilege.
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
    &tkp.Privileges[0].Luid);

    tkp.PrivilegeCount = 1;  // one privilege to set
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    // Get the shutdown privilege for this process.
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

    if (GetLastError() != ERROR_SUCCESS){
        return;
    }


    if(!InitiateSystemShutdown(NULL, NULL, timeout, FALSE, TRUE)){
        wxMessageBox("An error occurred, you probably already scheduled a shutdown previously. Please cancel any existing shutdown schedules and try again. If the problem persists try running as administrator", "Information");
    }else{
        //Success
    }
}


void SimpleShutdownFrame::Hibernate(){
    wxString message = "In order for sleep and hibernate functions to work, this application must be running in the background. Please click File->Send to system tray or leave the application on the desktop.";
    wxString caption = "Important information!";

    wxMessageBox(message, caption);

    SecToEvent = timeout;

    Countdown->Start(1000);

    //return true;
}

void SimpleShutdownFrame::Sleep(){
    wxString message = "In order for sleep and hibernate functions to work, this application must be running in the background. Please click File->Send to system tray or leave the application on the desktop.";
    wxString caption = "Important information!";

    wxMessageBox(message, caption);

    SecToEvent = timeout;

    Countdown->Start(1000);

    //return true;
}

int SimpleShutdownFrame::GetChoice(){

    if(RadioButtonShutdown->GetValue()){
        return SHUTDOWN;
    }

    if(RadioButtonRestart->GetValue()){
        return REBOOT;
    }

    if(RadioButtonHibernate->GetValue()){
        return HIBERNATE;
    }

    if(RadioButtonSleep->GetValue()){
        return SLEEP;
    }

    return 0;
}


void SimpleShutdownFrame::OnButton2Click(wxCommandEvent& event)
{
    //Check if timer was previously running and stop it
    if(Countdown->IsRunning()){
        Countdown->Stop();
    }

    //Clear the status label
    Status->SetLabel("");


    Choice = GetChoice();
    timeout = CalculateTimeout();

    if(timeout == 0){
        wxMessageBox("Time until action can not be 0, please set the appropriate value and then try again.", "Information");
        return;
    }

    if(Choice == SHUTDOWN){
        Shutdown();
    }else if(Choice == REBOOT){
        Restart();
    }else if(Choice == HIBERNATE){
        Hibernate();
    }else if(Choice == SLEEP){
        Sleep();
    }

}

void SimpleShutdownFrame::OnButton1Click(wxCommandEvent& event)
{
    //Stop countdown
    Countdown->Stop();

    //Clear the status text
    Status->SetLabel("");

    //Cancel all actions
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;

    // Get a token for this process.

    if (!OpenProcessToken(GetCurrentProcess(),
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)){
        wxMessageBox("Something is wrong with administrative privileges, please make sure you are logged in as administrator or running the application with administrative rights.", "Information");

        //return FALSE;
    }


    // Get the LUID for the shutdown privilege.
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
    &tkp.Privileges[0].Luid);

    tkp.PrivilegeCount = 1;  // one privilege to set
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    // Get the shutdown privilege for this process.
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

    if (GetLastError() != ERROR_SUCCESS){
        //return FALSE;
        wxMessageBox("Error canceling", "Error");
    }else{
        AbortSystemShutdownA(NULL);
    }


}


int SimpleShutdownFrame::CalculateTimeout(){
    int timeout_seconds;
    int s,m,h;

    //Seconds
    s = ChoiceS->GetSelection();

    //Minutes
    m = ChoiceM->GetSelection();
    m *= 60;    //Convert minutes to seconds

    //Hours
    h = ChoiceH->GetSelection();
    h *= 3600;  //Convert hours to seconds

    timeout_seconds = s + m + h;

    return timeout_seconds;
}

void SimpleShutdownFrame::OnTimerTick(wxTimerEvent &event){

    //Set the status string
    wxString StatusText;

    //Type of event
    if(Choice == HIBERNATE){
        StatusText = "Hibernating in ";
    }else if(Choice == SLEEP){
        StatusText = "Sleeping in ";
    }

    //Get the time
    wxString StringTimer = wxString::Format(wxT("%i"), SecToEvent);

    //Append timer to status
    StatusText += StringTimer;
    StatusText += "s";

    Status->SetLabel(StatusText);

    SecToEvent--;

    if(SecToEvent <= 0){
        //wxMessageBox("stopping timer");
        Countdown->Stop();
        //wxMessageBox("timer stopped");

        if(Choice == HIBERNATE){
            //Hibernate now
            StartHibernation();

            //Clear the status text
            Status->SetLabel("");

        }else if(Choice == SLEEP){
            //Sleep now
            StartSleep();

            //Clear the status text
            Status->SetLabel("");
        }else{
            //Nothing
        }
    }

}

void SimpleShutdownFrame::StartHibernation(){
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;

    // Get a token for this process.

    if (!OpenProcessToken(GetCurrentProcess(),
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)){
        wxMessageBox("Something went wrong with privileges, please try running the application as administrator");
        return;
    }


    // Get the LUID for the shutdown privilege.
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
    &tkp.Privileges[0].Luid);

    tkp.PrivilegeCount = 1;  // one privilege to set
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    // Get the shutdown privilege for this process.
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

    if (GetLastError() != ERROR_SUCCESS){
        return;
    }


    if(!SetSuspendState(TRUE, FALSE, FALSE)){
        wxMessageBox("An error occurred, you probably already scheduled a shutdown previously. Please cancel any existing shutdown schedules and try again. If the problem persists try running as administrator", "Information");
    }else{
        //Success
    }
}

void SimpleShutdownFrame::StartSleep(){
    HANDLE hToken;
    TOKEN_PRIVILEGES tkp;

    // Get a token for this process.

    if (!OpenProcessToken(GetCurrentProcess(),
        TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken)){
        wxMessageBox("Something went wrong with privileges, please try running the application as administrator");
        return;
    }


    // Get the LUID for the shutdown privilege.
    LookupPrivilegeValue(NULL, SE_SHUTDOWN_NAME,
    &tkp.Privileges[0].Luid);

    tkp.PrivilegeCount = 1;  // one privilege to set
    tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;

    // Get the shutdown privilege for this process.
    AdjustTokenPrivileges(hToken, FALSE, &tkp, 0, (PTOKEN_PRIVILEGES)NULL, 0);

    if (GetLastError() != ERROR_SUCCESS){
        return;
    }


    if(!SetSuspendState(FALSE, FALSE, FALSE)){
        wxMessageBox("An error occurred, you probably already scheduled a shutdown previously. Please cancel any existing shutdown schedules and try again. If the problem persists try running as administrator", "Information");
    }else{
        //Success
    }
}

void SimpleShutdownFrame::OnForceCheck(wxCommandEvent& event)
{
    force = CheckBoxForce->GetValue();
}


void SimpleShutdownFrame::ToSystemTray(wxCommandEvent &event){
    this->Hide();
}
