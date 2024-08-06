#pragma once

#include <iostream>
#include <set>

#include "Worker.hpp"

class Workshop {

    private:
        
        std::set<Worker*> _workers;

    public:

        Workshop();
        ~Workshop();

        void register_worker(Worker* worker);
        void release_worker(Worker* worker);
        void executeWorkDay();

};

std::ostream& operator << (std::ostream& os, const Workshop& wkshp);