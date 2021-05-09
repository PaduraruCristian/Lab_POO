#ifndef ESHOP_H
#define ESHOP_H
#include <vector>
#include <memory>
#include "product.h"
class eshop
{
    std::string name, address;
    std::vector <product> products;
    ///0<=tax<=1
    ///product.price = producer_price * (1+tax)
    double tax;

public:
    eshop(const std::string& n, const std::string& ad, const double t);
    ~eshop();

    void add_product(const std::shared_ptr<electronic> &e, const int n);
    void remove_product(int index);
    void sell(int index, int nr_prod);
    void supply(int index, int nr_prod);

    void list_products(std::ostream& c);
    void see_details(std::ostream& c, const int index);

    const std::string& get_name();
    const int get_nrprods();
    double get_price(const int index);
    int get_nr_items(const int index);
};

#endif // ESHOP_H
