//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H

#include <iostream>
#include <list>
#include <vector>
#include <tuple>
#include <iterator>
#include <utility>
#include <algorithm>

template<typename... container>
auto zip(const container&... containers) {
    using std::begin;
    using std::end;

    std::vector<std::size_t> tam = { containers.size()... };
   
    if(!std::all_of(tam.begin(), tam.end(), [&](std::size_t x) { return x == tam[0]; })) {
        std::cout << "ERROR: Containers do not have same size" << std::endl;
        return std::vector<std::vector<int>>{};
    }

    auto iters = std::make_tuple(begin(containers)...);
    auto ends = std::make_tuple(end(containers)...);

    std::vector<std::vector<int>> res;

    while (true) {
        bool all_not_end = true;
        std::vector<int> row;

        std::apply([&](auto&... it) {
            all_not_end = (... && (it != end(containers)));
            if (all_not_end) {
                row = { (*it)... };
                (..., ++it);
            }
        }, iters);

        if (!all_not_end) break;

        res.push_back(row);
    }

    return res;

}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P6_H
