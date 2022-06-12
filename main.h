
#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/button.h>
#include <wx/string.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/frame.h>
#include <wx/gauge.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/scrolwin.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#include "backendLogic.h"
#endif


class MyApp: public wxApp
{
public:
    virtual bool OnInit();
};

class allFrames : public MyApp
        {
        public:



    ///////////////////////////////////////////////////////////////////////////////
    /// Class frameStart
    ///////////////////////////////////////////////////////////////////////////////
    class frameStart : public wxFrame
    {
    private:

    protected:
        wxButton* b_start;  //m_button1
        wxButton* b_addDeck;    //m_button2
        wxButton* b_settings;    //m_button3
        wxButton* b_exit;    //m_button4

    public:

        frameStart( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 397,334 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
        ///Methody cos tam cos tam sraken pierdaken
        void openChoice(wxCommandEvent &);
        void openAdd(wxCommandEvent &);
        void OnExit(wxCommandEvent&);
        ~frameStart();
    };
    ///////////////////////////////////////////////////////////////////////////////
    /// Class frameLesson
    ///////////////////////////////////////////////////////////////////////////////
    class frameLesson : public wxFrame
    {
    private:
        std::vector<std::string> front;
        std::vector<std::string> back;
    protected:
        wxScrolledWindow* m_scrolledWindow1;
        wxGauge* m_gauge1;
        wxStaticText* m_staticText1;
        wxStaticText* m_staticText8;
        wxTextCtrl* m_textCtrl1;
        wxButton* m_button7;        //m_button7
        wxButton* m_button8;        //m_button8
        wxButton* b_sprawdz;

    public:

        frameLesson( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 620,497 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

        ~frameLesson();

    };

    ///////////////////////////////////////////////////////////////////////////////
    /// Class frameChooseDeck
    ///////////////////////////////////////////////////////////////////////////////
    class frameChooseDeck: public wxFrame
    {
    private:
    protected:
        wxScrolledWindow* m_scrolledWindow2;
        wxButton* m_button8;        //m_button8
        wxButton* m_button19;        //m_button19
        wxStaticText* m_staticText3;
        wxButton* m_button17;        //m_button17
        wxButton* m_button18;        //m_button18

    public:
//         int integer;
//         wxStaticText staticText;
//          static int currentlyChosen;
        frameChooseDeck( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 558,420 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
        void descriptionOfTheDeck(wxCommandEvent &);
        void openLesson(wxCommandEvent &);
        void openStart(wxCommandEvent &);

        ~frameChooseDeck();

    };

    ///////////////////////////////////////////////////////////////////////////////
    /// Class frameEditDeck
    ///////////////////////////////////////////////////////////////////////////////
    class frameEditDeck : public wxFrame
    {
    private:
    protected:
        wxScrolledWindow* m_scrolledWindow2;
        wxButton* m_button8;        //m_button8
        wxButton* m_button19;        //m_button19
        wxStaticText* m_staticText6;
        wxTextCtrl* m_textCtrl3;
        wxStaticText* m_staticText7;
        wxTextCtrl* m_textCtrl4;
        wxButton* m_button17;        //m_button17
        wxButton* m_button18;        //m_button18

    public:

        frameEditDeck( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 612,454 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

        ~frameEditDeck();

    };

    ///////////////////////////////////////////////////////////////////////////////
    /// Class frameAddDeck
    ///////////////////////////////////////////////////////////////////////////////
    class frameAddDeck : public wxFrame
    {
    private:
    protected:
        wxScrolledWindow* m_scrolledWindow2;
        wxButton* m_button8;        //m_button8
        wxButton* m_button19;        //m_button19
        wxStaticText* m_staticText3;
        wxButton* m_button18;        //m_button18
        wxButton* m_button36;        //m_button36
        wxButton* m_button17;        //m_button17

    public:
        int integer;

        wxStaticText staticText;
        frameAddDeck( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 641,473 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
        void descriptionOfTheDeck(wxCommandEvent &);
        void openStart(wxCommandEvent &);
        void dupa(wxCommandEvent &);

        ~frameAddDeck();

    };


};



///////////////////////////////////////////////////////////////////////////////
/// Class accessors
///////////////////////////////////////////////////////////////////////////////
class accesors{
private:
public:
    static int currentlyChosen;
};