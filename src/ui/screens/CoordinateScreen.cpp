#include "ui/screens/CoordinateScreen.h"

void CoordinateScreen::create(lv_obj_t* parentScreen){

    lv_obj_set_style_bg_color(parentScreen, lv_color_hex(0x101820), LV_PART_MAIN);

    m_panel = lv_obj_create(parentScreen);
    lv_obj_set_pos(m_panel, 100, 50);
    lv_obj_set_size(m_panel, 400, 300);
    lv_obj_set_style_bg_color(m_panel, lv_color_hex(0x26394F), LV_PART_MAIN);
    lv_obj_set_style_radius(m_panel,12,LV_PART_MAIN);
    lv_obj_set_style_pad_all(m_panel,0,LV_PART_MAIN);

    m_titleLabel = lv_label_create(m_panel);
    lv_label_set_text(m_titleLabel,"My First LVGL Application");
    lv_obj_set_pos(m_titleLabel,20,20);

    m_button = lv_button_create(m_panel);
    lv_obj_set_pos(m_button,30,80);
    lv_obj_set_size(m_button, 150,60);

    m_buttonLabel = lv_label_create(m_button);
    lv_label_set_text(m_buttonLabel,"Click Me");
    lv_obj_center(m_buttonLabel);
}