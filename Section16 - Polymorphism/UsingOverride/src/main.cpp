#include <iostream>
#include <memory>
#include "include/main.h"

using namespace std;

int main()
{
    Base *p1 = new Base{};
    p1->say_hello();

    Derived *p2 = new Derived{};
    p2->say_hello();

    Base *p3 = new Derived{};
    p3->say_hello();

    return 0;
}
