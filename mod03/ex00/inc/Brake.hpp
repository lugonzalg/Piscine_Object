#pragma once

#include <iostream>

#include "Wheel.hpp"

class Brake {

    public:

        Brake() : _wheel(NULL) {
            std::cout << "[BRAKE] - constructor called\n";
            std::cout << *this;
        }

        void execute(float force) {
            this->_wheel->executeRotation(force);
        }

        void attackWheel(Wheel *wheel) {
            this->_wheel = wheel;
        }

        friend std::ostream& operator <<(std::ostream& os, const Brake& brake) {
            os << "[BRAKE]:";
            os << "\n\tattached wheel: " << brake._wheel << std::endl;
            return os;
        }

    private:
        Wheel* _wheel;

};