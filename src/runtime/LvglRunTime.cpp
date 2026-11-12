#include <chrono>
#include <thread>
#include <csignal>
#include <stdexcept>
#include "runtime/LvglRunTime.h"

#include <lvgl/core/lv_init.h>
#include <lvgl/drivers/sdl/lv_sdl_window.h>

namespace {
    volatile std::sig_atomic_t applicationRunningSignal = 1;

    void handleSignal(int p_signal) {
        applicationRunningSignal = 0;
    }
}

LvglRunTime::~LvglRunTime() {
    stop();
}

void LvglRunTime::initialize() {
    if (m_initialized) {
        return;
    }

    lv_init();
    m_mainWindow = lv_sdl_window_create(800, 480);

    if (m_mainWindow == nullptr) {
        throw std::runtime_error("failed to create lvgl sdl2 window");
    }

    std::signal(SIGINT, handleSignal);
    m_initialized = true;
}

void LvglRunTime::run() {
    if (!m_initialized) {
        throw std::runtime_error("lvgl runtime has not been initialized");
    }

    applicationRunningSignal = 1;
    while (applicationRunningSignal != 0) {
        lv_timer_handler();
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
}

void LvglRunTime::stop() {
    applicationRunningSignal = 0;
}