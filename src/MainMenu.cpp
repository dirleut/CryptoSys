#include "MainMenu.h"
#include "sections/SymWindow.h"
#include "sections/AsymWindow.h"
// TODO разгрузить конструктор
MainMenu::MainMenu ()
{
    addAndMakeVisible(_info_button);
    _info_button.setButtonText (CharPointer_UTF8 ("Справка"));
    _info_button.addListener (this);

    addAndMakeVisible (_sym_section_button);
    _sym_section_button.setButtonText (CharPointer_UTF8 ("Симметричная секция"));
    _sym_section_button.addListener (this);

    addAndMakeVisible (_asym_section_button);
    _asym_section_button.setButtonText (CharPointer_UTF8 ("Асимметричная секция"));
    _asym_section_button.addListener (this);

    addAndMakeVisible (_lfsr_section_button);
    _lfsr_section_button.setButtonText (CharPointer_UTF8 ("Линейный регистр сдвига"));
    _lfsr_section_button.addListener (this);

    setSize(_size_x, _size_y);
}

MainMenu::~MainMenu()
{
    _sym_section_button.removeListener(this);
    _asym_section_button.removeListener(this);
    _info_button.removeListener(this);
    _lfsr_section_button.removeListener(this);
}

void MainMenu::paint (Graphics& g)
{
    g.fillAll (Colour (0xff999900));
}

void MainMenu::resized()
{
    // TODO подписать эти числа чтобы не были магическими
    _info_button.setBounds(getWidth() / 2 - 75 , getHeight() / 2 - 12 - 30, 150, 24);
    _sym_section_button.setBounds(getWidth() / 2 - 200 , getHeight() / 2 - 12, 184, 24);
    _asym_section_button.setBounds(getWidth() / 2 + 10, getHeight() / 2 - 12, 184, 24);
    _lfsr_section_button.setBounds(getWidth() / 2 - 92 , getHeight() / 2 - 12 + 30, 184, 24);
}

void MainMenu::buttonClicked (Button* clicked)
{
    if (clicked == &_sym_section_button)
    {
        auto sym_section = std::make_unique<SymWindow>();
        DialogWindow::showModalDialog(CharPointer_UTF8("Симметричная секция"), sym_section.get(), this, Colours::grey, true, true, true);
    }
    else if (clicked == &_asym_section_button)
    {
        auto asym_section = std::make_unique<AsymWindow>();
        DialogWindow::showModalDialog(CharPointer_UTF8("Acимметричная секция"), asym_section.get(), this, Colours::grey, true, true, true);
    }
    else if (clicked == &_info_button)
    {
        // Справка
    }
    else if (clicked == &_lfsr_section_button)
    {
        // Линейный регистр сдвига
    }
}

