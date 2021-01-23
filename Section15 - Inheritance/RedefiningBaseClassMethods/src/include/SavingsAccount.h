#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_
#include "Account.h"

/*
Savings Account class
Deposit method increments amount to be deposited by amount * int_rate percentage!!
So a 1000 deposit at 5% interest rate will deposit 1000 + 50 = 1050
*/

class SavingsAccount : public Account
{
    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &acount);

protected:
    double int_rate;

public:
    SavingsAccount();
    SavingsAccount(double balance, double int_rate);
    void deposit(double amount);
    // withdraw is inherited
};

#endif // _SAVINGSACCOUNT_H_
