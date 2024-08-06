#include "Workshop.hpp"

Workshop::Workshop() {
    std::cout << "[WORKSHOP] - constructor called\n";
}
Workshop::~Workshop() {
    std::cout << "[WORKSHOP] - destructor called\n";
}

void Workshop::register_worker(Worker* worker) {

    this->_workers.insert(worker);
    std::cout << "[WORKSHOP] - " << worker->get_name() << " registered to work!\n";
}

void Workshop::release_worker(Worker* worker) {

    std::set<Worker*>::iterator it;

    it = this->_workers.find(worker);
    if (it == this->_workers.end())
        return ;

    std::cout << "[WORKSHOP] - " << worker->get_name() << " leaved work!\n";
    this->_workers.erase(it);

}

void Workshop::executeWorkDay() {
    std::set<Worker *>::iterator it;

    std::cout << "[WORKSHOP] - workday!!\n";

    for (it = this->_workers.begin(); it != this->_workers.end(); it++) {
        (*it)->work();
    }
}

std::ostream& operator << (std::ostream& os, const Workshop& wkshp) {
    (void)wkshp;
    return os;
}