/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETTINGS_DATE_TIMEVIEWBASE_HPP
#define SETTINGS_DATE_TIMEVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/settings_date_time_screen/Settings_date_timePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class Settings_date_timeViewBase : public touchgfx::View<Settings_date_timePresenter>
{
public:
    Settings_date_timeViewBase();
    virtual ~Settings_date_timeViewBase();
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

#endif // SETTINGS_DATE_TIMEVIEWBASE_HPP
