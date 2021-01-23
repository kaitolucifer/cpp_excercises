#ifndef _SAVINGSACCOUNT_H_
#define _SAVINGSACCOUNT_H_
#include "Account.h"

class SavingsAccount: public Account
{
public:
    double int_rate;
    SavingsAccount();
    ~SavingsAccount();
    void deposit(double ammount);
    void withdraw(double amount);
};


#endif // _SAVINGSACCOUNT_H_