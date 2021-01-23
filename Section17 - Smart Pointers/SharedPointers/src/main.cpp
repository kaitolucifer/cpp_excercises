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

void func(std::shared_ptr<Test> p)
{
    std::cout << "Use count: " << p.use_count() << std::endl;
}

int main()
{
    std::shared_ptr<int> p1{new int(100)};
    std::cout << "Use count: " << p1.use_count() << std::endl;
    std::shared_ptr<int> p2{p1};
    std::cout << "Use count: " << p1.use_count() << std::endl;
    p1.reset(); // shared ownwership
    std::cout << "Use count: " << p1.use_count() << std::endl;
    std::cout << "Use count: " << p2.use_count() << std::endl;

    std::shared_ptr<Test> ptr{std::make_shared<Test>(100)};
    func(ptr);
    std::cout << "Use count: " << ptr.use_count() << std::endl;
    {
        std::shared_ptr<Test> ptr1{ptr};
        std::cout << "Use count: " << ptr.use_count() << std::endl;
        {
            std::shared_ptr<Test> ptr2{ptr1};
            std::cout << "Use count: " << ptr.use_count() << std::endl;
            ptr.reset();
        }
        std::cout << "Use count: " << ptr.use_count() << std::endl;
    }
    std::cout << "Use count: " << ptr.use_count() << std::endl;

    std::shared_ptr<Account> acc1 =
        std::make_shared<TrustAccount>("Larry", 10000, 3.1);
    std::shared_ptr<Account> acc2 =
        std::make_shared<CheckingAccount>("Moe", 5000);
    std::shared_ptr<Account> acc3 =
        std::make_shared<SavingsAccount>("Curry", 6000);
    std::vector<std::shared_ptr<Account>> accounts;
    accounts.push_back(acc1);
    accounts.push_back(acc2);
    accounts.push_back(acc3);
    for(auto acc: accounts) {
        std::cout << *acc << std::endl;
        std::cout << "Use count: " << acc.use_count() << std::endl;  // copy not reference
    }
    return 0;
}
