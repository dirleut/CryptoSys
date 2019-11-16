#include "MainComponent.h"
#include "utils.h"

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
    // TODO проверка на правильность длины
    inputKeyLength.onTextChange = [this] {
        keyLength = inputKeyLength.getTextValue().toString().getIntValue();
    };
    
    addAndMakeVisible(keysGenerateButton);
    keysGenerateButton.setButtonText(CharPointer_UTF8("Сгенерировать ключи"));
    keysGenerateButton.onClick = [this] {
        keyGen();
    };
//===================================================================================================
    createNamedLabel(&privateKeySection, &privateKeySectionDesc, CharPointer_UTF8("Закрытый ключ"), Justification::right, Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    privateKeySection.onTextChange = [this]{};
    
    createNamedLabel(&publicKeySection, &publicKeySectionDesc, CharPointer_UTF8("Открытый ключ"), Justification::right, Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    publicKeySection.onTextChange = [this]{};
//===================================================================================================
    createNamedLabel(&keySection, &keySectionDesc, CharPointer_UTF8("Ключ"), Justification::right, Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    keySection.onTextChange = [this]{
        // TODO проверить ключ на правильность
        keyToApply = RSAKey(keySection.getTextValue().toString());
    };
//===================================================================================================
    addAndMakeVisible(keyEncrypt);
    keyEncrypt.setButtonText(CharPointer_UTF8("Применить ключ"));
    keyEncrypt.onClick = [this] {
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
    std::string toEncode(textSection.getTextValue().toString().toStdString());
    std::string bitstr;
    switch (curToggleState) {
        // TODO ошибки
        case Hex:
            bitstr = hexToBinary(toEncode);
            break;
        case UTF8:
            bitstr = UTF8ToBinary(toEncode);
            break;
        case Binary:
            bitstr = toEncode;
            break;
        default:
            break;
    }
    std::cout << bitstr << std::endl;
    BigInteger T = fromBinString(bitstr);
    keyToApply.applyToValue(T);
    //T = modulo(T, keyToApply.part1, keyToApply.part2);
    bitstr = fromBigInt(T);
    std::cout << bitstr << std::endl;
    std::cout << std::endl;

    std::string outstr;
    switch (curToggleState) {
        case Hex:
            outstr = binaryToHex(bitstr);
            break;
        case UTF8:
            outstr = binaryToUTF8(bitstr);
            break;
        case Binary:
            outstr = bitstr;
            break;
        default:
            // TODO ошибки
            break;
    }
    textSection.setText(String(outstr));
}

void MainComponent::decodeToBinary() {
    if (curToggleState == Binary) {
        return;
    }
    std::string toEncode(textSection.getTextValue().toString().toStdString());
    std::string encoded;
    switch (curToggleState) {
        case Hex:
            if(isHex(toEncode)){
                 encoded = hexToBinary(toEncode);
            }
            break;
        case UTF8:
            encoded = UTF8ToBinary(toEncode);
            break;
        default:
            break;
    }
    curToggleState = Binary;
    textSection.setText(String(encoded));
}

void MainComponent::decodeToHex() {
    if (curToggleState == Hex) {
        return;
    }
    std::string toEncode(textSection.getTextValue().toString().toStdString());
    std::string encoded;
    switch (curToggleState) {
        case Binary:
            if(isBinary(toEncode)){
                 encoded = binaryToHex(toEncode);
            }
            break;
        case UTF8:
            toEncode = UTF8ToBinary(toEncode);
            encoded = binaryToHex(toEncode);
            break;
        default:
            break;
    }
    curToggleState = Hex;
    textSection.setText(String(encoded));
}

void MainComponent::decodeToUTF8() {
    if (curToggleState == UTF8) {
        return;
    }
    std::string toEncode(textSection.getTextValue().toString().toStdString());
    std::string encoded;
    switch (curToggleState) {
        case Binary:
            if(isBinary(toEncode)){
                encoded = binaryToUTF8(toEncode);
            }
            break;
        case Hex:
            if(isHex(toEncode)){
                toEncode = hexToBinary(toEncode);
                encoded = binaryToUTF8(toEncode);
            }
            break;
        default:
            break;
    }
    curToggleState = UTF8;
    textSection.setText(String(encoded));
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
