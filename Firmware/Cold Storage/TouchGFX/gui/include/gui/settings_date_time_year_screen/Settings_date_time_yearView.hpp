#ifndef SETTINGS_DATE_TIME_YEARVIEW_HPP
#define SETTINGS_DATE_TIME_YEARVIEW_HPP

#include <gui_generated/settings_date_time_year_screen/Settings_date_time_yearViewBase.hpp>
#include <gui/settings_date_time_year_screen/Settings_date_time_yearPresenter.hpp>

class Settings_date_time_yearView : public Settings_date_time_yearViewBase
{
public:
    Settings_date_time_yearView();
    virtual ~Settings_date_time_yearView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_DATE_TIME_YEARVIEW_HPP
