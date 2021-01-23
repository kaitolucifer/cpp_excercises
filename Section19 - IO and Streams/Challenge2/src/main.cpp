#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

void print_table_column_names()
{
    std::cout << std::setw(10) << std::left << "Student"
              << std::setw(10) << std::right << "Score" << std::endl;
    std::cout << std::setfill('-') << std::setw(20) << "" << std::endl;
    std::cout << std::setfill(' ');
}

void print_data(const std::string &name, const int &score)
{
    std::cout << std::setw(10) << std::left << name
              << std::setw(8) << std::right << score << std::endl;
}

void print_average_score(const double average_score)
{
    std::cout << std::setfill('-') << std::setw(20) << "" << std::endl;
    std::cout << std::setfill(' ');
    std::cout << std::setw(10) << std::left << "Average Score"
              << std::setw(7) << std::right << std::setprecision(2) << std::fixed
              <<average_score << std::endl;
}

int calc_score(const std::string &correct_responses, const std::string &student_responses)
{
    int score{0};
    for (size_t i{}; i < correct_responses.size(); i++)
    {
        if (correct_responses.at(i) == student_responses.at(i))
        {
            score++;
        }
    }
    return score;
}

int main()
{
    std::ifstream in_file;
    in_file.open("C:\\Users\\kaito\\OneDrive\\Documents\\Cpp\\Section19 - IO and Streams\\Challenge2\\src\\responses.txt");
    if (!in_file)
    {
        std::cerr << "Problem opening file" << std::endl;
        return 1;
    }
    std::string correct_responses{};
    std::getline(in_file, correct_responses);
    print_table_column_names();
    double average_score{0.0};
    int student_num{};
    std::string name{};
    std::string response{};
    int score{};
    while (!in_file.eof())
    {
        in_file >> name >> response;
        if (name.empty() || response.empty())
        {
            break;
        }
        score = calc_score(correct_responses, response);
        average_score += score;
        student_num++;
        print_data(name, score);
    }
    print_average_score(average_score / student_num);
    in_file.close();
    return 0;
}
