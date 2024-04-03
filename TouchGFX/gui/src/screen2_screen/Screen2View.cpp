#include <gui/screen2_screen/Screen2View.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

Screen2View::Screen2View()
{

}

void Screen2View::setupScreen()
{
   // txt.setTypedText(TypedText(T_SINGLEUSEID2));
     txt.setXY(255, 111);
     txt.setColor(Color::getColorFrom24BitRGB(0xFF, 0xFF, 0xFF));
     txt.setWildcard(txtBuffer);
     add(txt);
    Screen2ViewBase::setupScreen();
    hour = presenter->getHour();
    minute = presenter->getMinute();
    txt.setWidth(200);
    txt.resizeHeightToCurrentText(); // Will set height by wrapping text at 200px long lines

    txt.invalidate();
       Unicode::snprintf(textAreaHourBuffer, TEXTAREAHOUR_SIZE, "%02d", hour);
       Unicode::snprintf(textAreaMinuteBuffer, TEXTAREAMINUTE_SIZE, "%02d", minute);
}
void Screen2View::updateTxt(int newValue)
{

  txt.setWidth(200);
  txt.resizeHeightToCurrentText(); // Will set height by wrapping text at 200px long lines

  txt.invalidate();
  Unicode::snprintf(txtBuffer, 10, "%d", newValue);
  txt.invalidate();

}
void Screen2View::tearDownScreen()
{
    Screen2ViewBase::tearDownScreen();
    presenter->saveHour(hour);
    presenter->saveMinute(minute);
}

void Screen2View::buttonHourUpClicked()
{
    hour = (hour + 1) % 24; // Keep new value in range 0..23
    txt.setWidth(200);
    txt.resizeHeightToCurrentText(); // Will set height by wrapping text at 200px long lines

    txt.invalidate();
    Unicode::snprintf(textAreaHourBuffer, TEXTAREAHOUR_SIZE, "%02d", hour);
    textAreaHour.invalidate();
}

void Screen2View::buttonHourDownClicked()
{
    hour = (hour + 24 - 1) % 24; // Keep new value in range 0..23
    txt.setWidth(200);
    txt.resizeHeightToCurrentText(); // Will set height by wrapping text at 200px long lines

    txt.invalidate();
    Unicode::snprintf(textAreaHourBuffer, TEXTAREAHOUR_SIZE, "%02d", hour);
    textAreaHour.invalidate();
}

void Screen2View::buttonMinuteUpClicked()
{
    minute = (minute + 1) % 60; // Keep new value in range 0..59
    txt.setWidth(200);
    txt.resizeHeightToCurrentText(); // Will set height by wrapping text at 200px long lines

    txt.invalidate();
    Unicode::snprintf(textAreaMinuteBuffer, TEXTAREAMINUTE_SIZE, "%02d", minute);
    textAreaMinute.invalidate();
}

void Screen2View::buttonMinuteDownClicked()
{
    minute = (minute + 60 - 1) % 60; // Keep new value in range 0..59
    txt.setWidth(200);
    txt.resizeHeightToCurrentText(); // Will set height by wrapping text at 200px long lines

    txt.invalidate();
    Unicode::snprintf(textAreaMinuteBuffer, TEXTAREAMINUTE_SIZE, "%02d", minute);
    textAreaMinute.invalidate();
}
