#pragma once

#include <lvgl/lvgl.h>
#include "ui/IScreen.h"

class CoordinateScreen : public IScreen{
public:

    void create(lv_obj_t* parentScreen) override;

private:

    lv_obj_t* m_panel = nullptr;
    lv_obj_t* m_titleLabel = nullptr;
    lv_obj_t* m_button = nullptr;
    lv_obj_t* m_buttonLabel = nullptr;
};
