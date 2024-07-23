#include "Worker.hpp"

Worker::Worker(int x, int y, int z, int exp, int level) : 
    _coordonnee(x, y, z), _stat(exp, level), _shovel(NULL) {

    std::cout << "Worker constructor called\n";
    std::cout << *this;
}
Worker::~Worker() {
    std::cout << "Worker destructor called\n";
}

const Position& Worker::get_position() const {
    return this->_coordonnee;
}
const Statistic& Worker::get_stat() const {
    return this->_stat;
}

bool Worker::equip_shovel(Shovel *shovel) {

    if (shovel == NULL)
        return false;

    shovel->own(this);
    std::cout << "[WORKER] - Shovel equiped!\n";
    this->_shovel = shovel;
    return true;
}

void Worker::unequip_shovel() {
    this->_shovel = NULL;
    std::cout << "[WORKER] - Shovel unequiped!\n";
}

std::ostream& operator << (std::ostream& os, const Worker& worker) {
    os << "Worker info: "
        << "\ncoordonne: \n" << worker.get_position()
        << "\nstat: \n" << worker.get_stat() << std::endl;
    return os;
}