#include <iostream>
#include <string>

template <typename T> // template <class T>
T max(T a, T b)
{
    return (a > b) ? a : b;
}

template <typename T1, typename T2>
void func(T1 a, T2 b)
{
    std::cout << a << " " << b << std::endl;
}

struct Person
{
    std::string name;
    int age;
    bool operator>(const Person &rhs) const
    {
        return this->age > rhs.age;
    }
};

std::ostream &operator<<(std::ostream &os, const Person &rhs)
{
    os << rhs.name;
    return os;
}

template <typename T>
void my_swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int x{100};
    int y{200};
    std::cout << x << ", " << y << std::endl;
    my_swap(x, y);
    std::cout << x << ", " << y << std::endl;

    Person p1{"Curly", 50};
    Person p2{"Moe", 30};
    Person p3 = max(p1, p2);
    std::cout << p3.name << " is older" << std::endl;
    func(p1, p2);

    std::cout << max<int>(2, 3) << std::endl;
    std::cout << max(2, 3) << std::endl;
    std::cout << max('A', 'B') << std::endl;
    std::cout << max(12.5, 9.2) << std::endl;
    std::cout << max(5 + 2 * 2, 7 + 40) << std::endl;

    func<int, int>(10, 20);
    func(10, 20);
    func<char, double>('A', 12.4);
    func('A', 12.4);
    func(1000, "Testing");
    func(2000, std::string{"Frank"});

    return 0;
}
