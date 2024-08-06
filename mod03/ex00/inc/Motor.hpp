#pragma once

#include <iostream>

#include "Injector.hpp"
#include "ExplosionChamber.hpp"
#include "CrankShaft.hpp"
#include "Transmission.hpp"

class Car;

class Motor {

    private:

        CrankShaft _crankshaft;
        ExplosionChamber _explosionchamber;

    public:

        Injector injector;

        Motor() : _crankshaft(NULL), _explosionchamber(&_crankshaft), injector(&_explosionchamber) {
            std::cout << "[MOTOR] - constructor called\n";
        }

        ~Motor() {
            std::cout << "[MOTOR] - destructor called\n";
        }
        
        void connectToTransmission(Transmission* t) {

            if (t)
                std::cout << "[MOTOR] - transmission connected to Crankshaft\n";
            else
                std::cout << "[MOTOR] - transmission disconnected from Crankshaft\n";

            this->_crankshaft.set_transmission(t);
        }

        friend std::ostream& operator << (std::ostream& os, const Motor& motor) {
            os << "[MOTOR]:\n   + ";
            os << motor._crankshaft;
            os << "\n   + " << motor._explosionchamber;
            os << "\n   + " << motor.injector;
            return os;
        }

        friend Car;


};