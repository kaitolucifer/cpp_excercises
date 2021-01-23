#include <iostream>
#include <vector>

using namespace std;

int main()
{
    char selection {};
    vector<int> numbers {};
    do {
        cout << "P - Print numbers" << endl;
        cout << "A - Add a number" << endl;
        cout << "M - Display mean of the numbers" << endl;
        cout << "S - Display the smallest number" << endl;
        cout << "L - Display the largest number" << endl;
        cout << "Q - Quit" << endl;
        cout << "\nEnter your choice: ";
        cin >> selection;
        switch (selection)
            {
            case 'p':
            case 'P':
                {
                    cout << "[ ";
                    for (auto num: numbers) {
                        cout << num << " ";
                    }
                    cout << "]" << endl;
                    break;
                }
            case 'a':
            case 'A':
                {
                    int num;
                    cout << "Enter an integer to add to the list: ";
                    cin >> num;
                    numbers.push_back(num);
                    cout << num << " Added" << endl;
                    break;
                }
            case 'm':
            case 'M':
                {
                    if (numbers.size() == 0) {
                        cout << "Empty" << endl;
                    } else {
                        int sum {};
                        for (auto num: numbers) {
                            sum += num;
                        }
                        cout << "Mean: " << static_cast<double> (sum) / numbers.size()<< endl;
                    }
                    break;
                }
            case 's':
            case 'S':
                {
                    if (numbers.size() == 0) {
                        cout << "Empty" << endl;
                    } else {
                        int min {numbers.at(0)};
                        for (auto num: numbers) {
                            if (num < min) {
                                min = num;
                            }
                        }
                        cout << "The smallest number: " << min << endl;
                    }
                    break;
                }
            case 'l':
            case 'L':
                {
                    if (numbers.size() == 0) {
                        cout << "Empty" << endl;
                    } else {
                        int max {numbers.at(0)};
                        for (auto num: numbers) {
                            if (num > max) {
                                max = num;
                            }
                        }
                        cout << "The largest number: " << max << endl;
                    }
                    break;
                }
            case 'q':
            case 'Q':
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Unknown option -- try again..." << endl;
            }
    } while (selection != 'q' && selection != 'Q');
    return 0;
}