<<<<<<< HEAD
#include "product.h"

product::product(const std::shared_ptr<electronic> &e, const int pr, const int n):price(pr), nr(n), el(e)
{

}

product::~product()
{
    //dtor
}
int product::get_price()
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
    this->nr += x;
}
=======
#include "product.h"

product::product(const std::shared_ptr<electronic> &e, const int pr, const int n):price(pr), nr(n), el(e)
{

}

product::~product()
{
    //dtor
}
int product::get_price()
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
    this->nr += x;
}
>>>>>>> 3be57faeecfc3e8a619b903f5384a33fa9907e7f
