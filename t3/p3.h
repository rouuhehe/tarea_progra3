#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H

#include <vector>
#include <iterator>
#include <list>
#include <forward_list>
#include <deque>
#include <algorithm>
#include <type_traits>


// eliminar un solo valor
template <typename container, typename T>
container delete_range(const container &c, const T &value) {
    container res(c);
    res.erase(std::remove(res.begin(), res.end(), value), res.end());
    return res;
}

// eliminar un rango de valores
template <typename container, typename rango>
auto delete_range(const container &c, const rango &r)
    ->decltype(std::begin(r), std::end(r), container()) {   
    container res(c);
    for(const auto& vals: r){
        res.erase(std::remove(res.begin(), res.end(), vals), res.end());
    }
    return res;
}

// sobrecarga  para listas
template <typename container, typename T>
auto delete_range(const container &c, const std::initializer_list<T> &r){   
    container res(c);
    for(const auto& vals: r){
        res.erase(std::remove(res.begin(), res.end(), vals), res.end());
        }
    
    return res;
}
#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P3_H