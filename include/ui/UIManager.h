#pragma once
#include <memory>
#include "IScreen.h"

class UIManager {
public:
    void showScreen(std::unique_ptr<IScreen> screen);

private:
    std::unique_ptr<IScreen> m_screen;
};
