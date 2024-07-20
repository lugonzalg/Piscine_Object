#pragma once

#include <iostream>
#include <vector>

#include "Bank.hpp"

struct Account
{
    public:

        Account();

        int get_id() const;
        int get_value() const;

    private:

        static int _unique_id;
        int _id;
        int _value;

        int add_value(int value);
        friend void Bank::add_value(Account *client, int value);
};


std::ostream& operator << (std::ostream& p_os, const Account& p_account);