#include <iostream>
#include <algorithm>
#include <set>
#include <string>

class Person
{
    friend std::ostream &operator<<(std::ostream &os, const Person &p);
    std::string name;
    int age;

public:
    Person() : name{"Unknown"}, age{0} {}
    Person(std::string name, int age) : name{name}, age{age} {}
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs) const
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

std::ostream &operator<<(std::ostream &os, const Person &p)
{
    os << p.name << ": " << p.age;
    return os;
}

template <typename T>
void display(const std::set<T> &l)
{
    std::cout << "[ ";
    std::for_each(l.begin(), l.end(), [](T item) { std::cout << item << " "; });
    std::cout << "]" << std::endl;
}

void test1()
{
    std::cout << "Test1: " << std::endl;
    std::set<int> s1{1, 4, 3, 5, 2};
    display(s1);
    s1 = {1, 2, 3, 1, 1, 2, 2, 3, 3, 4, 5};
    display(s1);
    s1.insert(0);
    s1.insert(10);
    display(s1);
    if (s1.count(10))
        std::cout << "10 is in the set" << std::endl;
    else
        std::cout << "10 is NOT in the set" << std::endl;
    auto it = s1.find(5);
    if (it != s1.end())
        std::cout << "Found: " << *it << std::endl;
    s1.clear();
    display(s1);
}

void test2()
{
    std::cout << "Test2: " << std::endl;
    std::set<Person> stooges{
        {"Larry", 18},
        {"Moe", 25},
        {"Curly", 17}};
    display(stooges); // Using operator< to order
    stooges.emplace("James", 50);
    display(stooges);
    stooges.emplace("Frank", 50); // 50 already exists
    display(stooges);
    auto it = stooges.find(Person{"Moe", 2});
    if (it != stooges.end())
        stooges.erase(it);
    display(stooges);
    it = stooges.find(Person{"XXXX", 50}); // using operator< so James will be erased
    if (it != stooges.end())
        stooges.erase(it);
    display(stooges);
}

void test3()
{
    std::cout << "Test3: " << std::endl;
    std::set<std::string> s{"A", "B", "C"};
    auto result = s.insert("D");
    display(s);
    std::cout << std::boolalpha;
    std::cout << "first: " << *(result.first) << std::endl;
    std::cout << "second: " << result.second << std::endl;
    result = s.insert("A");
    display(s);
    std::cout << "first: " << *(result.first) << std::endl;
    std::cout << "second: " << result.second << std::endl;
}

int main()
{
    test1();
    test2();
    test3();
    return 0;
}
