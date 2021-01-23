#include <iostream>
#include <memory>
#include <vector>

#include "include/main.h"

auto make();
void fill(std::vector<std::shared_ptr<Test>> &vec, int num);
void display(const std::vector<std::shared_ptr<Test>> &vec);

auto make()
{
    return std::make_unique<std::vector<std::shared_ptr<Test>>>();
}

void fill(std::vector<std::shared_ptr<Test>> &vec, int num)
{
    for (size_t i{}; i < static_cast<size_t>(num); i++)
    {
        std::cout << "Enter data point"
                  << "[" << i + 1 << "]"
                  << " : ";
        int data;
        std::cin >> data;
        vec.push_back(std::make_shared<Test>(data));
    }
}

void display(const std::vector<std::shared_ptr<Test>> &vec)
{
    std::cout << "Displaying vector data:" << std::endl;
    std::cout << "***********************" << std::endl;
    for (auto &t : vec)
        std::cout << t->get_data() << std::endl;
    std::cout << "***********************" << std::endl;
}

int main()
{
    std::unique_ptr<std::vector<std::shared_ptr<Test>>> vec_ptr;
    vec_ptr = make();
    std::cout << "How many data points do you want to enter: ";
    int num;
    std::cin >> num;
    fill(*vec_ptr, num);
    display(*vec_ptr);
    return 0;
}
