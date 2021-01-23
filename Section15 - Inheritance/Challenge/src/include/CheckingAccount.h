#ifndef _CHECKINGACCOUNT_H_
#define _CHECKINGACCOUNT_H_
#include "Account.h"

class CheckingAccount : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const CheckingAccount &account);

private:
    static constexpr const char *def_name{"Unnamed Checking Account"};
    static constexpr double def_balance{0.0};
    static constexpr const double def_fee{1.5};

protected:
    double fee;

public:
    CheckingAccount(std::string name = def_name, double balance = def_balance, double fee = def_fee);
    CheckingAccount &operator+=(double amount);
    CheckingAccount &operator-=(double amount);
    bool withdraw(double amount);
};

#endif // _CHECKINGACCOUNT_H_
