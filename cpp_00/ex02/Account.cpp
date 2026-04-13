
#include "Account.hpp"

/* initi*/
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

/* Constructor & Destructor */
Account::Account( int initial_deposit )
{
	this->_amount += initial_deposit;
	this->_totalAmount += initial_deposit;
	this->_accountIndex += 1;
}
Account::~Account( void ){}


void	Account::displayAccountsInfos( void )
{
	std::cout << "Nb of accounts : \t\t" << getNbAccounts() << std::endl;
	std::cout << "Total Amount : \t\t" << getTotalAmount() << std::endl;
	std::cout << "Nb of total deposits : \t\t" << getNbDeposits() << std::endl;
	std::cout << "Nb of total withdrawals : \t\t" << getNbWithdrawals () << std::endl;
}
void	Account::makeDeposit( int deposit )
{
	this->_totalAmount += deposit;
	this->_amount += deposit;
	this->_totalNbDeposits += 1;
}
bool	Account::makeWithdrawal( int withdrawal )
{
	if (withdrawal > _amount)
	{
		return (false);
	}
	else
	{
		this->_totalAmount -= withdrawal;
		this->_amount -= withdrawal;
		this->_nbWithdrawals += 1;
		return (true);
	}
}

/* getters & setters */
int		Account::checkAmount( void ) const
{
	return this->_amount;
}

int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}
int	Account::getTotalAmount( void )
{
	return _totalAmount;
}
int		Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}
int		Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}
void	Account::displayStatus( void ) const
{
	std::cout << "Account index : " << _accountIndex << std::endl;
	std::cout << "Amount available : " << _amount << std::endl;
	std::cout << "Nb of deposits : " << _nbDeposits << std::endl;
	std::cout << "Nb of withdrawals : " << _nbWithdrawals << std::endl;
}