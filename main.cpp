
#include "main.h"
#include "dataBase.h"

///////////////////////////////////////////////////////////////////////////



///chuj wie, co tu sie dzieje ^^^


class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

bool MyApp::OnInit()
{
    frameStart *frame_start = new frameStart(NULL);
    frame_start->Show(true);


    /*
//
//    frameLesson *frame_lesson = new frameLesson(NULL);
//    frame_lesson->Show( true );

//    frameChoice *frame_choice = new frameChoice(NULL);
//    frame_choice->Show( true );

//    frameEditDeck *frame_edit = new frameEditDeck(NULL);
//    frame_edit->Show( true );
//
//    frameAddDecks *frame_add = new frameAddDecks(NULL);
//    frame_add->Show( true );
     */


    return true;
}

wxIMPLEMENT_APP(MyApp);