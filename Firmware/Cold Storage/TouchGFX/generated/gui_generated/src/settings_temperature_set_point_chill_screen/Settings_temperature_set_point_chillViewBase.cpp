/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settings_temperature_set_point_chill_screen/Settings_temperature_set_point_chillViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Settings_temperature_set_point_chillViewBase::Settings_temperature_set_point_chillViewBase()
{
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    back_text.setXY(132, 168);
    back_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    back_text.setLinespacing(0);
    back_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RN4M));
    add(back_text);

    chill_value_text.setXY(76, 120);
    chill_value_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    chill_value_text.setLinespacing(0);
    chill_value_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_U48V));
    add(chill_value_text);

    set_pint_text.setXY(81, 49);
    set_pint_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    set_pint_text.setLinespacing(0);
    set_pint_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_0YWV));
    add(set_pint_text);

    temperature_text.setXY(46, 7);
    temperature_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    temperature_text.setLinespacing(0);
    temperature_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_71P8));
    add(temperature_text);
}

Settings_temperature_set_point_chillViewBase::~Settings_temperature_set_point_chillViewBase()
{

}

void Settings_temperature_set_point_chillViewBase::setupScreen()
{

}