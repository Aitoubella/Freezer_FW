/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settings_back_screen/Settings_backViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Settings_backViewBase::Settings_backViewBase()
{
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    back_text.setXY(113, 168);
    back_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    back_text.setLinespacing(0);
    back_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_7PGL));
    add(back_text);

    data_logging_text.setXY(84, 140);
    data_logging_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    data_logging_text.setLinespacing(0);
    data_logging_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3EJW));
    add(data_logging_text);

    date_time_text.setXY(100, 112);
    date_time_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    date_time_text.setLinespacing(0);
    date_time_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_G5IW));
    add(date_time_text);

    alarms_text.setXY(120, 84);
    alarms_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    alarms_text.setLinespacing(0);
    alarms_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_K1BR));
    add(alarms_text);

    temperature_text.setXY(85, 56);
    temperature_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    temperature_text.setLinespacing(0);
    temperature_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_8D3J));
    add(temperature_text);

    settings_text.setXY(88, 7);
    settings_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    settings_text.setLinespacing(0);
    settings_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KDUI));
    add(settings_text);
}

Settings_backViewBase::~Settings_backViewBase()
{

}

void Settings_backViewBase::setupScreen()
{

}
