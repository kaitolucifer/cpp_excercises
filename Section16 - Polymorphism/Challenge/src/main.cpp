#include <iostream>
#include <vector>
#include "include/TrustAccount.h"
#include "include/CheckingAccount.h"
#include "include/AccountUtil.h"

using namespace std;

int main()
{
    cout.precision(2);
    cout << fixed;

    // Savings Accounts
    Account *s1 = new SavingsAccount{};
    Account *s2 = new SavingsAccount{"Superman"};
    Account *s3 = new SavingsAccount{"Batman", 2000};
    Account *s4 = new SavingsAccount{"Wonderwoman", 5000, 5.0};
    vector<Account *> sav_accounts{s1, s2, s3, s4};
    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);
    delete_all(sav_accounts);

    // Checking Accounts
    Account *c1 = new CheckingAccount{};
    Account *c2 = new CheckingAccount{"Ted"};
    Account *c3 = new CheckingAccount{"John", 2000};
    Account *c4 = new CheckingAccount{"Rebeca", 5000, 2.0};
    vector<Account *> checking_accounts{c1, c2, c3, c4};
    display(checking_accounts);
    deposit(checking_accounts, 1000);
    withdraw(checking_accounts, 2000);
    cout << *(checking_accounts.at(2)) << endl;
    *(checking_accounts.at(2)) -= 100;
    cout << *(checking_accounts.at(2)) << endl;
    *(checking_accounts.at(2)) += 5000;
    cout << *(checking_accounts.at(2)) << endl;
    delete_all(checking_accounts);

    // Trust Accounts
    Account *t1 = new TrustAccount{};
    Account *t2 = new TrustAccount{"Naruto"};
    Account *t3 = new TrustAccount{"Sasuke", 2000};
    Account *t4 = new TrustAccount{"Sakura", 5000, 1.5};
    vector<Account *> trust_accounts{t1, t2, t3, t4};
    display(trust_accounts);
    deposit(trust_accounts, 5000);
    withdraw(trust_accounts, 5000);
    for (size_t i {}; i < 4; i++)
    {
        cout << *(trust_accounts.at(3)) << endl;
        *(trust_accounts.at(3)) -= 1000;
        cout <<  *(trust_accounts.at(3)) << endl;
    }
    cout <<  *(trust_accounts.at(3)) << endl;
     *(trust_accounts.at(3)) += 5000;
    cout <<  *(trust_accounts.at(3)) << endl;
    delete_all(trust_accounts);

    return 0;
}
