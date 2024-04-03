#include <gui/screen4_screen/Screen4View.hpp>
#include "BitmapDatabase.hpp"
#include "texts/TextKeysAndLanguages.hpp"


Screen4View::Screen4View() :
scrollListItemSelectedCallback(this, &Screen4View::scrollListItemSelectedHandler),
scrollWheelAnimateToCallback(this, &Screen4View::scrollWheelAnimateToHandler)
{
	  // Support of larger displays for this example
	    // is handled by showing a black box in the
	    // unused part of the display.
	    if (HAL::DISPLAY_WIDTH > background.getWidth() ||
	            HAL::DISPLAY_HEIGHT > background.getHeight())
	    {
	        boxBackground.setVisible(false);
	    }
}

void Screen4View::setupScreen()
{
    Screen4ViewBase::setupScreen();
    // The item selected callbacks are registerd with scroll wheel and list
     scrollList.setItemSelectedCallback(scrollListItemSelectedCallback);
      scrollWheel.setAnimateToCallback(scrollWheelAnimateToCallback);

      // The scroll wheel and list is updated to show the selected icons and numbers.
      for (int i = 0; i < scrollWheelListItems.getNumberOfDrawables(); i++)
      {
          scrollList.itemChanged(i);
      }
      scrollWheel.animateToItem(15);
}

void Screen4View::tearDownScreen()
{
    Screen4ViewBase::tearDownScreen();
}


