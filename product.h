#ifndef PRODUCT_H
#define PRODUCT_H
#include <memory>
#include "electronic.h"

class product
{
    double price;
    int nr;
    std::shared_ptr<electronic> el;
public:
    product(std::shared_ptr<electronic> elec, double price, int nr);
    product(const product& pr);
    product();
    ~product();

    product& operator=(const product& pr);
    friend std::ostream& operator<<(std::ostream &c, const product& pr);

    double get_price() const;
    int get_nr() const;
    const std::shared_ptr<electronic>& get_el();

    void update_nr(int new_nr);

    friend class product_builder;
};

#endif // PRODUCT_H
