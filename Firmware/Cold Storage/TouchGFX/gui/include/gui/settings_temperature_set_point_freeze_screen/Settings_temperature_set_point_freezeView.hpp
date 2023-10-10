#ifndef SETTINGS_TEMPERATURE_SET_POINT_FREEZEVIEW_HPP
#define SETTINGS_TEMPERATURE_SET_POINT_FREEZEVIEW_HPP

#include <gui_generated/settings_temperature_set_point_freeze_screen/Settings_temperature_set_point_freezeViewBase.hpp>
#include <gui/settings_temperature_set_point_freeze_screen/Settings_temperature_set_point_freezePresenter.hpp>

class Settings_temperature_set_point_freezeView : public Settings_temperature_set_point_freezeViewBase
{
public:
    Settings_temperature_set_point_freezeView();
    virtual ~Settings_temperature_set_point_freezeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_TEMPERATURE_SET_POINT_FREEZEVIEW_HPP
