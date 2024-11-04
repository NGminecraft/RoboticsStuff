#include "ControllerTerminal.h"


using namespace vex;


ControllerTerminal::ControllerTerminal(controller NewController) : Controller(NewController) {}

void ControllerTerminal::PrintMessage(const char* msg)
{
    Controller.Screen.clearLine(1);
    Controller.Screen.print(msg);
}
