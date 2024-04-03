#include <gui/main_screen/MainView.hpp>

MainView::MainView()
{

}

void MainView::setupScreen()
{
    MainViewBase::setupScreen();
}

void MainView::tearDownScreen()
{
    MainViewBase::tearDownScreen();
}

void MainView::collapseAllOtherSlideMenu(const touchgfx::SlideMenu& value)
{
    if (&value != &slideMenuLeft)
    {
        slideMenuLeft.animateToState(SlideMenu::COLLAPSED);
    }
    if (&value != &slideMenuRight)
    {
        slideMenuRight.animateToState(SlideMenu::COLLAPSED);
    }
    if (&value != &slideMenuTop)
    {
        slideMenuTop.animateToState(SlideMenu::COLLAPSED);
    }
    if (&value != &slideMenuBottom)
    {
        slideMenuBottom.animateToState(SlideMenu::COLLAPSED);
    }
}
