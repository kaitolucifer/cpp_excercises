#include <cstring>
#include <iostream>
#include "Mystring.h"

// No-args constructor
Mystring::Mystring() : str {nullptr} {
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) : str {nullptr} {
    if (s==nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

//Copy constructor
Mystring::Mystring(const Mystring &source) : str {nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

//Move constructor
Mystring::Mystring(Mystring &&source) : str {source.str} {
    source.str = nullptr;
}

// Destructor
Mystring::~Mystring() {
    delete [] str;
}

// Copy assignment
Mystring &Mystring::operator=(const Mystring &rhs) {
    // std::cout << "Copy assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] this->str;
    str = new char[std::strlen(rhs.str) + 1];
    std::strcpy(this->str, rhs.str);
    return *this;
}

// Move assignment
Mystring &Mystring::operator=(Mystring &&rhs) {
    // std::cout << "Move assignment" << std::endl;
    if (this == &rhs)
        return *this;
    delete [] str;
    str = rhs.str;
    rhs.str = nullptr;
    return *this;
}

// Display method
void Mystring::display() const {
    std::cout << str << ": " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const {return std::strlen(str);}

// string getter
const char *Mystring::get_str() const {return str;}

// overloaded insertion operator
std::ostream &operator<<(std::ostream &os, const Mystring &rhs) {
    os << rhs.str;
    return os;
}

// overloaded extraction operator
std::istream &operator>>(std::istream &is, Mystring &rhs) {
    char *buff = new char[1000];
    is >> buff;
    rhs = Mystring {buff};
    delete[] buff;
    return is;
}

// lowercase
Mystring Mystring::operator-() const {
    size_t str_len {std::strlen(this->str)};
    char *buff = new char[str_len + 1];
    std::strcpy(buff, this->str);
    for (size_t i {0}; i < str_len; i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete[] buff;
    return temp;
}

// string equality
bool Mystring::operator==(const Mystring &rhs) const {
    return (std::strcmp(this->str, rhs.str) == 0);
}

// inequality
bool Mystring::operator!=(const Mystring &rhs) const {
    return !this->operator==(rhs);
}

// string lexically less than
bool Mystring::operator<(const Mystring &rhs) const {
    return this->str < rhs.str;
}

 // string lexically greater than
bool Mystring::operator>(const Mystring &rhs) const {
    return !this->operator<(rhs);
}

// concatenation
Mystring Mystring::operator+(const Mystring &rhs) const {
    size_t str1_len = std::strlen(this->str);
    size_t str2_len = std::strlen(rhs.str);
    char *buff = new char[str1_len + str2_len + 1];
    std::strcpy(buff, this->str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete[] buff;
    return temp;
}

// concatenation and store
Mystring &Mystring::operator+=(const Mystring &rhs) {
    *this = *this + rhs;
    return *this;
}

// repeat with r-value
Mystring Mystring::operator*(const size_t &&n) const {
    Mystring temp;
    for (size_t i {}; i < n; i++)
        temp += *this;
    return temp;
}

// repeat with l-value
Mystring Mystring::operator*(const size_t &n) const {
    Mystring temp;
    for (size_t i {}; i < n; i++)
        temp += *this;
    return temp;
}

// repeat and store with r-value
Mystring &Mystring::operator*=(const size_t &&n) {
    *this += *this * (n - 1);
    return *this;
}

// repeat and store with l-value
Mystring &Mystring::operator*=(const size_t &n) {
    *this += *this * (n - 1);
    return *this;
}

// preincrement
Mystring &Mystring::operator++() {
    for (size_t i {}; i < std::strlen(this->str); i++)
        this->str[i] = std::toupper(this->str[i]);
    return *this;
}

// postincrement
Mystring Mystring::operator++(int) {
    Mystring temp {*this};
    this->operator++();
    return temp;
}