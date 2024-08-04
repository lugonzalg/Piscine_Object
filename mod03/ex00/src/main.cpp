#include "Car.hpp"

int main() {

    Car car;

    std::cout << "--------------------PROGRAM----------------\n";
    // TODO start SEGFAULT stop
    car.start();
    car.accelerate(10.0f);
    car.shift_gears_up();
    car.shift_gears_down();
    car.turn_wheel(0.1f);
    car.straighten_wheels();
    car.apply_force_on_brakes(0.1f);
    car.apply_emergency_brakes();
    car.stop();
    std::cout << "----------------------END------------------\n";
    return 0;
}