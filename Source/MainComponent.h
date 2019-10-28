#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
    This component lives inside our window, and this is where you should put all
    your controls and content.
*/
class MainComponent : public Component, public Button::Listener
{
public:
    
MainComponent();
    ~MainComponent();

    void paint(Graphics&) override;
    void resized() override;
    void buttonClicked(Button* clickedButton) override;
    void keyGen();
    void createNamedLabel(Label *main, Label *attached, const String &text, Justification justification, Colour textColour, Colour backgroundColour);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    TextButton keysGenerateButton;
    TextButton keyEncrypt;
    TextButton keyDecrypt;

    Label headerLabel;
    Label inputKeyLength;
    Label inputKeyLengthDesc;

    Label privateKeySection;
    Label publicKeySection;
    Label privateKeySectionDesc;
    Label publicKeySectionDesc;
    
    Label keySection;
    Label keySectionDesc;
    
    TextEditor textSection;

    int keyLength;
    RSAKey privateKey;
    RSAKey publicKey;
};
