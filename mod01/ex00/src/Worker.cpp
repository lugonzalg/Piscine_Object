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

    tool->own(this);
    std::cout << "[WORKER] - Tool equiped!\n";
    this->_tool = tool;
    return true;
}

void Worker::unequip_tool() {
    this->_tool = NULL;
    std::cout << "[WORKER] - Tool unequiped!\n";
}

std::ostream& operator << (std::ostream& os, const Worker& worker) {
    os << "[WORKER]:"
        << "\n\tname: " << worker.get_name()
        << "\n\t" << worker.get_position()
        << "\n\t" << worker.get_stat() << std::endl;
    return os;
}