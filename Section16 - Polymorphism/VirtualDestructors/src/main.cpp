#include <iostream>
#include "include/main.h"

using namespace std;

int main()
{
    Account *p1 = new Account {};
    Account *p2 = new Checking {};
    Account *p3 = new Savings {};
    Account *p4 = new Trust {};
    p1->withdraw(1000);
    p2->withdraw(1000);
    p3->withdraw(1000);
    p4->withdraw(1000);
    delete p1;
    delete p2;
    delete p3;
    delete p4;

    return 0;
}
