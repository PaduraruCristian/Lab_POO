#ifndef ELECTRONIC_H
#define ELECTRONIC_H

#include <string>
#include <stdexcept>

class electronic
{
protected:
    const std::string name;
    std::string specs;
    double producer_price;

public:
    electronic(const std::string& n, const std::string& desc, const double p);
    virtual ~electronic() = default;

    virtual void present_product()=0;
    virtual double gen_bonus_income(const int nr_hours)=0;
};

#endif // ELECTRONIC_H
