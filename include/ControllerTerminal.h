#pragma once

#include "vex.h"
#include <string>


using namespace vex;

class ControllerTerminal{
    public:
        ControllerTerminal(controller NewController);
        int rows = 5;
        int columns = 16;
        void PrintMessage(const char* message);

    private:
        controller Controller;
};