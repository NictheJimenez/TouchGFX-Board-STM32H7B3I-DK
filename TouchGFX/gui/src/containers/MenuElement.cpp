#include <gui/containers/MenuElement.hpp>
#include <touchgfx\Bitmap.hpp>
MenuElement::MenuElement()
{

}

void MenuElement::initialize()
{
    MenuElementBase::initialize();
}




//void MenuElement::updateImage(Bitmap ico)
//{
////    icon.setBitmap(ico);
 //   icon.invalidate();
//}
void MenuElement::updateImage(Bitmap icon)
{
    image.setBitmap(icon);
    image.invalidate();
}
