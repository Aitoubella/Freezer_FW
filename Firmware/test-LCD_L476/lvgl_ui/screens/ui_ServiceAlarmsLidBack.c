// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ServiceAlarmsLidBack_screen_init(void)
{
ui_ServiceAlarmsLidBack = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ServiceAlarmsLidBack, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ServiceAlarmsLidBack, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ServiceAlarmsLidBack, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_LidAlarm1 = lv_label_create(ui_ServiceAlarmsLidBack);
lv_obj_set_width( ui_LidAlarm1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_LidAlarm1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_LidAlarm1, 3 );
lv_obj_set_y( ui_LidAlarm1, -78 );
lv_obj_set_align( ui_LidAlarm1, LV_ALIGN_CENTER );
lv_label_set_text(ui_LidAlarm1,"Lid Alarm");
lv_obj_set_style_text_color(ui_LidAlarm1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_LidAlarm1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_LidAlarm1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_LidAlarm1, &ui_font_verdana364, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_LidAlarm1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_LidAlarm1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TimeValue2 = lv_label_create(ui_ServiceAlarmsLidBack);
lv_obj_set_width( ui_TimeValue2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TimeValue2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TimeValue2, -2 );
lv_obj_set_y( ui_TimeValue2, -1 );
lv_obj_set_align( ui_TimeValue2, LV_ALIGN_CENTER );
lv_label_set_text(ui_TimeValue2,"2 mins");
lv_obj_set_style_text_color(ui_TimeValue2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TimeValue2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_TimeValue2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TimeValue2, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Back26 = lv_label_create(ui_ServiceAlarmsLidBack);
lv_obj_set_width( ui_Back26, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Back26, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Back26, -2 );
lv_obj_set_y( ui_Back26, 44 );
lv_obj_set_align( ui_Back26, LV_ALIGN_CENTER );
lv_label_set_text(ui_Back26,"Back");
lv_obj_set_style_text_color(ui_Back26, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Back26, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Back26, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Back26, &ui_font_verdana404, LV_PART_MAIN| LV_STATE_DEFAULT);

}