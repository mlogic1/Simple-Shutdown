/***************************************************************
 * Name:      SimpleShutdownApp.h
 * Purpose:   Defines Application Class
 * Author:    Filip Radić (multilogic@outlook.com)
 * Created:   2016-04-15
 * Copyright: Filip Radić ()
 * License:
 **************************************************************/

#ifndef SIMPLESHUTDOWNAPP_H
#define SIMPLESHUTDOWNAPP_H

#include <wx/app.h>

class SimpleShutdownApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // SIMPLESHUTDOWNAPP_H
