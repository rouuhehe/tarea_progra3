//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_2_V2025_01_SUM_VARIADIC_H
#define PROG3_FUNDAMENTOS_TASK_2_V2025_01_SUM_VARIADIC_H



namespace utils::math{
    template <typename... Args>
    auto sum_variadic(Args... a){
        return (0 + ... + a);
   }
}


#endif //PROG3_FUNDAMENTOS_TASK_2_V2025_01_SUM_VARIADIC_H
