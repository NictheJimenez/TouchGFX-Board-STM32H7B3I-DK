#include <gui/screenkeyboard_screen/ScreenKeyboardView.hpp>


extern Unicode:: UnicodeChar keyboardBuffer[2][18];
extern uint8_t keyboardSelection;

ScreenKeyboardView::ScreenKeyboardView()
{
keyboard.setPosition(80, 16, 320, 240);
add(keyboard);
}

void ScreenKeyboardView::setupScreen()
{
    ScreenKeyboardViewBase::setupScreen();
}

void ScreenKeyboardView::tearDownScreen()
{
    ScreenKeyboardViewBase::tearDownScreen();
}

void ScreenKeyboardView::getBuffer() // add
{
    Unicode::UnicodeChar* buff = keyboard.getBuffer();
	Unicode::strncpy(keyboardBuffer[keyboardSelection], buff, Unicode::strlen(buff) + 1);
}
