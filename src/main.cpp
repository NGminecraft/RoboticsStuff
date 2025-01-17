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

vision::signature jacket(1, -3031, -2535, -2783, 8759, 10083, 2504821, 2.5, 0); // Got using vision.vexcode.cloud

// define your global instances of motors and other devices here

controller mainController = controller(primary);

DriveTrain Drive = DriveTrain(PORT1, PORT2);

SingleMotor arm("Arm-A", PORT3);

SingleMotor pusher("Arm-D", PORT8);

SingleMotor arm2("Arm-B", PORT10);
SingleMotor arm3("Arm-C", PORT6);

void Move()
{
    Drive.TwoDDrive(mainController.Axis3.position(), mainController.Axis4.position());
}

int main() {

    arm2.setVelocity(15);
    arm3.setVelocity(15);

    Brain.Screen.printAt( 10, 50, "Hello V5" );
    
    mainController.Axis3.changed(Move);
    mainController.Axis4.changed(Move);

    mainController.ButtonL1.pressed([](){arm.spin(forward);});
    mainController.ButtonL2.pressed([](){arm.spin(reverse);});
    mainController.ButtonL1.released([](){arm.stopSpinning();});
    mainController.ButtonL2.released([](){arm.stopSpinning();});

    
    mainController.ButtonR1.pressed([](){arm2.spin(forward);});
    mainController.ButtonR2.pressed([](){arm2.spin(reverse);});
    mainController.ButtonR1.released([](){arm2.stopSpinning();});
    mainController.ButtonR2.released([](){arm2.stopSpinning();});


    mainController.ButtonB.pressed([](){pusher.spin(forward);});
    mainController.ButtonB.released([](){pusher.stopSpinning();});
    mainController.ButtonX.pressed([](){pusher.spin(reverse);});
    mainController.ButtonX.released([](){pusher.stopSpinning();});

    
    mainController.ButtonY.pressed([](){arm3.spin(forward);});
    mainController.ButtonY.released([](){arm3.stopSpinning();});
    mainController.ButtonA.pressed([](){arm3.spin(reverse);});
    mainController.ButtonA.released([](){arm3.stopSpinning();});

    while(true) {
        Brain.Screen.printAt(10, 50, "%f, %f", mainController.Axis3.position(), mainController.Axis4.position());
        printf("%ld, %ld\n", mainController.Axis3.position(), mainController.Axis4.position());
        Brain.Screen.clearScreen();
        this_thread::sleep_for(15);
    }
}
