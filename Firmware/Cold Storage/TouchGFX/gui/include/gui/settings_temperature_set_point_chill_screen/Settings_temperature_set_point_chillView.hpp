#ifndef SETTINGS_TEMPERATURE_SET_POINT_CHILLVIEW_HPP
#define SETTINGS_TEMPERATURE_SET_POINT_CHILLVIEW_HPP

#include <gui_generated/settings_temperature_set_point_chill_screen/Settings_temperature_set_point_chillViewBase.hpp>
#include <gui/settings_temperature_set_point_chill_screen/Settings_temperature_set_point_chillPresenter.hpp>

class Settings_temperature_set_point_chillView : public Settings_temperature_set_point_chillViewBase
{
public:
    Settings_temperature_set_point_chillView();
    virtual ~Settings_temperature_set_point_chillView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_TEMPERATURE_SET_POINT_CHILLVIEW_HPP
