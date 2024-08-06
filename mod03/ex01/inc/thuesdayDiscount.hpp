#pragma once

#include "command.hpp"

class ThuesdayDiscountCommand : public Command {

    public:
        ThuesdayDiscountCommand(const std::string& client) : 
            Command(client) {
        }

        ThuesdayDiscountCommand(const std::string& client, struct tm* t) : 
            Command(client, t) {
        }

        ~ThuesdayDiscountCommand() {
        }

        float get_total_price() {
            float total;

            total = Command::get_total_price();
            if (_date->tm_wday == 5) {

                std::cout << "[THUESDAY DISCOUNT COMMNAD] - discount applied:\n";
                std::cout << "   + Before: " << total;
                total *= 0.9f;
                std::cout << "\n   + After: " << total << std::endl;
            }
            return total;
        }
};