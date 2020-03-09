#pragma once
#include <JuceHeader.h>
// TODO подписать нормальным языком
// TODO разгрузить конструктор
class SymWindow  : public Component,
                   public Button::Listener
{
public:
    SymWindow ();
    ~SymWindow();

    void paint (Graphics& g) override;
    void resized() override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    std::unique_ptr<TextButton> newButton;
    std::unique_ptr<TextEditor> textEditor;
    std::unique_ptr<Label> label;
    std::unique_ptr<Label> label3;
    std::unique_ptr<TextEditor> textEditor2;
    std::unique_ptr<Label> label4;
    std::unique_ptr<TextEditor> textEditor3;
    std::unique_ptr<ToggleButton> toggleButton3;
    std::unique_ptr<ToggleButton> toggleButton4;
    std::unique_ptr<ToggleButton> toggleButton5;
    std::unique_ptr<TextButton> newButton2;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SymWindow)
};
