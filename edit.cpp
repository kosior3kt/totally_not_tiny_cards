//
// Created by JK on 29/05/2022.
//

#include "main.h"

int currentlyChosen_edit = -1;
int currentCard=-1;
allFrames::frameEditDeck::frameEditDeck( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{

    this->SetMinSize(wxSize(600, 900));
    if(currentlyChosen_edit==-1){
        createDeck();
    }
    currentlyChosen_edit = logic.returnNumberOfDecks()-1;
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer13;
    bSizer13 = new wxBoxSizer( wxHORIZONTAL );

    m_scrolledWindow2 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    m_scrolledWindow2->SetScrollRate( 5, 5 );
    wxBoxSizer* bSizer15;
    bSizer15 = new wxBoxSizer( wxVERTICAL );



    auto dodaj = [&](int i) {
        auto button = new wxButton(m_scrolledWindow2, i, logic.returnFrontOfCard(currentlyChosen_edit,i), wxDefaultPosition, wxDefaultSize, 0);
        bSizer15->Add(button, 0, wxEXPAND | wxALL, 5);
        button->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::updateCurrentlyChosen, this);
    };

    for(int i=0; i<logic.returnNumberOfCardsInDeck(currentlyChosen_edit);i++){
        dodaj(i);
    }


    m_button8 = new wxButton( m_scrolledWindow2, wxID_ANY, wxT("Add Card!!!"), wxDefaultPosition, wxDefaultSize, 0 );
    m_button8->SetForegroundColour(wxColour(0,150,0));
    m_button8->SetBackgroundColour(wxColour(0,150,0));
    bSizer15->Add( m_button8, 0, wxEXPAND|wxALL, 5 );


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

    m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxT("This is the front of the card"), wxDefaultPosition, wxDefaultSize, wxHSCROLL );
    bSizer21->Add( m_textCtrl3, 1, wxEXPAND|wxALL, 5 );

    m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("INPUT BACK HERE"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText7->Wrap( -1 );
    bSizer21->Add( m_staticText7, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

    m_textCtrl4 = new wxTextCtrl( this, wxID_ANY, wxT("This is the back od the card"), wxDefaultPosition, wxDefaultSize, wxHSCROLL );
    bSizer21->Add( m_textCtrl4, 1, wxEXPAND|wxALL, 5 );


    b_dodaj = new wxButton( this, wxID_ANY, wxT("ZATWIERDZ KARTE"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer21->Add( b_dodaj, 1, wxEXPAND|wxALL, 5 );

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

    b_zmien_opis = new wxButton( this, wxID_ANY, wxT("ZATWIERDZ OPIS I NAZWE"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer21->Add( b_zmien_opis, 1, wxEXPAND|wxALL, 5 );

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


    b_cancel->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::openAddWithoutSaving, this);
    m_button18->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::openAdd, this);

    /// test :<
    b_dodaj->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::addCard, this);
    m_button17->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::deleteCard, this);
    ///test bardziej nawet!!!!

    b_zmien_opis->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::changeDeckNameAndComment, this);
    m_button8->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::setCurrentChosenToAddMode, this);

}

allFrames::frameEditDeck::frameEditDeck( wxWindow* parent,int number, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{


    this->SetMinSize(wxSize(600, 900));

    currentlyChosen_edit = number;
    this->SetSizeHints( wxDefaultSize, wxDefaultSize );

    wxBoxSizer* bSizer13;
    bSizer13 = new wxBoxSizer( wxHORIZONTAL );

    m_scrolledWindow2 = new wxScrolledWindow( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxHSCROLL|wxVSCROLL );
    m_scrolledWindow2->SetScrollRate( 5, 5 );
    wxBoxSizer* bSizer15;
    bSizer15 = new wxBoxSizer( wxVERTICAL );


    auto dodaj = [&](int i) {
        auto button = new wxButton(m_scrolledWindow2, i, logic.returnFrontOfCard(currentlyChosen_edit,i), wxDefaultPosition, wxDefaultSize, 0);
        bSizer15->Add(button, 0, wxEXPAND | wxALL, 5);
        button->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::updateCurrentlyChosen, this);
    };

    for(int i=0; i<logic.returnNumberOfCardsInDeck(currentlyChosen_edit);i++){
        dodaj(i);
    }

    m_button8 = new wxButton( m_scrolledWindow2, wxID_ANY, wxT("Add Card!!"), wxDefaultPosition, wxDefaultSize, 0 );
    m_button8->SetForegroundColour(wxColour(0,150,0));
    m_button8->SetBackgroundColour(wxColour(0,150,0));
    bSizer15->Add( m_button8, 0, wxEXPAND|wxALL, 5 );
    ///////////////////////////////////////////


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

    m_textCtrl3 = new wxTextCtrl( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxHSCROLL );
    bSizer21->Add( m_textCtrl3, 1, wxEXPAND|wxALL, 5 );


    bSizer21->Add( 0, 0, 1, wxEXPAND|wxALL, 5 );

    m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("BACK"), wxDefaultPosition, wxDefaultSize, 0 );
    m_staticText7->Wrap( -1 );
    bSizer21->Add( m_staticText7, 0, wxALIGN_CENTER_HORIZONTAL, 5 );

    m_textCtrl4 = new wxTextCtrl( this, wxID_ANY, wxT(""), wxDefaultPosition, wxDefaultSize, wxHSCROLL );
    bSizer21->Add( m_textCtrl4, 1, wxEXPAND|wxALL, 5 );


    b_dodaj = new wxButton( this, wxID_ANY, wxT("ZATWIERDZ KARTE"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer21->Add( b_dodaj, 1, wxEXPAND|wxALL, 5 );
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


    b_zmien_opis = new wxButton( this, wxID_ANY, wxT("ZATWIERDZ OPIS I NAZWE"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer21->Add( b_zmien_opis, 1, wxEXPAND|wxALL, 5 );



    bSizer14->Add( bSizer21, 3, wxEXPAND|wxALL, 5 );

    wxBoxSizer* bSizer20;
    bSizer20 = new wxBoxSizer( wxHORIZONTAL );

    m_button17 = new wxButton( this, wxID_ANY, wxT("DELETE"), wxDefaultPosition, wxDefaultSize, 0 );
    m_button17->SetForegroundColour(wxColour(150,0,0));
    bSizer20->Add( m_button17, 1, wxEXPAND|wxALL, 5 );

    m_button18 = new wxButton( this, wxID_ANY, wxT("SAVE AND QUIT"), wxDefaultPosition, wxDefaultSize, 0 );
    bSizer20->Add( m_button18, 1, wxEXPAND|wxALL, 5 );



    bSizer14->Add( bSizer20, 1, wxEXPAND|wxALL, 5 );


    bSizer13->Add( bSizer14, 2, wxEXPAND|wxALL, 5 );


    this->SetSizer( bSizer13 );
    this->Layout();

    this->Centre( wxBOTH );

    m_button18->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::openAdd, this);
    /// test
    b_dodaj->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::addCard, this);
    m_button17->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::deleteCard, this);

    /////wiecej testu!!!1

    b_zmien_opis->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::changeDeckNameAndComment, this);
    m_button8->Bind(wxEVT_BUTTON, &allFrames::frameEditDeck::setCurrentChosenToAddMode, this);
}


