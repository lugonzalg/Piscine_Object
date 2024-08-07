#pragma once

#include <iostream>
#include <vector>

#include "Wheel.hpp"

class Car;

class Transmission {

    public:

        Transmission(Wheel wheels[2]) {

            std::cout << "[TRANSMISSION] - constructor called\n";
            std::cout << "[TRANSMISSION] - adding wheels\n";
            for (size_t idx = 0; idx < 2; idx++) {

                this->_wheels.push_back(&wheels[idx]);
                std::cout << "[TRANSMISSION] - new wheel added: " << wheels[idx];
            }
            std::cout << *this;
        }

        ~Transmission() {
            std::cout << "[TRANSMISSION] - destructor called\n";
        }

        void activate(float force) {
            std::vector<Wheel *>::iterator it;

            std::cout << "[TRANSMISSION] - Applying force of: " << force << " to:\n";
            it = this->_wheels.begin();
            for (; it != this->_wheels.end(); it++)
                (*it)->executeRotation(force);
        }

        friend std::ostream& operator << (std::ostream& os, const Transmission& t) {
            std::vector<Wheel *>::const_iterator cit;

            cit = t._wheels.begin();
            os << "[TRANSMISSION]:\n";
            for (; cit != t._wheels.end(); cit++)
                std::cout << "   + " << (**cit);
            return os;
        }

        friend Car;

    private:
        std::vector<Wheel *> _wheels;

};