#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

int main()
{
    std::ifstream in_file;
    in_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section19 - IO and Streams\\Challenge4\\src\\romeoandjuliet.txt");
    std::ofstream out_file;
    out_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section19 - IO and Streams\\Challenge4\\src\\romeoandjuliet_with_line_num.txt");
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

    std::string line;
    int line_no{1};
    while (std::getline(in_file, line))
    {
        if (line.empty())
        {
            out_file << line << std::endl;
        }
        else
        {
            out_file << std::setw(10) << std::left << line_no << line << std::endl;
            line_no++;
        }
    }

    return 0;
}
