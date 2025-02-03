#include "motorGroup.h"

void MotorGroup::AddMotor(SingleMotor* Motor, double Length) {
    AllMotors.push_back(Motor);
    AllSizes.push_back(Length);
};

double MotorGroup::getFullX(){
    double current = 0;
    for (int i = 0; i < AllMotors.size(); i++)
    {
        current += cos(AllMotors[i]->getAngle())*AllSizes[i];
    }
    return current;
}


double MotorGroup::getFullY(){
    double current = 0;
    for (int i = 0; i < AllMotors.size(); i++)
    {
        current += sin(AllMotors[i]->getAngle())*AllSizes[i];
    }
    return current;
}

MotorGroup::MotorGroup() {

};