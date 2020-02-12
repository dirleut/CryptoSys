#pragma once

#include <sstream>
#include <string>
#include <bitset>
#include "../JuceLibraryCode/JuceHeader.h"

class MainComponent : public Component, public Button::Listener
{
public:
    
    MainComponent();
    ~MainComponent();

    void paint(Graphics&) override;
    void resized() override;
    void buttonClicked(Button* clickedButton) override;

    void keyGen();
    void encryptTextSection();
    void showTextHash();
    
    void decodeToBinary();
    void decodeToHex();
    void decodeToUTF8();

    void createNamedLabel(Label *main, Label *attached, const String &text, Justification justification, Colour textColour, Colour backgroundColour);
    void showMessage(const std::string &message, const std::string &header);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainComponent)
    TextButton keysGenerateButton;
    TextButton keyEncrypt;
    TextButton keyHash;

    Label headerLabel;
    Label inputKeyLength;
    Label inputKeyLengthDesc;

    Label privateKeySection;
    Label publicKeySection;
    Label privateKeySectionDesc;
    Label publicKeySectionDesc;
    
    Label keySection;
    Label keySectionDesc;
    
    Label messageHash;
    Label messageHashDesc;

    TextEditor textSection;

    int keyLength = 64;
    RSAKey privateKey;
    RSAKey publicKey;
    RSAKey keyToApply = RSAKey();
    
    Label encodingLabel { {}, CharPointer_UTF8("Кодировка")};
    ToggleButton binEncodingButton { CharPointer_UTF8("Двоичная") };
    ToggleButton hexEncodingButton { CharPointer_UTF8("Hex") };
    ToggleButton utf8EncodingButton { CharPointer_UTF8("UTF-8") };
    
    enum RadioButtonIds { GenderButtons = 1 };
    enum ToggleStates { Binary, Hex, UTF8 };
    ToggleStates curToggleState;

    DialogWindow::LaunchOptions dia;
};
