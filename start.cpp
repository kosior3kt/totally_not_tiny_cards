//
// Created by JK on 29/05/2022.
//

#include "main.h"

allFrames::frameStart::frameStart( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{

    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer10;
    bSizer10 = new wxBoxSizer( wxHORIZONTAL );


    bSizer10->Add( 0, 0, 1, wxEXPAND|wxALL, 5 );

    wxBoxSizer* bSizer11;
    bSizer11 = new wxBoxSizer( wxVERTICAL );


    bSizer11->Add( 0, 0, 1, wxEXPAND|wxALL, 5 );

    b_addDeck = new wxButton( this, wxID_ANY, wxT("START"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer11->Add( b_addDeck, 0, wxEXPAND|wxALL, 5 );

    b_start = new wxButton( this, wxID_ANY, wxT("NOWA TALIA"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer11->Add( b_start, 0, wxEXPAND|wxALL, 5 );

    b_settings = new wxButton( this, wxID_ANY, wxT("USTAWIENIA"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer11->Add( b_settings, 0, wxEXPAND|wxALL, 5 );

    b_exit = new wxButton( this, wxID_ANY, wxT("EXIT"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer11->Add( b_exit, 0, wxEXPAND|wxALL, 5 );


    bSizer11->Add( 0, 0, 1, wxEXPAND|wxALL, 5 );


    bSizer10->Add( bSizer11, 1, wxEXPAND|wxALL, 5 );


    bSizer10->Add( 0, 0, 1, wxEXPAND|wxALL, 5 );


    this->SetSizer( bSizer10 );
    this->Layout();
    this->Centre( wxBOTH );

    b_start->Bind(wxEVT_BUTTON, &frameStart::openAdd, this);       //chyba musza byc na odwrot te guziki ale nwm czemu niby
    b_addDeck->Bind(wxEVT_BUTTON, &frameStart::openChoice, this);
    b_exit->Bind(wxEVT_BUTTON, &frameStart::OnExit, this);
}

allFrames::frameStart::~frameStart()
= default;

void allFrames::frameStart::openChoice(wxCommandEvent &) {
    auto *frame_add = new frameChooseDeck(nullptr);
    frame_add->Show(true);
    this->Show(false);
}

void allFrames::frameStart::openAdd(wxCommandEvent &) {
    auto *frame_choice = new frameAddDeck(nullptr);
    frame_choice->Show(true);
    this->Show(false);
}

void allFrames::frameStart::OnExit(wxCommandEvent& event) {
    Close( true );
    this->Destroy();
}


