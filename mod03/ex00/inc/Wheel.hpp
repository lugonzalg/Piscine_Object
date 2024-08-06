#pragma once

#include <iostream>
#include <string>

struct Wheel {

    public:

        Wheel() : _speed(0.0f) {
            std::cout << "[WHEEL] - constructor called\n";
            std::cout << *this;
        }
        ~Wheel() {
            std::cout << "[WHEEL] - destructor called\n";
        }

        void executeRotation(float force) {
            std::cout << *this;
            this->_speed += force;
            std::cout << "[WHEEL] - executing rotation: with a force of: " << force << std::endl;
            std::cout << *this;
        }
        friend std::ostream& operator << (std::ostream& os, const Wheel& wheel) {
            os << "[WHEEL] - speed: " << wheel._speed << std::endl;
            return os;
        }

    private:
        float       _speed;
};