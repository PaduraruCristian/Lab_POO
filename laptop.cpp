#include "laptop.h"


laptop::laptop(const std::string& nume, const std::string& desc, double pret, double rata): electronic(nume, desc, pret), rate(rata)
{
    if(rate<0)
        throw std::invalid_argument("Not a worthwhile product\n");
}

laptop::~laptop()
{
    std::cout<<"Laptop destructor for "<<this->name<<" \n";
}


void laptop::present_product(std::ostream& c)
{
    c<<this->name<<'\n'<<this->specs<<"\n";
    c<<"Tip: can mine coins at a rate of "<<this->rate<<" per hour.\n";
}

double laptop::gen_bonus_income(const int nr_hours)
{
    if(nr_hours<0)
        throw std::invalid_argument("Negative time? Trying to bend physics are we!?\n");
    std::cout<<"Mined coins for "<<nr_hours<<" hours with "<<this->name<<" laptops.\n";
    return this->rate * nr_hours;
}

