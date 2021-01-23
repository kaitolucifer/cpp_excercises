#include "PrintableInterface.h"


std::ostream &operator<<(std::ostream &os, const PrintableInterface &obj)
{
    obj.print(os);
    return os;
}
