// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ServiceAlarmsBatteryAlarm_screen_init(void)
{
ui_ServiceAlarmsBatteryAlarm = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ServiceAlarmsBatteryAlarm, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ServiceAlarmsBatteryAlarm, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ServiceAlarmsBatteryAlarm, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Alarms2 = lv_label_create(ui_ServiceAlarmsBatteryAlarm);
lv_obj_set_width( ui_Alarms2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Alarms2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Alarms2, 0 );
lv_obj_set_y( ui_Alarms2, -96 );
lv_obj_set_align( ui_Alarms2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Alarms2,"Alarms");
lv_obj_set_style_text_color(ui_Alarms2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Alarms2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Alarms2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Alarms2, &ui_font_verdana364, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Alarms2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Alarms2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Temperature5 = lv_label_create(ui_ServiceAlarmsBatteryAlarm);
lv_obj_set_width( ui_Temperature5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Temperature5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Temperature5, -8 );
lv_obj_set_y( ui_Temperature5, -54 );
lv_obj_set_align( ui_Temperature5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Temperature5,"Temperature");
lv_obj_set_style_text_color(ui_Temperature5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Temperature5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Temperature5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Temperature5, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Battery1 = lv_label_create(ui_ServiceAlarmsBatteryAlarm);
lv_obj_set_width( ui_Battery1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Battery1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Battery1, -2 );
lv_obj_set_y( ui_Battery1, -15 );
lv_obj_set_align( ui_Battery1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Battery1,"Battery");
lv_obj_set_style_text_color(ui_Battery1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Battery1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Battery1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Battery1, &ui_font_verdana404, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Lid1 = lv_label_create(ui_ServiceAlarmsBatteryAlarm);
lv_obj_set_width( ui_Lid1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Lid1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Lid1, -1 );
lv_obj_set_y( ui_Lid1, 23 );
lv_obj_set_align( ui_Lid1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Lid1,"Lid");
lv_obj_set_style_text_color(ui_Lid1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Lid1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Lid1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Lid1, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Back21 = lv_label_create(ui_ServiceAlarmsBatteryAlarm);
lv_obj_set_width( ui_Back21, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Back21, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Back21, -10 );
lv_obj_set_y( ui_Back21, 86 );
lv_obj_set_align( ui_Back21, LV_ALIGN_CENTER );
lv_label_set_text(ui_Back21,"Back");
lv_obj_set_style_text_color(ui_Back21, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Back21, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Back21, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Back21, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_MuteAlarms1 = lv_label_create(ui_ServiceAlarmsBatteryAlarm);
lv_obj_set_width( ui_MuteAlarms1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_MuteAlarms1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_MuteAlarms1, -1 );
lv_obj_set_y( ui_MuteAlarms1, 54 );
lv_obj_set_align( ui_MuteAlarms1, LV_ALIGN_CENTER );
lv_label_set_text(ui_MuteAlarms1,"Mute Alarms");
lv_obj_set_style_text_color(ui_MuteAlarms1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_MuteAlarms1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_MuteAlarms1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_MuteAlarms1, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

}
