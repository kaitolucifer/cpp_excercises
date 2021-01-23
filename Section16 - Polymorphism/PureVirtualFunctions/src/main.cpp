#include <iostream>
#include <vector>
#include "include/main.h"

using namespace std;

void screen_refresh(std::vector <Shape *> &shapes)
{
    std::cout << "Refreshing" << std::endl;
    for (const auto &p: shapes)
        p->draw();
}

int main()
{
    // Shape s;
    // Shape *p = new Shape {};

    Shape *s1 = new Circle();
    Shape *s2 = new Line();
    Shape *s3 = new Square();

    std::vector<Shape *> shapes{s1, s2, s3};
    screen_refresh(shapes);

    delete s1;
    delete s2;
    delete s3;
    return 0;
}
