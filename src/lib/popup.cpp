/*
  ==============================================================================

    popup.cpp
    Created: 19 Nov 2019 12:03:10pm

  ==============================================================================
*/
#include "popup.h"

PopUp::PopUp (std::string txt) : text(txt)
{
    okButton.reset (new TextButton ("okButton"));
    addAndMakeVisible (okButton.get());
    okButton->setButtonText (CharPointer_UTF8 ("\xd0\x9e\xd0\x9a"));
    okButton->addListener (this);
    okButton->setColour (TextButton::buttonColourId, Colour (0xff782f92));

    okButton->setBounds (75, 112, 104, 24);

    diaText.reset (new Label ("diaText", TRANS(text)));
    addAndMakeVisible (diaText.get());
    diaText->setFont (Font (14.00f, Font::plain).withTypefaceStyle ("Regular"));
    diaText->setJustificationType (Justification::centred);
    diaText->setEditable (false, false, false);
    diaText->setColour (Label::backgroundColourId, Colour (0xff2e393e));
    diaText->setColour (TextEditor::textColourId, Colours::black);
    diaText->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    diaText->setBounds (10, 16, 230, 80);
    setSize (250, 150);
}

PopUp::~PopUp()
{
    okButton = nullptr;
    diaText = nullptr;
}

//==============================================================================
void PopUp::paint (Graphics& g) {
    g.fillAll (Colour (0xff1b2224));
}

void PopUp::resized()
{}

void PopUp::buttonClicked (Button* buttonThatWasClicked) {
    if (buttonThatWasClicked == okButton.get()) {
        if (DialogWindow* dw = this->findParentComponentOfClass<DialogWindow>()) {
            dw->exitModalState (0);
        }
    }
}
