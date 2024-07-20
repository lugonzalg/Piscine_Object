#pragma once

#include <iostream>
#include <vector>

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


};


std::ostream& operator << (std::ostream& p_os, const Account& p_account);