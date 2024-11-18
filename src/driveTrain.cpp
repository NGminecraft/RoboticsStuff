#include "vex.h"
#include "driveTrain.h"

using namespace vex;


    // Constructors and their overloads
DriveTrain::DriveTrain() : 
    lm(motor(PORT1, ratio18_1, true)), rm(motor(PORT2, ratio18_1)),
    DriveTrainObj(lm, rm, circumference, trackWidth, wheelBase),
    maxRPM(200)
    {}
DriveTrain::DriveTrain(int leftMotor, int rightMotor) : 
    lm(motor(leftMotor, ratio18_1, true)), rm(motor(rightMotor, ratio18_1)),
    DriveTrainObj(lm, rm, circumference, trackWidth, wheelBase),
    maxRPM(200)
    {
        lm = motor(leftMotor, true);
        rm = motor(rightMotor, true);
        updateDrivetrain();
}
DriveTrain::DriveTrain(motor leftMotor, motor rightMotor) : 
    lm(motor(PORT1, ratio18_1, true)), rm(motor(PORT2, ratio18_1)),
    DriveTrainObj(leftMotor, rightMotor, circumference, trackWidth, wheelBase),
    maxRPM(200)
    {
        lm = leftMotor;
        rm = rightMotor;
        updateDrivetrain();
    }

void DriveTrain::updateDrivetrain() 
{
    DriveTrainObj = drivetrain(lm, rm, circumference, trackWidth, wheelBase);
}

void DriveTrain::DrivePercent(double percent)
{
    DriveTrainObj.drive(forward, (percent/100)*maxRPM, rpm);
}

void DriveTrain::TwoDDrive(double X, double Y)
{
    if (abs(X) <= 15 && abs(Y)<= 15){
        X = 0;
        Y = 0;
    }

    X = -X;
    Y = -Y;

    lm.spin(forward, (Y+X)/100*maxRPM, rpm);
    rm.spin(forward, (Y-X)/100*maxRPM, rpm);
}