allFrames::frameEditDeck::~frameEditDeck()
{
}

void allFrames::frameEditDeck::openAdd(wxCommandEvent &) {

    if(!logic.isDeckEmpty(currentlyChosen_edit)){
        editLogic::deleteDeck(currentlyChosen_edit);
        auto *dial = new wxMessageDialog(nullptr,wxT("Cannot save empty deck!!"), wxT("Info"), wxOK);
        dial->ShowModal();
    }
    else if(logic.returnNameOfDeck(currentlyChosen_edit)=="tempDeck"){
        editLogic::deleteDeck(currentlyChosen_edit);
        auto *dial = new wxMessageDialog(nullptr,wxT("Cannot save deck called \"tempDeck\"!!"), wxT("Info"), wxOK);
        dial->ShowModal();
    }
    auto *frame_choice = new frameAddDeck(nullptr);
    currentCard=-1;
    currentlyChosen_edit=-1;


    frame_choice->Show(true);
    this->Show(false);
}

void allFrames::frameEditDeck::openAddWithoutSaving(wxCommandEvent &e) {

    editLogic::deleteDeck(logic.returnNumberOfDecks()-1);
    currentCard=-1;
    currentlyChosen_edit=-1;
    auto *frame_choice = new frameAddDeck(nullptr);
    frame_choice->Show(true);
    this->Show(false);

}

void allFrames::frameEditDeck::renameDeck() {
    wxString str = m_textCtrl5->GetValue();
    std::string temp = const_cast<const char *>((const char *) str.mb_str());

    if(logic.containsWhiteSpaces(temp)){
        auto *dial = new wxMessageDialog(nullptr,wxT("Name Can't contain white spaces!!"), wxT("Info"), wxOK);
        dial->ShowModal();
    }
    else if(!temp.empty()) {
        logic.renameDeck(temp, currentlyChosen_edit);
    }

}

void allFrames::frameEditDeck::addCommentToDeck() {
    wxString str = m_textCtrl6->GetValue();
    std::string temp = const_cast<const char *>((const char *) str.mb_str());
    if(!temp.empty()) {
        logic.setComment(temp, currentlyChosen_edit);
    }

}

void allFrames::frameEditDeck::createDeck() {
    logic.createDeck();
}

void allFrames::frameEditDeck::deleteCard(wxCommandEvent &e) {
    logic.deleteCard(currentCard, currentlyChosen_edit);
    this->refresh();

}

void allFrames::frameEditDeck::addCard(wxCommandEvent &e) {
    wxString tempFrontWX = m_textCtrl3->GetValue();
    wxString tempBackWX = m_textCtrl4->GetValue();
    std::string tempFront = const_cast<const char *>((const char *) tempFrontWX.mb_str());
    std::string tempBack = const_cast<const char *>((const char *) tempBackWX.mb_str());

    if(currentCard==-1){
        logic.insertCard(tempFront, tempBack, currentlyChosen_edit);
    }

    this->refresh();
}

void allFrames::frameEditDeck::updateCurrentlyChosen(wxCommandEvent &e) {
    currentCard = e.GetId();
    this->m_textCtrl3->SetValue(logic.returnFrontOfCard(currentlyChosen_edit, currentCard));
    this->m_textCtrl4->SetValue(logic.returnBackOfCard(currentlyChosen_edit, currentCard));
}

void allFrames::frameEditDeck::refresh() {      ///not sure weather currently chosen will stay or not :<
    auto *frame_choice = new frameEditDeck(this, currentlyChosen_edit, wxID_ANY);
    frame_choice->Show(true);
    this->Show(false);
}

void allFrames::frameEditDeck::changeDeckNameAndComment(wxCommandEvent &e) {
    this->renameDeck();
    this->addCommentToDeck();
}

void allFrames::frameEditDeck::setCurrentChosenToAddMode(wxCommandEvent &e) {       ///moze potem jak mi sie bedzie chcialo - beda 2 mody - dodawania i edycji kart, blah blah blah
    currentCard=-1;
}
