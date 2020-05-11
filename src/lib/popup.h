#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class PopUp  : public Component,
               public Button::Listener
{
public:
    PopUp (std::string txt);
    ~PopUp();

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;

private:
    std::unique_ptr<TextButton> okButton;
    std::unique_ptr<Label> diaText;
    std::string text;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (PopUp)
};


