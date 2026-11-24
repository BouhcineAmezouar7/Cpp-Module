#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
    this->_accountIndex = _nbAccounts;
    this->_amount = initial_deposit;
    this->_nbDeposits = 0;
    this->_nbWithdrawals = 0;

    _nbAccounts++;
    _totalAmount += initial_deposit;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";created" << std::endl;
}

Account::~Account()
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";closed" << std::endl;
}

void Account::_displayTimestamp()
{
    std::time_t now = std::time(0);
    std::tm *t = std::localtime(&now);

    std::cout << "[" << (t->tm_year + 1900)
              << std::setfill('0') << std::setw(2) << (t->tm_mon + 1)
              << std::setw(2) << t->tm_mday << "_"
              << std::setw(2) << t->tm_hour
              << std::setw(2) << t->tm_min
              << std::setw(2) << t->tm_sec << "] ";
}

void Account::makeDeposit(int deposit)
{
    int previous_amount = this->_amount;

    this->_amount += deposit;
    this->_nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << previous_amount
              << ";deposit:" << deposit
              << ";amount:" << this->_amount
              << ";nb_deposits:" << this->_nbDeposits
              << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
    int previous_amount = this->_amount;

    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";p_amount:" << previous_amount;

    if (withdrawal <= this->_amount)
    {
        this->_amount -= withdrawal;
        this->_nbWithdrawals++;
        _totalAmount -= withdrawal;
        _totalNbWithdrawals++;

        std::cout << ";withdrawal:" << withdrawal
                  << ";amount:" << this->_amount
                  << ";nb_withdrawals:" << this->_nbWithdrawals
                  << std::endl;
        return true;
    }
    else
    {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
}

int Account::checkAmount() const
{
    return this->_amount;
}

void Account::displayStatus() const
{
    _displayTimestamp();
    std::cout << "index:" << this->_accountIndex
              << ";amount:" << this->_amount
              << ";deposits:" << this->_nbDeposits
              << ";withdrawals:" << this->_nbWithdrawals
              << std::endl;
}

int Account::getNbAccounts()
{
    return _nbAccounts;
}

int Account::getTotalAmount()
{
    return _totalAmount;
}

int Account::getNbDeposits()
{
    return _totalNbDeposits;
}

int Account::getNbWithdrawals()
{
    return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
    _displayTimestamp();
    std::cout << "accounts:" << getNbAccounts()
              << ";total:" << getTotalAmount()
              << ";deposits:" << getNbDeposits()
              << ";withdrawals:" << getNbWithdrawals()
              << std::endl;
}
