#include "Shovel.hpp"
#include "Worker.hpp"

Shovel::Shovel() : _numberOfUses(0), _owner(NULL) {
    std::cout << "Shovel constructor called\n";
}

Shovel::~Shovel() {
    std::cout << "Shovel destructor called\n";
}

void Shovel::own(Worker *worker) {

    if (this->_owner)
        this->_owner->unequip_shovel();

    this->_owner = worker;

}

bool Shovel::use() const {
    std::cout << "[SHOVEL] - used\n";
    this->_numberOfUses++;
}

int Shovel::get_number_of_uses() const {
    return this->_numberOfUses;
}

std::ostream& operator << (std::ostream& os, const Shovel& shovel) {
    os << "number of uses: " << shovel.get_number_of_uses() << std::endl;
    return os;
}