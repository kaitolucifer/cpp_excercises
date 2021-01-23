#include <iostream>
#include "include/main.h"

using namespace std;

int main()
{
    Base base;
    base.a = 100;
    // base.b = 200;  // compiler error
    // base.c = 300;  // compiler error
    Derived d;
    d.a = 100;
    // d.b = 200;  // compiler error
    // d.c = 300;  // compiler error
    return 0;
}