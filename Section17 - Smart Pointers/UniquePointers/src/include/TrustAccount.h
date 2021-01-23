#ifndef _TRUSTACCOUNT_H_
#define _TRUSTACCOUNT_H_
#include "SavingsAccount.h"

class TrustAccount : public SavingsAccount
{
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
    virtual void print(std::ostream &os) const override;
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual ~TrustAccount() = default;
};

#endif // _TRUSTACCOUNT_H_
