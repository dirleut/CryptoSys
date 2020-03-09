
#include "SymWindow.h"

SymWindow::SymWindow ()
{

    newButton.reset (new TextButton ("New button"));
    addAndMakeVisible (newButton.get());
    newButton->setButtonText (CharPointer_UTF8 ("\xd0\x97\xd0\xb0\xd1\x88\xd0\xb8\xd1\x84\xd1\x80\xd0\xbe\xd0\xb2\xd0\xb0\xd1\x82\xd1\x8c"));
    newButton->addListener (this);
    newButton->setColour (TextButton::buttonColourId, Colour (0xff2fad2f));

    newButton->setBounds (128, 208, 150, 24);

    textEditor.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor.get());
    textEditor->setMultiLine (false);
    textEditor->setReturnKeyStartsNewLine (false);
    textEditor->setReadOnly (false);
    textEditor->setScrollbarsShown (true);
    textEditor->setCaretVisible (true);
    textEditor->setPopupMenuEnabled (true);
    textEditor->setText (String());

    textEditor->setBounds (171, 71, 320, 80);

    label.reset (new Label ("new label",
                            CharPointer_UTF8 ("\xd0\x9e\xd1\x82\xd0\xba\xd1\x80\xd1\x8b\xd1\x82\xd1\x8b\xd0\xb9 \xd1\x82\xd0\xb5\xd0\xba\xd1\x81\xd1\x82/\n"
                            "\xd0\x97\xd0\xb0\xd1\x88\xd0\xb8\xd1\x84\xd1\x80\xd0\xbe\xd0\xb2\xd0\xb0\xd0\xbd\xd0\xbd\xd1\x8b\xd0\xb9 \xd1\x82\xd0\xb5\xd0\xba\xd1\x81\xd1\x82")));
    addAndMakeVisible (label.get());
    label->setFont (Font ("Georgia", 16.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredRight);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label->setBounds (-29, 79, 200, 56);

    label3.reset (new Label ("new label",
                             CharPointer_UTF8 ("\xd0\x9a\xd0\xbb\xd1\x8e\xd1\x87 ")));
    addAndMakeVisible (label3.get());
    label3->setFont (Font ("Georgia", 16.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label3->setBounds (120, 160, 168, 19);

    textEditor2.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor2.get());
    textEditor2->setMultiLine (false);
    textEditor2->setReturnKeyStartsNewLine (false);
    textEditor2->setReadOnly (false);
    textEditor2->setScrollbarsShown (true);
    textEditor2->setCaretVisible (true);
    textEditor2->setPopupMenuEnabled (true);
    textEditor2->setText (String());

    textEditor2->setBounds (171, 159, 184, 24);

    label4.reset (new Label ("new label",
                             CharPointer_UTF8 ("\xd0\xa0\xd0\xb5\xd0\xb7\xd1\x83\xd0\xbb\xd1\x8c\xd1\x82\xd0\xb0\xd1\x82")));
    addAndMakeVisible (label4.get());
    label4->setFont (Font ("Georgia", 16.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredRight);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    label4->setBounds (48, 272, 120, 40);

    textEditor3.reset (new TextEditor ("new text editor"));
    addAndMakeVisible (textEditor3.get());
    textEditor3->setMultiLine (false);
    textEditor3->setReturnKeyStartsNewLine (false);
    textEditor3->setReadOnly (false);
    textEditor3->setScrollbarsShown (true);
    textEditor3->setCaretVisible (true);
    textEditor3->setPopupMenuEnabled (true);
    textEditor3->setText (String());

    textEditor3->setBounds (168, 256, 320, 80);

    toggleButton3.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton3.get());
    toggleButton3->setButtonText (CharPointer_UTF8 ("\xd0\xa8\xd0\xb8\xd1\x84\xd1\x80 \xd0\xa6\xd0\xb5\xd0\xb7\xd0\xb0\xd1\x80\xd1\x8f"));
    toggleButton3->addListener (this);

    toggleButton3->setBounds (16, 24, 150, 24);

    toggleButton4.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton4.get());
    toggleButton4->setButtonText (CharPointer_UTF8 ("\xd0\xa8\xd0\xb8\xd1\x84\xd1\x80 \xd0\x92\xd0\xb8\xd0\xb6\xd0\xb5\xd0\xbd\xd0\xb5\xd1\x80\xd0\xb0"));
    toggleButton4->addListener (this);

    toggleButton4->setBounds (400, 24, 150, 24);

    toggleButton5.reset (new ToggleButton ("new toggle button"));
    addAndMakeVisible (toggleButton5.get());
    toggleButton5->setButtonText (CharPointer_UTF8 ("\xd0\xa8\xd0\xb8\xd1\x84\xd1\x80 \xd0\xa1\xd1\x86\xd0\xb8\xd1\x82\xd0\xb0\xd0\xbb\xd0\xb0"));
    toggleButton5->addListener (this);

    toggleButton5->setBounds (200, 24, 150, 24);

    newButton2.reset (new TextButton ("New button"));
    addAndMakeVisible (newButton2.get());
    newButton2->setButtonText (CharPointer_UTF8 ("\xd0\xa0\xd0\xb0\xd1\x81\xd1\x88\xd0\xb8\xd1\x84\xd1\x80\xd0\xbe\xd0\xb2\xd0\xb0\xd1\x82\xd1\x8c"));
    newButton2->addListener (this);
    newButton2->setColour (TextButton::buttonColourId, Colour (0xff2fad2f));

    newButton2->setBounds (384, 208, 150, 24);
    setSize (600, 400);

}

SymWindow::~SymWindow()
{
    newButton = nullptr;
    textEditor = nullptr;
    label = nullptr;
    label3 = nullptr;
    textEditor2 = nullptr;
    label4 = nullptr;
    textEditor3 = nullptr;
    toggleButton3 = nullptr;
    toggleButton4 = nullptr;
    toggleButton5 = nullptr;
    newButton2 = nullptr;
}

//==============================================================================
void SymWindow::paint (Graphics& g)
{
    g.fillAll (Colours::green);
}

void SymWindow::resized()
{
}

void SymWindow::buttonClicked (Button* buttonThatWasClicked)
{

    if (buttonThatWasClicked == newButton.get())
    {
    }
    else if (buttonThatWasClicked == toggleButton3.get())
    {
    }
    else if (buttonThatWasClicked == toggleButton4.get())
    {
    }
    else if (buttonThatWasClicked == toggleButton5.get())
    {
    }
    else if (buttonThatWasClicked == newButton2.get())
    {
    }
}
