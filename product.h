#ifndef PRODUCT_H
#define PRODUCT_H
#include <memory>
#include "electronic.h"

class product
{
    int price, nr;
    std::shared_ptr<electronic> el;
public:
    product(const std::shared_ptr<electronic> &e, const int pr, const int n);
    ~product();

    int get_price();
    int get_nr();
    std::shared_ptr<electronic>& get_el();
    void update_nr(int x);
};

#endif // PRODUCT_H
