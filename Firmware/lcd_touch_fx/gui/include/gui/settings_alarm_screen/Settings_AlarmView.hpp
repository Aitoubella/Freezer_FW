#ifndef SETTINGS_ALARMVIEW_HPP
#define SETTINGS_ALARMVIEW_HPP

#include <gui_generated/settings_alarm_screen/Settings_AlarmViewBase.hpp>
#include <gui/settings_alarm_screen/Settings_AlarmPresenter.hpp>

class Settings_AlarmView : public Settings_AlarmViewBase
{
public:
    Settings_AlarmView();
    virtual ~Settings_AlarmView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_ALARMVIEW_HPP
