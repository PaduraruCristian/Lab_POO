#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>

#include "eshop.h"
#include "laptop.h"
#include "smart_phone.h"

/// Un vector in care am pointeri la toate electronicele de pe piata
/// In eshop, fiecare produs are o copie a unui astfel de pointer -> shared_ptr > unique_ptr;
std::vector<std::shared_ptr<electronic>> all;


int main()
{
    all.push_back(std::make_shared<laptop>("ASUS","2TB\n12 GB RAM", 400, 30));
    all.push_back(std::make_shared<laptop>("HP","1TB\n6 GB RAM", 150, 10));

    eshop myshop("Blanco", "That Street, NR. 101", 0.5);
    myshop.add_product(all[0], 10);
    myshop.add_product(all[1], 25);

    myshop.list_products(std::cout);

    myshop.sell(0, 5);
    myshop.see_details(std::cout, 0);

    std::cout<<'\n';

    product p1(all[1], 300, 15);
    product p2(p1);
    product p3;
    p3=p1;
    std::cout<<"Constructor parametrizat\n"<<p1<<"\nConstructor de copiere\n"<<p2<<"\nOp=\n"<<p3;

    myshop.remove_product(0);
    myshop.list_products(std::cout);
    std::cout<<"\n\n\n";
    return 0;
}
