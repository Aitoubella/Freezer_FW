// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ServiceAlarmsBatteryAlarmEnter_screen_init(void)
{
ui_ServiceAlarmsBatteryAlarmEnter = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ServiceAlarmsBatteryAlarmEnter, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ServiceAlarmsBatteryAlarmEnter, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ServiceAlarmsBatteryAlarmEnter, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_BatteryAlarm = lv_label_create(ui_ServiceAlarmsBatteryAlarmEnter);
lv_obj_set_width( ui_BatteryAlarm, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_BatteryAlarm, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_BatteryAlarm, 3 );
lv_obj_set_y( ui_BatteryAlarm, -78 );
lv_obj_set_align( ui_BatteryAlarm, LV_ALIGN_CENTER );
lv_label_set_text(ui_BatteryAlarm,"Battery Alarm");
lv_obj_set_style_text_color(ui_BatteryAlarm, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_BatteryAlarm, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_BatteryAlarm, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_BatteryAlarm, &ui_font_verdana364, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_BatteryAlarm, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_BatteryAlarm, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Battery2 = lv_label_create(ui_ServiceAlarmsBatteryAlarmEnter);
lv_obj_set_width( ui_Battery2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Battery2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Battery2, -2 );
lv_obj_set_y( ui_Battery2, -1 );
lv_obj_set_align( ui_Battery2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Battery2,"20%");
lv_obj_set_style_text_color(ui_Battery2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Battery2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Battery2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Battery2, &lv_font_montserrat_40, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Back22 = lv_label_create(ui_ServiceAlarmsBatteryAlarmEnter);
lv_obj_set_width( ui_Back22, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Back22, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Back22, -2 );
lv_obj_set_y( ui_Back22, 44 );
lv_obj_set_align( ui_Back22, LV_ALIGN_CENTER );
lv_label_set_text(ui_Back22,"Back");
lv_obj_set_style_text_color(ui_Back22, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Back22, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Back22, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Back22, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

}
