#pragma once

#include <iostream>
#include <vector>

#include "Bank.hpp"

struct Account
{
    public:

        int get_id() const;
        int get_value() const;

    private:

        Account();

        static int _unique_id;
        int _id;
        int _value;

        int add_value(int value);
        friend void Bank::add_value(int account_id, int value);
        friend int Bank::create_account();
};


std::ostream& operator << (std::ostream& p_os, const Account& p_account);