#include "TrustAccount.h"

TrustAccount::TrustAccount(std::string name, double balance, double int_rate)
    : SavingsAccount{name, balance, int_rate}, withdrawal_count{0} {}

bool TrustAccount::deposit(double amount)
{
    if (amount >= this->bonus_threshold)
        amount += this->bonus_amount;
    return SavingsAccount::deposit(amount);
}

bool TrustAccount::withdraw(double amount)
{
    if (amount < this->balance * this->max_withdraw_percent &&
        amount > 0 && this->withdrawal_count < max_withdraw_count)
    {
        this->withdrawal_count++;
        return SavingsAccount::withdraw(amount);
    }
    else
    {
        return false;
    }
}

TrustAccount &TrustAccount::operator+=(double amount)
{
    bool success{this->deposit(amount)};
    if (!success)
        std::cout << "Failed Deposit of " << amount << " to " << *this << std::endl;
    return *this;
}

TrustAccount &TrustAccount::operator-=(double amount)
{
    bool success{this->withdraw(amount)};
    if (!success)
        std::cout << "Failed Withdrawal of " << amount << " from " << *this << std::endl;
    return *this;
}

std::ostream &operator<<(std::ostream &os, const TrustAccount &account)
{
    os << "[TrustAccount: " << account.name
       << ": " << account.balance << ", " << account.int_rate
       << "%, " << account.withdrawal_count << "]";
    return os;
}
