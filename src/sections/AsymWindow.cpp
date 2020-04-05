#include "AsymWindow.h"
#include "../lib/Encoding.h"
#include "../lib/Bignumber.h"
#include "../lib/PopUp.h"

AsymWindow::AsymWindow()
{
    addAndMakeVisible(_header);
    _header.setFont(Font(18.0, Font::bold));
    _header.setText("[ RSA ]", dontSendNotification);
    auto darkPurple = Colours::purple.getHue();
    _header.setColour(Label::backgroundColourId, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    _header.setJustificationType(Justification::centred);
    _header.setColour(Label::textColourId, Colours::white);
    
    createNamedLabel(&_key_length_field, &_length_field_desc, CharPointer_UTF8("Длина ключа"), Justification::right, Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    _key_length_field.setText(String(_init_key_length), dontSendNotification);
    _key_length_field.onTextChange = [this] {
        _init_key_length = _key_length_field.getTextValue().toString().getIntValue();
    };
    
    addAndMakeVisible(_keys_gen_button);
    _keys_gen_button.setButtonText(CharPointer_UTF8("Сгенерировать ключи"));
    _keys_gen_button.onClick = [this] {
        if (_init_key_length > 2048 || _init_key_length < 17){
            showMessage("Длина ключа должна быть в диапазоне от 17 до 2048", "Ошибка");
            return;
        }
        keyGen();
    };
//===================================================================================================
    createNamedLabel(&_private_key_field, &_private_key_desc, CharPointer_UTF8("Закрытый ключ"), Justification::right, Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    _private_key_field.onTextChange = [this]{};
    
    createNamedLabel(&_public_key_field, &_public_key_desc, CharPointer_UTF8("Открытый ключ"), Justification::right, Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    _public_key_field.onTextChange = [this]{};
//===================================================================================================
    createNamedLabel(&_input_key_field, &_input_key_desc, CharPointer_UTF8("Ключ"), Justification::right,
                     Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    _input_key_field.onTextChange = [this] {
        String checkKey = _input_key_field.getTextValue().toString();
        if (!checkKey.containsChar (',')) {
            showMessage("Неправильный формат ключа", "Ошибка");
            return;
        }
        _key_to_apply = RSAKey(checkKey);
    };

    createNamedLabel(&_msg_hash_field, &_hash_field_desc, CharPointer_UTF8("MD5 сообщения"), Justification::right,
                     Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));

//===================================================================================================
    addAndMakeVisible(_apply_key_button);
    _apply_key_button.setButtonText(CharPointer_UTF8("Применить ключ"));
    _apply_key_button.onClick = [this] {
        if (_text_block.getTextValue().toString().toStdString() == "") {
            showMessage("Секция текста пуста", "Ошибка");
            return;
        }
        encryptTextSection();
    };

    addAndMakeVisible(_get_msg_hash_button);
    _get_msg_hash_button.setButtonText(CharPointer_UTF8("Посчитать MD5 от сообщения"));
    _get_msg_hash_button.onClick = [this] {
        showTextHash();
    };
//===================================================================================================
    addAndMakeVisible(_encoding_desc);
    _encoding_desc.setColour(Label::textColourId, Colours::white);
    
    addAndMakeVisible(_bin_encoding_button);
    addAndMakeVisible(_hex_encoding_button);
    addAndMakeVisible(_utf8_encoding_button);

    _utf8_encoding_button.setToggleState(true, dontSendNotification);
    _selected_encoding = UTF8;

    _bin_encoding_button.onClick = [this] {
        decodeToBinary();
    };
    _hex_encoding_button.onClick = [this] {
        decodeToHex();
    };
    _utf8_encoding_button.onClick = [this] {
        decodeToUTF8();
    };

    _bin_encoding_button.setRadioGroupId(EncodingSelectionButtons);
    _hex_encoding_button.setRadioGroupId(EncodingSelectionButtons);
    _utf8_encoding_button.setRadioGroupId(EncodingSelectionButtons);
//===================================================================================================
    addAndMakeVisible(_text_block);
    _text_block.setCaretVisible(true);
    _text_block.setScrollbarsShown(true);
    _text_block.setMultiLine(true);
    _text_block.setText(CharPointer_UTF8("Введите текст для шифрования..."));

    setSize (800, 550);
}
//===================================================================================================
AsymWindow::~AsymWindow()
{
    _keys_gen_button.removeListener(this);
    _apply_key_button.removeListener(this);
    _get_msg_hash_button.removeListener(this);
    _bin_encoding_button.removeListener(this);
    _hex_encoding_button.removeListener(this);
    _utf8_encoding_button.removeListener(this);
}

void AsymWindow::paint (Graphics& g)
{
    auto darkPurple = Colours::purple.getHue();
    g.fillAll(Colour::fromHSV(darkPurple, 0.5, 0.4, 1.0));
}

// Зачем-то нужна
void AsymWindow::buttonClicked(Button *clickedButton) {}

void AsymWindow::keyGen() {
    RSAKey::createKeyPair(_public_key, _private_key, _init_key_length);
    _private_key_field.setText(_private_key.toString(), dontSendNotification);
    _public_key_field.setText(_public_key.toString(), dontSendNotification);
}

void AsymWindow::encryptTextSection() {
    if (!_key_to_apply.isValid()) {
        showMessage("Некорректный ключ", "Ошибка");
        return;
    }
    std::string chars(_text_block.getTextValue().toString().toStdString());
    switch (_selected_encoding) {
        case HEX:
            hexToBinary(chars);
            break;
        case UTF8:
            UTF8ToBinary(chars);
            break;
        case BINARY:
            break;
        default:
            break;
    }

    BigInteger T = fromBinString(chars);
    _key_to_apply.applyToValue(T);
    chars = fromBigInt(T);

    switch (_selected_encoding) {
        case HEX:
            binaryToHex(chars);
            break;
        case UTF8:
            if(!binaryToUTF8(chars)) {
                showMessage("Невозможно закодировать в UTF-8", "Ошибка");
                return;
            }
            break;
        case BINARY:
            break;
        default:
            break;
    }
    _text_block.setText(String(chars));
}

void AsymWindow::showTextHash() {
    std::string chars(_text_block.getTextValue().toString().toStdString());
    if (chars.empty()) {
        showMessage("Пустое сообщение", "Ошибка");
        return;
    }
    switch (_selected_encoding) {
        case BINARY:
            if (!isBinary(chars)) {
                showMessage("Не удалось взять хэш от сообщения", "Ошибка");
                return;
            }
            break;
        case HEX:
            if (!hexToBinary(chars)) {
                showMessage("Не удалось взять хэш от сообщения", "Ошибка");
                return;
            }
            break;
        case UTF8:
            UTF8ToBinary(chars);
            break;
        default:
            break;
    }

    size_t arr_size = (chars.length() / 8) + 1;
    char data[arr_size];
    memset(data, 0, sizeof(arr_size));

    std::stringstream ss(chars);
    int i = 0;
    std::bitset<8> byte;
    while (ss >> byte) {
        data[i++] = char(byte.to_ulong());
    }
    data[arr_size] = '\0';

    MD5 md5((char*)data, strlen(data));
    _msg_hash_field.setText(md5.toHexString(), dontSendNotification);
}

void AsymWindow::decodeToBinary() {
    if (_selected_encoding == BINARY) {
        return;
    }
    std::string chars(_text_block.getTextValue().toString().toStdString());
    switch (_selected_encoding) {
        case HEX:
            if (!hexToBinary(chars)) {
                _bin_encoding_button.setToggleState(false, dontSendNotification);
                _hex_encoding_button.setToggleState(true, dontSendNotification);
                showMessage("Данные представлены не в\nшестнадцатиричной кодировке", "Ошибка");
                return;
            }
            break;
        case UTF8:
            UTF8ToBinary(chars);
            break;
        default:
            break;
    }
    _selected_encoding = BINARY;
    _text_block.setText(String(chars));
}

void AsymWindow::decodeToHex() {
    if (_selected_encoding == HEX) {
        return;
    }
    std::string chars(_text_block.getTextValue().toString().toStdString());
    switch (_selected_encoding) {
        case BINARY:
            if (!binaryToHex(chars)) {
                _hex_encoding_button.setToggleState(false, dontSendNotification);
                _bin_encoding_button.setToggleState(true, dontSendNotification);
                showMessage("Данные представлены не в\nдвоичной кодировке", "Ошибка");
                return;
            }
            break;
        case UTF8:
            UTF8ToBinary(chars);
            binaryToHex(chars);
            break;
        default:
            break;
    }
    _selected_encoding = HEX;
    _text_block.setText(String(chars));
}

void AsymWindow::decodeToUTF8() {
    if (_selected_encoding == UTF8) {
        return;
    }
    std::string chars(_text_block.getTextValue().toString().toStdString());
    switch (_selected_encoding) {
        case BINARY:
            if(!isBinary(chars)) {
                _hex_encoding_button.setToggleState(false, dontSendNotification);
                _bin_encoding_button.setToggleState(true, dontSendNotification);
                showMessage("Данные представлены не в\nдвоичной кодировке", "Ошибка");
                return;
            }
            if(!binaryToUTF8(chars)) {
                _utf8_encoding_button.setToggleState(false, dontSendNotification);
                _bin_encoding_button.setToggleState(true, dontSendNotification);
                showMessage("Невозможно закодировать в UTF-8", "Ошибка");
                return;
            }
            break;
        case HEX:
            if (!hexToBinary(chars)) {
                _utf8_encoding_button.setToggleState(false, dontSendNotification);
                _hex_encoding_button.setToggleState(true, dontSendNotification);
                showMessage("Данные представлены не в\nшестнадцатиричной кодировке", "Ошибка");
                return;
            }
            if(!binaryToUTF8(chars)) {
                _utf8_encoding_button.setToggleState(false, dontSendNotification);
                _hex_encoding_button.setToggleState(true, dontSendNotification);
                showMessage("Невозможно закодировать в UTF-8", "Ошибка");
                return;
            }
            break;
        default:
            break;
    }
    _selected_encoding = UTF8;
    _text_block.setText(String(chars));
}

void AsymWindow::createNamedLabel(Label *main, Label *attached, const String &text,
                                  Justification justification, Colour textColour, Colour backgroundColour) {
    addAndMakeVisible(attached);
    attached->setText(text, dontSendNotification);
    attached->attachToComponent(main, true);
    attached->setColour(Label::textColourId, textColour);
    attached->setJustificationType(justification);
    
    addAndMakeVisible(main);
    main->setEditable(true);
    main->setColour(Label::backgroundColourId, backgroundColour);
}

void AsymWindow::showMessage(const std::string &message, const std::string &header) {
    PopUp* dialog = new PopUp(message);
    DialogWindow::showModalDialog(header, dialog, this, Colours::grey, true);
    delete dialog;
}

void AsymWindow::resized()
{
     // TODO подписать эти числа чтобы не были магическими
    _header.setBounds (10, 10, getWidth() - 20, 35);
    _key_length_field.setBounds (130, 50, 100, 25);
    
    _keys_gen_button.setBounds (getWidth() - 400, 50, 200, 25);
    _private_key_field.setBounds(130, 80, getWidth() - 200, 25);
    _public_key_field.setBounds(130, 110, getWidth() - 200, 25);
    
    _input_key_field.setBounds(180, 170, getWidth() - 250 , 25);
    _apply_key_button.setBounds (180, 200, 200, 25);
    
    _msg_hash_field.setBounds(245, 230, getWidth() - 315 , 25);
    _get_msg_hash_button.setBounds(180, 260, 200, 25);

    _encoding_desc.setBounds(20, 150, 100, 20);
    _bin_encoding_button.setBounds(20, 170, 100, 20);
    _hex_encoding_button.setBounds(20, 190, 150, 20);
    _utf8_encoding_button.setBounds(20, 210, 100, 20);

    _text_block.setBounds(10, 300, getWidth() - 20, getHeight() - 310);
}
