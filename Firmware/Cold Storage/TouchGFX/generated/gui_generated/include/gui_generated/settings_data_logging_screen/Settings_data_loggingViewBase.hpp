/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETTINGS_DATA_LOGGINGVIEWBASE_HPP
#define SETTINGS_DATA_LOGGINGVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/settings_data_logging_screen/Settings_data_loggingPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class Settings_data_loggingViewBase : public touchgfx::View<Settings_data_loggingPresenter>
{
public:
    Settings_data_loggingViewBase();
    virtual ~Settings_data_loggingViewBase();
    virtual void setupScreen();

protected:
    FrontendApplication& application() {
        return *static_cast<FrontendApplication*>(touchgfx::Application::getInstance());
    }

    /*
     * Member Declarations
     */
    touchgfx::Box __background;
    touchgfx::TextArea back_text;
    touchgfx::TextArea data_logging_text;
    touchgfx::TextArea date_time_text;
    touchgfx::TextArea alarms_text;
    touchgfx::TextArea temperature_text;
    touchgfx::TextArea settings_text;

private:

};

#endif // SETTINGS_DATA_LOGGINGVIEWBASE_HPP