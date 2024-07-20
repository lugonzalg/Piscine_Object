#pragma once

#include <vector>
#include <iostream>

struct Account;

struct Bank
{
    public:

        Bank();

        int get_liquidity() const;
        const std::vector<Account *> &get_client_accounts() const;
        void add_client(Account *client);
        void add_value(Account *client, int value);

    private:

        int _liquidity;
        std::vector<Account *> _client_accounts;

};

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);