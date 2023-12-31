// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ServiceTemperature_screen_init(void)
{
ui_ServiceTemperature = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ServiceTemperature, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ServiceTemperature, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ServiceTemperature, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Service = lv_label_create(ui_ServiceTemperature);
lv_obj_set_width( ui_Service, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Service, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Service, 0 );
lv_obj_set_y( ui_Service, -96 );
lv_obj_set_align( ui_Service, LV_ALIGN_CENTER );
lv_label_set_text(ui_Service,"Service");
lv_obj_set_style_text_color(ui_Service, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Service, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Service, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Service, &ui_font_verdana364, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_Service, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_Service, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Temperature = lv_label_create(ui_ServiceTemperature);
lv_obj_set_width( ui_Temperature, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Temperature, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Temperature, -7 );
lv_obj_set_y( ui_Temperature, -45 );
lv_obj_set_align( ui_Temperature, LV_ALIGN_CENTER );
lv_label_set_text(ui_Temperature,"Temperature");
lv_obj_set_style_text_color(ui_Temperature, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Temperature, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Temperature, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Temperature, &ui_font_verdana404, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Alarms = lv_label_create(ui_ServiceTemperature);
lv_obj_set_width( ui_Alarms, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Alarms, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Alarms, -3 );
lv_obj_set_y( ui_Alarms, -5 );
lv_obj_set_align( ui_Alarms, LV_ALIGN_CENTER );
lv_label_set_text(ui_Alarms,"Alarms");
lv_obj_set_style_text_color(ui_Alarms, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Alarms, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Alarms, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Alarms, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Back10 = lv_label_create(ui_ServiceTemperature);
lv_obj_set_width( ui_Back10, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Back10, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Back10, -10 );
lv_obj_set_y( ui_Back10, 86 );
lv_obj_set_align( ui_Back10, LV_ALIGN_CENTER );
lv_label_set_text(ui_Back10,"Back");
lv_obj_set_style_text_color(ui_Back10, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Back10, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Back10, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Back10, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_DataLogging = lv_label_create(ui_ServiceTemperature);
lv_obj_set_width( ui_DataLogging, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_DataLogging, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_DataLogging, -1 );
lv_obj_set_y( ui_DataLogging, 23 );
lv_obj_set_align( ui_DataLogging, LV_ALIGN_CENTER );
lv_label_set_text(ui_DataLogging,"Data Logging");
lv_obj_set_style_text_color(ui_DataLogging, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_DataLogging, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_DataLogging, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_DataLogging, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Calibrartion = lv_label_create(ui_ServiceTemperature);
lv_obj_set_width( ui_Calibrartion, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Calibrartion, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Calibrartion, -1 );
lv_obj_set_y( ui_Calibrartion, 54 );
lv_obj_set_align( ui_Calibrartion, LV_ALIGN_CENTER );
lv_label_set_text(ui_Calibrartion,"Calibrartion");
lv_obj_set_style_text_color(ui_Calibrartion, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Calibrartion, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Calibrartion, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Calibrartion, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

}
