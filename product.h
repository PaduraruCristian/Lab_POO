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
    product(const std::shared_ptr<electronic> &e, const double pr, const int n);
    product(const product& pr);
    ~product();

    product& operator=(const product& pr);
    friend std::ostream& operator<<(std::ostream &c, const product& pr);

    double get_price();
    int get_nr();
    std::shared_ptr<electronic>& get_el();
    void update_nr(int x);
    void update_price(double x);
};

#endif // PRODUCT_H
