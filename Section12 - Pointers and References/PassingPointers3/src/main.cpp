#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display(const vector<string> *const v);
void display(const int *array, const int sentinel);

void display(const vector<string> *const v) {
    for (auto str: *v)
        cout << str << " ";
    cout << endl;
}

void display(const int *array, const int sentinel) {
    while(*array != sentinel)
        cout << *array++ << " ";
    cout << endl;
}

int main()
{
    vector<string> stooges {"Larry", "Moe", "Curly"};
    display(&stooges);
    cout << endl;
    int scores[] {100, 98, 97, 79, 85, -1};
    display(scores, -1);
    return 0;
}