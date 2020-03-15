#pragma once
#include <JuceHeader.h>
#include "../lib/Toggles.h"
// TODO разгрузить конструктор
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

    ToggleButton _ceasar_toggle { CharPointer_UTF8("Цезаря") };
    ToggleButton _scytale_toggle { CharPointer_UTF8("Скитала") };
    ToggleButton _vigenere_toggle { CharPointer_UTF8("Виженера") };

    CipherSelection _selected_cipher;

    TextButton _encrypt_button;
    TextEditor _init_text_block;
    Label _init_text_desc;
    Label _key_field_desc;
    TextEditor _key_input_field;
    Label _result_text_desc;
    TextEditor _result_text_block;
    TextButton _decrypt_button;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SymWindow)
};
