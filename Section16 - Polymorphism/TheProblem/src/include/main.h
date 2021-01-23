#ifndef _MAIN_H_
#define _MAIN_H_
#include <iostream>

class Base
{
public:
    void say_hello() const
    {
        std::cout << "Hello - I'm a Base class object" << std::endl;
    }
};

class Derived : public Base
{
public:
    void say_hello() const
    {
        std::cout << "Hello - I'm a Derived class object" << std::endl;
    }
};

void greetings(const Base &obj)
{
    std::cout << "Greetings: ";
    obj.say_hello();
}

#endif // _MAIN_H_
