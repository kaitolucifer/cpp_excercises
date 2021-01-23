#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>

class Mystring {
    friend std::ostream &operator<<(std::ostream &os, const Mystring &rhs);
    friend std::istream &operator>>(std::istream &is, Mystring &rhs);
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
        Mystring operator-() const;                           // lowercase
        bool operator==(const Mystring &rhs) const;           // string equality
        bool operator!=(const Mystring &rhs) const;           // inequality
        bool operator<(const Mystring &rhs) const;            // string lexically less than
        bool operator>(const Mystring &rhs) const;            // string lexically greater than
        Mystring operator+(const Mystring &rhs) const;        // concatenation
        Mystring &operator+=(const Mystring &rhs);      // concatenation and store
        Mystring operator*(const size_t &&n) const;           // repeat with r-value
        Mystring operator*(const size_t &n) const;            // repeat with l-value
        Mystring &operator*=(const size_t &&n);         // repeat and store with r-value
        Mystring &operator*=(const size_t &n);          // repeat and store with l-value
        Mystring &operator++();                         // preincrement
        Mystring operator++(int);                       // postincrement

        void display() const;
        int get_length() const;
        const char *get_str() const;

};

#endif // _MYSTRING_H_