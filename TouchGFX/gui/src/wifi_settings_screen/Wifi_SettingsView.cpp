#include <gui/wifi_settings_screen/Wifi_SettingsView.hpp>
//#include "PollingRoutines.h"
//#include "RingBuff.h"
 Unicode:: UnicodeChar keyboardBuffer[2][18];
 uint8_t keyboardSelection = 0;
Wifi_SettingsView::Wifi_SettingsView()
{

}

void Wifi_SettingsView::setupScreen()
{
    Wifi_SettingsViewBase::setupScreen();
}

void Wifi_SettingsView::tearDownScreen()
{
    Wifi_SettingsViewBase::tearDownScreen();
}
void Wifi_SettingsView::KeyboardSelected(uint8_t value)
{
	keyboardSelection = value;
}
void Wifi_SettingsView::updateScreen()
{
	if(Unicode::strlen(keyboardBuffer[0]) > 0)
		{
			memset(&textAreaIDBuffer, 0, TEXTAREAID_SIZE);
			Unicode::strncpy(textAreaIDBuffer, keyboardBuffer[0], TEXTAREAID_SIZE - 1);
			textAreaIDBuffer[TEXTAREAID_SIZE-1] = '\0'; // make sure last index is null
			textAreaID.invalidate();
		}
		if(Unicode::strlen(keyboardBuffer[1]) > 0)
		{
			char temp[18] = {0};
			uint8_t n = Unicode::strlen(keyboardBuffer[1]);
			Unicode::UnicodeChar unicodeBuf[18] = {0};

			memset(&temp, '*', n);

			Unicode::fromUTF8((uint8_t*)temp, unicodeBuf, Unicode::strlen(keyboardBuffer[1]));

			memset(&textAreaID_PWBuffer, 0, TEXTAREAID_PW_SIZE);
			Unicode::strncpy(textAreaID_PWBuffer, unicodeBuf, TEXTAREAID_PW_SIZE - 1);
			textAreaID_PWBuffer[TEXTAREAID_PW_SIZE-1] = '\0'; // make sure last index is null
			textAreaID_PW.invalidate();
		}
}
