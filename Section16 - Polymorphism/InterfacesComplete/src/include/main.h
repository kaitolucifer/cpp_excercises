#ifndef _MAIN_H_
#define _MAIN_H_
#include <iostream>

class PrintableInterface
{
    friend std::ostream &operator<<(std::ostream &os, const PrintableInterface &obj);

public:
    virtual void print(std::ostream &os) const = 0;
};

std::ostream &operator<<(std::ostream &os, const PrintableInterface &obj)
{
    obj.print(os);
    return os;
}

class Account : public PrintableInterface
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Account::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Account display";
    }
    virtual ~Account() {}
};

class Checking : public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Checking::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Checking display";
    }
    virtual ~Checking() {}
};

class Savings : public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Savings::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Savings display";
    }
    virtual ~Savings() {}
};

class Trust : public Account
{
public:
    virtual void withdraw(double amount)
    {
        std::cout << "In Trust::withdraw" << std::endl;
    }
    virtual void print(std::ostream &os) const override
    {
        os << "Trust display";
    }
    virtual ~Trust() {}
};

class Dog : public PrintableInterface
{
public:
    virtual void print(std::ostream &os) const override
    {
        os << "Woof Woof";
    }
};

#endif // _MAIN_H_
