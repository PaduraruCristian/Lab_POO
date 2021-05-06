#ifndef ELECTRONIC_H
#define ELECTRONIC_H

#include <string>
#include <stdexcept>
#include <iostream>
class electronic
{
protected:
    const std::string name;
    std::string specs;
    double producer_price;

public:
    electronic(const std::string& n, const std::string& desc, const double p);
    virtual ~electronic() = default;

    double get_pprice();
    const std::string& get_name();

    virtual void present_product(std::ostream& c)=0;
    virtual double gen_bonus_income(const int nr_hours)=0;

};

#endif // ELECTRONIC_H
