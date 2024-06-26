#ifndef SCREEN2VIEW_HPP
#define SCREEN2VIEW_HPP

#include <gui_generated/screen2_screen/Screen2ViewBase.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class Screen2View : public Screen2ViewBase
{
	 TextAreaWithOneWildcard txt;
	 Unicode::UnicodeChar txtBuffer[10];
public:
    Screen2View();
    virtual ~Screen2View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void buttonHourUpClicked();
    virtual void buttonHourDownClicked();
    virtual void buttonMinuteUpClicked();
    virtual void buttonMinuteDownClicked();

    virtual void buttonSaveHourClicked()
        {
            presenter->saveHour(hour);
        }

        virtual void buttonSaveMinuteClicked()
        {
            presenter->saveMinute(minute);
        }
        virtual void updateTxt(int);
        int counter = 0;
protected:
    int16_t hour;
    int16_t minute;
};

#endif // SCREEN2VIEW_HPP
