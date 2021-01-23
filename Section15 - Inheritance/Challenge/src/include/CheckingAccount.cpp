#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string name, double balance, double fee)
    : Account{name, balance}, fee{fee} {}

bool CheckingAccount::withdraw(double amount)
{
    amount += this->fee;
    return Account::withdraw(amount);
}

CheckingAccount &CheckingAccount::operator+=(double amount)
{
    bool success{this->deposit(amount)};
    if (!success)
        std::cout << "Failed Deposit of " << amount << " to " << *this << std::endl;
    return *this;
}

CheckingAccount &CheckingAccount::operator-=(double amount)
{
    bool success{this->withdraw(amount)};
    if (!success)
        std::cout << "Failed Withdrawal of " << amount << " from " << *this << std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const CheckingAccount &account)
{
    os << "[CheckingAccount: " << account.name << ": " << account.balance
       << ", " << account.fee << "]";
    return os;
}
