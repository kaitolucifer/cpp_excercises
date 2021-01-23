#include <iostream>

using namespace std;

int main()
{
    int num1 {100};
    int num2 {200};

    const int *num_ptr_a {&num1};
    // *num_ptr_a = 200; // error
    num_ptr_a = &num2;

    int *const num_ptr_b {&num1};
    *num_ptr_b = 200;
    // num_ptr_b = &num2; // error

    const int *const num_ptr_c {&num1};
    // *num_ptr_c = 200; // error
    // num_ptr_c = &num2; // error
    return 0;
}