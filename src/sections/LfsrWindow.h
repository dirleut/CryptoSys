#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include <sstream>
#include <string>
using namespace std;

class LfsrWindow  : public Component, public Button::Listener
{
public:
   LfsrWindow ();
    ~LfsrWindow();
    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;
    void showMessage(const string message, const string header);
    static const char* _20200518_132617_jpg;
    static const int _20200518_132617_jpgSize;

private:
    string initSequence;
    int tbs[8] = { 0,0,0,0,0,0,0,0 };
    string keyGammaString = "";
    string keyGammaForUserText = "";
    string userTextString = "";

    void initializeElements();
    void onClickTb(int buttonID);
    void userTextChange();
    void onClickButtonShift();
    void onClickButtonBS();
    void onClickButtonEncrypt();
    void onClickButtonGenerateKeyGamma();
 
    bool checkValidSequence(string sequence);
    bool checkValidTbs();
    bool checkValidInput(string sequence);
    bool checkBSText(string text);

    string getOutputBit(string sequence);
    string getXORString(string stringForXOR);
    string reverseKeyGamma(string keyGamma);
    string updateSequence(string bit, string prevSequence);
    string getEncryptString(string textToEncrypt, string keyGammaValue);
    
    unique_ptr<TextButton> buttonToBS;
    unique_ptr<TextButton> buttonShift;
    unique_ptr<TextButton> keyToEncrypt;
    unique_ptr<TextButton> generateKeyGamma;
    //TextButton generateKeyGamma;
    unique_ptr<ToggleButton> tb0;
    unique_ptr<ToggleButton> tb1;
    unique_ptr<ToggleButton> tb2;
    unique_ptr<ToggleButton> tb3;
    unique_ptr<ToggleButton> tb4;
    unique_ptr<ToggleButton> tb5;
    unique_ptr<ToggleButton> tb6;
    unique_ptr<ToggleButton> tb7;

    TextEditor initValue;
    TextEditor keyGamma;
    TextEditor userText;
    unique_ptr<TextEditor> keyGammaToEncrypt;
    unique_ptr<TextEditor> resultEncrypt;

    unique_ptr<Label> label;
    unique_ptr<Label> label2;
    unique_ptr<Label> label3;
    unique_ptr<Label> label4;
    unique_ptr<Label> label5;
    
    Image cachedImage__20200518_132617_jpg_1;

    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LfsrWindow)
};


