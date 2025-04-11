//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_PRODUCT_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_PRODUCT_H

#include <string>

namespace company{
    class product{
        private:
            std::string name;
            double price;
            double weight;
        public:
            product(const std::string &name_, double price_, double weight_);

            std::string get_name() const;
            double get_weight() const;
            double get_price() const;

            bool operator==(const product &p) const;
            bool operator<(const product &p) const;

            friend bool compare_by_value(const product &p1, const product &p2);

            ~product();
    };
    bool compare_by_value(const product &p1, const product &p2);
}

#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_PRODUCT_H
