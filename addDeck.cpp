//
// Created by JK on 29/05/2022.
//

#include "main.h"


int allFrames::frameAddDeck::currentlyChosen=-1;

allFrames::frameAddDeck::frameAddDeck( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
    static backendLogic logic;
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer13;
    bSizer13 = new wxBoxSizer( wxHORIZONTAL );

    m_scrolledWindow2 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    m_scrolledWindow2->SetScrollRate( 5, 5 );
    wxBoxSizer* bSizer15;
    bSizer15 = new wxBoxSizer( wxVERTICAL );


        auto dodaj = [&](int i) {
            auto button = new wxButton(m_scrolledWindow2, i, logic.returnNameOfDeck(i), wxDefaultPosition, wxDefaultSize, 0);
            bSizer15->Add(button, 0, wxEXPAND | wxALL, 5);
            button->Bind(wxEVT_BUTTON, &frameAddDeck::descriptionOfTheDeck, this);
        };

        for(int i=0; i<logic.parser.returnNumberOfDecks();i++){
            dodaj(i);
        }

        b_addDeck = new wxButton( m_scrolledWindow2, wxID_ANY, wxT("Add Deck"), wxDefaultPosition, wxDefaultSize, 0 );
        b_addDeck->SetBackgroundColour(wxColor(0,150,0));
        bSizer15->Add( b_addDeck, 0, wxEXPAND|wxALL, 5);

    m_scrolledWindow2->SetSizer( bSizer15 );
    m_scrolledWindow2->Layout();
    bSizer15->Fit( m_scrolledWindow2 );
    bSizer13->Add( m_scrolledWindow2, 1, wxEXPAND | wxALL, 5 );

    wxBoxSizer* bSizer14;
    bSizer14 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer21;
    bSizer21 = new wxBoxSizer( wxVERTICAL );

    m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("There will be description of a chosen deck`"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL | wxST_NO_AUTORESIZE);
    m_staticText3->Wrap( -1 );
    bSizer21->Add( m_staticText3, 1, wxEXPAND|wxALL, 5 );


    bSizer14->Add( bSizer21, 3, wxEXPAND|wxALL, 5 );

    wxBoxSizer* bSizer20;
    bSizer20 = new wxBoxSizer( wxVERTICAL );

    m_button18 = new wxButton( this, wxID_ANY, wxT("Edytuj"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer20->Add( m_button18, 1, wxEXPAND|wxALL, 5 );

    m_button36 = new wxButton( this, wxID_ANY, wxT("Usuń"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer20->Add( m_button36, 1, wxEXPAND|wxALL, 5 );

    m_button17 = new wxButton( this, wxID_ANY, wxT("Wstecz"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer20->Add( m_button17, 1, wxEXPAND|wxALL, 5 );


    bSizer14->Add( bSizer20, 1, wxEXPAND|wxALL, 5 );


    bSizer13->Add( bSizer14, 2, wxEXPAND|wxALL, 5 );


    this->SetSizer( bSizer13 );
    this->Layout();

    this->Centre( wxBOTH );

    m_button17->Bind(wxEVT_BUTTON, &frameAddDeck::openStart, this);
    m_button18->Bind(wxEVT_BUTTON, &frameAddDeck::openEdit, this);
    m_button36->Bind(wxEVT_BUTTON, &frameAddDeck::deleteChosenDeck, this);
    b_addDeck->Bind(wxEVT_BUTTON,&frameAddDeck::openCreateDeck, this);

}

allFrames::frameAddDeck::~frameAddDeck()
{
}

void allFrames::frameAddDeck::openStart(wxCommandEvent &) {

    auto *frame_add = new frameStart(NULL);
    frame_add->Show(true);
    this->Show(false);

}

void allFrames::frameAddDeck::descriptionOfTheDeck(wxCommandEvent &e) {
    backendLogic logic;
    std::string temp = logic.returnCommentToDeck(e.GetId());
    currentlyChosen=e.GetId();
    m_staticText3->SetLabel(temp);
    m_staticText3->Wrap( -1 );
}

void allFrames::frameAddDeck::dupa(wxCommandEvent &e) {

    backendLogic logic;
    std::cout << logic.returnBackOfCard(1, 1);
    std::cout<<"\n";

}

void allFrames::frameAddDeck::openEdit(wxCommandEvent &e) {

    if(currentlyChosen>=0){
    auto *frame_add = new frameEditDeck(nullptr, currentlyChosen, wxID_ANY);
    frame_add->Show(true);
    this->Show(false);
    }
}

void allFrames::frameAddDeck::openCreateDeck(wxCommandEvent &e) {
    auto *frame_add = new frameEditDeck(nullptr);
    frame_add->Show(true);
    this->Show(false);
}

void allFrames::frameAddDeck::deleteChosenDeck(wxCommandEvent &e) {
    int answer = wxMessageBox("Are You sure You want to delete this deck? \n It will be permamently lost!", "Confirm Deletion",
                              wxYES_NO | wxNO_DEFAULT, this);
    if(answer == wxYES){
        dataBase db;
        backendLogic logic;
        std::string tempQry="DROP TABLE IF EXISTS ";
        std::string tempDeckName=logic.returnNameOfDeck(currentlyChosen);
        std::string tempQry2=";";
        tempQry=tempQry+tempDeckName+tempQry2;
        const char * qry = tempQry.c_str();
        db.mysql_execute_querry(qry);
        this->refresh();
        this->Refresh();        //still have to figure out how to make this shit refresh real time…, not anymore hehe

    }
}


void allFrames::frameAddDeck::refresh() {
    frameAddDeck *frame_choice = new frameAddDeck(NULL);
    frame_choice->Show(true);
    this->Show(false);
}


