#ifndef LAPTOP_H
#define LAPTOP_H

#include "electronic.h"

class laptop : public electronic
{
protected:
/// amount that it can generate per hour mining coins
    const double rate=0;
public:
    laptop(const std::string& n, const std::string& desc,  const double p, const double r);
    ~laptop();

    void present_product(std::ostream& c) override;
    double gen_bonus_income(const int nr_hours) override;
};

#endif // LAPTOP_H

