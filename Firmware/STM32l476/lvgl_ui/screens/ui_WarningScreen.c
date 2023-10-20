// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_WarningScreen_screen_init(void)
{
ui_WarningScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_WarningScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_WarningScreen, lv_color_hex(0xFF0000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_WarningScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Fridge5 = lv_label_create(ui_WarningScreen);
lv_obj_set_width( ui_Fridge5, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Fridge5, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Fridge5, -6 );
lv_obj_set_y( ui_Fridge5, -71 );
lv_obj_set_align( ui_Fridge5, LV_ALIGN_CENTER );
lv_label_set_text(ui_Fridge5,"Fridge");
lv_obj_set_style_text_color(ui_Fridge5, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Fridge5, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Fridge5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Fridge5, &ui_font_verdana404, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_WarningText = lv_label_create(ui_WarningScreen);
lv_obj_set_width( ui_WarningText, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_WarningText, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_WarningText, 40 );
lv_obj_set_y( ui_WarningText, 45 );
lv_obj_set_align( ui_WarningText, LV_ALIGN_CENTER );
lv_label_set_text(ui_WarningText,"Under Min\nTemp");
lv_obj_set_style_text_color(ui_WarningText, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_WarningText, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_WarningText, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_WarningText, &ui_font_verdana364, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Label1 = lv_label_create(ui_WarningScreen);
lv_obj_set_width( ui_Label1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Label1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Label1, -108 );
lv_obj_set_y( ui_Label1, 32 );
lv_obj_set_align( ui_Label1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Label1,"T");
lv_obj_set_style_text_color(ui_Label1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Label1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Label1, &lv_font_montserrat_40, LV_PART_MAIN| LV_STATE_DEFAULT);

}
