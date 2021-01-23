#include <iostream>
#include <memory>
#include <vector>
#include <utility>

#include "include/Account.h"
#include "include/CheckingAccount.h"
#include "include/TrustAccount.h"
#include "include/SavingsAccount.h"

class Test
{
private:
    int data;

public:
    Test() : data{0}
    {
        std::cout << "Test constructor (" << data << ")" << std::endl;
    }
    Test(int data) : data{data}
    {
        std::cout << "Test constructor (" << data << ")" << std::endl;
    }
    int get_data() const { return data; }
    ~Test() { std::cout << "Test destructor (" << data << ")" << std::endl; }
};

int main()
{
    // Test *t1 = new Test(1000);
    // delete t1;
    std::unique_ptr<Test> t1{new Test(100)};
    std::unique_ptr<Test> t2{std::make_unique<Test>(1000)};
    
    std::unique_ptr<Test> t3;
    t3 = std::move(t1);
    if (!t1)
        std::cout << "t1 is nullptr" << std::endl;

    std::unique_ptr<Account> a1 = std::make_unique<CheckingAccount>("Moe", 5000);
    std::cout << *a1 << std::endl;
    a1->deposit(5000);
    std::cout << *a1 << std::endl;

    std::vector<std::unique_ptr<Account>> accounts;
    accounts.push_back(std::make_unique<CheckingAccount>("James", 1000));
    accounts.push_back(std::make_unique<SavingsAccount>("Billy", 4000, 5.2));
    accounts.push_back(std::make_unique<TrustAccount>("Bobby", 5000, 4.5));
    for (auto &acc: accounts)
        std::cout << *acc << std::endl;
    return 0;
}
