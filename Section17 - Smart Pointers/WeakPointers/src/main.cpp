#include <iostream>
#include <memory>

class B;    // forward declaration

class A
{
    std::shared_ptr<B> b_ptr;
public:
    void set_B(std::shared_ptr<B> &b)
    {
        b_ptr = b;
    }
    A() {std::cout << "A Constructror" << std::endl;}
    ~A() {std::cout << "A Destructror" << std::endl;}
};

class B
{
    // std::shared_ptr<A> a_ptr;
    std::weak_ptr<A> a_ptr;
public:
    void set_A(std::shared_ptr<A> &a)
    {
        a_ptr = a;
    }
    B() {std::cout << "B Constructror" << std::endl;}
    ~B() {std::cout << "B Destructror" << std::endl;}
};

int main()
{
    std::shared_ptr<A> a {std::make_shared<A>()};
    std::shared_ptr<B> b {std::make_shared<B>()};
    a->set_B(b);
    b->set_A(a);

    return 0;
}
