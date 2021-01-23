#ifndef _MYSTRING_H_
#define _MYSTRING_H_
#include <iostream>

class Mystring {
    friend bool operator==(const Mystring &lhs, const Mystring &rhs);
    friend Mystring operator-(const Mystring &obj);
    friend Mystring operator+(const Mystring &lhs, const Mystring &rhs);
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
        
        void display() const;
        int get_length() const;
        const char *get_str() const;

};

#endif // _MYSTRING_H_