/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#ifndef SETTINGS_TEMPERATURE_SET_POINT_CHILLVIEWBASE_HPP
#define SETTINGS_TEMPERATURE_SET_POINT_CHILLVIEWBASE_HPP

#include <gui/common/FrontendApplication.hpp>
#include <mvp/View.hpp>
#include <gui/settings_temperature_set_point_chill_screen/Settings_temperature_set_point_chillPresenter.hpp>
#include <touchgfx/widgets/Box.hpp>
#include <touchgfx/widgets/TextArea.hpp>

class Settings_temperature_set_point_chillViewBase : public touchgfx::View<Settings_temperature_set_point_chillPresenter>
{
public:
    Settings_temperature_set_point_chillViewBase();
    virtual ~Settings_temperature_set_point_chillViewBase();
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
    touchgfx::TextArea chill_value_text;
    touchgfx::TextArea set_pint_text;
    touchgfx::TextArea temperature_text;

private:

};

#endif // SETTINGS_TEMPERATURE_SET_POINT_CHILLVIEWBASE_HPP
