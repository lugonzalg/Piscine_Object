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

int Bank::add_value(int account_id, int value) {
    Account *account;

    account = this->_get_account_by_id(account_id);
    if (account == NULL) {

        std::cerr << "[VALUE] - Account with id: " << account_id << " does not exist!\n";
        return -1;
    }

    if (value < 0) {
        std::cerr << "[VALUE] - Cannot add negative funds: " << value << std::endl;
        return -1;
    }
    
    this->_liquidity += value;
    value *= 0.95;
    return account->add_value(value);
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

            if ((*it).get_debt()) {
                std::cerr << "Account has debt, cannot delete it\n";
                return ;
            }

            this->_liquidity -= (*it).get_value();
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


int Bank::give_loan(int account_id, int value) {
    Account *account;

    account = this->_get_account_by_id(account_id);
    if (account == NULL) {

        std::cerr << "[LOAN] - Account with id: " << account_id << " does not exist!\n";
        return -1;
    }

    if (value < 0) {
        std::cerr << "[LOAN] - Cannot add negative funds: " << value << std::endl;
        return -1;
    }

    this->_liquidity -= value;
    value *= 1.05;
    return account->add_debt(value);
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    const std::vector<Account> &accounts = p_bank.get_accounts();
    p_os << "\tLiquidity : " << p_bank.get_liquidity() << std::endl;

    p_os << "\taccounts number: " << accounts.size() << std::endl;
    p_os << "\n\tdetailed account information: \n";
    p_os << "---------------------------------------------\n\n";
    for (size_t idx = 0; idx < accounts.size(); idx++) {
        const Account account = accounts.at(idx);
        p_os << "\tid: " << account.get_id() << "\n\tvalue: " << account.get_value()  << "\n\tdebt: " << account.get_debt() << "\n\n";
    }
    p_os << "---------------------------------------------\n";
    return (p_os);
}
