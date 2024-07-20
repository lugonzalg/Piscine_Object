#include <iostream>

#include "Account.hpp"
#include "Bank.hpp"

int main()
{
	Bank bank = Bank();

	int accountA_id = bank.create_account();
	int accountB_id = bank.create_account();

	bank.add_value(accountA_id, 200);
	bank.add_value(accountB_id, 100);
	bank.give_loan(accountA_id, 200);

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}