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
#include "motorGroup.h"

#include <iostream>
#include <functional>
#include "main.h"

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

MotorGroup armMotors = MotorGroup();

bool debug = false;

void Move()
{
    Drive.TwoDDrive(mainController.Axis3.position(), mainController.Axis4.position());
}

void resetAll()
{
    arm.reset();
    arm2.reset();
    arm3.reset();
}

void Debug()
{
    mainController.ButtonA.pressed([]()
                                   { resetAll(); });
}

int main()
{
    arm2.setVelocity(15);
    arm3.setVelocity(15);

    armMotors.AddMotor(&arm, 6.75);
    armMotors.AddMotor(&arm2, 3.75);
    armMotors.AddMotor(&arm3, 9);

    Brain.Screen.printAt(10, 50, "Hello V5");

    Normal();

    while (true)
    {
        if (Brain.Screen.row() == 6)
        {
            Brain.Screen.clearScreen();
            
            Brain.Screen.setCursor(0, 0);
        }

        if (mainController.ButtonL1.PRESSED & mainController.ButtonL2.PRESSED)
        {
            if (mainController.ButtonR1.PRESSED & mainController.ButtonR2.PRESSED)
            {
                debug = !debug;
                if (debug)
                {
                    Debug();
                    mainController.Screen.print("DEBUG MODE");
                }
                else
                {
                    Normal();
                    mainController.Screen.print("Normal Mode");
                }
            }
        }

        Brain.Screen.print(armMotors.getFullX());
        Brain.Screen.print("\n");
        std::cout << armMotors.getFullX() << "\n";
        this_thread::sleep_for(100);
    }
}

void Normal()
{
    mainController.Axis3.changed(Move);
    mainController.Axis4.changed(Move);

    mainController.ButtonL1.pressed([]()
                                    { arm.spin(forward); });
    mainController.ButtonL2.pressed([]()
                                    { arm.spin(reverse); });
    mainController.ButtonL1.released([]()
                                     { arm.stopSpinning(); });
    mainController.ButtonL2.released([]()
                                     { arm.stopSpinning(); });

    mainController.ButtonR1.pressed([]()
                                    { arm2.spin(forward); });
    mainController.ButtonR2.pressed([]()
                                    { arm2.spin(reverse); });
    mainController.ButtonR1.released([]()
                                     { arm2.stopSpinning(); });
    mainController.ButtonR2.released([]()
                                     { arm2.stopSpinning(); });

    mainController.ButtonB.pressed([]()
                                   { pusher.spin(forward); });
    mainController.ButtonB.released([]()
                                    { pusher.stopSpinning(); });
    mainController.ButtonX.pressed([]()
                                   { pusher.spin(reverse); });
    mainController.ButtonX.released([]()
                                    { pusher.stopSpinning(); });

    mainController.ButtonY.pressed([]()
                                   { arm3.spin(forward); });
    mainController.ButtonY.released([]()
                                    { arm3.stopSpinning(); });
    mainController.ButtonA.pressed([]()
                                   { arm3.spin(reverse); });
    mainController.ButtonA.released([]()
                                    { arm3.stopSpinning(); });
}