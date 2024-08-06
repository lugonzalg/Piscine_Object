#pragma once

#include "command.hpp"

class PackageReductionDiscountCommand : public Command {

    public:

        PackageReductionDiscountCommand(const std::string& client) : 
            Command(client) {
        }

        PackageReductionDiscountCommand(const std::string& client, struct tm* t) : 
            Command(client, t) {
        }

        ~PackageReductionDiscountCommand() {
        }

        float get_total_price() {
            float total;

            total = Command::get_total_price();
            if (total >= 150.0f) {
                std::cout << "[THUESDAY DISCOUNT COMMNAD] - discount applied:\n";
                std::cout << "   + Before: " << total;
                total -= 10.0f;
                std::cout << "\n   + After: " << total << std::endl;
            }
            return total;
        }
};