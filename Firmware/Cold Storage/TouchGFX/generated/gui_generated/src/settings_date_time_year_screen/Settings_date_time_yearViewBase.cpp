/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/settings_date_time_year_screen/Settings_date_time_yearViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Settings_date_time_yearViewBase::Settings_date_time_yearViewBase()
{
    __background.setPosition(0, 0, 320, 240);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    back_text.setXY(136, 195);
    back_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    back_text.setLinespacing(0);
    back_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_T4TW));
    add(back_text);

    set_minute_text.setXY(74, 158);
    set_minute_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    set_minute_text.setLinespacing(0);
    set_minute_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_SLAD));
    add(set_minute_text);

    set_hour_text.setXY(78, 128);
    set_hour_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    set_hour_text.setLinespacing(0);
    set_hour_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TLFY));
    add(set_hour_text);

    set_day_text.setXY(84, 98);
    set_day_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    set_day_text.setLinespacing(0);
    set_day_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_B436));
    add(set_day_text);

    set_month_text.setXY(70, 68);
    set_month_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    set_month_text.setLinespacing(0);
    set_month_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_HIS8));
    add(set_month_text);

    set_year_text.setXY(9, 17);
    set_year_text.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    set_year_text.setLinespacing(0);
    set_year_text.setTypedText(touchgfx::TypedText(T___SINGLEUSE_5BGM));
    add(set_year_text);
}

Settings_date_time_yearViewBase::~Settings_date_time_yearViewBase()
{

}

void Settings_date_time_yearViewBase::setupScreen()
{

}
