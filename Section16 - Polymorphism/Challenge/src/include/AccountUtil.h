#ifndef _ACCOUNTUTIL_H_
#define _ACCOUNTUTIL_H_
#include <vector>
#include "Account.h"

// Utility helper functions for Account class

void display(const std::vector<Account *> &accounts);
void deposit(std::vector<Account *> &accounts, double amount);
void withdraw(std::vector<Account *> &accounts, double amount);
void delete_all(std::vector<Account *> &accounts);

#endif // _ACCOUNTUTIL_H_
