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
#include "singleMotor.h"

#include <functional>

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen
vex::brain Brain;

// define your global instances of motors and other devices here

controller mainController = controller(primary);

DriveTrain Drive = DriveTrain(PORT1, PORT2);

SingleMotor arm(PORT3);

SingleMotor pusher(PORT8);


void Move()
{
    Drive.TwoDDrive(mainController.Axis3.position(), mainController.Axis4.position());
}

int main() {

    Brain.Screen.printAt( 10, 50, "Hello V5" );
    
    mainController.Axis3.changed(Move);
    mainController.Axis4.changed(Move);

    mainController.ButtonL1.pressed([](){arm.spin(forward);});
    mainController.ButtonL2.pressed([](){arm.spin(reverse);});
    mainController.ButtonL1.released([](){arm.stopSpinning();});
    mainController.ButtonL2.released([](){arm.stopSpinning();});

    while(true) {
        Brain.Screen.setCursor(0, 0);
        Brain.Screen.clearScreen();
//        this_thread::sleep_for(15);
    }
}
