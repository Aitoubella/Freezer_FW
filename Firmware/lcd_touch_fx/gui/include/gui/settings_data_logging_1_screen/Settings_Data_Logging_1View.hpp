#ifndef SETTINGS_DATA_LOGGING_1VIEW_HPP
#define SETTINGS_DATA_LOGGING_1VIEW_HPP

#include <gui_generated/settings_data_logging_1_screen/Settings_Data_Logging_1ViewBase.hpp>
#include <gui/settings_data_logging_1_screen/Settings_Data_Logging_1Presenter.hpp>

class Settings_Data_Logging_1View : public Settings_Data_Logging_1ViewBase
{
public:
    Settings_Data_Logging_1View();
    virtual ~Settings_Data_Logging_1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
protected:
};

#endif // SETTINGS_DATA_LOGGING_1VIEW_HPP
