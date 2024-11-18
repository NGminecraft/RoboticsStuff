#include "singleMotor.h"

void SingleMotor::startThread(){
}

SingleMotor::SingleMotor(motor Motor) : ThisMotor(Motor), targetPos(125) {
    
}
SingleMotor::SingleMotor(int Motor) : ThisMotor(Motor), targetPos(125) {}

void SingleMotor::spin(){printf("Moving the motor\n"); ThisMotor.spin(reverse, 200, rpm);}

void SingleMotor::spin(double velocity) {ThisMotor.spin(vex::forward, velocity, rpm);}

void SingleMotor::stopSpinning(bool hold = true) {
    ThisMotor.stop();
    targetPos = ThisMotor.position(degrees);
    holding = hold;
}

void SingleMotor::asyncHoldPos(){
    while (true) {
        if (holding && not ThisMotor.isSpinning()){
            ThisMotor.spinTo(targetPos, degrees);
            wait(10, msec);
        }
    }
}