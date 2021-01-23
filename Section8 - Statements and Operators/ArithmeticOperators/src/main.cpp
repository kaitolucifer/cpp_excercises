#include <iostream>

using namespace std;

int main() {

    int num1 {200};
    int num2 {100};

    cout << num1 << " + " << num2 << " = " << num1+num2 << endl;
    cout << num1 << " - " << num2 << " = " << num1-num2 << endl;
    cout << num1 << " * " << num2 << " = " << num1*num2 << endl;
    cout << num1 << " / " << num2 << " = " << num1/num2 << endl;
    cout << num2 << " / " << num1 << " = " << num2/num1 << endl;
    num1 = 10;
    num2 = 3;
    cout << num1 << " % " << num2 << " = " << num1%num2 << endl;
    cout << 5 << " / " << 10 << " = " << 5/10 << endl;
    cout << "5.0" << " / " << "10.0" << " = " << 5.0/10.0 << endl;
    return 0;
}
