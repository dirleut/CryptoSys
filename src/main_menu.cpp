#include "main_menu.h"
#include "sections/sym_win.h"
#include "sections/asym_win.h"

MainMenu::MainMenu ()
{
    _sym_section_button.reset (new TextButton ("new button"));
    addAndMakeVisible (_sym_section_button.get());
    _sym_section_button->setButtonText (CharPointer_UTF8 ("\xd0\xa1\xd0\xb8\xd0\xbc\xd0\xbc\xd0\xb5\xd1\x82\xd1\x80\xd0\xb8\xd1\x87\xd0\xbd\xd0\xb0\xd1\x8f \xd1\x81\xd0\xb5\xd0\xba\xd1\x86\xd0\xb8\xd1\x8f"));
    _sym_section_button->addListener (this);

    _asym_section_button.reset (new TextButton ("new button"));
    addAndMakeVisible (_asym_section_button.get());
    _asym_section_button->setButtonText (CharPointer_UTF8 ("\xd0\x90\xd1\x81\xd0\xb8\xd0\xbc\xd0\xbc\xd0\xb5\xd1\x82\xd1\x80\xd0\xb8\xd1\x87\xd0\xbd\xd0\xb0\xd1\x8f \xd1\x81\xd0\xb5\xd0\xba\xd1\x86\xd0\xb8\xd1\x8f"));
    _asym_section_button->addListener (this);

    _info_button.reset (new TextButton ("new button"));
    addAndMakeVisible (_info_button.get());
    _info_button->setButtonText (CharPointer_UTF8 ("\xd0\xa1\xd0\xbf\xd1\x80\xd0\xb0\xd0\xb2\xd0\xba\xd0\xb0"));
    _info_button->addListener (this);

    _lfsr_section_button.reset (new TextButton ("new button"));
    addAndMakeVisible (_lfsr_section_button.get());
    _lfsr_section_button->setButtonText (CharPointer_UTF8 ("\xd0\x9b\xd0\xb8\xd0\xbd\xd0\xb5\xd0\xb9\xd0\xbd\xd1\x8b\xd0\xb9 \xd1\x80\xd0\xb5\xd0\xb3\xd0\xb8\xd1\x81\xd1\x82\xd1\x80 \xd1\x81\xd0\xb4\xd0\xb2\xd0\xb8\xd0\xb3\xd0\xb0"));
    _lfsr_section_button->addListener (this);

    setSize (500, 300);
}

MainMenu::~MainMenu()
{
    _sym_section_button = nullptr;
    _asym_section_button = nullptr;
    _info_button = nullptr;
    _lfsr_section_button = nullptr;
}

void MainMenu::paint (Graphics& g)
{
    g.fillAll (Colour (0xff094c09));
}

void MainMenu::resized()
{
    // TODO подписать эти числа чтобы не были магическими
    _info_button->setBounds(getWidth() / 2 - 75 , getHeight() / 2 - 12 - 30, 150, 24);
    _sym_section_button->setBounds(getWidth() / 2 - 200 , getHeight() / 2 - 12, 183, 24);
    _asym_section_button->setBounds(getWidth() / 2 + 10, getHeight() / 2 - 12, 183, 24);
    _lfsr_section_button->setBounds(getWidth() / 2 - 92 , getHeight() / 2 - 12 + 30, 184, 24);
}

void MainMenu::buttonClicked (Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == _sym_section_button.get())
    {
        SymWindow* sym_section = new SymWindow();
        DialogWindow::showModalDialog(CharPointer_UTF8("Симметричная секция"), sym_section, this, Colours::grey, true);
        delete sym_section;
    }
    else if (buttonThatWasClicked == _asym_section_button.get())
    {
        AsymWindow* asym_section = new AsymWindow();
        DialogWindow::showModalDialog(CharPointer_UTF8("Acимметричная секция"), asym_section, this, Colours::grey, true);
        delete asym_section;
    }
    else if (buttonThatWasClicked == _info_button.get())
    {
    }
    else if (buttonThatWasClicked == _lfsr_section_button.get())
    {
    }
}

