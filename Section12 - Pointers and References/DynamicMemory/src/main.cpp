#include <iostream>

using namespace std;

int main()
{
    int *int_ptr {nullptr}; // in the stack (main function local variable)
    int_ptr = new int; // in the heap (freestore)
    cout << int_ptr << endl;
    cout << *int_ptr << endl;
    delete int_ptr;

    size_t size {};
    double *double_ptr {nullptr};
    cout << "How many elements? ";
    cin >> size;
    double_ptr = new double[size];
    cout << double_ptr << endl;
    delete [] double_ptr;
    return 0;
}