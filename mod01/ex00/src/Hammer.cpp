#include "Hammer.hpp"
#include "Worker.hpp"

Hammer::Hammer() : _numberOfUses(0), _owner(NULL) {
    std::cout << "[HAMMER] - constructor called\n";
    std::cout << *this << std::endl;
}

Hammer::~Hammer() {
    std::cout << "[HAMMER] - destructor called\n";
}

void Hammer::own(Worker *worker) {

    std::cout << "[HAMMER] - owned!\n";
    if (this->_owner) {
        std::cout << "[HAMMER] - " << this->_owner->get_name() << " lost owne\n";
        this->_owner->unequip_tool();
    }

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
    os << "[HAMMER] - number of uses: " << hammer.get_number_of_uses();
    return os;
}