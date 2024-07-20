#include <iostream>

#include "Account.hpp"
#include "Bank.hpp"

int main()
{
	Account accountA = Account();

	Account accountB = Account();

	Bank bank = Bank();
	bank.add_client(&accountA);
	bank.add_client(&accountB);

	std::cout << "Account : " << std::endl;
	std::cout << accountA << std::endl;
	std::cout << accountB << std::endl;

	std::cout << " ----- " << std::endl;

	std::cout << "Bank : " << std::endl;
	std::cout << bank << std::endl;

	return (0);
}