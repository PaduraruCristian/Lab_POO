//
// Created by Paduraru on 07-Jun-21.
//

#ifndef LAB_POO_PRODUCT_BUILDER_H
#define LAB_POO_PRODUCT_BUILDER_H

#include "product.h"

class product_builder {
private:
    product produs;

public:
    product_builder() = default;

    product_builder& elec(const std::shared_ptr<electronic>&);
    product_builder& nr(int numar);
    product_builder& pret(double  pret);

    product build();

};


#endif //LAB_POO_PRODUCT_BUILDER_H
