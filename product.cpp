#include "product.h"

product::product(const std::shared_ptr<electronic> &e, const double pr, const int n):price(pr), nr(n), el(e)
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
    //dtor
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

double product::get_price()
{
    return this->price;
}

int product::get_nr()
{
    return this->nr;
}

std::shared_ptr<electronic>& product::get_el()
{
    return this->el;
}

void product::update_nr(int x)
{
    this->nr = x;
}


void product::update_price(double x)
{
    this->price = x;
}

