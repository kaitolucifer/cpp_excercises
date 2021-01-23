#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    cout << "Hello" << " world!" << endl;
    cout << "Hello\nOut\nThere\n";

    int num1;
    // int num2;
    double num3;

    // If you entered "10 100" first,
    // it won't wait for you to enter the second double
    // and will display "You entered 10 and 100" immediately.
    // cout << "Enter a first integer: ";
    // cin >> num1;
    // cout << "Enter a second integer: ";
    // cin >> num2;

    // cout << "You entered " << num1 << " and " << num2 << endl;

    // cout << "Enter 2 integers separated with a space: ";
    // cin >> num1 >> num2;
    // cout << "You entered " << num1 << " and " << num2 << endl;

    // If you entered 10.5 first
    // it won't wait for you to enter the second double
    // and will display "You entered 10 and 0.5" immediately.
    // If you entered some string first
    // it will display "You entered 0 and <extreamly small double number>" immediately
    cout << "Enter a integer: ";
    cin >> num1;
    cout << "Enter a double: ";
    cin >> num3;
    cout << "You entered " << num1 << " and " << num3 << endl;
    
    return 0;
}
