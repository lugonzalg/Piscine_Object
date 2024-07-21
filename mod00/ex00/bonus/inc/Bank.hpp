#pragma once

#include <map>
#include <iostream>
#include <exception>

struct Bank
{

    public:

        Bank();
        ~Bank();

        struct Account
        {
            public:

                Account();

                int get_id() const;
                int get_value() const;
                int get_debt() const;

                friend struct Bank;
                friend std::ostream& operator << (std::ostream& p_os, const Account& p_accout);

            private:

                static int _unique_id;
                int _id;
                int _value;
                int _debt;
        };


        int get_liquidity() const;
        int add_value(int account_id, int value);
        int give_loan(int account_id, int value);

        int create_account();
        void delete_account(int account_id);

        const Account &operator [] (int account_id) const;
        friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank);

        class BankError : public std::exception {
            public:
                virtual const char *what() const throw() = 0;
        };

        class AccountNotFoundError : public BankError {
            public:
                virtual const char *what() const throw();
        };

        class NegativeValueError : public BankError {
            public:
                virtual const char *what() const throw();
        };

        class UnpaidDebtError : public BankError {
            public:
                virtual const char *what() const throw();
        };

    private:

        int _liquidity;
        std::map<int, Bank::Account> _accounts;
        Account& _get_account(int account_id);

};

std::ostream& operator << (std::ostream& p_os, const Bank::BankError& e);