#include "Shovel.hpp"
#include "Worker.hpp"

Shovel::Shovel() : _numberOfUses(0), _owner(NULL) {
    std::cout << "[SHOVEL] - constructor called\n";
    std::cout << *this << std::endl;
}

Shovel::~Shovel() {
    std::cout << "[SHOVEL] - destructor called\n";
}

void Shovel::own(Worker *worker) {

    std::cout << "[SHOVEL] - owned!\n";
    if (this->_owner) {
        std::cout << "[SHOVEL] - " << this->_owner->get_name() << " lost owne\n";
        this->_owner->unequip_tool();
    }

    this->_owner = worker;

}

void Shovel::use() {
    std::cout << "[SHOVEL] - used\n";
    this->_numberOfUses++;
}

int Shovel::get_number_of_uses() const {
    return this->_numberOfUses;
}

std::ostream& operator << (std::ostream& os, const Shovel& shovel) {
    os << "[SHOVEL] - number of uses: " << shovel.get_number_of_uses();
    return os;
}