void Screen4View::scrollWheelAnimateToHandler(int16_t itemSelected)
{
    selectedVal.invalidate();
    Unicode::snprintf(selectedValBuffer, SELECTEDVAL_SIZE, "%d", itemSelected);
}
//void Screen4View::scrollWheelUpdateItem(MenuElement& item, int16_t itemIndex);
/*void Screen4View::scrollListUpdateItem(MenuElement& item, int16_t itemIndex)
{
    switch (itemIndex)
    {
    case 0:
        item.updateImage(Bitmap(BITMAP_ICON00_ID));
        break;
    case 1:
        item.updateImage(Bitmap(BITMAP_ICON01_ID));
        break;
    case 2:
        item.updateImage(Bitmap(BITMAP_ICON02_ID));
        break;
    case 3:
        item.updateImage(Bitmap(BITMAP_ICON03_ID));
        break;
    case 4:
        item.updateImage(Bitmap(BITMAP_ICON04_ID));
        break;
    case 5:
        item.updateImage(Bitmap(BITMAP_ICON05_ID));
        break;
    case 6:
        item.updateImage(Bitmap(BITMAP_ICON06_ID));
        break;

    }
}*/
void Screen4View::scrollListUpdateItem(MenuElement& item, int16_t itemIndex)
{
    switch (itemIndex)
    {

    case 0:
        item.updateImage(Bitmap(BITMAP_ALERT_ID));
        break;
    case 1:
        item.updateImage(Bitmap(BITMAP_CALENDAR_ID));
        break;
    case 2:
        item.updateImage(Bitmap(BITMAP_DOCUMENT_ID));
        break;
    case 3:
        item.updateImage(Bitmap(BITMAP_EMAIL_ID));
        break;
    case 4:
        item.updateImage(Bitmap(BITMAP_FOLDER_ID));
        break;
    case 5:
        item.updateImage(Bitmap(BITMAP_HOME_ID));
        break;
    case 6:
        item.updateImage(Bitmap(BITMAP_INBOX_ID));
        break;
    case 7:
        item.updateImage(Bitmap(BITMAP_MAP_ID));
        break;
    case 8:
        item.updateImage(Bitmap(BITMAP_MOVIE_ID));
        break;
    case 9:
        item.updateImage(Bitmap(BITMAP_NEWS_ID));
        break;
    case 10:
        item.updateImage(Bitmap(BITMAP_SOUND_ID));
        break;
    case 11:
        item.updateImage(Bitmap(BITMAP_TOOLS_ID));
        break;
    case 12:
        item.updateImage(Bitmap(BITMAP_TRASH_ID));
        break;
    case 13:
        item.updateImage(Bitmap(BITMAP_USER_ID));
        break;
    }
}
/*
void Screen4View::scrollListItemSelectedHandler(int16_t itemSelected)
{
    selectedIcon.invalidate();

    switch (itemSelected)
    {
    case 0:
        selectedIcon.setBitmap(Bitmap(BITMAP_ICON00_ID));
        break;
    case 1:
        selectedIcon.setBitmap(Bitmap(BITMAP_ICON01_ID));
        break;
    case 2:
        selectedIcon.setBitmap(Bitmap(BITMAP_ICON02_ID));
        break;
    case 3:
        selectedIcon.setBitmap(Bitmap(BITMAP_ICON03_ID));
        break;
    case 4:
        selectedIcon.setBitmap(Bitmap(BITMAP_ICON04_ID));
        break;
    case 5:
        selectedIcon.setBitmap(Bitmap(BITMAP_ICON05_ID));
        break;
    case 6:
        selectedIcon.setBitmap(Bitmap(BITMAP_ICON06_ID));
        break;

    }
    selectedIcon.invalidate();
}
*/
void Screen4View::scrollListItemSelectedHandler(int16_t itemSelected)
{
    selectedIcon.invalidate();

    switch (itemSelected)
    {
    case 0:
        selectedIcon.setBitmap(Bitmap(BITMAP_ALERT_ID));
        break;
    case 1:
        selectedIcon.setBitmap(Bitmap(BITMAP_CALENDAR_ID));
        break;
    case 2:
        selectedIcon.setBitmap(Bitmap(BITMAP_DOCUMENT_ID));
        break;
    case 3:
        selectedIcon.setBitmap(Bitmap(BITMAP_EMAIL_ID));
        break;
    case 4:
        selectedIcon.setBitmap(Bitmap(BITMAP_FOLDER_ID));
        break;
    case 5:
        selectedIcon.setBitmap(Bitmap(BITMAP_HOME_ID));
        break;
    case 6:
        selectedIcon.setBitmap(Bitmap(BITMAP_INBOX_ID));
        break;
    case 7:
        selectedIcon.setBitmap(Bitmap(BITMAP_MAP_ID));
        break;
    case 8:
        selectedIcon.setBitmap(Bitmap(BITMAP_MOVIE_ID));
        break;
    case 9:
        selectedIcon.setBitmap(Bitmap(BITMAP_NEWS_ID));
        break;
    case 10:
        selectedIcon.setBitmap(Bitmap(BITMAP_SOUND_ID));
        break;
    case 11:
        selectedIcon.setBitmap(Bitmap(BITMAP_TOOLS_ID));
        break;
    case 12:
        selectedIcon.setBitmap(Bitmap(BITMAP_TRASH_ID));
        break;
    case 13:
        selectedIcon.setBitmap(Bitmap(BITMAP_USER_ID));
        break;
    }
    selectedIcon.invalidate();
}

void Screen4View::scrollListSelected()
{
    //selectText.setTypedText(TypedText(T_HEADLINE_SCROLLLIST));

    scrollList.setVisible(true);
   scrollWheel.setVisible(false);
    selectedIcon.setVisible(true);
    selectedVal.setVisible(false);


   // selectText.invalidate();
    scrollList.invalidate();
   scrollWheel.invalidate();
    selectedIcon.invalidate();
    selectedVal.invalidate();

}

void Screen4View::scrollWheelSelected()
{
    // selectText.setTypedText(TypedText(T_HEADLINE_SCROLLWHEEL));
	    scrollList.setVisible(false);
	    scrollWheel.setVisible(true);
	    selectedIcon.setVisible(false);
	    selectedVal.setVisible(true);
	  //  scrollWheelFrame.setVisible(true);

	  //  selectText.invalidate();
	    scrollList.invalidate();
	    scrollWheel.invalidate();
	    selectedIcon.invalidate();
	    selectedVal.invalidate();
	//    scrollWheelFrame.invalidate();

}
