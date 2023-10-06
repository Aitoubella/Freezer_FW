#ifndef SETTINGS_ALARMVIEW_HPP
#define SETTINGS_ALARMVIEW_HPP

#include <gui_generated/settings_alarm_screen/Settings_alarmViewBase.hpp>
#include <gui/settings_alarm_screen/Settings_alarmPresenter.hpp>

class Settings_alarmView : public Settings_alarmViewBase
{
public:
    Settings_alarmView();
    virtual ~Settings_alarmView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_ALARMVIEW_HPP
