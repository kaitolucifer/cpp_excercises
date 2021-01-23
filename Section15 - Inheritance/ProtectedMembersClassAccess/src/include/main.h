#ifndef _MAIN_H_
#define _MAIN_H_
#include <iostream>

class Base
{
public:
    int a {0};
    void display() {std::cout << a << ", " << b << ", " << c << std::endl;}
protected:
    int b {0};
private:
    int c {0};
};

class Derived: public Base
{
public:
    void access_base_members() {
        a = 100;
        b = 200;
        // c = 300;  // compiler error
    }
};

#endif // _MAIN_H_