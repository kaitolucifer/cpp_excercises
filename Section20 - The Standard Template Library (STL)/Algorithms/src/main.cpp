#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <cctype>

class Person
{
    std::string name;
    int age;

public:
    Person() = default;
    Person(std::string name, int age) : name{name}, age{age} {}
    bool operator<(const Person &rhs) const
    {
        return this->age < rhs.age;
    }
    bool operator==(const Person &rhs)
    {
        return (this->name == rhs.name && this->age == rhs.age);
    }
};

void find_test()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    auto loc = std::find(std::begin(vec), std::end(vec), 1); // vec.begin(), vec.end()
    if (loc != std::end(vec))
        std::cout << "Found the number: " << *loc << std::endl;
    else
        std::cout << "Couldn't find the number" << std::endl;

    std::list<Person> players{
        {"Larry", 18},
        {"Moe", 20},
        {"Curly", 21},
    };
    auto loc1 = std::find(players.begin(), players.end(), Person("Moe", 20));
    if (loc1 != players.end())
        std::cout << "Found Moe" << std::endl;
    else
        std::cout << "Moe not found" << std::endl;
}

void count_test()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1};
    int num = std::count(vec.begin(), vec.end(), 1);
    std::cout << num << " occurrences found" << std::endl;
}

void count_if_test()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1, 100};
    int num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 == 0; });
    std::cout << num << " even numbers found" << std::endl;
    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x % 2 != 0; });
    std::cout << num << " odd numbers found" << std::endl;
    num = std::count_if(vec.begin(), vec.end(), [](int x) { return x >= 5; });
    std::cout << num << " numbers are >= 5 found" << std::endl;
}

void replace_test()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 1, 2, 1};
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
    std::replace(vec.begin(), vec.end(), 1, 100);
    for (auto i : vec)
        std::cout << i << " ";
    std::cout << std::endl;
}

void any_of_all_of_test()
{
    std::vector<int> vec{1, 3, 5, 7, 9, 1, 3, 13, 19, 5};
    if (std::any_of(vec.begin(), vec.end(), [](int x) { return x > 10; }))
        std::cout << "Any of the elements are > 10" << std::endl;
    else
        std::cout << "None of the elements are > 10" << std::endl;

    if (std::all_of(vec.begin(), vec.end(), [](int x) { return x < 20; }))
        std::cout << "All the elements are < 20" << std::endl;
    else
        std::cout << "Not all the elements are < 20" << std::endl;
}

void string_transform_test()
{
    std::string str{"This is a test"};
    std::cout << "Before transform: " << str << std::endl;
    std::transform(str.begin(), str.end(), str.begin(), ::toupper); // ::xxx means global scope
    std::cout << "After transform: " << str << std::endl;
}

int main()
{
    find_test();
    count_test();
    count_if_test();
    replace_test();
    any_of_all_of_test();
    string_transform_test();
    return 0;
}
