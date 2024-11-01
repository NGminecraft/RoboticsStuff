#pragma once

#include "vex.h"

using namespace vex;

class DriveTrain{
    public:
        DriveTrain();
        DriveTrain(int lm, int rm);
        DriveTrain(motor lm, motor rm);

        void updateDrivetrain();
    private:
        motor lm = motor(PORT1, false);
        motor rm = motor(PORT2, false);

        float circumference = 638.37058f;
        float trackWidth = 342.9f; // distance between each wheel l/r
        float wheelBase = 266.7f;

        drivetrain DriveTrainObj;
};