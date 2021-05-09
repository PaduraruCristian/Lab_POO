#include "eshop.h"

eshop::eshop(const std::string& n, const std::string& ad, const double t):name(n), address(ad), tax(t)
{
    //products.clear();
}

eshop::~eshop()
{

}

void eshop::add_product(const std::shared_ptr<electronic> &e, const int n)
{
    products.emplace_back(e, e->get_pprice() * (1+tax), n);
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
                products[index].update_nr(products[index].get_nr() - nr_prod);
                return;
            }
            throw std::invalid_argument("Don't have enough products with index " + std::to_string(index) + " in stock.\n");
        }
        throw std::invalid_argument("Product index " + std::to_string(index) + " is out of stock.\n");
    }
    throw std::invalid_argument("Index out of range. sell() called with index=" + std::to_string(index) + ".\n");
}

void eshop::supply(int index, int nr_prod)
{
    if(index<products.size())
    {
        products[index].update_nr(products[index].get_nr() + nr_prod);
        return;
    }
    throw std::invalid_argument("Index out of range. supply() called with index=" + std::to_string(index) + ".\n");
}

void eshop::list_products(std::ostream& c)
{
    c<<"List of all products available at "<<this->name<<":\n"
     <<"======================================================\n";
    for(int i=0;i<products.size();++i)
    {
        c<<i+1<<'.'<<products[i].get_el()->get_name()<<'\n';
    }
    c<<"======================================================\n";
}

void eshop::see_details(std::ostream& c, const int index)
{
    if(index<products.size())
        c<<products[index];
    else
        throw std::invalid_argument("Index out of range. see_details() called with index=" + std::to_string(index) + ".\n");
}

const std::string& eshop::get_name()
{
    return this->name;
}

const int eshop::get_nrprods()
{
    return this->products.size();
}

double eshop::get_price(const int index)
{
    return this->products[index].get_price();
}

int eshop::get_nr_items(const int index)
{
    return this->products[index].get_nr();
}
