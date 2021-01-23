#include <iostream>
#include <deque>
#include <string>
#include <cctype>
#include <vector>
#include <iomanip>

bool is_palindrome(const std::string &s);
std::deque<char> string2deque(const std::string &s);

int main()
{
    std::vector<std::string> test_strings{"a", "aa", "aba", "abba",
                                          "abbcbba", "ab", "abc", "radar",
                                          "bob", "ana", "avid diva", "Amore, Roma",
                                          "A Toyota's a toyota", "A Santa at NASA", "C++",
                                          "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!",
                                          "This is a palindrome", "palindrome"};
    std::cout << std::boolalpha;
    std::cout << std::setw(8) << std::left << "Result"
              << "String" << std::endl;
    for (const auto &s : test_strings)
    {
        std::cout << std::setw(8) << std::left << is_palindrome(s) << s << std::endl;
    }
    return 0;
}

bool is_palindrome(const std::string &s)
{
    std::deque<char> d = string2deque(s);
    while ((d.size() > 1) && (d.front() == d.back()))
    {
        d.pop_front();
        d.pop_back();
    }
    if (d.size() > 1) {
        return false;
    } else {
        return true;
    }
}

std::deque<char> string2deque(const std::string &s)
{
    std::deque<char> d;
    for (const char &c: s)
    {
        if (std::isalpha(c)) {
            d.push_back(std::toupper(c));
        }
    }
    return d;
}
