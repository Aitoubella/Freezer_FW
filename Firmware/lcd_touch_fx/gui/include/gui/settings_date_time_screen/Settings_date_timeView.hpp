#ifndef SETTINGS_DATE_TIMEVIEW_HPP
#define SETTINGS_DATE_TIMEVIEW_HPP

#include <gui_generated/settings_date_time_screen/Settings_date_timeViewBase.hpp>
#include <gui/settings_date_time_screen/Settings_date_timePresenter.hpp>

class Settings_date_timeView : public Settings_date_timeViewBase
{
public:
    Settings_date_timeView();
    virtual ~Settings_date_timeView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_DATE_TIMEVIEW_HPP
