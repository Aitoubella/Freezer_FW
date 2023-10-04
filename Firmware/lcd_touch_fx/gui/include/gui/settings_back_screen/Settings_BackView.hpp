#ifndef SETTINGS_BACKVIEW_HPP
#define SETTINGS_BACKVIEW_HPP

#include <gui_generated/settings_back_screen/Settings_BackViewBase.hpp>
#include <gui/settings_back_screen/Settings_BackPresenter.hpp>

class Settings_BackView : public Settings_BackViewBase
{
public:
    Settings_BackView();
    virtual ~Settings_BackView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_BACKVIEW_HPP
