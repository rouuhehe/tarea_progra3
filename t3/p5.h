//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H

#include <tuple>
#include <utility>

template <typename ...Ts>
struct unpacker {
    std::tuple<Ts &...> referencias;

    unpacker(Ts &...referencias) : referencias(referencias...) {}

    template<typename ...Us>
    void assing(const std::tuple<Us...> &vals){
        assing_impl(vals, std::index_sequence_for<Us...>{});
    }

    template<typename ...Us>
    unpacker &operator=(const std::tuple<Us...> &vals){
        assing(vals);
        return *this;
    }

    private:
        template<typename Tuple, std::size_t ...Is>
        void assing_impl(const Tuple &vals, std::index_sequence<Is...>){
            ((std::get<Is>(referencias) = std::get<Is>(vals)), ...);
        }
      
};

template <typename ...Ts>
unpacker<Ts ...> unpack(Ts &...referencias) {
    return unpacker<Ts ...>(referencias...);
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P5_H
