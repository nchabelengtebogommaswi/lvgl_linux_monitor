#pragma once
#include <lvgl/api_map/lv_api_map_v8.h>

class LvglRunTime {
public:
    LvglRunTime() = default;
    ~LvglRunTime();
    void initialize();
    void run();
    void stop();

private:
    lv_disp_t* m_mainWindow = nullptr;
    bool m_initialized = false;
};
