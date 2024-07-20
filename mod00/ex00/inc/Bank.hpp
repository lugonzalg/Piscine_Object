#pragma once

struct Bank
{
    public:

        Bank() :
            liquidity(0)
        {

        }

        friend std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
        {
            p_os << "Bank informations : " << std::endl;
            p_os << "Liquidity : " << p_bank.liquidity << std::endl;
            for (auto &clientAccount : p_bank.clientAccounts)
            p_os << *clientAccount << std::endl;
            return (p_os);
        }

    private:

        int liquidity;
        std::vector<Account *> clientAccounts;

};