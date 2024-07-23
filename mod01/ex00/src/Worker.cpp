#include "Worker.hpp"

Worker::Worker(const std::string name, int x, int y, int z, int exp, int level) : 
    _name(name), _coordonnee(x, y, z), _stat(exp, level), _tool(NULL) {

    std::cout << "[WORKER] - constructor called\n";
    std::cout << *this;
}
Worker::~Worker() {
    std::cout << "[WORKER] - destructor called\n";
}

const Position& Worker::get_position() const {
    return this->_coordonnee;
}
const Statistic& Worker::get_stat() const {
    return this->_stat;
}

const std::string& Worker::get_name() const {
    return this->_name;
}

bool Worker::equip_tool(Tool *tool) {

    if (tool == NULL)
        return false;

    this->_tool = tool;
    std::cout << "[WORKER] - " << this->_name << " Tool equiped!\n";
    tool->own(this);
    return true;
}

void Worker::unequip_tool() {
    if (this->_tool) {
        this->_tool = NULL;
        std::cout << "[WORKER] - " << this->_name << " Tool unequiped!\n";
    }
}

void Worker::work() {
    std::cout << "[WORKER] - " << this->_name << " working!\n";
}

std::ostream& operator << (std::ostream& os, const Worker& worker) {
    os << "[WORKER]:"
        << "\n\tname: " << worker.get_name()
        << "\n\t" << worker.get_position()
        << "\n\t" << worker.get_stat() << std::endl;
    return os;
}