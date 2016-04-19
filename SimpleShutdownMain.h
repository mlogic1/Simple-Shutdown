/***************************************************************
 * Name:      SimpleShutdownMain.h
 * Purpose:   Defines Application Frame
 * Author:    Filip Radić (multilogic@outlook.com)
 * Created:   2016-04-15
 * Copyright: Filip Radić ()
 * License:
 **************************************************************/

#ifndef SIMPLESHUTDOWNMAIN_H
#define SIMPLESHUTDOWNMAIN_H

#define SHUTDOWN    0
#define REBOOT      1
#define HIBERNATE   2
#define SLEEP       3


#include "Instructions.h"
#include "Taskicon.h"
#include <wx/timer.h>


extern "C"
{
	#include <powrprof.h>
}

//(*Headers(SimpleShutdownFrame)
#include <wx/stattext.h>
#include <wx/menu.h>
#include <wx/checkbox.h>
#include <wx/statline.h>
#include <wx/radiobut.h>
#include <wx/statbox.h>
#include <wx/panel.h>
#include <wx/choice.h>
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/statusbr.h>
//*)

class SimpleShutdownFrame: public wxFrame
{
    public:

        SimpleShutdownFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~SimpleShutdownFrame();

    private:

        //(*Handlers(SimpleShutdownFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnButton2Click(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnForceCheck(wxCommandEvent& event);
        //*)


        void OnTimerTick(wxTimerEvent &event);



        void OnInstructions(wxCommandEvent &event);
        void ToSystemTray(wxCommandEvent &event);

        //(*Identifiers(SimpleShutdownFrame)
        static const long ID_STATICBOX1;
        static const long ID_RADIOBUTTON1;
        static const long ID_RADIOBUTTON2;
        static const long ID_CHECKBOX1;
        static const long ID_STATICBOX2;
        static const long ID_STATICTEXT1;
        static const long ID_CHOICE1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_STATICTEXT4;
        static const long ID_CHOICE2;
        static const long ID_CHOICE3;
        static const long ID_BUTTON1;
        static const long ID_BUTTON2;
        static const long ID_STATICLINE1;
        static const long ID_RADIOBUTTON3;
        static const long ID_RADIOBUTTON4;
        static const long ID_PANEL1;
        static const long ID_SYSTEMTRAY;
        static const long ID_EXIT;
        static const long ID_INSTRUCTIONS;
        static const long ID_ABOUT;
        static const long ID_STATUSBAR1;
        //*)

        static const long ID_TIMER;

        //(*Declarations(SimpleShutdownFrame)
        wxStaticText* StaticText2;
        wxRadioButton* RadioButtonRestart;
        wxMenuItem* MenuItem2;
        wxButton* Button1;
        wxMenuItem* MenuItem1;
        wxMenuItem* MenuItem4;
        wxRadioButton* RadioButtonShutdown;
        wxPanel* Panel1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText3;
        wxChoice* ChoiceM;
        wxStaticBox* StaticBox1;
        wxMenu* Menu1;
        wxButton* Button2;
        wxStaticBox* StaticBox2;
        wxMenuItem* MenuItem3;
        wxRadioButton* RadioButtonSleep;
        wxChoice* ChoiceS;
        wxStatusBar* StatusBar1;
        wxStaticLine* StaticLine1;
        wxMenuBar* MenuBar1;
        wxMenu* Menu2;
        wxStaticText* StaticText4;
        wxRadioButton* RadioButtonHibernate;
        wxChoice* ChoiceH;
        wxCheckBox* CheckBoxForce;
        //*)

        wxBitmap Checkbox;
        wxStaticText *Status;
        Taskicon *TrayIcon;

        wxTimer *Countdown;
        int SecToEvent;


        void Restart();
        void Shutdown();
        void Sleep();
        void Hibernate();


        void StartHibernation();
        void StartSleep();


        bool force;
        int timeout;
        int CalculateTimeout();
        int GetChoice();    //Shutdown type
        int Choice;  //Choice variable

        DECLARE_EVENT_TABLE()
};

#endif // SIMPLESHUTDOWNMAIN_H
