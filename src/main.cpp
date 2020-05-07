// TODO избавиться от лишнего
#include <JuceHeader.h>
#include "MainMenu.h"

class CryptoSysApplication  : public JUCEApplication
{
public:
    CryptoSysApplication() {}

    const String getApplicationName() override {
        return ProjectInfo::projectName;
    }

    const String getApplicationVersion() override {
        return ProjectInfo::versionString;
    }

    bool moreThanOneInstanceAllowed() override {
        return true;
    }

    void initialise (const String& commandLine) override {
        mainWindow.reset (new MainWindow (getApplicationName()));
    }

    void shutdown() override {
        mainWindow = nullptr;
    }

    void systemRequestedQuit() override {
        quit();
    }

    void anotherInstanceStarted (const String& commandLine) override
    {}

    class MainWindow : public DocumentWindow
    {
    public:
    MainWindow (String name)  : DocumentWindow (name, Colours::darkgrey,
                                DocumentWindow::allButtons)
    {
        setUsingNativeTitleBar (true);
        setContentOwned (new MainMenu(), true);

#if JUCE_IOS || JUCE_ANDROID
        setFullScreen (true);
#else
        setResizable (true, true);
        centreWithSize (getWidth(), getHeight());
#endif
        setVisible (true);
    }

    void closeButtonPressed() override {
            // This is called when the user tries to close this window. Here, we'll just
            // ask the app to quit when this happens, but you can change this to do
            // whatever you need.
            JUCEApplication::getInstance()->systemRequestedQuit();
        }

        /* Note: Be careful if you override any DocumentWindow methods - the base
           class uses a lot of them, so by overriding you might break its functionality.
           It's best to do all your work in your content component instead, but if
           you really have to override any DocumentWindow methods, make sure your
           subclass also calls the superclass's method.
        */

    private:
        JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MainWindow)
    };

private:
    std::unique_ptr<MainWindow> mainWindow;
};

START_JUCE_APPLICATION (CryptoSysApplication)
