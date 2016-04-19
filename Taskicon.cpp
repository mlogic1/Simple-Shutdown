#include "Taskicon.h"


//Event table
BEGIN_EVENT_TABLE(Taskicon, wxTaskBarIcon)

EVT_TASKBAR_LEFT_DCLICK(Taskicon::OnDoubleClick)

END_EVENT_TABLE()




//Constructor
Taskicon::Taskicon(wxWindow *parent){
    //Set parent pointer
    ParentFrame = parent;

    //Create the icon in windows taskbar
    ic = new wxIcon(wxT("icon.ico"), wxBITMAP_TYPE_ICO);
    SetIcon(*ic, wxT("Simple Shutdown"));


}


//Destructor
Taskicon::~Taskicon(){
    delete ic;
}

//Show the menu
void Taskicon::OnDoubleClick(wxTaskBarIconEvent &event){
    ParentFrame->Show(true);
}






