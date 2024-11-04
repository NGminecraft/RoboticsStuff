#pragma once

#include "vex.h"


using namespace vex;

class ControllerTerminal{
    public:
        ControllerTerminal(controller NewController);
        
        void PrintMessage(const char* message);

    private:
        controller Controller;
};