#ifndef SETTINGS_DATA_LOGGINGVIEW_HPP
#define SETTINGS_DATA_LOGGINGVIEW_HPP

#include <gui_generated/settings_data_logging_screen/Settings_data_loggingViewBase.hpp>
#include <gui/settings_data_logging_screen/Settings_data_loggingPresenter.hpp>

class Settings_data_loggingView : public Settings_data_loggingViewBase
{
public:
    Settings_data_loggingView();
    virtual ~Settings_data_loggingView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_DATA_LOGGINGVIEW_HPP
