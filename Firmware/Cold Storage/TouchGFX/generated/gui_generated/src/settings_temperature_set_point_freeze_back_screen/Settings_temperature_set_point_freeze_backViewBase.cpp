/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settings_temperature_set_point_freeze_back_screen/Settings_temperature_set_point_freeze_backViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Settings_temperature_set_point_freeze_backViewBase::Settings_temperature_set_point_freeze_backViewBase()
{
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    back_text.setXY(113, 168);
    back_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    back_text.setLinespacing(0);
    back_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CADZ));
    add(back_text);

    freeze_value_text.setXY(86, 140);
    freeze_value_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    freeze_value_text.setLinespacing(0);
    freeze_value_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_707V));
    add(freeze_value_text);

    set_point_text.setXY(81, 49);
    set_point_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    set_point_text.setLinespacing(0);
    set_point_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_P9JS));
    add(set_point_text);

    temperature_text.setXY(46, 7);
    temperature_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    temperature_text.setLinespacing(0);
    temperature_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_K7AJ));
    add(temperature_text);
}

Settings_temperature_set_point_freeze_backViewBase::~Settings_temperature_set_point_freeze_backViewBase()
{

}

void Settings_temperature_set_point_freeze_backViewBase::setupScreen()
{

}
