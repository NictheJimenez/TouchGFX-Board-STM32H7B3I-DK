#ifndef WIFI_SETTINGSVIEW_HPP
#define WIFI_SETTINGSVIEW_HPP

#include <gui_generated/wifi_settings_screen/Wifi_SettingsViewBase.hpp>
#include <gui/wifi_settings_screen/Wifi_SettingsPresenter.hpp>

class Wifi_SettingsView : public Wifi_SettingsViewBase
{
public:
    Wifi_SettingsView();
    virtual ~Wifi_SettingsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void KeyboardSelected(uint8_t value);
    virtual void updateScreen();

protected:
};

#endif // WIFI_SETTINGSVIEW_HPP
