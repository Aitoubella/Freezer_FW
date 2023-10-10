#ifndef SETTINGS_TEMPERATURE_SET_POINT_CHIL_BACKVIEW_HPP
#define SETTINGS_TEMPERATURE_SET_POINT_CHIL_BACKVIEW_HPP

#include <gui_generated/settings_temperature_set_point_chil_back_screen/Settings_temperature_set_point_chil_backViewBase.hpp>
#include <gui/settings_temperature_set_point_chil_back_screen/Settings_temperature_set_point_chil_backPresenter.hpp>

class Settings_temperature_set_point_chil_backView : public Settings_temperature_set_point_chil_backViewBase
{
public:
    Settings_temperature_set_point_chil_backView();
    virtual ~Settings_temperature_set_point_chil_backView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_TEMPERATURE_SET_POINT_CHIL_BACKVIEW_HPP
