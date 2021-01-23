#include <iostream>
#include <set>
#include <map>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cctype>

void display_word_counts(const std::map<std::string, int> &words)
{
    std::cout << std::setw(12) << std::left << "Word"
              << std::setw(7) << std::right << "Count" << std::endl;
    std::cout << std::setw(20) << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ');
    for (const auto &pair : words)
    {
        std::cout << std::setw(12) << std::left << pair.first
                  << std::setw(7) << std::right << pair.second << std::endl;
    }
}

void display_word_occuurrences(const std::map<std::string, std::set<int>> &words)
{
    std::cout << std::setw(12) << std::left << "Word"
              << "Occurrences" << std::endl;
    std::cout << std::setw(50) << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ');
    for (const auto &pair : words)
    {
        std::cout << std::setw(12) << std::left << pair.first
                  << std::left << "[ ";
        for (const auto &i : pair.second)
            std::cout << i << " ";
        std::cout << "]" << std::endl;
    }
}

std::string preprocess_word(const std::string &word)
{
    std::string result;
    for (const char &c : word)
    {
        if (!std::ispunct(c))
        {
            result += std::tolower(c);
        }
    }
    return result;
}

void read_text(const std::string &file_path, std::stringstream &ss)
{
    std::ifstream in_file;
    in_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section20 - The Standard Template Library (STL)\\Challenge3\\src\\words.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
    }
    else
    {
        ss << in_file.rdbuf();
    }
    in_file.close();
}

void process_text(const std::string &file_path,
                  std::map<std::string, int> &word_counts,
                  std::map<std::string, std::set<int>> &word_occuurrences)
{
    std::stringstream ss;
    read_text(file_path, ss);
    std::string line;
    int line_no{1};
    while (std::getline(ss, line))
    {
        std::istringstream iss{line};
        std::string word;
        while (iss >> word)
        {
            word = preprocess_word(word);
            word_counts[word]++;
            word_occuurrences[word].insert(line_no);
        }
        line_no++;
    }
}

int main()
{
    std::map<std::string, int> word_counts;
    std::map<std::string, std::set<int>> word_occuurrences;
    process_text("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section20 - The Standard Template Library (STL)\\Challenge3\\src\\words.txt",
                 word_counts,
                 word_occuurrences);
    display_word_counts(word_counts);
    std::cout << std::endl;
    display_word_occuurrences(word_occuurrences);
    return 0;
}
