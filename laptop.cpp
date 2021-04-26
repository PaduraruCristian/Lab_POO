#include "laptop.h"

#include <iostream>

laptop::laptop(const std::string& n, const std::string& desc, const int& nr, const double& p, const double &r): electronic(n, desc, nr, p), rate(r)
{
    if(rate<0)
        throw std::invalid_argument("Not a worthwhile product\n");
}

laptop::~laptop()
{

}

double laptop::sell(const int& nr)
{
    if(nr > this->in_stock)
        throw std::invalid_argument("Don't have enough " + this->name + " laptops in stock.\n");

    this->in_stock-=nr;
    return (double) nr * this->price;
}

void laptop::supply(const int& nr)
{
    this->in_stock += nr;
}

void laptop::present_product()
{
    std::cout<<this->name<<'\n'<<this->specs<<"\n";
    std::cout<<"Tip: can mine coins at a rate of "<<this->rate<<" per hour.\n";
}

double laptop::gen_bonus_income(const int& nr_hours)
{
    if(nr_hours<0)
        throw std::invalid_argument("Negative time? Trying to bend physics are we???\n");
    return this->rate * nr_hours;
}

