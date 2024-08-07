#include "rectangle.hpp"
#include "triangle.hpp"
#include "circle.hpp"

float get_area(const Shape& shape) {
    return shape.area();
}

float get_perimeter(const Shape& shape) {
    return shape.perimeter();
}

int main() {
    Rectangle rectangle(1.0f, 2.0f);
    Triangle triangle(4.0f, 4.0f, 5.0f);
    Circle circle(1.0f);

    std::cout << "Area: " << get_area(rectangle) << std::endl;
    std::cout << "Perimeter: " << get_perimeter(rectangle) << std::endl;

    std::cout << "Area: " << get_area(triangle) << std::endl;
    std::cout << "Perimeter: " << get_perimeter(triangle) << std::endl;

    std::cout << "Area: " << get_area(circle) << std::endl;
    std::cout << "Perimeter: " << get_perimeter(circle) << std::endl;
    return 0;
}