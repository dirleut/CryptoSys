#include "AsymWindow.h"

#include <string>
#include "../lib/Encoding.h"
#include "../lib/Bignumber.h"
#include "../lib/Analysis.h"
#include "../lib/PopUp.h"

AsymWindow::AsymWindow()
{
    addAndMakeVisible(_header);
    _header.setFont(Font(18.0, Font::bold));
    _header.setText("[ RSA ]", dontSendNotification);
    _header.setColour(Label::backgroundColourId, _label_background_colour);
    _header.setJustificationType(Justification::centred);
    _header.setColour(Label::textColourId, Colours::white);
    
    initializeKeysElements();
    initializeEncodingElements();
    initializeAnalysisElements();
    initializeTextElements();

    setSize(_size_x, _size_y);
}

AsymWindow::~AsymWindow()
{
    _keys_gen_button.removeListener(this);
    _apply_key_button.removeListener(this);
    _get_msg_hash_button.removeListener(this);
    _bin_encoding_button.removeListener(this);
    _hex_encoding_button.removeListener(this);
    _utf8_encoding_button.removeListener(this);
    _calculate_exp_modulo_button.removeListener(this);
    _factorize_button.removeListener(this);
}

void AsymWindow::initializeKeysElements()
{
    createNamedLabel(&_key_length_field, &_length_field_desc, CharPointer_UTF8("Длина ключа"), Justification::right, Colours::white, _label_background_colour);
    _key_length_field.setText(String(_init_key_length), dontSendNotification);
    _key_length_field.onTextChange = [this] {
        _init_key_length = _key_length_field.getTextValue().toString().getIntValue();
    };

    addAndMakeVisible(_keys_gen_button);
    _keys_gen_button.setButtonText(CharPointer_UTF8("Сгенерировать ключи"));
    _keys_gen_button.addListener(this);

    createNamedLabel(&_private_key_field, &_private_key_desc, CharPointer_UTF8("Закрытый ключ"), Justification::right, Colours::white, _label_background_colour);
    _private_key_field.onTextChange = [this]{};

    createNamedLabel(&_public_key_field, &_public_key_desc, CharPointer_UTF8("Открытый ключ"), Justification::right, Colours::white, _label_background_colour);
    _public_key_field.onTextChange = [this]{};

    createNamedLabel(&_input_key_field, &_input_key_desc, CharPointer_UTF8("Ключ"), Justification::right,
                     Colours::white, _label_background_colour);
    _input_key_field.onTextChange = [this] {
        String checkKey = _input_key_field.getTextValue().toString();
        if (!checkKey.containsChar (',')) {
            showMessage("Неправильный формат ключа", "Ошибка");
            return;
        }
        _key_to_apply = RSAKey(checkKey);
    };

    addAndMakeVisible(_apply_key_button);
    _apply_key_button.setButtonText(CharPointer_UTF8("Применить ключ"));
    _apply_key_button.addListener(this);
}

void AsymWindow::initializeEncodingElements() {
    addAndMakeVisible(_encoding_desc);
    _encoding_desc.setColour(Label::textColourId, Colours::white);
    
    addAndMakeVisible(_bin_encoding_button);
    addAndMakeVisible(_hex_encoding_button);
    addAndMakeVisible(_utf8_encoding_button);

    _utf8_encoding_button.setToggleState(true, dontSendNotification);
    _selected_encoding = UTF8;

    _bin_encoding_button.addListener(this);
    _hex_encoding_button.addListener(this);
    _utf8_encoding_button.addListener(this);

    _bin_encoding_button.setRadioGroupId(EncodingSelectionButtons);
    _hex_encoding_button.setRadioGroupId(EncodingSelectionButtons);
    _utf8_encoding_button.setRadioGroupId(EncodingSelectionButtons);
}

