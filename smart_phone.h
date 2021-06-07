#ifndef SMART_PHONE_H
#define SMART_PHONE_H

#include "electronic.h"

class smart_phone : public electronic
{

public:
    smart_phone(const std::string& nume, const std::string& desc, double pret);
    ~smart_phone() override;

    void present_product(std::ostream& c) override;
    double gen_bonus_income(int nr_hours) override;

};

#endif // SMART_PHONE_H
