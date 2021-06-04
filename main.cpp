#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <memory>

#include "eshop.h"
#include "laptop.h"
#include "smart_phone.h"
#include "rlutil.h"  /// nice license details :)))
#include "User_s.h"


void init(User_s* &user, std::vector<std::shared_ptr<electronic>>& all_electronics, std::vector<eshop>& shops)
{
    std::ifstream f("set_up.in");
    ///user's initial balance
    double balance;
    f>>balance;
    user->set_balance(balance);
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

void menu(User_s* &user, std::vector<std::shared_ptr<electronic>>& all_electronics, std::vector<eshop>& shops){
    int nr_shop=0, nr_prod=0, amount, option;
    long long int day_count = 1;
    while(true) {
        auto my_elec = shops.size() +1;
        auto end_of_the_day = shops.size() + 2;
        auto exit_opt = shops.size() + 3;
        if (!nr_shop) {
            rlutil::cls();
            std::cout << "===========================================\n";
            std::cout << "Day: "<<day_count<<'\n';
            std::cout << "===========================================\n";
            for (int i = 0; i < shops.size(); ++i) {
                std::cout << i + 1 << "." << shops[i].get_name() << '\n';
            }
            std::cout << "===========================================\n";
            std::cout << my_elec<< ". My electronics\n";
            std::cout << end_of_the_day<< ". End the day, get income from your electronics\n";
            std::cout << exit_opt << ". Exit\n";
            std::cin >> nr_shop;
        }

        rlutil::cls();
        if(nr_shop == my_elec){
            user->print_owned_elecs(std::cout);
            std::cout<<"1. Back\n";
            std::cin>>nr_shop;
            nr_shop=0;
            continue;
        }

        if(nr_shop == end_of_the_day)
        {
            ++day_count;
            user->gen_income();
            std::cout<<"New balance: "<<user->get_balance()<<'\n';
            std::cout<<"1. Back\n";
            std::cin>>nr_shop;
            nr_shop=0;
            continue;
        }

        if (nr_shop == exit_opt) break;
        
        auto &eshop = shops.at(nr_shop - 1);

        auto back_opt = eshop.get_nrprods() + 1;
        if (!nr_prod) {
            eshop.list_products(std::cout);
            std::cout << back_opt << ". Back\n";
            std::cout << "Choose a product to see more details or buy:";
            std::cin >> nr_prod;
        }

        if (nr_prod == back_opt) {
            nr_prod = 0;
            nr_shop = 0;
        }
        else {
            rlutil::cls();

            eshop.see_details(std::cout, nr_prod - 1);
            std::cout << "======================================\n";
            std::cout << "Your balance:" << user->get_balance() << '\n';
            std::cout << "1. Buy\n";
            std::cout << "2. Back\n";
            std::cin >> option;

            if (option == 1) {
                std::cout << "Amount:";
                std::cin >> amount;
                if (amount > 0 && amount <= eshop.get_nr_items(nr_prod - 1) &&
                    amount * eshop.get_price(nr_prod - 1) <= user->get_balance()) {
                    user->set_balance(user->get_balance() - amount * eshop.get_price(nr_prod - 1));
                    user->add_product(eshop.get_elec(nr_prod - 1), amount);
                    eshop.sell(nr_prod - 1, amount);
                }
            } else if (option == 2) {
                nr_prod = 0;
            }
            else throw std::out_of_range("Not a valid option");
        }
    }
}


int main()
{
    std::vector<std::shared_ptr<electronic>> all_electronics;
    std::vector<eshop> shops;

    auto user = User_s::get_user();
    try{
        init(user, all_electronics, shops);
        menu(user, all_electronics, shops);
    }
    catch(std::invalid_argument& s)
    {
        std::cout<<s.what();
        return 0;
    }
    catch(std::out_of_range& s)
    {
        std::cout<<"Index out of range\n"<<s.what()<<'\n';
    }
    catch (...) {
        std::cout<<"I have no f**ing idea what you managed to mess up...\n";
    }

    delete user;
    return 0;
}
