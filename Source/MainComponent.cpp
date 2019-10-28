#include "MainComponent.h"

MainComponent::MainComponent()
{
    addAndMakeVisible(headerLabel);
    headerLabel.setFont(Font(18.0, Font::bold));
    headerLabel.setText("[ RSA ]", dontSendNotification);
    auto darkPurple = Colours::purple.getHue();
    headerLabel.setColour(Label::backgroundColourId, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    headerLabel.setJustificationType(Justification::centred);
    headerLabel.setColour(Label::textColourId, Colours::white);
    
    createNamedLabel(&inputKeyLength, &inputKeyLengthDesc, CharPointer_UTF8("Длина ключа"), Justification::right, Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
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
    privateKeySection.onTextChange = [this]{};
//===================================================================================================
    createNamedLabel(&keySection, &keySectionDesc, CharPointer_UTF8("Ключ"), Justification::right, Colours::white, Colour::fromHSV(darkPurple, 0.5, 0.3, 1.0));
    privateKeySection.onTextChange = [this]{};
//===================================================================================================
    addAndMakeVisible(keyEncrypt);
    keyEncrypt.setButtonText(CharPointer_UTF8("Зашифровать"));
    keyEncrypt.onClick = [this]{};
    
    addAndMakeVisible(keyDecrypt);
    keyDecrypt.setButtonText(CharPointer_UTF8("Расшифровать"));
    keyDecrypt.onClick = [this]{};

    setSize (600, 400);
}
MainComponent::~MainComponent()
{
    keysGenerateButton.removeListener(this);
    keyEncrypt.removeListener(this);
    keyDecrypt.removeListener(this);
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

// Мусор
void MainComponent::buttonClicked(Button *clickedButton) {
    if(clickedButton == &keysGenerateButton){
        headerLabel.setText("keys", dontSendNotification);
    }
}

void MainComponent::keyGen() {
    RSAKey::createKeyPair(publicKey, privateKey, keyLength);
    privateKeySection.setText(privateKey.toString(), dontSendNotification);
    publicKeySection.setText(publicKey.toString(), dontSendNotification);
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
    inputKeyLength.setBounds (105, 50, getWidth() - 500, 25);
    
    keysGenerateButton.setBounds (350, 50, getWidth() - 400, 25);
    privateKeySection.setBounds(105, 80, getWidth() - 200, 25);
    publicKeySection.setBounds(105, 110, getWidth() - 200, 25);
    
    keySection.setBounds(105, 160, getWidth() - 200 , 25);
    
    keyEncrypt.setBounds (105, 190, getWidth() - 500, 25);
    keyDecrypt.setBounds (getWidth() - 295, 190, getWidth() - 500, 25);
}
