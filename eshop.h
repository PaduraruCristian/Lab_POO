#ifndef ESHOP_H
#define ESHOP_H
#include <vector>
#include <memory>
#include "product.h"
#include "smart_phone.h"

class eshop
{
    std::string name, address;
    std::vector <product> products;
    ///0<=tax<=1
    ///product.price = producer_price * (1+tax)
    double tax;
    void remove_product(int index);
    void supply(int index, int nr_prod);
public:
    eshop(std::string  nume, std::string  adresa, double taxa);
    ~eshop();

    void add_product(const product&);

    void sell(int index, int nr_prod);

    void list_products(std::ostream& c);
    void see_details(std::ostream& c, int index);

    const std::string& get_name();
    const std::string& get_address();
    int get_nrprods();
    double get_price(int index);
    int get_nr_items(int index);
    const std::shared_ptr<electronic>& get_elec(int index);
};

#endif // ESHOP_H
