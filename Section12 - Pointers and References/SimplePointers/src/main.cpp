#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    int num {10};
    cout << "Value of num is: " << num << endl;
    cout << "sizeof of num is: " << sizeof num << endl;
    cout << "Address of num is: " << &num << endl;
    cout << "Address of num is: " << sizeof &num << endl;

    int *p;
    cout << "\nValue of p is: " << p << endl;
    cout << "Address of ps is: " << &p << endl;
    cout << "sizeof of p is: " << sizeof p << endl;
    p = nullptr;
    cout << "\nValue of p is: " << p << endl;

    int *p1 {nullptr};
    double *p2 {nullptr};
    unsigned long long *p3 {nullptr};
    vector<string> *p4 (nullptr);
    string *p5 {nullptr};
    cout << "\nsizeof p1 is: " << sizeof p1 << endl;
    cout << "sizeof p2 is: " << sizeof p2 << endl;
    cout << "sizeof p3 is: " << sizeof p3 << endl;
    cout << "sizeof p4 is: " << sizeof p4 << endl;
    cout << "sizeof p5 is: " << sizeof p5 << endl;

    int int_num {10};
    int *int_ptr {nullptr};
    int_ptr = &int_num;
    cout << "Value of int_num is: " << int_num << endl;
    cout << "Address of int_num is: " << &int_num << endl;
    cout << "Value of int_ptr is: " << int_ptr << endl;
    // double double_num {100.7};
    // int_ptr = &double_num; // Compiler error

    return 0;
}