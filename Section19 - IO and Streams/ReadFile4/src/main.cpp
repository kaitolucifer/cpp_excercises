#include <iostream>
#include <fstream>

int main()
{
    std::ifstream in_file;
    in_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section19 - IO and Streams\\ReadFile4\\src\\poem.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    char c{};
    while (in_file.get(c))
    {
        std::cout << c;
    }
    in_file.close();
    return 0;
}
