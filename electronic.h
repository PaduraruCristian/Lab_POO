#ifndef ELECTRONIC_H
#define ELECTRONIC_H

#include <string>
#include <stdexcept>

class electronic
{
protected:
    const std::string name;
    std::string specs;
    int in_stock;
    double price;
public:
    electronic(const std::string& n, const std::string& desc, const int& nr, const double& p);
    virtual ~electronic() = default;

    virtual double sell(int nr)=0;
    virtual void supply(int nr)=0;
    virtual void present_product()=0;
    virtual double get_bonus_income()=0;
};

#endif // ELECTRONIC_H
