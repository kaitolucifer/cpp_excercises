#ifndef _MAIN_H_
#define _MAIN_H_
#include <iostream>

class Base
{
public:
    virtual void say_hello() const
    {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived : public Base
{
public:
    virtual void say_hello() const override
    {
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

#endif // _MAIN_H_
