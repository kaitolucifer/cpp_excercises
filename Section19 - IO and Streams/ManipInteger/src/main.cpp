#include <iostream>
#include <iomanip>

int main()
{
    int num{255};

    std::cout << "Displaying using different bases: " << std::endl;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "Displaying showing the base prefix: " << std::endl;
    std::cout << std::showbase;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "Display the hex value in uppercase" << std::endl;
    std::cout << std::uppercase;
    std::cout << std::hex << num << std::endl;

    std::cout << "Display the + sign in front of positive base 10 numbers" << std::endl;
    std::cout << std::showpos;
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;
    std::cout << std::oct << num << std::endl;

    std::cout << "Setting using the set method" << std::endl;
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);
    std::cout << std::dec << num << std::endl;
    std::cout << std::hex << num << std::endl;

    std::cout << "Resetting to defaults" << std::endl;
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);
    std::cout << num << std::endl;

    return 0;
}
