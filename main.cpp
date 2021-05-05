<<<<<<< HEAD
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>

#include "electronic.h"
#include "smart_phone.h"
#include "laptop.h"

int main()
{
    /*
    std::vector < std::unique_ptr <electronic>> v;
    std::vector < std::pair <int, int> > order;
    try{
        double sum = 0, bonus = 0;
        int free_hours = 5;
        v.push_back( std::make_unique<laptop>("ASUS", "8GB RAM \n2TB", 30, 249.5, (double) 1 / (1<<10)) );
        //v.push_back( std::make_unique<laptop>("ASUS", "8GB RAM \n2TB", 30, -4, (double) 1 / (1<<10)) );
        v.push_back( std::make_unique<laptop>("ASUS ROG", "16GB RAM \n1.5 TB", 10, 549.99, (double) 1 / (1<<8)) );

        v.push_back( std::make_unique<smart_phone>("SG 8S", "6GB RAM \n32 GB memory", 44, 325, 3));


        for(auto& x :v)
        {
            x->present_product();
            std::cout<<'\n';
        }

        order.push_back(std::make_pair(0, 4));
        order.push_back(std::make_pair(1, 1));
        order.push_back(std::make_pair(2, 5));

        for(auto x :order)
        {
            sum+= v[x.first]->sell(x.second);
        }
        std::cout<< sum <<"$ earned today from sales\n\n";

        for(auto& x :v)
        {
            bonus+= x->gen_bonus_income(free_hours);
        }

        std::cout<< bonus << "& earned by mining for "<<free_hours<<" hours\n\n";
    }
    catch(std::invalid_argument& er)
    {
        std::cout<<er.what();
    }*/
    return 0;
}
=======
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>

#include "electronic.h"
#include "smart_phone.h"
#include "laptop.h"

int main()
{
    /*
    std::vector < std::unique_ptr <electronic>> v;
    std::vector < std::pair <int, int> > order;
    try{
        double sum = 0, bonus = 0;
        int free_hours = 5;
        v.push_back( std::make_unique<laptop>("ASUS", "8GB RAM \n2TB", 30, 249.5, (double) 1 / (1<<10)) );
        //v.push_back( std::make_unique<laptop>("ASUS", "8GB RAM \n2TB", 30, -4, (double) 1 / (1<<10)) );
        v.push_back( std::make_unique<laptop>("ASUS ROG", "16GB RAM \n1.5 TB", 10, 549.99, (double) 1 / (1<<8)) );

        v.push_back( std::make_unique<smart_phone>("SG 8S", "6GB RAM \n32 GB memory", 44, 325, 3));


        for(auto& x :v)
        {
            x->present_product();
            std::cout<<'\n';
        }

        order.push_back(std::make_pair(0, 4));
        order.push_back(std::make_pair(1, 1));
        order.push_back(std::make_pair(2, 5));

        for(auto x :order)
        {
            sum+= v[x.first]->sell(x.second);
        }
        std::cout<< sum <<"$ earned today from sales\n\n";

        for(auto& x :v)
        {
            bonus+= x->gen_bonus_income(free_hours);
        }

        std::cout<< bonus << "& earned by mining for "<<free_hours<<" hours\n\n";
    }
    catch(std::invalid_argument& er)
    {
        std::cout<<er.what();
    }*/
    return 0;
}
>>>>>>> 3be57faeecfc3e8a619b903f5384a33fa9907e7f
