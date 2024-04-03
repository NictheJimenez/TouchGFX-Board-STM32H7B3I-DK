#ifndef WIFI_SETTINGSPRESENTER_HPP
#define WIFI_SETTINGSPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Wifi_SettingsView;

class Wifi_SettingsPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    Wifi_SettingsPresenter(Wifi_SettingsView& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Wifi_SettingsPresenter() {};

private:
    Wifi_SettingsPresenter();

    Wifi_SettingsView& view;
};

#endif // WIFI_SETTINGSPRESENTER_HPP
