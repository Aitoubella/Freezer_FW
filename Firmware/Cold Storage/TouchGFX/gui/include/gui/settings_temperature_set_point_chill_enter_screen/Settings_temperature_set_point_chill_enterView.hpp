#ifndef SETTINGS_TEMPERATURE_SET_POINT_CHILL_ENTERVIEW_HPP
#define SETTINGS_TEMPERATURE_SET_POINT_CHILL_ENTERVIEW_HPP

#include <gui_generated/settings_temperature_set_point_chill_enter_screen/Settings_temperature_set_point_chill_enterViewBase.hpp>
#include <gui/settings_temperature_set_point_chill_enter_screen/Settings_temperature_set_point_chill_enterPresenter.hpp>

class Settings_temperature_set_point_chill_enterView : public Settings_temperature_set_point_chill_enterViewBase
{
public:
    Settings_temperature_set_point_chill_enterView();
    virtual ~Settings_temperature_set_point_chill_enterView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_TEMPERATURE_SET_POINT_CHILL_ENTERVIEW_HPP
