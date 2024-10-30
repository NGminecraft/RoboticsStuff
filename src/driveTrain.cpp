#include "vex.h"
#include "driveTrain.h"

using namespace vex;

    // Constructors and their overloads
DriveTrain::DriveTrain() {
        lm = motor(PORT1, true);
        rm = motor(PORT2, true);
        updateDrivetrain();
}
DriveTrain::DriveTrain(int leftMotor, int rightMotor) {
        lm = motor(leftMotor, true);
        rm = motor(rightMotor, true);
        updateDrivetrain();
}
DriveTrain::DriveTrain(motor leftMotor, motor rightMotor) {
        lm = leftMotor;
        rm = rightMotor;
        updateDrivetrain();
}

void DriveTrain::updateDrivetrain() {DriveTrainObj = drivetrain(lm, rm, circumference, trackWidth, wheelBase);}