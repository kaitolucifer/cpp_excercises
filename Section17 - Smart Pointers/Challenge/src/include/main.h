#ifndef _MAIN_H_
#define _MAIN_H_
#include <iostream>

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

#endif // _MAIN_H_
