#include <iostream>
#include "AccountUtil.h"

// Displays Account objects in a vector of Account objects
void display(const std::vector<Account *> &accounts)
{
    for (const auto &p : accounts)
        std::cout << *p << std::endl;
}

// Deposits supplied amount to each Account objects in the vector
void deposit(std::vector<Account *> &accounts, double amount)
{
    for (auto &p : accounts)
    {
        if (p->deposit(amount))
            std::cout << "Deposited " << amount << " to " << *p << std::endl;
        else
            std::cout << "Failed Deposit of " << amount << " to " << *p << std::endl;
    }
}

// Withdraw amount from each Account objects in the vector
void withdraw(std::vector<Account *> &accounts, double amount)
{
    for (auto &p : accounts)
    {
        if (p->withdraw(amount))
            std::cout << "Withdrew " << amount << " from " << *p << std::endl;
        else
            std::cout << "Faield Withdrawal of " << amount << " from " << *p << std::endl;
    }
}

void delete_all(std::vector<Account *> &accounts)
{
    for (auto &p : accounts)
    {
        std::cout << "Deleting " << *p << std::endl;
        delete p;
    }
}