void AsymWindow::initializeAnalysisElements() {

    createNamedLabel(&_input_base_field, &_input_base_desc, CharPointer_UTF8("Основание"),
                     Justification::right, Colours::white, _label_background_colour);
    createNamedLabel(&_input_exponent_field, &_input_exponent_desc, CharPointer_UTF8("Степень"),
                     Justification::right, Colours::white, _label_background_colour);
    createNamedLabel(&_input_modulus_field, &_input_modulus_desc, CharPointer_UTF8("Модуль"),
                     Justification::right, Colours::white, _label_background_colour);

    addAndMakeVisible(_exponent_modulo_result_field);
    _exponent_modulo_result_field.setEditable(true);
    _exponent_modulo_result_field.setColour(Label::backgroundColourId, _label_background_colour);

    addAndMakeVisible(_calculate_exp_modulo_button);
    _calculate_exp_modulo_button.setButtonText(CharPointer_UTF8("Рассчитать"));
    _calculate_exp_modulo_button.addListener(this);

    createNamedLabel(&_input_number_to_factorize_field, &_input_number_to_factorize_desc, CharPointer_UTF8("Факторизация"),
                     Justification::right, Colours::white, _label_background_colour);
    addAndMakeVisible(_factorization_result_field);
    _factorization_result_field.setEditable(true);
    _factorization_result_field.setColour(Label::backgroundColourId, _label_background_colour);

    addAndMakeVisible(_factorize_button);
    _factorize_button.setButtonText(CharPointer_UTF8("Факторизовать"));
    _factorize_button.addListener(this);
}

void AsymWindow::initializeTextElements() {
    createNamedLabel(&_msg_hash_field, &_hash_field_desc, CharPointer_UTF8("MD5 сообщения"), Justification::right,
                        Colours::white, _label_background_colour);

    addAndMakeVisible(_get_msg_hash_button);
    _get_msg_hash_button.setButtonText(CharPointer_UTF8("Посчитать MD5 от сообщения"));
    _get_msg_hash_button.addListener(this);

    addAndMakeVisible(_text_block);
    _text_block.setCaretVisible(true);
    _text_block.setScrollbarsShown(true);
    _text_block.setMultiLine(true);
    _text_block.setText(CharPointer_UTF8("Введите текст для шифрования..."));
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

void AsymWindow::paint (Graphics& g)
{
    auto darkPurple = Colours::purple.getHue();
    g.fillAll(Colour::fromHSV(darkPurple, 0.5, 0.4, 1.0));
}

void AsymWindow::buttonClicked(Button *clicked) {
    if (clicked == &_bin_encoding_button) {
        decodeToBinary();
    }
    else if (clicked == &_hex_encoding_button) {
        decodeToHex();
    }
    else if (clicked == &_utf8_encoding_button) {
        decodeToUTF8();
    }
    else if (clicked == &_keys_gen_button) {
        keyGen();
    }
    else if (clicked == &_apply_key_button) {
        encryptTextSection();
    }
    else if (clicked == &_get_msg_hash_button) {
        calculateTextHash();
    }
    else if (clicked == &_calculate_exp_modulo_button) {
        calculateExponentModulo();
    }
    else if (clicked == &_factorize_button) {
        factorizeNumber();
    }
}

void AsymWindow::keyGen() {
    if (_init_key_length > 2048 || _init_key_length < 17){
        showMessage("Длина ключа должна быть в диапазоне от 17 до 2048", "Ошибка");
        return;
    }
    RSAKey::createKeyPair(_public_key, _private_key, _init_key_length);
    _private_key_field.setText(_private_key.toString(), dontSendNotification);
    _public_key_field.setText(_public_key.toString(), dontSendNotification);
}

void AsymWindow::encryptTextSection() {
    std::string chars(_text_block.getTextValue().toString().toStdString());
    if (chars.empty()) {
        showMessage("Секция текста пуста", "Ошибка");
        return;
    }
    if (!_key_to_apply.isValid()) {
        showMessage("Некорректный ключ", "Ошибка");
        return;
    }
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
            // Попробуем перевести сначала в читаемую кодировку
            if (binaryToUTF8(chars)) {
                _utf8_encoding_button.setToggleState(true, dontSendNotification);
                _selected_encoding = UTF8;
            } else {
                binaryToHex(chars);
            }
            break;
        case UTF8:
            if(!binaryToUTF8(chars)) {
                _hex_encoding_button.setToggleState(true, dontSendNotification);
                _selected_encoding = HEX;
                binaryToHex(chars);
            }
            break;
        case BINARY:
            break;
        default:
            break;
    }
    _text_block.setText(String(chars));
}

