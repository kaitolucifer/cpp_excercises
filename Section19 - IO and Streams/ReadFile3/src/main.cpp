#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in_file;
    in_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section19 - IO and Streams\\ReadFile3\\src\\poem.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    std::string line{};
    while(std::getline(in_file, line))
    {
        std::cout << line << std::endl;
    }
    in_file.close();
    return 0;
}
