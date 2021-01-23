#include <iostream>
#include <string>

#include "include/main.h"

double calculate_mpg(int miles, int gallons)
{
    if (gallons == 0)
        throw DivideByZeroException{};
    if (miles < 0 || gallons < 0)
        throw NegativeValueException{};
    return static_cast<double>(miles) / gallons;
}

int main()
{
    int miles{};
    int gallons{};
    double miles_per_gallon{};
    std::cout << "Etner the miles: ";
    std::cin >> miles;
    std::cout << "Enter the gallons: ";
    std::cin >> gallons;
    try
    {
        miles_per_gallon = calculate_mpg(miles, gallons);
        std::cout << "Results: " << miles_per_gallon << std::endl;
    }
    catch (const DivideByZeroException &ex)
    {
        std::cerr << "Sorry, you can't divide by zero" << std::endl;
    }
    catch (const NegativeValueException &ex)
    {
        std::cerr << "Negative vlue error" << std::endl;
    }
    catch (...)
    {
        std::cerr << "Unknown exception" << std::endl;
    }
    std::cout << "Bye" << std::endl;

    return 0;
}
