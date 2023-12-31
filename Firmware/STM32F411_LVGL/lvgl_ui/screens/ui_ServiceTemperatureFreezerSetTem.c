// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_ServiceTemperatureFreezerSetTem_screen_init(void)
{
ui_ServiceTemperatureFreezerSetTem = lv_obj_create(NULL);
lv_obj_clear_flag( ui_ServiceTemperatureFreezerSetTem, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_ServiceTemperatureFreezerSetTem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_ServiceTemperatureFreezerSetTem, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_FreezerManu1 = lv_label_create(ui_ServiceTemperatureFreezerSetTem);
lv_obj_set_width( ui_FreezerManu1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_FreezerManu1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_FreezerManu1, 0 );
lv_obj_set_y( ui_FreezerManu1, -96 );
lv_obj_set_align( ui_FreezerManu1, LV_ALIGN_CENTER );
lv_label_set_text(ui_FreezerManu1,"Freezer");
lv_obj_set_style_text_color(ui_FreezerManu1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_FreezerManu1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_FreezerManu1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_FreezerManu1, &ui_font_verdana364, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_FreezerManu1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_FreezerManu1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_SetPoint4 = lv_label_create(ui_ServiceTemperatureFreezerSetTem);
lv_obj_set_width( ui_SetPoint4, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_SetPoint4, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_SetPoint4, -1 );
lv_obj_set_y( ui_SetPoint4, -48 );
lv_obj_set_align( ui_SetPoint4, LV_ALIGN_CENTER );
lv_label_set_text(ui_SetPoint4,"Set Point");
lv_obj_set_style_text_color(ui_SetPoint4, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_SetPoint4, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_SetPoint4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_SetPoint4, &ui_font_verdana364, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TemperatureValue6 = lv_label_create(ui_ServiceTemperatureFreezerSetTem);
lv_obj_set_width( ui_TemperatureValue6, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TemperatureValue6, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TemperatureValue6, -7 );
lv_obj_set_y( ui_TemperatureValue6, 0 );
lv_obj_set_align( ui_TemperatureValue6, LV_ALIGN_CENTER );
lv_label_set_text(ui_TemperatureValue6,"-20°C");
lv_obj_set_style_text_color(ui_TemperatureValue6, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TemperatureValue6, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_TemperatureValue6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TemperatureValue6, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TemperatureValue7 = lv_label_create(ui_ServiceTemperatureFreezerSetTem);
lv_obj_set_width( ui_TemperatureValue7, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TemperatureValue7, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TemperatureValue7, -3 );
lv_obj_set_y( ui_TemperatureValue7, 37 );
lv_obj_set_align( ui_TemperatureValue7, LV_ALIGN_CENTER );
lv_label_set_text(ui_TemperatureValue7,"-21°C");
lv_obj_set_style_text_color(ui_TemperatureValue7, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TemperatureValue7, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_TemperatureValue7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TemperatureValue7, &lv_font_montserrat_36, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_TemperatureValue8 = lv_label_create(ui_ServiceTemperatureFreezerSetTem);
lv_obj_set_width( ui_TemperatureValue8, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_TemperatureValue8, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_TemperatureValue8, -3 );
lv_obj_set_y( ui_TemperatureValue8, 73 );
lv_obj_set_align( ui_TemperatureValue8, LV_ALIGN_CENTER );
lv_label_set_text(ui_TemperatureValue8,"-22°C");
lv_obj_set_style_text_color(ui_TemperatureValue8, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_TemperatureValue8, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_TemperatureValue8, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_TemperatureValue8, &lv_font_montserrat_24, LV_PART_MAIN| LV_STATE_DEFAULT);

}
