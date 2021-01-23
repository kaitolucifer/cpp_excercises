#include <iostream>
#include "include/Account.h"
#include "include/SavingsAccount.h"

using namespace std;

int main()
{
    cout << "--------------Account--------------" << endl;
    Account acc {};
    acc.deposit(2000.0);
    acc.withdraw(500.0);
    cout << endl;
    Account *p_acc {nullptr};
    p_acc = new Account();
    p_acc->deposit(1000.0);
    p_acc->withdraw(500.0);
    delete p_acc;
    cout << "--------------Savings Account--------------" << endl;
    SavingsAccount sav_acc {};
    sav_acc.deposit(2000.0);
    sav_acc.withdraw(500.0);
    cout << endl;
    SavingsAccount *p_sav_acc {nullptr};
    p_sav_acc = new SavingsAccount();
    p_sav_acc->deposit(2000.0);
    p_sav_acc->withdraw(500.0);
    delete p_sav_acc;
    return 0;
}