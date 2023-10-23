// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_SettingDateTimeYear_screen_init(void)
{
ui_SettingDateTimeYear = lv_obj_create(NULL);
lv_obj_clear_flag( ui_SettingDateTimeYear, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_SettingDateTimeYear, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_SettingDateTimeYear, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SetYear = lv_label_create(ui_SettingDateTimeYear);
lv_obj_set_width( ui_SetYear, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SetYear, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SetYear, 2 );
lv_obj_set_y( ui_SetYear, -85 );
lv_obj_set_align( ui_SetYear, LV_ALIGN_CENTER );
lv_label_set_text(ui_SetYear,"Set Year: 2023");
lv_obj_set_style_text_color(ui_SetYear, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SetYear, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_SetYear, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SetYear, &ui_font_verdana404, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SetMonth = lv_label_create(ui_SettingDateTimeYear);
lv_obj_set_width( ui_SetMonth, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SetMonth, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SetMonth, 0 );
lv_obj_set_y( ui_SetMonth, -44 );
lv_obj_set_align( ui_SetMonth, LV_ALIGN_CENTER );
lv_label_set_text(ui_SetMonth,"Set Month: 06");
lv_obj_set_style_text_color(ui_SetMonth, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SetMonth, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_SetMonth, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SetMonth, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SetDay = lv_label_create(ui_SettingDateTimeYear);
lv_obj_set_width( ui_SetDay, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SetDay, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SetDay, 0 );
lv_obj_set_y( ui_SetDay, -13 );
lv_obj_set_align( ui_SetDay, LV_ALIGN_CENTER );
lv_label_set_text(ui_SetDay,"Set Day: 06");
lv_obj_set_style_text_color(ui_SetDay, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SetDay, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_SetDay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SetDay, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Back5 = lv_label_create(ui_SettingDateTimeYear);
lv_obj_set_width( ui_Back5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Back5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Back5, -8 );
lv_obj_set_y( ui_Back5, 84 );
lv_obj_set_align( ui_Back5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Back5,"Back");
lv_obj_set_style_text_color(ui_Back5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Back5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Back5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Back5, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SetHour = lv_label_create(ui_SettingDateTimeYear);
lv_obj_set_width( ui_SetHour, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SetHour, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SetHour, -4 );
lv_obj_set_y( ui_SetHour, 19 );
lv_obj_set_align( ui_SetHour, LV_ALIGN_CENTER );
lv_label_set_text(ui_SetHour,"Set Hour: 06");
lv_obj_set_style_text_color(ui_SetHour, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SetHour, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_SetHour, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SetHour, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SetMinute = lv_label_create(ui_SettingDateTimeYear);
lv_obj_set_width( ui_SetMinute, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SetMinute, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SetMinute, -3 );
lv_obj_set_y( ui_SetMinute, 52 );
lv_obj_set_align( ui_SetMinute, LV_ALIGN_CENTER );
lv_label_set_text(ui_SetMinute,"Set Minute: 06");
lv_obj_set_style_text_color(ui_SetMinute, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SetMinute, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_SetMinute, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SetMinute, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

}
