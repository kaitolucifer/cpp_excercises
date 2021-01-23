#include <iostream>
#include "include/main.h"

using namespace std;

void do_withdraw(Account &account, double amount)
{
    account.withdraw(amount);
}

int main()
{
    Account a;
    Account &ref{a};
    ref.withdraw(1000);

    Trust t;
    Account &ref1{t};
    ref1.withdraw(1000);

    Account a1;
    Savings a2;
    Checking a3;
    Trust a4;

    do_withdraw(a1, 1000);
    do_withdraw(a2, 1000);
    do_withdraw(a3, 1000);
    do_withdraw(a4, 1000);
    

    return 0;
}
