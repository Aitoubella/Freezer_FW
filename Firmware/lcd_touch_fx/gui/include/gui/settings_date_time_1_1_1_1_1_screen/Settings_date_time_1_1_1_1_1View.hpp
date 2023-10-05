#ifndef SETTINGS_DATE_TIME_1_1_1_1_1VIEW_HPP
#define SETTINGS_DATE_TIME_1_1_1_1_1VIEW_HPP

#include <gui_generated/settings_date_time_1_1_1_1_1_screen/Settings_date_time_1_1_1_1_1ViewBase.hpp>
#include <gui/settings_date_time_1_1_1_1_1_screen/Settings_date_time_1_1_1_1_1Presenter.hpp>

class Settings_date_time_1_1_1_1_1View : public Settings_date_time_1_1_1_1_1ViewBase
{
public:
    Settings_date_time_1_1_1_1_1View();
    virtual ~Settings_date_time_1_1_1_1_1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_DATE_TIME_1_1_1_1_1VIEW_HPP
