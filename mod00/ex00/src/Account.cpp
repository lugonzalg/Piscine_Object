#include "Account.hpp"

int Account::_unique_id = 0;

Account::Account() : _id(Account::_unique_id++), _value(0) {}

int Account::get_id() const {
    return this->_id;
}
int Account::get_value() const {
    return this->_value;
}

std::ostream& operator << (std::ostream& p_os, const Account& p_account)
{
    p_os << "[" << p_account.get_id() << "] - [" << p_account.get_value() << "]";
    return (p_os);
}