//
// Created by JK on 29/05/2022.
//

#include "main.h"
#include "editLogic.h"

allFrames::frameEditDeck::frameEditDeck( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer13;
    bSizer13 = new wxBoxSizer( wxHORIZONTAL );

    m_scrolledWindow2 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    m_scrolledWindow2->SetScrollRate( 5, 5 );
    wxBoxSizer* bSizer15;
    bSizer15 = new wxBoxSizer( wxVERTICAL );

//    m_button8 = new wxButton( m_scrolledWindow2, wxID_ANY, wxT("EXAMPLE"), wxDefaultPosition, wxDefaultSize, 0 );
//    bSizer15->Add( m_button8, 0, wxEXPAND|wxALL, 5 );

    m_button19 = new wxButton( m_scrolledWindow2, wxID_ANY, wxT("Add Card"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer15->Add( m_button19, 0, wxEXPAND|wxALL, 5 );


    m_scrolledWindow2->SetSizer( bSizer15 );
    m_scrolledWindow2->Layout();
    bSizer15->Fit( m_scrolledWindow2 );
    bSizer13->Add( m_scrolledWindow2, 1, wxEXPAND | wxALL, 5 );

    wxBoxSizer* bSizer14;
    bSizer14 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer21;
    bSizer21 = new wxBoxSizer( wxVERTICAL );

    m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("INPUT FRONT HERE"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText6->Wrap( -1 );
    bSizer21->Add( m_staticText6, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

    m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxHSCROLL );
    bSizer21->Add( m_textCtrl3, 1, wxEXPAND|wxALL, 5 );

    m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("INPUT BACK HERE"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText7->Wrap( -1 );
    bSizer21->Add( m_staticText7, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

    m_textCtrl4 = new wxTextCtrl( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxHSCROLL );
    bSizer21->Add( m_textCtrl4, 1, wxEXPAND|wxALL, 5 );


    bSizer21->Add( 0, 0, 1, wxEXPAND|wxALL, 5 );
    bSizer21->Add( 0, 0, 1, wxEXPAND|wxALL, 5 );


    m_staticText8 = new wxStaticText( this, wxID_ANY, wxT("INPUT DECK NAME HERE"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText8->Wrap( -1 );
    bSizer21->Add( m_staticText8, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

    m_textCtrl5 = new wxTextCtrl( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxHSCROLL );
    bSizer21->Add( m_textCtrl5, 1, wxEXPAND|wxALL, 5 );

    m_staticText9 = new wxStaticText( this, wxID_ANY, wxT("INPUT DECK COMMENT HERE"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText9->Wrap( -1 );
    bSizer21->Add( m_staticText9, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

    m_textCtrl6 = new wxTextCtrl( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxHSCROLL );
    bSizer21->Add( m_textCtrl6, 1, wxEXPAND|wxALL, 5 );


    bSizer21->Add( 0, 0, 1, wxEXPAND|wxALL, 5 );


    bSizer14->Add( bSizer21, 3, wxEXPAND|wxALL, 5 );

    wxBoxSizer* bSizer20;
    bSizer20 = new wxBoxSizer( wxHORIZONTAL );

    m_button17 = new wxButton( this, wxID_ANY, wxT("DELETE"), wxDefaultPosition, wxDefaultSize, 0 );
    m_button17->SetForegroundColour(wxColour(150,0,0));
    bSizer20->Add( m_button17, 1, wxEXPAND|wxALL, 5 );

    m_button18 = new wxButton( this, wxID_ANY, wxT("SAVE AND QUIT"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer20->Add( m_button18, 1, wxEXPAND|wxALL, 5 );

    b_cancel = new wxButton( this, wxID_ANY, wxT("CANCEL"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer20->Add( b_cancel, 1, wxEXPAND|wxALL, 5 );


    bSizer14->Add( bSizer20, 1, wxEXPAND|wxALL, 5 );


    bSizer13->Add( bSizer14, 2, wxEXPAND|wxALL, 5 );


    this->SetSizer( bSizer13 );
    this->Layout();

    this->Centre( wxBOTH );


//    b_cancel
}

allFrames::frameEditDeck::frameEditDeck( wxWindow* parent,int number, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer13;
    bSizer13 = new wxBoxSizer( wxHORIZONTAL );

    m_scrolledWindow2 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    m_scrolledWindow2->SetScrollRate( 5, 5 );
    wxBoxSizer* bSizer15;
    bSizer15 = new wxBoxSizer( wxVERTICAL );

    m_button8 = new wxButton( m_scrolledWindow2, wxID_ANY, wxT("EXAMPLE"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer15->Add( m_button8, 0, wxEXPAND|wxALL, 5 );

    m_button19 = new wxButton( m_scrolledWindow2, wxID_ANY, wxT("Add Card"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer15->Add( m_button19, 0, wxEXPAND|wxALL, 5 );


    m_scrolledWindow2->SetSizer( bSizer15 );
    m_scrolledWindow2->Layout();
    bSizer15->Fit( m_scrolledWindow2 );
    bSizer13->Add( m_scrolledWindow2, 1, wxEXPAND | wxALL, 5 );

    wxBoxSizer* bSizer14;
    bSizer14 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer21;
    bSizer21 = new wxBoxSizer( wxVERTICAL );

    m_staticText6 = new wxStaticText( this, wxID_ANY, wxT("FRONT"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText6->Wrap( -1 );
    bSizer21->Add( m_staticText6, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

    m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxT("This is the front of the card"), wxDefaultPosition, wxDefaultSize, wxHSCROLL );
    bSizer21->Add( m_textCtrl3, 1, wxEXPAND|wxALL, 5 );


    bSizer21->Add( 0, 0, 1, wxEXPAND|wxALL, 5 );

    m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("BACK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText7->Wrap( -1 );
    bSizer21->Add( m_staticText7, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

    m_textCtrl4 = new wxTextCtrl( this, wxID_ANY, wxT("This is the back od the card"), wxDefaultPosition, wxDefaultSize, wxHSCROLL );
    bSizer21->Add( m_textCtrl4, 1, wxEXPAND|wxALL, 5 );


    bSizer21->Add( 0, 0, 1, wxEXPAND|wxALL, 5 );


    bSizer14->Add( bSizer21, 3, wxEXPAND|wxALL, 5 );

    wxBoxSizer* bSizer20;
    bSizer20 = new wxBoxSizer( wxHORIZONTAL );

    m_button17 = new wxButton( this, wxID_ANY, wxT("DELETE"), wxDefaultPosition, wxDefaultSize, 0 );
    m_button17->SetForegroundColour(wxColour(150,0,0));
    bSizer20->Add( m_button17, 1, wxEXPAND|wxALL, 5 );

    m_button18 = new wxButton( this, wxID_ANY, wxT("SAVE AND QUIT"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer20->Add( m_button18, 1, wxEXPAND|wxALL, 5 );

    b_cancel = new wxButton( this, wxID_ANY, wxT("CANCEL"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer20->Add( b_cancel, 1, wxEXPAND|wxALL, 5 );



    bSizer14->Add( bSizer20, 1, wxEXPAND|wxALL, 5 );


    bSizer13->Add( bSizer14, 2, wxEXPAND|wxALL, 5 );


    this->SetSizer( bSizer13 );
    this->Layout();

    this->Centre( wxBOTH );
}


allFrames::frameEditDeck::~frameEditDeck()
{
}

void allFrames::frameEditDeck::openAdd(wxCommandEvent &) {
    frameAddDeck *frame_choice = new frameAddDeck(NULL);
    frame_choice->Show(true);
    this->Show(false);
}

void allFrames::frameEditDeck::openAddWithoutSaving(wxCommandEvent &e) {

    frameAddDeck *frame_choice = new frameAddDeck(NULL);
    frame_choice->Show(true);
    this->Show(false);
}

