/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       minec                                                     */
/*    Created:      10/30/2024, 1:18:59 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "driveTrain.h"
#include "ControllerTerminal.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;

// define your global instances of motors and other devices here

controller mainController = controller();

DriveTrain Drive = DriveTrain(PORT1, PORT2);

ControllerTerminal OUT_controller = ControllerTerminal(mainController);


int main() {

    Brain.Screen.printAt( 10, 50, "Hello V5" );
    
    OUT_controller.PrintMessage("Hello Controller!");
    

    while(1) {
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}
