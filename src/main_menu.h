#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class MainMenu  : public Component,
                  public Button::Listener
{
public:
    MainMenu ();
    ~MainMenu();

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;

private:
    std::unique_ptr<TextButton> _sym_section_button;
    std::unique_ptr<TextButton> _asym_section_button;
    std::unique_ptr<TextButton> _info_button;
    std::unique_ptr<TextButton> _lfsr_section_button;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainMenu)
};
