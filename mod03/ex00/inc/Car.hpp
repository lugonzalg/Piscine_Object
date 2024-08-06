#pragma once

#include <iostream>

#include "Direction.hpp"
#include "BrakeController.hpp"
#include "Motor.hpp"
#include "Transmission.hpp"
#include "Cockpit.hpp"
#include "Electronics.hpp"
#include "BrakeController.hpp"

class Car {

    public:

        static float CENTER_DIRECTION;
        static float EMERGENCY_STOP;

        Car() : _transmission(_direction._wheels), _cockpit(&_electronics.dae), _brakecontroller(_direction._wheels) {
            std::cout << "[CAR] - constructor called\n";
            std::cout << *this;
        }

        ~Car() {
            std::cout << "[CAR] - destructor called\n";
        }

        void start() {
            std::cout << "[CAR] - starting motor\n";
            this->_motor.connectToTransmission(&this->_transmission);
        }

        void stop() {
            std::cout << "[CAR] - stopping motor\n";
            this->_motor.connectToTransmission(NULL);
        }

        void accelerate(float speed) {
            std::cout << "[CAR] - accelerating\n";
            this->_cockpit.pedal.setTarget(&this->_motor.injector);
            this->_cockpit.pedal.use(speed);
        }

        void shift_gears_up() {
            std::cout << "[CAR] - shift gears down\n";
            this->_cockpit.shift_gears_up();
        }

        void reverse() {
            std::cout << "[CAR] - shift gears to reverse\n";
            this->_cockpit.reverse();
        }

        void shift_gears_down() {
            std::cout << "[CAR] - shift gears down\n";
            this->_cockpit.shift_gears_down();
        }

        void turn_wheel(float angle) {
            std::cout << "[CAR] - turn with an angle of: " << angle << std::endl;
            this->_cockpit.turn_wheel(angle);
        }

        void straighten_wheels() {
            std::cout << "[CAR] - turn with an angle of: 0.0f\n";
            this->_cockpit.turn_wheel(Car::CENTER_DIRECTION);

        }

        void apply_force_on_brakes(float force) {
            std::cout << "[CAR] - apply force of: " << force << " on brakes\n";
            this->_cockpit.pedal.setTarget(&this->_brakecontroller);
            this->_cockpit.pedal.use(force);
        }

        void apply_emergency_brakes() {
            std::cout << "[CAR] - apply EMERGENCY force of: " << Car::EMERGENCY_STOP << " on brakes\n";
            this->_cockpit.pedal.setTarget(&this->_brakecontroller);
            this->_cockpit.pedal.use(Car::EMERGENCY_STOP);
        }

        friend std::ostream& operator << (std::ostream& os, const Car& car) {
            os << "[CAR]:\n   + ";
            os << car._direction;
            os << car._transmission;
            os << car._motor;
            return os;
        }

    private:

        Direction _direction;
        Transmission _transmission;
        Motor _motor;
        Electronics _electronics;
        CockPit _cockpit;
        BrakeController _brakecontroller;

};

float Car::CENTER_DIRECTION = 0.0f;
float Car::EMERGENCY_STOP = 100.0f;