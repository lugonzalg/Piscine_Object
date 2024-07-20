#include "Account.hpp"

int Account::_unique_id = 0;

Account::Account(int value) :
    _id(Account::_unique_id),
    _value(value)
{
    Account::_unique_id++;
}

Account::~Account()
{

}

int Account::get_id() const {
    return this->_id;
}

int Account::get_value() const {
    return this->_value;
}

bool Account::add_money(int value, const std::string &transaction_id, Bank &bank) {

    if (!bank.confirm_transaction(transaction_id, this))
        return false;

    this->_value += value;

    return true;
}

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account.get_id() << "] - [" << p_account.get_value() << "]";
    return (p_os);
}