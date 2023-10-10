/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETTINGS_TEMPERATUREVIEWBASE_HPP
#define SETTINGS_TEMPERATUREVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/settings_temperature_screen/Settings_temperaturePresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class Settings_temperatureViewBase : public touchgfx::View<Settings_temperaturePresenter>
{
public:
    Settings_temperatureViewBase();
    virtual ~Settings_temperatureViewBase();
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

#endif // SETTINGS_TEMPERATUREVIEWBASE_HPP
