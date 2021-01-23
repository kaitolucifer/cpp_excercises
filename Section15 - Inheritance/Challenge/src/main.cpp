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

    // Accounts
    vector<Account> accounts;
    accounts.push_back(Account{});
    accounts.push_back(Account{"Larry"});
    accounts.push_back(Account{"Moe", 2000});
    accounts.push_back(Account{"Curly", 5000});
    display(accounts);
    deposit(accounts, 1000);
    withdraw(accounts, 2000);

    // Savings Accounts
    vector<SavingsAccount> sav_accounts;
    sav_accounts.push_back(SavingsAccount{});
    sav_accounts.push_back(SavingsAccount{"Superman"});
    sav_accounts.push_back(SavingsAccount{"Batman", 2000});
    sav_accounts.push_back(SavingsAccount{"Wonderwoman", 5000, 5.0});
    display(sav_accounts);
    deposit(sav_accounts, 1000);
    withdraw(sav_accounts, 2000);

    // Checking Accounts
    vector<CheckingAccount> checking_accounts;
    checking_accounts.push_back(CheckingAccount{});
    checking_accounts.push_back(CheckingAccount{"Ted"});
    checking_accounts.push_back(CheckingAccount{"John", 2000});
    checking_accounts.push_back(CheckingAccount{"Rebeca", 5000, 2.0});
    display(checking_accounts);
    deposit(checking_accounts, 1000);
    withdraw(checking_accounts, 2000);
    cout << checking_accounts.at(2) << endl;
    checking_accounts.at(2) -= 100;
    cout << checking_accounts.at(2) << endl;
    checking_accounts.at(2) += 5000;
    cout << checking_accounts.at(2) << endl;

    // Trust Accounts
    vector<TrustAccount> trust_accounts;
    trust_accounts.push_back(TrustAccount{});
    trust_accounts.push_back(TrustAccount{"Naruto"});
    trust_accounts.push_back(TrustAccount{"Sasuke", 2000});
    trust_accounts.push_back(TrustAccount{"Sakura", 5000, 1.5});
    display(trust_accounts);
    deposit(trust_accounts, 5000);
    withdraw(trust_accounts, 5000);
    for (size_t i {}; i < 4; i++)
    {
        cout << trust_accounts.at(3) << endl;
        trust_accounts.at(3) -= 1000;
        cout << trust_accounts.at(3) << endl;
    }
    cout << trust_accounts.at(3) << endl;
    trust_accounts.at(3) += 5000;
    cout << trust_accounts.at(3) << endl;

    return 0;
}
