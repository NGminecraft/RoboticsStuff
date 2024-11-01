#include "ControllerTerminal.h"

#include <string>


void ControllerTerminal::PrintMessage(string msg)
{
    if (Controller.Screen.row() >= rows)
    {
        Controller.Screen.clearScreen();
        Controller.Screen.setCursor(1, 1);
    }
    Controller.Screen.print(msg);
    Controller.Screen.newLine();
}