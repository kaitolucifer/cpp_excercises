#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>

class Mystring {
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &is, Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);                                   // lowercase
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);           // string equality
    friend bool operator!=(const Mystring &lhs, const Mystring &rhs);           // inequality
    friend bool operator<(const Mystring &lhs, const Mystring &rhs);            // string lexically less than
    friend bool operator>(const Mystring &lhs, const Mystring &rhs);            // string lexically greater than
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);        // concatenation
    friend Mystring &operator+=(Mystring &lhs, const Mystring &rhs);            // concatenation and store
    friend Mystring operator*(const Mystring &lhs, const size_t &&n);           // repeat with r-value
    friend Mystring operator*(const Mystring &lhs, const size_t &n);            // repeat with l-value
    friend Mystring &operator*=(Mystring &lhs, const size_t &&n);               // repeat and store with r-value
    friend Mystring &operator*=(Mystring &lhs, const size_t &n);                // repeat and store with l-value
    friend Mystring &operator++(Mystring &obj);                                     // preincrement
    friend Mystring operator++(Mystring &obj, int);                             // postincrement
    private:
        char *str;  // pointer to a char[] that holds a c-style string
    public:
        Mystring();                                     // No-args constructor
        Mystring(const char *s);                        // Overloaded constructor
        Mystring(const Mystring &source);               // Copy constructor
        Mystring(Mystring &&source);                    // Move constructor
        ~Mystring();                                    // Destructor
        Mystring &operator=(const Mystring &rhs);       // Copy assignment
        Mystring &operator=(Mystring &&rhs);            // Move assignment

        void display() const;
        int get_length() const;
        const char *get_str() const;

};

#endif // _MYSTRING_H_