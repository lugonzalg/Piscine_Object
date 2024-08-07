#include "rectangle.hpp"

float get_area(const Shape& shape) {
    return shape.area();
}

float get_perimeter(const Shape& shape) {
    return shape.perimeter();
}

int main() {
    Rectangle rectangle(1.0f, 2.0f);

    std::cout << "Area: " << get_area(rectangle) << std::endl;
    std::cout << "Perimeter: " << get_perimeter(rectangle) << std::endl;
    return 0;
}