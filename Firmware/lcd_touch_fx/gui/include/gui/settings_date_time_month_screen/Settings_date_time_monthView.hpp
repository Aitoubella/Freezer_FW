#ifndef SETTINGS_DATE_TIME_MONTHVIEW_HPP
#define SETTINGS_DATE_TIME_MONTHVIEW_HPP

#include <gui_generated/settings_date_time_month_screen/Settings_date_time_monthViewBase.hpp>
#include <gui/settings_date_time_month_screen/Settings_date_time_monthPresenter.hpp>

class Settings_date_time_monthView : public Settings_date_time_monthViewBase
{
public:
    Settings_date_time_monthView();
    virtual ~Settings_date_time_monthView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_DATE_TIME_MONTHVIEW_HPP
