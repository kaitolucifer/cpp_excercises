#ifndef _PRINTABLEINTERFACE_H_
#define _PRINTABLEINTERFACE_H_
#include <iostream>
#include <string>

class PrintableInterface
{
    friend std::ostream &operator<<(std::ostream &os, const PrintableInterface &obj);
    public:
        virtual void print(std::ostream &os) const = 0;
        virtual ~PrintableInterface() = default;
};

#endif  // PRINTABLEINTERFACE
