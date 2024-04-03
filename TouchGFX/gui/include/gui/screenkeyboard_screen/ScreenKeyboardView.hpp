#ifndef SCREENKEYBOARDVIEW_HPP
#define SCREENKEYBOARDVIEW_HPP

#include <gui_generated/screenkeyboard_screen/ScreenKeyboardViewBase.hpp>
#include <gui/screenkeyboard_screen/ScreenKeyboardPresenter.hpp>
#include <gui/common/CustomKeyboard.hpp>
class ScreenKeyboardView : public ScreenKeyboardViewBase
{
public:
    ScreenKeyboardView();
    virtual ~ScreenKeyboardView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void getBuffer();
protected:
   CustomKeyboard keyboard;
};

#endif // SCREENKEYBOARDVIEW_HPP
