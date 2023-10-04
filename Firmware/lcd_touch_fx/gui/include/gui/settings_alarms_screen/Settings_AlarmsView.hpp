#ifndef SETTINGS_ALARMSVIEW_HPP
#define SETTINGS_ALARMSVIEW_HPP

#include <gui_generated/settings_alarms_screen/Settings_AlarmsViewBase.hpp>
#include <gui/settings_alarms_screen/Settings_AlarmsPresenter.hpp>

class Settings_AlarmsView : public Settings_AlarmsViewBase
{
public:
    Settings_AlarmsView();
    virtual ~Settings_AlarmsView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_ALARMSVIEW_HPP
