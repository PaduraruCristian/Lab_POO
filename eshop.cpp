#include "eshop.h"


eshop::eshop(std::string  nume, std::string  adresa, const double taxa):name(std::move(nume)), address(std::move(adresa)), tax(taxa)
{
    //products.clear();
    if(tax <0)
        throw std::invalid_argument("Is this some charity or a real business!?\n");
}

eshop::~eshop()= default;

void eshop::add_product(const product& pr)
{
    products.emplace_back(pr);
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
    auto nr = products.at(index).get_nr();
    if(nr)
    {
        if(nr>=nr_prod)
        {
            products.at(index).update_nr(nr - nr_prod);

            /// Daca numarul de produse a ajuns la 0
            if(products[index].get_nr() == 0)
            {
                auto smp = std::dynamic_pointer_cast<smart_phone>(products[index].get_el());
                /// si produsul este un smartphone -> remove_product; no supply for this
                if(smp)
                {
                    this->remove_product(index);
                }
                else
                {
                    /// este un laptop; supply in functie de nr de proudse vandute ultima data;
                    this->supply(index,int((3*nr+1)/2) );
                }
            }

            return;
        }
        throw std::invalid_argument("Don't have enough products with index " + std::to_string(index) + " in stock.\n");
    }
    throw std::invalid_argument("Product index " + std::to_string(index) + " is out of stock.\n");
}

void eshop::supply(int index, int nr_prod)
{
    products.at(index).update_nr(products.at(index).get_nr() + nr_prod);
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
    c<<products.at(index);
}

const std::string& eshop::get_name()
{
    return this->name;
}

int eshop::get_nrprods()
{
    return (int) this->products.size();
}

double eshop::get_price(const int index)
{
    return this->products.at(index).get_price();
}

int eshop::get_nr_items(const int index)
{
    return this->products.at(index).get_nr();
}

const std::shared_ptr<electronic> &eshop::get_elec(int index) {
    return products.at(index).get_el();
}

const std::string &eshop::get_address() {
    return this->address;
}
