#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream in_file;
    // std::fstream in_file;
    std::string line;
    int num;
    double total;
    in_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section19 - IO and Streams\\ReadFile1\\src\\test.txt");
    // fstream needs std::ios_base::in or std::ios_base::out to open and write 
    // in_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section19 - IO and Streams\\ReadFile1\\src\\test.txt", std::ios_base::in);
    if (!in_file) // in_file.is_open()
    {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    in_file >> line >> num >> total;
    std::cout << line << std::endl;
    std::cout << num << std::endl;
    std::cout << total << std::endl;
    in_file.close();
    return 0;
}
