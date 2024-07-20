#pragma once

#include <iostream>
#include <vector>

struct Account
{
    public:

        Account() :
            id(-1),
            value(0)
        {
        
        }

        friend std::ostream& operator << (std::ostream& p_os, const Account& p_account)
        {
            p_os << "[" << p_account.id << "] - [" << p_account.value << "]";
            return (p_os);
        }

    private:
        int id;
        int value;


};
