// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ServiceAlarmsTemp_screen_init(void)
{
ui_ServiceAlarmsTemp = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ServiceAlarmsTemp, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ServiceAlarmsTemp, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ServiceAlarmsTemp, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Alarms3 = lv_label_create(ui_ServiceAlarmsTemp);
lv_obj_set_width( ui_Alarms3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Alarms3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Alarms3, 0 );
lv_obj_set_y( ui_Alarms3, -96 );
lv_obj_set_align( ui_Alarms3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Alarms3,"Alarms");
lv_obj_set_style_text_color(ui_Alarms3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Alarms3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Alarms3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Alarms3, &ui_font_verdana364, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Alarms3, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Alarms3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Temperature4 = lv_label_create(ui_ServiceAlarmsTemp);
lv_obj_set_width( ui_Temperature4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Temperature4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Temperature4, -7 );
lv_obj_set_y( ui_Temperature4, -49 );
lv_obj_set_align( ui_Temperature4, LV_ALIGN_CENTER );
lv_label_set_text(ui_Temperature4,"Temperature");
lv_obj_set_style_text_color(ui_Temperature4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Temperature4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Temperature4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Temperature4, &ui_font_verdana404, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Battery = lv_label_create(ui_ServiceAlarmsTemp);
lv_obj_set_width( ui_Battery, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Battery, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Battery, -1 );
lv_obj_set_y( ui_Battery, -10 );
lv_obj_set_align( ui_Battery, LV_ALIGN_CENTER );
lv_label_set_text(ui_Battery,"Battery");
lv_obj_set_style_text_color(ui_Battery, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Battery, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Battery, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Battery, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Lid = lv_label_create(ui_ServiceAlarmsTemp);
lv_obj_set_width( ui_Lid, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Lid, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Lid, -1 );
lv_obj_set_y( ui_Lid, 23 );
lv_obj_set_align( ui_Lid, LV_ALIGN_CENTER );
lv_label_set_text(ui_Lid,"Lid");
lv_obj_set_style_text_color(ui_Lid, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Lid, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Lid, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Lid, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Back18 = lv_label_create(ui_ServiceAlarmsTemp);
lv_obj_set_width( ui_Back18, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Back18, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Back18, -10 );
lv_obj_set_y( ui_Back18, 86 );
lv_obj_set_align( ui_Back18, LV_ALIGN_CENTER );
lv_label_set_text(ui_Back18,"Back");
lv_obj_set_style_text_color(ui_Back18, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Back18, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Back18, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Back18, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_MuteAlarms = lv_label_create(ui_ServiceAlarmsTemp);
lv_obj_set_width( ui_MuteAlarms, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_MuteAlarms, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_MuteAlarms, -1 );
lv_obj_set_y( ui_MuteAlarms, 54 );
lv_obj_set_align( ui_MuteAlarms, LV_ALIGN_CENTER );
lv_label_set_text(ui_MuteAlarms,"Mute Alarms");
lv_obj_set_style_text_color(ui_MuteAlarms, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_MuteAlarms, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_MuteAlarms, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_MuteAlarms, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

}
