#include "Hammer.hpp"
#include "Worker.hpp"

Hammer::Hammer() : _numberOfUses(0), _owner(NULL) {
    std::cout << "Hammer constructor called\n";
}

Hammer::~Hammer() {
    std::cout << "Hammer destructor called\n";
}

void Hammer::own(Worker *worker) {

    if (this->_owner)
        this->_owner->unequip_tool();

    std::cout << "[HAMMER] - owned!\n";
    this->_owner = worker;

}

void Hammer::use() {
    std::cout << "[HAMMER] - used\n";
    this->_numberOfUses++;
}

int Hammer::get_number_of_uses() const {
    return this->_numberOfUses;
}

std::ostream& operator << (std::ostream& os, const Hammer& hammer) {
    os << "number of uses: " << hammer.get_number_of_uses() << std::endl;
    return os;
}