#include "electronic.h"

#include <utility>

electronic::electronic(std::string  nume, std::string  desc, double pret) : name(std::move(nume)), specs(std::move(desc)), producer_price(pret)
{
    if(producer_price<0)
        throw std::invalid_argument("Negative price for " + name +".\nWho would pay to sell their products??" );
    if( name.length() == 0)
        throw std::invalid_argument("Empty string as name.\n");
}


double electronic::get_producer_price() const
{
    return this->producer_price;
}

const std::string& electronic::get_name()
{
    return this->name;
}
