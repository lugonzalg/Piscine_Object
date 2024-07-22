#include "Worker.hpp"

Worker::Worker(int x, int y, int z, int exp, int level) :
    _coordonnee(x, y, z), _stat(exp, level) {

        std::cout << "Worker constructor called with this values: "
            << "\n\tcoordonne: " << this->_coordonne
            << "\n\tstat: " << this->_stat << std::endl;
}
Worker::~Worker() {
    std::cout << "Worker destructor called\n";
}