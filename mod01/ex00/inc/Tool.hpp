#pragma once

class Worker;

class Tool {

    public:
        virtual void use() = 0;
        virtual void own(Worker *worker) = 0;

};