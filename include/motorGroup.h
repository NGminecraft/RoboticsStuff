#pragma once

#include "vex.h"
#include "singleMotor.h"
#include <vector>

class MotorGroup{
public:
    MotorGroup();

    double getFullX();
    double getFullY(); 
    void AddMotor(SingleMotor* Motor, double Length);

private:
    std::vector<SingleMotor*> AllMotors;
    std::vector<double> AllSizes;
};