#include <iostream>
#include <memory>
#include "include/main.h"

using namespace std;

int main()
{
    Base b{};
    b.say_hello();
    Derived d{};
    d.say_hello();
    greetings(b);
    greetings(d);
    Base *ptr = new Derived();
    ptr->say_hello();
    delete ptr;
    std::unique_ptr<Base> ptr_u = std::make_unique<Derived>();
    ptr_u->say_hello();
    return 0;
}
