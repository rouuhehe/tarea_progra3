//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H

template<typename container>
auto rotate_range(const container &c, int n) {
    using std::begin;
    using std::end;

    auto res = c;
    
    auto first = begin(res);
    auto last = end(res);
    auto size = std::distance(first, last);

    
    if(n == 0 || size == 0) return res;

    n = n % size;

    if (n > 0) {
        auto it = last;
        std::advance(it, -n);
        std::rotate(res.begin(), it, res.end());
    } else if (n < 0) {
        auto it = first;
        std::advance(it, -n);  // -n positivo
        std::rotate(res.begin(), it, res.end());
    }
    
    return res;
}


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P7_H
