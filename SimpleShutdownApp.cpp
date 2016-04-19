/***************************************************************
 * Name:      SimpleShutdownApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Filip Radić (multilogic@outlook.com)
 * Created:   2016-04-15
 * Copyright: Filip Radić ()
 * License:
 **************************************************************/

#include "SimpleShutdownApp.h"

//(*AppHeaders
#include "SimpleShutdownMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(SimpleShutdownApp);

bool SimpleShutdownApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	SimpleShutdownFrame* Frame = new SimpleShutdownFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
