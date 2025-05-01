//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_2_V2025_01_STATIC_ARRAY_H
#define PROG3_FUNDAMENTOS_TASK_2_V2025_01_STATIC_ARRAY_H


//size_t es un int sin signo, entonces, se puede usar chevere para indices.
// initializer_list es una lista de valores que se puede usar para inicializar un array.
// se usa cuando se usan llaves

template<typename T, std::size_t N>
class static_array {
    private:
        T arr[N];
    public:

        // constructor 
        constexpr static_array(std::initializer_list<T> l) {
            std::copy(l.begin(), l.end(), arr);
        }
        
        constexpr static_array() = default;

        constexpr const T &operator[](std::size_t idx) const{
            return arr[idx];
        }

        constexpr T &operator[](std::size_t idx){
            return arr[idx];
        }

        constexpr const T *begin() const{return arr;}

        constexpr  T *begin() {return arr;}

        constexpr const T *end() const {return arr + N;}

        constexpr  T *end()  {return arr + N;}

        std::size_t size(){
            return N;
        }
        
        ~static_array() = default;
};

#endif //PROG3_FUNDAMENTOS_TASK_2_V2025_01_STATIC_ARRAY_H
