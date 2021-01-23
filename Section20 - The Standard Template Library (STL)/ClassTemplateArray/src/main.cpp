#include <iostream>
#include <string>

// Note: Since C++11 the STL has std::array which is template-based array class
// Use std::array instead of raw arrays whenever possible

// Note that we can have non-type template parameters
// That's what N is in this case

template <typename T, int N>
class Array
{
    int size{N};
    T values[N];

    friend std::ostream &operator<<(std::ostream &os, const Array<T, N> &arr)
    {
        os << "[ ";
        for (const auto &val: arr.values)
            os << val << " ";
        os << "]";
        return os;
    }
public:
    Array() = default;
    Array(T init_val)
    {
        for (auto &item: values)
            item = init_val;
    }
    void fill(T val)
    {
        for (auto &item: values)
            item = val;
    }
    int get_size() const
    {
        return size;
    }
    T &operator[](int index)
    {
        return values[index];
    }
    Array &operator=(const std::initializer_list<int>& other) {
        *this = Array(*other.begin());
        return *this;
    }
};

int main()
{
    Array<int, 5> nums;
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;
    nums.fill(0);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;
    nums.fill(10);
    std::cout << "The size of nums is: " << nums.get_size() << std::endl;
    std::cout << nums << std::endl;
    nums[0] = 1000;
    nums[3] = 2000;
    std::cout << nums << std::endl;

    Array<int, 100> nums2 {1};
    std::cout << "The size of nums2 is: " << nums2.get_size() << std::endl;
    std::cout << nums2 << std::endl;

    Array<std::string, 10> strings{std::string{"Frank"}};
    std::cout << "The size of strings is: " << strings.get_size() << std::endl;
    std::cout << strings << std::endl;
    strings[0] = std::string{"Larry"};
    std::cout << strings << std::endl;
    strings.fill(std::string{"X"});
    std::cout << strings << std::endl;

    Array<int, 5> test {1};
    std::cout << test << std::endl;
    test = {5};
    std::cout << test << std::endl;

    return 0;
}
