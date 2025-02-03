#pragma once

#include "vex.h"
#include "string.h"

using namespace vex;


class SingleMotor {
    public:
        SingleMotor(const char* ID, motor motor);
        SingleMotor(const char* ID, int motorPort);

        void spin(directionType direction);

        void spin(double velocity);

        void goToPos(int pos);

        void stopSpinning();

        void setVelocity(double velocity);

        double getAngle();

        void reset();

    
    private:
        motor ThisMotor;

        double velocity;

        void checkTemps();

};