// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ServiceAlarmsLid_screen_init(void)
{
ui_ServiceAlarmsLid = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ServiceAlarmsLid, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ServiceAlarmsLid, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ServiceAlarmsLid, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Alarms4 = lv_label_create(ui_ServiceAlarmsLid);
lv_obj_set_width( ui_Alarms4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Alarms4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Alarms4, 0 );
lv_obj_set_y( ui_Alarms4, -96 );
lv_obj_set_align( ui_Alarms4, LV_ALIGN_CENTER );
lv_label_set_text(ui_Alarms4,"Alarms");
lv_obj_set_style_text_color(ui_Alarms4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Alarms4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Alarms4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Alarms4, &ui_font_verdana364, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Alarms4, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Alarms4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Temperature6 = lv_label_create(ui_ServiceAlarmsLid);
lv_obj_set_width( ui_Temperature6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Temperature6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Temperature6, -8 );
lv_obj_set_y( ui_Temperature6, -54 );
lv_obj_set_align( ui_Temperature6, LV_ALIGN_CENTER );
lv_label_set_text(ui_Temperature6,"Temperature");
lv_obj_set_style_text_color(ui_Temperature6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Temperature6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Temperature6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Temperature6, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Battery3 = lv_label_create(ui_ServiceAlarmsLid);
lv_obj_set_width( ui_Battery3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Battery3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Battery3, -2 );
lv_obj_set_y( ui_Battery3, -22 );
lv_obj_set_align( ui_Battery3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Battery3,"Battery");
lv_obj_set_style_text_color(ui_Battery3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Battery3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Battery3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Battery3, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Lid2 = lv_label_create(ui_ServiceAlarmsLid);
lv_obj_set_width( ui_Lid2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Lid2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Lid2, -1 );
lv_obj_set_y( ui_Lid2, 18 );
lv_obj_set_align( ui_Lid2, LV_ALIGN_CENTER );
lv_label_set_text(ui_Lid2,"Lid");
lv_obj_set_style_text_color(ui_Lid2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Lid2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Lid2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Lid2, &ui_font_verdana404, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Back23 = lv_label_create(ui_ServiceAlarmsLid);
lv_obj_set_width( ui_Back23, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Back23, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Back23, -10 );
lv_obj_set_y( ui_Back23, 86 );
lv_obj_set_align( ui_Back23, LV_ALIGN_CENTER );
lv_label_set_text(ui_Back23,"Back");
lv_obj_set_style_text_color(ui_Back23, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Back23, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Back23, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Back23, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_MuteAlarms2 = lv_label_create(ui_ServiceAlarmsLid);
lv_obj_set_width( ui_MuteAlarms2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_MuteAlarms2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_MuteAlarms2, -1 );
lv_obj_set_y( ui_MuteAlarms2, 54 );
lv_obj_set_align( ui_MuteAlarms2, LV_ALIGN_CENTER );
lv_label_set_text(ui_MuteAlarms2,"Mute Alarms");
lv_obj_set_style_text_color(ui_MuteAlarms2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_MuteAlarms2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_MuteAlarms2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_MuteAlarms2, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

}
