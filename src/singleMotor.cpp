#include "singleMotor.h"

SingleMotor::SingleMotor(motor Motor) : ThisMotor(Motor) {
    ThisMotor.setStopping(brakeType::hold);
    ThisMotor.setVelocity(30, percent);
}
SingleMotor::SingleMotor(int Motor) : ThisMotor(motor(Motor)) {
    ThisMotor.setStopping(brakeType::hold);
    ThisMotor.setVelocity(30, percent);
}

void SingleMotor::spin(directionType direction = forward){
    ThisMotor.spin(direction);
}

void SingleMotor::spin(double velocity) {ThisMotor.spin(vex::forward, velocity, rpm);}

void SingleMotor::stopSpinning() {
    ThisMotor.stop();
}