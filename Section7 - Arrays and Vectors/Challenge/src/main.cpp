#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector <int> vec1;
    vec1.push_back(10);
    vec1.push_back(20);
    cout << "vec1:" << endl;
    cout << vec1.at(0) << endl;
    cout << vec1.at(1) << endl;
    cout << vec1.size() << endl;

    vector <int> vec2;
    vec2.push_back(100);
    vec2.push_back(200);
    cout << "vec2:" << endl;
    cout << vec2.at(0) << endl;
    cout << vec2.at(1) << endl;
    cout << vec2.size() << endl;

    vector <vector <int>> vec_2d;
    vec_2d.push_back(vec1);
    vec_2d.push_back(vec2);
    cout << "vec_2d:" << endl;
    cout << vec_2d.at(0).at(0) << endl;
    cout << vec_2d.at(0).at(1) << endl;
    cout << vec_2d.at(1).at(0) << endl;
    cout << vec_2d.at(1).at(1) << endl;

    cout << "change vec1:" << endl;
    vec1.at(0) = 1000;
    cout << "vec_2d now:" << endl;
    cout << vec_2d.at(0).at(0) << endl;
    cout << vec_2d.at(0).at(1) << endl;
    cout << vec_2d.at(1).at(0) << endl;
    cout << vec_2d.at(1).at(1) << endl;
    cout << "vec1 now:" << endl;
    cout << vec1.at(0) << endl;
    cout << vec1.at(1) << endl;

    return 0;
}