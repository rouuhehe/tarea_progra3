//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P1_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P1_H

#include <type_traits>
#include <iterator>
#include <forward_list>
#include <vector>


template < 
template<typename...> class exterior = std::vector,
template<typename...> class interior = std::vector,
typename container
>

exterior<interior<typename container::value_type>> split_range(const container &c, size_t n) {
    using tipo_valor = typename container::value_type;
    
    exterior<interior<tipo_valor>> res; // el vector de vectores aka resultado :3
    
    if(n==0) return res; // por si está vacío

    auto begin = std::begin(c);
    auto end = std::end(c);

    size_t tam = std::distance(begin, end);
    size_t cant_num = tam / n;
    size_t resto = tam % n;

    for(size_t i=0; i<n && begin != end; ++i){
        size_t tam_parte = cant_num + (i == n - 1 ? resto : 0);
        interior<tipo_valor> parte;
        
        if constexpr (std::is_same_v<interior<tipo_valor>, std::vector<tipo_valor>>){
            parte.reserve(tam_parte);
        }
        

        for(size_t j=0; j<tam_parte && begin != end; ++j){
            if constexpr (std::is_same_v<container, std::forward_list<tipo_valor>>){
                parte.insert(parte.end(), *begin);
            }else {
                parte.push_back(*begin);
            }        
            ++begin;
        }
        res.push_back(std::move(parte));
    }

    return res;

}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P1_H
