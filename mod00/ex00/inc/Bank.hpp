#pragma once

#include <iostream>
#include <map>
#include <string>

# define TAX 0.05
# define UUID_PATH "/proc/sys/kernel/random/uuid"

class Account;

struct Bank
{
    public:
        Bank();
        ~Bank();

        int get_liquidity() const;
        const std::map<int, Account *> &get_accounts() const;

        bool confirm_transaction(const std::string &transactionn_id, const Account *client_account);
        void add_client(Account *client_account);
        bool pay(Account *client_account, int value);

    private:
        int _liquidity;
        std::map<int, Account *> _clientAccounts;
        std::map<const std::string, const Account *> _transactions;
        bool _create_transaction(const Account *client_account, std::string &transaction_id);

        bool _is_client(int client_id) const;

};

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);