void AsymWindow::calculateTextHash() {
    std::string chars(_text_block.getTextValue().toString().toStdString());
    if (chars.empty()) {
        showMessage("Секция текста пуста", "Ошибка");
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

    chars += '\0';
    size_t arr_size = (chars.length() / 8) + 1;
    char *data = new char[arr_size]();

    std::stringstream ss(chars);
    int i = 0;
    std::bitset<8> byte;
    while (ss >> byte) {
        data[i++] = char(byte.to_ulong());
    }
    data[arr_size] = '\0';

    MD5 md5((char*)data, strlen(data));
    _msg_hash_field.setText(md5.toHexString(), dontSendNotification);
    delete [] data;
}

void AsymWindow::calculateExponentModulo() {
    std::string str_base = _input_base_field.getTextValue().toString().toStdString();
    std::string str_exponent = _input_exponent_field.getTextValue().toString().toStdString();
    std::string str_modulus = _input_modulus_field.getTextValue().toString().toStdString();
    if (str_base.size() > 9 ||
        str_exponent.size() > 9 ||
        str_modulus.size() > 9)
    {
        showMessage("Размер чисел слишком большой", "Ошибка");
        return;
    }
    
    BigInteger base(_input_base_field.getTextValue().toString().getIntValue());
    BigInteger exponent(_input_exponent_field.getTextValue().toString().getIntValue());
    BigInteger modulus(_input_modulus_field.getTextValue().toString().getIntValue());

    if (base.isNegative() ||
        exponent.isNegative() ||
        modulus.isNegative())
    {
        showMessage("Калькулятор возведения в степень по модулю не поддерживает отрицательные числа", "Ошибка");
        return;
    }

    base.exponentModulo(exponent, modulus);
    int64 result = base.toInt64();
    _exponent_modulo_result_field.setText(String(result), dontSendNotification);
}

// TODO добавить возможность работать с числами большего размера
// Показывать предупреждение с вероятной длительностью вычислений
// Запускать отдельный поток с окном, которое позволит прервать фактроизацию
void AsymWindow::factorizeNumber() {
    std::string str_number = _input_number_to_factorize_field.getTextValue().toString().toStdString();
    if (str_number.empty()) {
        showMessage("Пустое поле", "Ошибка");
        return;
    }
    if (str_number.size() > 10) {
        showMessage("Размер числа слишком большой", "Ошибка");
        return;
    }
    if (str_number.front() == '-') {
        showMessage("Поддерживаются только\nположительные числа", "Ошибка");
        return;
    }

    long long number = std::stoll(str_number);
    if (number == 0) {
        return;
    }

    std::vector<long long> factors = factorize(number);

    std::string result = "";
    for (auto& number : factors) {
        result += std::to_string(number) + " ";
    }
    _factorization_result_field.setText(String(result), dontSendNotification);
}

void AsymWindow::decodeToBinary() {
    if (_selected_encoding == BINARY) {
        return;
    }
    std::string chars(_text_block.getTextValue().toString().toStdString());
    if (chars.empty()) {
        return;
    }
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
    if (chars.empty()) {
        return;
    }
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
    if (chars.empty()) {
        return;
    }
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

void AsymWindow::showMessage(const std::string &message, const std::string &header) {
    auto dialog = std::make_unique<PopUp>(message);
    DialogWindow::showModalDialog(header, dialog.get(), this, Colours::grey, true);
}

void AsymWindow::resized()
{
    const int margin_x = 10;
    const int toggle_pos_x = 20;
    const int toggle_pos_y = 150;
    const int toggle_distance_y = 20;
    const int toggle_size_x = 100;
    const int toggle_size_y = 20;

    const int element_size_x = 200;
    const int element_size_y = 25;
    const int element_pos_x = 130;
    const int element_distance_y = 30;

    const int text_block_size_x = (getWidth() - 20) / 3 * 2;
    const int text_block_pos_y = 300;

    _header.setBounds (margin_x, 10, getWidth() - 20, element_size_y);
    _key_length_field.setBounds (element_pos_x, 50, 100, element_size_y);
    
    _keys_gen_button.setBounds (getWidth() - 400, 50,
                                element_size_x, element_size_y);
    _private_key_field.setBounds(element_pos_x, 80,
                                 getWidth() - element_size_x, element_size_y);
    _public_key_field.setBounds(element_pos_x, 80 + element_distance_y,
                                getWidth() - element_size_x, element_size_y);

    _input_key_field.setBounds(180, 170,
                               getWidth() - element_size_x + 10, element_size_y);
    _apply_key_button.setBounds (180, 170 + element_distance_y,
                                 element_size_x, element_size_y);
    
    _msg_hash_field.setBounds(245, 230,
                              getWidth() - element_size_x - 55, element_size_y);
    _get_msg_hash_button.setBounds(element_pos_x + 50, 230 + element_distance_y,
                                   element_size_x, element_size_y);

    _encoding_desc.setBounds(toggle_pos_x, toggle_pos_y,
                             toggle_size_x, toggle_size_y);
    _bin_encoding_button.setBounds(toggle_pos_x, toggle_pos_y + toggle_distance_y,
                                   toggle_size_x, toggle_size_y);
    _hex_encoding_button.setBounds(toggle_pos_x, toggle_pos_y + 2 * toggle_distance_y,
                                   toggle_size_x + 50, toggle_size_y);
    _utf8_encoding_button.setBounds(toggle_pos_x, toggle_pos_y + 3 * toggle_distance_y,
                                    toggle_size_x, toggle_size_y);

    // TODO подправить размер при изменении размера

    _input_base_field.setBounds(text_block_size_x + 100, text_block_pos_y,
                                getWidth() - _size_x + element_size_x - 30, element_size_y);
    _input_exponent_field.setBounds(text_block_size_x + 100, text_block_pos_y + element_distance_y,
                                getWidth() - _size_x + element_size_x - 30, element_size_y);
    _input_modulus_field.setBounds(text_block_size_x + 100, text_block_pos_y + 2 * element_distance_y,
                                getWidth() - _size_x + element_size_x - 30, element_size_y);

    _exponent_modulo_result_field.setBounds(text_block_size_x + 100, text_block_pos_y + 3 * element_distance_y,
                                getWidth() - _size_x + element_size_x - 30, element_size_y);
    _calculate_exp_modulo_button.setBounds(text_block_size_x + 15, text_block_pos_y + 3 * element_distance_y,
                                    element_size_x - 120, element_size_y);

    _input_number_to_factorize_field.setBounds(text_block_size_x + 110, text_block_pos_y + 5 * element_distance_y,
                                element_size_x - 40, element_size_y);

    _factorize_button.setBounds(text_block_size_x + 70, text_block_pos_y + 6 * element_distance_y,
                                element_size_x - 50, element_size_y);

    _factorization_result_field.setBounds(text_block_size_x + 20, text_block_pos_y + 7 * element_distance_y,
                                element_size_x + 50, element_size_y);

    _text_block.setBounds(margin_x, text_block_pos_y, text_block_size_x, getHeight() - 310);
}
