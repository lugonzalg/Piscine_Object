#include "Worker.hpp"

Worker::Worker(int x, int y, int z, int exp, int level) : 
    _coordonnee(x, y, z), _stat(exp, level) {

        std::cout << "Worker constructor called\n";
        std::cout << *this;
}
Worker::~Worker() {
    std::cout << "Worker destructor called\n";
}