#include "product.h"


product::product(std::shared_ptr<electronic> elec, const double price, const int nr):price(price), nr(nr), el(std::move(elec))
{

}

product::product(const product& pr): price(pr.price), nr(pr.nr), el(pr.el)
{

}
product::product(): price(0), nr(0), el(nullptr)
{

}

product::~product()
{

}

product& product::operator=(const product& pr)
{
    if(this != &pr)
    {
        el=pr.el;
        price=pr.price;
        nr=pr.nr;
    }

    return *this;
}
std::ostream& operator<<(std::ostream &c, const product& pr)
{
    pr.el->present_product(c);
    c<<"Price: "<<pr.price<<"\nIn stock: "<<pr.nr<<"\n";

    return c;
}

double product::get_price() const
{
    return this->price;
}

int product::get_nr() const
{
    return this->nr;
}

const std::shared_ptr<electronic>& product::get_el()
{
    return this->el;
}

void product::update_nr(int new_nr)
{
    this->nr = new_nr;
}


void product::update_price(double new_price)
{
    this->price = new_price;
}

