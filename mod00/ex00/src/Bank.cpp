#include "Bank.hpp"
#include "Account.hpp"

Bank::Bank() : _liquidity(0) {}

int Bank::get_liquidity() const {
    return this->_liquidity;
}

const std::vector<Account *> &Bank::get_client_accounts() const {
    return this->_client_accounts;
}

void Bank::add_client(Account *client) {
    this->_client_accounts.push_back(client);
}

void Bank::add_value(Account *client, int value) {
    
    this->_liquidity += value;
    value *= 0.95;
    client->add_value(value);
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    const std::vector<Account *> &clients = p_bank.get_client_accounts();
    p_os << "\tLiquidity : " << p_bank.get_liquidity() << std::endl;

    p_os << "\tclients number: " << clients.size() << std::endl;
    p_os << "\n\tdetailed client information: \n";
    p_os << "---------------------------------------------\n";
    for (size_t idx = 0; idx < clients.size(); idx++)
        p_os << "\tid: " << clients.at(idx)->get_id() << "\n\tvalue: " << clients.at(idx)->get_value() << "\n\n";
    p_os << "---------------------------------------------\n";
    return (p_os);
}
