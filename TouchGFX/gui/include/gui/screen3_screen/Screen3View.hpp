#ifndef SCREEN3VIEW_HPP
#define SCREEN3VIEW_HPP

#include <gui_generated/screen3_screen/Screen3ViewBase.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>
#include <touchgfx/widgets/TextAreaWithWildcard.hpp>

class Screen3View : public Screen3ViewBase
{
	TextAreaWithOneWildcard txt;
	Unicode::UnicodeChar txtBuffer[10];
public:
    Screen3View();
    virtual ~Screen3View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();

    virtual void handleTickEvent();

    virtual void updateTxt(int);
    int counter = 0;
protected:
    int16_t hour;
    int16_t minute;
    int16_t tickCount;
    int16_t addStart;
    int16_t addEnd;


};

#endif // SCREEN3VIEW_HPP
