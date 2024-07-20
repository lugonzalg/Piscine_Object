#include "Bank.hpp"
#include "Account.hpp"

Bank::Bank() : _liquidity(0) {}

Bank::~Bank() {
}

int Bank::get_liquidity() const {
    return this->_liquidity;
}

const std::vector<Account> &Bank::get_accounts() const {
    return this->_accounts;
}

void Bank::add_value(int account_id, int value) {
    Account *account;

    account = this->_get_account_by_id(account_id);
    if (account == NULL)
        return ;
    
    this->_liquidity += value;
    value *= 0.95;
    account->add_value(value);
}

int Bank::create_account() {

    Account account = Account();
    this->_accounts.push_back(account);
    return account.get_id();

}

void Bank::delete_account(int account_id) {

    std::vector<Account>::iterator it;

    for (it = this->_accounts.begin(); it != this->_accounts.end(); it++) {
        if ((*it).get_id() == account_id) {
            this->_accounts.erase(it);
            break ;
        }
    }
}

Account *Bank::_get_account_by_id(int account_id) {
    std::vector<Account>::iterator it;

    for (it = this->_accounts.begin(); it != this->_accounts.end(); it++) {
        if (it->get_id() == account_id)
            return &(*it);
    }
    return NULL;
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    const std::vector<Account> &accounts = p_bank.get_accounts();
    p_os << "\tLiquidity : " << p_bank.get_liquidity() << std::endl;

    p_os << "\taccounts number: " << accounts.size() << std::endl;
    p_os << "\n\tdetailed account information: \n";
    p_os << "---------------------------------------------\n";
    for (size_t idx = 0; idx < accounts.size(); idx++)
        p_os << "\tid: " << accounts.at(idx).get_id() << "\n\tvalue: " << accounts.at(idx).get_value() << "\n\n";
    p_os << "---------------------------------------------\n";
    return (p_os);
}
