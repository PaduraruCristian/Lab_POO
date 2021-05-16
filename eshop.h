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
    eshop(std::string  nume, std::string  adresa, double taxa);
    ~eshop();

    void add_product(const std::shared_ptr<electronic> &e, int n);
    void remove_product(int index);

    void sell(int index, int nr_prod);
    void supply(int index, int nr_prod);

    void list_products(std::ostream& c);

    void see_details(std::ostream& c, int index);

    const std::string& get_name();
    int get_nrprods();
    double get_price(int index);
    int get_nr_items(int index);
    const std::shared_ptr<electronic>& get_elec(int index);
};

#endif // ESHOP_H
