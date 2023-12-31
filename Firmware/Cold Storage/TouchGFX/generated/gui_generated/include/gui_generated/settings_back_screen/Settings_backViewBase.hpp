/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETTINGS_BACKVIEWBASE_HPP
#define SETTINGS_BACKVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/settings_back_screen/Settings_backPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class Settings_backViewBase : public touchgfx::View<Settings_backPresenter>
{
public:
    Settings_backViewBase();
    virtual ~Settings_backViewBase();
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

#endif // SETTINGS_BACKVIEWBASE_HPP
