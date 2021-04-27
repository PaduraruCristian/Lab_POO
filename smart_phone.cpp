#include "smart_phone.h"

#include <iostream>

smart_phone::smart_phone(const std::string& n, const std::string& desc, const int& nr, const double& p, int tre):electronic(n, desc, nr, p), threshold(tre)
{

}

smart_phone::~smart_phone()
{
    std::cout<<"Smart_phone destructor for "<<this->name<<" \n";
}
double smart_phone::sell(const int& nr)
{
    if(nr > this->in_stock)
        throw std::invalid_argument("Don't have enough " + this->name + " phones in stock.\n");

    this->in_stock-=nr;
    if(nr>=threshold)
    {
        std::cout<<"Offered a discount for "<<this->name<<"\n";
        return 3*(((double) nr * this->price)/4) ;
    }
    else
        return (double) nr * this->price;
}

void smart_phone::supply(const int& nr)
{
    this->in_stock += nr;
}

void smart_phone::present_product()
{
    std::cout<<this->name<<'\n'<<this->specs<<"\n";
}

double smart_phone::gen_bonus_income(const int& nr_hours)
{
    std::cout<<"Can't do much with a phone... still, you can play Candy Crush for "<<nr_hours<<" hours if you are that bored.\n";
    return 0;
}
