#pragma once

#include <lvgl/lvgl.h>

class IScreen {
    public:
        virtual ~IScreen() = default;
        virtual void create(lv_obj_t* parentScreen) = 0;
};
