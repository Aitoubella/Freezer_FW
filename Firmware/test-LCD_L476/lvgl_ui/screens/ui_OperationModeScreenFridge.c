// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.3.2
// LVGL version: 8.3.6
// Project name: SquareLine_Project

#include "../ui.h"

void ui_OperationModeScreenFridge_screen_init(void)
{
ui_OperationModeScreenFridge = lv_obj_create(NULL);
lv_obj_clear_flag( ui_OperationModeScreenFridge, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_OperationModeScreenFridge, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_OperationModeScreenFridge, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_OpeartionMode1 = lv_label_create(ui_OperationModeScreenFridge);
lv_obj_set_width( ui_OpeartionMode1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_OpeartionMode1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_OpeartionMode1, 0 );
lv_obj_set_y( ui_OpeartionMode1, -96 );
lv_obj_set_align( ui_OpeartionMode1, LV_ALIGN_CENTER );
lv_label_set_text(ui_OpeartionMode1,"Operation Mode");
lv_obj_set_style_text_color(ui_OpeartionMode1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_OpeartionMode1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_OpeartionMode1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_OpeartionMode1, &ui_font_verdana364, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_OpeartionMode1, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_OpeartionMode1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Fridge1 = lv_label_create(ui_OperationModeScreenFridge);
lv_obj_set_width( ui_Fridge1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Fridge1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Fridge1, -1 );
lv_obj_set_y( ui_Fridge1, -28 );
lv_obj_set_align( ui_Fridge1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Fridge1,"Fridge");
lv_obj_set_style_text_color(ui_Fridge1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Fridge1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Fridge1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Fridge1, &ui_font_verdana404, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Freezer1 = lv_label_create(ui_OperationModeScreenFridge);
lv_obj_set_width( ui_Freezer1, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Freezer1, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Freezer1, -5 );
lv_obj_set_y( ui_Freezer1, 14 );
lv_obj_set_align( ui_Freezer1, LV_ALIGN_CENTER );
lv_label_set_text(ui_Freezer1,"Freezer");
lv_obj_set_style_text_color(ui_Freezer1, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Freezer1, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Freezer1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Freezer1, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_Back3 = lv_label_create(ui_OperationModeScreenFridge);
lv_obj_set_width( ui_Back3, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_Back3, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_Back3, -4 );
lv_obj_set_y( ui_Back3, 51 );
lv_obj_set_align( ui_Back3, LV_ALIGN_CENTER );
lv_label_set_text(ui_Back3,"Back");
lv_obj_set_style_text_color(ui_Back3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_text_opa(ui_Back3, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_align(ui_Back3, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_Back3, &ui_font_verdana244, LV_PART_MAIN| LV_STATE_DEFAULT);

}