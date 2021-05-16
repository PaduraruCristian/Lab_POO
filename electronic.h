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
    electronic(std::string  nume, std::string  desc, double pret);
    virtual ~electronic() = default;

    double get_producer_price() const;
    const std::string& get_name();

    virtual void present_product(std::ostream& c)=0;
    virtual double gen_bonus_income(int nr_hours)=0;

};

#endif // ELECTRONIC_H
