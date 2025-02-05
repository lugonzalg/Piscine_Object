#pragma once

#include <vector>

#include "employee.hpp"

class EmployeeManager {

    public:

        EmployeeManager() {}
        ~EmployeeManager() {}

        void addEmployee(Employee *employee) {
            this->_employees.push_back(employee);
        }

        void removeEmployee(Employee* employee) {
            std::vector<Employee *>::iterator it;

            it = this->_employees.begin();
            for (; it != this->_employees.end(); it++) {

                if ((*it) == employee) {
                    this->_employees.erase(it);
                    break ;
                }
            }
        }

        void executeWorkday() {

        }

        void calculatePayroll() {

        }

    private:

        std::vector<Employee *> _employees;

};