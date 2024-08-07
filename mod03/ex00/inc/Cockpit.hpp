#pragma once

#include <iostream>

#include "Pedal.hpp"
#include "GearLever.hpp"
#include "SteerWheel.hpp"
#include "Electronics.hpp"

class CockPit {

    public:

        Pedal pedal;

        CockPit(DAE* dae) : _steerwheel(dae) {
            std::cout << "[COCK-PIT] - constructor called\n";
        }

        ~CockPit() {
            std::cout << "[COCK-PIT] - destructor called\n";
        }

        void shift_gears_up() {
            std::cout << "[COCKPIT] - shift gears up\n";
            this->_gearlever.change(GearLever::UP);
        }

        void shift_gears_down() {
            std::cout << "[COCKPIT] - shift gears down\n";
            this->_gearlever.change(GearLever::DOWN);
        }

        void reverse() {
            std::cout << "[COCKPIT] - shift gears to reverse\n";
            this->_gearlever.change(GearLever::REVERSE);
        }

        void turn_wheel(float angle) {
            std::cout << "[COCKPIT] - turn with an angle of: " << angle << std::endl;
            this->_steerwheel.turn(angle);
        }

        friend std::ostream& operator << (std::ostream& os, const CockPit& cp) {
            (void)cp;
            os << "[COCKPIT]:";
            return os;
        }

    private:

        GearLever _gearlever;
        SteerWheel _steerwheel;
};