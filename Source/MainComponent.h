#pragma once

#include <sstream>
#include <string>
#include <bitset>
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
    void applyKey(const std::string &block);
    void encryptTextSection();
    
    void decodeToBinary();
    void decodeToHex();
    void decodeToUTF8();

    void createNamedLabel(Label *main, Label *attached, const String &text, Justification justification, Colour textColour, Colour backgroundColour);
    void updateToggleState (Button* button, String name);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    TextButton keysGenerateButton;
    TextButton keyEncrypt;

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

    int keyLength = 64;
    RSAKey privateKey;
    RSAKey publicKey;
    RSAKey keyToApply;
    
    Label encodingLabel { {}, CharPointer_UTF8("Кодировка")};
    ToggleButton binEncodingButton { CharPointer_UTF8("Двоичная") };
    ToggleButton hexEncodingButton { CharPointer_UTF8("Hex") };
    ToggleButton utf8EncodingButton { CharPointer_UTF8("UTF-8") };
    
    enum RadioButtonIds { GenderButtons = 1 };
    enum ToggleStates { Binary, Hex, UTF8 };
    ToggleStates curToggleState;
};
