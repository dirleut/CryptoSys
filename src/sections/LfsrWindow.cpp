#include "LfsrWindow.h"

#include <string>
#include <sstream>
#include <iostream>
#include <stdlib.h>
#include "../lib/Encoding.h"
#include "../lib/PopUp.h"
#include "../lib/Toggles.h"
using namespace std;


LfsrWindow::LfsrWindow (){
    buttonToBS.reset (new TextButton ("buttonToBS"));
    addAndMakeVisible (buttonToBS.get());
    buttonToBS->setTooltip (CharPointer_UTF8 ("\xd0\x9f\xd0\xb5\xd1\x80\xd0\xb5\xd0\xb2\xd0\xb5\xd1\x81\xd1\x82\xd0\xb8 \xd0\xb2 \xd0\xb4\xd0\xb2\xd0\xbe\xd0\xb8\xd1\x87\xd0\xbd\xd1\x83\xd1\x8e \xd1\x81\xd0\xb8\xd1\x81\xd1\x82\xd0\xb5\xd0\xbc\xd1\x83\n"));
    buttonToBS->setButtonText (CharPointer_UTF8 ("\xd0\x9f\xd0\xb5\xd1\x80\xd0\xb5\xd0\xb2\xd0\xb5\xd1\x81\xd1\x82\xd0\xb8 \xd0\xb2 \xd0\xb4\xd0\xb2\xd0\xbe\xd0\xb8\xd1\x87\xd0\xbd\xd1\x83\xd1\x8e"));
    buttonToBS->addListener (this);
    buttonToBS->setColour (TextButton::buttonColourId, Colour (0xff4a4a4a));
    buttonToBS->setColour (TextButton::buttonOnColourId, Colour (0xff0d0d0d));

    tb0.reset(new ToggleButton("tb0"));
    addAndMakeVisible(tb0.get());
    tb0->setButtonText(TRANS("1"));
    tb0->addListener(this);

    tb1.reset (new ToggleButton ("tb1"));
    addAndMakeVisible (tb1.get());
    tb1->setButtonText (TRANS("2"));
    tb1->addListener (this);

    tb2.reset (new ToggleButton ("tb2"));
    addAndMakeVisible (tb2.get());
    tb2->setButtonText (TRANS("3"));
    tb2->addListener (this);

    tb3.reset (new ToggleButton ("tb3"));
    addAndMakeVisible (tb3.get());
    tb3->setButtonText (TRANS("4"));
    tb3->addListener (this);

    tb4.reset (new ToggleButton ("tb4"));
    addAndMakeVisible (tb4.get());
    tb4->setButtonText (TRANS("5"));
    tb4->addListener (this);

    tb5.reset (new ToggleButton ("tb5"));
    addAndMakeVisible (tb5.get());
    tb5->setButtonText (TRANS("6"));
    tb5->addListener (this);

    tb6.reset (new ToggleButton ("tb6"));
    addAndMakeVisible (tb6.get());
    tb6->setButtonText (TRANS("7"));
    tb6->addListener (this);

    tb7.reset (new ToggleButton ("tb7"));
    addAndMakeVisible (tb7.get());
    tb7->setButtonText (TRANS("8"));
    tb7->addListener (this);


    addAndMakeVisible(initValue);
    initValue.setMultiLine(false);
    initValue.setReturnKeyStartsNewLine(false);
    initValue.setReadOnly(false);
    initValue.setScrollbarsShown(true);
    initValue.setCaretVisible(true);
    initValue.setPopupMenuEnabled(false);
    initValue.setColour(TextEditor::backgroundColourId, Colour(0x88495358));
    initValue.setText(String());

    //keyGamma.reset (new TextEditor ("keyGamma"));
    addAndMakeVisible (keyGamma);
    keyGamma.setMultiLine (true);
    keyGamma.setReturnKeyStartsNewLine (false);
    keyGamma.setReadOnly (true);
    keyGamma.setScrollbarsShown (true);
    keyGamma.setCaretVisible (false);
    keyGamma.setPopupMenuEnabled (false);
    keyGamma.setColour (TextEditor::backgroundColourId, Colour (0x88495358));
    keyGamma.setText (String());

    buttonShift.reset (new TextButton ("buttonShift"));
    addAndMakeVisible (buttonShift.get());
    buttonShift->setButtonText (CharPointer_UTF8 ("\xd0\xa1\xd0\xb4\xd0\xb2\xd0\xb8\xd0\xb3 \xd1\x80\xd0\xb5\xd0\xb3\xd0\xb8\xd1\x81\xd1\x82\xd1\x80\xd0\xb0"));
    buttonShift->addListener (this);
    buttonShift->setColour (TextButton::buttonColourId, Colour (0xff4a4a4a));
    buttonShift->setColour (TextButton::buttonOnColourId, Colour (0xff212122));

    addAndMakeVisible(userText);
    userText.setMultiLine(true);
    userText.setText(CharPointer_UTF8 ("Введите текст..."));
   // userText.setText(CharPointer_UTF8 ("\xd0\x92\xd0\xb2\xd0\xb5\xd0\xb4\xd0\xb8\xd1\x82\xd0\xb5 \xd1\x82\xd0\xb5\xd0\xba\xd1\x81\xd1\x82 \xd0\xb4\xd0\xbb\xd1\x8f \n"));
    userText.setReturnKeyStartsNewLine(true);
    userText.setReadOnly(false);
    userText.setScrollbarsShown(true);
    userText.setCaretVisible(true);
    userText.setPopupMenuEnabled(false);
    userText.setColour(TextEditor::backgroundColourId, Colour(0xff282a2c));
    //userText.setText(CharPointer_UTF8 ("\xd0\x92\xd0\xb2\xd0\xb5\xd0\xb4\xd0\xb8\xd1\x82\xd0\xb5 \xd1\x82\xd0\xb5\xd0\xba\xd1\x81\xd1\x82 \xd0\xb4\xd0\xbb\xd1\x8f \n"));
    //userText.setText(CharPointer_UTF8("\xd0\x92\xd0\xb2\xd0\xb5\xd0\xb4\xd0\xb8\xd1\x82\xd0\xb5 \xd1\x82\xd0\xb5\xd0\xba\xd1\x81\xd1\x82 \xd0\xb4\xd0\xbb\xd1\x8f \n"));
    //userText.setText(CharPointer_UTF8("������� ����� ���\n����������..."));



    label.reset (new Label ("new label",
                            CharPointer_UTF8 ("\xd0\x9d\xd0\xb0\xd1\x87\xd0\xb0\xd0\xbb\xd1\x8c\xd0\xbd\xd0\xbe\xd0\xb5 \xd0\xb7\xd0\xbd\xd0\xb0\xd1\x87\xd0\xb5\xd0\xbd\xd0\xb8\xd0\xb5\n")));
    addAndMakeVisible (label.get());
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label2.reset (new Label ("new label",
                             CharPointer_UTF8 ("\xd0\x9e\xd1\x82\xd0\xb2\xd0\xbe\xd0\xb4\xd0\xbd\xd0\xb0\xd1\x8f \xd0\xbf\xd0\xbe\xd1\x81\xd0\xbb\xd0\xb5\xd0\xb4\xd0\xbe\xd0\xb2\xd0\xb0\xd1\x82\xd0\xb5\xd0\xbb\xd1\x8c\xd0\xbd\xd0\xbe\xd1\x81\xd1\x82\xd1\x8c\n")));
    addAndMakeVisible (label2.get());
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3.reset (new Label ("new label",
                             CharPointer_UTF8 ("\xd0\x9f\xd1\x81\xd0\xb5\xd0\xb2\xd0\xb4\xd0\xbe\xd1\x81\xd0\xbb\xd1\x83\xd1\x87\xd0\xb0\xd0\xb9\xd0\xbd\xd0\xb0\xd1\x8f \xd0\xbf\xd0\xbe\xd1\x81\xd0\xbb\xd0\xb5\xd0\xb4\xd0\xbe\xd0\xb2\xd0\xb0\xd1\x82\xd0\xb5\xd0\xbb\xd1\x8c\xd0\xbd\xd0\xbe\xd1\x81\xd1\x82\xd1\x8c (\xd0\xba\xd0\xbb\xd1\x8e\xd1\x87)\n"
                             "\n"
                             "\n")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

   
    //label4.reset (new Label ("new label",
                            // CharPointer_UTF8 ("\xd0\xa0\xd0\xb5\xd0\xb7\xd1\x83\xd0\xbb\xd1\x8c\xd1\x82\xd0\xb0\xd1\x82 \xd1\x88\xd0\xb8\xd1\x84\xd1\x80\xd0\xbe\xd0\xb2\xd0\xb0\xd0\xbd\xd0\xb8\xd1\x8f")));
    label4.reset(new Label("new label",
                             CharPointer_UTF8 ("Сгенерированный ключ")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));


    /*label5.reset (new Label ("new label",
                             CharPointer_UTF8 ("\xd0\xa0\xd0\xb5\xd0\xb7\xd1\x83\xd0\xbb\xd1\x8c\xd1\x82\xd0\xb0\xd1\x82 \xd1\x80\xd0\xb0\xd1\x81\xd1\x88\xd0\xb8\xd1\x84\xd1\x80\xd0\xbe\xd0\xb2\xd0\xb0\xd0\xbd\xd0\xb8\xd1\x8f\n"
                             "\n"
                             "\n")));*/
    label5.reset (new Label ("new label",
                             CharPointer_UTF8 ("Результат шифрования"
                             "\n"
                             "\n")));
    addAndMakeVisible (label5.get());
    label5->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    generateKeyGamma.reset (new TextButton ("generateKeyGamma"));
    addAndMakeVisible (generateKeyGamma.get());
    //addAndMakeVisible(generateKeyGamma);
    //generateKeyGamma->setTooltip (CharPointer_UTF8 ("\xd0\x9d\xd0\xb0\xd0\xbb\xd0\xbe\xd0\xb6\xd0\xb8\xd1\x82\xd1\x8c \xd0\xba\xd0\xbb\xd1\x8e\xd1\x87 \xd0\xb4\xd0\xbb\xd1\x8f \xd1\x88\xd0\xb8\xd1\x84\xd1\x80\xd0\xbe\xd0\xb2\xd0\xb0\xd0\xbd\xd0\xb8\xd1\x8f"));
    //generateKeyGamma->setButtonText (CharPointer_UTF8 ("\xd0\x9d\xd0\xb0\xd0\xbb\xd0\xbe\xd0\xb6\xd0\xb8\xd1\x82\xd1\x8c \xd0\xba\xd0\xbb\xd1\x8e\xd1\x87"));
    generateKeyGamma->setButtonText (CharPointer_UTF8 ("Cгенерировать ключ"));
    generateKeyGamma->addListener (this);
    generateKeyGamma->setColour (TextButton::buttonColourId, Colour (0xff4a4a4a));
    generateKeyGamma->setColour (TextButton::buttonOnColourId, Colour (0xff212122));

    keyGammaToEncrypt.reset (new TextEditor ("keyGammaToEncrypt"));
    addAndMakeVisible (keyGammaToEncrypt.get());
    keyGammaToEncrypt->setMultiLine (true);
    keyGammaToEncrypt->setReturnKeyStartsNewLine (true);
    keyGammaToEncrypt->setReadOnly (true);
    keyGammaToEncrypt->setScrollbarsShown (true);
    keyGammaToEncrypt->setCaretVisible (false);
    keyGammaToEncrypt->setPopupMenuEnabled (false);
    keyGammaToEncrypt->setColour (TextEditor::backgroundColourId, Colour (0xff282a2c));
    keyGammaToEncrypt->setText (String());

    resultEncrypt.reset (new TextEditor ("resultEncrypt"));
    addAndMakeVisible (resultEncrypt.get());
    resultEncrypt->setMultiLine (true);
    resultEncrypt->setReturnKeyStartsNewLine (true);
    resultEncrypt->setReadOnly (true);
    resultEncrypt->setScrollbarsShown (true);
    resultEncrypt->setCaretVisible (false);
    resultEncrypt->setPopupMenuEnabled (false);
    resultEncrypt->setColour (TextEditor::backgroundColourId, Colour (0xff282a2c));
    resultEncrypt->setText (String());

    keyToEncrypt.reset (new TextButton ("keyToEncrypt"));
    addAndMakeVisible (keyToEncrypt.get());
    keyToEncrypt->setTooltip (CharPointer_UTF8 ("\xd0\x9d\xd0\xb0\xd0\xbb\xd0\xbe\xd0\xb6\xd0\xb8\xd1\x82\xd1\x8c \xd0\xba\xd0\xbb\xd1\x8e\xd1\x87 \xd0\xb4\xd0\xbb\xd1\x8f \xd1\x80\xd0\xb0\xd1\x81\xd1\x88\xd0\xb8\xd1\x84\xd1\x80\xd0\xbe\xd0\xb2\xd0\xb0\xd0\xbd\xd0\xb8\xd1\x8f"));
    keyToEncrypt->setButtonText (CharPointer_UTF8 ("\xd0\x9d\xd0\xb0\xd0\xbb\xd0\xbe\xd0\xb6\xd0\xb8\xd1\x82\xd1\x8c \xd0\xba\xd0\xbb\xd1\x8e\xd1\x87"));
    keyToEncrypt->addListener (this);
    keyToEncrypt->setColour (TextButton::buttonColourId, Colour (0xff4a4a4a));
    keyToEncrypt->setColour (TextButton::buttonOnColourId, Colour (0xff212122));

    cachedImage__20200518_132617_jpg_1 = ImageCache::getFromMemory (_20200518_132617_jpg, _20200518_132617_jpgSize);

    setSize (780, 530);

    initializeElements();

}

LfsrWindow::~LfsrWindow(){
    buttonToBS = nullptr;
    tb1 = nullptr;
    tb2 = nullptr;
    tb3 = nullptr;
    tb4 = nullptr;
    tb5 = nullptr;
    tb6 = nullptr;
    tb7 = nullptr;
    //keyGamma = nullptr;
    buttonShift = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;
    tb0 = nullptr;
    label5 = nullptr;
    generateKeyGamma = nullptr;
    keyGammaToEncrypt = nullptr;
    resultEncrypt = nullptr;
    keyToEncrypt = nullptr;
}
void LfsrWindow::initializeElements() {
    initValue.onTextChange = [this] {
        std::string resultForwString = "";
        std::string resultString = "";
        std::string initValueText = initValue.getTextValue().toString().toStdString();
        cout << initSequence << '!\n';
        for (int i = 0; i < initValueText.length(); i++) {
            if ((initValueText[i] == '0' || initValueText[i] == '1') && (resultForwString.length() < 8)) {
                resultForwString = resultForwString + initValueText[i];
            }
        }
        const int length = resultForwString.length() - 1;
        for (int i = 0; i < length + 1; i++) {
            int j = length - i;
            resultString = resultString + resultForwString[j];
        }
        initValue.setText(string(resultForwString));
        initSequence = resultString;
    };
}
bool LfsrWindow::checkValidSequence(string sequence){
    bool isValid = false;
    const int length = sequence.length();
    for (int i = 0; i < length; i++) {
        if (sequence[i] == '1') {
            isValid = true;
        }
    }
    return isValid;
}
bool LfsrWindow::checkValidTbs(){
    int count = 0;
    for (int i = 0; i < 8; i++) {
        if (tbs[i] > 0) {
            count++;
        }
    }
    return count > 1;
}
void LfsrWindow::onClickTb(int buttonID){
    if (tbs[buttonID] == 0){
        tbs[buttonID] = 1;
    } else{
        tbs[buttonID] = 0;
    }
}
void LfsrWindow::userTextChange() {
    userTextString = userText.getTextValue().toString().toStdString();
    userText.setText(string(userTextString));
}
std::string LfsrWindow::getOutputBit(string sequence) {
    std::string bit, bit1;
    std::string stringForXOR = "";
    for (int i = 0; i < 8; i++) {
        if (tbs[i] > 0) {
            stringForXOR = stringForXOR + sequence[i];
        }
    }
    return getXORString(stringForXOR);
}
string LfsrWindow::getXORString(string stringForXOR) {
    int stringLength = stringForXOR.length();
    int* arr = new int[stringLength];
    for (int i = 0; i < stringLength; i++) {
       arr[i] = stringForXOR[i]-'0';
    }
    int bit = arr[0];
    for (int i = 1; i < stringLength; i++) {
        bit = bit ^ arr[i];
    }
    return bit == 0 ? "0" : "1";
}
string LfsrWindow::updateSequence(string bit, string prevSequence) {
    string sequence = "";
    const int length = prevSequence.length();
    for (int i = 1; i < length; i++) {
        sequence = sequence + prevSequence[i];
    }
    sequence = sequence + bit;
    return sequence;
}
std::string LfsrWindow::reverseKeyGamma(std::string keyGamma){
    string key = "";
    const int length = keyGamma.length();
    for (int i = 0; i < length; i++) {
        key = key + keyGamma[length - 1 - i];
    }
    return key;
}
bool LfsrWindow::checkValidInput(string sequence) {
    if (!checkValidTbs()) {
        showMessage("Нужно выбрать минимум 2 регистра", "Ошибка");
        return false;
    }
    if (sequence.length() != 8) {
        showMessage("Начальное значение должно содержать 8 бит", "Ошибка");
        return false;
    }
    if (!checkValidSequence(sequence)) {
        showMessage("Начальное значение должно содержать минимум одну единицу", "Ошибка");
        return false;
    }
    return true;
}
bool LfsrWindow::checkBSText(string text) {
    string bit;
    int stringLength = text.length();
    for (int i = 0; i < stringLength; i++) {
        bit = text[i];
        if (bit != "0" && bit !=  "1") {
            return false;
        }

    }
    return true;
}
void LfsrWindow::onClickButtonShift() {
    //initValueSequence = initValue.getTextValue().toString().toStdString();
    if(!checkValidInput(initSequence)){
        return;
    }
    string bit = getOutputBit(initSequence);
    keyGammaString = keyGammaString + initSequence[0];
    string keyGammaOutput = reverseKeyGamma(keyGammaString);
    initSequence = updateSequence(bit, initSequence);
    keyGamma.setText(string(keyGammaOutput));
}
void LfsrWindow::onClickButtonGenerateKeyGamma() {
    string keyGamma, keyGammaStr, bit;
    string userTextToEncrypt = userText.getTextValue().toString().toStdString();
    string initValueSequence = initValue.getTextValue().toString().toStdString();
    int stringLength = userTextToEncrypt.length();
    if (stringLength == 0) {
        showMessage("Строка пустая, введите текст для зашифрования", "Ошибка");
        return;
    }
    if (!checkValidInput(initValueSequence)) {
        return;
    }
    if (!checkBSText(userTextToEncrypt)) {
        showMessage("Приведите исходный текст к бинарному виду", "Ошибка");
        return;
    }
    for (int i = 0; i < stringLength; i++) {
        bit = getOutputBit(initValueSequence);
        keyGammaStr = keyGammaStr + initValueSequence[0];
        initValueSequence = updateSequence(bit, initValueSequence);
    }
    keyGamma = reverseKeyGamma(keyGammaStr);
    keyGammaToEncrypt->setText(String(keyGamma));
}
void LfsrWindow::onClickButtonBS() {
    string userTextToEncrypt = userText.getTextValue().toString().toStdString();
    int stringLength = userTextToEncrypt.length();
    if (stringLength == 0) {
        showMessage("Строка пустая, введите текст для зашифрования", "Ошибка");
        return;
    }
    UTF8ToBinary(userTextToEncrypt);
    userText.setText(string(userTextToEncrypt));
}
void LfsrWindow::onClickButtonEncrypt() {
    string userTextToEncrypt = userText.getTextValue().toString().toStdString();
    if (userTextToEncrypt.length() == 0) {
        showMessage("Строка fпустая, введите текст для зашифрования", "Ошибка");
        return;
    }
    string keyGammaValue = keyGammaToEncrypt->getTextValue().toString().toStdString();
    if (keyGammaValue.length() == 0) {
        showMessage("Сгенерируйте ключ для исходного текста", "Ошибка");
        return;
    }
    string encryptString = getEncryptString(userTextToEncrypt, keyGammaValue);
    binaryToUTF8(encryptString);
    resultEncrypt->setText(String(encryptString));
}
string LfsrWindow::getEncryptString(string textToEncrypt, string keyGammaValue) {
    string result = "";
    int xorBit;
    int stringLength = textToEncrypt.length();
    for (int i = 0; i < stringLength; i++) {
        xorBit = textToEncrypt[i] ^ keyGammaValue[i];
        result = result + (xorBit == 0 ? "0" : "1");
    }
     return result;
}
void LfsrWindow::buttonClicked (Button* buttonThatWasClicked){
    if (buttonThatWasClicked == buttonToBS.get()){
        onClickButtonBS();
    }else if (buttonThatWasClicked == tb0.get()){
        onClickTb(0);
    }else if (buttonThatWasClicked == tb1.get()){
        onClickTb(1);
    }else if (buttonThatWasClicked == tb2.get()){
        onClickTb(2);
    }else if (buttonThatWasClicked == tb3.get()){
        onClickTb(3);
    }else if (buttonThatWasClicked == tb4.get()){
        onClickTb(4);
    }else if (buttonThatWasClicked == tb5.get()){
        onClickTb(5);
    }else if (buttonThatWasClicked == tb6.get()){
        onClickTb(6);
    }else if (buttonThatWasClicked == tb7.get()){
        onClickTb(7);
    }else if (buttonThatWasClicked == buttonShift.get()){
        onClickButtonShift();
    }else if (buttonThatWasClicked == generateKeyGamma.get()){
        onClickButtonGenerateKeyGamma();
    }else if (buttonThatWasClicked == keyToEncrypt.get()){
        onClickButtonEncrypt();
    }
}
void LfsrWindow::showMessage(const std::string message, const std::string header) {
    auto dialog = std::make_unique<PopUp>(message);
    DialogWindow::showModalDialog(header, dialog.get(), this, Colours::grey, true);
}
void LfsrWindow::paint (Graphics& g){
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff5754e3));

    {
        int x = 12, y = 12, width = proportionOfWidth (0.9730f), height = 32;
        Colour fillColour = Colour (0x84454544);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 12, y = 12, width = proportionOfWidth (0.9678f), height = 30;
        String text (CharPointer_UTF8 ("8-\xd0\xb1\xd0\xb8\xd1\x82\xd0\xbd\xd1\x8b\xd0\xb9 \xd0\xb3\xd0\xb5\xd0\xbd\xd0\xb5\xd1\x80\xd0\xb0\xd1\x82\xd0\xbe\xd1\x80 \xd0\xbf\xd1\x81\xd0\xb5\xd0\xb2\xd0\xb4\xd0\xbe\xd1\x81\xd0\xbb\xd1\x83\xd1\x87\xd0\xb0\xd0\xb9\xd0\xbd\xd1\x8b\xd1\x85 \xd1\x87\xd0\xb8\xd1\x81\xd0\xb5\xd0\xbb \xd0\xbd\xd0\xb0 \xd0\xbe\xd1\x81\xd0\xbd\xd0\xbe\xd0\xb2\xd0\xb5 \xd0\xbb\xd0\xb8\xd0\xbd\xd0\xb5\xd0\xb9\xd0\xbd\xd0\xbe\xd0\xb3\xd0\xbe \xd1\x80\xd0\xb5\xd0\xb3\xd0\xb8\xd1\x81\xd1\x82\xd1\x80\xd0\xb0 \xd1\x81\xd0\xb4\xd0\xb2\xd0\xb8\xd0\xb3\xd0\xb0"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Bold"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    {
        int x = 12, y = 60, width = 372, height = 172;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (Colours::black);
        g.drawImage (cachedImage__20200518_132617_jpg_1,
                     x, y, width, height,
                     0, 0, cachedImage__20200518_132617_jpg_1.getWidth(), cachedImage__20200518_132617_jpg_1.getHeight());
    }

    {
        int x = -16, y = 288, width = proportionOfWidth (1.0193f), height = proportionOfHeight (0.5486f);
        Colour fillColour = Colour (0xfff5b460);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 12, y = 244, width = 372, height = 32;
        Colour fillColour = Colour (0x84454544);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = proportionOfWidth (0.3707f), y = 296, width = proportionOfWidth (0.2471f), height = 32;
        Colour fillColour = Colour (0x84454544);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = proportionOfWidth (0.7413f), y = 296, width = proportionOfWidth (0.2471f), height = 32;
        Colour fillColour = Colour (0x84454544);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillRect (x, y, width, height);
    }

    {
        int x = 12, y = 244, width = 372, height = 30;
        String text (CharPointer_UTF8 ("8-\xd0\xb1\xd0\xb8\xd1\x82\xd0\xbd\xd1\x8b\xd0\xb9 \xd1\x80\xd0\xb5\xd0\xb3\xd0\xb8\xd1\x81\xd1\x82\xd1\x80 \xd1\x81\xd0\xb4\xd0\xb2\xd0\xb8\xd0\xb3\xd0\xb0 \xd1\x81 \xd0\xbb\xd0\xb8\xd0\xbd\xd0\xb5\xd0\xb9\xd0\xbd\xd0\xbe\xd0\xb9 \xd0\xbe\xd0\xb1\xd1\x80\xd0\xb0\xd1\x82\xd0\xbd\xd0\xbe\xd0\xb9 \xd1\x81\xd0\xb2\xd1\x8f\xd0\xb7\xd1\x8c\xd1\x8e"));
        Colour fillColour = Colours::white;
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
        g.drawText (text, x, y, width, height,
                    Justification::centred, true);
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}
void LfsrWindow::resized(){
    buttonToBS->setBounds (proportionOfWidth (0.0515f), 296, proportionOfWidth (0.1236f), 32);
    tb0->setBounds(proportionOfWidth(0.5586f), 142, 50, 24);
    tb1->setBounds (proportionOfWidth (0.6075f), 142, 50, 24);
    tb2->setBounds (proportionOfWidth (0.6564f), 142, 50, 24);
    tb3->setBounds (proportionOfWidth (0.7078f), 142, 50, 24);
    tb4->setBounds (proportionOfWidth (0.7593f), 142, 50, 24);
    tb5->setBounds (proportionOfWidth (0.8108f), 142, 50, 24);
    tb6->setBounds (proportionOfWidth (0.8597f), 142, 50, 24);
    tb7->setBounds (proportionOfWidth (0.9112f), 142, 50, 24);
    initValue.setBounds (400, 78, proportionOfWidth (0.4736f), 32);
    keyGamma.setBounds (400, 244, proportionOfWidth (0.4736f), 32);
    buttonShift->setBounds (proportionOfWidth (0.6486f), 182, proportionOfWidth (0.1930f), 24);
    userText.setBounds (proportionOfWidth (0.0039f), 336, proportionOfWidth (0.2535f), 184);
    label->setBounds (proportionOfWidth (0.5148f), 54, proportionOfWidth (0.4736f), 24);
    label2->setBounds (proportionOfWidth (0.5650f), 115, proportionOfWidth (0.3810f), 24);
    label3->setBounds (proportionOfWidth (0.5148f), 216, proportionOfWidth (0.4736f), 24);
    label4->setBounds (proportionOfWidth (0.3707f), 300, proportionOfWidth (0.2471f), 24);
    label5->setBounds (proportionOfWidth (0.7413f), 296, proportionOfWidth (0.2471f), 32);
    //generateKeyGamma->setBounds (proportionOfWidth (0.2626f), 392, proportionOfWidth (0.1030f), 40);
    generateKeyGamma->setBounds (proportionOfWidth (0.2626f), 368, proportionOfWidth (0.1030f), 120);
    keyGammaToEncrypt->setBounds (proportionOfWidth (0.3707f), 336, proportionOfWidth (0.2535f), 184);
    resultEncrypt->setBounds (proportionOfWidth (0.7400f), 336, proportionOfWidth (0.2535f), 184);
    keyToEncrypt->setBounds (proportionOfWidth (0.6306f), 368, proportionOfWidth (0.1030f), 120);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}
//==============================================================================
#if 0
#endif

static const unsigned char resource_LfsrWindow__20200518_132617_jpg[] = { 255,216,255,224,0,16,74,70,73,70,0,1,1,1,0,96,0,96,0,0,255,219,0,67,0,3,2,2,3,2,2,3,3,3,3,4,3,3,4,5,8,5,5,4,4,5,10,7,7,6,8,12,
10,12,12,11,10,11,11,13,14,18,16,13,14,17,14,11,11,16,22,16,17,19,20,21,21,21,12,15,23,24,22,20,24,18,20,21,20,255,219,0,67,1,3,4,4,5,4,5,9,5,5,9,20,13,11,13,20,20,20,20,20,20,20,20,20,20,20,20,20,20,
20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,20,255,192,0,17,8,1,0,2,80,3,1,17,0,2,17,1,3,17,1,255,196,0,29,0,1,1,0,3,1,1,1,1,1,0,0,0,0,0,0,
0,0,7,5,6,8,4,3,2,9,1,255,196,0,89,16,0,0,5,3,1,3,4,9,14,11,6,4,5,5,0,0,0,1,2,3,4,5,6,7,17,8,18,33,19,20,49,65,24,34,56,82,87,116,145,181,210,21,22,35,50,55,66,81,115,117,149,150,178,209,211,39,67,84,
97,103,113,129,148,164,179,180,9,23,53,83,130,161,51,119,132,193,36,52,68,114,162,37,99,147,177,194,255,196,0,26,1,1,0,3,1,1,1,0,0,0,0,0,0,0,0,0,0,0,2,3,4,5,1,6,255,196,0,57,17,1,0,2,2,1,2,4,4,5,1,5,8,
3,0,0,0,0,1,2,3,17,33,18,49,4,19,65,81,34,50,97,113,5,35,82,129,145,66,20,98,130,161,240,21,51,53,114,115,177,178,209,52,162,193,255,218,0,12,3,1,0,2,17,3,17,0,63,0,254,169,128,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,209,114,102,92,131,140,165,208,161,191,69,173,87,
167,86,157,117,168,144,232,145,144,251,170,83,104,229,23,170,84,180,244,36,140,248,107,208,96,53,190,200,103,252,21,100,111,153,154,251,240,14,200,103,252,21,100,111,153,154,251,240,14,200,103,252,21,
100,111,153,154,251,240,14,200,103,252,21,100,111,153,154,251,240,14,200,103,252,21,100,111,153,154,251,240,24,139,75,107,40,87,197,2,53,106,141,141,114,20,218,108,147,89,52,251,52,150,22,149,110,45,72,
86,134,153,6,71,162,146,101,211,212,3,47,217,12,255,0,130,172,141,243,51,95,126,1,217,12,255,0,130,172,141,243,51,95,126,1,217,12,255,0,130,172,141,243,51,95,126,1,217,12,255,0,130,172,141,243,51,95,126,
3,17,83,218,202,21,30,191,69,162,203,198,185,9,154,149,96,222,76,38,21,73,96,148,247,36,141,247,55,72,228,106,122,39,137,232,71,167,88,12,191,100,51,254,10,178,55,204,205,125,248,7,100,51,254,10,178,55,
204,205,125,248,7,100,51,254,10,178,55,204,205,125,248,7,100,51,254,10,178,55,204,205,125,248,7,100,51,254,10,178,55,204,205,125,248,12,69,167,181,148,43,222,129,26,181,70,198,185,10,109,58,66,156,75,
79,179,73,97,105,81,161,106,109,90,26,100,25,30,138,74,139,167,168,6,95,178,25,255,0,5,89,27,230,102,190,252,3,178,25,255,0,5,89,27,230,102,190,252,3,178,25,255,0,5,89,27,230,102,190,252,3,178,25,255,
0,5,89,27,230,102,190,252,6,34,169,181,148,42,53,126,139,69,151,141,114,19,53,26,202,158,76,38,21,73,96,148,241,180,223,40,230,233,27,250,158,137,226,122,17,233,214,3,47,217,12,255,0,130,172,141,243,51,
95,126,1,217,12,255,0,130,172,141,243,51,95,126,1,217,12,255,0,130,172,141,243,51,95,126,1,217,12,255,0,130,172,141,243,51,95,126,1,217,12,255,0,130,172,141,243,51,95,126,3,17,105,237,101,10,247,160,199,
172,209,177,174,66,155,78,144,167,16,219,237,82,88,90,84,104,113,77,171,67,75,230,71,162,144,162,233,234,1,151,236,134,127,193,86,70,249,153,175,191,0,236,134,127,193,86,70,249,153,175,191,0,236,134,127,
193,86,70,249,153,175,191,0,236,134,127,193,86,70,249,153,175,191,1,136,170,109,101,10,141,94,162,81,165,227,92,132,205,70,178,167,145,9,133,82,88,37,60,109,54,110,57,186,70,254,167,162,75,83,208,143,
78,176,25,126,200,103,252,21,100,111,153,154,251,240,14,200,103,252,21,100,111,153,154,251,240,14,200,103,252,21,100,111,153,154,251,240,14,200,103,252,21,100,111,153,154,251,240,14,200,103,252,21,100,
111,153,154,251,240,24,139,79,107,40,87,189,5,138,205,27,26,228,41,180,231,214,226,27,125,170,75,11,74,141,183,20,218,244,52,190,100,122,41,10,46,158,160,25,126,200,103,252,21,100,111,153,154,251,240,
14,200,103,252,21,100,111,153,154,251,240,14,200,103,252,21,100,111,153,154,251,240,14,200,103,252,21,100,111,153,154,251,240,30,154,6,208,80,235,23,141,10,220,155,102,93,214,228,186,211,142,179,13,250,
213,61,182,25,90,219,101,111,40,181,39,84,126,209,181,116,17,241,211,163,80,21,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,28,167,238,235,132,188,122,173,230,231,64,87,128,0,0,0,0,66,
182,32,238,97,179,254,50,161,253,124,128,23,80,0,0,0,16,172,193,221,57,179,247,198,215,188,222,2,234,0,0,0,0,2,21,177,15,115,37,165,241,213,31,56,73,1,117,0,0,0,1,10,204,93,211,123,62,252,125,123,205,
198,2,234,0,0,0,0,2,21,177,15,115,53,171,227,21,63,56,201,1,117,0,0,0,1,10,204,93,211,59,62,120,205,119,205,170,1,117,0,0,0,0,1,11,216,143,185,162,215,241,170,167,156,165,0,186,0,0,0,0,144,229,143,118,
236,31,242,173,83,205,114,64,87,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,121,10,173,5,85,85,83,10,108,115,169,37,146,146,168,100,234,121,98,104,212,105,39,13,26,235,186,106,35,45,237,
52,212,140,128,75,50,159,187,174,18,241,234,183,155,157,1,94,1,2,207,27,85,208,112,14,79,182,41,151,85,102,149,65,180,159,164,77,169,213,231,77,105,215,100,164,208,235,12,197,106,58,26,51,82,148,181,186,
233,154,73,11,51,75,43,50,208,146,163,16,199,146,147,124,181,188,252,177,77,71,172,218,211,111,79,211,21,165,183,60,106,122,121,229,109,177,90,113,210,113,199,51,107,111,182,162,149,174,237,62,156,245,
90,145,30,251,154,234,109,106,170,214,198,77,181,111,28,125,18,249,164,87,161,73,180,101,67,58,130,43,11,115,146,97,44,18,77,74,90,205,122,114,123,164,74,222,37,232,105,52,153,40,136,200,197,217,233,62,
26,211,92,220,107,235,26,231,183,61,166,39,210,99,137,244,83,130,127,180,204,87,15,197,51,58,212,119,222,245,173,123,239,135,214,201,200,182,158,74,166,189,80,180,46,122,53,213,1,151,77,135,101,81,42,
13,76,105,183,8,136,205,10,91,106,81,18,180,81,30,134,122,232,101,240,132,210,213,136,180,199,19,219,234,243,170,38,102,187,229,177,8,36,133,108,65,220,195,103,252,101,67,250,249,0,44,245,202,180,122,
5,22,125,78,90,210,212,88,81,220,146,234,214,122,37,40,66,77,74,51,62,162,208,140,101,241,89,191,179,224,201,155,244,196,207,241,11,176,226,156,217,107,138,59,218,98,63,148,3,102,125,179,236,172,216,205,
189,107,84,46,154,49,229,105,84,148,84,234,20,26,99,47,182,211,6,164,37,195,105,11,94,242,20,226,16,180,146,219,39,20,180,154,87,169,22,234,136,186,217,60,62,166,241,138,122,163,30,162,211,30,253,173,
49,239,94,173,196,76,110,59,110,119,49,188,147,146,43,211,107,113,25,38,221,30,243,93,219,163,122,245,154,68,79,166,254,104,141,76,40,149,141,166,49,5,187,86,153,75,170,229,107,34,153,83,134,234,152,147,
10,101,197,13,167,152,113,39,162,144,180,41,194,52,168,140,140,140,140,181,35,24,107,106,222,58,171,59,134,139,210,216,231,87,141,79,19,207,180,198,227,249,142,99,232,223,104,213,154,125,197,73,135,84,
165,78,141,83,166,76,105,47,198,155,13,228,188,203,237,168,181,74,208,180,153,146,146,100,100,100,100,122,24,182,244,182,59,77,111,26,152,247,85,91,69,163,117,157,162,217,131,186,115,103,239,141,175,121,
188,65,37,212,4,11,60,109,87,65,192,57,62,216,166,93,85,154,85,6,210,126,145,54,167,87,157,53,167,93,146,147,67,172,51,21,168,232,104,205,74,82,214,235,166,105,36,44,205,44,172,203,66,74,140,67,30,74,
77,242,214,243,242,197,53,30,179,107,77,189,63,76,86,150,220,241,169,233,231,149,182,197,105,199,73,199,28,205,173,190,218,138,86,187,180,250,115,213,106,68,123,238,107,169,181,170,174,217,55,245,189,
145,172,202,101,217,109,213,88,170,219,181,40,229,42,44,246,140,210,133,182,125,102,74,34,52,153,104,100,105,81,17,164,200,200,200,140,140,133,249,233,111,13,105,174,110,53,223,152,214,187,239,125,166,
53,206,226,117,49,203,62,43,198,127,247,124,243,175,222,39,90,254,95,43,35,38,90,25,54,28,153,118,125,215,68,186,226,70,112,154,125,250,29,69,153,136,105,102,90,146,84,166,148,162,73,233,199,67,17,233,
180,86,45,174,63,215,254,225,239,85,102,211,93,243,254,191,245,45,148,69,36,43,98,30,230,75,75,227,170,62,112,146,2,207,92,171,71,160,81,103,212,229,173,45,69,133,29,201,46,173,103,162,82,132,36,212,163,
51,234,45,8,198,95,21,155,251,62,12,153,191,76,76,255,0,16,187,14,41,205,150,184,163,189,166,35,249,64,54,103,219,62,202,205,140,219,214,181,66,233,163,30,86,149,73,69,78,161,65,166,50,251,109,48,106,
66,92,54,144,181,239,33,78,33,11,73,45,178,113,75,73,165,122,145,110,168,139,173,147,195,234,111,24,167,170,49,234,45,49,239,218,211,30,245,234,220,68,198,227,182,231,115,27,201,57,34,189,54,183,17,146,
109,209,239,53,221,186,55,175,89,164,68,250,111,230,136,212,194,167,120,103,156,103,143,107,42,164,93,57,18,211,182,170,201,66,93,56,21,138,220,104,143,146,21,237,85,201,184,178,86,135,212,122,113,24,
43,122,222,102,43,59,152,226,126,147,168,157,79,183,19,19,246,152,95,53,154,196,76,199,126,223,246,110,112,103,70,169,194,143,50,28,134,165,196,144,218,93,102,67,11,37,182,234,20,90,165,73,81,112,50,50,
50,50,50,224,100,98,219,86,212,180,210,241,169,142,240,170,151,174,74,197,233,59,137,230,38,59,76,123,194,35,152,187,166,246,125,248,250,247,155,140,69,53,212,4,11,60,109,87,65,192,57,62,216,166,93,85,
154,85,6,210,126,145,54,167,87,157,53,167,93,146,147,67,172,51,21,168,232,104,205,74,82,214,235,166,105,36,44,205,44,172,203,66,74,140,67,30,74,77,242,214,243,242,197,53,30,179,107,77,189,63,76,86,150,
220,241,169,233,231,149,182,197,105,199,73,199,28,205,173,190,218,138,86,187,180,250,115,213,106,68,123,238,107,169,181,170,175,216,183,213,7,38,90,20,155,166,216,169,179,88,160,85,88,76,152,115,88,212,
146,226,15,243,25,17,164,200,245,35,74,136,148,147,35,35,34,50,50,26,114,226,190,11,206,60,145,204,126,255,0,188,76,113,49,61,226,99,137,142,97,155,30,74,101,142,170,78,251,199,239,19,169,255,0,55,189,
23,5,45,218,227,212,84,84,162,46,178,204,116,203,114,156,151,210,114,16,202,148,105,75,170,111,93,226,65,169,42,34,81,150,134,105,50,234,20,199,197,19,49,206,181,19,244,153,230,34,126,241,217,108,199,
78,183,235,189,125,117,173,235,237,184,223,182,225,239,7,136,86,196,61,204,214,175,140,84,252,227,36,5,158,185,86,143,64,162,207,169,203,90,90,139,10,59,146,93,90,207,68,165,8,73,169,70,103,212,90,17,
140,190,43,55,246,124,25,51,126,152,153,254,33,118,28,83,155,45,113,71,123,76,71,242,128,108,207,182,125,149,155,25,183,173,106,133,211,70,60,173,42,146,138,157,66,131,76,101,246,218,96,212,132,184,109,
33,107,222,66,156,66,22,146,91,100,226,150,147,74,245,34,221,81,23,91,39,135,212,222,49,79,84,99,212,90,99,223,181,166,61,235,213,184,137,141,199,109,206,230,55,146,114,69,122,109,110,35,36,219,163,222,
107,187,116,111,94,179,72,137,244,223,205,17,169,133,150,232,202,118,93,145,89,166,82,46,59,190,131,64,171,84,212,73,129,2,169,83,102,51,242,204,212,73,34,105,181,168,148,179,53,25,39,181,35,226,100,67,
13,109,23,201,229,86,119,110,56,245,231,113,28,119,230,98,117,239,169,91,111,130,158,101,184,175,60,250,113,223,159,167,171,104,18,16,172,197,221,51,179,231,140,215,124,218,160,23,80,16,44,241,181,93,
7,0,228,251,98,153,117,86,105,84,27,73,250,68,218,157,94,116,214,157,118,74,77,14,176,204,86,163,161,163,53,41,75,91,174,153,164,144,179,52,178,179,45,9,42,49,12,121,41,55,203,91,207,203,20,212,122,205,
173,54,244,253,49,90,91,115,198,167,167,158,86,219,21,167,29,39,28,115,54,182,251,106,41,90,238,211,233,207,85,169,17,239,185,174,166,214,170,173,108,100,219,86,241,199,209,47,154,69,122,20,155,70,84,
51,168,34,176,183,57,38,18,193,36,212,165,172,215,167,39,186,68,173,226,94,134,147,73,146,136,140,140,93,158,147,225,173,53,205,198,190,177,174,123,115,218,98,125,38,56,159,69,56,39,251,76,197,112,252,
83,51,173,71,125,239,90,215,190,248,125,108,156,139,105,228,170,107,213,11,66,231,163,93,80,25,116,216,118,85,18,160,212,198,155,112,136,140,208,165,182,165,17,43,69,17,232,103,174,134,95,8,77,45,88,139,
76,113,61,190,175,58,162,102,107,190,91,16,130,72,94,196,125,205,22,191,141,85,60,229,40,5,154,185,86,143,64,162,207,169,203,90,90,139,10,59,146,93,90,207,68,165,8,73,169,70,103,212,90,17,140,190,43,55,
246,124,25,51,126,152,153,254,33,118,28,83,155,45,113,71,123,76,71,242,128,108,207,182,125,149,155,25,183,173,106,133,211,70,60,173,42,146,138,157,66,131,76,101,246,218,96,212,132,184,109,33,107,222,66,
156,66,22,146,91,100,226,150,147,74,245,34,221,81,23,91,39,135,212,222,49,79,84,99,212,90,99,223,181,166,61,235,213,184,137,141,199,109,206,230,55,146,114,69,122,109,110,35,36,219,163,222,107,187,116,
111,94,179,72,137,244,223,205,17,169,135,66,207,168,69,165,69,84,153,178,89,135,29,38,148,169,231,220,36,32,141,70,73,73,25,159,14,38,100,69,240,153,145,12,51,104,174,183,61,230,34,62,243,58,136,251,204,
204,68,71,172,206,150,250,76,251,68,207,237,28,204,253,162,57,151,160,72,72,114,199,187,118,15,249,86,169,230,185,32,43,192,0,0,0,0,0,0,0,0,60,165,83,134,117,35,167,20,182,61,80,38,74,65,196,229,19,202,
147,70,173,210,94,230,186,238,234,70,90,233,166,165,160,15,80,0,0,0,0,0,0,0,9,126,96,191,46,187,118,227,177,237,203,62,61,25,117,91,142,92,166,149,38,185,202,155,12,182,196,101,188,122,37,163,37,26,140,
210,68,71,174,133,199,129,235,192,60,60,150,122,252,167,28,254,239,63,211,0,228,179,215,229,56,231,247,121,254,152,7,37,158,191,41,199,63,187,207,244,192,57,44,245,249,78,57,253,222,127,166,1,201,103,
175,202,113,207,238,243,253,48,14,75,61,126,83,142,127,119,159,233,128,114,89,235,242,156,115,251,188,255,0,76,3,146,207,95,148,227,159,221,231,250,96,28,150,122,252,167,28,254,239,63,211,1,196,31,218,
87,19,43,62,254,45,38,87,75,123,41,21,70,65,219,165,143,154,156,154,170,89,228,203,156,30,187,198,100,222,188,143,18,227,175,71,13,224,21,108,4,206,208,140,222,248,84,179,211,180,103,38,243,186,159,48,
40,228,71,82,36,250,156,246,247,59,83,94,194,124,55,55,119,53,87,78,249,153,128,238,112,28,69,120,237,31,140,113,54,215,89,14,237,200,13,78,98,101,46,155,6,212,182,231,71,165,63,49,50,95,38,213,46,92,
86,20,210,20,72,124,206,84,114,50,89,160,140,141,60,116,222,49,78,11,218,184,50,215,29,122,178,101,180,205,107,29,239,74,196,82,34,38,120,159,205,173,226,99,223,167,113,217,103,139,164,214,216,103,45,
226,49,99,164,218,102,103,138,90,243,59,155,123,111,29,107,49,63,167,171,222,90,237,207,106,212,168,91,41,216,54,69,66,206,149,86,189,46,251,177,235,154,62,49,74,82,219,114,152,57,203,158,237,62,74,212,
164,33,134,27,109,198,201,107,94,169,74,247,72,208,173,77,34,89,49,249,121,252,31,134,164,121,147,130,159,23,63,15,20,154,204,204,243,26,173,239,29,21,230,47,211,21,142,62,42,198,50,121,148,241,126,43,
170,113,198,107,204,86,117,241,124,83,186,198,187,238,244,165,166,252,196,214,179,105,222,227,157,243,99,171,119,92,227,145,170,210,241,133,27,6,86,105,212,184,20,169,54,37,12,218,117,183,91,90,156,125,
170,130,223,142,148,48,230,247,178,52,157,196,234,158,77,194,82,140,244,34,215,138,189,62,27,37,226,221,81,123,196,107,244,205,43,219,159,91,117,197,167,95,14,186,117,185,153,150,108,213,153,241,24,186,
163,90,165,166,63,189,213,104,137,222,187,116,249,122,136,158,126,41,158,34,97,216,98,133,232,86,196,29,204,54,127,198,84,63,175,144,3,237,182,173,192,253,7,102,91,225,152,145,223,153,80,172,70,69,10,
44,72,132,74,125,247,38,58,136,196,134,136,250,86,100,233,232,95,9,117,140,249,105,25,111,139,21,163,117,155,214,109,222,126,10,207,93,248,142,126,74,219,183,45,158,26,215,197,55,205,142,209,91,82,182,
180,76,246,139,69,103,167,127,226,233,132,94,193,191,44,13,160,114,174,27,183,48,213,58,75,150,142,46,118,68,234,165,95,212,167,225,51,78,62,104,228,86,169,197,203,54,133,27,174,41,211,90,200,186,154,
212,247,143,93,222,142,59,91,55,137,201,248,133,190,78,139,86,179,26,213,230,243,94,34,63,77,43,27,237,168,248,59,113,190,62,171,131,194,211,240,248,223,153,213,73,180,79,122,197,122,166,109,105,247,181,
184,142,243,51,215,62,156,237,25,183,0,99,60,179,149,34,99,200,24,222,211,102,117,69,181,87,174,251,150,61,18,33,79,98,25,184,100,134,146,247,39,190,151,229,186,151,11,149,35,223,74,26,121,68,100,189,
213,22,28,56,162,247,158,53,139,30,187,113,213,105,230,180,220,122,68,124,87,215,167,77,103,81,118,252,217,109,90,196,79,57,50,110,34,103,158,154,215,81,107,115,184,158,241,74,71,188,205,163,228,152,158,
161,161,209,41,246,205,22,5,34,149,13,154,125,46,3,8,139,22,36,116,18,27,101,164,36,146,132,36,139,160,136,136,136,139,243,13,89,114,223,54,75,101,201,59,181,167,115,63,89,83,74,87,29,98,149,142,33,24,
204,29,211,155,63,124,109,123,205,226,164,215,80,28,69,120,237,31,140,113,54,215,89,14,237,200,13,78,98,101,46,155,6,212,182,231,71,165,63,49,50,95,38,213,46,92,86,20,210,20,72,124,206,84,114,50,89,160,
140,141,60,116,222,49,78,11,218,184,50,215,29,122,178,101,180,205,107,29,239,74,196,82,34,38,120,159,205,173,226,99,223,167,113,217,103,139,164,214,216,103,45,226,49,99,164,218,102,103,138,90,243,59,155,
123,111,29,107,49,63,167,171,222,90,45,225,106,94,201,192,248,151,13,177,108,170,37,91,39,220,53,106,237,86,219,122,82,225,55,14,7,44,228,227,132,251,205,164,212,211,73,55,163,165,221,196,239,154,82,180,
37,59,202,45,45,156,22,243,112,120,74,116,222,60,54,40,180,205,185,167,93,122,107,93,199,245,86,183,180,205,98,59,205,41,29,81,89,155,71,147,151,242,252,79,142,141,199,155,150,43,30,150,233,183,87,104,
158,214,154,82,102,119,190,152,155,110,45,173,77,159,99,235,113,187,67,38,223,182,237,199,141,172,187,15,35,210,32,64,41,115,49,210,92,143,69,170,211,223,83,203,97,105,142,163,45,29,66,219,121,10,83,137,
223,62,26,30,233,145,13,52,152,191,134,182,76,115,63,63,77,162,127,85,107,19,89,143,104,154,223,180,125,231,157,68,102,189,39,30,92,117,190,167,225,153,172,198,247,169,152,139,69,183,222,119,88,152,153,
222,183,58,214,230,109,214,3,58,228,43,98,30,230,75,75,227,170,62,112,146,3,237,182,173,192,253,7,102,91,225,152,145,223,153,80,172,70,69,10,44,72,132,74,125,247,38,58,136,196,134,136,250,86,100,233,232,
95,9,117,140,249,105,25,111,139,21,163,117,155,214,109,222,126,10,207,93,248,142,126,74,219,183,45,158,26,215,197,55,205,142,209,91,82,182,180,76,246,139,69,103,167,127,226,233,132,94,193,191,44,13,160,
114,174,27,183,48,213,58,75,150,142,46,118,68,234,165,95,212,167,225,51,78,62,104,228,86,169,197,203,54,133,27,174,41,211,90,200,186,154,212,247,143,93,222,142,59,91,55,137,201,248,133,190,78,139,86,179,
26,213,230,243,94,34,63,77,43,27,237,168,248,59,113,190,62,171,131,194,211,240,248,223,153,213,73,180,79,122,197,122,166,109,105,247,181,184,142,243,51,215,62,156,233,217,119,29,228,155,122,226,201,217,
114,236,195,24,162,237,180,162,213,164,84,37,51,123,110,79,174,57,71,140,219,77,54,80,148,77,169,136,233,54,154,91,164,133,169,74,222,113,90,164,143,66,62,119,135,156,126,27,30,57,241,49,17,22,159,139,
166,62,40,181,239,49,19,105,158,39,166,179,72,233,175,120,172,234,119,109,87,165,154,50,120,172,182,167,135,159,150,34,43,213,197,102,43,94,171,107,83,51,29,86,155,252,86,215,166,235,17,28,247,221,21,
200,175,81,224,57,5,164,177,9,76,54,166,26,66,9,9,67,102,146,221,73,36,184,17,17,104,90,13,217,235,122,229,189,114,78,237,19,59,251,239,150,44,22,173,240,210,212,141,68,196,106,61,163,72,190,98,238,155,
217,247,227,235,222,110,49,74,245,212,7,17,94,59,71,227,28,77,181,214,67,187,114,3,83,152,153,75,166,193,181,45,185,209,233,79,204,76,151,201,181,75,151,21,133,52,133,18,31,51,149,28,140,150,104,35,35,
79,29,55,140,83,130,246,174,12,181,199,94,172,153,109,51,90,199,123,210,177,20,136,137,158,39,243,107,120,152,247,233,220,118,89,226,233,53,182,25,203,120,140,88,233,54,153,153,226,150,188,206,230,222,
219,199,90,204,79,233,234,247,150,86,204,202,173,108,159,179,141,167,18,230,110,151,106,94,183,189,94,161,58,151,66,175,204,68,24,116,181,74,148,228,149,38,75,170,52,165,182,163,54,242,77,101,193,70,100,
72,73,111,40,136,91,150,189,30,71,225,216,178,71,85,49,196,77,187,196,69,99,226,159,239,106,103,166,149,137,248,184,230,41,22,189,97,89,156,179,226,127,16,154,79,69,175,51,17,218,211,190,41,19,223,166,
109,21,234,153,157,244,198,247,185,141,79,235,97,163,181,42,25,111,58,214,105,55,252,44,129,91,151,80,167,197,151,86,110,115,111,61,60,153,136,149,57,41,40,66,205,40,97,79,72,117,182,210,217,19,105,75,
36,148,153,238,234,52,226,248,124,4,86,145,170,249,151,157,119,152,142,41,29,83,168,158,171,116,90,252,247,139,110,186,172,196,69,126,34,246,201,226,235,57,45,19,49,142,59,113,27,155,90,211,21,141,207,
21,172,227,175,59,182,227,118,153,181,166,103,177,134,116,208,173,136,123,153,173,95,24,169,249,198,72,15,182,218,183,3,244,29,153,111,134,98,71,126,101,66,177,25,20,40,177,34,17,41,247,220,152,234,35,
18,26,35,233,89,147,167,161,124,37,214,51,229,164,101,190,44,86,141,214,111,89,183,121,248,43,61,119,226,57,249,43,110,220,182,120,107,95,20,223,54,59,69,109,74,218,209,51,218,45,21,158,157,255,0,139,
166,17,123,6,252,176,54,129,202,184,110,220,195,84,233,46,90,56,185,217,19,170,149,127,82,159,132,205,56,249,163,145,90,167,23,44,218,20,110,184,167,77,107,34,234,107,83,222,61,119,122,56,237,108,222,
39,39,226,22,249,58,45,90,204,107,87,155,205,120,136,253,52,172,111,182,163,224,237,198,248,250,174,15,11,79,195,227,126,103,85,38,209,61,235,21,234,153,181,167,222,214,226,59,204,207,92,250,115,243,219,
123,22,208,172,187,114,237,187,81,134,169,185,41,203,153,46,157,122,242,184,94,110,66,237,54,9,166,163,182,243,44,238,42,66,153,108,141,110,154,35,154,77,59,139,81,168,181,35,46,101,48,70,91,215,193,86,
124,184,201,104,248,227,230,234,189,181,254,81,168,175,84,244,196,68,68,196,243,190,197,109,109,91,196,83,227,201,72,248,105,60,86,98,181,181,187,207,17,185,239,168,221,183,62,186,118,13,147,68,43,106,
205,160,210,10,123,213,82,129,1,136,165,62,65,234,228,157,198,210,158,81,71,199,138,180,212,255,0,88,234,120,172,147,155,196,100,201,53,214,230,103,94,219,158,206,71,131,164,99,240,248,233,91,117,68,68,
115,239,199,116,147,49,119,76,236,249,227,53,223,54,168,101,107,93,64,113,21,227,180,126,49,196,219,93,100,59,183,32,53,57,137,148,186,108,27,82,219,157,30,148,252,196,201,124,155,84,185,113,88,83,72,
81,33,243,57,81,200,201,102,130,50,52,241,211,120,197,56,47,106,224,203,92,117,234,201,150,211,53,172,119,189,43,17,72,136,153,226,127,54,183,137,143,126,157,199,101,158,46,147,91,97,156,183,136,197,142,
147,105,153,158,41,107,204,238,109,237,188,117,172,196,254,158,175,121,109,216,235,2,210,106,251,37,211,169,153,95,150,179,104,15,86,36,222,85,138,27,178,90,139,22,51,14,77,118,106,96,204,53,167,66,97,
4,182,247,211,218,113,111,67,50,34,50,23,102,199,139,194,199,134,173,230,45,228,86,177,239,19,110,157,118,143,154,43,51,49,72,230,39,85,226,220,43,166,91,231,191,138,201,139,117,243,166,218,158,98,209,
93,199,63,221,155,86,191,23,180,90,209,223,150,71,102,188,123,111,185,152,46,60,145,143,108,166,236,12,115,83,162,71,166,68,97,136,37,77,69,117,212,60,183,10,122,97,18,83,201,54,148,43,113,11,90,82,183,
9,106,86,155,187,170,85,152,163,54,28,89,177,231,220,117,90,179,21,158,102,189,49,104,153,159,211,215,186,252,61,227,167,118,136,180,204,41,205,90,95,196,99,182,41,137,138,86,209,54,142,214,234,154,204,
68,76,113,104,175,76,252,93,167,171,85,153,136,116,240,173,114,23,177,31,115,69,175,227,85,79,57,74,1,245,219,86,224,126,131,179,45,240,204,72,239,204,168,86,35,34,133,22,36,66,37,62,251,147,29,68,98,
67,68,125,43,50,116,244,47,132,186,198,124,180,140,183,197,138,209,186,205,235,54,239,63,5,103,174,252,71,63,37,109,219,150,207,13,107,226,155,230,199,104,173,169,91,90,38,123,69,162,179,211,191,241,116,
194,47,96,223,150,6,208,57,87,13,219,152,106,157,37,203,71,23,59,34,117,82,175,234,83,240,153,167,31,52,114,43,84,226,229,155,66,141,215,20,233,173,100,93,77,106,123,199,174,239,71,29,173,155,196,228,
252,66,223,39,69,171,89,141,106,243,121,175,17,31,166,149,141,246,212,124,29,184,223,31,85,193,225,105,248,124,111,204,234,164,218,39,189,98,189,83,54,180,251,218,220,71,121,153,235,159,78,118,253,165,
44,74,165,223,156,176,172,26,149,203,82,155,76,151,118,38,108,123,122,10,10,60,22,35,194,140,169,74,122,65,22,242,228,59,203,52,218,73,74,90,91,74,92,34,38,137,122,184,172,254,18,107,95,29,91,119,181,
41,146,251,159,78,216,227,166,59,68,254,109,119,51,187,113,110,153,173,102,106,217,226,166,39,193,94,145,199,93,169,94,59,206,231,170,219,223,120,233,173,190,24,136,215,205,51,61,48,234,129,224,131,237,
16,87,18,178,134,21,43,85,84,180,86,189,87,168,242,71,88,75,138,141,167,169,146,55,183,137,179,37,107,166,186,104,125,58,0,205,114,89,235,242,156,115,251,188,255,0,76,3,146,207,95,148,227,159,221,231,
250,96,28,150,122,252,167,28,254,239,63,211,0,228,179,215,229,56,231,247,121,254,152,7,37,158,191,41,199,63,187,207,244,192,57,44,245,249,78,57,253,222,127,166,1,201,103,175,202,113,207,238,243,253,48,
14,75,61,126,83,142,127,119,159,233,128,114,89,235,242,156,115,251,188,255,0,76,7,20,255,0,105,76,76,176,252,108,96,150,215,74,123,39,21,85,243,182,139,31,179,57,53,116,183,201,23,57,50,86,241,232,222,
166,198,166,92,117,221,227,166,240,14,168,216,193,141,162,25,177,204,179,203,212,71,36,114,105,230,41,96,136,234,133,199,255,0,84,166,189,132,251,93,52,221,35,87,78,241,234,3,163,0,0,0,0,0,0,0,72,114,
151,187,182,20,241,202,183,155,220,1,94,0,0,0,0,0,0,0,0,1,231,42,116,84,212,21,60,163,50,83,148,209,48,169,36,217,114,134,217,25,168,144,106,233,221,35,51,61,58,53,51,1,41,202,126,238,184,75,199,170,222,
110,116,5,120,0,4,131,62,224,154,166,87,147,109,87,173,43,226,102,57,190,237,199,31,245,54,191,26,11,115,219,38,95,74,81,33,151,163,58,100,135,80,162,74,76,181,62,213,73,74,139,163,67,174,177,124,121,
39,38,57,215,84,116,218,53,189,198,226,209,246,152,180,68,238,61,55,30,188,91,215,22,195,56,111,27,141,197,163,222,38,55,31,196,196,204,76,122,241,190,56,159,182,4,193,82,113,19,117,234,173,195,119,207,
200,55,221,196,243,111,86,46,90,131,8,141,203,37,164,154,89,101,152,237,246,140,50,130,82,140,144,70,125,178,214,122,241,34,45,61,84,166,40,195,138,189,53,220,218,121,153,153,181,181,187,76,207,210,34,
177,29,171,90,214,177,219,115,151,166,214,201,230,228,182,231,81,88,244,136,172,76,204,68,71,188,239,226,159,234,158,101,89,21,45,66,182,32,238,97,179,254,50,161,253,124,128,23,80,0,26,54,63,198,94,178,
238,171,238,225,149,81,42,181,78,233,170,34,106,157,230,252,145,198,142,219,13,178,196,82,237,149,188,148,18,22,173,120,106,167,86,122,22,161,143,242,240,87,12,119,221,173,51,239,54,158,255,0,181,98,180,
251,86,39,212,201,249,153,188,217,253,53,172,71,180,70,230,121,245,221,166,214,253,245,233,182,242,2,21,152,59,167,54,126,248,218,247,155,192,93,64,0,73,243,230,15,159,150,227,219,245,59,106,240,149,143,
175,155,114,75,146,40,247,36,88,109,204,228,9,212,114,111,180,228,119,52,75,173,184,141,53,73,153,118,201,66,189,238,135,79,69,171,154,51,99,182,167,83,89,246,154,206,167,83,30,241,49,19,19,206,167,122,
230,86,197,169,56,231,22,74,238,55,22,143,73,139,68,76,68,199,237,105,137,143,88,153,143,87,215,3,97,23,241,5,62,181,50,185,117,206,191,47,91,130,74,101,214,174,90,131,40,97,82,84,132,238,182,219,76,32,
205,44,180,132,234,73,109,38,100,70,165,113,227,161,105,221,41,142,49,98,174,171,185,153,231,115,54,157,110,102,103,237,17,17,218,43,17,30,155,156,149,165,231,36,229,203,109,219,81,17,198,162,43,19,58,
136,143,222,102,103,250,173,51,60,111,81,83,16,92,133,108,67,220,201,105,124,117,71,206,18,64,93,64,126,86,132,184,133,37,68,74,74,139,67,35,235,33,11,210,185,43,52,183,105,225,236,76,196,238,28,155,27,
97,138,250,141,139,70,163,154,107,243,240,116,89,92,180,124,122,84,230,27,112,217,37,242,137,134,245,68,140,222,118,49,40,205,60,153,145,123,30,234,117,45,210,80,183,13,186,103,29,252,68,121,150,199,174,
157,241,27,174,162,147,104,142,45,53,136,137,231,137,188,69,181,198,143,19,107,102,182,75,99,158,143,51,171,171,93,254,40,158,174,153,141,116,110,103,124,122,110,61,102,93,100,219,105,105,180,161,9,36,
33,36,73,74,82,90,17,23,81,17,15,38,102,103,114,140,68,86,34,181,141,68,33,153,139,186,111,103,223,143,175,121,184,199,143,87,80,0,26,165,243,137,172,124,159,204,253,121,89,182,253,219,204,247,185,183,
171,148,182,38,242,27,218,111,110,114,168,86,238,187,169,215,78,157,11,224,17,233,175,87,86,185,79,174,221,61,27,227,190,154,134,207,59,55,90,187,59,91,211,161,80,233,180,164,213,42,19,36,202,153,84,131,
75,106,19,143,37,201,14,60,219,38,72,212,249,54,146,231,38,132,154,140,146,73,224,69,174,130,116,181,171,131,30,25,159,150,181,137,159,213,104,142,109,63,89,153,153,245,212,78,183,42,102,177,108,183,203,
250,166,102,35,244,196,246,172,125,56,141,246,220,243,168,236,173,15,19,66,182,33,238,102,181,124,98,167,231,25,32,46,160,63,43,66,92,66,146,162,37,37,69,161,145,245,144,133,233,92,149,154,91,180,240,
246,38,98,119,14,79,103,97,203,133,41,245,154,246,105,174,175,5,161,243,91,120,245,186,100,116,61,200,26,249,94,102,186,158,166,242,227,239,153,164,208,101,169,181,162,55,184,111,13,24,114,77,109,143,
38,127,142,216,250,122,125,35,117,212,86,109,17,197,181,17,31,123,68,91,211,79,60,68,219,45,178,91,28,244,121,147,51,109,127,123,230,233,237,211,185,157,241,233,184,231,115,46,176,109,180,50,218,91,66,
73,8,65,18,82,148,150,132,68,93,4,43,153,155,78,231,186,53,172,82,34,181,237,8,102,98,238,153,217,243,198,107,190,109,80,241,37,212,0,4,51,106,61,159,174,204,253,14,214,139,110,100,102,172,54,104,179,
206,164,235,79,219,237,85,218,154,242,72,137,147,113,167,92,75,102,77,158,242,200,150,149,150,254,226,139,69,33,38,42,173,45,95,17,95,17,22,249,98,117,30,211,63,213,247,136,226,38,53,49,185,231,149,150,
154,91,5,176,90,187,234,152,223,62,145,233,175,88,153,212,204,118,157,71,13,163,8,88,121,18,196,165,212,217,200,153,73,89,70,108,135,146,184,178,189,111,198,164,20,70,201,58,26,55,24,51,37,234,124,119,
148,125,68,68,95,14,153,181,102,145,88,175,59,158,125,227,141,70,190,156,253,247,244,102,138,222,50,77,166,220,76,71,30,211,27,220,239,191,59,143,182,190,178,165,138,214,161,123,17,247,52,90,254,53,84,
243,148,160,23,64,0,26,45,87,23,55,88,204,246,245,255,0,34,160,103,234,37,26,109,46,45,55,145,224,78,73,117,133,173,253,253,238,146,75,4,130,78,239,190,51,215,168,49,126,85,178,219,214,241,88,251,69,102,
211,63,126,169,154,250,113,211,235,190,25,55,146,184,233,218,43,105,183,222,102,58,99,248,142,175,127,155,211,215,122,1,33,203,30,237,216,63,229,90,167,154,228,128,175,0,0,0,0,0,0,0,0,0,248,20,24,197,
52,230,115,118,185,217,182,76,156,141,194,229,13,4,122,146,119,186,116,212,204,244,232,212,192,125,192,0,0,0,0,0,0,0,72,114,151,187,182,20,241,202,183,155,220,1,94,0,0,0,0,0,0,0,0,0,1,33,202,126,238,184,
75,199,170,222,110,116,5,120,0,0,0,0,4,43,98,14,230,27,63,227,42,31,215,200,1,117,0,0,0,1,10,204,29,211,155,63,124,109,123,205,224,46,160,0,0,0,0,33,91,16,247,50,90,95,29,81,243,132,144,23,80,0,0,0,16,
172,197,221,55,179,239,199,215,188,220,96,46,160,0,0,0,0,33,91,16,247,51,90,190,49,83,243,140,144,23,80,0,0,0,16,172,197,221,51,179,231,140,215,124,218,160,23,80,0,0,0,0,16,189,136,251,154,45,127,26,170,
121,202,80,11,160,0,0,0,9,14,88,247,110,193,255,0,42,213,60,215,36,6,163,23,104,124,171,116,220,215,140,75,55,14,83,46,10,53,185,91,145,69,84,249,55,146,97,189,33,198,137,38,165,37,149,68,81,39,82,89,
104,70,189,63,56,167,13,237,147,5,60,69,171,168,183,86,162,57,157,86,246,167,211,188,214,120,75,39,77,115,91,13,103,115,88,174,253,62,106,214,223,94,209,101,27,22,103,91,119,38,217,22,253,125,110,21,183,
38,177,50,69,45,170,77,93,246,155,145,207,152,91,168,126,50,52,86,142,173,38,195,167,218,25,234,148,26,186,53,211,93,169,27,167,151,61,81,122,197,235,239,53,152,137,222,187,241,19,207,178,173,218,179,
122,228,141,77,45,211,62,219,244,231,235,233,239,247,225,187,86,174,10,93,183,25,169,21,106,148,58,92,119,159,110,43,110,205,125,44,161,111,56,162,67,109,145,168,200,141,106,81,146,82,146,226,102,100,
69,196,87,17,213,104,164,119,158,209,235,60,76,241,251,68,207,218,38,83,158,43,54,158,209,204,207,180,125,88,227,200,118,170,104,53,74,225,220,212,114,162,210,157,117,138,133,72,231,181,205,161,184,217,
238,186,135,92,222,221,109,72,62,10,37,25,25,31,78,130,59,142,154,223,210,218,212,250,78,231,81,175,125,207,17,175,94,18,233,158,171,83,92,199,120,245,142,55,207,183,28,253,185,124,110,124,163,102,89,
39,78,43,138,238,161,80,14,162,100,80,138,169,82,102,55,58,51,232,228,183,212,91,255,0,233,212,75,83,230,121,95,213,237,235,252,119,66,38,39,31,155,31,47,191,167,242,253,94,153,50,207,198,244,232,211,
238,235,174,137,107,64,148,231,36,196,170,213,69,152,109,58,189,13,91,168,83,138,73,40,244,35,61,11,168,132,38,209,91,116,76,243,237,235,199,127,227,113,252,165,17,54,175,92,118,247,251,246,121,40,153,
138,193,185,168,94,173,209,239,139,114,171,70,231,168,166,250,163,6,173,29,232,252,233,102,146,67,28,162,86,105,229,84,107,65,18,53,222,51,90,116,46,36,46,242,239,19,72,212,238,251,233,250,235,123,215,
190,181,59,215,180,251,74,29,81,171,78,254,88,220,253,35,222,125,161,176,59,112,82,216,174,71,162,185,82,134,221,98,67,11,148,205,61,111,164,164,58,202,20,148,173,196,183,174,241,161,38,180,17,168,139,
66,53,36,143,164,132,34,58,183,174,117,173,253,55,189,111,219,122,157,123,234,125,146,159,134,34,103,215,136,250,204,115,58,98,104,185,58,206,185,46,73,214,245,38,236,161,213,43,240,127,243,116,168,85,
38,94,149,31,227,26,74,141,72,253,164,67,202,126,101,60,202,115,95,120,237,252,151,252,187,69,47,196,207,164,181,107,159,51,63,71,149,80,118,149,68,135,112,91,144,20,166,103,92,140,92,16,153,131,74,121,
165,25,74,68,243,113,194,91,60,146,72,143,216,210,233,234,102,74,74,52,212,227,91,87,81,107,207,77,102,99,86,158,211,93,196,110,61,237,190,168,136,212,68,204,68,117,70,231,166,86,173,247,52,164,117,90,
35,229,245,220,199,84,110,61,34,107,53,157,239,122,157,197,102,53,213,72,131,58,53,78,20,121,144,228,53,46,36,134,210,235,50,24,89,45,183,80,162,213,42,74,139,129,145,145,145,145,151,3,35,22,90,182,165,
166,151,141,76,119,133,84,189,114,86,47,73,220,79,49,49,218,99,222,31,113,20,192,0,0,0,0,0,18,28,165,238,237,133,60,114,173,230,247,0,87,128,0,0,0,0,0,0,0,0,0,104,217,43,18,83,114,116,170,36,169,149,90,
205,30,101,25,199,93,137,42,139,51,155,60,133,56,141,197,246,228,147,63,107,169,112,50,224,163,215,80,26,215,99,155,94,18,50,55,210,71,61,16,14,199,54,188,36,100,111,164,142,122,32,38,214,86,45,168,87,
51,118,75,182,37,100,188,130,116,170,12,106,75,176,146,155,129,100,180,170,67,111,169,221,229,110,241,226,218,116,248,0,82,123,28,218,240,145,145,190,146,57,232,128,118,57,181,225,35,35,125,36,115,209,
1,137,181,54,73,164,89,84,8,180,106,69,253,144,97,211,227,111,155,76,51,95,54,144,157,229,169,106,209,40,66,82,90,169,70,124,11,142,186,158,167,169,128,203,118,57,181,225,35,35,125,36,115,209,1,54,218,
63,22,212,49,158,17,187,46,122,38,75,200,45,213,105,209,146,236,117,61,112,45,104,37,27,136,79,20,154,120,240,81,128,164,246,57,181,225,35,35,125,36,115,209,0,236,115,107,194,70,70,250,72,231,162,3,19,
82,217,42,145,86,175,81,171,50,175,236,130,237,66,144,111,28,55,215,95,53,45,174,85,27,139,221,81,160,212,157,83,192,247,76,181,232,61,75,128,12,183,99,155,94,18,50,55,210,71,61,16,14,199,54,188,36,100,
111,164,142,122,32,38,214,86,45,168,87,51,118,75,182,37,100,188,130,116,170,12,106,75,176,146,155,129,100,180,170,67,111,169,221,229,110,241,226,218,116,248,0,82,123,28,218,240,145,145,190,146,57,232,
128,118,57,181,225,35,35,125,36,115,209,1,137,181,54,73,163,217,84,24,212,106,69,253,144,97,211,227,154,205,182,25,175,155,72,78,250,212,181,104,148,33,41,45,84,163,62,5,199,93,79,83,212,192,101,187,28,
218,240,145,145,190,146,57,232,128,155,109,31,139,106,24,207,8,221,151,61,19,37,228,22,234,180,232,201,118,58,158,184,22,180,18,141,196,39,138,77,60,120,40,192,82,123,28,218,240,145,145,190,146,57,232,
128,118,57,181,225,35,35,125,36,115,209,1,137,169,236,147,71,171,215,168,213,153,87,246,65,118,161,72,55,149,13,245,215,205,75,104,221,70,226,247,84,104,53,39,84,240,61,211,45,122,15,82,224,3,45,216,230,
215,132,140,141,244,145,207,68,3,177,205,175,9,25,27,233,35,158,136,13,22,220,196,82,234,121,138,247,183,31,201,89,8,233,148,154,109,42,76,100,166,225,112,148,75,124,229,147,154,171,119,137,123,10,52,
248,56,252,32,55,174,199,54,188,36,100,111,164,142,122,32,29,142,109,120,72,200,223,73,28,244,64,98,109,77,146,104,246,85,6,61,30,145,127,100,24,116,248,230,226,155,101,154,249,182,132,154,214,165,171,
68,161,4,146,213,74,81,240,46,58,234,124,117,48,25,110,199,54,188,36,100,111,164,142,122,32,38,217,195,22,212,44,56,118,83,148,172,151,144,80,170,173,217,75,164,73,229,110,5,175,88,239,189,184,225,23,
107,192,244,232,62,160,20,158,199,54,188,36,100,111,164,142,122,32,29,142,109,120,72,200,223,73,28,244,64,98,106,123,36,209,234,245,218,53,98,85,253,144,94,168,82,20,242,161,188,186,249,169,108,155,168,
220,94,234,141,6,164,234,158,7,186,101,175,65,234,92,0,101,187,28,218,240,145,145,190,146,57,232,128,118,57,181,225,35,35,125,36,115,209,1,162,224,252,69,46,252,197,212,90,237,87,37,100,37,212,37,242,
252,170,154,184,92,66,79,117,247,16,90,22,239,14,9,32,27,215,99,155,94,18,50,55,210,71,61,16,14,199,54,188,36,100,111,164,142,122,32,49,54,166,201,52,123,46,133,30,143,72,191,178,12,58,123,10,113,77,178,
205,124,219,74,77,107,83,138,209,40,65,36,181,82,212,124,11,137,158,167,199,136,12,183,99,155,94,18,50,55,210,71,61,16,26,46,117,196,82,236,12,59,120,92,116,156,149,144,145,83,166,83,93,147,29,78,220,
46,45,36,180,150,165,170,119,120,144,13,235,177,205,175,9,25,27,233,35,158,136,7,99,155,94,18,50,55,210,71,61,16,30,171,127,103,186,93,14,239,162,92,114,110,155,182,191,58,142,227,174,195,106,183,87,84,
166,91,83,140,173,149,158,234,147,211,184,226,186,15,224,248,0,115,117,133,140,172,187,190,236,205,19,46,28,171,117,89,50,189,123,212,154,56,116,107,217,234,67,4,130,67,94,200,108,37,194,73,159,19,213,
70,71,174,233,107,174,131,39,134,173,127,217,216,190,46,254,102,249,222,191,59,39,191,17,26,231,95,93,250,167,146,214,159,29,151,225,237,24,245,199,127,202,167,243,237,254,77,38,143,94,173,77,199,248,
66,29,175,91,162,28,106,30,82,169,210,45,187,154,169,4,149,10,161,9,152,51,201,18,157,109,133,178,78,26,181,113,38,226,20,146,90,139,127,142,167,174,236,86,201,124,254,23,45,235,20,189,176,228,220,107,
81,17,26,172,106,63,166,38,145,19,17,218,55,26,141,106,25,178,210,152,177,248,140,53,153,181,107,151,22,167,123,157,204,69,167,115,253,93,54,153,137,158,243,174,103,124,183,76,193,152,238,27,177,167,236,
59,153,203,122,177,83,183,110,235,62,105,215,109,67,113,48,157,41,21,84,151,34,182,156,91,138,101,228,114,38,102,158,81,90,165,105,62,2,126,7,167,47,139,240,249,34,38,58,114,94,191,73,252,140,147,184,
158,59,111,86,143,73,215,51,180,188,76,219,31,135,241,24,230,119,213,138,109,245,143,204,172,106,126,253,226,125,121,227,135,135,42,250,133,217,57,80,172,34,60,215,48,180,58,229,57,187,245,76,173,5,78,
93,192,148,168,162,58,226,55,76,212,219,70,113,74,65,145,146,119,249,3,86,188,154,197,63,134,207,199,89,159,150,214,183,147,191,76,147,26,180,199,180,78,166,180,239,249,189,83,26,153,137,91,227,163,120,
230,35,230,138,71,153,239,229,111,113,31,120,141,218,209,223,202,227,122,152,133,62,200,59,16,243,94,127,60,146,116,67,172,28,216,252,159,174,62,71,79,80,57,131,28,159,39,202,240,230,252,175,58,222,221,
237,119,247,183,184,138,163,201,255,0,103,207,95,234,191,153,239,190,169,232,223,175,251,190,158,159,223,94,171,114,78,73,241,120,230,157,186,41,209,175,223,171,95,94,173,239,215,90,244,211,67,217,178,
171,2,190,140,55,66,168,201,97,202,85,14,29,193,89,140,221,69,196,251,21,53,201,74,141,73,74,146,190,254,58,212,164,107,199,117,173,70,184,140,150,201,25,115,79,199,92,24,233,120,158,254,101,252,187,78,
254,177,229,79,87,172,77,190,172,153,169,138,102,99,23,203,57,239,106,107,183,77,107,122,219,83,219,93,89,35,166,59,79,244,241,13,74,238,89,189,98,101,214,45,185,52,230,38,255,0,126,116,115,132,165,183,
202,199,109,102,186,89,54,165,182,133,36,212,141,226,226,73,82,117,34,50,35,46,145,95,128,243,38,159,134,244,207,61,126,39,191,63,215,226,190,222,157,191,101,254,51,166,39,198,111,183,147,143,183,248,
54,207,230,200,121,126,30,92,169,149,82,175,66,171,93,74,197,87,47,168,138,180,41,82,32,184,135,57,88,124,52,118,75,198,165,154,183,119,77,38,157,15,225,61,52,205,111,43,251,63,140,243,55,173,96,234,215,
232,235,201,213,175,175,79,86,218,113,245,121,190,19,183,207,125,111,245,116,70,183,244,222,191,207,108,229,246,120,196,177,30,12,254,235,189,65,245,203,234,253,19,214,207,169,36,215,60,228,249,102,249,
247,181,237,247,121,183,56,229,183,191,62,255,0,17,214,190,255,0,219,20,233,237,187,245,107,229,242,186,45,237,199,79,110,143,78,174,157,56,184,255,0,225,89,60,205,245,116,199,125,245,121,157,85,247,231,
171,171,123,245,239,190,54,209,41,109,185,148,108,253,160,172,86,210,231,173,218,53,215,116,215,46,39,8,141,41,125,68,165,156,40,122,245,239,56,131,121,100,94,245,148,36,248,56,62,111,197,115,248,38,63,
17,61,177,226,180,87,235,147,174,243,191,240,86,98,223,243,90,147,31,44,190,134,181,154,254,47,108,94,185,109,131,127,244,252,140,17,62,187,142,187,71,76,122,77,99,36,119,211,182,240,159,184,205,133,242,
4,15,233,219,31,81,248,159,255,0,63,63,252,246,255,0,202,95,43,248,55,252,51,195,127,211,167,254,48,221,7,49,216,0,0,0,0,0,0,72,114,151,187,182,20,241,202,183,155,220,1,94,0,0,0,0,0,0,0,0,0,0,0,0,1,21,
198,125,211,249,183,196,173,255,0,228,202,1,106,0,0,0,1,21,219,63,185,130,255,0,241,36,127,57,176,22,160,0,0,0,0,17,92,103,221,63,155,124,74,223,254,76,160,22,160,0,0,0,17,93,179,251,152,47,255,0,18,71,
243,155,1,106,0,0,0,0,1,42,178,251,163,178,135,200,212,31,173,80,1,85,0,0,0,1,21,218,139,252,59,25,255,0,204,10,23,245,0,45,64,0,0,0,0,37,91,46,123,133,91,63,245,95,213,58,2,170,0,0,0,2,85,181,87,115,
142,69,249,26,71,213,1,85,0,0,1,58,173,108,225,137,110,58,220,154,205,91,23,89,117,74,196,167,121,119,234,19,109,248,143,72,117,206,253,110,41,179,82,149,249,204,245,17,165,107,142,53,72,215,175,28,125,
127,239,202,86,180,223,230,157,255,0,173,127,217,157,186,113,93,151,124,208,225,81,110,75,66,131,112,81,161,45,46,69,167,85,105,140,73,143,29,68,147,73,26,27,90,77,41,50,73,153,17,145,23,3,50,18,183,199,
110,187,115,62,254,191,235,136,70,191,13,122,43,196,123,62,116,156,73,99,80,40,45,80,233,150,101,189,78,162,181,41,185,205,211,98,82,152,106,50,36,33,68,166,222,38,210,130,73,56,149,37,42,37,105,169,26,
72,200,248,9,245,219,117,182,249,175,111,166,226,99,143,110,38,99,237,50,143,77,98,45,26,226,221,254,191,127,119,185,187,6,216,106,220,159,111,162,220,164,162,131,60,222,84,186,82,96,180,81,100,155,170,
53,60,110,53,187,186,189,243,82,141,90,145,239,25,153,158,186,138,173,88,181,43,142,209,186,215,81,17,233,17,29,162,35,211,94,158,203,34,211,91,206,72,159,138,123,207,172,239,137,220,253,158,75,143,21,
217,87,130,105,137,175,89,244,26,217,82,244,230,5,81,166,49,35,154,105,209,201,111,164,247,52,208,180,221,211,160,79,115,230,121,223,213,239,235,252,247,66,34,35,31,147,31,47,183,167,241,217,162,47,101,
44,121,92,200,23,157,215,119,90,86,205,231,46,191,42,51,204,21,106,131,30,75,144,27,106,35,49,249,20,184,225,44,205,38,109,26,248,18,72,141,102,90,30,154,157,120,171,24,241,205,59,204,218,214,223,252,
218,227,246,215,249,175,205,150,114,249,113,218,41,72,174,191,197,123,111,233,190,173,126,221,253,35,233,102,236,185,98,88,183,221,203,89,164,219,86,236,10,29,98,53,45,41,183,161,80,216,98,52,121,80,157,
144,234,37,145,36,183,77,195,55,209,162,183,9,73,54,82,100,163,225,166,186,230,181,112,198,47,88,189,175,19,237,213,74,210,98,61,190,89,230,59,245,76,107,223,54,74,197,237,19,233,211,53,152,247,221,183,
207,249,70,185,237,10,131,182,253,45,250,228,122,211,148,216,110,86,35,176,184,172,212,22,194,78,67,76,173,73,82,219,75,154,111,18,20,104,65,154,72,244,51,74,76,250,8,81,19,211,189,113,189,111,235,173,
235,126,250,220,235,219,115,238,156,252,81,17,62,156,199,210,103,137,211,19,69,198,54,117,183,113,206,184,105,22,157,14,151,95,159,194,93,86,21,53,150,101,72,248,199,82,146,82,255,0,105,152,242,159,151,
79,46,156,87,218,59,127,5,255,0,50,209,107,243,49,235,47,100,43,42,221,166,67,171,196,135,65,166,68,139,88,121,217,53,38,24,134,218,17,53,215,75,71,92,121,36,157,28,82,203,130,148,173,77,93,122,136,218,
181,190,56,195,104,221,34,53,175,77,79,120,215,109,114,159,93,163,39,155,191,139,142,125,120,141,71,61,248,136,136,143,104,236,201,193,131,26,153,10,60,56,113,218,137,18,59,105,105,152,236,32,144,219,
72,73,104,148,165,37,192,136,136,136,136,139,129,17,11,45,107,94,211,123,206,230,123,202,154,82,184,235,20,164,106,35,136,136,237,17,237,15,184,138,96,0,0,0,0,0,9,14,82,247,118,194,158,57,86,243,123,128,
43,192,0,0,0,0,0,0,0,0,0,0,0,0,34,184,207,186,127,54,248,149,191,252,153,64,45,64,0,0,0,34,187,103,247,48,95,254,36,143,231,54,2,212,0,0,0,0,2,43,140,251,167,243,111,137,91,255,0,201,148,2,212,0,0,0,2,
43,182,127,115,5,255,0,226,72,254,115,96,45,64,0,0,0,0,37,86,95,116,118,80,249,26,131,245,170,0,42,160,0,0,0,34,187,81,127,135,99,63,249,129,66,254,160,5,168,0,0,0,0,4,171,101,207,112,171,103,254,171,
250,167,64,85,64,0,0,0,74,182,170,238,113,200,191,35,72,250,160,42,160,0,0,0,0,0,57,151,106,251,250,228,44,129,143,177,157,178,186,243,114,174,120,243,230,45,22,228,198,224,73,145,205,205,130,38,151,49,
104,95,53,100,137,229,184,183,16,147,89,242,73,74,53,53,232,117,83,29,188,70,92,149,137,226,149,137,214,245,31,20,204,110,102,57,212,107,81,17,204,218,245,158,209,43,111,122,96,193,91,207,205,123,116,
199,27,157,68,76,206,162,103,91,220,199,51,218,177,105,239,166,165,102,101,70,182,117,178,178,43,245,122,85,223,50,249,160,61,74,245,66,133,116,94,178,107,45,46,52,185,9,97,137,16,229,58,74,46,72,205,
110,235,236,72,81,169,163,74,136,187,83,27,113,90,51,249,24,177,246,190,88,199,51,173,77,109,58,239,239,26,152,154,234,117,60,246,152,150,92,145,56,188,220,151,239,76,89,50,71,60,90,41,91,90,99,233,59,
175,76,238,39,91,137,141,196,243,93,188,246,140,122,143,156,105,152,194,221,182,138,225,171,75,167,75,146,236,231,167,243,88,177,165,54,199,44,204,69,40,154,112,247,156,78,138,81,145,123,26,84,133,104,
173,226,33,143,13,167,61,179,86,145,242,87,113,245,152,181,43,104,250,116,197,235,59,245,153,215,190,173,205,106,224,156,17,147,127,153,109,118,237,29,55,180,91,235,185,199,104,136,227,180,206,251,111,
29,139,179,142,79,191,114,29,122,221,169,98,250,13,22,21,187,80,106,159,87,158,197,224,185,75,105,78,70,110,66,84,211,71,1,28,169,110,186,130,61,86,142,58,252,28,109,195,211,150,158,108,206,163,118,175,
239,95,255,0,38,102,57,253,244,102,139,98,180,83,91,153,138,219,246,153,152,254,99,166,103,95,110,87,177,224,0,0,0,0,0,0,0,0,0,0,144,229,47,119,108,41,227,149,111,55,184,2,188,0,0,0,0,0,0,0,0,0,0,0,0,
2,43,140,251,167,243,111,137,91,255,0,201,148,2,212,0,0,0,2,43,182,127,115,5,255,0,226,72,254,115,96,45,64,0,0,0,0,34,184,207,186,127,54,248,149,191,252,153,64,45,64,0,0,0,34,187,103,247,48,95,254,36,
143,231,54,2,212,0,0,0,0,2,85,101,247,71,101,15,145,168,63,90,160,2,170,0,0,0,2,43,181,23,248,118,51,255,0,152,20,47,234,0,90,128,0,0,0,0,74,182,92,247,10,182,127,234,191,170,116,5,84,0,0,0,4,171,106,
174,231,28,139,242,52,143,170,2,170,0,0,0,0,0,2,55,153,172,107,133,57,34,196,201,118,173,33,23,37,74,218,106,116,9,116,62,112,220,119,165,195,148,150,247,205,135,28,50,108,157,66,217,108,200,150,164,165,
68,106,35,81,112,16,199,51,135,61,239,173,214,245,233,157,119,141,90,45,89,231,81,49,222,38,59,243,19,29,181,51,201,17,155,13,105,184,139,82,209,104,153,251,77,109,28,115,27,137,137,137,212,243,88,143,
84,99,54,97,92,155,150,172,252,173,119,71,181,83,6,234,174,196,162,82,232,22,156,154,132,99,121,17,161,79,41,75,92,151,146,225,178,149,173,75,112,247,80,226,136,146,132,246,198,163,208,75,20,91,195,95,
21,233,49,54,243,171,146,103,157,68,86,53,88,247,159,89,182,163,215,81,189,110,101,51,95,17,23,197,146,102,180,242,115,99,143,121,182,74,90,38,99,255,0,172,70,231,210,102,117,10,77,11,8,87,109,171,255,
0,20,85,84,218,106,178,97,189,88,168,221,21,132,173,8,223,155,46,58,83,188,73,82,183,141,27,196,77,160,146,71,186,134,208,71,161,16,157,34,184,252,69,162,155,242,235,138,105,89,158,243,51,151,29,247,63,
91,106,247,153,237,185,159,164,48,102,139,230,173,50,90,62,57,203,23,180,123,86,49,101,164,70,248,220,87,170,148,143,89,239,62,178,220,49,69,151,89,182,178,102,95,171,84,161,243,106,125,126,185,22,101,
53,238,85,10,229,218,69,58,43,42,86,137,51,52,232,227,107,78,138,34,62,26,233,161,145,138,188,60,77,60,55,151,110,253,119,159,218,122,117,63,190,157,15,17,104,201,154,150,175,104,199,90,254,241,107,204,
199,241,48,169,9,169,0,0,0,0,0,0,0,0,0,0,72,114,151,187,182,20,241,202,183,155,220,1,94,0,0,0,0,0,0,0,0,0,0,0,0,1,21,198,125,211,249,183,196,173,255,0,228,202,1,106,0,0,0,1,21,219,63,185,130,255,0,241,
36,127,57,176,22,160,0,0,0,0,17,92,103,221,63,155,124,74,223,254,76,160,22,160,0,0,0,17,93,179,251,152,47,255,0,18,71,243,155,1,106,0,0,0,0,1,42,178,251,163,178,135,200,212,31,173,80,1,85,0,0,0,1,21,218,
139,252,59,25,255,0,204,10,23,245,0,45,64,0,0,0,0,37,91,46,123,133,91,63,245,95,213,58,2,170,0,0,0,2,85,181,87,115,142,69,249,26,71,213,1,85,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,33,202,94,238,216,
83,199,42,222,111,112,5,120,0,0,0,0,0,0,0,0,0,0,0,0,4,30,210,173,67,181,118,177,200,208,43,47,122,151,34,231,167,210,23,68,231,105,83,104,168,243,118,223,75,233,97,102,91,171,90,13,104,53,32,143,120,136,
245,211,78,32,47,0,0,0,0,35,219,95,211,38,85,246,105,191,227,64,135,34,124,163,167,242,137,143,17,165,58,234,201,14,33,106,221,66,72,212,163,36,164,207,66,35,62,0,41,150,173,213,71,190,45,202,117,126,
129,81,143,87,162,212,89,76,136,147,98,172,150,219,205,168,184,25,31,253,186,72,245,35,226,64,50,160,0,0,0,34,150,1,250,155,181,86,90,141,40,141,135,170,116,138,36,216,73,112,140,185,195,45,38,75,78,173,
7,208,162,66,212,148,171,78,131,82,117,246,197,168,90,192,0,0,0,69,118,208,35,236,91,200,206,18,84,104,98,152,114,28,52,150,187,173,182,180,45,106,225,212,73,74,140,255,0,49,0,180,54,226,30,109,46,54,
164,173,10,34,82,84,147,212,140,143,160,200,192,126,128,0,0,0,74,108,133,19,155,69,229,53,167,182,74,41,84,38,84,101,208,75,46,124,163,79,235,221,90,15,253,68,2,172,0,0,0,2,37,180,227,169,146,246,39,165,
50,124,173,74,101,249,74,121,136,168,45,92,91,108,41,111,190,189,11,222,161,182,212,165,40,248,22,133,214,100,70,22,208,0,0,0,24,203,150,229,165,89,214,253,70,185,92,158,197,46,143,78,97,114,101,205,148,
178,67,108,182,146,213,74,81,159,81,17,0,159,236,188,203,205,96,107,69,79,71,126,41,190,195,178,80,220,150,84,203,156,155,143,56,226,13,72,89,18,147,170,84,147,208,200,143,143,18,1,83,0,0,0,1,42,218,171,
185,199,34,252,141,35,234,128,170,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,144,229,47,119,108,41,227,149,111,55,184,2,188,0,0,0,0,0,0,0,0,0,0,0,0,3,90,200,88,230,221,202,150,195,244,11,158,154,138,
149,53,213,37,212,145,168,208,227,14,164,245,67,205,56,147,37,54,226,15,138,86,131,37,36,250,12,4,177,23,221,207,179,196,133,67,200,179,30,184,241,210,119,81,14,252,52,17,201,167,39,160,155,170,161,36,
69,186,92,8,165,160,137,39,248,212,160,251,117,5,206,44,166,103,70,102,76,103,155,145,29,228,19,141,186,210,137,72,90,76,181,37,36,203,129,145,145,234,70,64,62,160,0,0,57,234,233,181,42,251,54,220,117,
27,230,198,167,72,171,88,53,23,149,46,232,179,32,163,125,200,206,43,139,149,42,123,101,239,253,243,177,203,131,133,170,147,219,234,75,11,133,171,117,82,47,139,114,157,95,160,84,99,213,168,213,22,83,34,
44,216,171,223,109,214,213,208,100,127,246,233,35,212,143,137,0,202,128,0,0,154,230,203,22,167,112,83,105,183,45,172,150,202,249,181,221,84,234,65,56,179,67,114,210,101,163,240,157,50,252,91,232,45,222,
62,213,100,218,250,80,64,54,124,121,126,82,242,101,155,76,185,40,235,89,194,156,222,247,36,242,119,93,97,196,153,165,198,92,73,241,75,136,90,84,133,36,250,20,147,32,27,24,0,0,12,85,217,109,195,188,173,
106,205,191,81,71,41,79,170,194,122,12,132,119,205,186,131,66,203,200,163,1,58,217,66,228,153,114,236,249,102,29,81,123,245,154,92,85,80,234,70,126,219,157,193,113,113,31,51,248,12,220,97,71,251,64,86,
128,0,0,0,73,240,143,255,0,83,187,242,253,116,248,148,203,176,226,50,175,129,168,176,98,70,52,255,0,249,155,124,255,0,212,96,43,0,0,0,0,33,120,151,240,195,149,171,249,85,242,229,104,20,194,122,218,180,
9,69,170,84,202,28,46,127,57,58,151,227,222,109,45,165,73,61,13,168,200,50,246,230,2,232,0,0,3,240,243,205,199,105,110,186,180,180,210,18,106,90,214,122,37,36,92,76,204,250,136,7,60,81,148,123,90,221,
113,235,82,35,171,251,152,160,203,229,41,108,60,157,19,116,77,109,92,37,173,39,211,13,165,23,177,164,248,58,180,239,158,169,74,53,14,138,0,0,0,0,1,42,218,171,185,199,34,252,141,35,234,128,170,128,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,144,229,47,119,108,41,227,149,111,55,184,2,188,0,0,0,0,0,0,0,0,0,0,0,0,0,3,240,251,13,201,101,198,94,109,46,180,226,77,11,109,100,70,149,36,203,67,35,35,233,35,1,13,
149,143,110,92,7,49,234,190,52,140,229,118,200,208,220,155,142,249,66,74,163,113,213,78,210,150,163,209,179,226,102,113,84,100,218,189,225,180,126,216,41,216,239,36,91,249,82,218,106,185,110,78,231,113,
13,102,211,205,58,218,154,145,21,228,251,118,95,105,68,75,105,212,159,5,33,100,70,95,7,18,1,179,128,0,0,231,203,166,212,171,236,225,113,212,111,139,26,157,34,173,97,212,94,84,187,162,205,132,141,247,35,
56,174,46,84,169,237,151,191,247,206,176,92,28,45,84,159,100,212,150,22,235,86,234,164,95,22,229,58,191,64,168,199,171,81,170,44,166,68,89,177,87,190,219,173,159,65,145,255,0,219,164,143,82,62,36,3,42,
0,0,2,35,86,89,96,108,180,85,141,226,102,192,190,102,33,154,137,173,122,55,75,173,47,68,50,249,23,66,91,149,162,91,95,81,58,77,159,227,20,96,45,192,0,0,0,34,56,60,189,105,230,44,211,101,40,183,25,245,
90,53,215,5,42,224,102,197,65,141,29,211,225,46,117,22,89,254,181,241,1,110,0,0,0,1,39,217,115,255,0,21,134,169,245,131,226,170,253,70,167,94,222,239,147,50,124,137,40,253,155,142,160,139,243,17,0,172,
0,0,0,144,237,25,114,212,215,69,164,99,235,106,90,225,221,183,203,235,166,198,148,201,232,228,8,73,73,42,116,210,248,13,166,143,68,159,249,174,178,93,96,41,54,165,175,76,178,109,154,85,191,69,136,220,
10,69,46,43,112,226,70,104,180,75,77,54,146,74,82,95,168,136,128,101,64,0,0,115,197,215,86,147,180,253,227,81,176,232,139,113,172,95,69,145,205,238,186,219,42,52,250,175,33,62,218,149,25,69,210,217,112,
231,14,23,197,17,234,107,208,58,2,20,40,244,216,108,68,136,195,81,98,71,109,45,50,195,8,36,54,218,18,90,37,41,73,112,34,34,34,34,34,232,208,7,220,0,0,0,0,4,171,106,174,231,28,139,242,52,143,170,2,170,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,67,148,189,221,176,167,142,85,188,222,224,10,240,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,110,64,194,238,84,110,98,190,44,138,146,109,59,253,166,137,183,37,114,102,184,
85,102,211,237,88,158,201,25,114,168,234,75,132,100,235,122,246,170,211,84,152,125,241,158,103,110,236,169,174,214,185,233,138,179,114,20,86,141,217,22,252,167,73,105,144,217,30,135,38,27,218,17,73,96,
207,223,36,137,73,212,137,105,65,240,1,75,0,0,1,207,247,77,169,87,217,206,227,168,223,22,61,58,69,90,197,168,188,169,119,69,155,9,27,206,71,112,248,185,81,167,160,191,25,214,235,5,193,194,213,73,246,77,
73,97,107,181,174,154,69,239,110,83,171,212,26,140,122,181,26,160,202,100,69,155,21,123,205,186,131,232,50,63,251,116,145,145,145,241,32,25,80,0,24,123,190,211,165,223,86,189,82,222,173,69,76,202,85,74,
58,227,72,101,93,104,81,105,169,31,82,139,164,140,184,145,145,25,113,32,26,6,14,187,170,204,174,171,143,46,233,110,75,188,45,98,66,61,80,144,105,37,214,105,235,212,163,79,34,46,181,18,77,14,105,208,235,
107,234,82,64,85,192,0,0,68,175,148,250,207,218,163,26,215,210,147,76,91,166,147,81,181,37,44,248,36,223,108,138,124,62,63,14,235,51,200,181,233,223,224,2,218,0,0,3,85,202,247,87,172,76,91,120,220,187,
252,159,168,212,105,149,29,254,247,145,97,110,107,255,0,196,7,203,15,90,197,99,98,75,38,220,36,110,122,145,68,133,3,119,78,131,105,132,35,255,0,228,6,222,0,3,242,227,136,101,181,184,226,210,134,208,70,
165,41,71,161,17,23,73,153,128,136,224,52,175,39,92,247,14,100,150,74,56,181,164,21,42,214,109,95,138,162,178,179,52,190,69,174,154,202,119,121,253,116,35,228,202,57,31,181,1,112,0,0,1,11,202,183,189,
115,36,94,47,98,92,125,45,200,50,210,218,23,117,221,44,116,80,226,44,181,38,25,62,131,152,242,117,220,47,197,164,205,195,227,184,70,21,187,58,207,163,216,22,189,50,221,160,65,106,155,71,166,178,152,241,
163,52,92,16,146,235,51,233,53,25,234,102,163,226,102,102,102,102,102,96,51,32,0,0,0,0,0,37,91,85,119,56,228,95,145,164,125,80,21,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,28,165,238,237,133,60,114,
173,230,247,0,87,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,106,25,39,21,219,249,82,151,26,37,110,59,137,147,9,238,117,78,170,66,116,216,155,78,144,69,161,61,29,228,246,205,172,136,244,225,192,203,82,81,25,25,
145,134,129,73,202,117,252,61,80,139,111,229,201,12,200,167,74,144,81,169,87,244,102,9,152,114,141,71,162,25,158,130,237,98,62,124,8,151,193,151,15,218,154,20,100,216,11,112,0,0,8,13,209,106,213,246,118,
184,234,55,189,143,78,126,173,99,212,30,84,171,158,206,132,141,231,24,89,241,93,70,158,130,252,103,91,172,23,7,75,85,39,217,11,183,11,77,173,116,210,47,123,118,159,94,160,212,24,171,81,170,12,166,68,89,
177,87,188,219,168,62,131,35,255,0,246,93,36,100,100,124,72,6,84,0,4,167,57,217,117,87,209,74,191,45,8,220,189,239,106,154,222,143,25,4,68,117,72,107,211,156,192,81,159,249,137,73,26,12,253,171,168,108,
254,16,27,213,145,121,210,178,29,163,74,185,40,143,156,138,93,73,132,200,97,106,78,234,136,143,165,42,79,189,82,76,141,42,73,241,35,35,35,232,1,156,0,1,22,218,229,149,211,241,17,94,12,52,183,101,88,245,
104,23,82,119,58,73,152,175,165,82,250,181,208,226,42,82,120,119,192,44,232,90,93,66,86,133,18,208,162,213,42,73,234,70,95,9,0,253,0,0,147,237,74,103,35,9,214,41,73,35,81,215,102,83,168,6,130,233,82,102,
206,98,34,139,245,110,188,173,127,54,160,43,0,0,0,35,59,66,205,149,121,57,67,196,180,135,220,102,117,223,202,29,94,75,6,100,184,84,70,141,60,241,205,226,246,170,119,125,17,208,124,56,190,165,23,180,48,
21,234,125,62,53,38,4,104,48,216,68,104,113,154,75,44,176,210,116,67,104,73,17,37,36,93,68,68,68,64,61,0,0,36,57,171,41,86,233,213,88,24,251,30,180,204,220,143,91,104,221,109,233,8,223,141,68,135,174,
234,234,18,139,173,41,62,13,183,210,226,244,79,65,40,200,54,252,87,140,169,120,150,207,143,66,166,45,233,75,55,23,42,109,74,90,183,228,212,37,184,122,187,37,229,251,231,22,174,38,125,69,161,22,132,68,
68,27,120,0,0,0,0,0,0,9,86,213,93,206,57,23,228,105,31,84,5,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,135,41,123,187,97,79,28,171,121,189,192,21,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,30,74,173,38,21,
118,155,38,157,82,134,197,66,4,166,205,167,226,202,109,46,52,234,12,180,52,169,42,35,37,17,151,81,128,137,42,137,116,236,214,151,100,91,204,84,175,156,98,74,35,93,188,149,27,245,74,11,125,106,132,106,
61,233,49,210,92,121,186,143,148,65,127,195,53,17,19,96,44,22,149,225,69,191,45,248,117,203,122,167,30,175,73,150,157,230,101,70,94,242,79,168,200,250,210,162,61,72,210,122,26,76,140,140,136,200,200,6,
96,0,4,14,232,181,106,251,60,220,85,11,222,200,167,191,85,178,106,15,42,85,207,103,66,70,243,140,172,248,174,163,79,65,126,51,173,214,11,131,164,70,164,251,33,118,225,103,181,174,154,69,237,110,211,235,
212,26,131,21,90,61,65,148,191,22,100,101,239,54,234,15,160,200,255,0,216,203,164,140,140,143,137,0,202,128,0,133,199,211,0,102,34,139,161,51,143,175,233,198,108,37,13,158,229,42,184,178,51,82,76,250,
18,212,189,12,203,160,137,228,153,116,186,64,46,128,0,49,151,61,187,10,239,182,170,212,42,155,102,245,54,169,17,232,50,91,47,124,211,136,52,44,191,106,84,96,39,123,43,215,231,87,176,13,158,138,169,153,
214,233,49,151,65,169,239,123,110,121,5,197,195,124,207,224,51,114,58,207,246,128,171,128,0,147,231,34,85,74,230,196,116,52,104,162,157,119,183,33,228,107,208,212,88,82,229,146,191,81,58,195,37,250,212,
64,43,0,0,60,181,74,156,74,45,54,93,66,124,134,226,65,136,202,228,72,144,234,183,80,211,105,73,169,74,81,245,17,17,25,159,234,1,34,217,222,153,46,234,58,230,88,173,198,114,61,90,243,83,106,167,70,144,
141,28,129,69,107,123,153,49,161,145,41,42,89,45,114,22,147,232,92,133,23,189,32,22,112,0,19,140,211,150,156,198,180,184,16,40,180,223,92,119,205,117,213,67,160,80,80,189,195,148,241,22,170,113,213,126,
45,134,139,183,113,207,122,146,235,51,34,48,255,0,112,182,39,115,26,81,231,76,172,212,189,112,222,245,215,74,109,193,94,82,55,14,91,250,104,148,54,159,197,176,209,118,141,183,208,148,151,194,106,51,10,
48,0,0,0,0,0,0,0,9,86,213,93,206,57,23,228,105,31,84,5,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,135,41,123,187,97,79,28,171,121,189,192,21,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,27,199,16,85,
45,235,134,165,124,98,217,17,104,215,92,195,39,106,116,105,134,164,210,171,198,69,167,179,165,36,102,203,250,17,17,73,65,111,112,34,90,92,73,110,128,216,177,166,95,165,100,71,102,82,220,142,253,191,119,
211,16,147,170,219,53,45,19,50,22,246,164,149,240,224,235,42,50,61,199,155,51,66,190,18,50,52,144,111,128,0,32,215,69,171,86,217,242,226,168,94,214,69,61,250,173,151,80,121,82,174,107,62,18,55,156,101,
103,197,117,24,8,47,198,117,186,193,112,116,136,212,159,100,46,220,44,150,189,209,73,189,173,218,125,122,131,80,98,171,71,168,50,151,226,204,140,189,230,221,65,244,25,31,251,25,116,145,145,145,241,32,
25,80,26,238,66,177,41,89,54,203,171,91,21,182,150,229,54,164,201,180,225,180,179,67,141,171,93,80,227,106,46,41,90,20,73,82,84,92,73,73,35,234,1,166,96,155,246,169,87,137,85,179,46,231,154,59,246,212,
113,17,42,42,70,164,83,227,168,143,155,79,65,31,189,121,5,169,145,123,87,18,226,122,136,5,84,0,4,95,11,35,214,158,95,204,150,113,182,109,71,85,82,45,215,5,42,62,150,42,12,110,187,167,230,231,112,230,171,
253,96,45,0,0,36,247,66,14,177,180,213,131,21,42,35,106,145,110,214,42,79,39,189,113,199,161,48,193,254,212,156,175,32,10,192,0,8,166,113,81,229,11,182,131,136,34,171,122,21,69,5,89,186,141,38,94,199,
72,105,205,19,29,94,52,242,73,175,206,219,114,0,90,80,132,180,132,161,9,36,33,37,162,82,146,208,136,190,2,1,250,1,167,229,92,157,75,196,182,139,213,186,139,79,205,121,110,34,36,10,100,52,239,202,168,203,
112,244,106,51,40,247,206,45,92,11,224,45,76,244,34,51,1,169,97,76,95,91,166,212,170,23,254,65,117,137,185,30,186,209,52,235,81,213,191,26,139,12,143,121,186,124,83,235,74,79,182,91,157,46,185,170,143,
129,36,136,43,160,0,0,0,0,0,0,0,0,37,91,85,119,56,228,95,145,164,125,80,21,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,28,165,238,237,133,60,114,173,230,247,0,87,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,104,217,51,17,210,178,66,34,77,231,18,104,55,77,56,148,116,171,150,150,100,137,176,20,125,59,170,50,50,91,106,211,69,52,178,82,22,92,20,147,234,13,102,210,203,149,107,94,226,167,89,25,70,59,20,
219,138,97,242,84,187,138,26,20,138,85,113,93,73,108,204,207,155,201,62,184,235,62,61,45,169,194,212,146,21,240,0,16,139,158,214,171,96,11,138,161,123,89,52,247,234,182,109,65,229,74,185,172,248,104,222,
113,165,159,21,212,96,32,191,27,214,235,5,193,210,35,82,125,144,187,112,177,218,247,69,38,245,183,169,245,218,21,65,138,173,30,160,202,95,139,50,50,247,155,117,7,208,100,127,236,100,124,72,200,200,248,
144,12,160,8,246,119,182,42,180,121,116,172,161,105,197,118,101,205,108,33,105,153,78,101,123,167,87,165,40,201,82,34,159,81,173,58,114,173,107,208,180,105,239,204,5,46,210,186,169,87,205,177,75,184,104,
115,27,168,82,42,113,209,42,44,150,143,84,184,218,203,82,63,215,199,137,117,30,164,3,44,2,51,123,183,235,79,105,220,111,112,37,6,152,215,53,50,163,106,74,115,94,10,125,9,41,240,245,253,72,143,80,34,248,
192,22,96,0,18,123,85,40,171,237,49,144,106,41,81,169,20,171,126,143,71,36,245,37,213,57,54,75,190,84,61,27,200,2,176,3,19,118,221,52,203,30,215,171,92,53,169,72,133,73,165,197,114,100,169,11,62,8,109,
9,53,40,252,133,209,214,2,121,179,197,175,84,98,131,85,189,174,104,203,139,119,94,178,83,85,155,21,211,237,160,71,36,238,195,133,210,100,92,139,59,164,173,56,27,139,117,94,248,5,100,6,18,244,188,168,248,
246,213,169,220,119,4,214,233,212,122,107,38,252,153,46,116,37,37,208,68,93,38,163,51,34,36,151,19,51,34,46,38,2,81,138,44,138,246,67,188,90,203,57,10,27,144,39,19,107,110,213,181,159,232,160,196,89,104,
111,60,93,7,53,228,233,190,127,139,78,141,151,191,212,46,64,0,0,0,0,0,0,0,0,0,37,91,85,119,56,228,95,145,164,125,80,21,80,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,18,28,165,238,237,133,60,114,173,230,247,
0,87,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,98,110,171,82,143,124,91,243,104,117,250,108,106,189,34,107,102,219,240,229,182,75,109,105,253,71,208,101,210,70,92,72,200,140,180,50,1,32,110,161,116,
108,220,76,199,169,185,82,190,113,122,53,34,172,47,126,77,94,128,130,232,41,4,90,174,92,98,47,198,150,175,35,78,220,156,46,221,33,104,163,86,169,247,29,38,37,82,147,58,53,78,155,45,180,189,30,100,55,82,
235,47,32,203,82,82,22,147,50,81,25,117,145,128,246,128,133,92,246,181,91,1,220,53,11,214,201,167,191,85,179,234,15,42,85,203,104,67,78,242,219,89,241,93,66,2,63,205,235,117,146,224,233,17,169,58,56,93,
184,88,109,123,162,147,122,219,212,250,237,10,160,197,86,145,61,148,191,26,100,101,239,33,212,31,65,145,255,0,177,145,241,35,35,35,226,64,50,128,32,214,209,171,0,102,21,90,174,18,209,96,94,242,157,153,
67,112,201,41,102,151,85,61,86,252,30,173,16,255,0,108,243,101,208,75,39,82,93,41,32,23,144,17,221,171,89,58,126,37,93,218,211,102,185,54,77,78,13,212,74,35,208,210,196,71,210,185,154,127,238,136,114,
145,254,176,22,20,168,150,146,82,76,148,147,45,72,200,248,25,0,255,0,64,73,176,81,181,84,184,178,213,192,217,127,137,93,239,71,37,107,169,110,195,137,22,9,145,126,110,82,51,167,250,212,96,43,32,34,185,
48,191,189,188,171,68,198,236,234,229,191,69,228,110,59,164,203,93,199,9,43,51,129,8,207,160,249,71,80,167,150,147,247,145,210,71,193,192,22,160,31,9,211,163,82,225,72,153,50,67,81,98,71,109,79,60,251,
203,36,33,180,36,181,82,148,163,224,68,68,70,102,103,209,160,8,5,163,73,153,180,221,227,77,191,171,173,185,31,24,209,159,41,54,149,13,228,154,78,170,250,117,36,213,164,160,253,225,127,233,219,81,112,47,
101,50,212,209,160,116,48,0,0,0,0,0,0,0,0,0,0,9,86,213,93,206,57,23,228,105,31,84,5,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,135,41,123,187,97,79,28,171,121,189,192,21,224,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,17,122,190,43,174,226,202,164,139,135,18,183,25,49,37,72,84,154,189,143,37,100,212,25,234,81,153,173,232,139,232,137,36,204,204,204,200,185,39,12,251,116,146,180,112,131,121,198,
217,78,131,148,169,178,164,82,28,125,137,176,29,230,213,42,69,65,163,98,117,57,253,56,180,251,71,197,10,235,35,226,149,23,108,149,41,38,70,97,183,128,134,220,246,181,91,3,92,53,11,214,201,167,191,84,180,
103,188,169,87,45,161,13,59,203,66,207,219,212,32,35,252,222,183,89,46,14,145,111,39,71,11,183,10,245,177,115,210,111,75,122,159,93,161,84,24,170,82,39,178,151,227,76,140,173,228,58,131,232,50,63,246,
50,62,36,100,100,124,72,6,27,42,99,106,102,89,177,170,86,213,80,212,211,114,73,46,49,45,162,46,86,28,132,40,150,204,134,143,169,109,173,41,81,31,194,64,53,236,15,145,170,119,141,10,161,67,186,80,152,215,
237,174,249,83,107,172,161,190,77,183,92,221,213,169,77,23,249,79,163,71,19,240,25,169,61,41,48,27,245,193,66,133,116,208,106,84,106,155,9,147,78,168,198,118,28,150,21,208,227,78,32,208,180,159,235,73,
153,0,159,236,199,90,155,88,193,86,147,85,87,57,106,213,34,58,232,21,55,12,245,53,205,128,234,225,72,87,237,118,58,207,246,128,168,0,147,108,174,234,42,56,54,133,91,109,9,73,92,79,206,184,181,73,105,189,
207,166,61,44,143,246,147,228,3,118,200,183,221,59,25,88,245,171,162,171,190,112,169,145,212,250,155,105,38,167,30,87,66,26,65,23,74,214,179,74,18,93,106,81,16,13,95,1,88,85,43,54,205,126,163,114,18,23,
122,220,178,149,91,175,186,131,37,18,100,184,68,73,142,149,104,90,182,195,105,109,132,107,239,90,35,233,51,1,75,1,206,149,100,47,107,107,173,250,75,47,153,97,106,12,195,106,162,235,74,237,110,169,205,
43,140,100,168,189,180,38,150,94,200,101,193,213,167,112,181,74,87,168,116,67,77,33,134,208,219,104,75,109,160,137,41,66,75,66,73,23,65,17,0,253,128,0,0,0,0,0,0,0,0,0,0,149,109,85,220,227,145,126,70,145,
245,64,85,64,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,72,114,151,187,182,20,241,202,183,155,220,1,94,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,58,201,56,121,155,194,161,30,226,160,212,222,180,111,
168,73,36,69,184,32,160,148,110,55,174,167,30,83,103,218,200,97,70,92,91,95,18,62,217,6,133,17,40,7,146,195,204,50,37,220,158,178,239,154,98,45,91,225,41,51,97,180,185,191,2,178,132,150,170,126,11,167,
166,249,105,197,76,171,71,91,227,169,41,36,75,80,84,0,67,238,123,94,173,130,110,26,133,233,101,64,126,169,105,79,116,228,220,182,140,52,239,45,43,63,111,80,130,143,243,122,220,100,184,58,69,188,157,28,
46,220,43,150,197,207,73,189,45,248,21,202,28,246,42,148,137,237,19,241,165,198,86,242,29,65,244,25,31,251,25,31,18,50,50,61,12,128,73,51,205,14,117,133,93,167,230,59,106,26,229,84,40,76,28,107,134,157,
29,10,83,149,74,57,158,243,132,73,79,182,117,131,213,230,248,106,122,56,159,124,3,120,184,115,45,173,111,90,112,110,30,124,170,164,26,132,53,212,33,53,75,65,200,145,46,50,27,39,28,117,150,147,219,184,
72,108,201,70,73,35,61,52,34,35,51,34,48,227,91,35,111,252,127,75,201,85,155,63,27,200,43,206,101,251,120,194,126,128,77,199,121,136,240,145,49,166,27,152,228,130,113,41,89,114,114,27,144,241,160,136,
141,92,185,104,100,90,168,131,176,178,238,70,133,104,99,108,139,80,135,57,151,107,54,221,191,46,168,236,54,156,35,125,162,76,119,28,109,70,130,237,136,148,104,61,211,211,137,164,200,186,12,6,103,24,91,
94,179,49,173,167,111,238,114,126,164,210,34,64,220,211,77,57,38,80,141,63,248,128,157,92,134,156,199,156,224,219,40,209,235,90,194,91,53,122,198,154,26,36,85,150,157,232,81,143,226,80,103,37,69,196,183,
149,31,224,1,107,1,3,201,21,186,134,122,187,234,56,178,210,169,189,78,183,105,230,150,239,91,142,10,205,46,52,149,17,31,169,113,156,46,137,14,36,200,220,89,113,105,181,117,45,105,34,11,85,185,110,82,237,
10,5,62,137,69,128,197,46,145,79,97,17,162,66,140,130,67,108,180,146,209,41,73,23,65,17,16,12,144,0,0,0,0,0,0,0,0,0,0,0,9,86,213,93,206,57,23,228,105,31,84,5,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
4,135,41,123,187,97,79,28,171,121,189,192,21,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,26,229,255,0,143,104,25,58,219,122,135,113,192,76,232,43,90,93,65,146,141,183,99,186,147,213,15,50,226,
76,148,219,136,62,41,90,76,148,71,208,96,38,141,95,119,22,5,145,204,114,36,181,86,236,36,145,38,37,248,104,209,216,69,174,132,221,81,9,45,18,69,192,138,90,72,144,124,57,66,108,200,214,160,181,48,251,82,
152,109,230,92,67,204,184,146,90,28,109,68,164,169,38,90,145,145,151,73,25,117,128,133,223,116,231,246,111,168,213,114,21,186,148,174,199,146,225,203,186,109,162,90,80,77,40,207,183,168,66,35,50,34,119,
173,198,75,66,116,184,167,71,61,184,78,246,122,218,202,230,218,162,202,203,78,227,167,237,231,110,91,118,227,117,138,67,85,246,94,230,114,41,107,215,154,41,222,72,210,180,41,124,155,188,116,86,155,189,
7,212,28,67,134,178,14,73,194,155,123,216,81,51,69,42,85,147,70,167,162,172,204,26,44,22,100,72,131,29,137,77,62,230,236,36,37,78,169,214,213,32,219,34,36,26,244,221,36,150,155,132,73,10,251,152,150,200,
177,118,241,178,114,213,171,103,94,209,45,218,145,206,144,229,5,118,164,152,170,114,161,205,156,209,113,90,113,40,95,38,100,165,58,104,52,145,165,77,240,212,148,73,64,107,31,218,133,120,49,118,215,108,
27,187,31,75,184,104,87,195,201,118,213,168,81,166,210,166,211,103,205,140,241,239,178,209,50,243,104,229,219,223,55,72,201,59,233,51,117,31,155,80,216,174,108,199,121,255,0,103,3,248,194,77,243,62,126,
66,175,222,52,202,164,171,181,250,132,197,72,123,157,17,48,112,217,105,213,168,247,91,96,245,70,132,122,31,42,242,136,184,160,146,29,101,176,254,75,180,178,6,46,82,173,121,213,59,134,98,164,57,62,187,
113,72,165,200,139,26,117,77,245,111,200,54,150,234,72,150,68,163,221,36,164,207,113,9,109,39,167,0,27,70,96,200,117,138,237,204,206,42,199,179,83,30,243,158,193,72,170,214,80,130,113,22,229,61,70,101,
206,86,93,6,251,154,41,44,182,126,217,68,106,61,18,131,48,27,254,53,198,244,44,77,102,211,237,139,114,42,163,83,97,145,158,243,171,55,30,125,197,25,169,199,157,89,241,113,213,168,205,74,89,241,51,51,48,
27,56,0,0,0,0,0,0,0,0,0,0,0,0,9,86,213,93,206,57,23,228,105,31,84,5,84,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,4,135,41,123,187,97,79,28,171,121,189,192,21,224,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,31,55,216,106,83,14,48,251,104,121,151,18,104,91,110,36,148,149,36,203,67,35,35,233,35,46,160,17,103,172,107,143,3,202,93,71,30,198,118,189,98,241,114,101,134,75,46,86,31,29,84,229,45,107,
50,36,245,153,197,89,147,102,127,240,205,179,51,37,4,151,55,92,251,62,237,59,126,98,235,22,238,166,49,113,162,236,143,82,230,19,205,231,161,76,166,76,143,201,26,99,186,146,52,45,167,20,75,124,185,55,11,
82,82,9,38,158,223,136,79,241,78,199,211,54,108,218,34,175,110,224,171,218,122,99,85,232,228,155,149,218,228,70,165,162,128,202,157,74,216,117,183,18,104,75,146,148,72,117,45,52,182,204,137,10,83,139,
51,34,74,92,14,196,179,48,13,141,100,146,100,71,161,177,84,173,28,132,204,126,191,89,34,153,82,145,33,61,15,46,67,132,107,222,46,58,17,25,37,58,153,36,146,92,0,97,50,183,187,142,16,249,70,171,230,199,
192,80,239,27,34,222,200,84,39,168,183,69,14,157,112,210,94,61,87,10,167,21,18,26,51,208,200,143,117,100,101,169,106,122,31,73,106,3,137,246,143,216,254,217,137,144,172,107,154,255,0,168,214,174,156,37,
64,113,198,23,73,145,41,78,57,66,83,234,109,40,83,175,30,174,187,79,74,144,68,162,53,111,181,189,169,168,218,35,74,3,243,94,219,198,153,140,179,205,255,0,132,237,248,148,42,67,84,198,169,180,123,65,82,
20,212,26,84,57,6,209,156,163,144,189,82,148,52,214,250,116,65,118,202,54,141,9,35,53,167,64,235,60,35,140,104,216,210,209,81,83,170,71,113,212,170,239,29,70,173,114,188,164,173,234,188,181,145,111,62,
165,36,204,183,120,18,80,130,61,212,33,41,73,112,32,20,32,0,0,0,0,0,0,0,0,0,0,0,0,0,18,173,170,187,156,114,47,200,210,62,168,10,168,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,9,14,82,247,118,194,158,57,86,
243,123,128,43,192,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,60,149,104,242,229,83,37,179,2,90,96,77,113,165,33,153,75,107,149,38,86,101,161,47,112,204,137,90,31,29,12,248,128,254,95,237,39,
253,155,153,69,139,150,177,154,139,56,66,174,92,84,84,170,188,229,70,175,75,58,114,163,20,84,242,164,104,228,57,68,22,225,54,70,90,33,37,169,116,117,128,239,157,155,109,9,214,214,44,167,212,171,205,36,
175,27,149,71,95,184,29,34,208,213,58,65,18,148,143,253,173,35,147,97,5,212,134,80,64,42,64,36,57,91,221,199,8,124,163,85,243,99,224,43,192,60,213,58,108,90,205,54,93,62,116,118,229,193,150,210,216,126,
59,201,222,67,173,168,141,42,74,136,250,72,200,204,140,191,56,15,231,102,204,159,217,159,139,164,94,87,212,156,139,234,133,233,114,219,215,3,144,92,131,50,74,211,9,77,169,166,100,199,116,210,94,200,238,
243,79,183,174,250,205,38,105,81,26,79,67,1,253,0,183,105,22,229,145,14,13,179,66,135,76,160,198,105,149,46,37,34,158,219,113,208,150,146,100,74,52,52,146,45,18,70,164,234,100,90,106,162,215,164,6,112,
0,0,0,0,0,0,0,0,0,0,0,0,0,4,171,106,174,231,28,139,242,52,143,170,2,170,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,99,151,236,27,166,228,184,108,155,142,208,153,72,98,175,110,75,146,239,55,173,182,233,
176,243,111,199,91,42,226,217,239,18,139,120,140,184,104,124,122,52,226,24,253,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,
147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,
124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,
142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,
125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,13,51,
215,125,142,124,147,254,208,13,51,215,125,142,124,147,254,208,18,237,169,11,52,246,58,100,95,86,14,194,245,31,212,73,60,251,153,148,222,87,155,238,31,43,166,247,15,105,189,174,189,90,128,168,233,158,187,
236,115,228,159,246,128,105,158,187,236,115,228,159,246,128,151,228,162,205,63,223,22,32,231,71,97,243,238,127,82,230,124,137,77,228,247,189,79,123,127,148,212,245,211,119,93,52,235,211,94,0,42,26,103,
174,251,28,249,39,253,160,26,103,174,251,28,249,39,253,160,57,170,254,236,161,43,175,50,127,118,62,178,213,117,238,82,121,247,52,229,9,205,121,179,155,188,211,156,123,23,43,185,201,239,114,188,52,221,
211,136,9,175,246,112,158,88,59,195,43,122,186,81,11,46,114,209,125,87,254,240,57,239,170,28,203,69,242,60,151,255,0,107,127,148,215,78,31,240,250,183,64,119,71,225,191,244,127,252,112,7,225,191,244,127,
252,112,7,225,191,244,127,252,112,7,225,191,244,127,252,112,7,225,191,244,127,252,112,7,225,191,244,127,252,112,7,225,191,244,127,252,112,7,225,191,244,127,252,112,7,225,191,244,127,252,112,7,225,191,
244,127,252,112,7,225,191,244,127,252,112,7,225,191,244,127,252,112,7,225,191,244,127,252,112,7,225,191,244,127,252,112,13,115,34,217,25,147,36,216,149,219,90,115,246,44,88,149,104,142,68,113,232,252,
243,148,65,40,180,213,58,145,150,165,249,192,94,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,98,47,11,98,21,237,105,86,237,218,146,77,116,234,188,
23,233,242,82,93,38,211,173,169,181,151,145,70,3,71,217,206,239,151,114,227,56,116,202,211,169,59,186,217,89,219,245,246,139,165,51,99,145,32,220,211,169,47,35,147,125,29,58,161,228,128,167,128,144,229,
111,119,28,33,242,141,87,205,143,128,175,0,243,84,234,113,40,180,217,117,9,242,27,137,6,35,43,125,249,15,43,117,13,54,146,53,41,74,51,232,34,34,51,51,252,192,37,91,53,196,149,84,181,235,183,229,66,51,
177,39,95,117,103,43,200,142,250,77,46,51,11,147,109,136,40,81,25,17,165,92,213,134,22,164,232,91,170,113,101,211,169,152,85,151,78,138,228,246,167,42,51,42,154,211,106,101,185,38,217,27,136,66,140,141,
73,37,116,145,25,165,38,101,208,123,165,240,0,244,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,145,228,171,22,229,
160,94,45,228,108,120,211,50,235,156,138,34,215,45,199,157,38,89,175,69,65,153,163,117,195,224,220,166,183,149,201,184,174,213,68,102,218,204,146,105,82,3,102,199,25,138,215,202,9,146,205,34,106,227,214,
97,118,181,10,13,69,179,141,82,128,174,131,75,209,215,162,146,90,244,40,136,208,174,148,169,69,196,6,175,149,189,220,112,135,202,53,95,54,62,2,143,117,221,244,59,22,133,42,181,113,213,225,80,233,17,147,
188,244,218,131,233,101,164,23,231,82,140,139,246,117,128,140,203,98,171,181,44,214,163,72,166,206,160,225,232,239,33,247,74,123,74,143,46,234,82,76,148,132,114,74,209,109,65,212,136,213,190,68,167,244,
36,238,147,102,102,176,190,17,104,90,23,2,1,254,128,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,211,175,252,
61,102,101,19,138,187,158,221,135,84,151,19,255,0,43,60,210,109,75,139,211,175,35,33,6,151,91,233,63,104,162,1,160,206,217,46,222,155,83,165,206,43,203,32,180,229,41,110,46,9,42,234,148,250,163,26,208,
109,175,113,199,148,183,11,84,40,211,237,181,208,192,108,86,222,206,22,13,185,90,143,91,114,147,34,226,175,199,61,230,106,247,69,66,69,98,83,10,239,154,114,82,220,54,143,226,247,120,112,1,77,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,255,217,0,0};
const char* LfsrWindow::_20200518_132617_jpg = (const char*) resource_LfsrWindow__20200518_132617_jpg;
const int LfsrWindow::_20200518_132617_jpgSize = 22490;
