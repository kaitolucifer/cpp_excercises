#include <iostream>
#include <string>

using namespace std;

int main()
{
    string letters {};
    cout << "Enter some letters: ";
    getline(cin, letters);
    size_t bottom_len {2 * letters.length() - 1};
    for (size_t i {}; i < letters.length(); ++i) {
        string row (bottom_len, ' '); // initialize a row of pyramid with white space
        string row_letters (i * 2 + 1, letters.at(i)); // actual letters to display in a row
        if (i != 0) {
            for (size_t j {}; j < i; ++j) {
                // assign the same letter symmetrically
                row_letters.at(j) = letters.at(j);
                row_letters.at(row_letters.length() - j - 1) = letters.at(j);
            }
        }
        // replace white spaces in a row with actual letters
        cout << row.replace(letters.length() - i - 1, row_letters.length(),  row_letters) << endl;
    }
    return 0;
}