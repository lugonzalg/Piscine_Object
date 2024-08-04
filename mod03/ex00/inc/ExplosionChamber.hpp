#pragma once

#include <iostream>

#include "CrankShaft.hpp"

class ExplosionChamber {
    public:
        ExplosionChamber(CrankShaft* c) : _cksf(c) {
            std::cout << "[EXPLOSION-CHAMBER] - constructor called\n";
            std::cout << *this;
        }   

        ~ExplosionChamber() {
            std::cout << "[EXPLOSION-CHAMBER] - destructor called\n";
        }

        void fill(float volume) {

            float force;

            std::cout << "[EXPLOSION-CHAMBER] - filling the chamber with a volume of: " << volume << std::endl;
            force = volume * 0.88f;
            std::cout << "[EXPLOSION-CHAMBER] - creating a force of: " << force << " from volume: " << volume << std::endl;
            this->_cksf->receiveForce(force);
        }

        friend std::ostream& operator << (std::ostream& os, const ExplosionChamber& ec) {
            os << "[EXPLOSION-CHAMBER]:\n   + ";
            os << *ec._cksf;
            return os;
        }


    private:
        CrankShaft* _cksf;
};