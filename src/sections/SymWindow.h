#pragma once
#include <JuceHeader.h>
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
    std::unique_ptr<TextButton> _encrypt_button;
    std::unique_ptr<TextEditor> _init_text_block;
    std::unique_ptr<Label> _init_text_desc;
    std::unique_ptr<Label> _key_field_desc;
    std::unique_ptr<TextEditor> _key_input_field;
    std::unique_ptr<Label> _result_text_desc;
    std::unique_ptr<TextEditor> _result_text_block;
    std::unique_ptr<ToggleButton> _ceasar_toggle;
    std::unique_ptr<ToggleButton> _scytale_toggle;
    std::unique_ptr<ToggleButton> _vigenere_toggle;
    std::unique_ptr<TextButton> _decrypt_button;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SymWindow)
};
