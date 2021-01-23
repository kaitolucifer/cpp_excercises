#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <iomanip>
#include <cctype>


bool is_palindrome(const std::string &str)
{
    std::stack<char> s;
    std::queue<char> q;
    for(const char &c: str)
    {
        if (std::isalpha(c))
        {
            char lcase_c = std::tolower(c);
            s.push(lcase_c);
            q.push(lcase_c);
        }
    }
    while (!s.empty())
    {
        if (s.top() != q.front())
            return false;
        s.pop();
        q.pop();
    }
    return true;
}

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
    for (const auto &str : test_strings)
    {
        std::cout << std::setw(8) << std::left << is_palindrome(str) << str << std::endl;
    }
    return 0;
}
