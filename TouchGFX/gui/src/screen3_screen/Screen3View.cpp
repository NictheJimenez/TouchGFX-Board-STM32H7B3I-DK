#include <gui/screen3_screen/Screen3View.hpp>

#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Color.hpp>

Screen3View::Screen3View()
{

}

void Screen3View::setupScreen()
{

    // txt.setTypedText(TypedText(T_SINGLEUSEID2));
     txt.setXY(255, 111);
     txt.setColor(Color::getColorFrom24BitRGB(0xFF, 0xFF, 0xFF));
     txt.setWildcard(txtBuffer);
     add(txt);


    Screen3ViewBase::setupScreen();
    hour = presenter->getHour();
    minute = presenter->getMinute();

    txt.setWidth(200);
    txt.resizeHeightToCurrentText(); // Will set height by wrapping text at 200px long lines

    txt.invalidate();

    Unicode::snprintf(textClockBuffer1, TEXTCLOCKBUFFER1_SIZE, "%02d", hour);
    Unicode::snprintf(textClockBuffer2, TEXTCLOCKBUFFER2_SIZE, "%02d", minute);
}
void Screen3View::updateTxt(int newValue)
{

  txt.setWidth(200);
  txt.resizeHeightToCurrentText(); // Will set height by wrapping text at 200px long lines

  txt.invalidate();
  Unicode::snprintf(txtBuffer, 10, "%d", newValue);
  txt.invalidate();
}

void Screen3View::tearDownScreen()
{
    Screen3ViewBase::tearDownScreen();
}

void Screen3View::handleTickEvent()
{
    if (tickCount == 60)
    {
        minute++;
        hour = (hour + (minute / 60)) % 24;
        minute %= 60;

        txt.setWidth(200);
        txt.resizeHeightToCurrentText(); // Will set height by wrapping text at 200px long lines

        txt.invalidate();
        Unicode::snprintf(textClockBuffer1, TEXTCLOCKBUFFER1_SIZE, "%02d", hour);
        Unicode::snprintf(textClockBuffer2, TEXTCLOCKBUFFER2_SIZE, "%02d", minute);

        textClock.invalidate();

        tickCount = 0;
    }

    if (!textClock.isMoveAnimationRunning())
    {
        tickCount++;
        if (circle.getArcStart() + 340 == circle.getArcEnd())
        {
            addStart = 2;
            addEnd = 1;
        }
        else if (circle.getArcStart() + 20 == circle.getArcEnd())
        {
            addStart = 1;
            addEnd = 2;
        }
        circle.invalidate();
        circle.setArc(circle.getArcStart() + addStart, circle.getArcEnd() + addEnd);
        circle.invalidate();
    }
}
