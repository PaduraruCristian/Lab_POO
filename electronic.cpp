#include "electronic.h"

electronic::electronic(const std::string& n, const std::string& desc, const int& nr, const double& p) : name(n), specs(desc), in_stock(nr), price(p)
{
    if(in_stock<0 || price<0)
        throw std::invalid_argument("Negative values rejected\n");
    if( name.length() == 0)
        throw std::invalid_argument("Empty string as name rejected\n");
}
