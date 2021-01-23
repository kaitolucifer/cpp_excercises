#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_
#include "Account.h"

/*
Savings Account is a type of Account adds an interest rate
withdraw: same as regular account
deposit:
    Amount supplied to deposit will be incremented by (amount * int_rate / 100)
    and then the updated amount will be deposited
*/

class SavingsAccount : public Account
{
private:
    static constexpr const char *def_name = "Unnamed Savings Account";
    static constexpr double def_balance = 0.0;
    static constexpr double def_int_rate = 0.0;

protected:
    double int_rate;

public:
    SavingsAccount(std::string name = def_name, double balance = def_balance, double int_rate = def_int_rate);
    virtual bool deposit(double amount) override;
    virtual bool withdraw(double amount) override;
    virtual void print(std::ostream &os) const override;
    virtual ~SavingsAccount() = default;
};

#endif // _SAVINGSACCOUNT_H_
