// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ServiceAlarmsTempDeviation_screen_init(void)
{
ui_ServiceAlarmsTempDeviation = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ServiceAlarmsTempDeviation, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ServiceAlarmsTempDeviation, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ServiceAlarmsTempDeviation, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TempDeviation = lv_label_create(ui_ServiceAlarmsTempDeviation);
lv_obj_set_width( ui_TempDeviation, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TempDeviation, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TempDeviation, -5 );
lv_obj_set_y( ui_TempDeviation, -40 );
lv_obj_set_align( ui_TempDeviation, LV_ALIGN_CENTER );
lv_label_set_text(ui_TempDeviation,"Temp Deviation");
lv_obj_set_style_text_color(ui_TempDeviation, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TempDeviation, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_TempDeviation, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TempDeviation, &ui_font_verdana404, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_AlarmDelay = lv_label_create(ui_ServiceAlarmsTempDeviation);
lv_obj_set_width( ui_AlarmDelay, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_AlarmDelay, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_AlarmDelay, -5 );
lv_obj_set_y( ui_AlarmDelay, 22 );
lv_obj_set_align( ui_AlarmDelay, LV_ALIGN_CENTER );
lv_label_set_text(ui_AlarmDelay,"Alarm Delay");
lv_obj_set_style_text_color(ui_AlarmDelay, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_AlarmDelay, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_AlarmDelay, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_AlarmDelay, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Back19 = lv_label_create(ui_ServiceAlarmsTempDeviation);
lv_obj_set_width( ui_Back19, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Back19, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Back19, -10 );
lv_obj_set_y( ui_Back19, 69 );
lv_obj_set_align( ui_Back19, LV_ALIGN_CENTER );
lv_label_set_text(ui_Back19,"Back");
lv_obj_set_style_text_color(ui_Back19, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Back19, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Back19, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Back19, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

}
