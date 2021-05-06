#include "electronic.h"

electronic::electronic(const std::string& n, const std::string& desc, const double p) : name(n), specs(desc), producer_price(p)
{
    if(producer_price<0)
        throw std::invalid_argument("Negative price for " + name +".\nWho would pay to sell their products??" );
    if( name.length() == 0)
        throw std::invalid_argument("Empty string as name.\n");
}


double electronic::get_pprice()
{
    return this->producer_price;
}

const std::string& electronic::get_name()
{
    return this->name;
}
