#include <iostream>

using namespace std;

int main() {
    int counter {10};
    int result {0};

    cout << "counter: " << counter << endl;
    counter++;
    cout << "counter: " << counter << endl;
    ++counter;
    cout << "counter: " << counter << endl;
    result = ++counter; // counter += 1; result = counter;
    cout << "++counter: " << result << endl;
    result = counter++; // result = counter; counter += 1;
    cout << "counter++: " << result << endl;
    cout << "counter now: " << counter << endl;
    result = ++counter + 10; // counter += 1; result = counter + 10;
    cout << "++counter + 10: " << result << endl;
    result = counter++ + 10; // result = counter + 10; counter += 1;
    cout << "counter++ + 10: " << result << endl;
    cout << "counter now: " << counter << endl;
    return 0;
}