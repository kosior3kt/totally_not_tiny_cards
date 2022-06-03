//
// Created by JK on 29/05/2022.
//

#include "main.h"
#include "dataBase.h"

static wxBoxSizer* bSizer21;
int accesors::currentlyChosen=NULL;

frameChooseDeck::frameChooseDeck( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
    accesors::currentlyChosen=NULL;

    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer13;
    bSizer13 = new wxBoxSizer( wxHORIZONTAL);

    m_scrolledWindow2 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    m_scrolledWindow2->SetScrollRate( 5, 5 );

    wxBoxSizer* bSizer15;
    bSizer15 = new wxBoxSizer( wxVERTICAL );

//    m_button8 = new wxButton( m_scrolledWindow2, wxID_ANY, wxT("Dummy deck"), wxDefaultPosition, wxDefaultSize, 0 );
//    bSizer15->Add( m_button8, 0, wxEXPAND|wxALL, 5 );
//
//    m_button19 = new wxButton( m_scrolledWindow2, wxID_ANY, wxT("Dummy Deck 2"), wxDefaultPosition, wxDefaultSize, 0 );
//    bSizer15->Add( m_button19, 0, wxEXPAND|wxALL, 5 );

    dataBaseParser *p = new dataBaseParser;

    auto dodaj = [&](int i) {
        auto button = new wxButton(m_scrolledWindow2, i, p->returnNameOfDeck(i), wxDefaultPosition, wxDefaultSize, 0);
        bSizer15->Add(button, 0, wxEXPAND | wxALL, 5);
        button->Bind(wxEVT_BUTTON, &frameChooseDeck::descriptionOfTheDeck, this);
    };

    for(int i=0; i<p->returnNumberOfDecks();i++){
        dodaj(i);
    }

    m_scrolledWindow2->SetSizer( bSizer15 );
    m_scrolledWindow2->Layout();
    bSizer15->Fit( m_scrolledWindow2 );
    bSizer13->Add( m_scrolledWindow2, 1, wxEXPAND | wxALL, 5 );

    wxBoxSizer* bSizer14;
    bSizer14 = new wxBoxSizer( wxVERTICAL );


    bSizer21 = new wxBoxSizer( wxVERTICAL );

    m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("This is a dummy deck"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
    m_staticText3->Wrap( -1 );
    m_staticText3->SetLabel("...");
    bSizer21->Add( m_staticText3, 1, wxEXPAND, 5 );


    bSizer14->Add( bSizer21, 3, wxEXPAND, 5 );

    wxBoxSizer* bSizer20;
    bSizer20 = new wxBoxSizer( wxHORIZONTAL );

    m_button17 = new wxButton( this, wxID_ANY, wxT("Wstecz"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer20->Add( m_button17, 1, wxEXPAND, 5 );

    m_button18 = new wxButton( this, wxID_ANY, wxT("Wybierz"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer20->Add( m_button18, 1, wxEXPAND, 5 );


    bSizer14->Add( bSizer20, 1, wxEXPAND, 5 );


    bSizer13->Add( bSizer14, 2, wxEXPAND, 5 );


    this->SetSizer( bSizer13 );
    this->Layout();

    this->Centre( wxBOTH );


    m_button17->Bind(wxEVT_BUTTON, &frameChooseDeck::openStart, this);
    m_button18->Bind(wxEVT_BUTTON, &frameChooseDeck::openLesson, this);
}

frameChooseDeck::~frameChooseDeck()
{
}

void frameChooseDeck::openStart(wxCommandEvent &) {
    frameStart *frame_add = new frameStart(NULL);
    frame_add->Show(true);
    this->Show(false);
}


void frameChooseDeck::descriptionOfTheDeck(wxCommandEvent &e) {

    dataBaseParser *tempDataBaseParser = new dataBaseParser();
    tempDataBaseParser->makeItAllWork();
    std::string temp = tempDataBaseParser->returnCommentToDeck(e.GetId());
    m_staticText3->SetLabel(temp);
    m_staticText3->Wrap( -1 );
    accesors::currentlyChosen=e.GetId();

    dataBaseParser * tempDataBaseParser2 = new dataBaseParser();
    tempDataBaseParser2->makeItAllWork();

    std::string name = tempDataBaseParser2->returnNameOfDeck(e.GetId());
    std::string comment = tempDataBaseParser2->returnCommentToDeck(e.GetId());
    std::cout<<"\n\n"<<accesors::currentlyChosen<<"     "<<name<<"    "<<comment<<"     \n\n";  //debugg
    delete tempDataBaseParser;
}

void frameChooseDeck::openLesson(wxCommandEvent &) {
    frameLesson *frame_add = new frameLesson(NULL);
    frame_add->Show(true);
    this->Show(false);
}
