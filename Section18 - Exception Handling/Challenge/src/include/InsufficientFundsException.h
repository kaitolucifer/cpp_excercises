#ifndef _INSUFFICIENT_FUNDS_EXCEPTION_H_
#define _INSUFFICIENT_FUNDS_EXCEPTION_H_
#include <exception>
#include <stdexcept>

class InsufficientFundsException : public std::exception
{
public:
    InsufficientFundsException() noexcept = default;
    ~InsufficientFundsException() = default;
    virtual const char *what() const noexcept
    {
        return "Insufficient funds exception";
    }
};

#endif // _INSUFFICIENT_FUNDS_EXCEPTION_H_
