#pragma once

#include <vector>
#include <iostream>

struct Account;

struct Bank
{
    public:

        Bank();
        ~Bank();

        int get_liquidity() const;
        const std::vector<Account> &get_accounts() const;
        void add_value(int account_id, int value);
        int give_loan(int account_id, int value);

        int create_account();
        void delete_account(int account_id);

    private:

        int _liquidity;
        std::vector<Account> _accounts;
        bool _is_bank_account(int account_id);
        Account *_get_account_by_id(int account_id);
};

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);