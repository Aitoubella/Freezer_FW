#ifndef SETTINGS_DATE_TIME_MINUTEVIEW_HPP
#define SETTINGS_DATE_TIME_MINUTEVIEW_HPP

#include <gui_generated/settings_date_time_minute_screen/Settings_date_time_minuteViewBase.hpp>
#include <gui/settings_date_time_minute_screen/Settings_date_time_minutePresenter.hpp>

class Settings_date_time_minuteView : public Settings_date_time_minuteViewBase
{
public:
    Settings_date_time_minuteView();
    virtual ~Settings_date_time_minuteView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_DATE_TIME_MINUTEVIEW_HPP
