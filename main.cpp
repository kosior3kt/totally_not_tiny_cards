
#include "main.h"
bool MyApp::OnInit(){
    auto *frame_start = new allFrames::frameStart(nullptr);
    frame_start->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);
