//
// Created by Paduraru on 16-May-21.
//

#ifndef LAB_POO_USER_S_H
#define LAB_POO_USER_S_H
#include "product.h"
#include <vector>

class User_s {
private:
    double balance;
    std::vector<product> myproducts;

    static  User_s* user;
    User_s() = default;

public:
    User_s(const User_s&) = delete;
    User_s& operator=(const User_s&) = delete;
    static User_s* get_user();

    double get_balance() const;
    void set_balance(double new_balance);
    void add_product(const std::shared_ptr<electronic>& elec, int nr);

    void print_owned_elecs(std::ostream& c);
};


#endif //LAB_POO_USER_S_H
