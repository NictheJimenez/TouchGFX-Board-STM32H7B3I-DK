/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screenkeyboard_screen/ScreenKeyboardViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

ScreenKeyboardViewBase::ScreenKeyboardViewBase() :
    buttonCallback(this, &ScreenKeyboardViewBase::buttonCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    box1.setXY(0, 0);
    box1.setBitmap(touchgfx::Bitmap(BITMAP_BACKGROUND_SCREEN2_ID));

    ButtonSettings_Cancel.setXY(0, 232);
    ButtonSettings_Cancel.setBitmaps(touchgfx::Bitmap(BITMAP_BTN_ROUNDNEW_ID), touchgfx::Bitmap(BITMAP_BTN_ROUND_PRESSEDNEW_ID));
    ButtonSettings_Cancel.setLabelText(touchgfx::TypedText(T_SINGLEUSEID24));
    ButtonSettings_Cancel.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    ButtonSettings_Cancel.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    ButtonSettings_Cancel.setAction(buttonCallback);

    ButtonSettings_Ok.setXY(415, 232);
    ButtonSettings_Ok.setBitmaps(touchgfx::Bitmap(BITMAP_BTN_ROUNDNEW_ID), touchgfx::Bitmap(BITMAP_BTN_ROUND_PRESSEDNEW_ID));
    ButtonSettings_Ok.setLabelText(touchgfx::TypedText(T_SINGLEUSEID25));
    ButtonSettings_Ok.setLabelColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    ButtonSettings_Ok.setLabelColorPressed(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    ButtonSettings_Ok.setAction(buttonCallback);

    add(__background);
    add(box1);
    add(ButtonSettings_Cancel);
    add(ButtonSettings_Ok);
}

void ScreenKeyboardViewBase::setupScreen()
{

}

void ScreenKeyboardViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &ButtonSettings_Cancel)
    {
        //InteractionButtonCancel
        //When ButtonSettings_Cancel clicked change screen to Wifi_Settings
        //Go to Wifi_Settings with no screen transition
        application().gotoWifi_SettingsScreenNoTransition();
    }
    else if (&src == &ButtonSettings_Ok)
    {
        //InteractionButtonOk
        //When ButtonSettings_Ok clicked call virtual function
        //Call getBuffer
        getBuffer();

        //InteractionChangeToScreenSettings
        //When InteractionButtonOk completed change screen to Wifi_Settings
        //Go to Wifi_Settings with no screen transition
        application().gotoWifi_SettingsScreenNoTransition();
    }
}
