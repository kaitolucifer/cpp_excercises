#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <list>

void display(const std::vector<int> &vec)
{
    std::cout << "[ ";
    for (auto const &i : vec)
        std::cout << i << " ";
    std::cout << "]" << std::endl;
}

void it_test1()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    auto it = vec.begin(); // point to 1
    std::cout << *it << std::endl;
    it++; // point to 2
    std::cout << *it << std::endl;
    it += 2; // point to 4
    std::cout << *it << std::endl;
    it -= 2; // point to 2
    std::cout << *it << std::endl;
    it = vec.end() - 1; // point to 5
    std::cout << *it << std::endl;
}

void it_test2()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    // loop all elemtns
    std::vector<int>::iterator it = vec.begin();
    while (it != vec.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    // change all vector elements to 0
    it = vec.begin();
    while (it != vec.end())
    {
        *it = 0;
        it++;
    }
    display(vec);
}

void it_test3()
{
    std::vector<int> vec{1, 2, 3, 4, 5};
    std::vector<int>::const_iterator it = vec.begin();
    // auto it = vec.cbegin(); 
    while (it != vec.end())
    {
        std::cout << *it << std::endl;
        it++;
    }
    it = vec.begin();
    while(it != vec.end())
    {
        // *it = 0;  // Complier error - read only
        it++;
    }
}

void it_test4()
{
    std::vector<int> vec{1, 2, 3, 4};
    auto it1 = vec.rbegin();
    while(it1 != vec.rend())
    {
        std::cout << *it1 << std::endl;
        it1++;
    }

    std::list <std::string> name{"Larry", "Moe", "Curly"};
    auto it2 = name.crbegin();  // const reverse iterator
    std::cout << *it2 << std::endl; // point to "Curly"
    it2++;
    std::cout << *it2 << std::endl;

    std::map<std::string, std::string> favorites{
        {"Frank", "C++"},
        {"Bill", "Java"},
        {"James", "Haskell"}
    };
    auto it3 = favorites.begin();
    while(it3 != favorites.end())
    {
        std::cout << it3->first << ": " << it3->second << std::endl;
        it3++;
    }
}

void it_test5()
{
    std::vector<int> vec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    auto start = vec.begin() + 2;
    auto finish = vec.end() - 3;
    while(start != finish)
    {
        std::cout << *start << std::endl;
        start++;
    }
}

int main()
{
    it_test1();
    it_test2();
    it_test3();
    it_test4();
    it_test5();

    return 0;
}
