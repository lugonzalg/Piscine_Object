#pragma once

#include <iostream>

class Employee {

    public:

        Employee(int hourlyValue) : _hourlyValue(hourlyValue) {}

        ~Employee() {}

        int executeWorkday() {
            return this->_hourlyValue;
        }

    private:

        int _hourlyValue;

};