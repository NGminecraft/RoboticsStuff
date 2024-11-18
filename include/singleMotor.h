#pragma once

#include "vex.h"

using namespace vex;

class SingleMotor {
    public:
        SingleMotor(motor motor);
        SingleMotor(int motorPort);

        double targetPos;

        void spin();

        void spin(double velocity);

        void goToPos(int pos);

        void holdPos();

        void stopSpinning(bool hold);
    
    private:
        motor ThisMotor;
        void spinAsync(directionType, double velocity);

        void startThread();
        
        void asyncHoldPos();

        bool holding;
};