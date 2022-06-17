﻿
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
#include "wx/custombgwin.h"
#include "backendLogic.h"
#include "addLogic.h"
#include "editLogic.h"
#include "lessonLogic.h"

#endif


class MyApp: public wxApp
{
public:
    bool OnInit() override;
};

class allFrames : public MyApp
        {
        private:
            /*
             Jak mi się będzie chcialo, to wstawie tutaj wszystkie deklaracje nowych okien - na razie nie chce mi sie
             */
        public:
    ///////////////////////////////////////////////////////////////////////////////
    /// Class frameStart
    ///////////////////////////////////////////////////////////////////////////////
    class frameStart : public wxFrame
    {
    private:
        void openChoice(wxCommandEvent &);
        void openAdd(wxCommandEvent &);
        void OnExit(wxCommandEvent&);
    protected:
        wxButton* b_start;  //m_button1
        wxButton* b_addDeck;    //m_button2
        wxButton* b_settings;    //m_button3
        wxButton* b_exit;    //m_button4

    public:
        explicit frameStart( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 397,334 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
        ~frameStart() override;
    };
    ///////////////////////////////////////////////////////////////////////////////
    /// Class frameLesson
    ///////////////////////////////////////////////////////////////////////////////
    class frameLesson : public wxFrame
    {
    private:
        std::vector<std::string> front;
        std::vector<std::string> back;
        void openChoice();
        void keyPressed(wxKeyEvent &e);
        void AskUser();
        void showCard(wxCommandEvent &e);
        void showCard();
        void checkCorrectness(wxCommandEvent &);
        void checkCorrectness();
        void showCorrectAnswer(wxCommandEvent &e);
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

        frameLesson( wxWindow* parent,int number,const wxString& title ,wxWindowID id = wxID_ANY , const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL);
        ~frameLesson() override;
    };

    ///////////////////////////////////////////////////////////////////////////////
    /// Class frameChooseDeck
    ///////////////////////////////////////////////////////////////////////////////
    class frameChooseDeck: public wxFrame
    {
    private:
        int currentlyChosen;
        std::string currentlyChosenDeckName;
        backendLogic logic;
        void descriptionOfTheDeck(wxCommandEvent &);
        void openLesson(wxCommandEvent &);
        void openStart(wxCommandEvent &);
    protected:
        wxScrolledWindow* m_scrolledWindow2;
        wxStaticText* m_staticText3;
        wxBoxSizer* bSizer21;
        wxButton* m_button17;        //m_button17
        wxButton* m_button18;        //m_button18
    public:
        explicit frameChooseDeck( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 558,420 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
        ~frameChooseDeck() override;
    };

    ///////////////////////////////////////////////////////////////////////////////
    /// Class frameEditDeck
    ///////////////////////////////////////////////////////////////////////////////
    class frameEditDeck : public wxFrame
    {
    private:
        editLogic logic;
        void deleteCard(wxCommandEvent &e);
        void addCard(wxCommandEvent &e);
        void updateCurrentlyChosen(wxCommandEvent &e);
        void setCurrentChosenToAddMode(wxCommandEvent &e);
        void refresh();
        void createDeck();
        void renameDeck();
        void addCommentToDeck();
        void changeDeckNameAndComment(wxCommandEvent &e);
        void openAdd(wxCommandEvent &e);
        void openAddWithoutSaving(wxCommandEvent &e);
    protected:
        wxScrolledWindow* m_scrolledWindow2;
        wxButton* m_button8;        //m_button8
        wxButton* b_cancel{};        //m_button17
        wxStaticText* m_staticText6;
        wxStaticText* m_staticText8;
        wxStaticText* m_staticText9;
        wxTextCtrl* m_textCtrl3;
        wxTextCtrl* m_textCtrl5;
        wxTextCtrl* m_textCtrl6;
        wxStaticText* m_staticText7;
        wxTextCtrl* m_textCtrl4;
        wxButton* m_button17;        //m_button17
        wxButton* m_button18;        //m_button18
        wxButton* b_dodaj;
        wxButton* b_zmien_opis;

    public:

        explicit frameEditDeck( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
        frameEditDeck( wxWindow* parent, int number, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

        ~frameEditDeck() override;

    };

    ///////////////////////////////////////////////////////////////////////////////
    /// Class frameAddDeck
    ///////////////////////////////////////////////////////////////////////////////
    class frameAddDeck : public wxFrame
    {
    private:
        addLogic logic;
        static int currentlyChosen;
        void deleteChosenDeck(wxCommandEvent &e);
        void openCreateDeck(wxCommandEvent &e);
        void openEdit(wxCommandEvent &e);
        void refresh();
        void descriptionOfTheDeck(wxCommandEvent &);
        void openStart(wxCommandEvent &);
    protected:
        wxScrolledWindow* m_scrolledWindow2;
        wxButton* b_addDeck;        //m_button8
        wxStaticText* m_staticText3;
        wxButton* m_button18;        //m_button18
        wxButton* m_button36;        //m_button36
        wxButton* m_button17;        //m_button17

    public:
        explicit frameAddDeck( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 641,473 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
        ~frameAddDeck() override;
    };
};
