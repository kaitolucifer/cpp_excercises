#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double balance, double int_rate)
    : Account{balance}, int_rate{int_rate} {}

SavingsAccount::SavingsAccount() : SavingsAccount{0.0, 0.0} {}

void SavingsAccount::deposit(double amount)
{
    amount += (amount * int_rate / 100);
    Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingsAccount &account)
{
    os << "Savings Account balance: " << account.balance
       << " Interest rate: " << account.int_rate;
    return os;
}
