#pragma once

#include "vex.h"
#include <string>

using namespace vex;
using namespace std;

class ControllerTerminal{
    public:
        controller Controller;
        int rows = 5;
        int columns = 16;
        void PrintMessage(string message);
};