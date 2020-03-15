
#include "SymWindow.h"

SymWindow::SymWindow()
{
    _ceasar_toggle.reset(new ToggleButton());
    addAndMakeVisible(_ceasar_toggle.get());
    _ceasar_toggle->setButtonText(CharPointer_UTF8("Цезаря"));
    _ceasar_toggle->addListener(this);

    _scytale_toggle.reset(new ToggleButton());
    addAndMakeVisible(_scytale_toggle.get());
    _scytale_toggle->setButtonText(CharPointer_UTF8("Скитала"));
    _scytale_toggle->addListener(this);

    _vigenere_toggle.reset(new ToggleButton());
    addAndMakeVisible(_vigenere_toggle.get());
    _vigenere_toggle->setButtonText(CharPointer_UTF8("Виженера"));
    _vigenere_toggle->addListener(this);

    _ceasar_toggle->setRadioGroupId(CipherSelectionButtons);
    _scytale_toggle->setRadioGroupId(CipherSelectionButtons);
    _vigenere_toggle->setRadioGroupId(CipherSelectionButtons);

    _init_text_block.reset(new TextEditor());
    addAndMakeVisible(_init_text_block.get());
    _init_text_block->setScrollbarsShown(true);
    _init_text_block->setCaretVisible(true);
    _init_text_block->setPopupMenuEnabled(true);

    _init_text_desc.reset(new Label(CharPointer_UTF8("Исходные данные")));
    addAndMakeVisible(_init_text_desc.get());
    _init_text_desc->setJustificationType(Justification::centredRight);
    _init_text_desc->setEditable(false, false, false);
    _init_text_desc->setColour(TextEditor::textColourId, Colours::black);
    _init_text_desc->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    _key_input_field.reset(new TextEditor());
    addAndMakeVisible(_key_input_field.get());
    _key_input_field->setMultiLine(false);
    _key_input_field->setReturnKeyStartsNewLine(false);
    _key_input_field->setScrollbarsShown(true);
    _key_input_field->setCaretVisible(true);
    _key_input_field->setPopupMenuEnabled(true);

    _key_field_desc.reset(new Label(CharPointer_UTF8("Ключ")));
    addAndMakeVisible(_key_field_desc.get());
    _key_field_desc->setJustificationType(Justification::centredLeft);
    _key_field_desc->setEditable(false, false, false);
    _key_field_desc->setColour(TextEditor::textColourId, Colours::black);
    _key_field_desc->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    _encrypt_button.reset(new TextButton());
    addAndMakeVisible(_encrypt_button.get());
    _encrypt_button->setButtonText(CharPointer_UTF8("Зашифровать"));
    _encrypt_button->addListener(this);
    _encrypt_button->setColour(TextButton::buttonColourId, Colour(0xff2fad2f));

    _decrypt_button.reset(new TextButton());
    addAndMakeVisible(_decrypt_button.get());
    _decrypt_button->setButtonText(CharPointer_UTF8("Расшифровать"));
    _decrypt_button->addListener(this);
    _decrypt_button->setColour(TextButton::buttonColourId, Colour(0xff2fad2f));

    _result_text_desc.reset(new Label(CharPointer_UTF8("Результат")));
    addAndMakeVisible(_result_text_desc.get());
    _result_text_desc->setJustificationType(Justification::centredRight);
    _result_text_desc->setEditable(false, false, false);
    _result_text_desc->setColour(TextEditor::textColourId, Colours::black);
    _result_text_desc->setColour(TextEditor::backgroundColourId, Colour(0x00000000));

    _result_text_block.reset(new TextEditor());
    addAndMakeVisible(_result_text_block.get());
    _result_text_block->setReturnKeyStartsNewLine(false);
    _result_text_block->setScrollbarsShown(true);
    _result_text_block->setCaretVisible(true);
    _result_text_block->setPopupMenuEnabled(true);

    setSize(600, 400);
}

SymWindow::~SymWindow()
{
    _encrypt_button = nullptr;
    _init_text_block = nullptr;
    _init_text_desc = nullptr;
    _key_field_desc = nullptr;
    _key_input_field = nullptr;
    _result_text_desc = nullptr;
    _result_text_block = nullptr;
    _ceasar_toggle = nullptr;
    _scytale_toggle = nullptr;
    _vigenere_toggle = nullptr;
    _decrypt_button = nullptr;
}

//==============================================================================
void SymWindow::paint(Graphics& g)
{
    g.fillAll(Colours::green);
}

void SymWindow::resized()
{
    _ceasar_toggle->setBounds(16, 24, 150, 24);
    _scytale_toggle->setBounds(400, 24, 150, 24);
    _vigenere_toggle->setBounds(200, 24, 150, 24);

    _init_text_desc->setBounds(-29, 79, 200, 56);
    _init_text_block->setBounds(171, 71, 320, 80);

    _key_input_field->setBounds(171, 159, 184, 24);
    _key_field_desc->setBounds(120, 160, 168, 19);

    _encrypt_button->setBounds(128, 208, 150, 24);
    _decrypt_button->setBounds(384, 208, 150, 24);

    _result_text_desc->setBounds(48, 272, 120, 40);
    _result_text_block->setBounds(168, 256, 320, 80);
}

void SymWindow::buttonClicked(Button* buttonThatWasClicked)
{
    if(buttonThatWasClicked == _encrypt_button.get())
    {
    }
    else if(buttonThatWasClicked == _ceasar_toggle.get())
    {
    }
    else if(buttonThatWasClicked == _scytale_toggle.get())
    {
    }
    else if(buttonThatWasClicked == _vigenere_toggle.get())
    {
    }
    else if(buttonThatWasClicked == _decrypt_button.get())
    {
    }
}
