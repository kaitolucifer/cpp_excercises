#include <iostream>
#include <memory>

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

void my_deleter(Test *ptr)
{
    std::cout << "Using my custom function deleter" << std::endl;
    delete ptr;
}

int main()
{
    {
        std::shared_ptr<Test> ptr1{new Test(100), my_deleter};
    }
    {
        std::shared_ptr<Test> ptr2{new Test(1000),
                                   [](Test *ptr) {
            std::cout << "Using my custom lambda deleter" << std::endl;
            delete ptr; }};
    }

    return 0;
}
