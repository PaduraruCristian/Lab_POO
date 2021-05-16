//
// Created by Paduraru on 16-May-21.
//

#include "User_s.h"

User_s* User_s::user = nullptr;

User_s* User_s::get_user(){
    if(user== nullptr){
        user = new User_s;
    }
    return user;
}

void User_s::set_balance(double new_balance) {
    this->balance = new_balance;
}

double User_s::get_balance() const {
    return this->balance;
}

void User_s::add_product(const std::shared_ptr<electronic>& elec, int nr) {

    for (auto& produs : myproducts) {
        if(produs.get_el() == elec){
            produs.update_nr( produs.get_nr() + nr);
            return;
        }
    }
    myproducts.emplace_back( product{elec, elec->get_producer_price(), nr});
}

void User_s::print_owned_elecs(std::ostream& c) {
    for(auto& pr: myproducts)
        c<<pr.get_el()->get_name() << "\nYou own " <<pr.get_nr()<< " items of this type\n\n";
}
