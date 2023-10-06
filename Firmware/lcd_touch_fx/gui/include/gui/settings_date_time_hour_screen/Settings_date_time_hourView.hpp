#ifndef SETTINGS_DATE_TIME_HOURVIEW_HPP
#define SETTINGS_DATE_TIME_HOURVIEW_HPP

#include <gui_generated/settings_date_time_hour_screen/Settings_date_time_hourViewBase.hpp>
#include <gui/settings_date_time_hour_screen/Settings_date_time_hourPresenter.hpp>

class Settings_date_time_hourView : public Settings_date_time_hourViewBase
{
public:
    Settings_date_time_hourView();
    virtual ~Settings_date_time_hourView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_DATE_TIME_HOURVIEW_HPP
