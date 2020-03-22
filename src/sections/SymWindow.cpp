
#include "SymWindow.h"
#include "../lib/SymCiphers.h"
#include "../lib/PopUp.h"

// TODO добавить русский алфавит

SymWindow::SymWindow()
{
    addAndMakeVisible(_caesar_toggle);
    _caesar_toggle.setToggleState(true, dontSendNotification);
    _caesar_toggle.addListener(this);
    addAndMakeVisible(_scytale_toggle);
    _scytale_toggle.addListener(this);
    addAndMakeVisible(_vigenere_toggle);
    _vigenere_toggle.addListener(this);

    _caesar_toggle.setRadioGroupId(CipherSelectionButtons);
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
    _encrypt_button.addListener(this);

    addAndMakeVisible(_decrypt_button);
    _decrypt_button.setButtonText(CharPointer_UTF8("Расшифровать"));
    _decrypt_button.addListener(this);

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
    _caesar_toggle.removeListener(this);
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
    // TODO подписать эти числа чтобы не были магическими
    _caesar_toggle.setBounds(16, 24, 150, 24);
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

void SymWindow::applyCaesar(short shift)
{
    std::string msg = _init_text_block.getTextValue().toString().toStdString();
    if (msg.empty()) {
        return;
    }
    if (!isLatin(msg)) {
        showMessage("Использован не латинский алфавит", "Ошибка");
        return;
    }
    caesar(msg, shift);
    _result_text_block.setText(String(msg));
}

void SymWindow::applyVigenere(bool encrypt)
{
    std::string key = _key_input_field.getTextValue().toString().toStdString();
    std::string msg = _init_text_block.getTextValue().toString().toStdString();
    if (msg.empty()) {
        return;
    }
    if (!isLatin(msg)) {
        showMessage("Использован не латинский алфавит", "Ошибка");
        return;
    }
    vigenere(msg, key, encrypt);
    _result_text_block.setText(String(msg));
}

void SymWindow::buttonClicked(Button* clicked)
{
    if(clicked == &_caesar_toggle) {
        _selected_cipher = CAESAR;
    }
    else if(clicked == &_scytale_toggle) {
        _selected_cipher = SCYTALE;
    }
    else if(clicked == &_vigenere_toggle) {
        _selected_cipher = VIGINERE;
    }
    else if(clicked == &_encrypt_button)
    {
        switch (_selected_cipher) {
            case CAESAR:
            {
                short shift = _key_input_field.getTextValue().toString().getIntValue();
                applyCaesar(shift);
                break;
            }
            case SCYTALE:
            {
                break;
            }
            case VIGINERE:
            {
                applyVigenere(true);
                break;
            }
            default:
                break;
        }
    }
    else if(clicked == &_decrypt_button)
    {
        switch (_selected_cipher) {
            case CAESAR:
            {
                short shift = ENG_ALPHABET_SIZE - _key_input_field.getTextValue().toString().getIntValue();
                applyCaesar(shift);
                break;
            }
            case SCYTALE:
            {
                break;
            }
            case VIGINERE:
            {
                applyVigenere(false);
                break;
            }
            default:
                break;
        }
    }
}

void SymWindow::showMessage(const std::string &message, const std::string &header) {
    auto dialog = std::make_unique<PopUp>(message);
    DialogWindow::showModalDialog(header, dialog.get(), this, Colours::grey, true);
}
