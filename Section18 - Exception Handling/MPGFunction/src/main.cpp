#include <iostream>

double calculate_mpg(int miles, int gallons)
{
    if (gallons == 0)
        throw 0;
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
    catch (int &ex)
    {
        std::cerr << "Sorry, you can't divide by zero" << std::endl;
    }
    std::cout << "Bye" << std::endl;

    return 0;
}
