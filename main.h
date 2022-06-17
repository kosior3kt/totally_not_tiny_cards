
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
    ///this method initializes menu(start) frame
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
        ///this method is used to generate new frame and close current
        void openChoice(wxCommandEvent &);
        ///this method is used to generate new frame and close current
        void openAdd(wxCommandEvent &);
        ///this method is used to clean up memory before leaving application
        void OnExit(wxCommandEvent&);
    protected:
        wxButton* b_start;
        wxButton* b_addDeck;
        wxButton* b_settings;
        wxButton* b_exit;

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
        ///this method is used to generate new frame and close current
        void openChoice();
        ///this method is used to listen for a key presses during a lesson it also helps automate process
        void keyPressed(wxKeyEvent &e);
        ///this method makes sure, that user is aware that closing app will mean losing progress
        void AskUser();
        ///this method is responsible for showing a card, when button is being pressed
        void showCard(wxCommandEvent &e);
        ///this method is responsible for showing a card without button being pressed (used in other functions)
        void showCard();
        ///this method is responsible for checking correctness of the proposed solution
        void checkCorrectness(wxCommandEvent &);
        ///this method is responsible for checking correctness of a proposed solution but without needing button to be pressed
        void checkCorrectness();
        ///this method is responsible for showing correct solution
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
        ///this method is responsible for showing description of the deck on the screen
        void descriptionOfTheDeck(wxCommandEvent &);
        ///this method is used to generate new frame and close current
        void openLesson(wxCommandEvent &);
        ///this method is used to generate new frame and close current
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
        ///this method is responsible for deleting a card from database
        void deleteCard(wxCommandEvent &e);
        ///this method is responsible for adding a card to the database
        void addCard(wxCommandEvent &e);
        ///this method is responsible for updating which deck is currently chosen
        void updateCurrentlyChosen(wxCommandEvent &e);
        ///this method is responsible for togling between eddit mode and view mode
        void setCurrentChosenToAddMode(wxCommandEvent &e);
        ///this method is responsible for refreshing
        void refresh();
        ///this method is responsible for creating a deck
        void createDeck();
        ///this method is responsible for renaming a deck
        void renameDeck();
        ///this method is resopnsible for edditing a comment to a deck
        void addCommentToDeck();
        ///this method is responsible for changing name and comment of a deck when the button is being pressed
        void changeDeckNameAndComment(wxCommandEvent &e);
        ///this method is used to generate new frame and close current
        void openAdd(wxCommandEvent &e);
        ///this method is used to generate new frame and close current but without deck being created
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
        ///this method is responsible for deleting currently chosen deck
        void deleteChosenDeck(wxCommandEvent &e);
        ///this method is responsible for opening currently chosen deck
        void openCreateDeck(wxCommandEvent &e);
        ///this method is responsible for creating new frame and closing current
        void openEdit(wxCommandEvent &e);
        ///this method is responsible for refreshing current frame
        void refresh();
        ///this method is responsible for printing description of a deck to the static text field
        void descriptionOfTheDeck(wxCommandEvent &);
        ///this method is responsible for creating new frame and closing current
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
