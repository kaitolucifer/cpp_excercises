#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::ifstream in_file;
    in_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section19 - IO and Streams\\CopyFile2\\src\\poem.txt");
    std::ofstream out_file;
    out_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section19 - IO and Streams\\CopyFile2\\src\\poem_out.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening input file" << std::endl;
        return 1;
    }
    if (!out_file)
    {
        std::cerr << "Problem opening output file" << std::endl;
        return 1;
    }

    char c;
    while (in_file.get(c))
    {
        out_file.put(c);
    }
    std::cout << "File copied" << std::endl;

    in_file.close();
    out_file.close();
    return 0;
}
