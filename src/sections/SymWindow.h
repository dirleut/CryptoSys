#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "../lib/Toggles.h"
#include "../lib/SymCiphers.h"
class SymWindow  : public Component,
                   public Button::Listener
{
public:
    SymWindow ();
    ~SymWindow();

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;

private:
    void encryptInitText();
    void decryptInitText();
    void applyCaesar(short shift);
    void applyVigenere(Operation operation);
    void applyScytale(short shift, Operation operation);
    void findKey();
    void showMessage(const std::string &message, const std::string &header);

    ToggleButton _caesar_toggle { CharPointer_UTF8("Цезаря") };
    ToggleButton _scytale_toggle { CharPointer_UTF8("Скитала") };
    ToggleButton _vigenere_toggle { CharPointer_UTF8("Виженера") };

    CipherSelection _selected_cipher = CAESAR;

    TextEditor _init_text_block;
    Label _init_text_desc;
    TextEditor _key_input_field;
    Label _key_field_desc;

    TextButton _encrypt_button;
    TextButton _decrypt_button;
    TextButton _find_key_button;

    TextEditor _result_text_block;
    Label _result_text_desc;

    const int _size_x = 700;
    const int _size_y = 380;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SymWindow)
};
