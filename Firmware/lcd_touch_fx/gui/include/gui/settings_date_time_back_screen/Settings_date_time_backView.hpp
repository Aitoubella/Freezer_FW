#ifndef SETTINGS_DATE_TIME_BACKVIEW_HPP
#define SETTINGS_DATE_TIME_BACKVIEW_HPP

#include <gui_generated/settings_date_time_back_screen/Settings_date_time_backViewBase.hpp>
#include <gui/settings_date_time_back_screen/Settings_date_time_backPresenter.hpp>

class Settings_date_time_backView : public Settings_date_time_backViewBase
{
public:
    Settings_date_time_backView();
    virtual ~Settings_date_time_backView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_DATE_TIME_BACKVIEW_HPP
