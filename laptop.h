#ifndef LAPTOP_H
#define LAPTOP_H

#include "electronic.h"

#include <string>



class laptop : public electronic
{
protected:
/// amount that it can generate per hour mining coins
    const double rate=0;
public:
    laptop(const std::string& n, const std::string& desc, const int& nr, const double& p, const double &r);
    ~laptop();

    double sell(const int& nr);
    void supply(const int& nr);
    void present_product();
    double gen_bonus_income(const int& nr_hours);
};

#endif // LAPTOP_H
