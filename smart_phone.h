#ifndef SMART_PHONE_H
#define SMART_PHONE_H

#include "electronic.h"

class smart_phone : public electronic
{
protected:
    /// if more than threshold phones are sold -> discount
    const int threshold = 1<<30;
public:
    smart_phone(const std::string& nume, const std::string& desc, double pret, int tre=0);
    ~smart_phone() override;

    void present_product(std::ostream& c) override;
    double gen_bonus_income(int nr_hours) override;

};

#endif // SMART_PHONE_H
