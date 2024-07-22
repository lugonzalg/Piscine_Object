#include "Bank.hpp"

//ACCOUNT

int Bank::Account::_unique_id = 0;

Bank::Account::Account() : _id(Bank::Account::_unique_id++), _value(0), _debt(0){}

int Bank::Account::get_id() const {
    return this->_id;
}
int Bank::Account::get_value() const {
    return this->_value;
}

int Bank::Account::get_debt() const {
    return this->_debt;
}

std::ostream& operator << (std::ostream& p_os, const Bank::Account& p_account)
{
    p_os << "\n---------- ACCOUNT INFO -------------\n";
    p_os << "id: " << p_account.get_id()
        << "\ncurrent value: " << p_account.get_value()
        << "\ncurrent debt: " << p_account.get_debt() << std::endl;
    p_os << "-------------------------------------\n";

    return (p_os);
}


//BANK

Bank::Bank() : _liquidity(0) {}

Bank::~Bank() {
}

int Bank::get_liquidity() const {
    return this->_liquidity;
}

int Bank::add_value(int account_id, int value) {

    if (value < 0) {
        throw Bank::NegativeValueError();
    }

    try {

        Bank::Account& account = this->_get_account(account_id);
        this->_liquidity += value;
        value *= 0.95;
        account._value += value;
        std::cout << "Value succesfuly given to: " << account._id << " - current value: " << account._value << std::endl;
        return account._value;
    } catch (Bank::AccountNotFoundError& err) {
        throw ;
    }

}

int Bank::create_account() {

    Bank::Account account = Bank::Account();
    this->_accounts[account.get_id()] = account;
    return account.get_id();

}

void Bank::delete_account(int account_id) {

    std::map<int, Account>::iterator it;

    it = this->_accounts.find(account_id);
    if (it == this->_accounts.end())
        throw Bank::AccountNotFoundError();


    if (it->second._debt)
        throw Bank::UnpaidDebtError();

    this->_accounts.erase(it);
}

int Bank::give_loan(int account_id, int value) {

    if (value < 0)
        throw Bank::NegativeValueError();

    try {

        Bank::Account& account = this->_get_account(account_id);
        this->_liquidity -= value;
        value *= 1.05;
        account._debt += value;
        std::cout << "Loan succesfuly given to: " << account._id << " - current debt: " << account._debt << std::endl;
        return account._debt;
    } catch (Bank::AccountNotFoundError &err) {
        throw ;
    }
}

Bank::Account& Bank::_get_account(int account_id) {
    std::map<int, Bank::Account>::iterator it;

    it = this->_accounts.find(account_id);
    if (it == this->_accounts.end())
        throw Bank::AccountNotFoundError();

    return it->second;
}

const Bank::Account& Bank::operator [] (int account_id) const {
    std::map<int, Bank::Account>::const_iterator it;

    it = this->_accounts.find(account_id);
    if (it == this->_accounts.end())
        throw Bank::AccountNotFoundError();

    return it->second;
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    std::map<int, Bank::Account>::const_iterator cit;
    p_os << "---------------- BANK INFORMATION -----------\n\n";
    p_os << "Liquidity : " << p_bank.get_liquidity() << std::endl;
    p_os << "Current accounts: " << p_bank._accounts.size() << std::endl;
    p_os << "\nAccounts info: \n";
    for (cit = p_bank._accounts.begin(); cit != p_bank._accounts.end(); cit++) {
        p_os << "\tid: " << cit->second.get_id()
            << "\n\tcurrent value: " << cit->second.get_value()
            << "\n\tcurrent debt: " << cit->second.get_debt() << std::endl;
    }
    p_os << "\n---------------------------------------------\n";
    return (p_os);
}

std::ostream& operator << (std::ostream& p_os, const Bank::BankError& err) {
    p_os << err.what();
    return p_os;
}


//EXCEPTIONS

const char *Bank::AccountNotFoundError::what() const throw() {
    return "Error: Account not found!\n";
}

const char *Bank::NegativeValueError::what() const throw() {
    return "Error: Negative value, unprocesable!\n";
}

const char *Bank::UnpaidDebtError::what() const throw() {
    return "Error: Account still has debt!\n";
}