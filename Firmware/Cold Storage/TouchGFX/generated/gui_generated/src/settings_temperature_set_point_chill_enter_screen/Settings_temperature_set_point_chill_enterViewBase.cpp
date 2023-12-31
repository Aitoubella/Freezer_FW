/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settings_temperature_set_point_chill_enter_screen/Settings_temperature_set_point_chill_enterViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Settings_temperature_set_point_chill_enterViewBase::Settings_temperature_set_point_chill_enterViewBase()
{
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    temperature_value_3_text.setXY(126, 141);
    temperature_value_3_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    temperature_value_3_text.setLinespacing(0);
    temperature_value_3_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_Q6FV));
    add(temperature_value_3_text);

    temperature_value_2_text.setXY(141, 195);
    temperature_value_2_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    temperature_value_2_text.setLinespacing(0);
    temperature_value_2_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_JVFK));
    add(temperature_value_2_text);

    temperature_value_1_text.setXY(141, 112);
    temperature_value_1_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    temperature_value_1_text.setLinespacing(0);
    temperature_value_1_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_99Q1));
    add(temperature_value_1_text);

    set_point_text.setXY(81, 49);
    set_point_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    set_point_text.setLinespacing(0);
    set_point_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4LTD));
    add(set_point_text);

    temperature_text.setXY(46, 7);
    temperature_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    temperature_text.setLinespacing(0);
    temperature_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_K6SJ));
    add(temperature_text);
}

Settings_temperature_set_point_chill_enterViewBase::~Settings_temperature_set_point_chill_enterViewBase()
{

}

void Settings_temperature_set_point_chill_enterViewBase::setupScreen()
{

}
