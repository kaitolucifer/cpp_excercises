#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string name, double balance, double fee)
    : Account{name, balance}, fee{fee} {}

bool CheckingAccount::withdraw(double amount)
{
    amount += this->fee;
    return Account::withdraw(amount);
}

bool CheckingAccount::deposit(double amount)
{
    return Account::deposit(amount);
}


void CheckingAccount::print(std::ostream &os) const
{
    os << "[CheckingAccount: " << this->name << ": " << this->balance
       << ", " << this->fee << "]";
}
