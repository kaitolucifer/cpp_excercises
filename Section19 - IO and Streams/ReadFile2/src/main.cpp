#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    std::ifstream in_file;
    std::string line;
    int num;
    double total;
    in_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section19 - IO and Streams\\ReadFile2\\src\\test.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    while(in_file >> line >> num >> total) {
        std::cout << std::setw(10) << std::left << line
                  << std::setw(10) << num
                  << std::setw(10) << total
                  << std::endl;
    }
    in_file.close();
    return 0;
}
