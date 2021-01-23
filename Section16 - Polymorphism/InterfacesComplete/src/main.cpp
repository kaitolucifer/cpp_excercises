#include <iostream>
#include "include/main.h"

using namespace std;

void print(const PrintableInterface &obj)
{
    std::cout << obj << std::endl;
}

int main()
{
    Account a;
    std::cout << a << std::endl;
    Checking c;
    std::cout << c << std::endl;
    Savings s;
    std::cout << s << std::endl;
    Trust t;
    std::cout << t << std::endl;

    Account *p1 = new Account();
    std::cout << *p1 << std::endl;

    Account *p2 = new Checking();
    std::cout << *p2 << std::endl;

    Dog *dog = new Dog();
    print(*dog);
    return 0;
}
