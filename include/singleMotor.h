#pragma once

#include "vex.h"

using namespace vex;

class SingleMotor {
    public:
        SingleMotor(motor motor);
        SingleMotor(int motorPort);

        void spin(directionType direction);

        void spin(double velocity);

        void goToPos(int pos);

        void stopSpinning();
    
    private:
        motor ThisMotor;
        void spinAsync(directionType, double velocity);

        void startThread();

};