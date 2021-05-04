#ifndef ESHOP_H
#define ESHOP_H
#include <vector>
#include <memory>
#include "product.h"
class eshop
{
protected:
    std::string name, address;
    std::vector <product> products;

public:
    eshop(std::string& n, std::string& ad);
    ~eshop();

    void add_product(const std::shared_ptr<electronic> &e, const int pr, const int n);
    void remove_product(int index);
    void sell(int index, int nr_prod);
    void supply();
};

#endif // ESHOP_H
