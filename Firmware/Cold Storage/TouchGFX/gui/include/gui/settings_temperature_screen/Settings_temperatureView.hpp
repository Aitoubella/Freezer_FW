#ifndef SETTINGS_TEMPERATUREVIEW_HPP
#define SETTINGS_TEMPERATUREVIEW_HPP

#include <gui_generated/settings_temperature_screen/Settings_temperatureViewBase.hpp>
#include <gui/settings_temperature_screen/Settings_temperaturePresenter.hpp>

class Settings_temperatureView : public Settings_temperatureViewBase
{
public:
    Settings_temperatureView();
    virtual ~Settings_temperatureView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_TEMPERATUREVIEW_HPP
