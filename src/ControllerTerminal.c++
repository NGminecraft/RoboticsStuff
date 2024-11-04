#include "ControllerTerminal.h"

#include <string>

using namespace vex;


ControllerTerminal::ControllerTerminal(controller NewController) : Controller(NewController) {}

void ControllerTerminal::PrintMessage(const char* msg)
{
    if (Controller.Screen.row() >= rows)
    {
        Controller.Screen.clearScreen();
        Controller.Screen.setCursor(1, 1);
    }
    Controller.Screen.print(msg);
    Controller.Screen.newLine();
}