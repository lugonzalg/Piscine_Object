#include <iostream>

#include "Account.hpp"
#include "Bank.hpp"

int main()
{
	Bank bank = Bank();

	int accountA_id = bank.create_account();
	int accountB_id = bank.create_account();

	//non-existing user and negative value
	bank.add_value(1234, 200);
	bank.add_value(accountA_id, -100);
	bank.add_value(1234, -100);

	bank.add_value(accountA_id, 200);
	bank.add_value(accountA_id, 200);
	bank.add_value(accountB_id, 100);

	bank.give_loan(1234, 200);
	bank.give_loan(accountA_id, -100);
	bank.give_loan(1234, -100);

	bank.give_loan(accountA_id, 450);
	bank.delete_account(accountA_id);
	bank.delete_account(accountB_id);

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}