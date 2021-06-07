//
// Created by Paduraru on 07-Jun-21.
//

#include "product_builder.h"

product_builder &product_builder::elec(const std::shared_ptr<electronic> & elec) {
    this->produs.el = elec;
    return *this;
}

product_builder &product_builder::nr(int numar) {
    this->produs.nr = numar;
    return *this;
}

product_builder &product_builder::pret(double pret) {
    this->produs.price = pret;
    return *this;
}

product product_builder::build() {
    return this->produs;
}
