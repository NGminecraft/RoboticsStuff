#include "vex.h"
#include "driveTrain.h"

using namespace vex;


    // Constructors and their overloads
DriveTrain::DriveTrain() : 
        lm(motor(PORT1)), rm(motor(PORT2)),
        DriveTrainObj(lm, rm, circumference, trackWidth, wheelBase)
        {}
DriveTrain::DriveTrain(int leftMotor, int rightMotor) : 
        lm(motor(leftMotor)), rm(motor(rightMotor)),
        DriveTrainObj(lm, rm, circumference, trackWidth, wheelBase)
        {
                lm = motor(leftMotor, true);
                rm = motor(rightMotor, true);
                updateDrivetrain();
}
DriveTrain::DriveTrain(motor leftMotor, motor rightMotor) : 
        lm(motor(PORT1)), rm(motor(PORT2)),
        DriveTrainObj(leftMotor, rightMotor, circumference, trackWidth, wheelBase)
        {
                lm = leftMotor;
                rm = rightMotor;
                updateDrivetrain();
        }

void DriveTrain::updateDrivetrain() 
        {
        DriveTrainObj = drivetrain(lm, rm, circumference, trackWidth, wheelBase);
        }