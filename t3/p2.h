//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H

#include <vector>
#include <forward_list>
#include <deque>
#include <iterator>

template<typename container1, typename container2>

auto sum_range(const container1 &c1, const container2 &c2){

    using tipo1 = typename container1::value_type;
    using tipo2 = typename container2::value_type;
    using tipo_res = std::common_type_t<tipo1, tipo2>;

    size_t size1 = std::distance(c1.begin(), c1.end());
    size_t size2 = std::distance(c2.begin(), c2.end());
    size_t max = std::max(size1, size2);

    std::vector<tipo_res> res;
    res.reserve(max);

    auto it1 = std::begin(c1);
    auto it2 = std::begin(c2);

    if (size1 == 0 && size2 == 0) return res;

    for(size_t i = 0; i < max; ++i){

        if(it1 == std::end(c1)) it1 = std::begin(c1);
        if(it2 == std::end(c2)) it2 = std::begin(c2);
    
        res.push_back(*it1 + *it2);

        if(size1 > 0)++it1;
        if(size2 > 0)++it2;
        
    }
    
    return res;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P2_H
