#include "smart_phone.h"


smart_phone::smart_phone(const std::string& nume, const std::string& desc, const double pret, int tre):electronic(nume, desc, pret), threshold(tre)
{

}

smart_phone::~smart_phone()
{
    std::cout<<"Smart_phone destructor for "<<this->name<<" \n";
}


void smart_phone::present_product(std::ostream& c)
{
    c<<this->name<<'\n'<<this->specs<<"\n";
}

double smart_phone::gen_bonus_income(const int nr_hours)
{
    ///std::cout<<"Can't do much with a phone... still, you can play Candy Crush for "<<nr_hours<<" hours if you are that bored.\n";
    return 0;
}

