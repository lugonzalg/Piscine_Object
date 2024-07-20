#pragma once

#include <iostream>
#include <string>

#include "Bank.hpp"

struct Account
{
    public:

        Account(int value);
        ~Account();

        const std::string &get_key() const;
        int get_id() const;
        int get_value() const;
        bool add_money(int value, const std::string &key, Bank &bank);

    private:

        Account();
        int _id;
        int _value;

        static int _unique_id;

};

std::ostream& operator << (std::ostream& p_os, const Account& p_account);