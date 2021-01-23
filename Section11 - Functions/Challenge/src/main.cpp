#include <iostream>
#include <vector>
#include <string>

using namespace std;

void display_menu();
void input_selection(char &selection);
void print_numbers(const vector<int> &numbers);
void add_number(vector<int> &numbers);
void print_mean_of_numbers(const vector<int> &numbers);
void print_min_of_numbers(const vector<int> &numbers);
void print_max_of_numbers(const vector<int> &numbers);
double calc_mean_of_numbers(const vector<int> &numbers);
int calc_min_of_numbers(const vector<int> &numbers);
int calc_max_of_numbers(const vector<int> &numbers);
inline void quit_program(const string message = "Goodbye");
inline void unknown_selection(const string message = "Unknown option -- try again...");

int main()
{
    char selection {};
    vector<int> numbers {};
    do {
        display_menu();
        input_selection(selection);
        switch (selection) {
            case 'p':
            case 'P':
                print_numbers(numbers);
                break;
            case 'a':
            case 'A':
                add_number(numbers);
                break;
            case 'm':
            case 'M':
                print_mean_of_numbers(numbers);
                break;
            case 's':
            case 'S':
                print_min_of_numbers(numbers);
                break;
            case 'l':
            case 'L':
                print_max_of_numbers(numbers);
                break;
            case 'q':
            case 'Q':
                quit_program();
                break;
            default:
                unknown_selection(); 
            }
    } while (selection != 'q' && selection != 'Q');
    return 0;
}

void display_menu() {
    cout << "P - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "Q - Quit" << endl;
}

void input_selection(char &selection) {
    cout << "\nEnter your choice: ";
    cin >> selection;
}

void print_numbers(const vector<int> &numbers) {
    cout << "[ ";
    for (auto num: numbers) {
        cout << num << " ";
    }
    cout << "]" << endl;
}

void add_number(vector<int> &numbers) {
    int number;
    cout << "Enter an integer to add to the list: ";
    cin >> number;
    numbers.push_back(number);
    cout << number << " Added" << endl;
}

double calc_mean_of_numbers(const vector<int> &numbers) {
    int sum {};
    for (auto num: numbers)
        sum += num;
    return static_cast<double> (sum) / numbers.size();
}

void print_mean_of_numbers(const vector<int> &numbers) {
    if (numbers.size() == 0) {
        cout << "Empty" << endl;
    } else {
        cout << "Mean: " << calc_mean_of_numbers(numbers) << endl;
    }
}

int calc_min_of_numbers(const vector<int> &numbers) {
    int min {numbers.at(0)};
    for (auto num: numbers) {
        if (num < min) {
            min = num;
        }
    }
    return min;
}

void print_min_of_numbers(const vector<int> &numbers) {
    if (numbers.size() == 0) {
        cout << "Empty" << endl;
    } else {
        cout << "The smallest number: " << calc_min_of_numbers(numbers) << endl;
    }
}

int calc_max_of_numbers(const vector<int> &numbers) {
    int max {numbers.at(0)};
    for (auto num: numbers) {
        if (num > max) {
            max = num;
        }
    }
    return max;
}

void print_max_of_numbers(const vector<int> &numbers) {
    if (numbers.size() == 0) {
        cout << "Empty" << endl;
    } else {
        cout << "The largest number: " << calc_max_of_numbers(numbers) << endl;
    }
}

inline void quit_program(const string message) {
    cout << message << endl;
}

inline void unknown_selection(const string message) {
    cout << message << endl;
}