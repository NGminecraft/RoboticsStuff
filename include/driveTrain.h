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
        motor lm;
        motor rm;

        float circumference;
        float trackWidth; // distance between each wheel l/r
        float wheelBase;
};