/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       minec                                                     */
/*    Created:      10/30/2024, 1:18:59 PM                                    */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"
#include "driveTrain.cpp"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain       Brain;

// define your global instances of motors and other devices here

DriveTrain Drive = DriveTrain(PORT1, PORT2);

int main() {

    Brain.Screen.printAt( 10, 50, "Hello V5" );

   
    while(1) {
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}
