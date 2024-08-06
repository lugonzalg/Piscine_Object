#pragma once

#include <iostream>

#include "Transmission.hpp"

class CrankShaft {

    public:

        CrankShaft(Transmission* t) : _trms(t) {
            std::cout << "[CRANK-SHAFT] - constructor called\n";
            std::cout << *this;
        }

        ~CrankShaft() {
            std::cout << "[CRANK-SHAFT] - destructor called\n";
        }

        void set_transmission(Transmission* t) {
            this->_trms = t;
        }
        
        void receiveForce(float force) {
            std::cout << "[CRANK-SHAFT] - Applying force of: " << force << " to transmission\n";
            this->_trms->activate(force);
        }

        friend std::ostream& operator << (std::ostream& os, const CrankShaft& cs) {
            os << "[CRANK-SHAFT]:\n   + ";
            if (cs._trms == NULL) {
                os << "[TRANSMISSION]: No connection\n";
                return os;
            }
            os << *cs._trms << std::endl;
            return os;
        }

    private:

        Transmission* _trms;

};