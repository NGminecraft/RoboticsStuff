#include "singleMotor.h"
#include "string.h"

SingleMotor::SingleMotor(const char* ID, motor Motor) : ThisMotor(Motor), velocity(30){
    ThisMotor.setStopping(brakeType::hold);
}
SingleMotor::SingleMotor(const char* ID, int Motor) : ThisMotor(motor(Motor)), velocity(30) {
    ThisMotor.setStopping(brakeType::hold);
}

void SingleMotor::spin(directionType direction = forward){
    ThisMotor.spin(direction);
}

void SingleMotor::spin(double velocity) {ThisMotor.spin(vex::forward, velocity, rpm);}

void SingleMotor::stopSpinning() {
    ThisMotor.stop();
}

void SingleMotor::bindToKeybind(controller::button forwardButton, controller::button backwardButton){
    

}

void SingleMotor::setVelocity(double velocity) {
    ThisMotor.setVelocity(velocity, percent);
}

void SingleMotor::checkTemps(){
    if (ThisMotor.temperature() > 40){

        setVelocity(velocity*(ThisMotor.temperature()/50));
    }
}
