#pragma once

#include <iostream>

#include "LinkablePart.hpp"
#include "Brake.hpp"
#include "Wheel.hpp"

class BrakeController : public LinkablePart {

    public:

        BrakeController(Wheel wheels[2]) {
            std::cout << "[BRAKE-CONTROLLER] - constructor called\n";
            this->_brakes[0].attackWheel(&wheels[0]);
            this->_brakes[1].attackWheel(&wheels[1]);
            std::cout << *this;
        }
        
        void execute(float pression) {
            this->_brakes[0].execute(pression);
            this->_brakes[1].execute(pression);
        }
        friend std::ostream& operator << (std::ostream& os, const BrakeController& BrakeController);

    private:
        
        Brake _brakes[2];

};

std::ostream& operator << (std::ostream& os, const BrakeController& brakecontroller) {
    os << "[BRAKE-CONTROLLER]:";
    os << "\n\tbrake[0]: " << brakecontroller._brakes[0];
    os << "\n\tbrake[1]: " << brakecontroller._brakes[1];
    return os;
}