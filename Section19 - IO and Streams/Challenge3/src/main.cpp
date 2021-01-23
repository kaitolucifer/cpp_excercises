#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <unordered_map>

bool strcmp(const std::string &str1, const std::string &str2)
{
    size_t str1_size{str1.size()};
    size_t str2_size{str2.size()};
    bool match_flag{};
    for (size_t i{}; i < str2_size; i++)
    {
        if (std::tolower(str2.at(i)) == std::tolower(str1.at(0)))
        {
            match_flag = true;
            for (size_t j{1}; j < str1_size; j++)
            {
                if (i + j >= str2_size ||
                    std::tolower(str2.at(i + j)) != std::tolower(str1.at(j)))
                {
                    match_flag = false;
                    break;
                }
            }
            if (match_flag)
                return match_flag;
        }
    }
    return false;
}

void count_all_words(std::ifstream &in_file,
                     int &word_num,
                     std::unordered_map<std::string, int> &word_counter)
{
    std::string word{};
    while (in_file >> word)
    {
        word_num++;
        auto itr = word_counter.find(word);
        if (itr != word_counter.end())
        {
            word_counter[word]++;
        }
        else
        {
            word_counter[word] = 1;
        }
    }
}

int get_match_word_counts(const std::string &word,
                          const std::unordered_map<std::string, int> &word_counter)
{
    int word_counts{};
    for (auto itr = word_counter.begin(); itr != word_counter.end(); itr++)
    {
        if (strcmp(word, itr->first)) {
            word_counts += itr->second;
        }
    }
    return word_counts;
}

int main()
{
    std::ifstream in_file;
    in_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section19 - IO and Streams\\Challenge3\\src\\romeoandjuliet.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }

    int word_num{};
    std::unordered_map<std::string, int> word_counter;
    count_all_words(in_file, word_num, word_counter);

    std::string word{};
    std::cout << "Enter the substring to search for: ";
    std::cin >> word;

    std::cout << word_num << " words were searched..." << std::endl;
    std::cout << "The substring " << word << " was found "
              << get_match_word_counts(word, word_counter) << " times"
              << std::endl;

    in_file.close();
    return 0;
}
