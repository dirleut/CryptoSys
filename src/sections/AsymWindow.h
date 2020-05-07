#pragma once

#include <sstream>
#include <string>
#include <bitset>
#include <JuceHeader.h>
#include "../lib/Toggles.h"

 // TODO разгрузить класс
class AsymWindow : public Component, public Button::Listener
{
public:
    
    AsymWindow();
    ~AsymWindow();

    void paint(Graphics&) override;
    void resized() override;
    void buttonClicked(Button* clickedButton) override;

    void keyGen();
    void encryptTextSection();
    void calculateTextHash();
    void calculateExponentModulo();
    void factorize();
    
    void decodeToBinary();
    void decodeToHex();
    void decodeToUTF8();

    void createNamedLabel(Label *main, Label *attached, const String &text, Justification justification, Colour textColour, Colour backgroundColour);
    void showMessage(const std::string &message, const std::string &header);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AsymWindow)
    TextButton _keys_gen_button;
    TextButton _apply_key_button;
    TextButton _get_msg_hash_button;

    Label _header;
    Label _key_length_field;
    Label _length_field_desc;

    Label _private_key_field;
    Label _public_key_field;
    Label _private_key_desc;
    Label _public_key_desc;
    
    Label _input_key_field;
    Label _input_key_desc;
    
    Label _msg_hash_field;
    Label _hash_field_desc;

    TextEditor _text_block;

    int _init_key_length = 64;
    RSAKey _private_key;
    RSAKey _public_key;
    RSAKey _key_to_apply = RSAKey();
    
    Label _encoding_desc { {}, CharPointer_UTF8("Кодировка")};
    ToggleButton _bin_encoding_button { CharPointer_UTF8("Двоичная") };
    ToggleButton _hex_encoding_button { CharPointer_UTF8("Hex") };
    ToggleButton _utf8_encoding_button { CharPointer_UTF8("UTF-8") };
    EncodingSelection _selected_encoding;

    Label _input_base_field;
    Label _input_base_desc;
    Label _input_exponent_field;
    Label _input_exponent_desc;
    Label _input_modulus_field;
    Label _input_modulus_desc;
    Label _exponent_modulo_result_field;
    TextButton _calculate_exp_modulo_button;

    Label _input_number_to_factorize_field;
    Label _input_number_to_factorize_desc;
    Label _factorization_result_field;
    TextButton _factorize_button;

    Colour _label_background_colour = Colour::fromHSV(Colours::purple.getHue(), 0.5, 0.3, 1.0);
    const int _size_x = 800;
    const int _size_y = 600;
};
