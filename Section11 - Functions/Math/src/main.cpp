#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double num {};
    cout << "Enter a number (double): ";
    cin >> num;
    cout << "sqrt: " << sqrt(num) << endl;
    cout << "cubed root: " << cbrt(num) << endl;
    cout << "sin: " << sin(num) << endl;
    cout << "cos: " << cos(num) << endl;
    cout << "ceil: " << ceil(num) << endl;
    cout << "floor: " << floor(num) << endl;
    cout << "round: " << round(num) << endl;
    double power {};
    cout << "\nEnter a power to raise " << num << " to: ";
    cin >> power;
    cout << num << "raised to the " << power << " power is: " << pow(num, power) << endl;
    return 0;
}