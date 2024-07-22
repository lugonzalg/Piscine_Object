#include <iostream>

#include "Bank.hpp"

int main()
{
	Bank bank = Bank();

	int accountA_id = bank.create_account();
	int accountB_id = bank.create_account();

	//non-existing user and negative value
	try {
		bank.add_value(1234, 200);
	} catch (Bank::AccountNotFoundError& err) {
		std::cerr << err;
	}

	try {
		bank.add_value(accountA_id, -100);
	} catch (Bank::NegativeValueError& err) {
		std::cerr << err;
	}

	bank.add_value(accountA_id, 200);
	bank.add_value(accountA_id, 200);
	bank.add_value(accountB_id, 100);

	try {
		bank.give_loan(1234, 200);
	} catch (Bank::AccountNotFoundError& err) {
		std::cerr << err;
	}

	try {
		bank.give_loan(accountA_id, -100);
	} catch (Bank::NegativeValueError& err) {
		std::cerr << err;
	}

	bank.give_loan(accountA_id, 450);

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;
	try {
		bank.delete_account(1234);
	} catch (Bank::AccountNotFoundError& err) {
		std::cerr << err;
	}

	const Bank::Account& account = bank[0];
	std::cout << account;

	try {
		bank.delete_account(accountA_id);
	} catch (Bank::UnpaidDebtError& err) {
		std::cerr << err;
	}
	bank.delete_account(accountB_id);

	std::cout << bank << std::endl;

	return (0);
}