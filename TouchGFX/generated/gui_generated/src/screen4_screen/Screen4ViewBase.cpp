/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen4_screen/Screen4ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include "BitmapDatabase.hpp"
#include <texts/TextKeysAndLanguages.hpp>

Screen4ViewBase::Screen4ViewBase() :
    buttonCallback(this, &Screen4ViewBase::buttonCallbackHandler),
    updateItemCallback(this, &Screen4ViewBase::updateItemCallbackHandler)
{

    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    boxBackground.setPosition(0, 0, 480, 272);
    boxBackground.setColor(touchgfx::Color::getColorFrom24BitRGB(13, 12, 12));

    background.setXY(0, 0);
    background.setBitmap(touchgfx::Bitmap(BITMAP_BACKGROUND_SCREEN2_ID));

    scrollWheel.setPosition(35, 8, 390, 256);
    scrollWheel.setHorizontal(false);
    scrollWheel.setCircular(false);
    scrollWheel.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollWheel.setSwipeAcceleration(10);
    scrollWheel.setDragAcceleration(10);
    scrollWheel.setNumberOfItems(61);
    scrollWheel.setSelectedItemOffset(153);
    scrollWheel.setDrawableSize(64, 0);
    scrollWheel.setDrawables(scrollWheelListItems, updateItemCallback);
    scrollWheel.animateToItem(0, 0);
    scrollWheel.setVisible(false);

    overlay.setXY(-160, -111);
    overlay.setBitmap(touchgfx::Bitmap(BITMAP_OVERLAY_ID));

    selectedIcon.setXY(425, 13);
    selectedIcon.setBitmap(touchgfx::Bitmap(BITMAP_ICON05_ID));

    selectedVal.setPosition(431, 1, 48, 49);
    selectedVal.setVisible(false);
    selectedVal.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));
    selectedVal.setLinespacing(0);
    Unicode::snprintf(selectedValBuffer, SELECTEDVAL_SIZE, "%s", touchgfx::TypedText(T_SINGLEUSEID14).getText());
    selectedVal.setWildcard(selectedValBuffer);
    selectedVal.setTypedText(touchgfx::TypedText(T_SINGLEUSEID13));

    scrollList.setPosition(35, 0, 390, 272);
    scrollList.setHorizontal(false);
    scrollList.setCircular(false);
    scrollList.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollList.setSwipeAcceleration(10);
    scrollList.setDragAcceleration(10);
    scrollList.setNumberOfItems(10);
    scrollList.setPadding(0, 0);
    scrollList.setSnapping(false);
    scrollList.setDrawableSize(64, 0);
    scrollList.setDrawables(scrollListListItems, updateItemCallback);

    buttonwithalpha0_1.setXY(411, 13);
    buttonwithalpha0_1.setBitmaps(touchgfx::Bitmap(BITMAP_BTN_ROUNDNEW_ID), touchgfx::Bitmap(BITMAP_BTN_ROUND_PRESSEDNEW_ID));
    buttonwithalpha0_1.setAction(buttonCallback);
    buttonwithalpha0_1.setAlpha(0);

    add(__background);
    add(boxBackground);
    add(background);
    add(scrollWheel);
    add(overlay);
    add(selectedIcon);
    add(selectedVal);
    add(scrollList);
    add(buttonwithalpha0_1);
}

void Screen4ViewBase::setupScreen()
{
    scrollWheel.initialize();
    for (int i = 0; i < scrollWheelListItems.getNumberOfDrawables(); i++)
    {
        scrollWheelListItems[i].initialize();
    }
    scrollList.initialize();
    for (int i = 0; i < scrollListListItems.getNumberOfDrawables(); i++)
    {
        scrollListListItems[i].initialize();
    }
}

void Screen4ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonwithalpha0_1)
    {
        //Interaction1
        //When buttonwithalpha0_1 clicked change screen to Wifi
        //Go to Wifi with screen transition towards East
        application().gotoWifiScreenCoverTransitionEast();
    }
}

void Screen4ViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &scrollListListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        MenuElement* cc = (MenuElement*)d;
        scrollListUpdateItem(*cc, itemIndex);
    }
    else if (items == &scrollWheelListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        MenuElement* cc = (MenuElement*)d;
        scrollWheelUpdateItem(*cc, itemIndex);
    }
}