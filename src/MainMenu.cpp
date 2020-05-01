#include "MainMenu.h"
#include "sections/SymWindow.h"
#include "sections/AsymWindow.h"
// TODO разгрузить конструктор
MainMenu::MainMenu ()
{
    _info_button.reset (new TextButton ("new button"));
    addAndMakeVisible (_info_button.get());
    _info_button->setButtonText (CharPointer_UTF8 ("Справка"));
    _info_button->addListener (this);

    _sym_section_button.reset (new TextButton ("new button"));
    addAndMakeVisible (_sym_section_button.get());
    _sym_section_button->setButtonText (CharPointer_UTF8 ("Симметричная секция"));
    _sym_section_button->addListener (this);

    _asym_section_button.reset (new TextButton ("new button"));
    addAndMakeVisible (_asym_section_button.get());
    _asym_section_button->setButtonText (CharPointer_UTF8 ("Асимметричная секция"));
    _asym_section_button->addListener (this);

    _lfsr_section_button.reset (new TextButton ("new button"));
    addAndMakeVisible (_lfsr_section_button.get());
    _lfsr_section_button->setButtonText (CharPointer_UTF8 ("Линейный регистр сдвига"));
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
    _sym_section_button->setBounds(getWidth() / 2 - 200 , getHeight() / 2 - 12, 184, 24);
    _asym_section_button->setBounds(getWidth() / 2 + 10, getHeight() / 2 - 12, 184, 24);
    _lfsr_section_button->setBounds(getWidth() / 2 - 92 , getHeight() / 2 - 12 + 30, 184, 24);
}

void MainMenu::buttonClicked (Button* buttonThatWasClicked)
{
    if (buttonThatWasClicked == _sym_section_button.get())
    {
        SymWindow* sym_section = new SymWindow();
        DialogWindow::showModalDialog(CharPointer_UTF8("Симметричная секция"), sym_section, this, Colours::grey, true, true, true);
        delete sym_section;
    }
    else if (buttonThatWasClicked == _asym_section_button.get())
    {
        AsymWindow* asym_section = new AsymWindow();
        DialogWindow::showModalDialog(CharPointer_UTF8("Acимметричная секция"), asym_section, this, Colours::grey, true, true, true);
        delete asym_section;
    }
    else if (buttonThatWasClicked == _info_button.get())
    {
    }
    else if (buttonThatWasClicked == _lfsr_section_button.get())
    {
    }
}

