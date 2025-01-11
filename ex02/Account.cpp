/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtelek <mtelek@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/29 20:36:40 by mtelek            #+#    #+#             */
/*   Updated: 2025/01/11 15:20:55 by mtelek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
	: _accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created\n";
}

Account::~Account()
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed\n";
}

void Account::_displayTimestamp()
{
	time_t now = time(NULL);
	tm *ltm = localtime(&now);

	std::cout << "[" 
			<< 1900 + ltm->tm_year
			<< std::setfill('0') << std::setw(2) << ltm->tm_mon + 1
			<< std::setfill('0') << std::setw(2) << ltm->tm_mday << "_"
			<< std::setfill('0') << std::setw(2) << ltm->tm_hour
			<< std::setfill('0') << std::setw(2) << ltm->tm_min
			<< std::setfill('0') << std::setw(2) << ltm->tm_sec
			<< "]";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << " accounts:" << _nbAccounts
				<< ";total:" << _totalAmount
				<< ";deposits:" << _totalNbDeposits
				<< ";withdrawals:" << _totalNbWithdrawals
				<< "\n";
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex
				<< ";amount:" << _amount
				<< ";deposits:" << _nbDeposits
				<< ";withdrawals:" << _nbWithdrawals
				<< "\n";
}

int Account::getNbAccounts()
{
	return(_nbAccounts);
}

int Account::getTotalAmount()
{
	return (_totalAmount);
}

int Account::getNbDeposits()
{
	return(_totalNbDeposits);
}

int Account::getNbWithdrawals()
{
	return (_totalNbWithdrawals);
}


void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
				<< ";deposit:" << deposit;
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	std::cout << ";amount:" << _amount << ";nb_deposits:" << _nbDeposits << "\n";
}


bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
					<< ";withdrawal:refused\n";
		return (false);
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_displayTimestamp();
	std::cout << " index:" << _accountIndex << ";p_amount:" << (_amount + withdrawal)
				<< ";withdrawal:" << withdrawal << ";amount:" << _amount
				<< ";nb_withdrawals:" << _nbWithdrawals << "\n";
	return (true);
}

int Account::checkAmount() const
{
	return(_amount);
}
