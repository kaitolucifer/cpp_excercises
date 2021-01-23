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
Mystring operator-(const Mystring &obj) {
    size_t str_len {std::strlen(obj.str)};
    char *buff = new char[str_len + 1];
    std::strcpy(buff, obj.str);
    for (size_t i {0}; i < str_len; i++) {
        buff[i] = std::tolower(buff[i]);
    }
    Mystring temp {buff};
    delete[] buff;
    return temp;
}

// string equality
bool operator==(const Mystring &lhs, const Mystring &rhs) {
    return (std::strcmp(lhs.str, rhs.str) == 0);
}

// inequality
bool operator!=(const Mystring &lhs, const Mystring &rhs) {
    return !operator==(lhs, rhs);
}

// string lexically less than
bool operator<(const Mystring &lhs, const Mystring &rhs) {
    return lhs.str < rhs.str;
}

 // string lexically greater than
bool operator>(const Mystring &lhs, const Mystring &rhs) {
    return !operator<(lhs, rhs);
}

// concatenation
Mystring operator+(const Mystring &lhs, const Mystring &rhs) {
    size_t str1_len = std::strlen(lhs.str);
    size_t str2_len = std::strlen(rhs.str);
    char *buff = new char[str1_len + str2_len + 1];
    std::strcpy(buff, lhs.str);
    std::strcat(buff, rhs.str);
    Mystring temp {buff};
    delete[] buff;
    return temp;
}

// concatenation and store
Mystring &operator+=(Mystring &lhs, const Mystring &rhs) {
    lhs = lhs + rhs;
    return lhs;
}

// repeat with r-value
Mystring operator*(const Mystring &lhs, const size_t &&n) {
    Mystring temp;
    for (size_t i {}; i < n; i++)
        temp += lhs;
    return temp;
}

// repeat with l-value
Mystring operator*(const Mystring &lhs, const size_t &n) {
    Mystring temp;
    for (size_t i {}; i < n; i++)
        temp += lhs;
    return temp;
}

// repeat and store with r-value
Mystring &operator*=(Mystring &lhs, const size_t &&n) {
    lhs += lhs * (n - 1);
    return lhs;
}

// repeat and store with l-value
Mystring &operator*=(Mystring &lhs, const size_t &n) {
    lhs += lhs * (n - 1);
    return lhs;
}

// preincrement
Mystring &operator++(Mystring &obj) {
    for (size_t i {}; i < std::strlen(obj.str); i++)
        obj.str[i] = std::toupper(obj.str[i]);
    return obj;
}

// postincrement
Mystring operator++(Mystring &obj, int) {
    Mystring temp {obj};
    operator++(obj);
    return temp;
}