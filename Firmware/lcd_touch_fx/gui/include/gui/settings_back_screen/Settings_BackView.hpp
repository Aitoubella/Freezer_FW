#ifndef SETTINGS_BACKVIEW_HPP
#define SETTINGS_BACKVIEW_HPP

#include <gui_generated/settings_back_screen/Settings_backViewBase.hpp>
#include <gui/settings_back_screen/Settings_backPresenter.hpp>

class Settings_backView : public Settings_backViewBase
{
public:
    Settings_backView();
    virtual ~Settings_backView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_BACKVIEW_HPP
