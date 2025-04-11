//
// Created by rudri on 10/11/2020.
//

#include "product.h"

namespace company{

    product::product(const std::string &name_, double price_, double weight_) : name(name_), price(price_), weight(weight_) {}

    std::string product::get_name() const {return name;}
    double product::get_weight() const {return weight;}
    double product::get_price() const {return price;}

    bool product::operator==(const product &p) const{
        return (price==p.price && weight==p.weight);
    }

    bool product::operator<(const product &p) const{
        return (price<p.price && weight<p.weight);
    }

    bool compare_by_value(const product &p1, const product &p2){
        //p1=prod2("item_b", 15.0, 15.0); // Ratio = 1.0
        //p2=prod1("item_a", 10.0, 2.0); // Ratio = 5.0
        // return false okay
        return (p1.price/p1.weight >= p2.price/p2.weight);
    }

    product::~product() = default;
}

