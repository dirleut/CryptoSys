
#include "SymWindow.h"

SymWindow::SymWindow()
{
    addAndMakeVisible(_ceasar_toggle);
    addAndMakeVisible(_scytale_toggle);
    addAndMakeVisible(_vigenere_toggle);

    _ceasar_toggle.setRadioGroupId(CipherSelectionButtons);
    _scytale_toggle.setRadioGroupId(CipherSelectionButtons);
    _vigenere_toggle.setRadioGroupId(CipherSelectionButtons);

    addAndMakeVisible(_init_text_block);
    _init_text_block.setScrollbarsShown(true);
    _init_text_block.setCaretVisible(true);
    _init_text_block.setPopupMenuEnabled(true);

    addAndMakeVisible(_init_text_desc);
    _init_text_desc.setText(CharPointer_UTF8("Исходные данные"), dontSendNotification);
    _init_text_desc.setJustificationType(Justification::centredRight);
    _init_text_desc.setEditable(false, false, false);
    _init_text_desc.setColour(TextEditor::textColourId, Colours::black);
    _init_text_desc.setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(_key_input_field);
    _key_input_field.setMultiLine(false);
    _key_input_field.setReturnKeyStartsNewLine(false);
    _key_input_field.setScrollbarsShown(true);
    _key_input_field.setCaretVisible(true);
    _key_input_field.setPopupMenuEnabled(true);

    addAndMakeVisible(_key_field_desc);
    _key_field_desc.setText(CharPointer_UTF8("Ключ"), dontSendNotification);
    _key_field_desc.setJustificationType(Justification::centredLeft);
    _key_field_desc.setEditable(false, false, false);
    _key_field_desc.setColour(TextEditor::textColourId, Colours::black);
    _key_field_desc.setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(_encrypt_button);
    _encrypt_button.setButtonText(CharPointer_UTF8("Зашифровать"));
    _encrypt_button.setColour(TextButton::buttonColourId, Colour(0xff2fad2f));

    addAndMakeVisible(_decrypt_button);
    _decrypt_button.setButtonText(CharPointer_UTF8("Расшифровать"));
    _decrypt_button.addListener(this);
    _decrypt_button.setColour(TextButton::buttonColourId, Colour(0xff2fad2f));

    addAndMakeVisible(_result_text_desc);
    _result_text_desc.setText(CharPointer_UTF8("Результат"), dontSendNotification);
    _result_text_desc.setJustificationType(Justification::centredRight);
    _result_text_desc.setEditable(false, false, false);
    _result_text_desc.setColour(TextEditor::textColourId, Colours::black);
    _result_text_desc.setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    addAndMakeVisible(_result_text_block);
    _result_text_block.setReturnKeyStartsNewLine(false);
    _result_text_block.setScrollbarsShown(true);
    _result_text_block.setCaretVisible(true);
    _result_text_block.setPopupMenuEnabled(true);

    setSize(600, 400);
}

SymWindow::~SymWindow()
{
    _ceasar_toggle.removeListener(this);
    _scytale_toggle.removeListener(this);
    _vigenere_toggle.removeListener(this);
    _encrypt_button.removeListener(this);
    _decrypt_button.removeListener(this);
}

//==============================================================================
void SymWindow::paint(Graphics& g)
{
    g.fillAll(Colours::green);
}

void SymWindow::resized()
{
    _ceasar_toggle.setBounds(16, 24, 150, 24);
    _scytale_toggle.setBounds(400, 24, 150, 24);
    _vigenere_toggle.setBounds(200, 24, 150, 24);

    _init_text_desc.setBounds(-29, 79, 200, 56);
    _init_text_block.setBounds(171, 71, 320, 80);

    _key_input_field.setBounds(171, 159, 184, 24);
    _key_field_desc.setBounds(120, 160, 168, 19);

    _encrypt_button.setBounds(128, 208, 150, 24);
    _decrypt_button.setBounds(384, 208, 150, 24);

    _result_text_desc.setBounds(48, 272, 120, 40);
    _result_text_block.setBounds(168, 256, 320, 80);
}

void SymWindow::buttonClicked(Button* buttonThatWasClicked)
{
    /*
    if(buttonThatWasClicked == _encrypt_button.get())
    {
    }
    else if(buttonThatWasClicked == _ceasar_toggle)
    {
    }
    else if(buttonThatWasClicked == _scytale_toggle)
    {
    }
    else if(buttonThatWasClicked == _vigenere_toggle)
    {
    }
    else if(buttonThatWasClicked == _decrypt_button.get())
    {
    }
     */
}
