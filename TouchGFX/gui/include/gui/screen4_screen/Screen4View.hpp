#ifndef SCREEN4VIEW_HPP
#define SCREEN4VIEW_HPP

#include <gui_generated/screen4_screen/Screen4ViewBase.hpp>
#include <gui/screen4_screen/Screen4Presenter.hpp>

class Screen4View : public Screen4ViewBase
{
public:
    Screen4View();
    virtual ~Screen4View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void scrollListUpdateItem(MenuElement& item, int16_t itemIndex);
  //  virtual void scrollWheelUpdateItem(MenuElement& item, int16_t itemIndex)
  //  {
   //       item.setNumber(itemIndex);

   //   }
//virtual void scrollWheelUpdateCenterItem(textCenterContainer& item, int16_t itemIndex);
//virtual void scrollWheelSelected();

   virtual void scrollListSelected();
  virtual void scrollWheelSelected();
protected:
   // Callback<Screen4View, int16_t> scrollWheelAnimateToCallback;
   //  void scrollWheelAnimateToHandler(int16_t icon);
    // Callback which is executed when a item in the scroll list is selected.
    // The parameter itemSelected is the selected item.
    Callback<Screen4View, int16_t> scrollListItemSelectedCallback;
    void scrollListItemSelectedHandler(int16_t itemSelected);

    // Callback which is executed when a item in the scroll whell is selected to as selected style.
    // The parameter itemSelected is the selected item.
    Callback<Screen4View, int16_t> scrollWheelAnimateToCallback;
   void scrollWheelAnimateToHandler(int16_t itemSelected);

};

#endif // SCREEN4VIEW_HPP


