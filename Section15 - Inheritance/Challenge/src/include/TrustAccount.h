#ifndef _TRUSTACCOUNT_H_
#define _TRUSTACCOUNT_H_
#include "SavingsAccount.h"

class TrustAccount : public SavingsAccount
{
    friend std::ostream &operator<<(std::ostream &os, const TrustAccount &account);

private:
    static constexpr const char *def_name{"Unnamed Trust Account"};
    static constexpr const double def_balance{0.0};
    static constexpr const double def_int_rate{0.0};
    static constexpr const double bonus_threshold{5000.0};
    static constexpr const double bonus_amount{50.0};
    static constexpr const double max_withdraw_percent{0.2};
    static constexpr const int max_withdraw_count{3};

protected:
    int withdrawal_count;

public:
    TrustAccount(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    TrustAccount &operator+=(double amount);
    TrustAccount &operator-=(double amount);
    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif // _TRUSTACCOUNT_H_
