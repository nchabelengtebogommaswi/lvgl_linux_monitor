#include <memory>
#include <iostream>
#include <exception>

#include "ui/UIManager.h"
#include "runtime/LvglRunTime.h"
#include "ui/screens/CoordinateScreen.h"

int main(){

    try{

        LvglRunTime runtime;
        runtime.initialize();

        UIManager uiManager;
        uiManager.showScreen(std::make_unique<CoordinateScreen>());

        runtime.run();
    }
    catch (const std::exception& exception){
        std::cerr << "Application error: " << exception.what() << '\n';
        return 1;
    }

    return 0;
}