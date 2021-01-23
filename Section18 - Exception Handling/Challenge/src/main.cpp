#include <iostream>
#include <memory>
#include <utility>

#include "include/Account.h"
#include "include/CheckingAccount.h"
#include "include/TrustAccount.h"
#include "include/SavingsAccount.h"
#include "include/IllegalBalanceException.h"
#include "include/InsufficientFundsException.h"

int main()
{
    try
    {
        std::unique_ptr<Account> moes_account = std::make_unique<CheckingAccount>("Moe", -10.0);
        std::cout << *moes_account << std::endl;
    }
    catch (const IllegalBalanceException &e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        std::unique_ptr<Account> moes_account = std::make_unique<CheckingAccount>("Moe", 1000);
        moes_account->withdraw(2000);
        std::cout << *moes_account << std::endl;
    }
    catch (const InsufficientFundsException &e)
    {
        std::cerr << e.what() << '\n';
    }

    std::cout << "Program completed successfully" << std::endl;
    return 0;
}
