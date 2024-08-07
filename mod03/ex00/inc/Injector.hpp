#pragma once

#include <iostream>

#include "LinkablePart.hpp"
#include "ExplosionChamber.hpp"

class Injector : public LinkablePart {

    public:

        Injector(ExplosionChamber* ec) : _epscmbr(ec) {
            std::cout << "[INJECTOR] - constructor called\n";
            std::cout << *this;
        }

        ~Injector() {
            std::cout << "[INJECTOR] - destructor called\n";
        }

        friend std::ostream& operator << (std::ostream& os, const Injector& injector) {
            os << "[INJECTOR]:\n   + ";
            os << *injector._epscmbr;
            return os;
        }

        void execute(float pression) {

            float fuel;

            if (this->_epscmbr == NULL)
                return ;

            fuel = pression * 0.77f;
            this->_epscmbr->fill(fuel);
        }

    private:
        ExplosionChamber* _epscmbr;
};