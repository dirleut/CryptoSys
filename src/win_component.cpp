#include "win_component.h"
#include "lib/encoding.h"
#include "lib/bignumber.h"
#include "lib/popup.h"

MainComponent::MainComponent()
{
    //addChildComponent(headerLabel);
    //headerLabel.setVisible(true);
    addAndMakeVisible(headerLabel);
    headerLabel.setFont(Font(18.0, Font::bold));
    headerLabel.setText("[ RSA ]", dontSendNotification);
    auto darkPurple = Colours::purple.getHue();
    headerLabel.setColour(Label::backgroundColourId, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    headerLabel.setJustificationType(Justification::centred);
    headerLabel.setColour(Label::textColourId, Colours::white);
    
    createNamedLabel(&inputKeyLength, &inputKeyLengthDesc, CharPointer_UTF8("Длина ключа"), Justification::right, Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    inputKeyLength.setText(String(keyLength), dontSendNotification);
    inputKeyLength.onTextChange = [this] {
        keyLength = inputKeyLength.getTextValue().toString().getIntValue();
    };
    
    addAndMakeVisible(keysGenerateButton);
    keysGenerateButton.setButtonText(CharPointer_UTF8("Сгенерировать ключи"));
    keysGenerateButton.onClick = [this] {
        if (keyLength > 2048 || keyLength < 17){
            showMessage("Длина ключа должна быть в диапазоне от 17 до 2048", "Ошибка");
            return;
        }
        keyGen();
    };
//===================================================================================================
    createNamedLabel(&privateKeySection, &privateKeySectionDesc, CharPointer_UTF8("Закрытый ключ"), Justification::right, Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    privateKeySection.onTextChange = [this]{};
    
    createNamedLabel(&publicKeySection, &publicKeySectionDesc, CharPointer_UTF8("Открытый ключ"), Justification::right, Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    publicKeySection.onTextChange = [this]{};
//===================================================================================================
    createNamedLabel(&keySection, &keySectionDesc, CharPointer_UTF8("Ключ"), Justification::right,
                     Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    keySection.onTextChange = [this] {
        keyToApply = RSAKey();
        String checkKey = keySection.getTextValue().toString();
        if (!checkKey.containsChar (',')) {
            showMessage("Неправильный формат ключа", "Ошибка");
            return;
        }
        keyToApply = RSAKey(checkKey);
    };
//===================================================================================================
    addAndMakeVisible(keyEncrypt);
    keyEncrypt.setButtonText(CharPointer_UTF8("Применить ключ"));
    keyEncrypt.onClick = [this] {
        if (textSection.getTextValue().toString().toStdString() == "") {
            showMessage("Секция текста пуста", "Ошибка");
            return;
        }
        encryptTextSection();
    };
//===================================================================================================
    addAndMakeVisible(encodingLabel);
    encodingLabel.setColour(Label::textColourId, Colours::white);
    
    addAndMakeVisible(binEncodingButton);
    addAndMakeVisible(hexEncodingButton);
    addAndMakeVisible(utf8EncodingButton);

    utf8EncodingButton.setToggleState(true, dontSendNotification);
    curToggleState = UTF8;

    binEncodingButton.onClick = [this] {
        decodeToBinary();
    };
    hexEncodingButton.onClick = [this] {
        decodeToHex();
    };
    utf8EncodingButton.onClick = [this] {
        decodeToUTF8();
    };

    binEncodingButton.setRadioGroupId(GenderButtons);
    hexEncodingButton.setRadioGroupId(GenderButtons);
    utf8EncodingButton.setRadioGroupId(GenderButtons);
//===================================================================================================
    addAndMakeVisible(textSection);
    textSection.setCaretVisible(true);
    textSection.setScrollbarsShown(true);
    textSection.setMultiLine(true);
    textSection.setText(CharPointer_UTF8("Введите текст для шифрования..."));

    setSize (800, 450);
}
//===================================================================================================
MainComponent::~MainComponent()
{
    keysGenerateButton.removeListener(this);
    keyEncrypt.removeListener(this);
    binEncodingButton.removeListener(this);
    hexEncodingButton.removeListener(this);
    utf8EncodingButton.removeListener(this);
}

void MainComponent::paint (Graphics& g)
{
    auto darkPurple = Colours::purple.getHue();
    g.fillAll(Colour::fromHSV(darkPurple, 0.5, 0.4, 1.0));
    
   // g.setColour(Colours::darkorange);
   // auto centralArea = getLocalBounds().toFloat().reduced (10.0f);
   // g.drawRoundedRectangle (centralArea, 5.0f, 3.0f);

    //g.setFont (Font (18.0f));
    //g.setColour (Colours::lightgrey);
    //g.drawText ("[ RSA ]", getLocalBounds(), Justification::centredTop, true);
}

// Зачем-то нужна
void MainComponent::buttonClicked(Button *clickedButton) {}

void MainComponent::keyGen() {
    RSAKey::createKeyPair(publicKey, privateKey, keyLength);
    privateKeySection.setText(privateKey.toString(), dontSendNotification);
    publicKeySection.setText(publicKey.toString(), dontSendNotification);
}

void MainComponent::encryptTextSection() {
    if (!keyToApply.isValid()) {
        showMessage("Некорректный ключ", "Ошибка");
        return;
    }
    std::string chars(textSection.getTextValue().toString().toStdString());
    switch (curToggleState) {
        case Hex:
            hexToBinary(chars);
            break;
        case UTF8:
            UTF8ToBinary(chars);
            break;
        case Binary:
            break;
        default:
            break;
    }

    BigInteger T = fromBinString(chars);
    keyToApply.applyToValue(T);
    chars = fromBigInt(T);

    switch (curToggleState) {
        case Hex:
            binaryToHex(chars);
            break;
        case UTF8:
            if(!binaryToUTF8(chars)) {
                showMessage("Невозможно закодировать в UTF-8", "Ошибка");
                return;
            }
            break;
        case Binary:
            break;
        default:
            break;
    }
    textSection.setText(String(chars));
}

void MainComponent::decodeToBinary() {
    if (curToggleState == Binary) {
        return;
    }
    std::string chars(textSection.getTextValue().toString().toStdString());
    switch (curToggleState) {
        case Hex:
            if (!hexToBinary(chars)) {
                binEncodingButton.setToggleState(false, dontSendNotification);
                hexEncodingButton.setToggleState(true, dontSendNotification);
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
    curToggleState = Binary;
    textSection.setText(String(chars));
}

void MainComponent::decodeToHex() {
    if (curToggleState == Hex) {
        return;
    }
    std::string chars(textSection.getTextValue().toString().toStdString());
    switch (curToggleState) {
        case Binary:
            if (!binaryToHex(chars)) {
                hexEncodingButton.setToggleState(false, dontSendNotification);
                binEncodingButton.setToggleState(true, dontSendNotification);
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
    curToggleState = Hex;
    textSection.setText(String(chars));
}

void MainComponent::decodeToUTF8() {
    if (curToggleState == UTF8) {
        return;
    }
    std::string chars(textSection.getTextValue().toString().toStdString());
    switch (curToggleState) {
        case Binary:
            if(!isBinary(chars)) {
                hexEncodingButton.setToggleState(false, dontSendNotification);
                binEncodingButton.setToggleState(true, dontSendNotification);
                showMessage("Данные представлены не в\nдвоичной кодировке", "Ошибка");
                return;
            }
            if(!binaryToUTF8(chars)) {
                utf8EncodingButton.setToggleState(false, dontSendNotification);
                binEncodingButton.setToggleState(true, dontSendNotification);
                showMessage("Невозможно закодировать в UTF-8", "Ошибка");
                return;
            }
            break;
        case Hex:
            if (!hexToBinary(chars)) {
                utf8EncodingButton.setToggleState(false, dontSendNotification);
                hexEncodingButton.setToggleState(true, dontSendNotification);
                showMessage("Данные представлены не в\nшестнадцатиричной кодировке", "Ошибка");
                return;
            }
            if(!binaryToUTF8(chars)) {
                utf8EncodingButton.setToggleState(false, dontSendNotification);
                hexEncodingButton.setToggleState(true, dontSendNotification);
                showMessage("Невозможно закодировать в UTF-8", "Ошибка");
                return;
            }
            break;
        default:
            break;
    }
    curToggleState = UTF8;
    textSection.setText(String(chars));
}

void MainComponent::createNamedLabel(Label *main, Label *attached, const String &text, Justification justification, Colour textColour, Colour backgroundColour) {
    addAndMakeVisible(attached);
    attached->setText(text, dontSendNotification);
    attached->attachToComponent(main, true);
    attached->setColour(Label::textColourId, textColour);
    attached->setJustificationType(justification);
    
    addAndMakeVisible(main);
    main->setEditable(true);
    main->setColour(Label::backgroundColourId, backgroundColour);
    main->onTextChange = [this]{};
}

void MainComponent::showMessage(const std::string &message, const std::string &header) {
    PopUp* dialog = new PopUp(message);
    DialogWindow::showModalDialog(header, dialog, this, Colours::grey, true);
    delete dialog;
}

void MainComponent::resized()
{
    headerLabel.setBounds (10, 10, getWidth() - 20, 35);
    inputKeyLength.setBounds (130, 50, 100, 25);
    
    keysGenerateButton.setBounds (getWidth() - 400, 50, 200, 25);
    privateKeySection.setBounds(130, 80, getWidth() - 200, 25);
    publicKeySection.setBounds(130, 110, getWidth() - 200, 25);
    
    keySection.setBounds(180, 170, getWidth() - 250 , 25);
    keyEncrypt.setBounds (180, 200, 200, 25);
    
    encodingLabel.setBounds(20, 150, 100, 20);
    binEncodingButton.setBounds(20, 170, 100, 20);
    hexEncodingButton.setBounds(20, 190, 150, 20);
    utf8EncodingButton.setBounds(20, 210, 100, 20);

    textSection.setBounds(10, 240, getWidth() - 20, getHeight() - 250);
}
