#pragma once

#include "vex.h"

using namespace vex;

class DriveTrain{
    public:
        DriveTrain();
        DriveTrain(int lm, int rm);
        DriveTrain(motor lm, motor rm);

        void updateDrivetrain();
        void DrivePercent(double percent);
        void TwoDDrive(double percentX, double percentY);
    private:
        motor lm;
        motor rm;

        float circumference = 638.37058;
        float trackWidth = 342.9; // distance between each wheel l/r
        float wheelBase = 266.7;

        drivetrain DriveTrainObj;

        int maxRPM = 200;

};