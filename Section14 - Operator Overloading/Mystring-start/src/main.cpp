#include <iostream>
#include "Mystring.h"

using namespace std;

int main()
{
    Mystring empty;
    Mystring larry("Larry");
    Mystring stooge {larry};

    empty.display();
    larry.display();
    stooge.display();
    cout << larry.get_str() << endl;
    return 0;
}