#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <cstdlib>

#include "eshop.h"
#include "laptop.h"
#include "smart_phone.h"

/// Un vector in care am pointeri la toate electronicele de pe piata
/// In eshop, fiecare produs are o copie a unui astfel de pointer -> shared_ptr > unique_ptr;
std::vector<std::shared_ptr<electronic>> all_electronics;
std::vector<eshop> shops;

double balance;

void init()
{
    std::ifstream f("set_up.in");
    ///user's initial balance
    f>>balance;

    std::string name, specs;
    double producer_price, r;
    int tre;
    int nr_l, nr_sp;
    ///add all laptops
    f>>nr_l;
    for(;nr_l; --nr_l)
    {
        //read the \n after nr_l and then read the actual name and override it
        std::getline(f, name);

        std::getline(f, name);
        std::getline(f, specs);
        f>>producer_price>>r;
        all_electronics.emplace_back(std::make_shared<laptop>(name, specs, producer_price, r));
    }
    ///add all smart_phones
    f>>nr_sp;
    for(;nr_sp; --nr_sp)
    {
        std::getline(f, name);

        std::getline(f, name);
        std::getline(f, specs);
        f>>producer_price>>tre;
        all_electronics.emplace_back(std::make_shared<smart_phone>(name, specs, producer_price, tre));
    }
    ///init every shop;
    int nr_products, nr_bucati, index, nr_shops;
    double tax;
    std::string address;
    f>>nr_shops;
    for(int i=0; i<nr_shops; ++i)
    {
        std::getline(f, name);
        std::getline(f, name);
        std::getline(f, address);
        f>>tax;
        shops.emplace_back(eshop(name, address, tax));

        f>>nr_products;
        for(;nr_products; --nr_products)
        {
            f>>index>>nr_bucati;
            shops[i].add_product(all_electronics[index-1], nr_bucati);
            ///index expected to be from 1 to nr_products so I added a -1;
        }
    }
}


int main()
{
    try{
        init();
    }
    catch(std::invalid_argument& s)
    {
        std::cout<<s.what();
    }
    int nr_shop=0, nr_prod=0, amount;
    while(true)
    {

        //std::system("cls");
        std::cout<<"===========================================\n";
        for(int i=0;i<shops.size();++i)
        {
            std::cout<<i+1<<"."<<shops[i].get_name()<<'\n';
        }
        std::cout<<"===========================================\n";
        std::cout<<"Choose a shop (giving an out of range index will close the program):";
        std::cin>>nr_shop;
        std::system("cls");
        if(1<=nr_shop && nr_shop<=shops.size())
        {
            shops[nr_shop-1].list_products(std::cout);
            std::cout<<"Choose a product to see more details or buy:";
            std::cin>>nr_prod;
            if(1<=nr_prod && nr_prod<=shops[nr_shop-1].get_nrprods())
            {
                std::system("cls");
                shops[nr_shop-1].see_details(std::cout, nr_prod-1);
                std::cin>>amount;
                return 0;
            }
        }
        else
        {
            std::cout<<"Out of range index: process terminated;\n";
            return 0;
        }
    }

    return 0;
}
