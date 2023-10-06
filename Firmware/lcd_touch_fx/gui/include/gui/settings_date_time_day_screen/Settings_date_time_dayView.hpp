#ifndef SETTINGS_DATE_TIME_DAYVIEW_HPP
#define SETTINGS_DATE_TIME_DAYVIEW_HPP

#include <gui_generated/settings_date_time_day_screen/Settings_date_time_dayViewBase.hpp>
#include <gui/settings_date_time_day_screen/Settings_date_time_dayPresenter.hpp>

class Settings_date_time_dayView : public Settings_date_time_dayViewBase
{
public:
    Settings_date_time_dayView();
    virtual ~Settings_date_time_dayView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_DATE_TIME_DAYVIEW_HPP
