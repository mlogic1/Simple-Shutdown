#ifndef TASKICON_H
#define TASKICON_H

#include <wx/menu.h>
#include <wx/taskbar.h>
#include <wx/msgdlg.h>
#include <wx/icon.h>
#include <wx/window.h>
#include <wx/notifmsg.h>



class Taskicon:public wxTaskBarIcon{
private:

    wxIcon *ic;
    wxWindow *ParentFrame;

    //Taskbar handlers
    void OnDoubleClick(wxTaskBarIconEvent &event);


public:
    Taskicon(wxWindow *parent);

    ~Taskicon();


    DECLARE_EVENT_TABLE()
};



#endif // TASKICON_H
