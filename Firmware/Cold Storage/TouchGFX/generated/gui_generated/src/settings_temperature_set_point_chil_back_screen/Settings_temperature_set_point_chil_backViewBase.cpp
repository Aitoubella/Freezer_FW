/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settings_temperature_set_point_chil_back_screen/Settings_temperature_set_point_chil_backViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Settings_temperature_set_point_chil_backViewBase::Settings_temperature_set_point_chil_backViewBase()
{
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    back_text.setXY(113, 168);
    back_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    back_text.setLinespacing(0);
    back_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UZ17));
    add(back_text);

    chill_text.setXY(112, 140);
    chill_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    chill_text.setLinespacing(0);
    chill_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_YUPS));
    add(chill_text);

    set_point_text.setXY(81, 49);
    set_point_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    set_point_text.setLinespacing(0);
    set_point_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_DGNG));
    add(set_point_text);

    temperature_text.setXY(46, 7);
    temperature_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    temperature_text.setLinespacing(0);
    temperature_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_QMQC));
    add(temperature_text);
}

Settings_temperature_set_point_chil_backViewBase::~Settings_temperature_set_point_chil_backViewBase()
{

}

void Settings_temperature_set_point_chil_backViewBase::setupScreen()
{

}
