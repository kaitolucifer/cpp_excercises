#include "Account.h"
#include "IllegalBalanceException.h"
#include "InsufficientFundsException.h"

Account::Account(std::string name, double balance)
    : name{name}, balance{balance}
{
    if (balance < 0.0)
        throw IllegalBalanceException{};
}

bool Account::deposit(double amount)
{
    if (amount < 0)
    {
        return false;
    }
    else
    {
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount)
{
    if (balance - amount >= 0)
    {
        balance -= amount;
        return true;
    }
    else
    {
        throw InsufficientFundsException {};
    }
}

double Account::get_balance() const
{
    return this->balance;
}

Account &Account::operator+=(double amount)
{
    bool success{this->deposit(amount)};
    if (!success)
        std::cout << "Failed Deposit of " << amount << " to " << *this << std::endl;
    return *this;
}

Account &Account::operator-=(double amount)
{
    bool success{this->withdraw(amount)};
    if (!success)
        std::cout << "Failed Withdrawal of " << amount << " from " << *this << std::endl;
    return *this;
}
