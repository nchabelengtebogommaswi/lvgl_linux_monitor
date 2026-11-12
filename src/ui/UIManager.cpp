#include "ui/UIManager.h"

#include <stdexcept>
#include <utility>

void UIManager::showScreen(std::unique_ptr<IScreen> screen){

    if (screen == nullptr){
        throw std::invalid_argument("Cannot display an empty screen");
    }

    m_screen = std::move(screen);
    m_screen->create(lv_screen_active());
}