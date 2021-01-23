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

void TrustAccount::print(std::ostream &os) const
{
    os << "[TrustAccount: " << this->name
       << ": " << this->balance << ", " << this->int_rate
       << "%, " << this->withdrawal_count << "]";
}
