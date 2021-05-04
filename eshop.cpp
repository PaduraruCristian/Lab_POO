#include "eshop.h"

eshop::eshop(std::string& n, std::string& ad):name(n), address(ad)
{
    //ctor
}

eshop::~eshop()
{
    //dtor
}

void eshop::add_product(const std::shared_ptr<electronic> &e, const int pr, const int n)
{
    products.emplace_back(e, pr, n);
}

void eshop::remove_product(int index)
{
    if(index<products.size())
    {
        products.erase(products.begin() + index);
        return;
    }
    throw std::invalid_argument("Index out of range. remove_product() called with index=" + std::to_string(index) + ".\n");
}

void eshop::sell(int index, int nr_prod)
{
    if(index<products.size())
    {
        if(products[index].get_nr())
        {
            if(products[index].get_nr()>=nr_prod)
            {
                products[index].update_nr(-nr_prod);
                return;
            }
            throw std::invalid_argument("Don't have enough products with index " + std::to_string(index) + " in stock.\n");
        }
        throw std::invalid_argument("Product index " + std::to_string(index) + " is out of stock.\n");
    }
    throw std::invalid_argument("Index out of range. sell() called with index=" + std::to_string(index) + ".\n");
}




