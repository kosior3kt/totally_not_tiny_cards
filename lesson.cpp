//
// Created by JK on 29/05/2022.
//

#include "main.h"

frameLesson::frameLesson( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer2;
    bSizer2 = new wxBoxSizer( wxVERTICAL );

    m_scrolledWindow1 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    m_scrolledWindow1->SetScrollRate( 5, 5 );
    wxBoxSizer* bSizer4;
    bSizer4 = new wxBoxSizer( wxVERTICAL );

    wxBoxSizer* bSizer6;
    bSizer6 = new wxBoxSizer( wxHORIZONTAL );

    m_gauge1 = new wxGauge( m_scrolledWindow1, wxID_ANY, 100, wxDefaultPosition, wxDefaultSize, wxGA_HORIZONTAL );
    m_gauge1->SetValue( 0 );
    bSizer6->Add( m_gauge1, 1, wxALIGN_CENTER_VERTICAL, 5 );


    bSizer4->Add( bSizer6, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer7;
    bSizer7 = new wxBoxSizer( wxHORIZONTAL );

    m_staticText1 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("One Side Of A Given Card"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
    m_staticText1->Wrap( -1 );
    bSizer7->Add( m_staticText1, 1, wxALIGN_CENTER_VERTICAL, 5 );


    bSizer4->Add( bSizer7, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer28;
    bSizer28 = new wxBoxSizer( wxHORIZONTAL );

    m_staticText8 = new wxStaticText( m_scrolledWindow1, wxID_ANY, wxT("???"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTER_HORIZONTAL );
    m_staticText8->Wrap( -1 );
    bSizer28->Add( m_staticText8, 1, wxALL, 5 );


    bSizer4->Add( bSizer28, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer8;
    bSizer8 = new wxBoxSizer( wxHORIZONTAL );

    m_textCtrl1 = new wxTextCtrl( m_scrolledWindow1, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
    bSizer8->Add( m_textCtrl1, 1, wxALIGN_CENTER_VERTICAL, 5 );


    bSizer4->Add( bSizer8, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer9;
    bSizer9 = new wxBoxSizer( wxHORIZONTAL );

    wxBoxSizer* bSizer10;
    bSizer10 = new wxBoxSizer( wxHORIZONTAL );

    wxBoxSizer* bSizer11;
    bSizer11 = new wxBoxSizer( wxVERTICAL );


    bSizer11->Add( 0, 0, 1, wxEXPAND, 5 );


    bSizer10->Add( bSizer11, 1, wxEXPAND, 5 );

    wxBoxSizer* bSizer13;
    bSizer13 = new wxBoxSizer( wxHORIZONTAL );

    m_button7 = new wxButton( m_scrolledWindow1, wxID_ANY, wxT("ZAKOŃCZ"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer13->Add( m_button7, 0, wxALL, 5 );

    m_button8 = new wxButton( m_scrolledWindow1, wxID_ANY, wxT("DALEJ"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer13->Add( m_button8, 0, wxALL, 5 );

    b_sprawdz = new wxButton(m_scrolledWindow1, wxID_ANY,wxT("SUBMIT"), wxDefaultPosition, wxDefaultSize, 0 ) ;
    bSizer13->Add(b_sprawdz, 0, wxALL, 5 );

    bSizer10->Add( bSizer13, 2, wxALIGN_CENTER_VERTICAL, 5 );

    wxBoxSizer* bSizer14;
    bSizer14 = new wxBoxSizer( wxVERTICAL );


    bSizer14->Add( 0, 0, 1, wxEXPAND, 5 );


    bSizer10->Add( bSizer14, 1, wxEXPAND, 5 );


    bSizer9->Add( bSizer10, 1, wxEXPAND, 5 );


    bSizer4->Add( bSizer9, 1, wxEXPAND, 5 );


    m_scrolledWindow1->SetSizer( bSizer4 );
    m_scrolledWindow1->Layout();
    bSizer4->Fit( m_scrolledWindow1 );
    bSizer2->Add( m_scrolledWindow1, 1, wxEXPAND, 5 );


    this->SetSizer( bSizer2 );
    this->Layout();

    this->Centre( wxBOTH );
}

frameLesson::~frameLesson()
{
}