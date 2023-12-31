// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ServiceAlarmsMuteAlarmBack_screen_init(void)
{
ui_ServiceAlarmsMuteAlarmBack = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ServiceAlarmsMuteAlarmBack, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ServiceAlarmsMuteAlarmBack, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ServiceAlarmsMuteAlarmBack, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_MuteDuration2 = lv_label_create(ui_ServiceAlarmsMuteAlarmBack);
lv_obj_set_width( ui_MuteDuration2, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_MuteDuration2, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_MuteDuration2, 3 );
lv_obj_set_y( ui_MuteDuration2, -78 );
lv_obj_set_align( ui_MuteDuration2, LV_ALIGN_CENTER );
lv_label_set_text(ui_MuteDuration2,"Mute Duration");
lv_obj_set_style_text_color(ui_MuteDuration2, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_MuteDuration2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_MuteDuration2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_MuteDuration2, &ui_font_verdana364, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_MuteDuration2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_MuteDuration2, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TimeValue9 = lv_label_create(ui_ServiceAlarmsMuteAlarmBack);
lv_obj_set_width( ui_TimeValue9, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TimeValue9, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TimeValue9, -2 );
lv_obj_set_y( ui_TimeValue9, -1 );
lv_obj_set_align( ui_TimeValue9, LV_ALIGN_CENTER );
lv_label_set_text(ui_TimeValue9,"2 mins");
lv_obj_set_style_text_color(ui_TimeValue9, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TimeValue9, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_TimeValue9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TimeValue9, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Back29 = lv_label_create(ui_ServiceAlarmsMuteAlarmBack);
lv_obj_set_width( ui_Back29, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Back29, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Back29, -2 );
lv_obj_set_y( ui_Back29, 44 );
lv_obj_set_align( ui_Back29, LV_ALIGN_CENTER );
lv_label_set_text(ui_Back29,"Back");
lv_obj_set_style_text_color(ui_Back29, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Back29, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Back29, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Back29, &ui_font_verdana404, LV_PART_MAIN| LV_STATE_DEFAULT);

}
