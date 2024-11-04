#include "vex.h"
#include "driveTrain.h"

using namespace vex;

motor motor1 = motor(PORT1, true);
motor motor2 = motor(PORT2, true);

drivetrain DriveTrainObj = drivetrain(motor1, motor2, 638.37058, 342.9, 266.7); 

    // Constructors and their overloads
DriveTrain::DriveTrain() : 
        lm(motor(PORT1)), rm(motor(PORT2))
        {}
DriveTrain::DriveTrain(int leftMotor, int rightMotor) : 
        lm(motor(PORT1)), rm(motor(PORT2))
        {
                lm = motor(leftMotor, true);
                rm = motor(rightMotor, true);
                updateDrivetrain();
}
DriveTrain::DriveTrain(motor leftMotor, motor rightMotor) : 
        lm(motor(PORT1)), rm(motor(PORT2))
        {
                lm = leftMotor;
                rm = rightMotor;
                updateDrivetrain();
        }

void DriveTrain::updateDrivetrain() 
        {
        DriveTrainObj = drivetrain(lm, rm, circumference, trackWidth, wheelBase);
        }