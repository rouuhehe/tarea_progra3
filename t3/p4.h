//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H

#include <algorithm>
#include <ranges>
#include <vector>
#include <list>

template <typename container>
auto delete_duplicated(const container &v1) -> container
{
     container res = v1;  

    if constexpr(std::is_same_v<typename std::remove_cv<typename std::remove_reference<container>::type>::type, 
                                std::list<typename container::value_type>>){
        res.sort();
        res.unique();
    } else {
        std::sort(res.begin(), res.end());
        res.erase(std::unique(res.begin(), res.end()), res.end());
    }
    return res;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P4_H
