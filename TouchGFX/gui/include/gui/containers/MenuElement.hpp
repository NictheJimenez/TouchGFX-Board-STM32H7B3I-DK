#ifndef MENUELEMENT_HPP
#define MENUELEMENT_HPP

#include <gui_generated/containers/MenuElementBase.hpp>
#include <BitmapDatabase.hpp>
#include <math.h>


class MenuElement : public MenuElementBase
{
public:
    MenuElement();
    virtual ~MenuElement() {}

    void updateImage(Bitmap icon);

    virtual void initialize();
    //Adjusts the position of the text and the icon, based in the calculated offset(x)
 //   virtual void setIconBitmaps	(	const Bitmap &	newIconReleased ,
 //  const Bitmap &	newIconPressed){}

/*  void setNumber(int no)
    {
        Unicode::itoa(no, textBuffer, TEXT_SIZE, 10);
        image.invalidate();

       switch (no % 7)
       {
        case 0:
        	image.setBitmap(Bitmap(BITMAP_ICON00_ID));
            break;
        case 1:
        	image.setBitmap(Bitmap(BITMAP_ICON01_ID));
            break;
        case 2:
        	image.setBitmap(Bitmap(BITMAP_ICON02_ID));
            break;
        case 3:
        	image.setBitmap(Bitmap(BITMAP_ICON03_ID));
            break;
        case 4:
        	image.setBitmap(Bitmap(BITMAP_ICON04_ID));
            break;
        case 5:
        	image.setBitmap(Bitmap(BITMAP_ICON05_ID));
            break;
        case 6:
        	image.setBitmap(Bitmap(BITMAP_ICON06_ID));
            break;
        }
       image.invalidate();
  }*/
    void offset(int16_t x)
      {

    	  image.moveTo(40 + x, image.getY());
          text.moveTo(90 + x, text.getY());
      }

      //The new declaration and implementation of the setY() function
      virtual void setY(int16_t y)
      {
          //set Y as normal
          MenuElementBase::setY(y);

          const int circleRadius = 200;

          //center around middle of background
          y = y + getHeight() / 2 - 262 /2;

          //calculate x
          float x_f = circleRadius - sqrtf((float)((circleRadius * circleRadius) - (y * y)));
          int16_t x = (int16_t)(x_f + 0.5f);

          offset(x);
      }
protected:
};

#endif // MENUELEMENT_HPP
