
#include "main.h"

///////////////////////////////////////////////////////////////////////////



///chuj wie, co tu sie dzieje ^^^




bool MyApp::OnInit()
{
    allFrames::frameStart *frame_start = new allFrames::frameStart(nullptr);
    frame_start->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);


