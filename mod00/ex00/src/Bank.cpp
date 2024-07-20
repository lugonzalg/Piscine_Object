#include <fstream>

#include "Bank.hpp"
#include "Account.hpp"

Bank::Bank() :
		_liquidity(0)
{
}

Bank::~Bank(){}

int Bank::get_liquidity() const {
	return this->_liquidity;
}

const std::map<int, Account *> &Bank::get_accounts() const {
	return this->_clientAccounts;
}

void Bank::add_client(Account *client_account) {

	int client_id = client_account->get_id();
	this->_liquidity += client_account->get_value();

	if (this->_clientAccounts.find(client_id) == this->_clientAccounts.end()) 
		this->_clientAccounts[client_id] = client_account;
}

bool Bank::confirm_transaction(const std::string &transaction_id, const Account *client_account) {
	
	std::map<const std::string, const Account *>::iterator it;
	it = this->_transactions.find(transaction_id);

	if (it == this->_transactions.end())
		return false;

	if ((*it).second != client_account)
		return false;

	this->_transactions.erase(it);
	return true;
}

bool Bank::_is_client(int client_id) const {
	return this->_clientAccounts.find(client_id) != this->_clientAccounts.end();
}

bool Bank::_create_transaction(const Account *client_account, std::string &transaction_id) {
	std::ifstream random_uuid(UUID_PATH);

	if (!random_uuid.is_open())
		return false;

	std::getline(random_uuid, transaction_id);
	this->_transactions[transaction_id] = client_account;

	return true;
}

bool Bank::pay(Account *client_account, int value) {

	int bank_fee;
	std::string transaction_id;

	if (this->_clientAccounts.find(client_account->get_id()) == this->_clientAccounts.end())
		return false;

	if (!this->_create_transaction(client_account, transaction_id))
		return false;
	this->_liquidity += value;

	bank_fee = value * TAX;
	return client_account->add_money(value - bank_fee, transaction_id, *this);
}

std::ostream& operator << (std::ostream& p_os, const Bank& p_bank)
{
    std::map<int, Account *>::const_iterator client;
    const std::map<int, Account *>           &client_accounts = p_bank.get_accounts();

    p_os << "Bank informations : " << std::endl;
    p_os << "\tLiquidity : " << p_bank.get_liquidity() << "\n\n";
    for (client = client_accounts.begin(); client != client_accounts.end(); client++)
        p_os << "\t" << *(*client).second << std::endl;
    return (p_os);
}