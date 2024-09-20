/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anferre <anferre@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 15:41:13 by anferre           #+#    #+#             */
/*   Updated: 2024/09/20 16:59:31 by anferre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp( void ) {
	char buffer[20];
	
	std::time_t cur_time = std::time(0);
	std::tm* local_time = std::localtime(&cur_time);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", local_time);
	std::cout << buffer;
}

int Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int Account::getTotalAmount( void ) {
	return _totalAmount;
}

int Account::checkAmount( void ) const {
	return _amount;
}

void Account::displayStatus( void ) const {
	std::cout << "refused" << std::endl;
}


int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos( void ) {
	_displayTimestamp();
	std::cout << " accounts:" << Account::_nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account ( void ) {
	return;
}

Account::Account ( int initial_deposit ){
	_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	Account::_nbDeposits++;
	Account::_accountIndex = Account::_nbAccounts;
	Account::_nbAccounts++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account ( void ) {
	_displayTimestamp(), std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
	return;
}

void Account::makeDeposit( int deposit ) {
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (withdrawal > _amount) {
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
		displayStatus();
		return false;
	}
	else
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		Account::_totalAmount -= withdrawal;
		Account::_totalNbWithdrawals++;
	}
	return true;
}
