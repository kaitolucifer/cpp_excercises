#ifndef _MAIN_H_
#define _MAIN_H_
#include <iostream>

class Base
{
private:
    int value;

public:
    Base() : value {0} { std::cout << "Base no-args constructor" << std::endl; }
    Base(int x) : value {x} { std::cout << "Base(int) overloaded constructor" << std::endl; }
    ~Base() { std::cout << "Base destructor" << std::endl; }
};

class Derived : public Base
{
private:
    int doubled_value;

public:
    Derived() : Base{}, doubled_value{0}
    {
        std::cout << "Derived no-args constructor" << std::endl;
    }
    Derived(int x) : Base{x}, doubled_value{x * 2}
    {
        std::cout << "Derived(int) overloaded constructor" << std::endl;
    }
    ~Derived()
    {
        std::cout << "Derived destructor" << std::endl;
    }
};

#endif // _MAIN_H_
