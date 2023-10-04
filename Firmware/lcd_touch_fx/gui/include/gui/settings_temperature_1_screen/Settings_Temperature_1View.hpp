#ifndef SETTINGS_TEMPERATURE_1VIEW_HPP
#define SETTINGS_TEMPERATURE_1VIEW_HPP

#include <gui_generated/settings_temperature_1_screen/Settings_Temperature_1ViewBase.hpp>
#include <gui/settings_temperature_1_screen/Settings_Temperature_1Presenter.hpp>

class Settings_Temperature_1View : public Settings_Temperature_1ViewBase
{
public:
    Settings_Temperature_1View();
    virtual ~Settings_Temperature_1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_TEMPERATURE_1VIEW_HPP
